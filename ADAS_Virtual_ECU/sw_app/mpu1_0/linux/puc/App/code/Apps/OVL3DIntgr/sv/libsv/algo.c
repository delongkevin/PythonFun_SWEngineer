/*******************************************************************************
 * algo.c
 *
 * Algo-view generator
 *
 * Copyright (c) 2022 Cogent Embedded Inc.
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

#define MODULE_TAG                      ALGO

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "mesh-render.h"
#include "mesh-gen.h"
#include "algo.h"
#include <search.h>
#include "../../../TAD2Intgr/TAD2/TAD2Defines.h"
#include "ProxiParameters.h"
/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Local types definitions
 ******************************************************************************/

typedef struct algo_view
{
    /**> View identifier (must be first) */
    const char         *id;

    /**> View type */
    uint32_t            type;

    /**> Mesh data */
    mesh_data_t         mesh;

    /**> Frame-buffer object */
    fbo_data_t         *fbo;

    /**> Pointer to mesh configuration */
    cfg_mesh_t         *cfg;

    /**> Invalidate flag */
    int                 invalidate;

    vbo_data_t         *copy_mesh;

}   algo_view_t;

/*******************************************************************************
 * Global variables
 ******************************************************************************/

/**> Map of created algo-view */
static void     *__algo_views;

/*******************************************************************************
 * Vertex shader construction
 ******************************************************************************/

/**> Vertex shader construction */
static const char * vbo_vertex_shader =
    "#version 310 es\n"
    SH_SETPREC
    "in vec2 XY;\n"
    "in vec2 UV;\n"
    "out vec2 uv;\n"
    "void main(void)\n"
    "{\n"
    "   uv = UV;\n"
    "   gl_Position = vec4(XY.x, XY.y, 0.0, 1.0);\n"
    "}\n";

static const char * vbo_vertex_blend_shader =
    "#version 310 es\n"
    SH_SETPREC
    "in vec2 XY;\n"
    "in vec2 UV;\n"
    "in vec2 Q;\n"
    "out vec2 uv;\n"
    "out vec2 q;\n"
    "out vec2 pos;\n"
    "void main(void)\n"
    "{\n"
    "   uv = UV;\n"
    "   q = Q;\n"
    "   pos.x = 0.5*(XY.x + 1.0);\n"
    "   pos.y = 0.5*(XY.y + 1.0);\n"
    "   gl_Position = vec4(XY.x, XY.y, 0.0, 1.0);\n"
    "}\n";

/**> Fragment shader construction */
static const char * y_fragment_shader =
    "#version 310 es\n"
    "#extension GL_OES_EGL_image_external : enable\n"
    SH_SETPREC
    "in vec2 uv;\n"
    "out uint color;\n"
    "uniform samplerExternalOES tex;\n"
    "void main (void)\n"
    "{\n"
    "   vec3    rgb = texture2D(tex, uv).rgb;\n"
    "   color = uint(dot(rgb.rgb, vec3(0.2126, 0.7152, 0.0722)) * 255.0);\n"
    "}\n";

static const char * y_fragment_blend_shader =
    "#version 310 es\n"
    "#extension GL_OES_EGL_image_external : enable\n"
    SH_SETPREC
    "in vec2 uv;\n"
    "in vec2 q;\n"
    "in vec2 pos;\n"
    "out uint color;\n"
    "uniform samplerExternalOES tex;\n"
    "uniform sampler2D tex_out;\n"
    "void main (void)\n"
    "{\n"
    "   vec3    rgb = texture2D(tex, uv).rgb;\n"
    "   float    out_pix = texture(tex_out, pos).x;\n"
    "   float gray = dot(rgb.rgb, vec3(0.2126, 0.7152, 0.0722));\n"
    "   float gray_out = out_pix;\n"
    "   gray = mix(gray_out, gray, q.x);\n"
    "   color = uint(gray * 255.0);\n"
    "}\n";

/**> Fragment shader construction */
static const char * rgb_fragment_shader =
    "#version 310 es\n"
    "#extension GL_OES_EGL_image_external : enable\n"
    SH_SETPREC
    "in vec2 uv;\n"
    "layout(location = 0) out uint color_r;\n"
    "layout(location = 1) out uint color_g;\n"
    "layout(location = 2) out uint color_b;\n"
    "uniform samplerExternalOES tex;\n"
    "void main (void)\n"
    "{\n"
    "   vec3   rgb = texture2D(tex, uv).rgb * 255.0;\n"
    "   color_r = uint(rgb.r);\n"
    "   color_g = uint(rgb.g);\n"
    "   color_b = uint(rgb.b);\n"
    "}\n";

/**> Fragment shader construction */
static const char * rgb_fragment_blend_shader =
    "#version 310 es\n"
    "#extension GL_OES_EGL_image_external : enable\n"
    SH_SETPREC
    "in vec2 uv;\n"
    "in vec2 q;\n"
    "in vec2 pos;\n"
    "layout(location = 0) out uint color_r;\n"
    "layout(location = 1) out uint color_g;\n"
    "layout(location = 2) out uint color_b;\n"
    "uniform samplerExternalOES tex;\n"
    "uniform sampler2D tex_out0;\n"
    "uniform sampler2D tex_out1;\n"
    "uniform sampler2D tex_out2;\n"
    "void main (void)\n"
    "{\n"
    "   vec3   rgb = texture2D(tex, uv).rgb;\n"
    "   float  out_pix0 = texture(tex_out0, pos).x;\n"
    "   float  out_pix1 = texture(tex_out1, pos).x;\n"
    "   float  out_pix2 = texture(tex_out2, pos).x;\n"
    "   rgb = mix(vec3(out_pix0, out_pix1, out_pix2), rgb, q.x);\n"
    "   color_r = uint(rgb.r * 255.0);\n"
    "   color_g = uint(rgb.g * 255.0);\n"
    "   color_b = uint(rgb.b * 255.0);\n"
    "}\n";

/* ...specify shader name */
#define SHADER_TAG                  ALGO
#define SHADER_VERTEX_SOURCE        vbo_vertex_shader
#define SHADER_FRAGMENT_SOURCE      y_fragment_shader

/**> Generic shader attributes */
#define SHADER_ATTRIBUTES     \
    __A(XY), __A(UV),

/**> Generic shader uniforms */
#define SHADER_UNIFORMS       \
    __U(tex),

/* ...build shader lists */
#include "../src/shader-impl.h"

#define SHADER_TAG                  ALGO_BLEND
#define SHADER_VERTEX_SOURCE        vbo_vertex_blend_shader
#define SHADER_FRAGMENT_SOURCE      y_fragment_blend_shader

/**> Generic shader attributes */
#define SHADER_ATTRIBUTES     \
    __A(XY), __A(UV), __A(Q),

/**> Generic shader uniforms */
#define SHADER_UNIFORMS       \
    __U(tex), __U(tex_out),

/* ...build shader lists */
#include "../src/shader-impl.h"

/* ...specify shader name */
#define SHADER_TAG                  ALGO_RGB
#define SHADER_VERTEX_SOURCE        vbo_vertex_shader
#define SHADER_FRAGMENT_SOURCE      rgb_fragment_shader

/**> Generic shader attributes */
#define SHADER_ATTRIBUTES     \
    __A(XY), __A(UV),

/**> Generic shader uniforms */
#define SHADER_UNIFORMS       \
    __U(tex),

/* ...build shader lists */
#include "../src/shader-impl.h"


/* ...specify shader name */
#define SHADER_TAG                  ALGO_BLEND_RGB
#define SHADER_VERTEX_SOURCE        vbo_vertex_blend_shader
#define SHADER_FRAGMENT_SOURCE      rgb_fragment_blend_shader

/**> Generic shader attributes */
#define SHADER_ATTRIBUTES     \
    __A(XY), __A(UV), __A(Q),

/**> Generic shader uniforms */
#define SHADER_UNIFORMS       \
    __U(tex), __U(tex_out0), __U(tex_out1), __U(tex_out2),

/* ...build shader lists */
#include "../src/shader-impl.h"

/*******************************************************************************
 * Rendering functions
 ******************************************************************************/

/**
 * @brief   Compile shader for algo-views rendering
 *
 * @return                  Shader pointer
 */
static shader_data_t * algo_shader_compile(int rgb)
{
    const shader_desc_t    *desc = NULL;
    if (rgb == 0)
    {
        /* ...set texture unit for RGB shader */
        desc = &SHADER_DESC(ALGO);
    }

    if (rgb == 1)
    {
        /* ...set texture unit for RGB shader */
        desc = &SHADER_DESC(ALGO_RGB);
    }

    if (rgb == 2)
    {
        /* ...set texture unit for RGB shader */
        desc = &SHADER_DESC(ALGO_BLEND);
    }

    if (rgb == 3)
    {
        /* ...set texture unit for RGB shader */
        desc = &SHADER_DESC(ALGO_BLEND_RGB);
    }

    if (desc == NULL)
    {
        TRACE(ERROR, _b("invalid shader type"));
        return NULL;
    }

    shader_data_t          *shader;

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
static shader_data_t * algo_get_shader(int rgb)
{
    static shader_data_t * __shader[4];

    if (__shader[rgb] == NULL)
    {
        /* ...shader not found; create new one */
        CHK_ERR(__shader[rgb] = algo_shader_compile(rgb), NULL);

        TRACE(INIT, _b("shader created: %u"), shader_program(__shader[rgb]));
    }

    return __shader[rgb];
}


typedef struct
{
    GLfloat x;
    GLfloat y;
    GLfloat u;
    GLfloat v;
} xyuv_point_t;


static inline void fill_quad_ver(float32_t x0, float32_t x1, float32_t y0, float32_t y1, float32_t w, float32_t h,  xyuv_point_t *verts)
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

static inline void fill_quad_tex(float32_t x0, float32_t x1, float32_t y0, float32_t y1, float32_t w, float32_t h,  xyuv_point_t *verts)
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
}

void init_copy_mesh(vbo_data_t** dst, uint32_t img_w, uint32_t img_h, uint32_t out_w, uint32_t out_h)
{
    /// 6 points in 2 triangles
    /// 4 quads, 1 quad for each camera type
    xyuv_point_t data[6*4] = {0};

    xyuv_point_t* data_out = data;
    uint32_t stride = 6;

    uint32_t i;

    float32_t s_x0 = img_w - 2;
    float32_t s_x1 = img_w;
    float32_t s_y0 = 0;
    float32_t s_y1 = 1;

    float32_t d_x0 = out_w / 2 - 4;
    float32_t d_x1 = out_w / 2 - 2;
    float32_t d_y0 = out_h / 2 - 1;
    float32_t d_y1 = out_h / 2;

    for (i = 0; i < 4; i++)
    {
        fill_quad_ver(d_x0 + i*2, d_x1 + i*2, d_y0, d_y1, out_w, out_h, data_out);
        fill_quad_tex(s_x0, s_x1, s_y0, s_y1, img_w, img_h, data_out);

        data_out+=stride;
    }

    if (dst[0])
    {
        vbo_destroy(dst[0]);
    }

    dst[0] = vbo_create(6 * sizeof(xyuv_point_t), 4, data);
}


#define U(id)       u[UNIFORM(ALGO_BLEND, id)]
#define A(id)       ATTRIBUTE(ALGO_BLEND, id)
static void algo_vbo_render_blend(vbo_data_t *vbo, texture_data_t *texture, texture_data_t** tex_prev)
{
    const size_t    XY_off = 0;
    const size_t    UV_off = XY_off + 2 * sizeof(GLfloat);
    const size_t    W_off = UV_off + 2 * sizeof(GLfloat);
    const size_t    vbo_size = sizeof(mesh_vertex_t);
    shader_data_t  *shader;

    /* ...bail out if shader is not found */
    if ((shader = algo_get_shader(2)) == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %m"));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    /* ...set rendering program */
    glUseProgram(shader_program(shader));     GLCHECK();

    /* ...bind texture uniforms (up to 4) */
    glUniform1i(U(tex), 0);     GLCHECK();

    /* ...bind texture */
    glActiveTexture(GL_TEXTURE0);   GLCHECK();
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, texture->tex[0]);    GLCHECK();

    glUniform1i(U(tex_out), 1);     GLCHECK();
    /* ...bind texture */
    glActiveTexture(GL_TEXTURE1);   GLCHECK();
    glBindTexture(GL_TEXTURE_2D, tex_prev[0]->tex[0]);    GLCHECK();

    /* ...bind VBO buffer */
    glBindBuffer(GL_ARRAY_BUFFER, vbo_get_id(vbo));    GLCHECK();

    /* ...enable attributes vector */
    glEnableVertexAttribArray(A(XY));           GLCHECK();
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)XY_off);   GLCHECK();

    glEnableVertexAttribArray(A(UV));           GLCHECK();
    glVertexAttribPointer(A(UV), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)UV_off);   GLCHECK();

    glEnableVertexAttribArray(A(Q));           GLCHECK();
    glVertexAttribPointer(A(Q), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)W_off);   GLCHECK();

    /* ...draw all triangles */
    glDrawArrays(GL_TRIANGLES, 0, vbo_get_num(vbo));   GLCHECK();

    TRACE(DEBUG, _b("VBO-%d: render %d triangles"), vbo_get_id(vbo), vbo_get_num(vbo) / 3);

    /* ...reset rendering program */
    glUseProgram(0);
}

#undef  U
#undef  A


#define U(id)       u[UNIFORM(ALGO_BLEND_RGB, id)]
#define A(id)       ATTRIBUTE(ALGO_BLEND_RGB, id)
static void algo_vbo_render_blend_rgb(vbo_data_t *vbo, texture_data_t *texture, texture_data_t** tex_prev)
{
    const size_t    XY_off = 0;
    const size_t    UV_off = XY_off + 2 * sizeof(GLfloat);
    const size_t    W_off = UV_off + 2 * sizeof(GLfloat);
    const size_t    vbo_size = sizeof(mesh_vertex_t);
    shader_data_t  *shader;

    /* ...bail out if shader is not found */
    if ((shader = algo_get_shader(3)) == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %m"));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    /* ...set rendering program */
    glUseProgram(shader_program(shader));     GLCHECK();

    /* ...bind texture uniforms (up to 4) */
    glUniform1i(U(tex), 0);     GLCHECK();

    /* ...bind texture */
    glActiveTexture(GL_TEXTURE0);   GLCHECK();
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, texture->tex[0]);    GLCHECK();

    glUniform1i(U(tex_out0), 1);     GLCHECK();
    /* ...bind texture */
    glActiveTexture(GL_TEXTURE1);   GLCHECK();
    glBindTexture(GL_TEXTURE_2D, tex_prev[0]->tex[0]);    GLCHECK();

    glUniform1i(U(tex_out1), 2);     GLCHECK();
    /* ...bind texture */
    glActiveTexture(GL_TEXTURE2);   GLCHECK();
    glBindTexture(GL_TEXTURE_2D, tex_prev[1]->tex[0]);    GLCHECK();

    glUniform1i(U(tex_out2), 3);     GLCHECK();
    /* ...bind texture */
    glActiveTexture(GL_TEXTURE3);   GLCHECK();
    glBindTexture(GL_TEXTURE_2D, tex_prev[2]->tex[0]);    GLCHECK();
    /* ...bind VBO buffer */
    glBindBuffer(GL_ARRAY_BUFFER, vbo_get_id(vbo));    GLCHECK();

    /* ...enable attributes vector */
    glEnableVertexAttribArray(A(XY));           GLCHECK();
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)XY_off);   GLCHECK();

    glEnableVertexAttribArray(A(UV));           GLCHECK();
    glVertexAttribPointer(A(UV), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)UV_off);   GLCHECK();

    glEnableVertexAttribArray(A(Q));           GLCHECK();
    glVertexAttribPointer(A(Q), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)W_off);   GLCHECK();

    /* ...draw all triangles */
    glDrawArrays(GL_TRIANGLES, 0, vbo_get_num(vbo));   GLCHECK();

    TRACE(DEBUG, _b("VBO-%d: render %d triangles"), vbo_get_id(vbo), vbo_get_num(vbo) / 3);

    /* ...reset rendering program */
    glUseProgram(0);
}

#undef  U
#undef  A

/**
 * @brief   Render VBO mesh
 *
 * @param   vbo[in]         VBO data
 * @param   texture[in]     Camera texture
 * @param   cc[in]          Color-correction coefficients
 * @param   intensity[in]   Global scene intensity level
 */

#define U(id)       u[UNIFORM(ALGO, id)]
#define A(id)       ATTRIBUTE(ALGO, id)

static void algo_vbo_render(vbo_data_t *vbo, texture_data_t *texture, int rgb)
{
    const size_t    XY_off = 0;
    const size_t    UV_off = XY_off + 2 * sizeof(GLfloat);
    const size_t    W_off = UV_off + 2 * sizeof(GLfloat);
    const size_t    vbo_size = sizeof(mesh_vertex_t);
    shader_data_t  *shader;

    /* ...bail out if shader is not found */
    if ((shader = algo_get_shader(rgb)) == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %m"));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    /* ...set rendering program */
    glUseProgram(shader_program(shader));

    /* ...bind texture uniforms (up to 4) */
    glUniform1i(U(tex), 0);     GLCHECK();

    /* ...bind texture */
    glActiveTexture(GL_TEXTURE0);   GLCHECK();
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, texture->tex[0]);    GLCHECK();

    /* ...bind VBO buffer */
    glBindBuffer(GL_ARRAY_BUFFER, vbo_get_id(vbo));    GLCHECK();

    /* ...enable attributes vector */
    glEnableVertexAttribArray(A(XY));           GLCHECK();
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)XY_off);   GLCHECK();

    glEnableVertexAttribArray(A(UV));           GLCHECK();
    glVertexAttribPointer(A(UV), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)UV_off);   GLCHECK();

    /* ...draw all triangles */
    glDrawArrays(GL_TRIANGLES, 0, vbo_get_num(vbo));   GLCHECK();

    TRACE(DEBUG, _b("VBO-%d: render %d triangles"), vbo_get_id(vbo), vbo_get_num(vbo) / 3);

    /* ...reset rendering program */
    glUseProgram(0);
}



#define U(id)       u[UNIFORM(ALGO, id)]
#define A(id)       ATTRIBUTE(ALGO, id)

static void algo_copy_ctlval(algo_view_t *view, texture_data_t *texture, int rgb, uint32_t camera_indx)
{
    const size_t    XY_off = 0;
    const size_t    UV_off = 2 * sizeof(GLfloat);
    const size_t    vbo_size = sizeof(xyuv_point_t);
    shader_data_t  *shader;

    vbo_data_t *vbo = view->copy_mesh;

    /* ...bail out if shader is not found */
    if ((shader = algo_get_shader(rgb)) == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %s"),strerror(errno));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    /* ...set rendering program */
    glUseProgram(shader_program(shader));

    /* ...bind texture uniforms (up to 4) */
    glUniform1i(U(tex), 0);     GLCHECK();

    /* ...bind texture */
    glActiveTexture(GL_TEXTURE0);   GLCHECK();
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, texture->tex[0]);    GLCHECK();

    /* ...bind VBO buffer */
    glBindBuffer(GL_ARRAY_BUFFER, vbo_get_id(vbo));    GLCHECK();

    /* ...enable attributes vector */
    glEnableVertexAttribArray(A(XY));           GLCHECK();
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)XY_off);   GLCHECK();

    glEnableVertexAttribArray(A(UV));           GLCHECK();
    glVertexAttribPointer(A(UV), 2, GL_FLOAT, GL_FALSE, vbo_size, (void *)(uintptr_t)UV_off);   GLCHECK();

    /* ...draw all triangles */
    glDrawArrays(GL_TRIANGLES, 6*camera_indx, 6);   GLCHECK();

    /* ...reset rendering program */
    glUseProgram(0);
}


/**
 * @brief   Render raw texture
 *
 * @param   texture[in]     Texture data
 * @param   src[in]         Source tile
 * @param   dst[in]         Destination tile
 * @param   intensity[in]   Global scene intensity level
 */
static void algo_tex_render(texture_data_t *texture, float32_t *src, float32_t *dst, int rgb)
{
    shader_data_t  *shader;

    /* ...bail out if shader is not found */
    if ((shader = algo_get_shader(rgb)) == NULL)
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

    TRACE(DEBUG, _b("dst: %f,%f,%f,%f, src:%f,%f,%f,%f"), x0, y0, x1, y1, X0, Y0, X1, Y1);

    /* ...set shader program */
    glUseProgram(shader_program(shader));

    /* ...bind texture uniforms (up to 4) */
    glUniform1i(U(tex), 0);     GLCHECK();

    /* ...bind texture */
    glActiveTexture(GL_TEXTURE0);   GLCHECK();
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, texture->tex[0]);    GLCHECK();

    /* ...make sure no array binding is set */
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    /* ...set vertices array attribute ("position") */
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, 0, verts);
    glEnableVertexAttribArray(A(XY));

    /* ...set vertex coordinates attribute ("texcoord") */
    glVertexAttribPointer(A(UV), 2, GL_FLOAT, GL_FALSE, 0, texcoords);
    glEnableVertexAttribArray(A(UV));

    /* ...render triangles on the surface */
    glDrawArrays(GL_TRIANGLES, 0, 6);   GLCHECK();

    TRACE(DEBUG, _b("render texture"));

    /* ...reset current program */
    glUseProgram(0);
}

#undef  U
#undef  A

/**
 * @brief   Render raw mesh
 */
static void algo_view_render_raw(algo_view_t *view, texture_data_t **texture, int width, int height, int rgb)
{
    cfg_raw_mcv_mesh_t *raw_mc = &view->cfg->raw_mc;
    int                 k;

    for (k = 0; k < raw_mc->number; k++)
    {
        cfg_raw_mesh_t     *raw = &raw_mc->raw[k];
        texture_data_t     *tex = texture[raw->id];

        TRACE(DEBUG, _b("raw-mc: %d (id=%d), tex: %u, W*H=%d*%d"), k, raw->id, (tex ? tex->tex[0] : 0), width, height);

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

        /* ...raw mesh rendering */
        algo_tex_render(tex, src, dst, rgb);
    }
}

/**
 * @brief   Render VBO mesh
 */
static void algo_view_render_vbo(algo_view_t *view, texture_data_t **texture, texture_data_t **out, int rgb)
{
    int     k;

    uint32_t err = 0;

    if (view->copy_mesh == NULL)
    {
        for(int i = 0; i < 4; i++)
        {
            if(texture[i] != NULL)
            {
                init_copy_mesh(&view->copy_mesh, texture[i]->w, texture[i]->h, out[0]->w, out[0]->h);
                break;
            }
        }
    }

    if (fbo_attach_texture(view->fbo, out[0], 0, 0) != 0)
    {
        err = 1;
        TRACE(ERROR, _x("failed to attach internal texture"));
        return;
    }

    if (rgb && (err == 0))
    {
        err =  fbo_attach_texture(view->fbo, out[1], 0, 1) | fbo_attach_texture(view->fbo, out[2], 0, 2);
    }


    if (err == 0)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);   GLCHECK();
        glClear(GL_COLOR_BUFFER_BIT);           GLCHECK();

        for (k = 0; k < 3; k+=2)
        {
            mesh_item_t    *item = &view->mesh.item[k];
            int32_t        *dst = item->dst;
            uint32_t        id = item->id;
            texture_data_t *tex = texture[id];

            if (item->vbo != NULL && vbo_get_num(item->vbo) > 0 && tex != NULL)
            {
                algo_vbo_render(item->vbo, tex, rgb);
                algo_copy_ctlval(view, tex, rgb, k);

                TRACE(DEBUG, _b("render vbo-%d (id=%u)"), k, id);
            }
        }

        for (k = 1; k < 4; k+=2)
        {
            mesh_item_t    *item = &view->mesh.item[k];
            int32_t        *dst = item->dst;
            uint32_t        id = item->id;
            texture_data_t *tex = texture[id];

            if (item->vbo != NULL && vbo_get_num(item->vbo) > 0 && tex != NULL)
            {
                if (rgb)
                    algo_vbo_render_blend_rgb(item->vbo, tex, out);
                else
                    algo_vbo_render_blend(item->vbo, tex, out);

                algo_copy_ctlval(view, tex, rgb, k);

                TRACE(DEBUG, _b("render vbo-%d (id=%u)"), k, id);
            }
        }
    }
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Render screen layout and process all transitions
 *
 * @param   vm[in]          View manager handle
 * @param   texture[in]     Array of camera textures
 * @param   output[in]      Output textures array
 * @param   sync[in]        Synchronization object pointer
 *
 * @return                  Negative on failure
 */
int algo_view_render(algo_view_t *view, texture_data_t **texture, texture_data_t **output, sync_data_t **sync)
{
    render_context_t    ctx;
    int                 r = 0;
    int                 width, height;
    int                 k;

    fbo_get(view->fbo);

    glDisable(GL_DEPTH_TEST);
	glDisable(GL_SCISSOR_TEST);
    glDisable(GL_BLEND);
    glDisable(GL_CULL_FACE);

    width = output[0]->w;
    height = output[0]->h;

    glViewport(0, 0, width, height);    GLCHECK();
    glDrawBuffers(3, (GLenum[3]){GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2});    GLCHECK();

    if (view->type == ALGO_VIEW_GRAYSCALE_RAW)
    {
        if (fbo_attach_texture(view->fbo, output[0], 0, 0) == 0)
        {
            algo_view_render_raw(view, texture, width, height, 0);
        }
        else
        {
            TRACE(ERROR, _x("failed to attach texture: %s"), strerror(errno));
            r = -1;
        }
    }
    else if (view->type == ALGO_VIEW_RGB_PLANAR_RAW)
    {
        if (fbo_attach_texture(view->fbo, output[0], 0, 0) == 0 &&
            fbo_attach_texture(view->fbo, output[1], 0, 1) == 0 &&
            fbo_attach_texture(view->fbo, output[2], 0, 2) == 0)
        {
            algo_view_render_raw(view, texture, width, height, 1);
        }
        else
        {
            TRACE(ERROR, _x("failed to attach texture: %s"), strerror(errno));
            r = -1;
        }
    }
    else if (view->type == ALGO_VIEW_RGB_PLANAR)
    {
        algo_view_render_vbo(view, texture, output, 1);
    }
    else if (view->type == ALGO_VIEW_GRAYSCALE)
    {
        algo_view_render_vbo(view, texture, output, 0);
    }
    else
    {
        TRACE(ERROR, _x("invalid algo-view type: %d"), view->type);
        r = -1;
    }

    if (r >= 0)
    {
        /* ...trigger rendering */
        if (sync != NULL)
        {
            *sync = sync_create();
        }
        else
        {
            glFinish();
        }
    }

    fbo_put(view->fbo);

    return r;
}

/**
 * @brief   Update algo-view mesh
 *
 * @param   view[in]        Algo-view handle
 * @param   gen[in]         Mesh-generator data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle data
 *
 * @return                  Negative on failure
 */
int algo_view_update_cfg(algo_view_t *view, mesh_gen_t *gen, cfg_data_t *cfg, vehicle_state_t *vehicle)
{
    if (view->invalidate)
    {
        view->invalidate = 0;

        switch (view->cfg->base.type)
        {
        case MESH_SCV:
        {
            recalculate_position(&view->cfg->scv, cfg);
            return mesh_generate_scv(gen, cfg, &view->cfg->scv, vehicle, &view->mesh);
        }

        case MESH_TV:
        {
            calculate_shadow_from_vehicle(cfg, &view->cfg->tv);
            return mesh_generate_tv(gen, cfg, &view->cfg->tv, &view->mesh);
        }

        case MESH_RAW:
        case MESH_RAW_MCV:
            /* ...no special mesh preparation */
            return 0;

        default:
            return TRACE(ERROR, _x("unknown mesh type: %d"), view->cfg->base.type), -(errno = EINVAL);
        }
    }

    return 0;
}

/**
 * @brief   Find mesh configuration
 *
 * @param   cfg[in]         Global configuration data
 * @param   id[in]          Algo-view identifier
 * @param   type[in]        Mesh type
 *
 * @return                  Mesh configuration, or NULL on failure
 */
static cfg_mesh_t * algo_view_find_config(cfg_data_t *cfg, const char *id, int type)
{
    int         i;

    /* ...search for mesh configuration */
    for (i = 0; i < cfg->ui.pages_num; i++)
    {
        cfg_ui_page_t  *page = &cfg->ui.pages[i];

        if (!strcmp(page->id, id))
        {
            /* ...get TV-configuration */
            if (page->views_num != 1 || (type >= 0 && page->views[0]->base.type != type))
            {
                TRACE(ERROR, _b("invalid configuration: %d vs %d"), page->views[0]->base.type, type);
            }
            else
            {
                return page->views[0];
            }
        }
    }

    return NULL;
}

/**
 * @brief   UI page comparison functor
 *
 * @param   a[in]       First parameter
 * @param   b[in]       Second parameter
 *
 * @return              Comparison result
 */
static int algo_str_cmp(const void *a, const void *b)
{
    const char  * const * A = a, * const *B = b;

    return strcmp(*A, *B);
}

/**
 * @brief   Create algo-view
 *
 * @param   cfg[in]     Global configuration data
 * @param   id[in]      View identifier
 * @param   type[in]    Mesh type
 *
 * @return              Algo-view handle, or NULL on failure
 */
static algo_view_t * algo_view_alloc(cfg_data_t *cfg, const char *id, int type)
{
    algo_view_t     *view, **val;
    cfg_mesh_t      *mesh;

    /* ...find mesh configuration */
    if ((mesh = algo_view_find_config(cfg, id, type)) == NULL)
    {
        TRACE(ERROR, _b("no mesh configuration found for %s"), id);
        return (errno = ENOENT, NULL);
    }

    /* ...allocate algo-view handle */
    CHK_ERR(view = calloc(1, sizeof(*view)), NULL);
    view->id = id;
    view->cfg = mesh;
    view->invalidate = 1;

    /* ...put record into a map */
    CHK_ERR(val = tsearch(view, &__algo_views, algo_str_cmp), NULL);
    if (*val != view)
    {
        /* ...view duplication */
        TRACE(ERROR, _b("algo-view '%s' duplication"), id);
        free(view);
        return (errno = EINVAL, NULL);
    }

    TRACE(INIT, _b("algo-view '%s' created"), id);

    return view;
}

/**
 * @brief   Find algo-view handle
 *
 * @param   id[in]          View identifier
 *
 * @return                  View handle, or NULL if not found
 */
static algo_view_t * algo_view_find(const char *id)
{
    algo_view_t   **val;

    if ((val = tfind(&id, &__algo_views, algo_str_cmp)) == NULL)
    {
        /* ...not found; silently ignore */
        return NULL;
    }

    return *val;
}

/**
 * @brief   Destroy algo-view
 *
 * @param   cfg[in]     Global configuration data
 * @param   id[in]      View identifier
 * @param   type[in]    Mesh type
 *
 * @return              Algo-view handle, or NULL on failure
 */
void algo_view_destroy(algo_view_t *view)
{
    const char     *id = view->id;

    /* ...remove item from the map */
    tdelete(view, &__algo_views, algo_str_cmp);

    /* ...destroy all allocated resources - tbd */
    (view->fbo != NULL ? fbo_destroy(view->fbo) : 0);

    if (view->copy_mesh)
    {
        vbo_destroy(view->copy_mesh);
        view->copy_mesh = NULL;
    }

    /* ...release view handle */
    free(view);

    TRACE(INIT, _b("view '%s' destroyed"), id);
}

/**
 * @brief   Invalidate algo-view
 *
 * @param   id[in]          View identifier
 */
void algo_view_invalidate(const char *id)
{
    algo_view_t    *view;

    if ((view = algo_view_find(id)) != NULL)
    {
        view->invalidate = 1;

        TRACE(INFO, _b("algo-view '%s' invalidated"), id);
    }
}

/**
 * @brief   Invalidation callback
 */
static void algo_invalidate(const void *nodep, VISIT which, int depth)
{
    if (which == postorder || which == leaf)
    {
        algo_view_t    *view = *(algo_view_t**)nodep;

        view->invalidate = 1;

        TRACE(INFO, _b("algo-view '%s' invalidated"), view->id);
    }
}

/**
 * @brief   Invalidate all algo-views
 */
void algo_view_invalidate_all(void)
{
    twalk(__algo_views, algo_invalidate);
}

/**
 * @brief   Create algo-view mesh - fisheye frame
 *
 * @param   cfg[in]         Global configuration data
 * @param   width[in]       Output buffer width
 * @param   height[in]      Output buffer height
 *
 * @return                  Negative on failure
 */
algo_view_t *algo_fisheye_y_create(cfg_data_t *cfg, int width, int height)
{
    algo_view_t *view;

    if ((view = algo_view_alloc(cfg, "algo-fisheye-y", MESH_RAW_MCV)) == NULL)
    {
        TRACE(ERROR, _x("failed to create view: %s"), strerror(errno));
        return NULL;
    }

    /* ...create frame-buffer for out-of-screen rendering */
    if ((view->fbo = fbo_create_ext(width, height, 0, 0)) == NULL)
    {
        TRACE(ERROR, _x("failed to create fbo: %s"), strerror(errno));
        goto error;
    }

    /* ...put algo-view-id - tbd */
    view->type = ALGO_VIEW_GRAYSCALE_RAW;

    TRACE(INIT, _b("fisheye-y view created: %d*%d"), width, height);

    return view;

error:
    /* ...release view handle */
    free(view);

    return NULL;
}

/**
 * @brief   Create algo-view mesh - Rear-Top-View, Y-coordinate
 *
 * @param   cfg[in]         Global configuration data
 * @param   width[in]       Output buffer width
 * @param   height[in]      Output buffer height
 *
 * @return                  Negative on failure
 */
algo_view_t *algo_rear_tv_y_create(cfg_data_t *cfg, int width, int height)
{
    algo_view_t *view = NULL;

    uint32_t bAlgoCreateFail = 0;
	FILE* fp;
	uint8_t var_id = 8;
	ME_Proxi_MPU1_0_to_MCU1_0_t *proxi_req = NULL;
#if 0 // ToDo: Pravin Pawar
	fp = fopen("/fs/variants/VarData.version", "r");
	if (NULL == fp)
	{
		ME_Debugger_F_Printf_v("variantHelper: Read from file failed\n");
	}
	else
	{
		fread((void*)proxi_req,sizeof(proxi_req),1,fp);
		var_id = proxi_req->PRX_variantID_u8;
		fclose(fp);
	}
#endif
	switch(var_id)
    {
      case  9:
      {
        if ((view = algo_view_alloc(cfg, "mule4-algo-rear-tv-y", MESH_SCV)) == NULL)
        {
          bAlgoCreateFail = 1;
        }
        break;
      }
      case  4:
      {
        if ((view = algo_view_alloc(cfg, "mule5-algo-rear-tv-y", MESH_SCV)) == NULL)
        {
          bAlgoCreateFail = 1;
        }
        break;
      }
      case  8:
      {
        if ((view = algo_view_alloc(cfg, "mule6-algo-rear-tv-y", MESH_SCV)) == NULL)
        {
          bAlgoCreateFail = 1;
        }
        break;
      }
      default:
      {
        if ((view = algo_view_alloc(cfg, "mule6-algo-rear-tv-y", MESH_SCV)) == NULL)
        {
          bAlgoCreateFail = 1;
        }
        break;
      }
    }
    if (bAlgoCreateFail)
    {
      TRACE(ERROR, _x("failed to create view: %s"), strerror(errno));
      return NULL;
    }

    /* ...create frame-buffer for out-of-screen rendering (may be shared, I believe - tbd) */
    if ((view->fbo = fbo_create_ext(width, height, 0, 0)) == NULL)
    {
        TRACE(ERROR, _x("failed to create fbo: %s"), strerror(errno));
        goto error;
    }

    /* ...put algo-view-id */
    view->type = ALGO_VIEW_GRAYSCALE;

    TRACE(INIT, _b("rear-tv view created: %d*%d"), width, height);

    return view;

error:
    /* ...release view handle */
    algo_view_destroy(view);

    return NULL;
}

/**
 * @brief   Create algo-view mesh - planar RGB cylindrical projection
 *
 * @param   cfg[in]         Global configuration data
 * @param   width[in]       Output buffer width
 * @param   height[in]      Output buffer height
 *
 * @return                  Negative on failure
 */
algo_view_t *algo_cylindrical_rgb_create(cfg_data_t *cfg, int width, int height)
{
    algo_view_t *view;

    if ((view = algo_view_alloc(cfg, "algo-rear-cyl-rgb", MESH_SCV)) == NULL)
    {
        TRACE(ERROR, _x("failed to create view: %s"), strerror(errno));
        return NULL;
    }

    /* ...create frame-buffer for out-of-screen rendering - why do I need that always? - tbd */
    if ((view->fbo = fbo_create_ext(width, height, 0, 0)) == NULL)
    {
        TRACE(ERROR, _x("failed to create fbo: %s"), strerror(errno));
        goto error;
    }

    /* ...put algo-view-id */
    view->type = ALGO_VIEW_RGB_PLANAR;

    TRACE(INIT, _b("cylindrical-rgb view created: %d*%d"), width, height);

    return view;

error:
    /* ...release view handle */
    algo_view_destroy(view);

    return NULL;
}

/**
 * @brief   Create algo-view mesh - grayscale top-view
 *
 * @param   cfg[in]         Global configuration data
 * @param   width[in]       Output buffer width
 * @param   height[in]      Output buffer height
 *
 * @return                  Negative on failure
 */
algo_view_t *algo_tv_y_create(cfg_data_t *cfg, int width, int height)
{
    algo_view_t    *view;

    if ((view = algo_view_alloc(cfg, "algo-tv-y", MESH_TV)) == NULL)
    {
        TRACE(ERROR, _x("failed to create view: %s"), strerror(errno));
        return NULL;
    }

    /* ...create frame-buffer for out-of-screen rendering */
    if ((view->fbo = fbo_create_ext(width, height, 0, 0)) == NULL)
    {
        TRACE(ERROR, _x("failed to create fbo: %s"), strerror(errno));
        goto error;
    }

    /* ...put algo-view-id */
    view->type = ALGO_VIEW_GRAYSCALE;

    TRACE(INIT, _b("top-view-y view created: %d*%d"), width, height);

    return view;

error:
    /* ...release view handle */
    algo_view_destroy(view);

    return NULL;
}

/**
 * @brief   Create generic algo-view
 *
 * @param   cfg[in]         Global configuration data
 * @param   id[in]          View identifier
 * @param   type[in]        View type
 * @param   width[out]      Output buffer width
 * @param   height[out]     Output buffer height
 *
 * @return                  Algo-view handle
 */
algo_view_t *algo_view_create(cfg_data_t *cfg, char *id, int type, int *width, int *height)
{
    algo_view_t    *view;

    if ((view = algo_view_alloc(cfg, id, -1)) == NULL)
    {
        TRACE(ERROR, _x("failed to create view: %s"), strerror(errno));
        return NULL;
    }

    /* ...determine output buffer size */
    *width = view->cfg->base.dst[2];
    *height = view->cfg->base.dst[3];
    if (*width <= 0 || *height <= 0)
    {
        TRACE(ERROR, _x("invalid buffer size: %d * %d"), *width, *height);
        goto error;
    }

    /* ...create frame-buffer for out-of-screen rendering */
    if ((view->fbo = fbo_create_ext(*width, *height, 0, 0)) == NULL)
    {
        TRACE(ERROR, _x("failed to create fbo: %s"), strerror(errno));
        goto error;
    }

    /* ...put algo-view-type - tbd */
    view->type = type;

    TRACE(INIT, _b("algo-view '%s' created: %d*%d, type=%d"), id, *width, *height, type);

    return view;

error:
    /* ...release view handle */
    algo_view_destroy(view);

    return NULL;
}


int algo_view_get_matrix(cfg_data_t *cfg, char *id, float32_t matrix[3*3])
{
    cfg_mesh_t      *mesh;

    /* ...find mesh configuration */
    if ((mesh = algo_view_find_config(cfg, id, -1)) == NULL)
    {
        TRACE(ERROR, _b("no mesh configuration found for %s"), id);
        return ENOENT;
    }

    if (mesh->base.type != MESH_TV)
    {
        TRACE(ERROR, _b("requested matrix for %s is not a top-view"), id);
        return EINVAL;
    }

    algo_get_matix(cfg, (cfg_tv_mesh_t *)mesh, matrix);

    return 0;
}

int algo_view_set_src_roi(cfg_data_t *cfg, char *id, int32_t roi[4])
{
    cfg_mesh_t      *mesh;

    /* ...find mesh configuration */
    if ((mesh = algo_view_find_config(cfg, id, -1)) == NULL)
    {
        TRACE(ERROR, _b("no mesh configuration found for %s"), id);
        return ENOENT;
    }

    if (mesh->base.type != MESH_RAW_MCV && mesh->base.type != MESH_RAW)
    {
        return EINVAL;
    }

    if (mesh->base.type == MESH_RAW_MCV)
    {
        uint32_t N = mesh->raw_mc.number;

        uint32_t i;

        for (i = 0; i < N; i++)
        {
            memcpy(mesh->raw_mc.raw[i].crop, roi, sizeof(int32_t) * 4);
        }
    }
    else if (mesh->base.type == MESH_RAW)
    {
        memcpy(mesh->raw.crop, roi, sizeof(int32_t) * 4);
    }
    else
    {
        return EINVAL;
    }
    return 0;
}
