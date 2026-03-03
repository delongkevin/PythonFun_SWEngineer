/*******************************************************************************
 * aiming.c
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

#define MODULE_TAG                      AIMING

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "config.h"
#include "math-neon.h"
#include "aiming.h"
#include "vbo-dynarray.h"

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * External declarations - tbd - think about getting some "utils"
 ******************************************************************************/

/**
 * @brief   Load PNG file
 *
 * @param   path[in]            File name
 * @param   width[in, out]      Image width; if non-zero on input, shall match the
 *                              actual width of the image loaded from file
 * @param   height[in, out]     Image height; if non-zero on input, shall match the
 *                              actual width of the image loaded from file
 * @param   format[in, out]     Image format; if non-zero on input, shall match the
 *                              actual format of the image loaded from file
 * @param   data[in, out]       Pointer to the pixel-data buffer; if NULL on input,
 *                              the buffer will be allocated
 *
 * @return                      Negative on failure
 */
extern int load_png(const char *path, int *width, int *height, int *format, void **data);

/**
 * @brief   Load BMP file
 *
 * @param   path[in]            File name
 * @param   width[in, out]      Image width; if non-zero on input, shall match the
 *                              actual width of the image loaded from file
 * @param   height[in, out]     Image height; if non-zero on input, shall match the
 *                              actual width of the image loaded from file
 * @param   format[in, out]     Image format; if non-zero on input, shall match the
 *                              actual format of the image loaded from file
 * @param   data[in, out]       Pointer to the pixel-data buffer; if NULL on input,
 *                              the buffer will be allocated
 *
 * @return                      Negative on failure
 */
extern int load_bmp(const char *path, int *width, int *height, int *format, void **data);

/*******************************************************************************
 * Loal types definitions
 ******************************************************************************/

/**> Vertex data: {X,Y} + {U,V} */
typedef GLfloat  aim_vertex_t[4];

/**
 * @brief   Icon render object
 */
typedef struct aim_render_object
{
    /**> GL texture identifier (reference) */
    GLuint              tex;

    /**> Foreground color */
    GLfloat             fg_color[4];

    /**> Background color */
    GLfloat             bg_color[4];

    /**> Single quad buffer */
    aim_vertex_t        vertex[6];

}   aim_render_object_t;

/*******************************************************************************
 * Vertex shader construction
 ******************************************************************************/

/* ...VBO vertex shader */
static const char *mask_vertex_shader =
    SH_SETPREC
    "attribute vec2	XY;\n"
    "attribute vec2 UV;\n"
    "uniform vec2 scale;\n"
    "varying vec2 uv;\n"
    "void main(void)\n"
    "{\n"
    "   uv = UV;\n"
    "	gl_Position = vec4(XY.x * scale.x - 1.0, 1.0 - XY.y * scale.y, 0.0, 1.0);\n"
    "}\n";

/* ...VBO fragment shader */
static const char *mask_fragment_shader =
    SH_SETPREC
    "uniform vec4 bg_color;\n"
    "uniform vec4 fg_color;\n"
    "uniform sampler2D tex;\n"
    "uniform float intensity;\n"
    "varying vec2 uv;\n"
    "void main()\n"
    "{\n"
    "   vec4    rgba = texture2D(tex, uv);\n"
    "   gl_FragColor = mix(bg_color, fg_color, rgba.r) * intensity;\n"
    //"   gl_FragColor = rgba;\n"
    "}\n";

/* ...specify shader name */
#define SHADER_TAG                  MASK
#define SHADER_VERTEX_SOURCE        mask_vertex_shader
#define SHADER_FRAGMENT_SOURCE      mask_fragment_shader

/* ...define list of attributes */
#define SHADER_ATTRIBUTES                               \
    __A(XY), __A(UV),

/* ...define list of uniforms */
#define SHADER_UNIFORMS                                 \
    __U(scale), __U(tex), __U(bg_color), __U(fg_color), __U(intensity),

/* ...build shader lists */
#include "../src/shader-impl.h"

/*******************************************************************************
 * Vertex shader construction
 ******************************************************************************/

/* ...VBO vertex shader */
static const char *image_vertex_shader =
    SH_SETPREC
    "attribute vec2	XY;\n"
    "attribute vec2 UV;\n"
    "uniform vec2 scale;\n"
    "varying vec2 uv;\n"
    "void main(void)\n"
    "{\n"
    "   uv = UV;\n"
    "	gl_Position = vec4(XY.x * scale.x - 1.0, 1.0 - XY.y * scale.y, 0.0, 1.0);\n"
    "}\n";

/* ...VBO fragment shader */
static const char *image_fragment_shader =
    SH_SETPREC
    "uniform sampler2D tex;\n"
    "uniform float intensity;\n"
    "varying vec2 uv;\n"
    "void main()\n"
    "{\n"
    "   vec4    rgba = texture2D(tex, uv);\n"
    "   gl_FragColor = rgba * intensity;\n"
    "}\n";

/* ...specify shader name */
#define SHADER_TAG                  IMAGE
#define SHADER_VERTEX_SOURCE        image_vertex_shader
#define SHADER_FRAGMENT_SOURCE      image_fragment_shader

/* ...define list of attributes */
#define SHADER_ATTRIBUTES                               \
    __A(XY), __A(UV),

/* ...define list of uniforms */
#define SHADER_UNIFORMS                                 \
    __U(scale), __U(tex), __U(intensity),

/* ...build shader lists */
#include "../src/shader-impl.h"

/*******************************************************************************
 * Solid-color shader construction
 ******************************************************************************/

/* ...vertex shader */
static const char *solid_vertex_shader =
    SH_SETPREC
    "attribute vec2	XY;\n"
    "uniform vec2 scale;\n"
    "void main(void)\n"
    "{\n"
    "	gl_Position = vec4(XY.x * scale.x - 1.0, 1.0 - XY.y * scale.y, 0.0, 1.0);\n"
    "}\n";

/* ...VBO fragment shader */
static const char *solid_fragment_shader =
    SH_SETPREC
    "uniform vec4 color;\n"
    "uniform float intensity;\n"
    "void main()\n"
    "{\n"
    "   gl_FragColor = color * intensity;\n"
    "}\n";

/* ...specify shader name */
#define SHADER_TAG                  SOLID
#define SHADER_VERTEX_SOURCE        solid_vertex_shader
#define SHADER_FRAGMENT_SOURCE      solid_fragment_shader

/* ...define list of attributes */
#define SHADER_ATTRIBUTES                               \
    __A(XY),

/* ...define list of uniforms */
#define SHADER_UNIFORMS                         \
    __U(scale), __U(color), __U(intensity),

/* ...build shader lists */
#include "../src/shader-impl.h"

/**
 * @brief   Return shader object for mask rendering
 *
 * @return                  Shader pointer, or NULL in case of error
 */
static shader_data_t * aim_get_mask_shader(void)
{
    static shader_data_t * __shader;

    if (__shader == NULL)
    {
        __shader = shader_create(&SHADER_DESC(MASK));
    }

    return __shader;
}

/**
 * @brief   Return shader object for mask rendering
 *
 * @return                  Shader pointer, or NULL in case of error
 */
static shader_data_t * aim_get_image_shader(void)
{
    static shader_data_t * __shader;

    if (__shader == NULL)
    {
        __shader = shader_create(&SHADER_DESC(IMAGE));
    }

    return __shader;
}

/**
 * @brief   Return shader object for solid color rendering
 *
 * @return                  Shader pointer, or NULL in case of error
 */
static shader_data_t * aim_get_solid_shader(void)
{
    static shader_data_t * __shader;

    if (__shader == NULL)
    {
        __shader = shader_create(&SHADER_DESC(SOLID));
    }

    return __shader;
}

/**
 * @brief   Render circle of specified color
 *
 * @param   ctx[in]         Rendering context
 * @param   center[in]      Center-point, in pixels
 * @param   radius[in]      Circle radius, in pixels
 * @param   width[in]       Circle width, in pixels
 * @param   fg[in]          Foreground color
 * @param   bg[in]          Background color
 */

#define U(id)       u[UNIFORM(SOLID, id)]
#define A(id)       ATTRIBUTE(SOLID, id)

static void aim_draw_circle(render_context_t *ctx, float32_t center[2], float32_t radius, float32_t width, float32_t *bg, float32_t *fg, float32_t intensity)
{
    shader_data_t  *shader = aim_get_solid_shader();

    if (shader == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %s"), strerror(errno));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    glUseProgram(shader_program(shader));

    /* ...set scaling factors for pixel-to-GL conversion */
    glUniform2fv(U(scale), 1, (GLfloat [2]){ 2.0f / ctx->width, 2.0f / ctx->height });

    /* ...set line width */
    glLineWidth(ctx->scale * width);

    /* ...set intensity */
    glUniform1f(U(intensity), intensity);

    /* ...fill points coordinates */
    const int32_t   K = 16;
    float32_t       points[K + 2][2];
    float32_t     (*p)[2] = &points[1];
    int32_t         i;

    /* ...build points on circle */
    float32x4_t     A = vmulq_n_f32(__mk_float32x4(0.0f, 1.0f, 2.0f, 3.0f), (float32_t)(2 * M_PI / K));

    /* ...save center of triangle */
    memcpy(points[0], center, sizeof(points[0]));

    for (i = 0; i < K; i += 4)
    {
        /* ...evaluate sine/cosine of the angle */
        float32x4_t     S, C;
        sincos_ps(A, &S, &C);

        float32x4x2_t   V;
        V.val[0] = vmlaq_n_f32(vdupq_n_f32(center[0]), C, radius);
        V.val[1] = vmlsq_n_f32(vdupq_n_f32(center[1]), S, radius);

        /* ...store points in interim array */
        vst2q_f32(*p, V);
        p += 4;

        /* ...advance angles */
        A = vaddq_f32(A, vdupq_n_f32((float32_t)(4 * 2 * M_PI / K)));
    }

    /* ...put last point */
    memcpy(*p, points[1], sizeof(points[1]));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glEnableVertexAttribArray(A(XY));
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, sizeof(float32_t[2]), points);

    /* ...set background color */
    if (bg != NULL)
    {
        glUniform4fv(U(color), 1, bg);

        /* ...generate triangle-fan with background color */
        glDrawArrays(GL_TRIANGLE_FAN, 0, K + 2);    GLCHECK();
    }

    /* ...set foreground color */
    if (fg != NULL)
    {
        glUniform4fv(U(color), 1, fg);

        /* ...generate closed line-strip with foreground color */
        glDrawArrays(GL_LINE_STRIP, 1, K + 1);      GLCHECK();
    }

    /* ...clear after the program */
    glUseProgram(0);

    TRACE(0, _b("render circle at %f,%f"), center[0], center[1]);
}

static void aim_draw_marker(render_context_t *ctx, float32_t center[2], float32_t radius, float32_t width, float32_t *fg, float32_t intensity)
{
    shader_data_t  *shader = aim_get_solid_shader();

    if (shader == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %s"), strerror(errno));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    glUseProgram(shader_program(shader));

    /* ...set scaling factors for pixel-to-GL conversion */
    glUniform2fv(U(scale), 1, (GLfloat [2]){ 2.0f / ctx->width, 2.0f / ctx->height });

    /* ...set line width */
    glLineWidth(ctx->scale * width);

    /* ...set intensity */
    glUniform1f(U(intensity), intensity);

    /* ...fill points coordinates */
    const int32_t   K = 16;
    float32_t       points[K + 1][2];
    float32_t     (*p)[2] = &points[1];
    int32_t         i;

    /* ...build points on circle */
    float32x4_t     A = vmulq_n_f32(__mk_float32x4(0.0f, 1.0f, 2.0f, 3.0f), (float32_t)(M_PI / (K / 2 - 1)));

    A = vmlaq_n_f32(vdupq_n_f32((float32_t)-M_PI_4), __mk_float32x4(0, 1, 2, 3), (float32_t)(M_PI / (K / 2 - 1)));

    /* ...save center of triangle */
    memcpy(points[0], center, sizeof(points[0]));

    for (i = 0; i < K / 2; i += 4)
    {
        /* ...evaluate sine/cosine of the angle */
        float32x4_t     S, C;
        sincos_ps(A, &S, &C);

        float32x4x2_t   V;
        V.val[0] = vmlaq_n_f32(vdupq_n_f32(center[0]), C, radius);
        V.val[1] = vmlsq_n_f32(vdupq_n_f32(center[1]), S, radius);

        /* ...store points in interim array */
        vst2q_f32(*p, V);
        p += 4;

        /* ...advance angles */
        A = vaddq_f32(A, vdupq_n_f32((float32_t)(4 * M_PI / (K / 2 - 1))));
    }

    A = vmlsq_n_f32(vdupq_n_f32((float32_t)-M_PI_4), __mk_float32x4(0, 1, 2, 3), (float32_t)(M_PI / (K / 2 - 1)));

    for (i = 0; i < K / 2; i += 4)
    {
        /* ...evaluate sine/cosine of the angle */
        float32x4_t     S, C;
        sincos_ps(A, &S, &C);

        float32x4x2_t   V;
        V.val[0] = vmlaq_n_f32(vdupq_n_f32(center[0]), C, radius);
        V.val[1] = vmlsq_n_f32(vdupq_n_f32(center[1]), S, radius);

        /* ...store points in interim array */
        vst2q_f32(*p, V);
        p += 4;

        /* ...advance angles */
        A = vsubq_f32(A, vdupq_n_f32((float32_t)(4 * M_PI / (K / 2 - 1))));
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glEnableVertexAttribArray(A(XY));
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, sizeof(float32_t[2]), points);

    /* ...set foreground color */
    glUniform4fv(U(color), 1, fg);

    /* ...generate closed line-strip with foreground color */
    glDrawArrays(GL_LINE_STRIP, 1, K);      GLCHECK();

    /* ...clear after the program */
    glUseProgram(0);

    TRACE(0, _b("render circle at %f,%f"), center[0], center[1]);
}

/**
 * @brief   Draw rectangle of specified width/color
 */
static void aim_draw_rect(render_context_t *ctx, int32_t dst[4], float32_t width, float32_t *fg, float32_t intensity)
{
    shader_data_t  *shader = aim_get_solid_shader();

    if (shader == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %s"), strerror(errno));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    glUseProgram(shader_program(shader));

    /* ...set scaling factors for pixel-to-GL conversion */
    glUniform2fv(U(scale), 1, (GLfloat [2]){ 2.0f / ctx->width, 2.0f / ctx->height });

    /* ...set intensity */
    glUniform1f(U(intensity), intensity);

    /* ...set line width */
    glLineWidth(ctx->scale * width);

    /* ...fill points coordinates */
    float32_t       points[5][2];
    float32_t     (*p)[2] = &points[0];

    /* ...[0]: {X0, X1}, [1]: {Y0, Y1} */
    int32x2x2_t     D = vld2_s32(dst);

    /* ...create coordinates of the points:
     * [0]: {X0, X0, X1, X1}
     * [1]: {Y0, Y1, Y1, Y0}
     */
    float32x4x2_t   P;
    P.val[0] = vcvtq_f32_s32(vcombine_s32(vtrn1_s32(D.val[0], D.val[0]), vtrn2_s32(D.val[0], D.val[0])));
    P.val[1] = vcvtq_f32_s32(vcombine_s32(D.val[1], vext_s32(D.val[1], D.val[1], 1)));

    vst2q_f32(points[0], P);

    /* ...put last point */
    memcpy(points[4], points[0], sizeof(points[0]));

    /* ...set line color */
    glUniform4fv(U(color), 1, fg);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glEnableVertexAttribArray(A(XY));
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, sizeof(float32_t[2]), points);

    /* ...generate closed line-strip with foreground color */
    glDrawArrays(GL_LINE_STRIP, 0, 5);      GLCHECK();

    /* ...clear after the program */
    glUseProgram(0);
}

/**
 * @brief   Draw rectangle of specified width/color
 *
 * @param   ctx[in]         Rendering context
 * @param   dst[in]         Rectangle tile
 * @param   bg[in]          Background color
 * @param   intensity[in]   Global scene intensity
 */
static void aim_draw_bar(render_context_t *ctx, int32_t dst[4], float32_t *bg, float32_t intensity)
{
    shader_data_t  *shader = aim_get_solid_shader();

    if (shader == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %s"), strerror(errno));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    glUseProgram(shader_program(shader));

    /* ...set scaling factors for pixel-to-GL conversion */
    glUniform2fv(U(scale), 1, (GLfloat [2]){ 2.0f / ctx->width, 2.0f / ctx->height });

    /* ...set intensity */
    glUniform1f(U(intensity), intensity);

    /* ...fill points coordinates */
    float32_t       points[6][2];
    float32_t     (*p)[2] = &points[0];

    /* ...[0]: {X0, X1}, [1]: {Y0, Y1} */
    int32x2x2_t     D = vld2_s32(dst);

    /* ...create coordinates of the points:
     * [0]: {X0, X0, X1, X1}
     * [1]: {Y0, Y1, Y0, Y1}
     */
    float32x4x2_t   P;
    P.val[0] = vcvtq_f32_s32(vcombine_s32(vtrn1_s32(D.val[0], D.val[0]), vtrn2_s32(D.val[0], D.val[0])));
    P.val[1] = vcvtq_f32_s32(vcombine_s32(D.val[1], D.val[1]));

    float32x2x2_t   B01, B23;
    B01.val[0] = vget_low_f32(P.val[0]);
    B01.val[1] = vget_low_f32(P.val[1]);
    B23.val[0] = vget_high_f32(P.val[0]);
    B23.val[1] = vget_high_f32(P.val[1]);

    vst2_f32(*p, B01);
    p += 2;

    float32x2x2_t   B22;
    B22.val[0] = vdup_lane_f32(B23.val[0], 0);
    B22.val[1] = vdup_lane_f32(B23.val[1], 0);

    vst2_f32(*p, B22);
    p += 2;

    float32x2x2_t   B13;
    B13.val[0] = vtrn2_f32(B01.val[0], B23.val[0]);
    B13.val[1] = vtrn2_f32(B01.val[1], B23.val[1]);
    vst2_f32(*p, B13);

    /* ...set bar color */
    glUniform4fv(U(color), 1, bg);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glEnableVertexAttribArray(A(XY));
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, sizeof(float32_t[2]), points);

    /* ...generate closed line-strip with foreground color */
    glDrawArrays(GL_TRIANGLES, 0, 6);      GLCHECK();

    /* ...clear after the program */
    glUseProgram(0);
}

#undef U
#undef A

/**
 * @brief   Create two triangles from the adjacent point-pairs
 *
 * @param   v[in, out]      Icon VBO pointer
 * @param   B01[in]         First two points ({0},{1}) in interleaved order:
 *                          [0]: X0:U0:X1:U1
 *                          [1]: Y0:V0:Y1:V1
 * @param   B23[in]         Last two points ({2},{3}) in interleaved order
 *                          [0]: X2:U2:X3:U3
 *                          [1]: Y2:V2:Y3:V3
 */
static inline void aim_quad_encode(aim_vertex_t *v, float32x4x2_t B01, float32x4x2_t B23)
{
    /* ...make a triangle of points {0},{1},{2} and {2},{1},{3}; place points {0},{1} first
     * [0]: X0:U0:X1:U1
     * [1]: Y0:V0:Y1:V1
     */
    vst2q_f32(*v, B01);
    v += 2;

    /* ...next two points to store are {2}, {2}:
     * [0]: X2:U2:X2:U2
     * [1]: Y2:V2:Y2:V2
     */
    float32x4x2_t   B22;
    B22.val[0] = vcombine_f32(vget_low_f32(B23.val[0]), vget_low_f32(B23.val[0]));
    B22.val[1] = vcombine_f32(vget_low_f32(B23.val[1]), vget_low_f32(B23.val[1]));
    vst2q_f32(*v, B22);
    v += 2;

    /* ...next two points are {1},{3}:
     * [0]: X1:U1:X3:U3
     * [1]: Y1:V1:Y3:V3
     */
    float32x4x2_t   B13;
    B13.val[0] = vcombine_f32(vget_high_f32(B01.val[0]), vget_high_f32(B23.val[0]));
    B13.val[1] = vcombine_f32(vget_high_f32(B01.val[1]), vget_high_f32(B23.val[1]));
    vst2q_f32(*v, B13);
    v += 2;
}

/**
 * @brief   Add icon item to rendering list
 *
 * @param   v[in]           VBO buffer
 * @param   src[in]         Source tile in texture
 * @param   dst[in]         Destination tile on display
 *
 * @return                  Negative on failure
 */
static void aim_add_quad(aim_vertex_t *v, float32_t *src, int32_t *dst)
{
    /* ...[0]: {X0, X1}, [1]: {Y0, Y1} */
    int32x2x2_t     D = vld2_s32(dst);

    /* ...create coordinates of the points:
     * [0]: {X0, X0, X1, X1}
     * [1]: {Y0, Y1, Y0, Y1}
     */
    float32x4x2_t   P;
    P.val[0] = vcvtq_f32_s32(vcombine_s32(vtrn1_s32(D.val[0], D.val[0]), vtrn2_s32(D.val[0], D.val[0])));
    P.val[1] = vcvtq_f32_s32(vcombine_s32(D.val[1], D.val[1]));

    /* ...load source coordinates of the points:
     * [0]: {U0, U1}
     * [1]: {V0, V1}
     */
    float32x2x2_t   S = vld2_f32(src);

    /* ...create coordinates of the corners in source tile:
     * [0]: {U0, U0, U1, U1}
     * [1]: {V0, V1, V0, V1}
     */
    float32x4x2_t   R;
    R.val[0] = vcombine_f32(vtrn1_f32(S.val[0], S.val[0]), vtrn2_f32(S.val[0], S.val[0]));
    R.val[1] = vcombine_f32(S.val[1], S.val[1]);

    /* ...create the quad points in interleaved order:
     * [0]: {X0, U0, X1, U1}
     * [1]: {Y0, V0, Y1, V1}
     */
    float32x4x2_t   B01, B23;
    B01.val[0] = vzip1q_f32(P.val[0], R.val[0]);
    B01.val[1] = vzip1q_f32(P.val[1], R.val[1]);
    B23.val[0] = vzip2q_f32(P.val[0], R.val[0]);
    B23.val[1] = vzip2q_f32(P.val[1], R.val[1]);

    /* ...encode quad in VBO */
    aim_quad_encode(v, B01, B23);
}

/**
 * @brief   Draw rectangle of specified width/color
 *
 * @param   ctx[in]         Rendering context
 * @param   dst[in]         Rectangle tile
 * @param   bg[in]          Background color
 * @param   intensity[in]   Global scene intensity
 */

#define U(id)       u[UNIFORM(MASK, id)]
#define A(id)       ATTRIBUTE(MASK, id)

static void aim_draw_mask(render_context_t *ctx, int32_t dst[4], float32_t src[4], GLuint tex, float32_t *bg, float32_t *fg,float32_t intensity)
{
    shader_data_t  *shader = aim_get_mask_shader();

    if (shader == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %s"), strerror(errno));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    glUseProgram(shader_program(shader));

    /* ...set scaling factors for pixel-to-GL conversion */
    glUniform2fv(U(scale), 1, (GLfloat [2]){ 2.0f / ctx->width, 2.0f / ctx->height });

    /* ...set intensity */
    glUniform1f(U(intensity), intensity);

    /* ...fill points coordinates */
    aim_vertex_t    vbo[6];
    aim_add_quad(vbo, src, dst);

    /* ...set sampler */
    glUniform1i(U(tex), 0);

    /* ...set colors */
    glUniform4fv(U(bg_color), 1, bg);
    glUniform4fv(U(fg_color), 1, fg);

    /* ..bind texture */
    glActiveTexture(GL_TEXTURE0);  GLCHECK();
    glBindTexture(GL_TEXTURE_2D, tex);  GLCHECK();

    /* ...bind attributes */
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glEnableVertexAttribArray(A(XY));
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, sizeof(float32_t[4]), &vbo[0][0]);

    glEnableVertexAttribArray(A(UV));
    glVertexAttribPointer(A(UV), 2, GL_FLOAT, GL_FALSE, sizeof(float32_t[4]), &vbo[0][2]);

    /* ...generate closed line-strip with foreground color */
    glDrawArrays(GL_TRIANGLES, 0, 6);      GLCHECK();

    /* ...clear after the program */
    glUseProgram(0);
}

#undef U
#undef A

/**
 * @brief   Draw rectangle of specified width/color
 *
 * @param   ctx[in]         Rendering context
 * @param   dst[in]         Rectangle tile
 * @param   bg[in]          Background color
 * @param   intensity[in]   Global scene intensity
 */

#define U(id)       u[UNIFORM(IMAGE, id)]
#define A(id)       ATTRIBUTE(IMAGE, id)

static void aim_draw_image(render_context_t *ctx, int32_t dst[4], float32_t src[4], GLuint tex, float32_t intensity)
{
    shader_data_t  *shader = aim_get_image_shader();

    if (shader == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %s"), strerror(errno));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    glUseProgram(shader_program(shader));

    /* ...set scaling factors for pixel-to-GL conversion */
    glUniform2fv(U(scale), 1, (GLfloat [2]){ 2.0f / ctx->width, 2.0f / ctx->height });

    /* ...set intensity */
    glUniform1f(U(intensity), intensity);

    /* ...fill points coordinates */
    aim_vertex_t    vbo[6];
    aim_add_quad(vbo, src, dst);

    /* ...set sampler */
    glUniform1i(U(tex), 0);

    /* ..bind texture */
    glActiveTexture(GL_TEXTURE0);  GLCHECK();
    glBindTexture(GL_TEXTURE_2D, tex);  GLCHECK();

    /* ...bind attributes */
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glEnableVertexAttribArray(A(XY));
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, sizeof(float32_t[4]), &vbo[0][0]);

    glEnableVertexAttribArray(A(UV));
    glVertexAttribPointer(A(UV), 2, GL_FLOAT, GL_FALSE, sizeof(float32_t[4]), &vbo[0][2]);

    /* ...generate closed line-strip with foreground color */
    glDrawArrays(GL_TRIANGLES, 0, 6);      GLCHECK();

    /* ...clear after the program */
    glUseProgram(0);
}

#undef U
#undef A

/**
 * @brief   Draw a message box
 */
static inline void aim_draw_mbox(icon_item_t *item, render_context_t *ctx, int32_t *dst, float32_t *fg, float32_t *bg, float32_t intensity)
{
    float32_t src[4] = {0};

    if (item->src && item->scale_x && item->scale_y)
    {
        memcpy(src, item->src, sizeof(src));
        src[0]*= *item->scale_x;
        src[1]*= *item->scale_y;
        src[2]*= *item->scale_x;
        src[3]*= *item->scale_y;
    }

    aim_draw_mask(ctx, dst, src, item->tex, bg, fg, intensity);
    aim_draw_rect(ctx, dst, 2.0f, fg, intensity);
}

/**
 * @brief   Draw a progress bar
 */
static inline void aim_draw_progress(render_context_t *ctx, int32_t *dst, int32_t progress, float32_t *fg, float32_t *bg, float32_t intensity)
{
    float32_t   filled = (float32_t)(MAX(MIN(progress, 100), 0)) * 0.01f;
    float32_t   width = (float32_t)(dst[2] - dst[0]) * filled;
    int32_t     bar_dst[4] = { dst[0], dst[1], dst[0] + (int32_t)width, dst[3] };

    aim_draw_bar(ctx, bar_dst, bg, intensity);
    aim_draw_rect(ctx, dst, 2.0f, fg, intensity);
}

/**
 * @brief   Render aim view
 *
 * @param   icon[in]            Icon resources
 * @param   vehicle[in]         Vehicle state
 * @param   cfg[in]             Global configuration data
 * @param   ctx[in]             Rendering context
 * @param   intensity[in]       Global scene intensity
 */
void aiming_render(icon_data_t *icon, vehicle_state_t *vehicle, cfg_data_t *cfg, render_context_t *ctx, float32_t intensity)
{
    float32_t       col_black[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float32_t       col_white[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float32_t       col_green[4] = { 0.255040f, 0.670885f, 0.205247f, 1.0f };
    float32_t       col_red[4] = { 0.741640f, 0.093011f, 0.092274f, 1.0f };
    aiming_state_t *aiming = &vehicle->aiming;
    float32_t      *col;
    icon_item_t    *item;
    int32_t         i;
    static icon_render_t render = {0};

    /* ...reset render-list */
    icon_reset(&render);

    /* ...specify viewport - we always use full-screen display coordinates for that */
    render_context_set_view(ctx, NULL);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    int32_t X0 = 60, Y0 = 16;

    /* ...set speed condition icon */
    if (1)
    {
        int32_t     dst[4] = { X0 + 212, Y0 + 110, X0 + 212 + 273, Y0 + 110 + 202 };
        col = aiming->inv_speed ? col_red : col_green;

        aim_draw_bar(ctx, dst, col, intensity);
        aim_draw_rect(ctx, dst, 2.0f, col_white, intensity);
    }

    if (1)
    {
        int32_t     dst[4] = { X0 + 509, Y0 + 110, X0 + 509 + 273, Y0 + 110 + 202 };
        col = aiming->inv_steering ? col_red : col_green;

        aim_draw_bar(ctx, dst, col, intensity);
        aim_draw_rect(ctx, dst, 2.0f, col_white, intensity);
    }

    int32_t arrow_dst[4][4] = {
        [0] = { X0 + 51, Y0 + 113, X0 + 100, Y0 + 169 },
        [1] = { X0 + 21, Y0 + 143, X0 + 77, Y0 + 192 },
        [2] = { X0 + 51, Y0 + 166, X0 + 100, Y0 + 222 },
        [3] = { X0 + 74, Y0 + 143, X0 + 130, Y0 + 192 },
    };

    /* ...set camera colors */
    for (i = 0; i < 4; i++)
    {
        switch (aiming->camera_status[i])
        {
        case AIM_STATUS_INACTIVE:
            item = NULL;
            break;

        case AIM_STATUS_PROCESSING:
            icon_get_resource(icon, ICON_AIM_ARROW_GRAY, &item);
            break;

        case AIM_STATUS_PAUSE:
            icon_get_resource(icon, ICON_AIM_ARROW_YELLOW, &item);
            break;

        case AIM_STATUS_SUCCESS:
            icon_get_resource(icon, ICON_AIM_ARROW_GREEN, &item);
            break;

        default:
            icon_get_resource(icon, ICON_AIM_ARROW_RED, &item);
        }

        if (item != NULL)
        {
            icon_add_item_rot(item, arrow_dst[i], 0.0f, NULL, i, &render);
        }
    }

    /* ...add procedure status */
    if (aiming->status == AIM_STATUS_PROCESSING)
    {
        if (icon_get_resource(icon, ICON_AIM_PLAY, &item) == 0)
        {
            icon_add_item(item, (int32_t [4]){X0 + 41, Y0 + 265, X0 + 107, Y0 + 360}, &render);
        }
    }
    else if (aiming->status == AIM_STATUS_PAUSE)
    {
        if (icon_get_resource(icon, ICON_AIM_PAUSE, &item) == 0)
        {
            icon_add_item(item, (int32_t [4]){X0 + 21, Y0 + 259, X0 + 129, Y0 + 366}, &render);
        }
    }
    else if (aiming->status == AIM_STATUS_SUCCESS)
    {
        if (icon_get_resource(icon, ICON_AIM_SUCCESS, &item) == 0)
        {
            icon_add_item(item, (int32_t [4]){X0 + 19, Y0 + 258, X0 + 132, Y0 + 367}, &render);
        }
    }
    else if (aiming->status == AIM_STATUS_FAILURE)
    {
        if (icon_get_resource(icon, ICON_AIM_FAILURE, &item) == 0)
        {
            icon_add_item(item, (int32_t [4]){X0 + 26, Y0 + 269, X0 + 119, Y0 + 361}, &render);
        }
    }

    if (aiming->camera_progress[0] < 25)
    {
        if (icon_get_resource(icon, ICON_AIM_PROGRESS_0, &item) == 0)
        {
            icon_add_item(item, (int32_t [4]){X0 + 498, Y0 + 343, X0 + 527, Y0 + 359}, &render);
        }
    }
    else if (aiming->camera_progress[0] < 50)
    {
        if (icon_get_resource(icon, ICON_AIM_PROGRESS_25, &item) == 0)
        {
            icon_add_item(item, (int32_t [4]){X0 + 212, Y0 + 337, X0 + 527, Y0 + 369}, &render);
        }
    }
    else if (aiming->camera_progress[0] < 75)
    {
        if (icon_get_resource(icon, ICON_AIM_PROGRESS_50, &item) == 0)
        {
            icon_add_item(item, (int32_t [4]){X0 + 212, Y0 + 337, X0 + 527, Y0 + 369}, &render);
        }
    }
    else if (aiming->camera_progress[0] < 100)
    {
        if (icon_get_resource(icon, ICON_AIM_PROGRESS_75, &item) == 0)
        {
            icon_add_item(item, (int32_t [4]){X0 + 212, Y0 + 337, X0 + 640, Y0 + 369}, &render);
        }
    }
    else
    {
        if (icon_get_resource(icon, ICON_AIM_PROGRESS_100, &item) == 0)
        {
            icon_add_item(item, (int32_t [4]){X0 + 212, Y0 + 337, X0 + 782, Y0 + 369}, &render);
        }
    }

    /* ...add static frame at the end */
    if (icon_get_resource(icon, ICON_AIM_FRAME, &item) == 0)
    {
        icon_add_item(item, (int32_t [4]){ X0 + 18, Y0 + 110, X0 + 782, Y0 + 370 }, &render);
    }

    icon_render(&render, ctx, intensity);
}
