/*******************************************************************************
 * mesh-render.c
 *
 * Mesh renderer for surround view
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

#define MODULE_TAG                      MESH-RENDER

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "math-neon.h"
#include "display.h"
#include "mesh-gen.h"
#include "mesh-render.h"
#include "sv_api.h"

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);


#define SH_OUT_FMT  "float"
#define SH_OUT_SC  "1.0"

/*******************************************************************************
 * Vertex shader construction
 ******************************************************************************/

/**> Vertex shader construction */
#define __SH_VERTEX                                                        \
    SH_SETPREC                                                             \
    "attribute vec2 XY;\n"                                                 \
    "attribute vec2 UV;\n"                                                 \
    "attribute vec2 Q;\n"                                                  \
    "varying vec2 xy;\n"                                                   \
    "varying vec2 uv;\n"                                                   \
    "varying vec2 q;\n"                                                    \
    "uniform float depth;\n"                                                            \
    "void main(void)\n"                                                    \
    "{\n"                                                                  \
    "   xy = vec2(XY.x, -XY.y);\n"                                         \
    "   uv = UV;\n"                                                        \
    "   q = Q;\n"                                                          \
    "   gl_Position = vec4(XY.x, -XY.y, depth, 1.0);\n"                      \
    "}\n"

#define ALPHAMASK_GEN \
    "\n"                                                                   \
    "/* Gradient value for point (x,y) in a radial sector\n"               \
    "   between lines l & m from sector 's' */ \n"                         \
    "\n"                                                                   \
    "/* Gradient value for point v=(x,y,1)\n"                              \
    "   in a radial sector between lines l & m */ \n"                      \
    "float sector_gradient(int s, vec3 v)\n"                               \
    "{\n"                                                                  \
    "    vec3 l = vec3(ll[s][0], ll[s][1], ll[s][2]);\n"                   \
    "    vec3 m = vec3(mm[s][0], mm[s][1], mm[s][2]);\n"                   \
    "\n"                                                                   \
    "    float dl = -dot(v, l);\n"                                         \
    "    float dm = -dot(v, m);\n"                                         \
    "\n"                                                                   \
    "    return ((dl < 0.0) ?\n"                                           \
    "           0.0 :\n"                                                   \
    "           1.0 - (dm) / ((dl) + (dm)));\n "                           \
    "}\n"                                                                  \
    "/* Calculate combined mask for all four blending zones */\n"          \
    "float mask_gradient(vec2 p)\n"                                        \
    "{\n"                                                                  \
    "    vec3 v =  vec3(xy.x, -xy.y, 1.0) * ndc2world;\n"                  \
    "\n"                                                                   \
    "    float g01 = max(sector_gradient(0, v), sector_gradient(1, v));\n" \
    "    float g23 = max(sector_gradient(2, v), sector_gradient(3, v));\n" \
    "\n"                                                                   \
    "    float m0 = (v.y < 0.0) ? 0.0 : g01;\n "                           \
    "    float m1 = (v.y > 0.0) ? 0.0 : g23;\n "                           \
    "\n"                                                                   \
    "    return max(m0, m1);\n"                                            \
   "}\n"

/**> Fragment shader construction */
#define __SH_FRAGMENT(format)                                                  \
    "#extension GL_OES_EGL_image_external : enable\n"                          \
    SH_SETPREC                                                                 \
    "varying vec2 xy;\n"                                                       \
    "varying vec2 uv;\n"                                                       \
    "varying vec2 q;\n"                                                        \
    "uniform vec3 CC[3];\n"                                                    \
    "uniform float intensity;\n"                                               \
    "uniform sampler2D mask;\n"                                                \
    "/* Interpolation between 1.0 and inverted generated alphamask */\n"       \
    "uniform float factor;\n"                                                  \
    "/* Interpolation between old and new alpha mask (global 'switch') */\n"   \
    "uniform float q_factor\n;"                                                \
    SH_YUV2RGB                                                                 \
    __SHF_FETCH_##format                                                       \
    "void main (void)\n"                                                       \
    "{\n"                                                                      \
    "   // Fetch source texture and apply color correction\n"                  \
    "   vec3 rgb = (fetch(uv) * CC[2] + mix(CC[1], CC[0], q.y)) * intensity;\n"\
    "   float q_alpha = q.x; // old interpolated value from VBO attribute \n"  \
    "   // Interpolate between zero and mask texture\n"                        \
    "   // When factor = 0, no mask is applied\n"                              \
    "   float mask_alpha =\n"                                                  \
    "             mix(1.0,\n"                                                  \
    "                 1.0 - texture2D(mask, 0.5 * xy + vec2(0.5)).r,\n"        \
    "                 factor);\n"                                              \
    "   // Interpolate between 'new' (texture-based) and 'old' (q.x) masks\n"  \
    "   float alpha = mix(mask_alpha, q_alpha, q_factor); \n"                  \
    "   gl_FragColor = vec4(rgb, alpha);\n"                                    \
    "   // Optional debug output of mask:\n"                                   \
    "   //gl_FragColor = vec4(vec3(alpha), 1.0);\n"                            \
    "}\n"

/**> Custom shaders */

#define __SH_VERTEX_MASK                                                       \
    "#version 310 es\n"                                                        \
    SH_SETPREC                                                                 \
    "in vec2 XYMask;\n"                                                 \
    "out vec2 xy;\n"                                                       \
    "void main(void)\n"                                                        \
    "{\n"                                                                      \
    "   xy = vec2(XYMask.x, -XYMask.y);\n"                                     \
    "   gl_Position = vec4(XYMask.x, -XYMask.y, 0.0, 1.0);\n"                  \
    "}\n"

#define __SH_FRAGMENT_MASK                                                    \
    "#version 310 es\n"                                                       \
    SH_SETPREC                                                                \
    "in vec2 xy;\n"                                                           \
    "uniform mat4 ll;\n"                                                      \
    "uniform mat4 mm;\n"                                                      \
    "uniform mat3 ndc2world;\n"                                               \
    "out " SH_OUT_FMT " color;\n"                                             \
    ALPHAMASK_GEN                                                             \
    "void main (void)\n"                                                      \
    "{\n"                                                                     \
    "   float alpha = mask_gradient(xy);\n"                                   \
    "   color = " SH_OUT_FMT "(alpha * " SH_OUT_SC ");\n"                     \
    "}\n"

#define __SH_VERTEX_TEX                                                       \
    SH_SETPREC                                                                \
    "attribute vec2 XY;\n"                                                    \
    "varying vec2 xy;\n"                                                      \
    "void main(void)\n"                                                       \
    "{\n"                                                                     \
    "   xy = vec2(XY.x, XY.y);\n"                                             \
    "   gl_Position = vec4(XY.x, XY.y, 0.0, 1.0);\n"                          \
    "}\n"

#define __SH_FRAGMENT_TEX                                                     \
    SH_SETPREC                                                                \
    "varying vec2 xy;\n"                                                      \
    "uniform sampler2D tex;\n"                                                \
    "void main (void)\n"                                                      \
    "{\n"                                                                     \
    "   //gl_FragColor = vec4(0.5 * xy + vec2(0.5), 0.0,1.0);\n"              \
    "   gl_FragColor = vec4(texture2D(tex, 0.5 * xy + vec2(0.5)).rgb, 1.0);\n"\
    "}\n"

/*******************************************************************************
 * Dynamic shaders construction
 ******************************************************************************/

/**> Generic shader attributes */
#define __SHADER_ATTRIBUTES     \
    __A(XY), __A(UV), __A(Q)

/**> Generic shader uniforms */
#define __SHADER_UNIFORMS       \
    __U(depth), __U(tex), __U(mask), __U(q_factor), __U(factor), __U(CC), __U(intensity)

/**> Shader attributes ordinals */
#define __A(id)                 __MESH_VBO_SHADER_ATTRIBUTE_##id
enum __mesh_vbo_shader_attributes {
    __SHADER_ATTRIBUTES,
    __SHADER_ATTRIBUTES_NUM
};
#undef  __A

/**> Shader uniforms ordinals */
#define __U(id)                 __MESH_VBO_SHADER_UNIFORM_##id
enum __mesh_vbo_shader_uniforms {
    __SHADER_UNIFORMS,
    __SHADER_UNIFORMS_NUM
};
#undef  __U

/**> Shader attributes literals */
#define __A(id)                 #id
static const char * const __mesh_vbo_shader_attributes_id[__SHADER_ATTRIBUTES_NUM + 1] = {
    __SHADER_ATTRIBUTES,
    NULL
};
#undef  __A

/**> Shader uniforms literals */
#define __U(id)                 #id
static const char * const __mesh_vbo_shader_uniforms_id[__SHADER_UNIFORMS_NUM + 1] = {
    __SHADER_UNIFORMS,
    NULL
};
#undef  __U

/*******************************************************************************
 * Shader compilation
 ******************************************************************************/

static const char *mask_vertex_shader = __SH_VERTEX_MASK;

static const char *mask_fragment_shader = __SH_FRAGMENT_MASK;

/* ...specify shader name */
#define SHADER_TAG                  MASK
#define SHADER_VERTEX_SOURCE        mask_vertex_shader
#define SHADER_FRAGMENT_SOURCE      mask_fragment_shader

/* ...define list of attributes */
#define SHADER_ATTRIBUTES                               \
    __A(XYMask),

/* ...define list of uniforms */
#define SHADER_UNIFORMS                         \
    __U(ll), __U(mm), __U(ndc2world),

/* ...build shader lists */
#include "../src/shader-impl.h"

/**
 * @brief   Compile shader for alphamask calculation
 *
 * @return                  Shader pointer
 */
static shader_data_t * gl_mask_shader_compile(void)
{
    const shader_desc_t    *desc = &SHADER_DESC(MASK);
    shader_data_t          *shader;
    return shader_create(desc);
}

static const char *TEX_vertex_shader = __SH_VERTEX_TEX;

static const char *TEX_fragment_shader = __SH_FRAGMENT_TEX;

/* ...specify shader name */
#define SHADER_TAG                 TEX
#define SHADER_VERTEX_SOURCE       TEX_vertex_shader
#define SHADER_FRAGMENT_SOURCE     TEX_fragment_shader

/* ...define list of attributes */
#define SHADER_ATTRIBUTES                               \
    __A(XY),

/* ...define list of uniforms */
#define SHADER_UNIFORMS                         \
    __U(tex),

/* ...build shader lists */
#include "../src/shader-impl.h"

/**
 * @brief   Compile shader for debug texture output
 *
 * @return                  Shader pointer
 */
static shader_data_t * gl_tex_shader_compile(void)
{
    const shader_desc_t    *desc = &SHADER_DESC(TEX);
    shader_data_t          *shader;
    return shader_create(desc);
}


/**> Supported shader formats */
enum mesh_shader_type {
    MESH_SHADER_EXT,
    MESH_SHADER_RGB,
    MESH_SHADER_BGR,
    MESH_SHADER_I420,
    MESH_SHADER_NULL,
    MESH_SHADER_NUMBER
};

/**
 * @brief   Compile shader for given source texture format
 *
 * @param   type[in]        Shader type
 *
 * @return                  Shader pointer
 */
static shader_data_t * mesh_vbo_shader_compile(int type)
{
    shader_data_t  *shader;
    shader_desc_t   desc;
    const char *    v_src;
    char *          v_strings[1] = { NULL };
    char *          f_strings[1] = { NULL };

    /* ...reset descriptor */
    memset(&desc, 0, sizeof(desc));

    /* ...prepare vertex shader program */
    v_strings[0] = __SH_VERTEX;

    switch (type)
    {
    case MESH_SHADER_RGB:
        f_strings[0] = __SH_FRAGMENT(RGB);
        break;
    case MESH_SHADER_BGR:
        f_strings[0] = __SH_FRAGMENT(BGR);
        break;
    case MESH_SHADER_I420:
        f_strings[0] = __SH_FRAGMENT(I420);
        break;
    case MESH_SHADER_NULL:
        f_strings[0] = __SH_FRAGMENT(FILL0);
        break;
    default:
        f_strings[0] = __SH_FRAGMENT(EXT);
    }

    /* ...dump programs created */
    TRACE(DEBUG, _b("type=%d:\n\nVertex shader:\n%s\nFragment shader:\n%s"), type, v_strings[0], f_strings[0]);

    /* ...fill in shader descriptor parameters */
    desc.v_src = (const char * const *)v_strings;
    desc.f_src = (const char * const *)f_strings;

    desc.attr = __mesh_vbo_shader_attributes_id;
    desc.attr_num = __SHADER_ATTRIBUTES_NUM;
    desc.uni = __mesh_vbo_shader_uniforms_id;
    desc.uni_num = __SHADER_UNIFORMS_NUM;

    /* ...compile shader */
    return shader_create(&desc);
}

/**
 * @brief   Return shader for alphamask calculation
 *
 * @return                  Shader pointer, or NULL in case of error
 */
static shader_data_t * mask_get_shader(void)
{
    static shader_data_t * __shader;

    if (__shader == NULL)
    {
        /* ...shader not found; create new one */
        CHK_ERR(__shader = gl_mask_shader_compile(), NULL);

        TRACE(INIT, _b("MASK shader created: %u"), shader_program(__shader));
    }

    return __shader;
}

/**
 * @brief   Return shader for debug texture output
 *
 * @return                  Shader pointer, or NULL in case of error
 */
static shader_data_t * tex_get_shader(void)
{
    static shader_data_t * __shader;

    if (__shader == NULL)
    {
        /* ...shader not found; create new one */
        CHK_ERR(__shader = gl_tex_shader_compile(), NULL);

        TRACE(INIT, _b("TEX shader created: %u"), shader_program(__shader));
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
static shader_data_t * mesh_get_shader(texture_data_t *texture)
{
    static shader_data_t * __shaders[MESH_SHADER_NUMBER];

    int         idx;

    /* ...select shader index */
    if (texture == NULL)
    {
        idx = MESH_SHADER_NULL;
    }
    else if (texture->image != NULL)
    {
        idx = MESH_SHADER_EXT;
    }
    else if (texture->format == GST_VIDEO_FORMAT_RGBA || texture->format == GST_VIDEO_FORMAT_RGB)
    {
        idx = MESH_SHADER_RGB;
    }
    else if (texture->format == GST_VIDEO_FORMAT_BGRA)
    {
        idx = MESH_SHADER_BGR;
    }
    else if (texture->format == GST_VIDEO_FORMAT_I420)
    {
        idx = MESH_SHADER_I420;
    }
    else
    {
        TRACE(ERROR, _x("unknown texture format: %d"), texture->format);
        idx = MESH_SHADER_EXT;
    }

    shader_data_t  *shader = __shaders[idx];

    if (shader == NULL)
    {
        /* ...shader not found; create new one */
        CHK_ERR(shader = mesh_vbo_shader_compile(idx), NULL);

        /* ...cache new shader */
        __shaders[idx] = shader;

        TRACE(INIT, _b("shader %d created: %u"), idx, shader_program(shader));
    }

    return shader;
}

/*******************************************************************************
 * Rendering functions
 ******************************************************************************/

#define U(id)       u[UNIFORM(MASK, id)]
#define A(id)       ATTRIBUTE(MASK, id)

/**
 * @brief   Render alphamask for TopView
 *
 */
static void mesh_render_mask(mesh_alphamask_cfg_t *mask)
{
    shader_data_t  *shader = mask_get_shader();

    if (shader == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %s"),strerror(errno));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    glUseProgram(shader_program(shader));

    /* ...upload both wedge matrices at once */
    glUniformMatrix4fv(U(ll), 1, GL_FALSE, (GLfloat *)mask->l);
    glUniformMatrix4fv(U(mm), 1, GL_FALSE, (GLfloat *)mask->m);
    glUniformMatrix3fv(U(ndc2world), 1, GL_FALSE, (GLfloat *)mask->U);

    /* ...full-screen quad vertices */
    float v[12] =
    {
        -1.f, +1.f,
        -1.f, -1.f,
        +1.f, -1.f,

        -1.f, +1.f,
        +1.f, -1.f,
        +1.f, +1.f
    };
    glBindBuffer(GL_ARRAY_BUFFER, 0);    GLCHECK();

    /* ...enable attributes vector */
    glEnableVertexAttribArray(A(XYMask));           GLCHECK();
    glVertexAttribPointer(A(XYMask), 2, GL_FLOAT, GL_FALSE, 0, v);   GLCHECK();

    glDrawArrays(GL_TRIANGLES, 0, 6);   GLCHECK();

    glUseProgram(0);
}

#undef U
#undef A
/**
 * @brief   Render VBO mesh
 *
 * @param   vbo[in]         VBO data
 * @param   texture[in]     Camera texture
 * @param   cc[in]          Color-correction coefficients
 * @param   intensity[in]   Global scene intensity level
 * @param   mask_tex        alphamask texture
 * @param   factor          0.0 - old rendering, 1.0 - new 'masked' rendering
 */

#define U(id)       u[__MESH_VBO_SHADER_UNIFORM_##id]
#define A(id)       (__MESH_VBO_SHADER_ATTRIBUTE_##id)

static void mesh_vbo_render(vbo_data_t *vbo,
                            texture_data_t *texture,
                            const float32_t cc[3][3], float32_t intensity,
                            float32_t depth,
                            GLuint mask_tex,
                            float factor,
                            float q_factor)
{
    const size_t    XY_off = 0;
    const size_t    UV_off = XY_off + 2 * sizeof(GLfloat);
    const size_t    W_off = UV_off + 2 * sizeof(GLfloat);
    const size_t    vbo_size = sizeof(mesh_vertex_t);
    shader_data_t  *shader;

    /* ...bail out if shader is not found */
    if ((shader = mesh_get_shader(texture)) == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %m"));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    /* ...set rendering program */
    glUseProgram(shader_program(shader));   GLCHECK();

    glUniform1f(U(depth), depth);   GLCHECK();

    /* ...set color-correction parameters */
    glUniform3fv(U(CC), 3, *cc);            GLCHECK();

    /* ...set global scene intensity level */
    glUniform1f(U(intensity), intensity);   GLCHECK();

    /* ...set mask usage 'flag' - when 0.0, alpha is set to const 1.0 */
    glUniform1f(U(factor), factor);         GLCHECK();

    /* ...set region (top or bottom) for mask generation */
    glUniform1f(U(q_factor), q_factor);     GLCHECK();

    if (texture)
    {
        glUniform1iv(U(tex), (texture->image ? 1 : 4), (GLint [4]){ 0, 1, 2, 3 });     GLCHECK();
        /* ...bind textures (up to 4) */
        if (texture->image)
        {
            /* ...assign the only external image */
            glActiveTexture(GL_TEXTURE0);
            GLCHECK();
            glBindTexture(GL_TEXTURE_EXTERNAL_OES,
                          texture->tex[0]);
            GLCHECK();
        }
        else
        {
            /* ...assign auxiliary textures */
            glActiveTexture(GL_TEXTURE0);                       GLCHECK();
            glBindTexture(GL_TEXTURE_2D, texture->tex[0]);      GLCHECK();
            glActiveTexture(GL_TEXTURE1);                       GLCHECK();
            glBindTexture(GL_TEXTURE_2D, texture->tex[1]);      GLCHECK();
            glActiveTexture(GL_TEXTURE2);                       GLCHECK();
            glBindTexture(GL_TEXTURE_2D, texture->tex[2]);      GLCHECK();
            glActiveTexture(GL_TEXTURE3);                       GLCHECK();
            glBindTexture(GL_TEXTURE_2D, texture->tex[3]);      GLCHECK();
        }
    }

    glUniform1i(U(mask), 1);     GLCHECK();

    if (mask_tex)
    {
        glActiveTexture(GL_TEXTURE1);        GLCHECK();
        glBindTexture(GL_TEXTURE_2D, mask_tex);   GLCHECK();
    }

    /* ...bind VBO buffer */
    glBindBuffer(GL_ARRAY_BUFFER, vbo_get_id(vbo));    GLCHECK();

    /* ...enable attributes vector */
    glEnableVertexAttribArray(A(XY));           GLCHECK();
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)XY_off);   GLCHECK();

    glEnableVertexAttribArray(A(UV));           GLCHECK();
    glVertexAttribPointer(A(UV), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)UV_off);   GLCHECK();

    glEnableVertexAttribArray(A(Q));            GLCHECK();
    glVertexAttribPointer(A(Q), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)W_off);     GLCHECK();

    /* ...draw all triangles */
    glDrawArrays(GL_TRIANGLES, 0, vbo_get_num(vbo));   GLCHECK();

    TRACE(DEBUG, _b("VBO-%d: render %d triangles, intensity: %f"), vbo_get_id(vbo), vbo_get_num(vbo) / 3, intensity);

    /* ...reset rendering program */
    glUseProgram(0);
}

/**
 * @brief   Render raw texture
 *
 * @param   texture[in]     Texture data
 * @param   src[in]         Source tile (normalized)
 * @param   dst[in]         Destination tile (normalized)
 * @param   intensity[in]   Global scene intensity level
 */
static void mesh_tex_render(texture_data_t *texture, float32_t *src, float32_t *dst, float32_t intensity)
{
    shader_data_t  *shader;

    /* ...bail out if shader is not found */
    if ((shader = mesh_get_shader(texture)) == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %m"));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    float32_t   x0 = 2.0f * dst[0] - 1.0f;
    float32_t   y0 = 2.0f * dst[1] - 1.0f;
    float32_t   x1 = 2.0f * dst[2] - 1.0f;
    float32_t   y1 = 2.0f * dst[3] - 1.0f;

    /* ...vertices coordinates */
    GLfloat    verts[6 * 2] = {
        x0,  y0,
        x1,  y0,
        x0,  y1,
        x0,  y1,
        x1,  y0,
        x1,  y1,
    };

    float32_t   X0 = src[0];
    float32_t   Y0 = src[1];
    float32_t   X1 = src[2];
    float32_t   Y1 = src[3];

    /* ...triangle coordinates */
    GLfloat    texcoords[6 * 2] = {
        X0, Y0,
        X1, Y0,
        X0, Y1,
        X0, Y1,
        X1, Y0,
        X1, Y1,
    };

    /* ...fake weights coordinates */
    static const GLfloat    weights[6 * 2] = {
        [0 ... 11] = 1.0f,
    };

    /* ...fake color-correction coordinates */
    static const GLfloat    cc[3][3] = {
        [0 ... 1] = {},
        [2] = {1.0f, 1.0f, 1.0f},
    };

    /* ...set shader program */
    glUseProgram(shader_program(shader));

    /* ...bind texture uniforms (up to 4) */
    glUniform1iv(U(tex), (texture->image ? 1 : 4), (GLint [4]){ 0, 1, 2, 3 });     GLCHECK();

    /* ...set color-correction parameters */
    glUniform3fv(U(CC), 3, cc[0]);     GLCHECK();

    /* ...set global scene intensity level */
    glUniform1f(U(intensity), intensity);   GLCHECK();

    glUniform1f(U(factor), 0.0f);   GLCHECK();

    /* ...bind textures (up to 4) */
    if (texture->image)
    {
        /* ...assign the only external image */
        glActiveTexture(GL_TEXTURE0);   GLCHECK();
        glBindTexture(GL_TEXTURE_EXTERNAL_OES, texture->tex[0]);    GLCHECK();
    }
    else
    {
        /* ...assign auxiliary textures */
        glActiveTexture(GL_TEXTURE0);                       GLCHECK();
        glBindTexture(GL_TEXTURE_2D, texture->tex[0]);      GLCHECK();
        glActiveTexture(GL_TEXTURE1);                       GLCHECK();
        glBindTexture(GL_TEXTURE_2D, texture->tex[1]);      GLCHECK();
        glActiveTexture(GL_TEXTURE2);                       GLCHECK();
        glBindTexture(GL_TEXTURE_2D, texture->tex[2]);      GLCHECK();
        glActiveTexture(GL_TEXTURE3);                       GLCHECK();
        glBindTexture(GL_TEXTURE_2D, texture->tex[3]);      GLCHECK();
    }

    /* ...make sure no array binding is set */
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    /* ...set vertices array attribute ("position") */
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, 0, verts);
    glEnableVertexAttribArray(A(XY));

    /* ...set vertex coordinates attribute ("texcoord") */
    glVertexAttribPointer(A(UV), 2, GL_FLOAT, GL_FALSE, 0, texcoords);
    glEnableVertexAttribArray(A(UV));

    /* ...set weights coordinates attribute ("texcoord") */
    glVertexAttribPointer(A(Q), 2, GL_FLOAT, GL_FALSE, 0, weights);
    glEnableVertexAttribArray(A(Q));

    /* ...render triangles on the surface */
    glDrawArrays(GL_TRIANGLES, 0, 6);   GLCHECK();

    TRACE(DEBUG, _b("render texture; intensity: %f"), intensity);

    /* ...reset current program */
    glUseProgram(0);
}

#undef  U
#undef  A

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Upload mesh vertices into pending VBO bank, and make it current
 *
 * @param   mesh[in]        Mesh descriptor
 * @param   vbo[in]         Array of mesh VBO objects
 * @param   number[in]      Number of mesh VBO objects
 *
 * @return                  Negative on failure
 */
int mesh_update(mesh_data_t *mesh, mesh_vbo_t *vbo, uint32_t number)
{
    uint32_t        k;

    /* ...fill all mesh items */
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        uint32_t        num = mesh_vbo_num(&vbo[k]);
        mesh_vertex_t  *v = mesh_vbo_buffer(&vbo[k]);
        mesh_item_t    *item = &mesh->item[k];

        /* ...create VBO object as required */
        if (item->vbo == NULL)
        {
            if ((item->vbo = vbo_create(sizeof(mesh_vertex_t), num, v)) == NULL)
            {
                TRACE(ERROR, _x("failed to create VBO[num=%u]: %m"), num);
                return -1;
            }
        }
        else
        {
            if (vbo_upload(item->vbo, v, num) < 0)
            {
                TRACE(ERROR, _x("failed to upload VBO[num=%u]: %m"), num);
                return -1;
            }
        }

        /* ...save camera id - use camera id as index? - tbd */
        item->id = vbo[k].id;

        if (vbo[k].dst != NULL)
        {
            /* ...save destination tile for a VBO */
            memcpy(item->dst, vbo[k].dst, sizeof(item->dst));
        }
    }

    TRACE(DEBUG, _b("mesh uploaded"));

    return 0;
}

/**
 * @brief   Render generic mesh
 *
 * @param   mesh[in]            Generic mesh descriptor
 * @param   tex[in]             Array of camera textures
 * @param   ctx[in]             Rendering context
 * @param   intensity[in]       Global scene intensity level
 * @param   CC[in]              Color-correction coefficients pointer
 */
void mesh_render(mesh_data_t *mesh, texture_data_t **tex, render_context_t *ctx, float32_t intensity, float32_t (*CC)[3][3])
{
    int     k;

    glEnable(GL_SCISSOR_TEST);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glDepthMask(GL_TRUE);
    glDisable(GL_CULL_FACE);

    if (mesh->type == MESH_CTL)
    {
        glDisable(GL_BLEND);
    }
    else
    {
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);    GLCHECK();
        glEnable(GL_BLEND);
    }

    /* ...fake color-correction coefficients */
    const GLfloat    cc[3][3] = {
        [0 ... 1] = {0.0f, 0.0f, 0.0f},
        [2] = {1.0f, 1.0f, 1.0f},
    };

    /* ...render all prepared cameras */
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        mesh_item_t    *item = &mesh->item[k];
        int32_t        *dst = item->dst;
        uint32_t        id = item->id;
        texture_data_t *texture = tex[id];

        if (item->vbo != NULL && vbo_get_num(item->vbo) > 0 && texture != NULL)
        {
            TRACE(DEBUG, _b("mesh-item-%u: id=%u, dst=%d,%d,%d,%d"), k, id, dst[0], dst[1], dst[2], dst[3]);

            if (CC != NULL)
            {
                TRACE(DEBUG, _b("CC[%d][0]: %f,%f,%f, CC[%d][1]: %f,%f,%f, CC[%d][2]: %f,%f,%f"), id, CC[id][0][0], CC[id][0][1], CC[id][0][2], id, CC[id][1][0], CC[id][1][1], CC[id][1][2], id, CC[id][2][0], CC[id][2][1], CC[id][2][2]);
            }

            /* ...prepare crop-region using current parameters (use GL window coordinates) */
            render_context_set_view(ctx, dst);

            /* ...render individual camera VBO using old mask (q_factor = 0) */
            mesh_vbo_render(item->vbo,
                            texture,
                            (CC ? CC[id] : cc),
                            intensity,
                            mesh->type == MESH_CTL ? -0.5f : 0.f,
                            0, 0.f, 1.f);
        }
    }

    glDisable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);
}

/**
 * @brief   Render tv mesh
 *
 * @param   mesh[in]            tv mesh descriptor
 * @param   tex[in]             Array of camera textures
 * @param   ctx[in]             Rendering context
 * @param   intensity[in]       Global scene intensity level
 * @param   CC[in]              Color-correction coefficients pointer
 */

typedef struct { float x, y; } quad_vertex_t;

void mesh_tv_create_mask(mesh_data_t *mesh, mesh_alphamask_cfg_t* alpha_mask_cfg)
{
    const int fbo_w = 512;
    const int fbo_h = 1024;

    /// lazy init, first run only
    if (mesh->mask_tex == 0 || mesh->mask_fbo == 0)
    {
        /* temporary frame buffer */
        mesh->mask_fbo = fbo_create_ext(fbo_w, fbo_h, 0, 0);
        mesh->mask_tex = calloc(1, sizeof(texture_data_t));

        {
            glGenTextures(1, &mesh->mask_tex->tex[0]);
            glBindTexture(GL_TEXTURE_2D, mesh->mask_tex->tex[0]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, fbo_w, fbo_h, 0, GL_RED, GL_UNSIGNED_BYTE, NULL);
            glBindTexture(GL_TEXTURE_2D, 0);    GLCHECK();
        }

        fbo_get(mesh->mask_fbo);
        fbo_attach_texture(mesh->mask_fbo, mesh->mask_tex, 0, 0);
        fbo_put(mesh->mask_fbo);
    }

    /// re-remder on each request
    if (mesh->mask_tex != 0 && mesh->mask_fbo != 0)
    {
        fbo_get(mesh->mask_fbo);

        glDisable(GL_CULL_FACE);
        glDisable(GL_BLEND);
        glDepthMask(GL_FALSE);
        glViewport(0, 0, fbo_w, fbo_h);
        mesh_render_mask(alpha_mask_cfg);

        fbo_put(mesh->mask_fbo);
    }
    else
    {
        TRACE(ERROR, _x("failed to create mesh mask texture or FBO"));
    }
}

void mesh_render_tv(mesh_data_t *mesh, texture_data_t **tex, render_context_t *ctx, float32_t intensity, float32_t (*CC)[3][3])
{
    int     k;

    glEnable(GL_SCISSOR_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);    GLCHECK();
    glDisable(GL_CULL_FACE);
    glDisable(GL_BLEND);
    glDepthMask(GL_FALSE);

    /* ...fake color-correction coefficients */
    const GLfloat    cc[3][3] = {
        [0 ... 1] = {0.0f, 0.0f, 0.0f},
        [2] = {1.0f, 1.0f, 1.0f},
    };

    /* ...render all prepared cameras */
    for (k = 0; k < SV_CAMERAS_NUMBER; k+=2)
    {
        mesh_item_t    *item = &mesh->item[k];
        int32_t        *dst = item->dst;
        uint32_t        id = item->id;
        texture_data_t *texture = tex[id];

        if (item->vbo != NULL && vbo_get_num(item->vbo) > 0)
        {
            TRACE(DEBUG, _b("mesh-item-%u: id=%u, dst=%d,%d,%d,%d"), k, id, dst[0], dst[1], dst[2], dst[3]);

            if (CC != NULL)
            {
                TRACE(DEBUG, _b("CC[%d][0]: %f,%f,%f, CC[%d][1]: %f,%f,%f, CC[%d][2]: %f,%f,%f"), id, CC[id][0][0], CC[id][0][1], CC[id][0][2], id, CC[id][1][0], CC[id][1][1], CC[id][1][2], id, CC[id][2][0], CC[id][2][1], CC[id][2][2]);
            }

            /* ...prepare crop-region using current parameters (use GL window coordinates) */
            render_context_set_view(ctx, dst);

            /* ...render individual camera VBO -> mask texture is used */
            mesh_vbo_render(item->vbo, texture, (CC ? CC[id] : cc), intensity, 0, 0, 0.f, 1.f);
        }
    }

    glEnable(GL_BLEND);


    /* ...render all prepared cameras */
    for (k = 1; k < SV_CAMERAS_NUMBER; k+=2)
    {
        mesh_item_t    *item = &mesh->item[k];
        int32_t        *dst = item->dst;
        uint32_t        id = item->id;
        texture_data_t *texture = tex[id];

        if (item->vbo != NULL && vbo_get_num(item->vbo) > 0)
        {
            TRACE(DEBUG, _b("mesh-item-%u: id=%u, dst=%d,%d,%d,%d"), k, id, dst[0], dst[1], dst[2], dst[3]);

            if (CC != NULL)
            {
                TRACE(DEBUG, _b("CC[%d][0]: %f,%f,%f, CC[%d][1]: %f,%f,%f, CC[%d][2]: %f,%f,%f"), id, CC[id][0][0], CC[id][0][1], CC[id][0][2], id, CC[id][1][0], CC[id][1][1], CC[id][1][2], id, CC[id][2][0], CC[id][2][1], CC[id][2][2]);
            }

            /* ...prepare crop-region using current parameters (use GL window coordinates) */
            render_context_set_view(ctx, dst);

            /* ...render individual camera VBO -> do not use mask texture */
            mesh_vbo_render(item->vbo, texture, (CC ? CC[id] : cc), intensity, 0.f, (mesh->mask_tex) ? mesh->mask_tex->tex[0] : 0, 1.f, 0.f);
        }
    }
}

/**
 * @brief   Render  mesh into frame-buffer
 *
 * @param   mesh[in]            Generic mesh descriptor
 * @param   tex[in]             Array of camera textures
 * @param   ctx[in]             Rendering context
 * @param   intensity[in]       Global scene intensity level
 * @param   CC[in]              Color-correction coefficients pointer
 */
void mesh_render_fb(mesh_data_t *mesh, texture_data_t *tex, int k, float32_t (*CC)[3][3])
{
    /* ...fake color-correction coefficients */
    const GLfloat    cc[3][3] = {
        [0 ... 1] = {0.0f, 0.0f, 0.0f},
        [2] = {1.0f, 1.0f, 1.0f},
    };

    mesh_item_t    *item = &mesh->item[k];
    int32_t        *dst = item->dst;
    uint32_t        id = item->id;

    if (item->vbo != NULL && vbo_get_num(item->vbo) > 0 && tex != NULL)
    {
        TRACE(0, _b("mesh-item-%u (id=%u): dst=%d,%d,%d,%d"), k, id, dst[0], dst[1], dst[2], dst[3]);

        /* ...render individual camera VBO */
        mesh_vbo_render(item->vbo, tex, (CC ? CC[id] : cc), 1.0f, 0.f, 0, 0.f, 1.f);
    }
}

/**
 * @brief   Render raw texture
 *
 * @param   texture[in]         Camera texture
 * @param   cfg[in]             Raw mesh configuration
 * @param   ctx[in]             Rendering context
 * @param   intensity[in]       Global scene intensity level
 */
void mesh_render_raw(texture_data_t *texture, cfg_raw_mesh_t *cfg, render_context_t *ctx, float32_t intensity)
{
    if (texture != NULL)
    {
        /* ...full-screen rendering */
        render_context_set_view(ctx, NULL);

        /* ...disable blending */
        glDisable(GL_BLEND);
        glDisable(GL_CULL_FACE);

        float32_t           dst[4] = {
            (float32_t)cfg->base.dst[0] / (float32_t)ctx->width,
            (float32_t)cfg->base.dst[1] / (float32_t)ctx->height,
            (float32_t)cfg->base.dst[2] / (float32_t)ctx->width,
            (float32_t)cfg->base.dst[3] / (float32_t)ctx->height,
        };

        GLfloat     src[4];
        if (!cfg->crop || !memcmp(cfg->crop, (int32_t[4]){ 0 }, sizeof(int32_t[4])))
        {
            src[0] = src[1] = 0.0f, src[2] = src[3] = 1.0f;
        }
        else
        {
            src[0] = (GLfloat)cfg->crop[0] / (GLfloat)texture->w;
            src[1] = (GLfloat)cfg->crop[1] / (GLfloat)texture->h;
            src[2] = (GLfloat)cfg->crop[2] / (GLfloat)texture->w;
            src[3] = (GLfloat)cfg->crop[3] / (GLfloat)texture->h;
        }

        /* ...render texture */
        mesh_tex_render(texture, src, dst, intensity);
    }
}

/**
 * @brief   Render raw-mcv view
 *
 * @param   texture[in]         Camera texture
 * @param   cfg[in]             Raw-MCV mesh configuration
 * @param   ctx[in]             Rendering context
 * @param   intensity[in]       Global scene intensity level
 */
void mesh_render_raw_mcv(texture_data_t **texture, cfg_raw_mcv_mesh_t *cfg, render_context_t *ctx, float32_t intensity)
{
    int32_t     width = cfg->base.dst[2] - cfg->base.dst[0];
    int32_t     height = cfg->base.dst[3] - cfg->base.dst[1];
    int         k;

    render_context_set_view(ctx, cfg->base.dst);

    /* ...disable blending */
    glDisable(GL_BLEND);
    glDisable(GL_CULL_FACE);

    for (k = 0; k < cfg->number; k++)
    {
        cfg_raw_mesh_t     *raw = &cfg->raw[k];
        texture_data_t     *tex = texture[raw->id];

        /* ...skip missing camera */
        if (tex == NULL)    continue;

        float32_t           dst[4] = {
            (float32_t)raw->base.dst[0] / (float32_t)width,
            (float32_t)raw->base.dst[1] / (float32_t)height,
            (float32_t)raw->base.dst[2] / (float32_t)width,
            (float32_t)raw->base.dst[3] / (float32_t)height,
        };

        float32_t           src[4];
        if (!raw->crop || !memcmp(raw->crop, (int32_t[4]){0}, sizeof(int32_t[4])))
        {
            src[0] = src[1] = 0.0f, src[2] = src[3] = 1.0f;
        }
        else
        {
            src[0] = (float32_t)raw->crop[0] / (float32_t)tex->w;
            src[1] = (float32_t)raw->crop[1] / (float32_t)tex->h;
            src[2] = (float32_t)raw->crop[2] / (float32_t)tex->w;
            src[3] = (float32_t)raw->crop[3] / (float32_t)tex->h;
        }

        mesh_tex_render(tex, src, dst, intensity);
    }
}
