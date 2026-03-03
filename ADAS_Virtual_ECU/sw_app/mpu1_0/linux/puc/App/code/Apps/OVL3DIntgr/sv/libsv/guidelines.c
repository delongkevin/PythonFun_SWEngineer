/*******************************************************************************
 * guidelines.c
 *
 * Guidelines generator and renderer for surround view
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

#define MODULE_TAG                      GUIDE

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "debug.h"
#include "config.h"
#include "math-neon.h"
#include "camera.h"
#include "guidelines.h"

typedef int bool_t;

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Internal functions
 ******************************************************************************/

/**> Guidelines point VBO: UV + RGBA */
typedef GLfloat gl_vertex_t[2 + 4];

/**> Guidelines point VBO: UV + TEX */
typedef GLfloat gl_vertex_ffc_t[2 + 3];

/*******************************************************************************
 * Vertex shader construction
 ******************************************************************************/

#define SH_SETPREC  "precision highp float;\n"



/* ...VBO vertex shader */
static const char *bw_vertex_shader =
    SH_SETPREC
    "attribute vec2	uv;\n"
    "attribute vec4	c;\n"
    "varying vec4 color;\n"
    "uniform float intensity;\n"
    "void main(void)\n"
    "{\n"
    "  gl_Position = vec4(uv, 0.0, 1.0);\n"
    "  color = c * intensity;\n"
    "}\n";

/* ...VBO fragment shader */
static const char *bw_fragment_shader =
    SH_SETPREC
    "varying vec4 color;\n"
    "void main()\n"
    "{\n"
    "    float c = clamp((color.x - 0.4)*5.0,0.0,1.0);\n"
    "   gl_FragColor = vec4(c, c, c, 1.0);\n"
    "}\n";

/* ...specify shader name */
#define SHADER_TAG                  BW
#define SHADER_VERTEX_SOURCE        bw_vertex_shader
#define SHADER_FRAGMENT_SOURCE      bw_fragment_shader

/* ...define list of attributes */
#define SHADER_ATTRIBUTES                               \
    __A(uv), __A(c),

/* ...define list of uniforms */
#define SHADER_UNIFORMS                         \
    __U(intensity),

/* ...build shader lists */
#include "../src/shader-impl.h"


static const char *ffc_vertex_shader =
    SH_SETPREC
    "attribute vec2	uv;\n"
    "attribute vec3	c;\n"
    "varying vec3 color;\n"
    "void main(void)\n"
    "{\n"
    "   color = c;\n"
    "   gl_Position = vec4(uv, 0.0, 1.0);\n"
    "}\n";

/* ...VBO fragment shader */
static const char *ffc_fragment_shader =
    SH_SETPREC
    "varying vec3 color;\n"
    "uniform sampler2D tex;\n"
    "uniform float  intensity;\n"
    "void main()\n"
    "{\n"
    "   vec4 ret = texture2D(tex, vec2(color.x,color.y)) * intensity;\n"
    "   gl_FragColor = vec4(ret.xyz, ret.w*(1.0-color.z));\n"
    "}\n";

/* ...specify shader name */
#define SHADER_TAG                  FFC
#define SHADER_VERTEX_SOURCE        ffc_vertex_shader
#define SHADER_FRAGMENT_SOURCE      ffc_fragment_shader

/* ...define list of attributes */
#define SHADER_ATTRIBUTES                               \
    __A(uv), __A(c),

/* ...define list of uniforms */
#define SHADER_UNIFORMS                         \
    __U(intensity), __U(tex),

/* ...build shader lists */
#include "../src/shader-impl.h"

/* ...VBO vertex shader */
static const char *vbo_vertex_shader =
    SH_SETPREC
    "attribute vec2	uv;\n"
    "attribute vec4	c;\n"
    "varying vec4 color;\n"
    "uniform float intensity;\n"
    "void main(void)\n"
    "{\n"
    "  gl_Position = vec4(uv, 0.0, 1.0);\n"
    "  color = c * intensity;\n"
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
    __A(uv), __A(c),

/* ...define list of uniforms */
#define SHADER_UNIFORMS                         \
    __U(intensity),

/* ...build shader lists */
#include "../src/shader-impl.h"

static const uint32_t ffc_sections = 64U;

/**
 * @brief   Compile shader for guidelines rendering
 *
 * @return                  Shader pointer
 */
static shader_data_t * gl_vbo_shader_compile(void)
{
    const shader_desc_t    *desc = &SHADER_DESC(VBO);
    shader_data_t          *shader;

    /* ...compile shader */
    return shader_create(desc);
}


/**
 * @brief   Compile shader for guidelines rendering
 *
 * @return                  Shader pointer
 */
static shader_data_t * gl_vbo_shader_compile_ffc(void)
{
    const shader_desc_t    *desc = &SHADER_DESC(FFC);
    shader_data_t          *shader;

    /* ...compile shader */
    return shader_create(desc);
}


/**
 * @brief   Compile shader for guidelines rendering (black-and-white)
 *
 * @return                  Shader pointer
 */
static shader_data_t * gl_vbo_shader_compile_bw(void)
{
    const shader_desc_t    *desc = &SHADER_DESC(BW);

    /* ...compile shader */
    return shader_create(desc);
}

/**
 * @brief   Return shader for given texture format
 *
 * @param   texture[in]     Texture handle
 *
 * @return                  Shader pointer, or NULL in case of error
 */
static shader_data_t * gl_get_shader(void)
{
    static shader_data_t * __shader;

    if (__shader == NULL)
    {
        /* ...shader not found; create new one */
        CHK_ERR(__shader = gl_vbo_shader_compile(), NULL);

        TRACE(INIT, _b("shader created: %u"), shader_program(__shader));
    }

    return __shader;
}

/**
 * @brief   Return shader for given texture format
 *
 * @param   texture[in]     Texture handle
 *
 * @return                  Shader pointer, or NULL in case of error
 */
static shader_data_t * gl_get_shader_bw(void)
{
    static shader_data_t * __shader;

    if (__shader == NULL)
    {
        /* ...shader not found; create new one */
        CHK_ERR(__shader = gl_vbo_shader_compile_bw(), NULL);

        TRACE(INIT, _b("shader created: %u"), shader_program(__shader));
    }

    return __shader;
}

/**
 * @brief   Return shader for given texture format
 *
 * @param   texture[in]     Texture handle
 *
 * @return                  Shader pointer, or NULL in case of error
 */
static shader_data_t * gl_get_shader_ffc(void)
{
    static shader_data_t * __shader;

    if (__shader == NULL)
    {
        /* ...shader not found; create new one */
        CHK_ERR(__shader = gl_vbo_shader_compile_ffc(), NULL);

        TRACE(INIT, _b("shader created: %u"), shader_program(__shader));
    }

    return __shader;
}
/**
 * @brief   Render VBO mesh
 *
 * @param   vbo[in]         VBO data
 * @param   intensity[in]   Global scene intensity level
 */

#define U(id)       u[UNIFORM(VBO, id)]
#define A(id)       ATTRIBUTE(VBO, id)

static void gl_vbo_render(vbo_data_t *vbo, GLfloat intensity, bool_t bw)
{
    const size_t    UV_off = 0;
    const size_t    C_off = UV_off + 2 * sizeof(GLfloat);
    const size_t    vbo_size = sizeof(gl_vertex_t);
    shader_data_t  *shader;

    shader_data_t* (*get_shader)(void) = (bw) ? gl_get_shader_bw : gl_get_shader;

    /* ...bail out if shader is not found */
    if ((shader = get_shader()) == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %m"));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    /* ...set rendering program */
    glUseProgram(shader_program(shader));

    /* ...set global scene intensity level */
    glUniform1f(U(intensity), intensity);   GLCHECK();

    /* ...bind VBO buffer */
    glBindBuffer(GL_ARRAY_BUFFER, vbo_get_id(vbo));    GLCHECK();

    /* ...enable attributes vector */
    glEnableVertexAttribArray(A(uv));           GLCHECK();
    glVertexAttribPointer(A(uv), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)UV_off);   GLCHECK();

    glEnableVertexAttribArray(A(c));            GLCHECK();
    glVertexAttribPointer(A(c), 4, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)C_off);     GLCHECK();

    /* ...draw all points */
    glDrawArrays(GL_TRIANGLES, 0, vbo_get_num(vbo));   GLCHECK();

    TRACE(DEBUG, _b("VBO-%d: render %d points"), vbo_get_id(vbo), vbo_get_num(vbo));

    /* ...reset rendering program */
    glUseProgram(0);
}



static void gl_vbo_render_lines(vbo_data_t *vbo, GLfloat intensity)
{
    const size_t    UV_off = 0;
    const size_t    C_off = UV_off + 2 * sizeof(GLfloat);
    const size_t    vbo_size = sizeof(gl_vertex_t);
    shader_data_t  *shader;

    /* ...bail out if shader is not found */
    if ((shader = gl_get_shader()) == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %s"),strerror(errno));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    /* ...set rendering program */
    glUseProgram(shader_program(shader));

    glLineWidth(3.0f);

    /* ...set global scene intensity level */
    glUniform1f(U(intensity), intensity);   GLCHECK();

    /* ...bind VBO buffer */
    glBindBuffer(GL_ARRAY_BUFFER, vbo_get_id(vbo));    GLCHECK();

    /* ...enable attributes vector */
    glEnableVertexAttribArray(A(uv));           GLCHECK();
    glVertexAttribPointer(A(uv), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)UV_off);   GLCHECK();

    glEnableVertexAttribArray(A(c));            GLCHECK();
    glVertexAttribPointer(A(c), 4, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)C_off);     GLCHECK();

    /* ...draw all points */
    glDrawArrays(GL_LINES, 0, vbo_get_num(vbo));   GLCHECK();

    TRACE(DEBUG, _b("VBO-%d: render %d points"), vbo_get_id(vbo), vbo_get_num(vbo));

    /* ...reset rendering program */
    glUseProgram(0);
    glLineWidth(1.0f);
}

#undef  U
#undef  A



#define U(id)       u[UNIFORM(FFC, id)]
#define A(id)       ATTRIBUTE(FFC, id)

static void gl_vbo_render_ffc(vbo_data_t *vbo, GLfloat intensity, GLuint tex)
{
    const size_t    UV_off = 0;
    const size_t    C_off = UV_off + 2 * sizeof(GLfloat);
    const size_t    vbo_size = sizeof(gl_vertex_ffc_t);
    shader_data_t  *shader;

    /* ...bail out if shader is not found */
    if ((shader = gl_get_shader_ffc()) == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %s"),strerror(errno));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    /* ...set rendering program */
    glUseProgram(shader_program(shader));

    /* ...set global scene intensity level */
    glUniform1f(U(intensity), intensity);   GLCHECK();

    /* ...set sampler */
    glUniform1i(U(tex), 0);

    /* ...bind texture */
    glActiveTexture(GL_TEXTURE0);  GLCHECK();
    glBindTexture(GL_TEXTURE_2D, tex);  GLCHECK();

    /* ...bind VBO buffer */
    glBindBuffer(GL_ARRAY_BUFFER, vbo_get_id(vbo));    GLCHECK();

    /* ...enable attributes vector */
    glEnableVertexAttribArray(A(uv));           GLCHECK();
    glVertexAttribPointer(A(uv), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)UV_off);   GLCHECK();

    glEnableVertexAttribArray(A(c));            GLCHECK();
    glVertexAttribPointer(A(c), 3, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)C_off);     GLCHECK();

    /* ...draw all points */
    glDrawArrays(GL_TRIANGLES, 0, vbo_get_num(vbo));   GLCHECK();

    TRACE(DEBUG, _b("VBO-%d: render %d points"), vbo_get_id(vbo), vbo_get_num(vbo));

    /* ...reset rendering program */
    glUseProgram(0);
}

#undef  U
#undef  A

/*******************************************************************************
 * Quads encoding
 ******************************************************************************/

/**
 * @brief   Create two triangles from the adjacent point-pairs
 *
 * @param   v[in, out]      Graphical VBO pointer
 * @param   B01[in]         First two points ({0},{1}) in interleaved order:
 *                          [0]: U0:G0:U1:G1
 *                          [1]: V0:B0:V1:B1
 *                          [2]: R0:A0:R1:A1
 * @param   B23[in]         Last two points ({2},{3}) in interleaved order
 *                          [0]: U2:G2:U3:G3
 *                          [1]: V2:B2:V3:B3
 *                          [1]: R2:A2:R3:A3
 */
static inline gl_vertex_t * gl_quad_encode(gl_vertex_t *v, float32x4x3_t B01, float32x4x3_t B23)
{
    /* ...make a triangle of points {0},{1},{2} and {2},{1},{3}; place points {0},{1} first
     * [0]: U0:G0:U1:G1
     * [1]: V0:B0:V1:B1
     * [2]: R0:A0:R1:A1
     */
    vst3q_f32(*v, B01);
    v += 2;

    /* ...next two points to store are {2}, {2}:
     * [0]: U2:G2:U2:G2
     * [1]: V2:B2:V2:B2
     * [2]: R2:A2:R2:A2
     */
    float32x4x3_t   B22;
    B22.val[0] = vcombine_f32(vget_low_f32(B23.val[0]), vget_low_f32(B23.val[0]));
    B22.val[1] = vcombine_f32(vget_low_f32(B23.val[1]), vget_low_f32(B23.val[1]));
    B22.val[2] = vcombine_f32(vget_low_f32(B23.val[2]), vget_low_f32(B23.val[2]));
    vst3q_f32(*v, B22);
    v += 2;

    /* ...next two points are {1},{3}:
     * [0]: U1:G1:U3:G3
     * [1]: V1:B1:V3:B3
     * [2]: R1:A1:R3:A3
     */
    float32x4x3_t   B13;
    B13.val[0] = vcombine_f32(vget_high_f32(B01.val[0]), vget_high_f32(B23.val[0]));
    B13.val[1] = vcombine_f32(vget_high_f32(B01.val[1]), vget_high_f32(B23.val[1]));
    B13.val[2] = vcombine_f32(vget_high_f32(B01.val[2]), vget_high_f32(B23.val[2]));
    vst3q_f32(*v, B13);
    v += 2;

    return v;
}

/**
 * @brief   Load point into buffer
 *
 * @param   p[in]           Pointer to U/V coordinates
 * @param   C[in]           Color of the point
 *
 * @return                  Point buffer in interleaved order:
 *                          [0]: U0:G0
 *                          [1]: V0:B0
 *                          [2]: R0:A0
 */
static inline float32x2x3_t guide_vertex_encode(float32_t *p, float32x4_t C)
{
    float32x2x3_t   B;
    float32x2_t     P = vld1_f32(p);

    B.val[0] = vtrn1_f32(P, vget_low_f32(C));
    B.val[1] = vtrn2_f32(P, vget_low_f32(C));
    B.val[2] = vget_high_f32(C);

    return B;
}

/**
 * @brief   Load point-pair into buffer
 *
 * @param   p[in]           Pointer to U/V coordinates
 * @param   C0[in]          Color of first point
 * @param   C1[in]          Color of second point
 *
 * @return                  Point-pair buffer in interleaved order:
 *                          [0]: U0:G0:U1:G1
 *                          [1]: V0:B0:V1:B1
 *                          [2]: R0:A0:R1:A1
 */
static inline float32x4x3_t guide_vertex_pair_encode(float32_t (*p)[2], float32x4_t C0, float32x4_t C1)
{
    /* ...load vertex-pair:
     * [0] = { U0, V0 }
     * [1] = { U1, V1 }
     */
    float32x2_t     P0 = vld1_f32(p[0]);
    float32x2_t     P1 = vld1_f32(p[1]);

    /* ...put vertices into buffer:
     * [0] = { U0, G0, U1, G1 }
     * [1] = { V0, B0, V1, B1 }
     * [2] = { R0, A0, R1, A1 }
     */
    float32x4x3_t   B;
    B.val[0] = vcombine_f32(vtrn1_f32(P0, vget_low_f32(C0)), vtrn1_f32(P1, vget_low_f32(C1)));
    B.val[1] = vcombine_f32(vtrn2_f32(P0, vget_low_f32(C1)), vtrn2_f32(P1, vget_low_f32(C1)));
    B.val[2] = vcombine_f32(vget_high_f32(C0), vget_high_f32(C1));

    return B;
}

/**
 * @brief   Load point-pair into buffer
 *
 * @param   p[in]           Pointer to U/V coordinates
 * @param   C0[in]          Color of first point
 * @param   C1[in]          Color of second point
 *
 * @return                  Point-pair buffer in interleaved order:
 *                          [0]: U0:G0:U1:G1
 *                          [1]: V0:B0:V1:B1
 *                          [2]: R0:A0:R1:A1
 */
static inline float32x4x3_t guide_vertex_pair_encode_2(float32_t (*p0)[2], float32_t (*p1)[2], float32x4_t C0, float32x4_t C1)
{
    /* ...load vertex-pair:
     * [0] = { U0, V0 }
     * [1] = { U1, V1 }
     */
    float32x2_t     P0 = vld1_f32(*p0);
    float32x2_t     P1 = vld1_f32(*p1);

    /* ...put vertices into buffer:
     * [0] = { U0, G0, U1, G1 }
     * [1] = { V0, B0, V1, B1 }
     * [2] = { R0, A0, R1, A1 }
     */
    float32x4x3_t   B;
    B.val[0] = vcombine_f32(vtrn1_f32(P0, vget_low_f32(C0)), vtrn1_f32(P1, vget_low_f32(C1)));
    B.val[1] = vcombine_f32(vtrn2_f32(P0, vget_low_f32(C1)), vtrn2_f32(P1, vget_low_f32(C1)));
    B.val[2] = vcombine_f32(vget_high_f32(C0), vget_high_f32(C1));

    return B;
}

/**
 * @brief   Encode single quad
 *
 * @param   v[in, out]      VBO pointer
 * @param   B01[in]         First two points ({0},{1}) in interleaved order:
 *                          [0]: U0:G0:U1:G1
 *                          [1]: V0:B0:V1:B1
 *                          [2]: R0:A0:R1:A1
 * @param   B23[in]         Last two points ({2},{3}) in interleaved order
 *                          [0]: U2:G2:U3:G3
 *                          [1]: V2:B2:V3:B3
 *                          [1]: R2:A2:R3:A3
 *
 * @return                  Updated VBO pointer
 */
static inline gl_vertex_t * guide_add_quad(gl_vertex_t *v, float32x4x3_t B01, float32x4x3_t B23)
{
    /* ...place vertices {0},{1} */
    vst3q_f32(*v, B01);
    v += 2;

    /* ...place vertices {2},{2} */
    float32x4x3_t   B22;
    B22.val[0] = vcombine_f32(vget_low_f32(B23.val[0]), vget_low_f32(B23.val[0]));
    B22.val[1] = vcombine_f32(vget_low_f32(B23.val[1]), vget_low_f32(B23.val[1]));
    B22.val[2] = vcombine_f32(vget_low_f32(B23.val[2]), vget_low_f32(B23.val[2]));
    vst3q_f32(*v, B22);
    v += 2;

    /* ...place vertices {1},{3} */
    float32x4x3_t   B13;
    B13.val[0] = vcombine_f32(vget_high_f32(B01.val[0]), vget_high_f32(B23.val[0]));
    B13.val[1] = vcombine_f32(vget_high_f32(B01.val[1]), vget_high_f32(B23.val[1]));
    B13.val[2] = vcombine_f32(vget_high_f32(B01.val[2]), vget_high_f32(B23.val[2]));
    vst3q_f32(*v, B13);
    v += 2;

    return v;
}

/**
 * @brief   Carpet generation
 */
static gl_vertex_t * guide_add_carpet(
    gl_vertex_t *v,
    float32_t (*left)[2][2],
    float32_t (*right)[2][2],
    float32_t (*top)[2][2],
    float32_t (*bottom)[2][2],
    int32_t N,
    int32_t M,
    float32_t *color)
{
    int32_t         i;

    /* ...carpet color: {GBRA} */
    float32x4_t     C = vld1q_f32(color);

    /* ...central point buffer */
    float32_t       center[2] = {
        ((*left)[0][0] + (*right)[N - 1][0]) * 0.5f,
        ((*left)[0][1] + (*right)[N - 1][1]) * 0.5f,
    };

    float32x2x3_t   B0 = guide_vertex_encode(center, C);

    /* ...first triangle point */
    float32x2x3_t   B1 = guide_vertex_encode((*left++)[0], C);

    /* ...left edge */
    for (i = 1; i < N; i++)
    {
        float32x2x3_t   B2 = guide_vertex_encode((*left++)[0], C);

        vst3_f32(*v++, B0);
        vst3_f32(*v++, B1);
        vst3_f32(*v++, B2);

        B1 = B2;
    }

    /* ...top edge */
    for (i = 1; i < M; i++)
    {
        float32x2x3_t   B2 = guide_vertex_encode((*++top)[0], C);

        vst3_f32(*v++, B0);
        vst3_f32(*v++, B1);
        vst3_f32(*v++, B2);
        B1 = B2;
    }

    /* ...right edge */
    for (i = 1, right += N - 1; i < N; i++)
    {
        float32x2x3_t   B2 = guide_vertex_encode((*--right)[0], C);

        vst3_f32(*v++, B0);
        vst3_f32(*v++, B1);
        vst3_f32(*v++, B2);
        B1 = B2;
    }

    /* ...bottom edge */
    for (i = 1, bottom += M - 1; i < M; i++)
    {
        float32x2x3_t   B2 = guide_vertex_encode((*--bottom)[0], C);

        vst3_f32(*v++, B0);
        vst3_f32(*v++, B1);
        vst3_f32(*v++, B2);
        B1 = B2;
    }

    return v;
}

/**
 * @brief   Draw a segmented line of specified color and width
 *
 * @param   v[in]           Guideline vertex buffer object pointer
 * @param   uv[in]          Array of point-pairs defining a reference point
 *                          and normale direction
 * @param   count[in]       Number of point-pairs in array
 * @param   color[in]       Line color
 * @param   width[in]       Line width in normale direction
 */
static gl_vertex_t * guide_add_vertical_line(gl_vertex_t *v, float32_t (*uv)[2][2], uint32_t count, float32_t fade0, float32_t fade1, float32_t *color)
{
    float32x2x2_t   T0, T1;

    /* ...load main color (GBRA) */
    float32x4_t     C = vld1q_f32(color);

    float32_t       dr0 = (fade0 > 0.f ? 1.0f / fade0 : 1.0f);
    float32_t       dr1 = (fade1 > 0.f ? 1.0f / fade1 : 1.0f);
    float32_t       ratio0 = (fade0 > 0.f ? 0.0f : 1.0f);
    float32_t       ratio1 = (fade1 > 0.f ? (count - 1) * dr1 : count);
    float32_t       ratio = MIN(MIN(ratio0, ratio1), 1.0f);
    float32_t       alpha = vgetq_lane_f32(C, 3);
    float32x4_t     CC = vsetq_lane_f32(alpha * ratio, C, 3);
    uint32_t        i;

    float32x4x3_t   B01 = guide_vertex_pair_encode(*uv++, CC, CC);
    float32x4x3_t   B23;

    ratio0 += dr0;
    ratio1 -= dr1;

    for (i = 1; i < count; i++)
    {
        ratio = MIN(MIN(ratio0, ratio1), 1.0f);
        CC = vsetq_lane_f32(alpha * ratio, C, 3);
        B23 = guide_vertex_pair_encode(*uv++, CC, CC);

        /* ...store quad */
        v = guide_add_quad(v, B01, B23);

        ratio0 += dr0;
        ratio1 -= dr1;

        /* ...move to next quad */
        B01 = B23;
    }

    return v;
}


/**
 * @brief   Draw a segmented line of specified color and width
 *
 * @param   v[in]           Guideline vertex buffer object pointer
 * @param   uv[in]          Array of point-pairs defining a reference point
 *                          and normale direction
 * @param   count[in]       Number of point-pairs in array
 * @param   color[in]       Line color
 * @param   width[in]       Line width in normale direction
 */
static gl_vertex_t * guide_add_vertical_line_2_colors(gl_vertex_t *v, float32_t (*uv)[2][2], uint32_t count, float32_t fade0, float32_t fade1)
{
    float32x2x2_t   T0, T1;

    float32_t black = 0;
    float32_t white = 1;
    /* ...load main color (GBRA) */
    float32x4_t     C1 = vld1q_dup_f32(&white);
    float32x4_t     C2 = vld1q_dup_f32(&black);

    float32_t       dr0 = (fade0 > 0.f ? 1.0f / fade0 : 1.0f);
    float32_t       dr1 = (fade1 > 0.f ? 1.0f / fade1 : 1.0f);
    float32_t       ratio0 = (fade0 > 0.f ? 0.0f : 1.0f);
    float32_t       ratio1 = (fade1 > 0.f ? (count - 1) * dr1 : count);
    float32_t       ratio = MIN(MIN(ratio0, ratio1), 1.0f);
    float32_t       alpha = vgetq_lane_f32(C1, 3);
    float32x4_t     CC1 = vsetq_lane_f32(alpha * ratio, C1, 3);
    float32x4_t     CC2 = vsetq_lane_f32(alpha * ratio, C2, 3);
    uint32_t        i;

    float32x4x3_t   B01 = guide_vertex_pair_encode(*uv++, CC1, CC2);
    float32x4x3_t   B23;

    ratio0 += dr0;
    ratio1 -= dr1;

    for (i = 1; i < count; i++)
    {
        ratio = MIN(MIN(ratio0, ratio1), 1.0f);
        CC1 = vsetq_lane_f32(alpha * ratio, C1, 3);
        CC2 = vsetq_lane_f32(alpha * ratio, C2, 3);
        B23 = guide_vertex_pair_encode(*uv++, CC1, CC2);

        /* ...store quad */
        v = guide_add_quad(v, B01, B23);

        ratio0 += dr0;
        ratio1 -= dr1;

        /* ...move to next quad */
        B01 = B23;
    }

    return v;
}


/**
 * @brief   Draw a segmented line of specified color and width
 *
 * @param   v[in]           Guideline vertex buffer object pointer
 * @param   uv[in]          Array of point-pairs defining a reference point
 *                          and normale direction
 * @param   count[in]       Number of point-pairs in array
 * @param   color[in]       Line color
 * @param   width[in]       Line width in normale direction
 */
static gl_vertex_ffc_t * guide_add_vertical_line_tex(gl_vertex_ffc_t *v
    ,float32_t (*uv0)[2]
    ,float32_t (*uv1)[2]
    ,float32_t tex_step
    ,float32_t tex_x0
    ,float32_t tex_x1
    ,uint32_t count
    ,float32_t right_offset)
{
    uint32_t i;

    for (i = 1; i < count; i++)
    {
        v[0][0] = uv0[i - 1][0];
        v[0][1] = uv0[i - 1][1];
        v[0][4] = 0;
        v[1][0] = uv1[i - 1][0];
        v[1][1] = uv1[i - 1][1];
        v[1][4] = 0;
        v[2][0] = uv0[i][0];
        v[2][1] = uv0[i][1];
        v[2][4] = 0;
        v[3][0] = uv0[i][0];
        v[3][1] = uv0[i][1];
        v[3][4] = 0;
        v[4][0] = uv1[i - 1][0];
        v[4][1] = uv1[i - 1][1];
        v[4][4] = 0;
        v[5][0] = uv1[i][0];
        v[5][1] = uv1[i][1];
        v[5][4] = 0;

        v[0][2] = v[2][2] = v[3][2] = tex_x0;
        v[1][2] = v[4][2] = v[5][2] = tex_x1;

        v[0][3] = v[1][3] = v[4][3] = tex_step*(i-1);
        v[2][3] = v[3][3] = v[5][3] = tex_step*i;

        {
            v[0][3]+= right_offset*tex_x0;
            v[2][3]+= right_offset*tex_x0;
            v[3][3]+= right_offset*tex_x0;
        }
        {
            v[1][3]+= right_offset*tex_x1;
            v[4][3]+= right_offset*tex_x1;
            v[5][3]+= right_offset*tex_x1;
        }

        v += 6;
    }

    return v;
}

static gl_vertex_t * put_line_c(gl_vertex_t *_v, float32_t *uv0, float32_t *uv1, uint32_t count, float32_t *color)
{
    float32_t* v = (float32_t*)_v;
    uint32_t vlen = 6;
    uint32_t qlen = vlen*4;

    uint32_t i = 0;
    uint32_t j = 0;

    float32_t* uv[2] = {uv0, uv1};

    uint32_t indxs[4][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1},
    };

    
    for (i = 0; i < (count - 1); i++)
    {
        for (j = 0; j < 4; j++)
        {
            float32_t* p_uv = uv[indxs[j][0]];
            v[i*qlen + j*vlen + 0] = p_uv[indxs[j][1]*2 + 0];
            v[i*qlen + j*vlen + 1] = p_uv[indxs[j][1]*2 + 1];
            v[i*qlen + j*vlen + 3] = color[0];
            v[i*qlen + j*vlen + 4] = color[1];
            v[i*qlen + j*vlen + 2] = color[2];
            v[i*qlen + j*vlen + 5] = color[3];
        }

        uv[0]+=2;
        uv[1]+=2;
    }

    return (gl_vertex_t*)(v + i*qlen);
}

/**
 * @brief   Draw a segmented line of specified color and width
 *
 * @param   v[in]           Guideline vertex buffer object pointer
 * @param   uv[in]          Array of point-pairs defining a reference point
 *                          and normale direction
 * @param   count[in]       Number of point-pairs in array
 * @param   color[in]       Line color
 * @param   width[in]       Line width in normale direction
 */
static gl_vertex_t * guide_add_vertical_line_2(gl_vertex_t *v, float32_t (*uv0)[2], float32_t (*uv1)[2], uint32_t count, float32_t fade0, float32_t fade1, float32_t *color)
{
    float32x2x2_t   T0, T1;

    /* ...load main color (GBRA) */
    float32x4_t     C = vld1q_f32(color);

    float32_t       dr0 = (fade0 > 0.f ? 1.0f / fade0 : 1.0f);
    float32_t       dr1 = (fade1 > 0.f ? 1.0f / fade1 : 1.0f);
    float32_t       ratio0 = (fade0 > 0.f ? 0.0f : 1.0f);
    float32_t       ratio1 = (fade1 > 0.f ? (count - 1) * dr1 : count);
    float32_t       ratio = MIN(MIN(ratio0, ratio1), 1.0f);
    float32_t       alpha = vgetq_lane_f32(C, 3);
    float32x4_t     CC = vsetq_lane_f32(alpha * ratio, C, 3);
    uint32_t        i;

    float32x4x3_t   B01 = guide_vertex_pair_encode_2(uv0++, uv1++, CC, CC);
    float32x4x3_t   B23;

    ratio0 += dr0;
    ratio1 -= dr1;

    for (i = 1; i < count; i++)
    {
        ratio = MIN(MIN(ratio0, ratio1), 1.0f);
        CC = vsetq_lane_f32(alpha * ratio, C, 3);
        B23 = guide_vertex_pair_encode_2(uv0++, uv1++, CC, CC);

        /* ...store quad */
        v = guide_add_quad(v, B01, B23);

        ratio0 += dr0;
        ratio1 -= dr1;

        /* ...move to next quad */
        B01 = B23;
    }

    return v;
}

/**
 * @brief   Draw a segmented line of specified color and width
 *
 * @param   v[in]           Guideline vertex buffer object pointer
 * @param   uv[in]          Array of point-pairs defining a reference point
 *                          and normale direction
 * @param   count[in]       Number of point-pairs in array
 * @param   color[in]       Line color
 * @param   width[in]       Line width in normale direction
 */
static gl_vertex_t * guide_add_vertical_line_stl(gl_vertex_t *v, float32_t (*uv0)[2], float32_t (*uv1)[2], uint32_t count, uint32_t N0, uint32_t N1, float32_t *color)
{
    float32x2x2_t   T0, T1;

    /* ...load main color (GBRA) */
    float32x4_t     C0 = vld1q_f32(color);
    float32x4_t     C1 = vld1q_f32(color + 4);
    float32x4_t     C2 = vld1q_f32(color + 8);

    uint32_t        i;

    float32x4_t CC = C0;
    float32x4x3_t   B01 = guide_vertex_pair_encode_2(uv0, uv1, CC, CC);
    float32x4x3_t   B23;

    for (i = 1; i < count; i++)
    {
        if (i == (N1 + 1) || (i == (N0 + 1)))
        {
            CC = (i == (N1 + 1)) ? C2 : C1;
            B01 = guide_vertex_pair_encode_2(uv0, uv1, CC, CC);
        }

        uv0++;
        uv1++;

        B23 = guide_vertex_pair_encode_2(uv0, uv1, CC, CC);

        /* ...store quad */
        v = guide_add_quad(v, B01, B23);

        /* ...move to next quad */
        B01 = B23;
    }

    return v;
}

/**
 * @brief   Draw a dash line with tha gaps
 *
 * @param   v[in]           Guideline vertex buffer object pointer
 * @param   uv[in]          Array of point-pairs defining a reference point
 *                          and normale direction
 * @param   count[in]       Number of point-pairs in array
 * @param   N[in]           points number in one block
 * @param   color[in]       Line color
 * @param   width[in]       Line width in normale direction
 */
static gl_vertex_t * guide_add_vertical_line_dash(gl_vertex_t *v, float32_t (*uv0)[2], float32_t (*uv1)[2], uint32_t count, uint32_t N, float32_t *color)
{
    float32x2x2_t   T0, T1;

    /* ...load main color (GBRA) */
    float32x4_t     C1 = vld1q_f32(color + 0);
    float32x4_t     C2 = vld1q_f32(color + 4);

    uint32_t        i;

    float32x4_t CC = C1;
    float32x4x3_t   B01;
    float32x4x3_t   B23;

    for (i = 1; i < count; i++)
    {
        CC = ( ((i - 1) / N) % 2) ? C2 : C1;
        B01 = guide_vertex_pair_encode_2(uv0, uv1, CC, CC);
        B23 = guide_vertex_pair_encode_2(uv0 + 1, uv1 + 1, CC, CC);
        uv0++;
        uv1++;
        /* ...store quad */
        v = guide_add_quad(v, B01, B23);

        /* ...move to next quad */
        B01 = B23;
    }

    return v;
}


/**
 * @brief   Draw a segmented line of specified color and width
 *
 * @param   v[in]           Guideline vertex buffer object pointer
 * @param   uv[in]          Array of point-pairs defining a reference point
 *                          and normale direction
 * @param   count[in]       Number of point-pairs in array
 * @param   color[in]       Line color
 * @param   width[in]       Line width in normale direction
 */
static gl_vertex_t * guide_add_horizontal_line_stl(gl_vertex_t *v, float32_t (*uv0)[2], float32_t (*uv1)[2], uint32_t count, float32_t *color)
{
    float32x2x2_t   T0, T1;

    /* ...load main color (GBRA) */
    float32x4_t     CC = vld1q_f32(color);

    uint32_t        i;

    float32x4x3_t   B01 = guide_vertex_pair_encode_2(uv0, uv1, CC, CC);
    float32x4x3_t   B23;

    for (i = 1; i < count; i++)
    {
        uv0++;
        uv1++;

        B23 = guide_vertex_pair_encode_2(uv0, uv1, CC, CC);

        /* ...store quad */
        v = guide_add_quad(v, B01, B23);

        /* ...move to next quad */
        B01 = B23;
    }

    return v;
}

/**
 * @brief   Draw a segmented line of specified color and width
 *
 * @param   v[in]           Guideline vertex buffer object pointer
 * @param   uv[in]          Array of point-pairs defining a reference point
 *                          and normale direction
 * @param   count[in]       Number of point-pairs in array
 * @param   color[in]       Line color
 * @param   width[in]       Line width in normale direction
 */
static gl_vertex_t * guide_add_horizontal_line(gl_vertex_t *v, float32_t (*uv)[2][2], uint32_t count, float32_t *color)
{
    float32x4_t     C0 = vld1q_f32(color); /* GBRA */
    float32x4_t     C1 = vsetq_lane_f32(0.0f, C0, 3);
    float32x4x3_t   B01 = guide_vertex_pair_encode(*uv++, C0, C1);
    float32x4x3_t   B23;
    uint32_t        i;

    for (i = 1; i < count; i++)
    {
        B23 = guide_vertex_pair_encode(*uv++, C0, C1);

        /* ...store quad */
        v = guide_add_quad(v, B01, B23);

        /* ...move to next quad */
        B01 = B23;
    }

    return v;
}

/**
 * @brief   Draw a segmented line of specified color and width
 *
 * @param   v[in]           Guideline vertex buffer object pointer
 * @param   uv[in]          Array of point-pairs defining a reference point
 *                          and normale direction
 * @param   count[in]       Number of point-pairs in array
 * @param   color[in]       Line color
 * @param   width[in]       Line width in normale direction
 */
static gl_vertex_t * guide_add_horizontal_line_2(gl_vertex_t *v, float32_t (*uv0)[2], float32_t (*uv1)[2], uint32_t count, float32_t *color, float32_t alpha)
{
    float32x4_t     C0 = vld1q_f32(color); /* GBRA */
    float32x4_t     C1 = vsetq_lane_f32(alpha, C0, 3);
    float32x4x3_t   B01 = guide_vertex_pair_encode_2(uv0++, uv1++, C0, C1);
    float32x4x3_t   B23;
    uint32_t        i;

    for (i = 1; i < count; i++)
    {
        B23 = guide_vertex_pair_encode_2(uv0++, uv1++, C0, C1);

        /* ...store quad */
        v = guide_add_quad(v, B01, B23);

        /* ...move to next quad */
        B01 = B23;
    }

    return v;
}


/*******************************************************************************
 * Internal functions implementation
 ******************************************************************************/

/**
 * @brief   Prepare guidelines generator
 *
 * @param   gen[in]         Guideline generator data
 * @param   dst[in]         Destination tile
 * @param   guide[in]       Guideline data
 */
static inline void guide_gen_prepare(guide_gen_t *gen, int32_t *dst, guide_data_t *guide)
{
    /* ...reset VBO dynarray */
    vbo_dynarray_clear(&gen->vbo, sizeof(gl_vertex_t));
    vbo_dynarray_clear(&gen->vbo_bw, sizeof(gl_vertex_t));
    vbo_dynarray_clear(&gen->vbo_ffc, sizeof(gl_vertex_ffc_t));
    vbo_dynarray_clear(&gen->vbo_hatched, sizeof(gl_vertex_ffc_t));
    vbo_dynarray_clear(&gen->vbo_lines, sizeof(gl_vertex_t));

    /* ...copy destination tile (pointer shall be enough? - tbd) */
    memcpy(guide->dst, dst, sizeof(int32_t [4]));
}


/**
 * @brief   Finalize VBO preparation
 *
 * @param   src[in]         Guidelines generator data
 * @param   dst[out]        VBO
 */
static int vbo_sync(vbo_dynarray_t *src, vbo_data_t **dst, uint32_t elem)
{
    vbo_dynarray_t *vbo = src;
    void    *buffer = vbo_dynarray_buffer(vbo, elem);
    int             r = 0;

    /* ...upload points into VBO */
    if (*dst == NULL)
    {
        if ((dst[0] = vbo_create(elem, vbo_dynarray_num(vbo), buffer)) == NULL)
        {
            TRACE(ERROR, _x("failed to create VBO[num=%u]: %s"), vbo_dynarray_num(vbo), strerror(errno));
            r = -1;
        }
    }
    else
    {
        /* ...upload buffer into GL VBO */
        if (vbo_upload(dst[0], buffer, vbo_dynarray_num(vbo)) < 0)
        {
            TRACE(ERROR, _x("failed to upload VBO[num=%u]: %s"), vbo_dynarray_num(vbo), strerror(errno));
            r = -1;
        }
    }

    TRACE(DEBUG, _b("vbo size: %u"), vbo->size);

    return r;
}

/**
 * @brief   Finalize VBO preparation
 *
 * @param   gen[in]         Guidelines generator data
 * @param   guide[in]       Guidelines data
 */
static int guide_gen_finalize(guide_gen_t *gen, guide_data_t *guide)
{
    int ret = vbo_sync(&gen->vbo_bw, &guide->vbo_bw, sizeof(gl_vertex_t));

    if (ret == 0)
    {
        ret = vbo_sync(&gen->vbo, &guide->vbo, sizeof(gl_vertex_t));
    }

    if (ret == 0)
    {
        ret = vbo_sync(&gen->vbo_ffc, &guide->vbo_ffc, sizeof(gl_vertex_ffc_t));
    }

    if (ret == 0)
    {
        ret = vbo_sync(&gen->vbo_hatched, &guide->vbo_hatched, sizeof(gl_vertex_ffc_t));
    }

    if (ret == 0)
    {
        ret = vbo_sync(&gen->vbo_lines, &guide->vbo_lines, sizeof(gl_vertex_t));
    }

    return ret;
}

/**
 * @brief   Prepare virtual camera for given single-view configuration
 *
 * @param   vcam[in]        Virtual camera data
 * @param   scv[in]         SCV-configuration data
 */
static inline void guide_prepare_vcam(vcamera_data_t *vcam, cfg_scv_mesh_t *scv, vehicle_state_t *vehicle)
{
    float32_t   rotation[3];
    float32_t   fov[4];

    /* ...set rotation angles */
    rotation[0] = scv->rotation[0];
    rotation[1] = scv->rotation[1];
    rotation[2] = scv->rotation[2] + scv->yaw_adj_coef * vehicle->steering;

    /* ...set field of view parameters */
    fov[0] = scv->fov[0] + scv->fov_adj_coef[0] * fabsf(vehicle->steering);
    fov[1] = scv->fov[1] + scv->fov_adj_coef[1] * fabsf(vehicle->steering);
    fov[2] = scv->fov[2] + scv->fov_adj_coef[2] * vehicle->steering;
    fov[3] = scv->fov[3] + scv->fov_adj_coef[3] * vehicle->steering;

    /* ...initialize virtual camera */
    vcamera_init(vcam, rotation, scv->position, fov, scv->distortion, scv->compression);
}

/**
 * @brief   Prepare virtual camera for given single-view configuration
 *
 * @param   vcam[in]        Virtual camera data
 * @param   scv[in]         SCV-configuration data
 */
static inline void guide_prepare_stv_vcam(vcamera_data_t *vcam, cfg_stv_mesh_t *stv)
{
    float32_t   dist[2] = { 0.0f, 0.0f };
    float32_t   comp[2] = { 1.0f, 1.0f };
    float32_t   fov[4];

    fov[0] = stv->fov[0];
    fov[1] = stv->fov[1];
    fov[2] = 0.0f;
    fov[3] = 0.0f;

    /* ...initialize virtual camera (no distortion) */
    vcamera_init(vcam, stv->rotation, stv->position, fov, dist, comp);
}

/**
 * @brief   Translate 3D-coordinates in world-space into 2D virtual camera space
 *
 * @param   vcam[in]        Virtual camera data
 * @param   points[in]      Array of 3D-points in world coordinate system
 * @param   coords[out]     Array of 2D-points in virtual camera sensor space
 * @param   count[in]       Number of points in array
 */
static void guide_vcam_project(vcamera_data_t *vcam, float32_t (*points)[3], float32_t (*coords)[2], uint32_t count)
{
    /* ...in-place transform set of points to virtual camera coordinate system */
    map_world_to_cam(points, vcam->T, vcam->R, count, points);

    /* ...distort points into virtual camera space */
    vcamera_distort(vcam, points, coords, count);
}

/**
 * @brief   Translate 3D-coordinates in world-space into 2D virtual camera space
 *
 * @param   vcam[in]        Virtual camera data
 * @param   points[in]      Array of 3D-points in world coordinate system
 * @param   coords[out]     Array of 2D-points in virtual camera sensor space
 * @param   count[in]       Number of points in array
 */
static void guide_vcam_project_adv(vcamera_data_t *vcam, float32_t (*points)[3], float32_t (*coords)[2], uint32_t count)
{
    /* ...in-place transform set of points to virtual camera coordinate system */
    map_world_to_cam(points, vcam->T, vcam->R, count, points);
    /* ...distort points into virtual camera space */
    vcamera_distort(vcam, points, coords, count);



}

/**
 * @brief   Prepare color in GBRA format
 *
 * @param   color[out]          GBRA vector
 * @param   rgb[in]             RGB-components
 * @param   transmittance[in]   Transmittance in percents
 */
static void guide_set_color(float32_t *color, uint8_t rgb[3], uint8_t transmittance)
{
    color[0] = (float32_t)rgb[1] / 255.0f;
    color[1] = (float32_t)rgb[2] / 255.0f;
    color[2] = (float32_t)rgb[0] / 255.0f;
    color[3] = 1.0f - (float32_t)transmittance * 0.01f;
}

/**
 * @brief   Calculate instant rotation matrix (center and radius)
 *
 * @param   cfg[in]         Global configuration data pointer
 * @param   angle[in]       Wheel angle, rad
 * @param   step[in]        Advance along vehicle path, mm
 * @param   R[out]          Rotation matrix
 */
static void guide_instant_rotation_params(const cfg_data_t *cfg, float32_t angle, float32_t step, __mat3x3 R)
{
    /* ...check if angle is within 0.25 degrees */
    if (fabsf(angle) < (float32_t)(0.25 * M_PI / 180.0))
    {
        /* ...no curvature; build simple translation matrix */
        __mat3x3_identity(R);
        __M(3, R, 0, 2) = -step;
    }
    else
    {
        /* ...calculate instant rotation center coordinates */
        float32_t   r = cfg->vehicle.wheel_base / tanf(angle);
        float32_t   t = 0;

        /* ...we want to have incremental rotation to be equal to "step" */
        float32_t   dphi = step / r;
        float32_t   c = cosf(dphi);
        float32_t   s = sinf(dphi);

        TRACE(0, _b("Cxy=%f, %f, dphi=%f"), r, t, dphi);

        /* ...rotation angle is non-zero; calculate rotation/translation matrix */
        __M(3, R, 0, 0) = c;
        __M(3, R, 0, 1) = s;
        __M(3, R, 1, 0) = -s;
        __M(3, R, 1, 1) = c;

        /* ...translation component */
        __M(3, R, 0, 2) = t * (1 - c) - r * s;
        __M(3, R, 1, 2) = r * (1 - c) + t * s;

        /* ...last row of affine transformation matrix (not needed really) */
        __M(3, R, 2, 0) = 0.0f;
        __M(3, R, 2, 1) = 0.0f;
        __M(3, R, 2, 2) = 1.0f;
    }
}

/**
 * @brief   Generate fixed guidelines overlay for front/front-wide view
 *
 * @param   gen[in]         Guidelines generator handle
 * @param   cfg[in]         Global configuration data
 * @param   vcam[in]        Virtual camera handle
 * @param   front[in]       Front-view flag
 * @param   narrow[in]      Narrow-view flag
 *
 * @return                  Negative on failure
 */
static int guide_gen_fixed_line(guide_gen_t *gen, cfg_data_t *cfg, vcamera_data_t *vcam, int front, int narrow)
{
    cfg_guide_fixed_fr_t   *fixed;

    if (front)
    {
        fixed = (narrow ? &cfg->guide.fixed_front : &cfg->guide.fixed_front_wide);
    }
    else
    {
        fixed = (narrow ? &cfg->guide.fixed_rear : &cfg->guide.fixed_rear_wide);
    }

    const int       N = 32;
    const int       M = 32;

    float32_t       points[2 * N + 3 * M][2][3];
    float32_t     (*p_left)[2][3] = &points[0];
    float32_t     (*p_right)[2][3] = p_left + N;
    float32_t     (*p_center)[2][3] = p_right + N;
    float32_t     (*p_top)[2][3] = p_center + M;
    float32_t     (*p_bottom)[2][3] = p_top + M;

    float32_t       coords[2 * N + 3 * M][2][2];
    float32_t     (*c_left)[2][2] = &coords[0];
    float32_t     (*c_right)[2][2] = c_left + N;
    float32_t     (*c_center)[2][2] = c_right + N;
    float32_t     (*c_top)[2][2] = c_center + M;
    float32_t     (*c_bottom)[2][2] = c_top + M;

    vbo_dynarray_t *vbo = &gen->vbo;
    gl_vertex_t    *v;
    float32_t       x0, x1, xc, sx;
    float32_t       y0, y1, sy;
    int             i;

    /* ...set initial X-coordinate position and step along X */
    if (front)
    {
        /* ...front-view fixed line */
        x0 = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + fixed->front_gap;
        xc = x0 + fixed->close_section_length;
        x1 = x0 + fixed->total_length;
        sx = fixed->total_length / (float32_t)(N - 1);
    }
    else
    {
        /* ...rear-view fixed line */
        x0 = -cfg->vehicle.rear_overhang - fixed->rear_gap;
        xc = x0 - fixed->close_section_length;
        x1 = x0 - fixed->total_length;
        sx = -fixed->total_length / (float32_t)(N - 1);
    }

    /* ...initial Y-coordinates always depend on the vehicle width including mirrors */
    y0 = -(y1 = fixed->total_width * 0.5f);
    sy = (y1 - y0) / (float32_t)(M - 1);

    float32_t   X0 = x0;
    float32_t   line_width = fixed->line_width;

    /* ...left/right lines generation */
    for (i = 0; i < N; i++)
    {
        /* ...set reference point on the trajectory */
        (*p_left)[0][0] = x0, (*p_left)[0][1] = y0, (*p_left)[0][2] = 0.0f;
        (*p_left)[1][0] = x0, (*p_left)[1][1] = y0 + line_width, (*p_left)[1][2] = 0.0f;
        (*p_right)[0][0] = x0, (*p_right)[0][1] = y1, (*p_right)[0][2] = 0.0f;
        (*p_right)[1][0] = x0, (*p_right)[1][1] = y1 - line_width, (*p_right)[1][2] = 0.0f;

        /* ...advance point position */
        x0 += sx;

        p_left++, p_right++;
    }

    int32_t     close_n = (int32_t)ceilf((float32_t)N * (fixed->fade_section_start_length / fixed->total_length));
    int32_t     far_n = (int32_t)ceilf((float32_t)N * (fixed->fade_section_end_length / fixed->total_length));

    close_n = MIN(close_n, N);
    far_n = MIN(far_n, N);

    float32_t   xb = X0 + sx * close_n;
    float32_t   xt = x1 - sx * far_n;

    /* ...top/bottom lines generation */
    for (i = 0; i < M ; i++)
    {
        /* ...set reference point on the trajectory */
        (*p_top)[0][0] = xt, (*p_top)[0][1] = y0, (*p_top)[0][2] = 0.0f;
        (*p_top)[1][0] = x1, (*p_top)[1][1] = y0, (*p_top)[1][2] = 0.0f;

        (*p_bottom)[0][0] = xb, (*p_bottom)[0][1] = y0, (*p_bottom)[0][2] = 0.0f;
        (*p_bottom)[1][0] = X0, (*p_bottom)[1][1] = y0, (*p_bottom)[1][2] = 0.0f;

        /* ...advance point position */
        y0 += sy;

        p_top++, p_bottom++;
    }

    /* ...central/top/bottom lines generation */
    float32_t   close_line_width = (narrow ? fixed->close_interlock_width : fixed->surface_close_width);
    float32_t   close_line_gap = (narrow ? fixed->close_interlock_gap : fixed->surface_close_gap);

    /* ...for front-view, invert width */
    (front ? close_line_width = -close_line_width : 0);

    y0 = -(y1 = fixed->total_width * 0.5f - close_line_gap);
    sy = (y1 - y0) / (float32_t)(M - 1);

    for (i = 0; i < M ; i++)
    {
        /* ...set reference point on the trajectory */
        (*p_center)[0][0] = xc, (*p_center)[0][1] = y0, (*p_center)[0][2] = 0.0f;
        (*p_center)[1][0] = xc + close_line_width, (*p_center)[1][1] = y0, (*p_center)[1][2] = 0.0f;

        /* ...advance point position */
        y0 += sy;

        p_center++;
    }

    /* ...project points into virtual camera sensor space */
    guide_vcam_project(vcam, &points[0][0], &coords[0][0], (N * 2 + M * 3) * 2);

    float32_t   surface_color[4], surface_close_color[4], line_color[4];
    guide_set_color(surface_color, cfg->guide.static_surface_color, cfg->guide.static_surface_transmittance);
    guide_set_color(line_color, cfg->guide.static_line_color, cfg->guide.static_line_transmittance);
    guide_set_color(surface_close_color, cfg->guide.static_surface_close_color, cfg->guide.static_surface_close_transmittance);

    int32_t     N2 = MAX(N - (far_n + close_n), 0);
    uint32_t    vnum = 3 * (M - 1) * 6 + 2 * (N - 1) * 6;

    /* ...reserve buffer for carpet generation */
    (N2 > 1 ? vnum += 6 * (N2 - 1) + 6 * (M - 1) : 0);

    /* ...reserve vertices in a buffer */
    CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), vnum), -1);

    /* ...add carpet as needed */
    if (N2 > 1)
    {
        v = guide_add_carpet(v, c_left + close_n, c_right + close_n, c_top, c_bottom, N2, M, surface_color);
    }

    /* ...add top/bottom carpet faded sections */
    v = guide_add_horizontal_line(v, c_top, M, surface_color);
    v = guide_add_horizontal_line(v, c_bottom, M, surface_color);

    /* ...add right/left static lines */
    float32_t   fade_start = (float32_t)(N - 1) * fixed->fade_section_start_length / fixed->total_length;
    float32_t   fade_end = (float32_t)(N - 1) * fixed->fade_section_end_length / fixed->total_length;
    v = guide_add_vertical_line(v, c_right, N, fade_start, fade_end, line_color);
    v = guide_add_vertical_line(v, c_left, N, fade_start, fade_end, line_color);

    /* ...add center static line */
    if (narrow)
    {
        v = guide_add_vertical_line(v, c_center, M, 0.0f, 0.0f, line_color);
    }
    else
    {
        v = guide_add_horizontal_line(v, c_center, M, surface_close_color);
    }

    return 0;
}

/**
 * @brief   Generate horizontal section of the dynamic guideline (subject to NEON acceleration)
 */
static void guide_gen_line(
    float32_t (*p)[3],
    const uint32_t M,
    float32_t P0[2], float32_t P1[2], float32_t Z0)
{
    float32_t   X0 = P0[0], Y0 = P0[1];
    float32_t   sx = (P1[0] - X0) / (float32_t)(M - 1);
    float32_t   sy = (P1[1] - Y0) / (float32_t)(M - 1);
    uint32_t    i;

    for (i = 0; i < M; i++)
    {
        /* ...save close line points */
        (*p)[0] = X0, (*p)[1] = Y0, (*p)[2] = Z0;

        /* ...advance point position */
        X0 += sx, Y0 += sy;

        p++;
    }
}

/**
 * @brief   Generate horizontal section of the dynamic guideline (subject to NEON acceleration)
 */
static void guide_gen_dynamic_hor_section(
    float32_t (*p)[2][3],
    const uint32_t M,
    cfg_data_t *cfg,
    int front,
    float32_t angle,
    float32_t front_gap,
    float32_t rear_gap,
    float32_t total_width,
    float32_t length,
    float32_t width,
    float32_t gap)
{
    float32_t   X0, Y0;
    uint32_t    i;

    if (front)
    {
        X0 = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + front_gap;
        length = -length;
        width = -width;
    }
    else
    {
        X0 = -cfg->vehicle.rear_overhang - rear_gap;
    }

    Y0 = total_width * 0.5f;

    float32_t   x00, x01, x10, x11, sx0, sx1;
    float32_t   y00, y01, y10, y11, sy0, sy1;
    __mat3x3    R;
    __vec3      t;

    guide_instant_rotation_params(cfg, angle, length, R);
    __mat3x3_mulvh(R, (float32_t [2]){X0, Y0 - gap}, t), x00 = t[0], y00 = t[1];
    __mat3x3_mulvh(R, (float32_t [2]){X0, -Y0 + gap}, t), x01 = t[0], y01 = t[1];

    guide_instant_rotation_params(cfg, angle, length - width, R);
    __mat3x3_mulvh(R, (float32_t [2]){X0, Y0 - gap}, t), x10 = t[0], y10 = t[1];
    __mat3x3_mulvh(R, (float32_t [2]){X0, -Y0 + gap}, t), x11 = t[0], y11 = t[1];

    sx0 = (x01 - x00) / (float32_t)(M - 1);
    sx1 = (x11 - x10) / (float32_t)(M - 1);
    sy0 = (y01 - y00) / (float32_t)(M - 1);
    sy1 = (y11 - y10) / (float32_t)(M - 1);

    for (i = 0; i < M; i++)
    {
        /* ...save close line points */
        (*p)[0][0] = x00, (*p)[0][1] = y00, (*p)[0][2] = 0.0f;
        (*p)[1][0] = x10, (*p)[1][1] = y10, (*p)[1][2] = 0.0f;

        /* ...advance point position */
        x00 += sx0, y00 += sy0;
        x10 += sx1, y10 += sy1;

        p++;
    }
}

/**
 * @brief   Generate horizontal section of the dynamic guideline (subject to NEON acceleration)
 */
static void guide_gen_dynamic_hor_section_2(
    float32_t (*p0)[3],
    float32_t (*p1)[3],
    const uint32_t M,
    cfg_data_t *cfg,
    int front,
    float32_t angle,
    float32_t distance,
    float32_t length,
    float32_t width)
{
    float32_t   X0, Y0;

    if (front)
    {
        /* ...use position of front axle */
        X0 = cfg->vehicle.wheel_base;
        distance = -distance - cfg->vehicle.front_overhang;
        width = -width;
    }
    else
    {
        /* ...use position of rear axle */
        X0 = 0;
        distance += cfg->vehicle.rear_overhang;
    }

    Y0 = length * 0.5f;

    float32_t   P00[2], P01[2], P10[2], P11[2];
    __mat3x3    R;

    guide_instant_rotation_params(cfg, angle, distance, R);
    __mat3x2_mulvh(R, (float32_t [2]){X0, Y0}, P00);
    __mat3x2_mulvh(R, (float32_t [2]){X0, -Y0}, P01);
    guide_gen_line(p0, M, P00, P01, 0.0f);

    guide_instant_rotation_params(cfg, angle, distance - width, R);
    __mat3x2_mulvh(R, (float32_t [2]){X0, Y0}, P10);
    __mat3x2_mulvh(R, (float32_t [2]){X0, -Y0}, P11);
    guide_gen_line(p1, M, P10, P11, 0.0f);
}

static void calc_shifted_point(float32_t x0, float32_t y0, float32_t centerx, float32_t centery, float32_t shift_mm, float32_t* x, float32_t* y)
{
    float32_t   dx = x0 - centerx;
    float32_t   dy = y0 - centery;
    float32_t   angle = atan2f(dy, dx);
    float32_t shift_x = shift_mm * cosf(angle);
    float32_t shift_y = shift_mm * sinf(angle);
    *x = x0 + shift_x;
    *y = y0 + shift_y;
}

/**
 * @brief   Genenerate dynamic trajectory line points (subject to NEON acceleration)
 *
 * @param   p[out]          Array of 3D point-pairs coordinates
 * @param   N[in]           Number of 3D point-pairs / number of steps
 * @param   R[in]           Rotation matrix for each step
 * @param   width[in]       Line width
 * @param   delta[in]       Line width increment for each step
 * @param   X0[in]          Starting position of trajectory line, X-coordinate
 * @param   Y0[in]          Starting position of trajectory line, Y-coordinate
 */
static void guide_gen_trajectory_line(float32_t (*p)[2][3], const int32_t N, __mat3x3 R, float32_t width, float32_t delta, float32_t X0, float32_t Y0, float32_t tr)
{
    float32_t   x0 = X0, y0 = Y0;
    float32_t   x1 = x0, y1 = y0 + width;
    __vec3      t;
    uint32_t    i;

    calc_shifted_point(-y0, x0, -tr, 0, (tr < 0) ? width : -width, &y1, &x1);
    y1*=-1;

    for (i = 0; i < N; i++)
    {
        /* ...set reference point on the trajectory */
        (*p)[0][0] = x0, (*p)[0][1] = y0, (*p)[0][2] = 0.0f;
        (*p)[1][0] = x1, (*p)[1][1] = y1, (*p)[1][2] = 0.0f;

        /* ...advance point position */
        __mat3x3_mulvh(R, (*p)[0], t), x0 = t[0], y0 = t[1];
        __mat3x3_mulvh(R, (*p)[1], t), x1 = t[0], y1 = t[1] + delta;

        p++;
    }
}

/**
 * @brief   Genenerate dynamic trajectory line points (subject to NEON acceleration)
 *
 * @param   p[out]          Array of 3D point-pairs coordinates
 * @param   N[in]           Number of 3D point-pairs / number of steps
 * @param   R[in]           Rotation matrix for each step
 * @param   P[in]           Starting position of trajectory line, 2D-coordinate
 */
static void guide_gen_trajectory_line_1(float32_t (*p)[3], const int32_t N, __mat3x3 R, float32_t P[2])
{
    float32_t   T[2] = { P[0], P[1] };
    uint32_t    i;

    for (i = 0; i < N; i++)
    {
        /* ...set reference point on the trajectory */
        (*p)[0] = T[0], (*p)[1] = T[1], (*p)[2] = 0.0f;

        /* ...advance point position */
        __mat3x2_mulvh(R, *p, T);

        p++;
    }
}



/**
 * @brief   Genenerate dynamic trajectory line points (subject to NEON acceleration)
 *
 * @param   p[out]             Array of 3D point-pairs coordinates
 * @param   N[in]              Number of 3D point-pairs / number of steps
 * @param   N1[in]             Start block for the yellow zone
 * @param   N2[in]             Start block for the green zone
 * @param   angle[in]          wheel angle in degrees
 * @param   cfg[in]            Global configuration data
 * @param   dynamic[in]        Guide-lines configuration data
 * @param   sx_multiplier[in]  -1 or 1 depending on front/rear
 * @param   P[in]              Starting position of trajectory line, 2D-coordinate
 */
static void guide_gen_trajectory_line_ffc(
    float32_t (*p)[3], 
    const int32_t N, 
    float32_t angle,
    const cfg_data_t *cfg,
    const cfg_guide_dynamic_fr_t *dynamic,
    float32_t sx_multiplier,
    float32_t P[2]
    )
{
    float32_t   length = dynamic->ffc_length - dynamic->ffc_hidden;
    float32_t   hidden = dynamic->ffc_hidden + cfg->vehicle.front_overhang;
    float32_t   T[3] = { 0 };
    uint32_t    i = 0;

    __mat3x3 R1,R2;
    float32_t step = length / (N - 1);
    guide_instant_rotation_params(cfg, angle, hidden*sx_multiplier, R1);
    guide_instant_rotation_params(cfg, angle, step*sx_multiplier, R2);

    __mat3x2_mulvh(R1, P, T);
    p[0][0] = T[0];
    p[0][1] = T[1];
    p[0][2] = 0.f;


    for (i = 0; i < (N - 1); i++, p++)
    {
        __mat3x2_mulvh(R2, *p, p[1]);
        p[1][2] = 0.f;
    }
}



/**
 * @brief   Genenerate dynamic trajectory line points (subject to NEON acceleration)
 *
 * @param   p[out]             Array of 3D point-pairs coordinates
 * @param   N[in]              Number of 3D point-pairs / number of steps
 * @param   N1[in]             Start block for the yellow zone
 * @param   N2[in]             Start block for the green zone
 * @param   angle[in]          wheel angle in degrees
 * @param   cfg[in]            Global configuration data
 * @param   dynamic[in]        Guide-lines configuration data
 * @param   sx_multiplier[in]  -1 or 1 depending on front/rear
 * @param   P[in]              Starting position of trajectory line, 2D-coordinate
 */
static void guide_gen_trajectory_line_ffc_mix(
    float32_t (*p)[3], 
    const int32_t N, 
    float32_t angle,
    const cfg_data_t *cfg,
    const cfg_guide_dynamic_fr_t *dynamic,
    float32_t sx_multiplier,
    float32_t P0[2],
    float32_t P1[2],
    float32_t factor
    )
{
    float32_t P[2] = {0};
    P[0] = P1[0] * factor + P0[0] * (1 - factor);
    P[1] = P1[1] * factor + P0[1] * (1 - factor);
    guide_gen_trajectory_line_ffc(p, N, angle, cfg, dynamic, sx_multiplier, P);
}
/**
 * @brief   Genenerate dynamic trajectory line points (subject to NEON acceleration)
 *
 * @param   p[out]             Array of 3D point-pairs coordinates
 * @param   N[in]              Number of 3D point-pairs / number of steps
 * @param   N1[in]             Start block for the yellow zone
 * @param   N2[in]             Start block for the green zone
 * @param   angle[in]          wheel angle in degrees
 * @param   cfg[in]            Global configuration data
 * @param   dynamic[in]        Guide-lines configuration data
 * @param   sx_multiplier[in]  -1 or 1 depending on front/rear
 * @param   P[in]              Starting position of trajectory line, 2D-coordinate
 */
static void guide_gen_trajectory_line_3_sections(
    float32_t (*p)[3],
    const int32_t N,
    const int32_t N1, // start 1st zone
    const int32_t N2, // start 2nd zone
    float32_t angle,
    const cfg_data_t *cfg,
    const cfg_guide_dynamic_fr_t *dynamic,
    float32_t sx_multiplier,
    float32_t P[2]
    )
{
    float32_t distance_marker_1 = dynamic->distance_marker_1 - dynamic->hidden_width;
    float32_t distance_marker_2 = dynamic->distance_marker_2 - dynamic->hidden_width;

    float32_t   length = dynamic->total_length - dynamic->hidden_width;
    float32_t   step_hor = dynamic->vehicle_trajectory_width;
    float32_t   sx1 = (distance_marker_1 - step_hor) / (float32_t)(N1 - 1);
    float32_t   sx2 = (distance_marker_2 - distance_marker_1 - step_hor) / (float32_t)(N2 - N1 - 1);
    float32_t   sx3 = (length - distance_marker_2) / (float32_t)(N - N2 - 1);
    float32_t   T[2] = { P[0], P[1] };
    uint32_t    i = 0;

    __mat3x3 R1,R2,R3,Rs;
    guide_instant_rotation_params(cfg, angle, sx1*sx_multiplier, R1);
    guide_instant_rotation_params(cfg, angle, sx2*sx_multiplier, R2);
    guide_instant_rotation_params(cfg, angle, sx3*sx_multiplier, R3);
    guide_instant_rotation_params(cfg, angle, step_hor*sx_multiplier, Rs);

    (*p)[0] = T[0], (*p)[1] = T[1], (*p)[2] = 0.0f;

    for (i = 0; i < (N1 - 1); i++, p++)
    {
        __mat3x2_mulvh(R1, *p, p[1]);
        p[1][2] = 0.f;
    }

    __mat3x2_mulvh(Rs, *p, p[1]);
    p[1][2] = 0.f;
    p++;

    for (i = 0; i < (N2 - N1 - 1); i++, p++)
    {
        __mat3x2_mulvh(R2, *p, p[1]);
        p[1][2] = 0.f;
    }

    __mat3x2_mulvh(Rs, *p, p[1]);
    p[1][2] = 0.f;
    p++;

    for (i = 0; i < (N - N2 - 1); i++, p++)
    {
        __mat3x2_mulvh(R3, *p, p[1]);
        p[1][2] = 0.f;
    }
}


/**
 * @brief   Genenerate dynamic trajectory line points (subject to NEON acceleration)
 *
 * @param   p[out]             Array of 3D point-pairs coordinates
 * @param   N[in]              Number of 3D point-pairs / number of steps
 * @param   N1[in]             Start block for the yellow zone
 * @param   N2[in]             Start block for the green zone
 * @param   angle[in]          wheel angle in degrees
 * @param   cfg[in]            Global configuration data
 * @param   dynamic[in]        Guide-lines configuration data
 * @param   sx_multiplier[in]  -1 or 1 depending on front/rear
 * @param   P[in]              Starting position of trajectory line, 2D-coordinate
 */
static void guide_gen_trajectory_line_dash(
    float32_t (*p)[3],
    const int32_t N_blocks,
    const int32_t block_sz,
    float32_t angle,
    const cfg_data_t *cfg,
    const cfg_guide_dynamic_fr_t *dynamic,
    float32_t sx_multiplier,
    float32_t Z,
    float32_t border,
    float32_t P[2]
    )
{
    float32_t percentage_gap = 0.3f;

    float32_t   length = dynamic->total_length - dynamic->distance_marker_1 + dynamic->vehicle_trajectory_width;
    float32_t   step = length / (float32_t)(N_blocks*block_sz);
    float32_t   step_visible = step*(1.f - percentage_gap);
    float32_t   step_hidden = step*percentage_gap;
    step_hidden+= fabs(border);
    step_visible-= fabs(border);

    float32_t   T[2] = { P[0], P[1] };
    uint32_t    i = 0;

    __mat3x3 Rv, Rh, R0;
    guide_instant_rotation_params(cfg, angle, 2*step_visible*sx_multiplier, Rv);
    guide_instant_rotation_params(cfg, angle, 2*step_hidden*sx_multiplier, Rh);
    guide_instant_rotation_params(cfg, angle, 2*fabs(border)*sx_multiplier, R0);

    (*p)[0] = T[0], (*p)[1] = T[1] + border, (*p)[2] = Z;

    int k;

    if (fabs(border) > 0.0001f)
    {
        __mat3x2_mulvh(R0, *p, *p);
    }

    for (k = 0; k < (N_blocks / 2); k++)
    {
        for (i = 0; i < block_sz; i++, p++)
        {
            __mat3x2_mulvh(Rv, *p, p[1]);
            p[1][2] = Z;
        }

        for (i = 0; i < block_sz; i++, p++)
        {
            __mat3x2_mulvh(Rh, *p, p[1]);
            p[1][2] = Z;
        }
    }

    for (i = 0; i < block_sz; i++, p++)
    {
        __mat3x2_mulvh(Rv, *p, p[1]);
        p[1][2] = Z;
    }
}

/**
 * @brief   Genenerate dynamic trajectory horizontal points
 *
 * @param   p[out]          Array of 3D point-pairs coordinates
 * @param   N[in]           Number of 3D point-pairs / number of steps
 * @param   dynamic[in]     Trajectory line parameters
 * @param   P0[in]          Starting position of trajectory line, 2D-coordinate
 * @param   P1[in]          Ending position of trajectory line, 2D-coordinate
 */
static void guide_gen_trajectory_horizontal_line(
    float32_t (*p)[3],
    const int32_t N,
    const cfg_guide_dynamic_fr_t *dynamic,
    float32_t P0[2],
    float32_t P1[2]
    )
{
    float32_t   ml = dynamic->distance_marker_length;
    float32_t   tl = dynamic->vehicle_width - dynamic->vehicle_trajectory_width;
    float32_t   percentage = ml/tl;
    float32_t   d[2] = {P1[0] - P0[0], P1[1] - P0[1]};
    d[0]*=percentage;
    d[1]*=percentage;

    uint32_t i;

    for (i = 0; i < N; i++)
    {
        (*p)[0] = P0[0] + d[0] * (float32_t)i / (float32_t)(N - 1);
        (*p)[1] = P0[1] + d[1] * (float32_t)i / (float32_t)(N - 1);
        (*p)[2] = 0.0f;
        p++;
    }

    for (i = 0; i < N; i++)
    {
        (*p)[0] = P1[0] - d[0] * (float32_t)i / (float32_t)(N - 1);
        (*p)[1] = P1[1] - d[1] * (float32_t)i / (float32_t)(N - 1);
        (*p)[2] = 0.0f;
        p++;
    }
}

/**
 * @brief   Calculate start position of the point on trajectory basing on X
 *
 * @param   P[in]       Point of interest
 * @param   Cy[in]      Instant rotation center position (Y-coordinate)
 * @param   XS[in]      X-coordinate of start position
 * @param   Q[out]      Position of the starting point
 */
static inline void guide_calc_start_position(float32_t *P, float32_t Cy, float32_t XS, float32_t *Q)
{
    if (Cy != 0.0f)
    {
        float32_t   R2 = P[0] * P[0] + (P[1] - Cy) * (P[1] - Cy);

        if (R2 >= XS * XS)
        {
            float32_t   Y =  fabsf(Cy) - sqrtf(R2 - XS * XS);

            Q[0] = XS;
            Q[1] = (Cy < 0.0f ? -Y : Y);
        }
        else
        {
            Q[0] = (XS > 0.0 ? 1.0f : -1.0f) * sqrtf(R2);
            Q[1] = Cy;
        }
    }
    else
    {
        Q[0] = XS;
        Q[1] = P[1];
    }
}

/**
 * @brief   Generate dynamic guidelines overlay for front/rear views
 *
 * @param   gen[in]         Guidelines generator data
 * @param   cfg[in]         Global configuration data
 * @param   vcam[in]        Virtual camera handle
 * @param   front[in]       Front guidelines flag
 * @param   stv[in]         STV guidelines flag
 * @param   angle[in]       Wheel angle, radians
 *
 * @return                  Negative on failure
 */
static int guide_gen_dynamic_line(guide_gen_t *gen, cfg_data_t *cfg, vcamera_data_t *vcam, int front, int stv, float32_t angle)
{
    const int       N = 32;
    const int       M0 = 32;
    const int       M1 = 16;
    const int       M2 = 24;

    cfg_guide_dynamic_fr_t *dynamic;

    if (front)
    {
        dynamic = (stv ? &cfg->guide.dynamic_front_stv : &cfg->guide.dynamic_front);
    }
    else
    {
        dynamic = (stv ? &cfg->guide.dynamic_rear_stv : &cfg->guide.dynamic_rear);
    }

    float32_t       points[12 * N + 2 * M0 + 6 * M1 + 4 * M2][3];
    float32_t       coords[12 * N + 2 * M0 + 6 * M1 + 4 * M2][2];

    float32_t       sx = (dynamic->total_length - dynamic->hidden_width) / (float32_t)(N - 1);
    int             i;
    float32_t       X0;

    /* ...set initial X-coordinate position and step along X */
    if (front)
    {
        X0 = cfg->vehicle.wheel_base;
        sx = -sx;
    }
    else
    {
        X0 = 0;
    }

    int     side = stv && (fabsf(angle) > dynamic->side_angle_threshold * (float32_t)(M_PI / 180.0));
    int     left = ((angle > 0.0f && front) || (!front && angle < 0.0f));

    float32_t       P[14][2];
    P[0][1] = dynamic->vehicle_width * 0.5f;
    P[1][1] = P[0][1] - dynamic->vehicle_trajectory_width;
    P[2][1] = dynamic->wheel_lateral_distance * 0.5f;
    P[3][1] = P[2][1] - dynamic->wheel_border_width;
    P[4][1] = P[2][1] - dynamic->wheel_width + dynamic->wheel_border_width;
    P[5][1] = P[4][1] - dynamic->wheel_border_width;

    for (i = 0; i < 6; i++)
    {
        P[11 - i][1] = -P[i][1];
        P[11 - i][0] = P[i][0] = X0;
    }

    if (1 || side != 0)
    {
        if (left != 0)
        {
            P[0][0] = P[1][0] = (front ? 0.0f : cfg->vehicle.wheel_base + cfg->vehicle.front_overhang);
            P[10][0] = P[11][0] = (front ? cfg->vehicle.wheel_base + cfg->vehicle.front_overhang : 0.0f);
        }
        else
        {
            P[10][0] = P[11][0] = (front ? 0.0f : cfg->vehicle.wheel_base + cfg->vehicle.front_overhang);
            P[0][0] = P[1][0] = (front ? cfg->vehicle.wheel_base + cfg->vehicle.front_overhang : 0.0f);
        }
    }

    float32_t   Cy;
    float32_t   dphi;
    __mat3x3    R;
    float32_t   alpha;

    /* ...calculate instant rotation center position */
    if (fabsf(angle) < (float32_t)(0.25 * M_PI / 180.0))
    {
        Cy = 0.0f;
        alpha = 0.0f;
    }
    else
    {
        /* ...calculate instant rotation center coordinates */
        Cy = cfg->vehicle.wheel_base / tanf(angle);
        alpha = dynamic->total_length / Cy;
    }

    float32_t   XS0 = (front ? cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + dynamic->hidden_width : -cfg->vehicle.rear_overhang - dynamic->hidden_width);

    if (side != 0)
    {
        float32_t   XS1 = (front ? dynamic->hidden_width : cfg->vehicle.wheel_base + cfg->vehicle.front_overhang - dynamic->hidden_width);
        float32_t   XS2 = (front ? cfg->vehicle.wheel_base + dynamic->hidden_width : -dynamic->hidden_width);

        if (left != 0)
        {
            guide_calc_start_position(P[0], Cy, XS1, P[0]);
            guide_calc_start_position(P[1], Cy, XS1, P[1]);

            guide_calc_start_position(P[10], Cy, XS2, P[10]);
            guide_calc_start_position(P[11], Cy, XS2, P[11]);
        }
        else
        {
            guide_calc_start_position(P[0], Cy, XS2, P[0]);
            guide_calc_start_position(P[1], Cy, XS2, P[1]);

            guide_calc_start_position(P[10], Cy, XS1, P[10]);
            guide_calc_start_position(P[11], Cy, XS1, P[11]);
        }
    }
    else
    {
        guide_calc_start_position(P[0], Cy, XS0, P[0]);
        guide_calc_start_position(P[1], Cy, XS0, P[1]);

        guide_calc_start_position(P[10], Cy, XS0, P[10]);
        guide_calc_start_position(P[11], Cy, XS0, P[11]);
    }

    for (i = 2; i < 10; i++)
    {
        guide_calc_start_position(P[i], Cy, XS0, P[i]);
    }

    float32_t   XS1 = XS0 - dynamic->horizontal_line_width * (front ? 1.0f : -1.0f);
    guide_calc_start_position(P[2], Cy, XS1, P[12]);
    guide_calc_start_position(P[9], Cy, XS1, P[13]);

    /* ...calculate rotation matrix for vertical lines */
    guide_instant_rotation_params(cfg, angle, sx, R);

    /* ...build vertical lines */
    for (i = 0; i < 12; i++)
    {
        TRACE(0, _b("P[%d]=%f,%f"), i, P[i][0], P[i][1]);
        guide_gen_trajectory_line_1(&points[i * N], N, R, P[i]);
    }

    if (side != 0)
    {
        float32_t   length2 = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + (front ? 0.0f : cfg->vehicle.rear_overhang);

        sx = (dynamic->total_length - dynamic->hidden_width + length2) / (float32_t)(N - 1) * (front ? -1.0f : 1.0f);
        //sx = (length2 - dynamic->hidden_width) / (float32_t)(N - 1) * (front ? -1.0f : 1.0f);
        guide_instant_rotation_params(cfg, angle, sx, R);

        if (left != 0)
        {
            guide_gen_trajectory_line_1(&points[0 * N], N, R, P[0]);
            guide_gen_trajectory_line_1(&points[1 * N], N, R, P[1]);
        }
        else
        {
            guide_gen_trajectory_line_1(&points[10 * N], N, R, P[10]);
            guide_gen_trajectory_line_1(&points[11 * N], N, R, P[11]);
        }

        length2 = (front ? cfg->vehicle.front_overhang : cfg->vehicle.rear_overhang);
        sx = (dynamic->total_length - dynamic->hidden_width + length2) / (float32_t)(N - 1) * (front ? -1.0f : 1.0f);
        guide_instant_rotation_params(cfg, angle, sx, R);

        if (left != 0)
        {
            guide_gen_trajectory_line_1(&points[10 * N], N, R, P[10]);
            guide_gen_trajectory_line_1(&points[11 * N], N, R, P[11]);
        }
        else
        {
            guide_gen_trajectory_line_1(&points[0 * N], N, R, P[0]);
            guide_gen_trajectory_line_1(&points[1 * N], N, R, P[1]);
        }
    }

    /* ...generate close-section horizontal line points */
    guide_gen_line(&points[12 * N + 0 * M0], M0, P[2], P[9], 0.0f);
    guide_gen_line(&points[12 * N + 1 * M0], M0, P[12], P[13], 0.0f);

    if (side != 0)
    {
        P[0][0] = P[1][0] = P[2][0] = P[3][0] = (front ? 0.0f : cfg->vehicle.wheel_base);
        P[0][1] = dynamic->wheel_lateral_distance * 0.5f;
        P[1][1] = P[0][1] - dynamic->wheel_border_width;
        P[2][1] = P[0][1] - dynamic->wheel_width + dynamic->wheel_border_width;
        P[3][1] = P[2][1] - dynamic->wheel_border_width;

        if (left == 0)
        {
            P[0][1] = -P[0][1];
            P[1][1] = -P[1][1];
            P[2][1] = -P[2][1];
            P[3][1] = -P[3][1];
        }

        XS0 = (front ? dynamic->hidden_width : cfg->vehicle.wheel_base - dynamic->hidden_width);

        float32_t length2 = cfg->vehicle.wheel_base + (front ? cfg->vehicle.front_overhang : cfg->vehicle.rear_overhang);

        /* ...calculate rotation matrix for vertical lines */
        sx = (length2 - dynamic->hidden_width) / (float32_t)(M2 - 1) * (front ? -1.0f : 1.0f);
        guide_instant_rotation_params(cfg, angle, sx, R);

        /* ...shift position to specified gap */
        for (i = 0; i < 4; i++)
        {
            guide_calc_start_position(P[i], Cy, XS0, P[i]);
            guide_gen_trajectory_line_1(&points[12 * N + 2 * M0 + 6 * M1 + i * M2], M2, R, P[i]);
        }
    }

    guide_gen_dynamic_hor_section_2(&points[12 * N + 2 * M0 + 0 * M1],
                                    &points[12 * N + 2 * M0 + 1 * M1],
                                    M1, cfg, front, angle,
                                    dynamic->distance_marker_1,
                                    dynamic->distance_marker_length,
                                    dynamic->distance_marker_width);

    guide_gen_dynamic_hor_section_2(&points[12 * N + 2 * M0 + 2 * M1],
                                    &points[12 * N + 2 * M0 + 3 * M1],
                                    M1, cfg, front, angle,
                                    dynamic->distance_marker_2,
                                    dynamic->distance_marker_length,
                                    dynamic->distance_marker_width);

    guide_gen_dynamic_hor_section_2(&points[12 * N + 2 * M0 + 4 * M1],
                                    &points[12 * N + 2 * M0 + 5 * M1],
                                    M1, cfg, front, angle,
                                    dynamic->distance_marker_3,
                                    dynamic->distance_marker_length,
                                    dynamic->distance_marker_width);

    /* ...project points into virtual camera sensor space */
    guide_vcam_project(vcam, &points[0], &coords[0], (12 * N + 2 * M0 + 6 * M1 + (side ? 4 * M2 : 0)));

    /* ...reserve place in dynamic vertex buffer array */
    vbo_dynarray_t *vbo = &gen->vbo;
    gl_vertex_t    *v;

    CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (8 * (N - 1) + 1 * (M0 - 1) + 3 * (M1 - 1) + (side ? 3 * (M2 - 1) : 0)) * 6), -1);

    /* ...add vertical lines */
    float32_t   color_A[4], color_B1[4], color_B2[4], color_C[4], color_D[4], color_E[4], color_F[4];

    guide_set_color(color_A, (uint8_t[3]){ 180, 255, 0 }, 30);
    guide_set_color(color_B1, (uint8_t[3]){ 180, 255, 0 }, 50);
    guide_set_color(color_B2, (uint8_t[3]){ 180, 255, 0 }, 30);
    guide_set_color(color_C, (uint8_t[3]){ 180, 255, 0 }, 30);
    guide_set_color(color_D, (uint8_t[3]){ 180, 255, 0 }, 30);
    guide_set_color(color_E, (uint8_t[3]){ 180, 255, 0 }, 30);
    guide_set_color(color_F, (uint8_t[3]){ 250, 10, 0 }, 0);

    float32_t   fade_start = (float32_t)(N - 1) * dynamic->fade_section_start_length / dynamic->total_length;
    float32_t   fade_end = (float32_t)(N - 1) * dynamic->fade_section_end_length / dynamic->total_length;

    v = guide_add_vertical_line_2(v, &coords[0], &coords[N], N, fade_start, fade_end, color_A);
    v = guide_add_vertical_line_2(v, &coords[2 * N], &coords[3 * N], N, fade_start, fade_end, color_B2);
    v = guide_add_vertical_line_2(v, &coords[3 * N], &coords[4 * N], N, fade_start, fade_end, color_B1);
    v = guide_add_vertical_line_2(v, &coords[4 * N], &coords[5 * N], N, fade_start, fade_end, color_B2);

    v = guide_add_vertical_line_2(v, &coords[6 * N], &coords[7 * N], N, fade_start, fade_end, color_B2);
    v = guide_add_vertical_line_2(v, &coords[7 * N], &coords[8 * N], N, fade_start, fade_end, color_B1);
    v = guide_add_vertical_line_2(v, &coords[8 * N], &coords[9 * N], N, fade_start, fade_end, color_B2);
    v = guide_add_vertical_line_2(v, &coords[10 * N], &coords[11 * N], N, fade_start, fade_end, color_A);

    /* ...add horizontal lines */
    v = guide_add_horizontal_line_2(v, &coords[12 * N], &coords[12 * N + M0], M0, color_F, color_F[3]);
    v = guide_add_horizontal_line_2(v, &coords[12 * N + 2 * M0], &coords[12 * N + 2 * M0 + M1], M1, color_C, color_C[3]);
    v = guide_add_horizontal_line_2(v, &coords[12 * N + 2 * M0 + 2 * M1], &coords[12 * N + 2 * M0 + 3 * M1], M1, color_D, color_D[3]);
    v = guide_add_horizontal_line_2(v, &coords[12 * N + 2 * M0 + 4 * M1], &coords[12 * N + 2 * M0 + 5 * M1], M1, color_E, color_E[3]);

    if (side)
    {
        fade_start = (float32_t)(M2 - 1) * dynamic->fade_section_start_length / dynamic->total_length;
        fade_end = (float32_t)(M2 - 1) * dynamic->fade_section_end_length / dynamic->total_length;

        v = guide_add_vertical_line_2(v, &coords[12 * N + 2 * M0 + 6 * M1 + 0 * M2], &coords[12 * N + 2 * M0 + 6 * M1 + 1 * M2], M2, fade_start, fade_end, color_B2);
        v = guide_add_vertical_line_2(v, &coords[12 * N + 2 * M0 + 6 * M1 + 1 * M2], &coords[12 * N + 2 * M0 + 6 * M1 + 2 * M2], M2, fade_start, fade_end, color_B1);
        v = guide_add_vertical_line_2(v, &coords[12 * N + 2 * M0 + 6 * M1 + 2 * M2], &coords[12 * N + 2 * M0 + 6 * M1 + 3 * M2], M2, fade_start, fade_end, color_B2);
    }

    return 0;
}

static float32_t calc_ffc_dx(cfg_data_t *cfg, float32_t angle, float32_t start_x, float32_t start_y0, float32_t start_y1)
{
    if (angle == 0.0f)
    {
        return 0.0f;
    }

    float32_t r = cfg->vehicle.wheel_base / tanf(angle);

    float32_t angle0 = atan2f(start_y0 - r, start_x);
    float32_t angle1 = atan2f(start_y1 - r, start_x);

    return (angle1 - angle0)*r;
}


/**
 * @brief   Generate dynamic guidelines overlay for front/rear views(STL design)
 *
 * @param   gen[in]         Guidelines generator data
 * @param   cfg[in]         Global configuration data
 * @param   vcam[in]        Virtual camera handle
 * @param   front[in]       Front guidelines flag
 * @param   stv[in]         STV guidelines flag
 * @param   angle[in]       Wheel angle, radians
 *
 * @return                  Negative on failure
 */
static int guide_gen_ffc(guide_gen_t *gen, cfg_data_t *cfg, vcamera_data_t *vcam, int front, int stv, float32_t angle)
{
    const int       N = ffc_sections;
    const int       N2 = ffc_sections / 2U;

    cfg_guide_dynamic_fr_t *dynamic;

    if (front)
    {
        dynamic = (stv ? &cfg->guide.dynamic_front_stv : &cfg->guide.dynamic_front);
    }
    else
    {
        dynamic = (stv ? &cfg->guide.dynamic_rear_stv : &cfg->guide.dynamic_rear);
    }

    float32_t       points[2 * N][3];
    float32_t       coords[2 * N][2];

    int             i;

    float32_t       P[4][2] = {0};

    P[0][1] = dynamic->ffc_width * 0.5f + dynamic->ffc_tire_width*0.5f;
    P[1][1] = P[0][1] - dynamic->ffc_tire_width;

    float32_t tire_step = (dynamic->ffc_length - dynamic->ffc_hidden) / (N - 1) / dynamic->ffc_tire_width;

    float32_t start_x = (front ? cfg->vehicle.wheel_base : 0);

    for (uint32_t i = 0; i < sizeof(P) / sizeof(P[0]); i++)
    {
        P[i][0] = start_x;
    }

    for (uint32_t i = 0; i < 2; i++)
    {
        P[i + 2][1] = -P[1 - i][1];
    }

    const uint32_t hor_N = 9;
    float32_t sc = 1.f / hor_N;
    gl_vertex_ffc_t    *v;
    vbo_dynarray_t *vbo = &gen->vbo_ffc;
    CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (2 * hor_N * (N - 1)) * 6), -1);

    for (uint32_t k = 0; k < 2; k++)
    {
        float32_t right_offset = calc_ffc_dx(cfg, angle, P[k*2][0], P[k*2][1], P[k*2 + 1][1]) / dynamic->ffc_tire_width;

        for (uint32_t i = 0; i <= hor_N; i++)
        {
            uint32_t cur = (i % 2);
            uint32_t prev = cur ^ 1;
            guide_gen_trajectory_line_ffc_mix(&points[cur * N], N, angle, cfg, dynamic, front ? -1 : 1, P[k*2], P[k*2 + 1], i*sc);
            guide_vcam_project_adv(vcam, &points[cur * N], &coords[cur * N], N);

            if (i > 0)
            {
                v = guide_add_vertical_line_tex(v, &coords[prev*N], &coords[cur*N], tire_step, (i-1)*sc, i*sc, N, right_offset);
            }
        }
    }

    return 0;
}



/**
 * @brief   Generate dynamic guidelines overlay for front/rear views(STL design)
 *
 * @param   gen[in]         Guidelines generator data
 * @param   cfg[in]         Global configuration data
 * @param   vcam[in]        Virtual camera handle
 * @param   front[in]       Front guidelines flag
 * @param   stv[in]         STV guidelines flag
 * @param   angle[in]       Wheel angle, radians
 *
 * @return                  Negative on failure
 */
static int guide_gen_dynamic_line_stl(guide_gen_t *gen, cfg_data_t *cfg, vcamera_data_t *vcam, int front, int stv, float32_t angle)
{
    const int       N = 32;
    const int       N0 = 8;
    const int       N1 = 24;
    const int       M0 = 4;
    const int       M1 = 4;
    const int       D1 = 17; // must be odd
    const int       D2 = 2;
    const int       DS = D1*D2+1;


    cfg_guide_dynamic_fr_t *dynamic;

    if (front)
    {
        dynamic = (stv ? &cfg->guide.dynamic_front_stv : &cfg->guide.dynamic_front);
    }
    else
    {
        dynamic = (stv ? &cfg->guide.dynamic_rear_stv : &cfg->guide.dynamic_rear);
    }

    float32_t       points[6 * N + 4 * M0 + 4 * M1 + 4 * DS][3];
    float32_t       coords[6 * N + 4 * M0 + 4 * M1 + 4 * DS][2];


    int             i;
    float32_t       X0;

    /* ...set initial X-coordinate position and step along X */
    if (front)
    {
        X0 = cfg->vehicle.wheel_base;
    }
    else
    {
        X0 = 0;
    }

    int     side = stv && (fabsf(angle) > dynamic->side_angle_threshold * (float32_t)(M_PI / 180.0));
    int     left = ((angle > 0.0f && front) || (!front && angle < 0.0f));

    float32_t       P[14][2] = {0};
    P[0][1] = dynamic->vehicle_width * 0.5f + dynamic->vehicle_trajectory_width*0.5f;
    P[1][1] = P[0][1] - dynamic->vehicle_trajectory_width;
    P[2][1] = dynamic->center_trajectory_width*0.5f;
    P[3][1] = P[2][1] - dynamic->center_trajectory_width;


    for (i = 0; i < 6; i++)
    {
        P[11 - i][1] = -P[i][1];
        P[11 - i][0] = P[i][0] = X0;
    }

    float32_t front_sx[2] = {cfg->vehicle.wheel_base, cfg->vehicle.wheel_base + cfg->vehicle.front_overhang};
    float32_t rear_sx[2] = {-cfg->vehicle.rear_overhang, 0};

    float32_t* start = (front) ? front_sx : rear_sx;

    if (left != 0)
    {
        P[0][0] = P[1][0] = start[0];
        P[10][0] = P[11][0] = start[1];
    }
    else
    {
        P[10][0] = P[11][0] = start[0];
        P[0][0] = P[1][0] = start[1];
    }

    P[2][0] = P[3][0] = (front ? cfg->vehicle.wheel_base + cfg->vehicle.front_overhang : -cfg->vehicle.front_overhang);

    float32_t   Cy;
    float32_t   dphi;
    float32_t   alpha;

    /* ...calculate instant rotation center position */
    if (fabsf(angle) < (float32_t)(0.25 * M_PI / 180.0))
    {
        Cy = 0.0f;
        alpha = 0.0f;
    }
    else
    {
        /* ...calculate instant rotation center coordinates */
        Cy = cfg->vehicle.wheel_base / tanf(angle);
        alpha = dynamic->total_length / Cy;
    }

    float32_t   XS0 = (front ? cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + dynamic->hidden_width : -cfg->vehicle.rear_overhang - dynamic->hidden_width);
    float32_t   XS1 = (front
        ? cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + dynamic->distance_marker_middle
        : -cfg->vehicle.rear_overhang - dynamic->distance_marker_middle);


    {
        guide_calc_start_position(P[0], Cy, XS0, P[0]);
        guide_calc_start_position(P[1], Cy, XS0, P[1]);

        guide_calc_start_position(P[2], Cy, XS1, P[2]);
        guide_calc_start_position(P[3], Cy, XS1, P[3]);

        guide_calc_start_position(P[10], Cy, XS0, P[10]);
        guide_calc_start_position(P[11], Cy, XS0, P[11]);
    }

    float32_t center_z = dynamic->center_trajectory_z;

    /* ...calculate rotation matrix for vertical lines */
    guide_gen_trajectory_line_3_sections(&points[0], N, N0, N1, angle, cfg, dynamic, front ? -1 : 1, P[0]);
    guide_gen_trajectory_line_3_sections(&points[1 * N], N, N0, N1, angle, cfg, dynamic, front ? -1 : 1, P[1]);

    guide_gen_trajectory_line_dash(&points[6*N + M0*4 + M1*4 + 0], D1, D2, angle, cfg, dynamic, front ? -1 : 1, center_z, 0, P[2]);
    guide_gen_trajectory_line_dash(&points[6*N + M0*4 + M1*4 + DS], D1, D2, angle, cfg, dynamic, front ? -1 : 1, center_z, 0, P[3]);
    guide_gen_trajectory_line_dash(&points[6*N + M0*4 + M1*4 + 2*DS], D1, D2, angle, cfg, dynamic, front ? -1 : 1, center_z, -4, P[2]);
    guide_gen_trajectory_line_dash(&points[6*N + M0*4 + M1*4 + 3*DS], D1, D2, angle, cfg, dynamic, front ? -1 : 1, center_z, 4, P[3]);

    guide_gen_trajectory_line_3_sections(&points[4 * N], N, N0, N1, angle, cfg, dynamic, front ? -1 : 1, P[10]);
    guide_gen_trajectory_line_3_sections(&points[5 * N], N, N0, N1, angle, cfg, dynamic, front ? -1 : 1, P[11]);

    guide_gen_trajectory_horizontal_line(&points[6*N], M0, dynamic, points[1*N + N0 - 1], points[4*N + N0 - 1]);
    guide_gen_trajectory_horizontal_line(&points[6*N + M0*2], M0, dynamic, points[1*N + N0], points[4*N + N0]);

    guide_gen_trajectory_horizontal_line(&points[6*N + M0*4], M1, dynamic, points[1*N + N1 - 1], points[4*N + N1 - 1]);
    guide_gen_trajectory_horizontal_line(&points[6*N + M0*4 + M1*2], M1, dynamic, points[1*N + N1], points[4*N + N1]);



    /* ...project points into virtual camera sensor space */
    guide_vcam_project(vcam, &points[0], &coords[0], (6 * N + 4 * M0 + 4 * M1 + DS*4));

    bool_t center_traj_enable = dynamic->center_trajectory_width > 0.0f;

    /* ...reserve place in dynamic vertex buffer array */
    vbo_dynarray_t *vbo = &gen->vbo;
    gl_vertex_t    *v;

    uint32_t center_lines = center_traj_enable ? 2 : 0;

    CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (2 * (N - 1) + 4 * (M0 - 1) + center_lines*DS) * 6), -1);

    /* ...add vertical lines */
    float32_t   colors[4*3];

    float32_t   colors_bw[4*2];



    guide_set_color(&colors[0*4], (uint8_t[3]){ 255, 0, 0 }, 40);
    guide_set_color(&colors[1*4], (uint8_t[3]){ 255, 255, 0 }, 40);
    guide_set_color(&colors[2*4], (uint8_t[3]){ 0, 128, 0 }, 40);

    guide_set_color(&colors_bw[0*4], (uint8_t[3]){ 255, 255, 255 }, 40);
    guide_set_color(&colors_bw[1*4], (uint8_t[3]){ 0, 0, 0 }, 100);


    v = guide_add_vertical_line_stl(v, &coords[0], &coords[N], N, N0, N1, colors);
    v = guide_add_vertical_line_stl(v, &coords[4*N], &coords[5*N], N, N0, N1, colors);

    if (center_traj_enable)
    {
        v = guide_add_vertical_line_dash(v, &coords[6*N + M0*4 + M1*4], &coords[6*N + M0*4 + M1*4 + DS], DS, D2, colors_bw);
        guide_set_color(&colors_bw[0*4], (uint8_t[3]){ 0, 0, 0 }, 30);
        guide_set_color(&colors_bw[1*4], (uint8_t[3]){ 0, 0, 0 }, 100);
        v = guide_add_vertical_line_dash(v, &coords[6*N + M0*4 + M1*4 + DS*2], &coords[6*N + M0*4 + M1*4 + DS*3], DS, D2, colors_bw);
    }

    v = guide_add_horizontal_line_stl(v, &coords[6*N], &coords[6*N + M0*2], M0, colors);
    v = guide_add_horizontal_line_stl(v, &coords[6*N + M0], &coords[6*N + M0*3], M0, colors);

    v = guide_add_horizontal_line_stl(v, &coords[6*N + M0*4], &coords[6*N + M0*4 + M1*2], M0, &colors[4]);
    v = guide_add_horizontal_line_stl(v, &coords[6*N + M0*4 + M1], &coords[6*N + M0*4 + M1*3], M0, &colors[4]);

    return 0;
}

/**
 * @brief   Prepare ray-tracing parameters for TV-mesh generation - duplication - tbd
 *
 * @param   cfg[in]         TV-mesh configuration data
 * @param   C[in]           2D-world-coordinates of vehicle geometric center, mm
 * @param   U[out]          2*3 matrix for world-to-display conversion
 */
static inline void guide_gen_tv_prepare(cfg_tv_mesh_t *cfg, float32_t *C, float32_t *U)
{
    int32_t    *dst = cfg->base.dst;
    int32_t     x0 = dst[0], y0 = dst[1], x1 = dst[2], y1 = dst[3];
    float32_t   W = (float32_t)(x1 - x0), H = (float32_t)(y1 - y0);
    float32_t   S = 1.0f / cfg->scale;
    float32_t   invW = 2.0f / W;
    float32_t   invH = -2.0f / H;

    /* ...build 2*3 row-major matrix for calculation {x,y} = U * {X,Y,1} */
    U[0] = invW * S * 0.0f;
    U[1] = invW * S * -1.0f;
    U[2] = 0.0f - U[0] * C[0] - U[1] * C[1];

    U[3] = invH * S * -1.0f;
    U[4] = invH * S * 0.0f;
    U[5] = 0.0f - U[3] * C[0] - U[4] * C[1];
}

/**
 * @brief   Translate 3D-coordinates in world-space into 2D virtual TV-camera space
 *
 * @param   U[in]           2*3 world-to-display translation matrix
 * @param   points[in]      Array of 3D-points in world coordinate system
 * @param   coords[out]     Array of 2D-points in virtual camera sensor space
 * @param   count[in]       Number of points in array
 */
static void guide_tv_project(float32_t *U, float32_t (*points)[3], float32_t (*coords)[2], uint32_t count)
{
    uint32_t        i;

    /* ...load row-major translation matrix:
     * [0]: {m00, m10}
     * [1]: {m01, m11}
     * [2]: {m02, m12}
     */
    float32x2x3_t   M = vld3_f32(U);

    for (i = 0; i < count; i += 2)
    {
        float32x4x3_t   Q = vld3q_f32(*points);
        points += 2;

        /* ...convert world-coordinate to display */
        float32x4x2_t   P;
        P.val[0] = vmlaq_lane_f32(vmlaq_lane_f32(vdupq_lane_f32(M.val[2], 0), Q.val[0], M.val[0], 0), Q.val[1], M.val[1], 0);
        P.val[1] = vmlaq_lane_f32(vmlaq_lane_f32(vdupq_lane_f32(M.val[2], 1), Q.val[0], M.val[0], 1), Q.val[1], M.val[1], 1);

        vst2q_f32(*coords, P);
        coords += 2;
    }
}

/**
 * @brief   Select top-view trajectory line visibility for specific wheel
 *
 * @param   visible[in, out]    Current visibility state
 * @param   angle[in]           Wheel nominally positive angle, rad
 */
static inline void guide_tv_calc_visibility(int *visible, float32_t angle)
{
    if (*visible != 0)
    {
        *visible = (angle >= (float32_t)(1.0 * M_PI / 180.0));
    }
    else
    {
        *visible = (angle >= (float32_t)(3.0 * M_PI / 180.0));
    }
}

/**
 * @brief   Generate dynamic guidelines overlay for top-view
 *
 * @param   cfg[in]         Global configuration data
 * @param   svc[in]         SVC-camera configuration
 *
 * @return                  Negative on failure
 */
static int guide_gen_tv_line(guide_gen_t *gen, cfg_data_t *cfg, float32_t *U, int forward, float32_t angle, guide_data_t *guide)
{
    const int       N = 32;

    cfg_guide_tv_t *tv = &cfg->guide.tv;

    float32_t       points[4 * N + 2][2][3];
    float32_t     (*p_0)[2][3] = &points[0];
    float32_t     (*p_1)[2][3] = p_0 + N;
    float32_t     (*p_2)[2][3] = p_1 + N;
    float32_t     (*p_3)[2][3] = p_2 + N;

    float32_t       coords[4 * N + 2][2][2];
    float32_t     (*c_0)[2][2] = &coords[0];
    float32_t     (*c_1)[2][2] = c_0 + N;
    float32_t     (*c_2)[2][2] = c_1 + N;
    float32_t     (*c_3)[2][2] = c_2 + N;

    float32_t       X0, X1, Y0, Y1;

    float32_t       length = tv->total_length;
    float32_t       sx = length / (float32_t)(N - 1), sy;

    vbo_dynarray_t *vbo = &gen->vbo_bw;


    /* ...set initial X-coordinate position and step along X */
    if (forward)
    {
        /* ...rear dynamic lines originate from rear axle */
        X1 = 0.0f;
        sx = -sx;
    }
    else
    {
        /* ...rear dynamic lines originate from rear edge of the vehicle */
        X1 = - tv->rear_gap;
    }

    /* ...initial Y-coordinates always depend on the vehicle width including mirrors */
    /*the param total width is just offset*/
    Y0 = cfg->vehicle.width_mirrors*0.5f + tv->total_width;
    Y1 = cfg->vehicle.width_mirrors*0.5f + tv->total_width; 

    /* ...front-wheels origin X-coordinate */ /*Refer HMI FTS to understand below code significant*/
    X0 = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + tv->front_gap;

    /*Tire_width = 301 for STLA*/
    /*Turning_Radius = (wheel_base / SIN(wheel_angle)) + 0.5*Tire Width + wall_to_wall_offset*/  /*We consider wall to wall*/ 

    /* ...calculate instant rotation parameters for a single step: {X(n),Y(n)} = R*{X(n-1),Y(n-1),1} */
    __mat3x3        R;
    guide_instant_rotation_params(cfg, angle, sx, R);

    /* ...build trajectories of all tracks */
    float32_t   line_width = tv->line_width;
    float32_t tr = (fabsf(angle) > 0.000001) ? cfg->vehicle.wheel_base / tanf(angle): INFINITY;

    /*Front*/
    guide_gen_trajectory_line(p_0, N, R, -line_width, 0.0f, X0, Y0, tr);
    guide_gen_trajectory_line(p_1, N, R, line_width, 0.0f, X0, -Y0, tr);

    /*Rear*/
    guide_gen_trajectory_line(p_2, N, R, -line_width, 0.0f, X1, Y1, tr);
    guide_gen_trajectory_line(p_3, N, R, line_width, 0.0f, X1, -Y1, tr);

    /* ...project 3D-points into TV camera sensor space */
    guide_tv_project(U, &points[0][0], &coords[0][0], 4 * N * 2);

    /* ...add trajectory lines */
    int32_t     close_n = (int32_t)ceilf((float32_t)N * (tv->close_section_length / tv->total_length));
    float32_t   fade_start = (float32_t)(N - 1) * tv->fade_section_start_length / tv->total_length;
    float32_t   fade_end = (float32_t)(N - 1) * tv->fade_section_end_length / tv->total_length;
    float32_t   close_line_color[4];
    float32_t   line_color[4];

    /* ...limit size of the close section */
    (close_n > N ? close_n = N : 0);

    guide_set_color(close_line_color, cfg->guide.tv_close_section_color, cfg->guide.tv_close_section_transmittance);
    guide_set_color(line_color, cfg->guide.tv_line_color, cfg->guide.tv_line_transmittance);

    gl_vertex_t    *v;

    if (guide->tv.visible[0] != 0)
    {
        CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (N - 1) * 6), -1);
        v = guide_add_vertical_line_2_colors(v, c_0, close_n + 1, fade_start, 0.0f);
        v = guide_add_vertical_line_2_colors(v, c_0 + close_n, N - close_n, 0.0f, fade_end);
    }

    if (guide->tv.visible[1] != 0)
    {
        CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (N - 1) * 6), -1);
        v = guide_add_vertical_line_2_colors(v, c_1, close_n + 1, fade_start, 0.0f);
        v = guide_add_vertical_line_2_colors(v, c_1 + close_n, N - close_n, 0.0f, fade_end);
    }

    if (guide->tv.visible[2] != 0)
    {
        CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (N - 1) * 6), -1);
        v = guide_add_vertical_line_2_colors(v, c_2, close_n + 1, fade_start, 0.0f);
        v = guide_add_vertical_line_2_colors(v, c_2 + close_n, N - close_n, 0.0f, fade_end);
    }

    if (guide->tv.visible[3] != 0)
    {
        CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (N - 1) * 6), -1);
        v = guide_add_vertical_line_2_colors(v, c_3, close_n + 1, fade_start, 0.0f);
        v = guide_add_vertical_line_2_colors(v, c_3 + close_n, N - close_n, 0.0f, fade_end);
    }

    return 0;
}

/**
 * @brief   Generate dynamic guidelines overlay for top-front view
 *
 * @param   cfg[in]         Global configuration data
 * @param   svc[in]         SVC-camera configuration
 *
 * @return                  Negative on failure
 */
static int guide_gen_front_tv_line(guide_gen_t *gen, cfg_data_t *cfg, float32_t *U, float32_t angle, guide_data_t *guide)
{
    const int       N = 32;

    cfg_guide_tv_t *tv = &cfg->guide.tv;

    float32_t       points[4 * N + 2][2][3];
    float32_t     (*p_0)[2][3] = &points[0];
    float32_t     (*p_1)[2][3] = p_0 + N;
    float32_t     (*p_2)[2][3] = p_1 + N;
    float32_t     (*p_3)[2][3] = p_2 + N;

    float32_t       coords[4 * N + 2][2][2];
    float32_t     (*c_0)[2][2] = &coords[0];
    float32_t     (*c_1)[2][2] = c_0 + N;
    float32_t     (*c_2)[2][2] = c_1 + N;
    float32_t     (*c_3)[2][2] = c_2 + N;

    float32_t       X0, X1, Y0, Y1;

    float32_t       length = tv->total_length;
    float32_t       sx = length / (float32_t)(N - 1), sy;

    vbo_dynarray_t *vbo = &gen->vbo_bw;


    /* ...set initial X-coordinate position and step along X */
    /* ...rear dynamic lines originate from rear axle */
    X1 = 0.0f;
    sx = -sx;
    
    /* ...front-wheels origin X-coordinate */ /*Refer HMI FTS to understand below code significant*/
    X0 = cfg->vehicle.wheel_base;

    /* ...initial Y-coordinates always depend on the vehicle width including mirrors */
    /*the param total width is just offset*/
    Y0 = cfg->vehicle.width_mirrors*0.5f + tv->total_width;
    Y1 = cfg->vehicle.width_mirrors*0.5f + tv->total_width; 

    /*Tire_width = 301 for STLA*/
    /*Turning_Radius = (wheel_base / SIN(wheel_angle)) + 0.5*Tire Width + wall_to_wall_offset*/  /*We consider wall to wall*/ 

    /* ...calculate instant rotation parameters for a single step: {X(n),Y(n)} = R*{X(n-1),Y(n-1),1} */
    __mat3x3        R;
    guide_instant_rotation_params(cfg, angle, sx, R);

    /* ...build trajectories of all tracks */
    float32_t   line_width = tv->line_width;
    float32_t tr = (fabsf(angle) > 0.000001) ? cfg->vehicle.wheel_base / tanf(angle): INFINITY;

    /*Front*/
    guide_gen_trajectory_line(p_0, N, R, -line_width, 0.0f, X0, Y0, tr);
    guide_gen_trajectory_line(p_1, N, R, line_width, 0.0f, X0, -Y0, tr);

    /*Rear*/
    guide_gen_trajectory_line(p_2, N, R, -line_width, 0.0f, X1, Y1, tr);
    guide_gen_trajectory_line(p_3, N, R, line_width, 0.0f, X1, -Y1, tr);

    /* ...project 3D-points into TV camera sensor space */
    guide_tv_project(U, &points[0][0], &coords[0][0], 4 * N * 2);

    /* ...add trajectory lines */
    int32_t     close_n = (int32_t)ceilf((float32_t)N * (tv->close_section_length / tv->total_length));
    float32_t   fade_start = (float32_t)(N - 1) * tv->fade_section_start_length / tv->total_length;
    float32_t   fade_end = (float32_t)(N - 1) * tv->fade_section_end_length / tv->total_length;
    float32_t   close_line_color[4];
    float32_t   line_color[4];

    /* ...limit size of the close section */
    (close_n > N ? close_n = N : 0);

    guide_set_color(close_line_color, cfg->guide.tv_close_section_color, cfg->guide.tv_close_section_transmittance);
    guide_set_color(line_color, cfg->guide.tv_line_color, cfg->guide.tv_line_transmittance);

    gl_vertex_t    *v;

    if (guide->tv.visible[0] != 0)
    {
        CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (N - 1) * 6), -1);
        v = guide_add_vertical_line_2_colors(v, c_0, close_n + 1, fade_start, 0.0f);
        v = guide_add_vertical_line_2_colors(v, c_0 + close_n, N - close_n, 0.0f, fade_end);
    }

    if (guide->tv.visible[1] != 0)
    {
        CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (N - 1) * 6), -1);
        v = guide_add_vertical_line_2_colors(v, c_1, close_n + 1, fade_start, 0.0f);
        v = guide_add_vertical_line_2_colors(v, c_1 + close_n, N - close_n, 0.0f, fade_end);
    }

    if (guide->tv.visible[2] != 0)
    {
        CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (N - 1) * 6), -1);
        v = guide_add_vertical_line_2_colors(v, c_2, close_n + 1, fade_start, 0.0f);
        v = guide_add_vertical_line_2_colors(v, c_2 + close_n, N - close_n, 0.0f, fade_end);
    }

    if (guide->tv.visible[3] != 0)
    {
        CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (N - 1) * 6), -1);
        v = guide_add_vertical_line_2_colors(v, c_3, close_n + 1, fade_start, 0.0f);
        v = guide_add_vertical_line_2_colors(v, c_3 + close_n, N - close_n, 0.0f, fade_end);
    }

    return 0;
}

/**
 * @brief   Generate dynamic guidelines overlay for top-rear view
 *
 * @param   cfg[in]         Global configuration data
 * @param   svc[in]         SVC-camera configuration
 *
 * @return                  Negative on failure
 */
static int guide_gen_rear_tv_line(guide_gen_t *gen, cfg_data_t *cfg, float32_t *U, float32_t angle, guide_data_t *guide)
{
    const int       N = 32;

    cfg_guide_tv_t *tv = &cfg->guide.tv;

    float32_t       points[4 * N + 2][2][3];
    float32_t     (*p_0)[2][3] = &points[0];
    float32_t     (*p_1)[2][3] = p_0 + N;
    float32_t     (*p_2)[2][3] = p_1 + N;
    float32_t     (*p_3)[2][3] = p_2 + N;

    float32_t       coords[4 * N + 2][2][2];
    float32_t     (*c_0)[2][2] = &coords[0];
    float32_t     (*c_1)[2][2] = c_0 + N;
    float32_t     (*c_2)[2][2] = c_1 + N;
    float32_t     (*c_3)[2][2] = c_2 + N;

    float32_t       X0, X1, Y0, Y1;

    float32_t       length = tv->total_length;
    float32_t       sx = length / (float32_t)(N - 1), sy;

    vbo_dynarray_t *vbo = &gen->vbo_bw;

    /* ...set initial X-coordinate position and step along X */
    /* ...rear dynamic lines originate from rear edge of the vehicle */
    X1 = - tv->rear_gap;
    X0 = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang;

    /* ...initial Y-coordinates always depend on the vehicle width including mirrors */
    /*the param total width is just offset*/
    Y0 = cfg->vehicle.width_mirrors*0.5f + tv->total_width;
    Y1 = cfg->vehicle.width_mirrors*0.5f + tv->total_width; 

    /*Tire_width = 301 for STLA*/
    /*Turning_Radius = (wheel_base / SIN(wheel_angle)) + 0.5*Tire Width + wall_to_wall_offset*/  /*We consider wall to wall*/ 

    /* ...calculate instant rotation parameters for a single step: {X(n),Y(n)} = R*{X(n-1),Y(n-1),1} */
    __mat3x3        R;
    guide_instant_rotation_params(cfg, angle, sx, R);

    /* ...build trajectories of all tracks */
    float32_t   line_width = tv->line_width;
    float32_t tr = (fabsf(angle) > 0.000001) ? cfg->vehicle.wheel_base / tanf(angle): INFINITY;

    /*Front*/
    guide_gen_trajectory_line(p_0, N, R, -line_width, 0.0f, X0, Y0, tr);
    guide_gen_trajectory_line(p_1, N, R, line_width, 0.0f, X0, -Y0, tr);

    /*Rear*/
    guide_gen_trajectory_line(p_2, N, R, -line_width, 0.0f, X1, Y1, tr);
    guide_gen_trajectory_line(p_3, N, R, line_width, 0.0f, X1, -Y1, tr);

    /* ...project 3D-points into TV camera sensor space */
    guide_tv_project(U, &points[0][0], &coords[0][0], 4 * N * 2);

    /* ...add trajectory lines */
    int32_t     close_n = (int32_t)ceilf((float32_t)N * (tv->close_section_length / tv->total_length));
    float32_t   fade_start = (float32_t)(N - 1) * tv->fade_section_start_length / tv->total_length;
    float32_t   fade_end = (float32_t)(N - 1) * tv->fade_section_end_length / tv->total_length;
    float32_t   close_line_color[4];
    float32_t   line_color[4];

    /* ...limit size of the close section */
    (close_n > N ? close_n = N : 0);

    guide_set_color(close_line_color, cfg->guide.tv_close_section_color, cfg->guide.tv_close_section_transmittance);
    guide_set_color(line_color, cfg->guide.tv_line_color, cfg->guide.tv_line_transmittance);

    gl_vertex_t    *v;

    if (guide->tv.visible[0] != 0)
    {
        CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (N - 1) * 6), -1);
        v = guide_add_vertical_line_2_colors(v, c_0, close_n + 1, fade_start, 0.0f);
        v = guide_add_vertical_line_2_colors(v, c_0 + close_n, N - close_n, 0.0f, fade_end);
    }

    if (guide->tv.visible[1] != 0)
    {
        CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (N - 1) * 6), -1);
        v = guide_add_vertical_line_2_colors(v, c_1, close_n + 1, fade_start, 0.0f);
        v = guide_add_vertical_line_2_colors(v, c_1 + close_n, N - close_n, 0.0f, fade_end);
    }

    if (guide->tv.visible[2] != 0)
    {
        CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (N - 1) * 6), -1);
        v = guide_add_vertical_line_2_colors(v, c_2, close_n + 1, fade_start, 0.0f);
        v = guide_add_vertical_line_2_colors(v, c_2 + close_n, N - close_n, 0.0f, fade_end);
    }

    if (guide->tv.visible[3] != 0)
    {
        CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (N - 1) * 6), -1);
        v = guide_add_vertical_line_2_colors(v, c_3, close_n + 1, fade_start, 0.0f);
        v = guide_add_vertical_line_2_colors(v, c_3 + close_n, N - close_n, 0.0f, fade_end);
    }

    return 0;
}

/**
 * @brief   Select side-view trajectory line visibility for specific wheel
 *
 * @param   visible[in, out]    Current visibility state
 * @param   angle[in]           Wheel nominally positive angle, rad
 */
static inline void guide_sv_calc_visibility(int *visible, float32_t angle)
{
    if (*visible != 0)
    {
        *visible = (angle >= (float32_t)(-1.0 * M_PI / 180.0));
    }
    else
    {
        *visible = (angle >= (float32_t)(0.0 * M_PI / 180.0));
    }
}

/**
 * @brief   Generate static guidelines for side-view
 *
 * @param   gen[in]         Guideline generator
 * @param   vcam[in]        Virtual camera data
 * @param   cfg[in]         Configuration data pointer
 * @param   left[in]        Flag indicating left-side guidelines
 * @param   guide[in]       Guidelines data
 *
 * @return                  Negative on failure
 */
static int guide_gen_side_static(guide_gen_t *gen, vcamera_data_t *vcam, cfg_data_t *cfg, int left, guide_data_t *guide)
{
    const int       N = 32;
    const int       M = 16;

    cfg_guide_fixed_sv_t   *fixed = &cfg->guide.fixed_sv;

    float32_t       points[3 * N + M][2][3];
    float32_t     (*p_carpet)[2][3] = &points[0];
    float32_t     (*p_carpet_2)[2][3] = p_carpet + N;
    float32_t     (*p_vert)[2][3] = p_carpet_2 + N;
    float32_t     (*p_hor)[2][3] = p_vert + N;

    float32_t       coords[3 * N + M][2][2];
    float32_t     (*c_carpet)[2][2] = &coords[0];
    float32_t     (*c_carpet_2)[2][2] = c_carpet + N;
    float32_t     (*c_vert)[2][2] = c_carpet_2 + N;
    float32_t     (*c_hor)[2][2] = c_vert + N;

    vbo_dynarray_t *vbo = &gen->vbo;

    float32_t       x0, x1, sx;
    float32_t       y0, y1, yg, sy;
    int             i;

    /* ...set initial Y-coordinate position depending on direction */
    y1 = 0.5f * fixed->total_width;
    y0 = y1 - fixed->bar_width;
    yg = MIN(y0 + fixed->bar_fade_width, y1);

    if (!left)
    {
        y0 = -y0;
        y1 = -y1;
        yg = -yg;
    }

    /* ...set increment along X direction */
    x0 = fixed->vert_line_start;
    x1 = fixed->total_length;
    sx = (x1 - x0) / (float32_t)(N - 1);

    float32_t   line_width = fixed->vert_line_width;

    (left ? line_width = -line_width : 0);

    /* ...generate longitudinal lines */
    for (i = 0; i < N; i++)
    {
        (*p_vert)[0][0] = x0, (*p_vert)[0][1] = y1, (*p_vert)[0][2] = 0.0f;
        (*p_vert)[1][0] = x0, (*p_vert)[1][1] = y1 - line_width, (*p_vert)[1][2] = 0.0f;

        (*p_carpet)[0][0] = x0, (*p_carpet)[0][1] = y1, (*p_carpet)[0][2] = 0.0f;
        (*p_carpet)[1][0] = x0, (*p_carpet)[1][1] = yg, (*p_carpet)[1][2] = 0.0f;

        (*p_carpet_2)[0][0] = x0, (*p_carpet_2)[0][1] = yg, (*p_carpet_2)[0][2] = 0.0f;
        (*p_carpet_2)[1][0] = x0, (*p_carpet_2)[1][1] = y0, (*p_carpet_2)[1][2] = 0.0f;

        x0 += sx;
        p_vert++, p_carpet++, p_carpet_2++;
    }

    /* ...generate lateral line */
    line_width = fixed->hor_line_width;
    x0 = x1;
    y1 -= (left ? fixed->hor_line_gap : -fixed->hor_line_gap);
    y0 = (left ? fixed->hor_line_start : -fixed->hor_line_start);
    sy = (y0 - y1) / (float32_t)(M - 1);
    for (i = 0; i < M; i++)
    {
        (*p_hor)[0][0] = x0, (*p_hor)[0][1] = y1, (*p_hor)[0][2] = 0.0f;
        (*p_hor)[1][0] = x0 - line_width, (*p_hor)[1][1] = y1, (*p_hor)[1][2] = 0.0f;

        y1 += sy;
        p_hor++;
    }

    /* ...distort points into virtual camera space */
    guide_vcam_project(vcam, &points[0][0], &coords[0][0], (3 * N + M) * 2);

    /* ...allocate dynamic array */
    gl_vertex_t    *v;
    CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (3 * (N - 1) + 1 * (M - 1)) * 6), -1);

    /* ...add carpet bar */
    float32_t   surface_color[4];
    guide_set_color(surface_color, cfg->guide.static_surface_color, cfg->guide.static_surface_transmittance);
    v = guide_add_vertical_line(v, c_carpet, N, 0.0f, 0.0f, surface_color);
    v = guide_add_horizontal_line(v, c_carpet_2, N, surface_color);

    /* ...add static lines */
    float32_t   static_line_color[4];
    guide_set_color(static_line_color, cfg->guide.static_line_color, cfg->guide.static_line_transmittance);
    v = guide_add_vertical_line(v, c_vert, N, (N - 1) * (fixed->vert_fade_length / x1), 0.0f, static_line_color);
    v = guide_add_vertical_line(v, c_hor, M, 0.0f, (M - 1) * (fixed->hor_fade_length / fabsf(y1 - y0)), static_line_color);

    return 0;
}

/**
 * @brief   Generate guidelines for side-view
 *
 * @param   gen[in]         Guideline generator
 * @param   vbo[in]         Dynamic VBO array
 * @param   vcam[in]        Virtual camera data
 * @param   cfg[in]         Configuration data pointer
 * @param   left[in]        Flag indicating left-side guidelines
 * @param   angle[in]       Wheel angle, radians
 */
static int guide_gen_side_dynamic(guide_gen_t *gen, vcamera_data_t *vcam, cfg_data_t *cfg, int left, int stv, float32_t angle, guide_data_t *guide)
{
    const int       N = 32;

    float32_t       points[N][2][3];
    float32_t     (*p_dyn)[2][3] = &points[0];

    float32_t       coords[N][2][2];
    float32_t     (*c_dyn)[2][2] = &coords[0];

    float32_t       x0, y0, sx;
    int             i;

    vbo_dynarray_t *vbo = &gen->vbo;

    /* ...draw dynamic guideline */
    cfg_guide_dynamic_sv_t *dynamic = (stv ? &cfg->guide.dynamic_sv_stv : &cfg->guide.dynamic_sv);
    float32_t       length = dynamic->total_length;
    float32_t       line_width = dynamic->line_width;
    float32_t       delta_width = dynamic->delta_width * fabsf(angle);

    if (left != 0)
    {
        line_width = -line_width;
        delta_width = -delta_width;
    }

    sx = -length / (float32_t)(N - 1);
    x0 = 0;
    y0 = dynamic->total_width * (left ? 0.5f : -0.5f);

    __mat3x3        R;
    guide_instant_rotation_params(cfg, angle, sx, R);
    float32_t tr = (fabsf(angle) > 0.000001) ? cfg->vehicle.wheel_base / tanf(angle): INFINITY;
    guide_gen_trajectory_line(p_dyn, N, R, line_width, delta_width, x0, y0, tr);

    /* ...distort points into virtual camera space */
    guide_vcam_project(vcam, &points[0][0], &coords[0][0], N * 2);

    /* ...add dynamic trajectory line */
    float32_t   dynamic_line_color[4];
    float32_t   fade_start = (float32_t)(N - 1) * dynamic->fade_section_start_length / dynamic->total_length;
    float32_t   fade_end = (float32_t)(N - 1) * dynamic->fade_section_end_length / dynamic->total_length;

    gl_vertex_t    *v;
    CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), (N - 1) * 6), -1);
    guide_set_color(dynamic_line_color, cfg->guide.dynamic_line_color, cfg->guide.line_transmittance);
    v = guide_add_vertical_line(v, c_dyn, N, fade_start, fade_end, dynamic_line_color);

    return 0;
}

/**
 * @brief   Add sector carpet
 */
static gl_vertex_t * guide_add_sector(gl_vertex_t *v, float32_t (*p0)[2], int N0, float32_t (*p1)[2], int N1, float32_t (*p2)[2], int N2, float32_t *color)
{
    int     i;

    /* ...carpet color: {GBRA} */
    float32x4_t     C = vld1q_f32(color);

    p2 += N2 - 1;

    /* ...central point buffer */
    float32_t       center[2] = { (p0[0][0] + p1[0][0] + p2[0][0]) / 3.0f, (p0[0][1] + p1[0][1] + p2[0][1]) / 3.0f };

    float32x2x3_t   B0 = guide_vertex_encode(center, C);

    /* ...first triangle point */
    float32x2x3_t   B1 = guide_vertex_encode(*p0++, C);

    /* ...create triangle fan */
    for (i = 1; i < N0; i++)
    {
        float32x2x3_t   B2 = guide_vertex_encode(*p0++, C);

        vst3_f32(*v++, B0);
        vst3_f32(*v++, B1);
        vst3_f32(*v++, B2);

        B1 = B2;
    }

    for (i = 1; i < N1; i++)
    {
        float32x2x3_t   B2 = guide_vertex_encode(*++p1, C);

        vst3_f32(*v++, B0);
        vst3_f32(*v++, B1);
        vst3_f32(*v++, B2);

        B1 = B2;
    }

    for (i = 1; i < N2; i++)
    {
        float32x2x3_t   B2 = guide_vertex_encode(*--p2, C);

        vst3_f32(*v++, B0);
        vst3_f32(*v++, B1);
        vst3_f32(*v++, B2);

        B1 = B2;
    }

    return v;
}


float32_t solve_quadratic_equation(float32_t R, float32_t d1, float32_t y0, float32_t H, float32_t d0, float32_t x0)
{
    // Coefficients of the quadratic equation
    float32_t a = d1*d1 + d0*d0;
    float32_t b = 2 * d1 * (y0 + H) + 2 * d0 * x0;
    float32_t c = (y0 + H)*(y0 + H) + x0*x0 - R*R;

    // Discriminant
    float32_t D = b*b - 4 * a * c;

    // Check for real roots
    if (D < 0) {
        return 0.0;
    } else {
        // Solutions of the equation
        float32_t x1 = (-b + sqrt(D)) / (2 * a);
        float32_t x2 = (-b - sqrt(D)) / (2 * a);
        // we need the largest solution
        return x1 > x2 ? x1 : x2;
    }
}


static inline void linspace(float32_t start, float32_t end, int num, float32_t arr[])
{
    float32_t step = (end - start) / (num - 1);
    for (int i = 0; i < num; i++) 
    {
        arr[i] = start + i * step;
    }
}

static inline void linspace2d(float32_t* start, float32_t* end, float32_t z, int num, float32_t arr[])
{
    float32_t step0 = (end[0] - start[0]) / (num - 1);
    float32_t step1 = (end[1] - start[1]) / (num - 1);
    for (int i = 0; i < num; i++) 
    {
        arr[i*3 + 0] = start[0] + i * step0;
        arr[i*3 + 1] = start[1] + i * step1;
        arr[i*3 + 2] = z;
    }
}


static void find_curve_points(float32_t H,
    float32_t L,
    float32_t R,
    int N,
    int M,
    float32_t AL,
    float32_t z,
    float32_t* arc_points,
    float32_t* line_points,
    float32_t* arc_points_bottom,
    float32_t* tmp)
{
    // Circle center
    float32_t center_x = -sqrt(R*R - H*H), center_y = 0;

    // Angle by which the arc of the circle has turned
    float32_t theta = AL / R;

    // Angle of the tangent to the circle
    float32_t tangent_angle = -asin(H/R) - theta;

    // Calculation of points on the arc of the circle
    linspace(-asin(H/R), -asin(H/R) - theta, N / 2, tmp);

    for (int i = 0; i < (N / 2); i++) {
        arc_points[i*3 + 0] = center_x + R * cosf(tmp[i]);
        arc_points[i*3 + 1] = center_y + R * sinf(tmp[i]);
        arc_points[i*3 + 2] = z;
    }

    float32_t* line_start_point = &arc_points[(N / 2 - 1)*3];

    // Direction of the tangent
    float32_t direction[2] = {tan(tangent_angle), -1};
    float32_t norm = sqrt(direction[0]*direction[0] + direction[1]*direction[1]);
    direction[0] /= norm;
    direction[1] /= norm;
    float32_t l = solve_quadratic_equation(L, direction[1], line_start_point[1], H, direction[0], line_start_point[0]);

    float32_t line_end_point[2] = {line_start_point[0] + l * direction[0], line_start_point[1] + l * direction[1]};

    linspace2d(line_start_point, line_end_point, z, N / 2, line_points);

    float32_t s[2] = {(line_end_point[0] - 0) / L, (line_end_point[1] + H) / L};

    float32_t angle = atan2f(s[1], s[0]);
    float32_t arc_len = fabsf(angle + (float32_t)(M_PI/2));

    linspace(angle, angle + arc_len, M, tmp);

    for (int i = 0; i < M; i++) {
        arc_points_bottom[i*3 + 0] = L * cosf(tmp[i]);
        arc_points_bottom[i*3 + 1] = -H + L * sinf(tmp[i]);
        arc_points_bottom[i*3 + 2] = z;
    }
}

static inline float32_t euclidean_dist_2d(float32_t x1, float32_t y1, float32_t x2, float32_t y2)
{
    return sqrtf((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int32_t tha_check(cfg_data_t *cfg, vehicle_state_t *vehicle, float32_t world_coords[3] )
{
    cfg_guide_tha_t *tha = &cfg->guide.tha;
    float32_t       X0 = -cfg->vehicle.rear_overhang - tha->offset[0];
    float32_t       Z0 = tha->offset[2];

    float32_t       angle = tha->angle * (float32_t)(0.5 * M_PI / 180.0);
    
    float32_t       left_right = tha->radius;
    float32_t       length = tha->length;

    float32_t centerLR = sqrt(left_right*left_right - X0*X0);
    float32_t D1 = euclidean_dist_2d(world_coords[0], -fabsf(world_coords[1]), 0, -centerLR);
    float32_t D3 = euclidean_dist_2d(world_coords[0], world_coords[1], X0, 0);

    if (D1 > left_right && D3 < length)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief   Generate guidelines for THA-view
 *
 * @param   gen[in]         Guideline generator
 * @param   vcam[in]        Virtual camera data
 * @param   cfg[in]         Configuration data pointer
 * @param   guide[in]       Guideline data
 */
static int guide_gen_tha_static(guide_gen_t *gen, vcamera_data_t *vcam, cfg_data_t *cfg, guide_data_t *guide)
{
    const int       N = 32;
    const int       M = 8;

    float32_t       points[(N+M)*2][3];
    float32_t       coords[(N+M)*2][2];

    int             i;

    /* ...draw dynamic guideline */
    cfg_guide_tha_t *tha = &cfg->guide.tha;
    float32_t       angle = tha->angle * (float32_t)(0.5 * M_PI / 180.0);
    float32_t       s = sinf(angle), c = cosf(angle);
    float32_t       length = tha->length;
    float32_t       line_width = tha->line_width;
    float32_t       border_width = tha->border_width;
    float32_t       tha_R = tha->radius;
    float32_t       AL = tha->arc_len;

    float32_t       X0 = -cfg->vehicle.rear_overhang - tha->offset[0];
    float32_t       Z0 = tha->offset[2];

    find_curve_points(-X0, length, tha_R, N, M, AL, Z0, &points[0][0], &points[N/2][0], &points[N][0], &coords[0][0]);

    for (i = 0; i < (N+M); i++)
    {
        float32_t t = points[i][0];
        points[i][0] = points[i][1];
        points[i][1] = t;
    }

    /// mirroring
    for (i = 0; i < (N+M); i++)
    {
        points[i + N + M][0] = points[i][0];
        points[i + N + M][1] = -points[i][1];
        points[i + N + M][2] = points[i][2];

    }
    /* ...project points into virtual camera sensor space */
    guide_vcam_project(vcam, &points[0], &coords[0], ((N+M)*2));

    /* ...reserve place in dynamic vertex buffer array */
    vbo_dynarray_t *vbo = &gen->vbo;
    vbo_dynarray_t *vbo_line = &gen->vbo_lines;
    gl_vertex_t    *v;
    gl_vertex_t    *v_line;
    CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(gl_vertex_t), (N-1+M-1)*6), -1);
    CHK_ERR(v_line = vbo_dynarray_add(vbo_line, sizeof(gl_vertex_t), (N-1+M-1)*4), -1);

    float32_t   line_color[4], canvas_color[4];
    guide_set_color(line_color, tha->line_color, tha->line_transmittance);
    guide_set_color(canvas_color, tha->canvas_color, tha->canvas_transmittance);

    memset(v_line, 0, sizeof(gl_vertex_t));
    v_line = put_line_c(v_line, &coords[0 * N][0], &coords[N + M][0], N, line_color);
    v_line = put_line_c(v_line, &coords[1 * N][0], &coords[N + N + M][0], M, line_color);

    /* ...add sector lines */
    v = guide_add_vertical_line_2(v, &coords[0 * N], &coords[N + M], N, 0.0f, 0.0f, canvas_color);
    v = guide_add_vertical_line_2(v, &coords[1 * N], &coords[N + N + M], M, 0.0f, 0.0f, canvas_color);

    return 0;
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Guideline generator initialization
 */
guide_gen_t * guide_gen_create(icon_data_t* icon_data)
{
    guide_gen_t    *gen;

    /* ...allocate generator data */
    CHK_ERR(gen = calloc(1, sizeof(*gen)), NULL);

    /* ...create dynamic array */
    if (vbo_dynarray_init(&gen->vbo, sizeof(gl_vertex_t), 1500) != 0)
    {
        TRACE(ERROR, _x("failed to create dynarray: %s"), strerror(errno));
        free(gen);
        gen = NULL;
    }

    if (vbo_dynarray_init(&gen->vbo_ffc, sizeof(gl_vertex_ffc_t), (ffc_sections-1U)*12U) != 0)
    {
        TRACE(ERROR, _x("failed to create dynarray: %s"), strerror(errno));
        free(gen);
        gen = NULL;
    }

    if (vbo_dynarray_init(&gen->vbo_hatched, sizeof(gl_vertex_ffc_t), (max_hatched_sections-1U)*max_quads_in_sections*6U) != 0)
    {
        TRACE(ERROR, _x("failed to create dynarray: %s"), strerror(errno));
        free(gen);
        gen = NULL;
    }

    if (vbo_dynarray_init(&gen->vbo_lines, sizeof(gl_vertex_t), 256U) != 0)
    {
        TRACE(ERROR, _x("failed to create dynarray: %s"), strerror(errno));
        free(gen);
        gen = NULL;
    }

    icon_item_t* item = NULL;

    if (icon_get_resource(icon_data, ICON_GL_FFC, &item) )
    {
        TRACE(ERROR, _x("failed to get icon resource"));
        free(gen);
        gen = NULL;
    }
    else
    {
        gen->ffc_tex = item->tex;
    }

    if (icon_get_resource(icon_data, ICON_TV_HATCHED, &item) )
    {
        TRACE(ERROR, _x("failed to get icon resource"));
        free(gen);
        gen = NULL;
    }
    else
    {
        gen->hatched_tex = item->tex;
        memcpy(gen->hatched_dst, item->src, sizeof(gen->hatched_dst));
    }

    return gen;
}


/**
 * @brief   Generate dynamic guidelines overlay for top-view
 *
 * @param   gen[in]         Guidelines generator
 * @param   cfg[in]         Global configuration data
 * @param   tv[in]          TV-mesh configuration
 * @param   forward[in]     Forward movement flag
 * @param   vehicle[in]     Vehicle state
 * @param   guide[in]       Guidelines descriptor
 *
 * @return                  Negative on failure
 */
int guide_gen_top_view(guide_gen_t *gen, cfg_data_t *cfg, cfg_tv_mesh_t *tv, int forward, vehicle_state_t *vehicle, guide_data_t *guide)
{
    float32_t       angle = vehicle->wheel_angle * (float32_t)(M_PI / 180.0);
    float32_t       U[2 * 3];
    int             r;

    /* ...determine trajectory lines visibility */
    if (forward != 0)
    {
        /* ...front-wheels trajectories are always visible */
        guide->tv.visible[0] = guide->tv.visible[1] = 1;

        /* ...rear-left wheel trajectory visibility */
        guide_tv_calc_visibility(&guide->tv.visible[2], angle);

        /* ...rear-right wheel trajectory visibility */
        guide_tv_calc_visibility(&guide->tv.visible[3], -angle);
    }
    else
    {
        /* ...front-left wheel visibility */
        guide_tv_calc_visibility(&guide->tv.visible[0], -angle);

        /* ...front-right wheel visibility */
        guide_tv_calc_visibility(&guide->tv.visible[1], angle);

        /* ...rear-wheels are always visible */
        guide->tv.visible[2] = guide->tv.visible[3] = 1;
    }

    /* ...world-coordinates of vehicle geometric center */
    float32_t   C[2] = {
        (cfg->vehicle.wheel_base + cfg->vehicle.front_overhang - cfg->vehicle.rear_overhang) * 0.5f,
        0.0f,
    };

    /* ...prepare transformation matrix */
    guide_gen_tv_prepare(tv, C, U);

    /* ...prepare guidelines generator */
    guide_gen_prepare(gen, tv->base.dst, guide);

    if (!vehicle->gl_disable != 0)
    {
        if(forward)
        {
            if(vehicle->front_gl_enable)
            {
                /* ...generate guidelines top front view */
                guide_gen_front_tv_line(gen, cfg, U, angle, guide);
            }
        }
        else
        {
            if(vehicle->rear_gl_enable)
            {
                /* ...generate guidelines for top rear view */
                guide_gen_rear_tv_line(gen, cfg, U, angle, guide);
            }
        }
    }

    /* ...upload points into VBO */
    return guide_gen_finalize(gen, guide);
}

/**
 * @brief   Generate guidelines for front/rear-view
 *
 * @param   gen[in]         Guidelines generator data
 * @param   cfg[in]         Global configuration data
 * @param   scv[in]         SCV-configuration data
 * @param   front[in]       Front-view guidelines
 * @param   narrow[in]      Narrow-view flag
 * @param   vehicle[in]     Vehicle state data
 * @param   guide[in]       Guideline descriptor
 *
 * @return                  Negative on failure
 */
int guide_front_rear_generate(guide_gen_t *gen, cfg_data_t *cfg, cfg_scv_mesh_t *scv, int front, int narrow, vehicle_state_t *vehicle,  guide_data_t *guide)
{
    float32_t       angle = vehicle->wheel_angle * (float32_t)(M_PI / 180.0);
    vcamera_data_t  vcam;
    int             r = 0;

    /* ...prepare virtual camera configuration */
    guide_prepare_vcam(&vcam, scv, vehicle);

    /* ...prepare guidelines generator */
    guide_gen_prepare(gen, scv->base.dst, guide);

    /* ...generate fixed guidelines */
    //guide_gen_fixed_line(gen, cfg, &vcam, front, narrow);

    /* ...for narrow view add dynamic guidelines */
    if (narrow != 0 && !vehicle->gl_disable)
    {
        if (front && vehicle->front_gl_enable)
        {
            guide_gen_dynamic_line_stl(gen, cfg, &vcam, 1, 0, angle);
        }
        else if (!front && vehicle->rear_gl_enable)
        {
            guide_gen_dynamic_line_stl(gen, cfg, &vcam, 0, 0, angle);
        }
    }

    /* ...upload points into VBO */
    return guide_gen_finalize(gen, guide);
}


/**
 * @brief   Generate guidelines for front/rear-view
 *
 * @param   gen[in]         Guidelines generator data
 * @param   cfg[in]         Global configuration data
 * @param   scv[in]         SCV-configuration data
 * @param   front[in]       Front-view guidelines
 * @param   narrow[in]      Narrow-view flag
 * @param   vehicle[in]     Vehicle state data
 * @param   guide[in]       Guideline descriptor
 *
 * @return                  Negative on failure
 */
int guide_ffc_generate(guide_gen_t *gen, cfg_data_t *cfg, cfg_scv_mesh_t *scv, int front, int narrow, vehicle_state_t *vehicle,  guide_data_t *guide)
{
    guide->ffc_tex = gen->ffc_tex;
    float32_t       angle = vehicle->wheel_angle * (float32_t)(M_PI / 180.0);
    vcamera_data_t  vcam;
    int             r = 0;

    /* ...prepare virtual camera configuration */
    guide_prepare_vcam(&vcam, scv, vehicle);

    /* ...prepare guidelines generator */
    guide_gen_prepare(gen, scv->base.dst, guide);

    if (vehicle->ffc_gl_enable)
    {
        guide_gen_ffc(gen, cfg, &vcam, front, 0, angle);
    }

    /* ...upload points into VBO */
    return guide_gen_finalize(gen, guide);
}

void calculate_tex_cooords(gl_vertex_ffc_t* vertex, uint32_t N, float32_t tex_width, float32_t tex_height, int32_t dst_roi[4])
{
    float32_t DW = dst_roi[2] - dst_roi[0];
    float32_t DH = dst_roi[3] - dst_roi[1];

    for (uint32_t i = 0; i < N; i++)
    {
        vertex[i][2] = (vertex[i][0]*DW / tex_width + 1.f)*0.5f;
        vertex[i][3] = (vertex[i][1]*DH / tex_height + 1.f)*0.5f;
    }
}

static int find_circumcenter(__vec2 A, __vec2 B, __vec2 O, __vec2 ret)
{
    __vec2 M = {(A[0] + B[0]) * 0.5f, (A[1] + B[1]) * 0.5f};

    __vec2 bisec = {M[0] - O[0], M[1] - O[1]};

    float32_t angle = atan2f(bisec[1], bisec[0]);

    float32_t c = cosf(angle);
    float32_t s = sinf(angle);

    __vec2 R[2] = {{c, -s}, {s, c}};

    __vec2 A1 = {R[0][0] * A[0] + R[0][1] * A[1], R[1][0] * A[0] + R[1][1] * A[1]};
    __vec2 B1 = {R[0][0] * B[0] + R[0][1] * B[1], R[1][0] * B[0] + R[1][1] * B[1]};
    __vec2 O1 = {R[0][0] * O[0] + R[0][1] * O[1], R[1][0] * O[0] + R[1][1] * O[1]};

    float32_t dya = A1[1] - O1[1];
    float32_t dxa = A1[0] - O1[0];
    float32_t dyb = B1[1] - O1[1];
    float32_t dxb = B1[0] - O1[0];

    if (fabsf(dya) < 1e-6 || fabsf(dyb) < 1e-6)
    {
        return -1;
    }

    float32_t ka = -dxa/dya;
    float32_t kb = -dxb/dyb;

    float32_t ba = A1[1] - ka*A1[0];
    float32_t bb = B1[1] - kb*B1[0];


    if (fabsf(ka - kb) < 1e-6)
    {
        return -1;
    }

    float32_t x = (bb - ba)/(ka - kb);
    float32_t y = ka*x + ba;

    ret[0] = R[0][0] * x + R[1][0] * y;
    ret[1] = R[0][1] * x + R[1][1] * y;

    return 0;
}

static void draw_rounging_off_corner(__vec2 points[TV_HATCHED_MAX_POINTS],
    __vec3* dst,
    uint32_t max_n_dst,
    uint32_t indx_src,
    uint32_t* indx_dst,
    float32_t rounding_off)

{

    rounding_off = MIN(rounding_off, 0.98f);
    float32_t d0 = 0.f;
    float32_t d1 = 0.f;
    float32_t d  = 0.f;
    __vec2 dvec0,dvec1;

    __vec2  prev = {dst[*indx_dst - 1][0], dst[*indx_dst - 1][1]};

    if (rounding_off > 0)
    {
        __vec2_sub(prev, points[indx_src], dvec0);
        __vec2_sub(points[indx_src + 1], points[indx_src], dvec1);
        d0 = sqrtf(__vec2_dprod(dvec0, dvec0));
        d1 = sqrtf(__vec2_dprod(dvec1, dvec1));

        __vec2_muls(dvec0, 1.f / d0, dvec0);
        __vec2_muls(dvec1, 1.f / d1, dvec1);

        d = MIN(d0, d1)*rounding_off;
    }

    if (d == 0.f)
    {
        if (*indx_dst < (max_n_dst - 1))
        {
            dst[*indx_dst][0] = points[indx_src][0];
            dst[*indx_dst][1] = points[indx_src][1];
            dst[*indx_dst][2] = 0.f;
            (*indx_dst)++;
        }
    }
    else
    {
        __vec2 O = {points[indx_src][0], points[indx_src][1]};
        __vec2 A,B,t;

        __vec2_muls(dvec0, d, t);
        __vec2_add(O, t, A);

        __vec2_muls(dvec1, d, t);
        __vec2_add(O, t, B);

        __vec2 C;
        int check = find_circumcenter(A, B, O, C);

        if (check != 0)
        {
            if (*indx_dst < (max_n_dst - 1))
            {
                dst[*indx_dst][0] = points[indx_src][0];
                dst[*indx_dst][1] = points[indx_src][1];
                dst[*indx_dst][2] = 0.f;
                (*indx_dst)++;
            }

            return;
        }

        __vec2 dca;
        __vec2_sub(C, A, dca);
        float32_t length = sqrtf(__vec2_dprod(dca, dca));



        __vec2 v1 = {A[0] - C[0], A[1] - C[1]};
        __vec2 v2 = {B[0] - C[0], B[1] - C[1]};

        float32_t arc1 = atan2f(v1[1], v1[0]);
        float32_t arc2 = atan2f(v2[1], v2[0]);

        if (arc1 < 0)
        {
            arc1 += 2*M_PI;
        }

        if (arc2 < 0)
        {
            arc2 += 2*M_PI;
        }

        float32_t arc = arc2 - arc1;

        float32_t step = arc / 16.f;

        for (uint32_t i = 1; i <= 16; i++)
        {
            if (*indx_dst < (max_n_dst - 1))
            {
                dst[*indx_dst][0] = C[0] + length*cosf(arc1 + i*step);
                dst[*indx_dst][1] = C[1] + length*sinf(arc1 + i*step);
                dst[*indx_dst][2] = 0.f;
                (*indx_dst)++;
            }
        }
    }
}


/**
 * @brief   Generate guidelines for front/rear-view
 *
 * @param   gen[in]         Guidelines generator data
 * @param   cfg[in]         Global configuration data
 * @param   scv[in]         SCV-configuration data
 * @param   front[in]       Front-view guidelines
 * @param   narrow[in]      Narrow-view flag
 * @param   vehicle[in]     Vehicle state data
 * @param   guide[in]       Guideline descriptor
 *
 * @return                  Negative on failure
 */
int guide_hatched_generate(guide_gen_t *gen, cfg_data_t *cfg, cfg_tv_mesh_t *tv, guide_data_t *guide)
{
    guide->hatched_tex = gen->hatched_tex;
    int             r = 0;

    guide_gen_prepare(gen, tv->base.dst, guide);

    gl_vertex_ffc_t    *v;
    vbo_dynarray_t *vbo = &gen->vbo_hatched;

    float32_t U[2 * 3] = {0};

    float32_t tex_width = gen->hatched_dst[2] - gen->hatched_dst[0];
    float32_t tex_height = gen->hatched_dst[3] - gen->hatched_dst[1];

    /* ...world-coordinates of vehicle geometric center */
    float32_t   C[2] = {
        (cfg->vehicle.wheel_base + cfg->vehicle.front_overhang - cfg->vehicle.rear_overhang) * 0.5f,
        0.0f,
    };

    /* ...prepare transformation matrix */
    guide_gen_tv_prepare(tv, C, U);

    cfg_guide_tv_hatched_t* hatched_cfg = &cfg->guide.tv_hatched;

    __vec2* points = hatched_cfg->points;
    float32_t* rounding_off_corners = hatched_cfg->rounding_off_corners;

    __vec2* points_l = gen->display_points_for_hatched_area_l;
    __vec2* points_r = gen->display_points_for_hatched_area_r;

    uint32_t indx_src = 1;
    uint32_t indx_dst = 1;
    gen->curved_points_for_hatched_area[0][0] = points[0][0];
    gen->curved_points_for_hatched_area[0][1] = points[0][1];
    gen->curved_points_for_hatched_area[0][2] = 0.f;

    for (; indx_src < hatched_cfg->num_points - 1; indx_src++)
    {
        draw_rounging_off_corner(points, gen->curved_points_for_hatched_area, sizeof(gen->curved_points_for_hatched_area), indx_src, &indx_dst, rounding_off_corners[indx_src - 1]);
    }
    draw_rounging_off_corner(points, gen->curved_points_for_hatched_area, sizeof(gen->curved_points_for_hatched_area), indx_src, &indx_dst, 0.f);

    guide_tv_project(U, gen->curved_points_for_hatched_area, points_l, indx_dst);

    for (uint32_t i = 0; i < indx_dst; i++)
    {
        gen->curved_points_for_hatched_area[i][1] = -gen->curved_points_for_hatched_area[i][1];
    }

    guide_tv_project(U, gen->curved_points_for_hatched_area, points_r, indx_dst);

    for (uint32_t i = 1; i < indx_dst; i++)
    {
        {
            /// add quad
            CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), 6), -1);
            v[0][0] = points_l[i - 1][0];
            v[0][1] = points_l[i - 1][1];
            v[0][4] = 0.f;

            v[1][0] = points_r[i - 1][0];
            v[1][1] = points_r[i - 1][1];
            v[1][4] = 0.f;

            v[2][0] = points_r[i][0];
            v[2][1] = points_r[i][1];
            v[2][4] = 0.f;

            v[3][0] = points_r[i][0];
            v[3][1] = points_r[i][1];
            v[3][4] = 0.f;

            v[4][0] = points_l[i][0];
            v[4][1] = points_l[i][1];
            v[4][4] = 0.f;

            v[5][0] = points_l[i - 1][0];
            v[5][1] = points_l[i - 1][1];
            v[5][4] = 0.f;

            calculate_tex_cooords(v, 6, tex_width, tex_height, guide->dst);
        }
    }

    /* ...upload points into VBO */
    return guide_gen_finalize(gen, guide);
}

/**
 * @brief   Generate guidelines for see-through view
 *
 * @param   gen[in]         Guidelines generator
 * @param   cfg[in]         Global configuration data
 * @param   stv[in]         STV-configuration data
 * @param   front[in]       Front-view guidelines
 * @param   vehicle[in]     Vehicle state data
 * @param   guide[in]       Guideline descriptor
 *
 * @return                  Negative on failure
 */
int guide_stv_generate(guide_gen_t *gen, cfg_data_t *cfg, cfg_stv_mesh_t *stv, int front, vehicle_state_t *vehicle, guide_data_t *guide)
{
    float32_t       angle = vehicle->wheel_angle * (float32_t)(M_PI / 180.0);
    vcamera_data_t  vcam;
    int             r = 0;

    /* ...prepare virtual camera configuration */
    guide_prepare_stv_vcam(&vcam, stv);

    /* ...save destination tile (pointer shall be enough - tbd) */
    guide_gen_prepare(gen, stv->base.dst, guide);

    /* ...generate dynamic guidelines */
    if (!vehicle->gl_disable && (vehicle->front_gl_enable || vehicle->rear_gl_enable))
    {
        guide_gen_dynamic_line(gen, cfg, &vcam, vehicle->front_gl_enable, 1, angle);
    }

    /* ...upload points into VBO */
    return guide_gen_finalize(gen, guide);
}

static void set_point3d(float32_t p[3], float32_t x, float32_t y, float32_t z)
{
    p[0] = x;
    p[1] = y;
    p[2] = z;
}

uint32_t tha_check_arc(float32_t (*coords)[2], float32_t point[2])
{
    uint32_t i;

    for (i = 1; i < 4; i++)
    {
        coords[i][0]-=coords[0][0];
        coords[i][1]-=coords[0][1];
    }

    point[0]-= coords[0][0];
    point[1]-= coords[0][1];

    float32_t angle_point = atan2f(point[0], point[1]);
    float32_t angle_arc = atan2f(coords[1][0], coords[1][1]);

    float32_t length_point = (point[0]*point[0] + point[1]*point[1]);
    float32_t length_arc = (coords[2][0]*coords[2][0] + coords[2][1]*coords[2][1]);

    return (fabsf(angle_point) < fabsf(angle_arc) && length_point < length_arc) ? 1 : 0;
}

/**
 * @brief   Generate guidelines for THA view
 *
 * @param   cfg[in]         Global configuration data
 * @param   scv[in]         SCV-configuration data
 * @param   vehicle[in]     Vehicle state data
 * @param   guide[in]       Guideline descriptor
 *
 * @return                  Negative on failure
 */
int guide_tha_generate(guide_gen_t *gen, cfg_data_t *cfg, cfg_scv_mesh_t *scv, vehicle_state_t *vehicle, guide_data_t *guide)
{
    vcamera_data_t  vcam;

    /* ...prepare guidelines generator */
    guide_gen_prepare(gen, scv->base.dst, guide);

    if (vehicle->tha_gl_enable)
    {
        /* ...prepare virtual camera configuration */
        guide_prepare_vcam(&vcam, scv, vehicle);

        /* ...generate THA guidelines */
        guide_gen_tha_static(gen, &vcam, cfg, guide);
    }

    return guide_gen_finalize(gen, guide);
}

/**
 * @brief   Generate guidelines for side-view
 *
 * @param   cfg[in]         Global configuration data
 * @param   scv[in]         SCV-configuration data
 * @param   left[in]        Left/right side flag
 * @param   vehicle[in]     Vehicle state data
 * @param   guide[in]       Guideline descriptor
 *
 * @return                  Negative on failure
 */
int guide_side_generate(guide_gen_t *gen, cfg_data_t *cfg, cfg_scv_mesh_t *scv, int left, vehicle_state_t *vehicle, guide_data_t *guide)
{
    float32_t       angle = vehicle->wheel_angle * (float32_t)(M_PI / 180.0);
    vcamera_data_t  vcam;

    /* ...determine wheel trajectory lines visibility */
    if (0)
    {
        guide_sv_calc_visibility(&guide->sv.visible, (left ? angle : -angle));
    }
    else
    {
        guide_tv_calc_visibility(&guide->sv.visible, (left ? angle : -angle));
    }

    /* ...prepare virtual camera configuration */
    guide_prepare_vcam(&vcam, scv, vehicle);

    /* ...prepare guidelines generator */
    guide_gen_prepare(gen, scv->base.dst, guide);

    /* ...generate side-view guidelines */
    guide_gen_side_static(gen, &vcam, cfg, left, guide);

    /* ...generate dynamic guidelines as needed */
    if (!vehicle->gl_disable && guide->sv.visible != 0)
    {
        guide_gen_side_dynamic(gen, &vcam, cfg, left, 0, angle, guide);
    }

    return guide_gen_finalize(gen, guide);
}

/**
 * @brief   Render guidelines overlay
 *
 * @param   guide[in]       Guidelines data
 * @param   ctx[in]         Rendering context
 * @param   intensity[in]   Global scene intensity
 */
void guide_render(guide_data_t *guide, render_context_t *ctx, float32_t intensity)
{
    int32_t    *dst = guide->dst;

    /* ...prepare GL context */
    render_context_set_view(ctx, dst);

    /* ...do not use depth testing - tbd - maybe not? */
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_CULL_FACE);

    /* ...now render the VBO as a set of points - just one or a set of them? - tbd */
    
    if (guide->vbo)
    {
        gl_vbo_render(guide->vbo, intensity, 0);
        gl_vbo_render(guide->vbo_bw, intensity, 1);
        gl_vbo_render_ffc(guide->vbo_ffc, intensity, guide->ffc_tex);
        gl_vbo_render_ffc(guide->vbo_hatched, intensity, guide->hatched_tex);
        gl_vbo_render_lines(guide->vbo_lines, intensity);
    }
}
