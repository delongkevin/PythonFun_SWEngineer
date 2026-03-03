/*******************************************************************************
 * icons.c
 *
 * Icons loader and renderer for surround view
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

#define MODULE_TAG                      ICON

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "list.h"
#include "vbo-dynarray.h"
#include "config.h"
#include "math-neon.h"
#include "icons.h"
#include "../src/util.h"
#include "../src/png-load.h"

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**
 * @brief   Icon VBO vertex
 */
typedef GLfloat     icon_vertex_t[4];

/**
 * @brief   Icon data
 */
struct icon_data
{
    /**> GL textures identifiers  */
    GLuint                 *tex;
    float32_t*              tex_scale;

    /**> Number of different textures */
    uint32_t                number;
    uint32_t                trsc_indx;
    float32_t               trsc_angle0;
    float32_t               trsc_angle1;

    /**> Resources mapping */
    icon_item_t             map[ICON_RESOURCE_MAX];
};

/**
 * @brief   Icon render object
 */
typedef struct icon_render_object
{
    /**> GL texture identifier (reference) */
    GLuint              tex;

    /**> Single quad buffer */
    icon_vertex_t       vertex[6];

}   icon_render_object_t;

/*******************************************************************************
 * Vertex shader construction
 ******************************************************************************/

/**> VBO vertex shader */
static const char *vbo_vertex_shader =
    SH_SETPREC
    "attribute vec2	XY;\n"
    "attribute vec2	UV;\n"
    "varying vec2 uv;\n"
    "uniform vec2 scale;\n"
    "void main(void)\n"
    "{\n"
    "   uv = UV;\n"
    "	gl_Position = vec4(XY.x * scale.x - 1.0, 1.0 - XY.y * scale.y, 0.0, 1.0);\n"
    "}\n";

/* ...VBO fragment shader */
static const char *vbo_fragment_shader =
    SH_SETPREC
    "varying vec2 uv;\n"
    "uniform sampler2D tex;\n"
    "uniform float  intensity;\n"
    "void main()\n"
    "{\n"
    "   gl_FragColor = texture2D(tex, uv) * intensity;\n"
    "}\n";

/* ...specify shader name */
#define SHADER_TAG                  VBO
#define SHADER_VERTEX_SOURCE        vbo_vertex_shader
#define SHADER_FRAGMENT_SOURCE      vbo_fragment_shader

/* ...define list of attributes */
#define SHADER_ATTRIBUTES                       \
    __A(XY), __A(UV),

/* ...define list of uniforms */
#define SHADER_UNIFORMS                         \
    __U(tex), __U(scale), __U(intensity),

/* ...build shader lists */
#include "../src/shader-impl.h"

/**
 * @brief   Compile shader for icons rendering
 *
 * @return                  Shader pointer
 */
static shader_data_t * icon_vbo_shader_compile(void)
{
    const shader_desc_t    *desc = &SHADER_DESC(VBO);
    shader_data_t          *shader;

    /* ...compile shader */
    return shader_create(desc);
}

/**
 * @brief   Return shader for icons rendering
 *
 * @param   type[in]        Icon type
 *
 * @return                  Shader pointer, or NULL in case of error
 */
static shader_data_t * icon_get_shader(void)
{
    static shader_data_t * __shader;

    if (__shader == NULL)
    {
        /* ...shader not found; create new one */
        CHK_ERR(__shader = icon_vbo_shader_compile(), NULL);

        TRACE(INIT, _b("shader created: %u"), shader_program(__shader));
    }

    return __shader;
}

/**
 * @brief   Render icon VBO
 *
 * @param   vbo[in]         VBO dynamic array
 * @param   tex[in]         GL texture id
 * @param   W[in]           Output window width
 * @param   H[in]           Output window height
 * @param   intensity[in]   Global scene intensity level
 */

#define U(id)       u[UNIFORM(VBO, id)]
#define A(id)       ATTRIBUTE(VBO, id)

static void icon_item_render(vbo_dynarray_t *vbo, GLuint tex, int32_t W, int32_t H, GLfloat intensity)
{
    void           *XY_off = vbo_dynarray_buffer(vbo, sizeof(icon_vertex_t));
    void           *UV_off = XY_off + 2 * sizeof(GLfloat);
    const size_t    vbo_size = sizeof(icon_vertex_t);
    shader_data_t  *shader;

    /* ...bail out if shader is not found */
    if ((shader = icon_get_shader()) == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %s"), strerror(errno));
        return;
    }

    const GLint    *u = shader_uniforms(shader);

    /* ...set rendering program */
    glUseProgram(shader_program(shader));

    /* ...set sampler */
    glUniform1i(U(tex), 0);

    /* ...bind dimensions uniform */
    glUniform2fv(U(scale), 1, (GLfloat [2]){ 2.0f / (float32_t)W, 2.0f / (float32_t)H });   GLCHECK();

    /* ...set global scene intensity level */
    glUniform1f(U(intensity), intensity);   GLCHECK();

    /* ...bind texture */
    glActiveTexture(GL_TEXTURE0);  GLCHECK();
    glBindTexture(GL_TEXTURE_2D, tex);  GLCHECK();

    /* ...make sure no VBO binding set */
    glBindBuffer(GL_ARRAY_BUFFER, 0);    GLCHECK();

    /* ...enable attributes vector */
    glEnableVertexAttribArray(A(XY));           GLCHECK();
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, vbo_size, XY_off);   GLCHECK();

    glEnableVertexAttribArray(A(UV));           GLCHECK();
    glVertexAttribPointer(A(UV), 2, GL_FLOAT, GL_FALSE, vbo_size, UV_off);   GLCHECK();

    /* ...draw all triangles */
    glDrawArrays(GL_TRIANGLES, 0, vbo_dynarray_num(vbo));   GLCHECK();

    TRACE(DEBUG, _b("VBO: render %d triangles"),vbo_dynarray_num(vbo) / 3);

    /* ...reset rendering program */
    glUseProgram(0);
}

/**
 * @brief   Render icons list
 *
 * @param   render[in]      Icons render-list
 * @param   ctx[in]         Rendering context
 * @param   dst[in]         Destination tile (crop-region)
 * @param   intensity[in]   Global scene intensity
 */
void icon_render(icon_render_t *render, render_context_t *ctx, float32_t intensity)
{
    icon_render_object_t   *v = vbo_dynarray_buffer(&render->vbo, sizeof(*v));
    int32_t                 num = vbo_dynarray_num(&render->vbo);
    int32_t                 i;
    shader_data_t          *shader;

    /* ...bail out if shader is not found */
    if ((shader = icon_get_shader()) == NULL)
    {
        TRACE(ERROR, _x("failed to get shader: %s"), strerror(errno));
        return;
    }

    /* ...specify viewport - we always use full-screen display coordinates for icons? */
    render_context_set_view(ctx, NULL);

    /* ...specify scissors */
    //render_context_set_crop(ctx, render->dst);

    const GLint        *u = shader_uniforms(shader);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);    GLCHECK();
    glDisable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);

    /* ...set rendering program */
    glUseProgram(shader_program(shader));

    /* ...set sampler */
    glUniform1i(U(tex), 0);

    /* ...bind dimensions uniform */
    glUniform2fv(U(scale), 1, (GLfloat [2]){ 2.0f / (float32_t)ctx->width, 2.0f / (float32_t)ctx->height });   GLCHECK();

    /* ...set global scene intensity level */
    glUniform1f(U(intensity), intensity);   GLCHECK();

    /* ...bind texture */
    glActiveTexture(GL_TEXTURE0);  GLCHECK();

    /* ...make sure no VBO binding set */
    glBindBuffer(GL_ARRAY_BUFFER, 0);    GLCHECK();

    /* ...enable attributes vectors */
    glEnableVertexAttribArray(A(XY));           GLCHECK();
    glEnableVertexAttribArray(A(UV));           GLCHECK();

    /* ...render all items */
    for (i = 0; i < num; i++, v++)
    {
        void           *XY_off = &v->vertex[0][0];
        void           *UV_off = &v->vertex[0][2];
        const size_t    vbo_size = sizeof(icon_vertex_t);

        /* ...set texture id / vertex attributes */
        glBindTexture(GL_TEXTURE_2D, v->tex);  GLCHECK();
        glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, vbo_size, XY_off);   GLCHECK();
        glVertexAttribPointer(A(UV), 2, GL_FLOAT, GL_FALSE, vbo_size, UV_off);   GLCHECK();

        /* ...draw single quad */
        glDrawArrays(GL_TRIANGLES, 0, 6);   GLCHECK();
    }

    TRACE(DEBUG, _b("render %u quads (intensity: %f)"), num, intensity);

    /* ...reset rendering program */
    glUseProgram(0);
}

#undef  U
#undef  A

/*******************************************************************************
 * Internal functions
 ******************************************************************************/


/**
 * @brief   Get mapping of icon item to resource identifier
 *
 * @param   icon[in]        Icons data
 * @param   id[in]          Resource identifier
 *
 * @return                  Icon item, or NULL on failure
 */
static inline icon_item_t * icon_get_item(icon_data_t *icon, uint32_t id)
{
    icon_item_t    *item;

    /* ...sanity check - resource id is valid */
    if (id < ICON_RESOURCE_MAX)
    {
        item = (icon->map[id].tex == 0 ? NULL : &icon->map[id]);
    }
    else
    {
        item = NULL;
    }

    return item;
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

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
static inline void icon_quad_encode(icon_vertex_t *v, float32x4x2_t B01, float32x4x2_t B23)
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
 * @brief   Prepare icon data for update
 *
 * @param   render[in]      Icon render list
 */
void icon_reset(icon_render_t *render)
{
    vbo_dynarray_clear(&render->vbo, sizeof(icon_render_object_t));
}

/**
 * @brief   Add icon item to rendering list
 *
 * @param   icon[in]        Icon data
 * @param   id[in]          Resource id
 * @param   dst[in]         Destination tile on display
 * @param   transform[in]   Optional transformation 2*3 matrix
 *
 * @return                  Negative on failure
 */
static inline float32x4x2_t icon_rotate_quad(float32x4x2_t P, float32_t *pivot, float32_t angle)
{
    float32x4x2_t   Q;

    /* ...load transform matrix:
     * [0]: {m00, m10}
     * [1]: {m01, m11}
     * [2]: {m02, m12}
     */
    float32_t       s = sinf(angle), c = cosf(angle);

    /* ...get rotation center */
    float32x2_t     R;

    if (pivot != NULL)
    {
        R = vld1_f32(pivot);
    }
    else
    {
        float32x2_t     t0 = vadd_f32(vget_low_f32(P.val[0]), vget_high_f32(P.val[0]));
        float32x2_t     t1 = vadd_f32(vget_low_f32(P.val[1]), vext_f32(vget_low_f32(P.val[1]), vget_low_f32(P.val[1]), 1));

        R = vmul_n_f32(vtrn1_f32(t0, t1), 0.5f);
    }

    /* ...{R.x - c*Rx, R.y - c*R.y} */
    float32x2_t     T = vmls_n_f32(R, R, c);

    /* {(R.x - c*Rx) - s*Ry, (R.y - c*R.y) - s*(-R.x) */
    T = vmls_n_f32(T, vext_f32(R, vneg_f32(R), 1), s);

    /* ...multiply points by transformation matrix */
    Q.val[0] = vmlaq_n_f32(vmlaq_n_f32(vdupq_lane_f32(T, 0), P.val[0], c), P.val[1], s);
    Q.val[1] = vmlaq_n_f32(vmlsq_n_f32(vdupq_lane_f32(T, 1), P.val[0], s), P.val[1], c);

    return Q;
}

/**
 * @brief   Add icon item to rendering list
 *
 * @param   item[in]        Icon item data
 * @param   dst[in]         Destination tile on display
 * @param   angle[in]       Rotation angle, radians
 * @param   render[in]      Icon render-list
 *
 * @return                  Negative on failure
 */
int icon_add_item_rot(icon_item_t *item, int32_t *dst, float32_t angle, float32_t *pivot, int tr, icon_render_t *render)
{
    icon_render_object_t   *v;

    float32_t src[4];
    if (item->src && item->scale_x && item->scale_y)
    {
        memcpy(src, item->src, sizeof(src));
        src[0]*= *item->scale_x;
        src[1]*= *item->scale_y;
        src[2]*= *item->scale_x;
        src[3]*= *item->scale_y;
    }

    /* ...add new quad to dynamic array */
    CHK_ERR(v = vbo_dynarray_add(&render->vbo, sizeof(*v), 1), -1);

    /* ...save texture id */
    v->tex = item->tex;

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

    if (tr != 0)
    {
        if (tr == 1)
        {
            R.val[0] = vcombine_f32(vtrn1_f32(vget_high_f32(R.val[0]), vget_low_f32(R.val[0])),
                                    vtrn2_f32(vget_high_f32(R.val[0]), vget_low_f32(R.val[0])));

            R.val[1] = vcombine_f32(vtrn1_f32(vget_high_f32(R.val[1]), vget_low_f32(R.val[1])),
                                    vtrn2_f32(vget_high_f32(R.val[1]), vget_low_f32(R.val[1])));
        }
        else if (tr == 3)
        {
            R.val[0] = vcombine_f32(vtrn2_f32(vget_high_f32(R.val[0]), vget_low_f32(R.val[0])),
                                    vtrn1_f32(vget_high_f32(R.val[0]), vget_low_f32(R.val[0])));

            R.val[1] = vcombine_f32(vtrn2_f32(vget_high_f32(R.val[1]), vget_low_f32(R.val[1])),
                                    vtrn1_f32(vget_high_f32(R.val[1]), vget_low_f32(R.val[1])));
        }
        else
        {
            R.val[0] = vcombine_f32(vext_f32(vget_high_f32(R.val[0]), vget_high_f32(R.val[0]), 1),
                                    vext_f32(vget_low_f32(R.val[0]), vget_low_f32(R.val[0]), 1));

            R.val[1] = vcombine_f32(vext_f32(vget_high_f32(R.val[1]), vget_high_f32(R.val[1]), 1),
                                    vext_f32(vget_low_f32(R.val[1]), vget_low_f32(R.val[1]), 1));
        }
    }

    /* ...rotate point around the center */
    if (angle != 0.0f)
    {
        P = icon_rotate_quad(P, pivot, angle);
    }

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
    icon_quad_encode(v->vertex, B01, B23);

    return 0;
}

typedef struct {
    uint8_t r, g, b, a;
} Pixel;

static void merge_images(void* img1,
    void* img2,
    int32_t width,
    int32_t height,
    int32_t stride1,
    int32_t stride2,
    float angle1,
    uint32_t merge_bottom)
{
    Pixel *pixelData1 = (Pixel*)img1;
    Pixel *pixelData2 = (Pixel*)img2;

    float radians = angle1 * M_PI / 180.0;
    float tan_angle = tan(radians);

    for (int32_t y = 0; y < height; y++) 
    {
        for (int32_t x = 0; x < width; x++) 
        {
            if ((x > tan_angle * y) ^ merge_bottom)
            {
                if (img2)
                {
                    Pixel* pixel2 = (Pixel*)((uint8_t*)pixelData2 + y * stride2 + x * sizeof(Pixel));
                    Pixel* pixel1 = (Pixel*)((uint8_t*)pixelData1 + y * stride1 + x * sizeof(Pixel));
                    *pixel1 = *pixel2;
                }
                else
                {
                    Pixel* pixel1 = (Pixel*)((uint8_t*)pixelData1 + y * stride1 + x * sizeof(Pixel));
                    pixel1->a = 0;
                }
            }
        }
    }
}




static int32_t trsc_upload(const char *fname, GLuint *tex, int32_t *width, int32_t *height, float32_t angles[2])
{
    int             format = 0;
    int             lod = 0;
    void           *data = NULL;

    if (load_png(fname, width, height, &format, &data) < 0)
    {
        TRACE(ERROR, _b("failed to load icon from '%s': %s"), fname, strerror(errno));
        return -1;
    }

    uint32_t img_step = 200;
    uint32_t W = 196;
    uint32_t H = 195;

    uint32_t* data_u32 = (uint32_t*)data;

    merge_images(data_u32 + 0*img_step, 0, W, H, *width * 4, *width * 4, angles[0], 1);
    merge_images(data_u32 + 1*img_step, 0, W, H, *width * 4, *width * 4, angles[0], 1);
    merge_images(data_u32 + 2*img_step, 0, W, H, *width * 4, *width * 4, angles[0], 1);
    merge_images(data_u32 + 1*img_step, data_u32 + 3*img_step, W, H, *width * 4, *width * 4, angles[1], 0);
    merge_images(data_u32 + 2*img_step, data_u32 + 4*img_step, W, H, *width * 4, *width * 4, angles[1], 0);

    if (*tex == 0)
    {
        glGenTextures(1, tex);      GLCHECK();
    }

    /* ...upload texture into GL context */
    glBindTexture(GL_TEXTURE_2D, *tex); GLCHECK();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, *width, *height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); GLCHECK();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


#if DUMP_TRSC
    char dump_fname[256];
    snprintf(dump_fname, sizeof(dump_fname), "/tmp/img_%dx%d.rgba", *width, *height);
    FILE* dump_file = fopen(dump_fname, "wb");
    fwrite(data, *width * *height * 4, 1, dump_file);
    fclose(dump_file);
#endif

    if (data)
        free(data);

    return 0;
}

static float32_t clamp_angle(float32_t angle, float32_t max_angle);


int32_t icons_trsc_load(icon_data_t* icon, cfg_data_t *cfg, float32_t angles[2])
{
    if (icon->trsc_indx == 0)
    {
        return -1;
    }

    angles[0] = clamp_angle(angles[0], 89.9f);
    angles[1] = clamp_angle(angles[1], 89.9f);

    if (icon->trsc_angle0 == angles[0] 
        && icon->trsc_angle1 == angles[1])
    {
        return 0;
    }

    uint32_t i = icon->trsc_indx - 1;

    {
        cfg_icon_t         *cfg_icon = &cfg->icons.icon[i];
        const char         *filename = cfg_icon->file;
        int                 width = 0, height = 0;

        if (trsc_upload(filename, &icon->tex[i], &width, &height, angles) != 0)
        {
            TRACE(ERROR, _x("failed to upload image '%s': %s"), filename, strerror(errno));
            return -1;
        }

        icon->trsc_angle0 = angles[0];
        icon->trsc_angle1 = angles[1];

        icon->tex_scale[i*2 + 0] = 1.0f / (float32_t)width;
        icon->tex_scale[i*2 + 1] = 1.0f / (float32_t)height;

        /* ...process all individual items contained here */
        for (uint32_t k = 0; k < cfg_icon->number; k++)
        {
            uint32_t        id = cfg_icon->item[k].id;
            icon_item_t    *item = &icon->map[id];

            /* ...save GL texture id */
            item->tex = icon->tex[i];

            /* ...transform source destination to GL-space */
            item->src = &cfg_icon->item[k].src[0];

            item->scale_x = &icon->tex_scale[i*2 + 0];
            item->scale_y = &icon->tex_scale[i*2 + 1];
        }
    }

    return 0;
}

/**
 * @brief   Load icons resources
 *
 * @param   cfg[in]     Global configuration data
 *
 * @return              Icon data handle, or NULL on failure
 */
icon_data_t * icons_load(cfg_data_t *cfg)
{
    uint32_t        number = cfg->icons.number;
    icon_data_t    *icon;
    uint32_t        i, k;

    /* ...allocate icons data structure */
    CHK_ERR(icon = calloc(1, sizeof(*icon)), NULL);
    icon->trsc_angle0 = -1.0f;
    icon->trsc_angle1 = -1.0f;

    /* ...save number of containers */
    icon->number = number;

    /* ...generate textures */
    CHK_ERR(icon->tex = calloc(number, sizeof(*icon->tex)), NULL);
    CHK_ERR(icon->tex_scale = calloc(number, 2*sizeof(*icon->tex_scale)), NULL);

    /* ...create GL-textures */
    glGenTextures(number, icon->tex);       GLCHECK();

    /* ...build resources basing on configuration */
    for (i = 0; i < number; i++)
    {
        cfg_icon_t         *cfg_icon = &cfg->icons.icon[i];
        const char         *filename = cfg_icon->file;
        int                 width = 0, height = 0;

        if (strstr(filename, "trsc"))
        {
            icon->trsc_indx = i+1;
            float angles[2] = {0.0f, 0.0f};
            icons_trsc_load(icon, cfg, angles);
            continue;
        }

        if (tex_upload(filename, &icon->tex[i], &width, &height, NULL) != 0)
        {
            TRACE(ERROR, _x("failed to upload image '%s': %s"), filename, strerror(errno));
            continue;
        }

        icon->tex_scale[i*2 + 0] = 1.0f / (float32_t)width;
        icon->tex_scale[i*2 + 1] = 1.0f / (float32_t)height;

        /* ...process all individual items contained here */
        for (k = 0; k < cfg_icon->number; k++)
        {
            uint32_t        id = cfg_icon->item[k].id;
            icon_item_t    *item = &icon->map[id];

            /* ...save GL texture id */
            item->tex = icon->tex[i];

            /* ...transform source destination to GL-space */
            item->src = &cfg_icon->item[k].src[0];

            item->scale_x = &icon->tex_scale[i*2 + 0];
            item->scale_y = &icon->tex_scale[i*2 + 1];

            //TRACE(INIT, _b("icon[%u] mapped: tex=%u, src=%f,%f,%f,%f"), id, item->tex, item->src[0], item->src[1], item->src[2], item->src[3]);

        }
    }

    return icon;
}

/*******************************************************************************
 * Auxiliary functions for icons visualization
*******************************************************************************/

/**
 * @brief   Get PAS-off status
 */
static inline int pas_state_off(pas_state_t *pas)
{
    return (pas->state == PAS_STATE_OFF || pas->state == PAS_STATE_INIT ||
            pas->state == PAS_STATE_TMP_FAILURE_REAR_TRAILER || pas->state == PAS_STATE_TMP_FAILURE ||
            pas->state == PAS_STATE_FAILURE);
}

/**
 * @brief   Select sonars icons basing on current PAS state
 *
 * @param   icon[in]        Icon data
 * @param   pas[in]         PAS state
 * @param   sonars[out]     Array of sonar icons
 * @param   type[in]        PAS indicators type
 *
 * @return                  Mask of failing sonars
 */
static uint32_t icon_pas_sonars_set(icon_data_t *icon, pas_state_t *pas, icon_item_t *sonars[6], uint32_t crit[6], uint32_t length_var)
{
    const int   id[6][2] = {
        { ICON_PAS_FC_CAUTION0 + length_var, ICON_PAS_FC_CRITICAL0 + length_var },
        { ICON_PAS_FR_CAUTION0 + length_var, ICON_PAS_FR_CRITICAL0 + length_var },
        { ICON_PAS_FL_CAUTION0 + length_var, ICON_PAS_FL_CRITICAL0 + length_var },
        { ICON_PAS_RC_CAUTION0 + length_var, ICON_PAS_RC_CRITICAL0 + length_var },
        { ICON_PAS_RR_CAUTION0 + length_var, ICON_PAS_RR_CRITICAL0 + length_var },
        { ICON_PAS_RL_CAUTION0 + length_var, ICON_PAS_RL_CRITICAL0 + length_var },
    };

    uint32_t    mask = 0;
    uint32_t    i;

    for (i = 0; i < 6U; i++)
    {
        TRACE(0, _b("sonar-%u: state=%d, sonar-state=%d/%d, area-info=%d"), i, pas->state, pas->sonar_state[2 * i], pas->sonar_state[2 * i + 1], pas->area_info[i]);

        /* ...by default show no icon */
        sonars[i] = NULL;

        /* ...fill failure mask basing on sonar status */
        if (pas->sonar_state[i] != 0U)
        {
            mask |= 1U << i;
        }
        else if (pas->state == PAS_STATE_ON || pas->state == PAS_STATE_ON_SILENT)
        {
            if (pas->area_info[i] == PAS_AREA_INFO_MIDDLE_DISTANCE)
            {
                if (1 || pas->blink_25_on)
                {
                    sonars[i] = &icon->map[id[i][0]];
                    crit[i] = 0;
                }
            }
            else if (pas->area_info[i] == PAS_AREA_INFO_CLOSE_DISTANCE)
            {
                if (1 || pas->blink_50_on)
                {
                    sonars[i] = &icon->map[id[i][1]];
                    crit[i] = 1;
                }
            }
        }
    }

    return mask;
}


/**
 * @brief   Add car model icon and PAS for sonar view
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle state data pointer
 * @param   tv[in]          Top-view model flag
 * @param   type[in]        Sonar icon type
 * @param   render[in]      Icon render-list data
 *
 * @return                  Negative on failure
 */
int icon_add_pdc(icon_data_t *icon, cfg_data_t *cfg, vehicle_state_t *vehicle, int tv, int type, icon_render_t *render)
{
    uint32_t length_var = cfg_get_body_length_variant(cfg);
    icon_item_t    *model = icon_get_item(icon, ICON_CAR_MODEL0 + length_var);
    icon_item_t    *item;
    icon_item_t    *sonars[6];
    ap_state_t* ap_state = &vehicle->ap;
    pas_state_t* pas = &vehicle->pas;
    cfg_sonar_t    *sonar = &cfg->vm.sonar_tv;


    int32_t        *dst[12] = {
            sonar->sonar_rl_pas_dst[1][length_var],
            sonar->sonar_rl_pas_dst[0][length_var],
            sonar->sonar_fr_pas_dst[1][length_var],
            sonar->sonar_fr_pas_dst[0][length_var],
            sonar->sonar_fc_pas_dst[1][length_var],
            sonar->sonar_fc_pas_dst[0][length_var],
            sonar->sonar_fl_pas_dst[1][length_var],
            sonar->sonar_fl_pas_dst[0][length_var],
            sonar->sonar_rr_pas_dst[1][length_var],
            sonar->sonar_rr_pas_dst[0][length_var],
            sonar->sonar_rc_pas_dst[1][length_var],
            sonar->sonar_rc_pas_dst[0][length_var],
            
        };

    const int   ids[12][3] = {
        {ap_state->PDC_RearLeft_Red_b, ICON_PAS_RL_CRITICAL0 + length_var, pas->blink_50_on},
        {ap_state->PDC_RearLeft_Yellow_b, ICON_PAS_RL_CAUTION0 + length_var, pas->blink_25_on},
        {ap_state->PDC_FrontRight_Red_b, ICON_PAS_FR_CRITICAL0 + length_var, pas->blink_50_on},
        {ap_state->PDC_FrontRight_Yellow_b, ICON_PAS_FR_CAUTION0 + length_var, pas->blink_25_on},
        {ap_state->PDC_FrontCenter_Red_b, ICON_PAS_FC_CRITICAL0 + length_var, pas->blink_50_on},
        {ap_state->PDC_FrontCenter_Yellow_b, ICON_PAS_FC_CAUTION0 + length_var, pas->blink_25_on},
        {ap_state->PDC_FrontLeft_Red_b, ICON_PAS_FL_CRITICAL0 + length_var, pas->blink_50_on},
        {ap_state->PDC_FrontLeft_Yellow_b, ICON_PAS_FL_CAUTION0 + length_var, pas->blink_25_on},
        {ap_state->PDC_RearRight_Red_b, ICON_PAS_RR_CRITICAL0 + length_var, pas->blink_50_on},
        {ap_state->PDC_RearRight_Yellow_b, ICON_PAS_RR_CAUTION0 + length_var, pas->blink_25_on},
        {ap_state->PDC_RearCenter_Red_b, ICON_PAS_RC_CRITICAL0 + length_var, pas->blink_50_on},
        {ap_state->PDC_RearCenter_Yellow_b, ICON_PAS_RC_CAUTION0 + length_var, pas->blink_25_on}};

    uint32_t    i;

    for (i = 0; i < 12U; i++)
    {
        if (ids[i][0])
        {
            /*COMMENTED TO DISABLED BLINKING*/
			// if (ids[i][2])
            // { 
                CHK_API(icon_add_item(&icon->map[ids[i][1]], dst[i], render));
            // }
        }
    }

    return 0;
}


/**
 * @brief   Add car model icon and PAS for sonar view
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle state data pointer
 * @param   tv[in]          Top-view model flag
 * @param   type[in]        Sonar icon type
 * @param   render[in]      Icon render-list data
 *
 * @return                  Negative on failure
 */
int icon_add_sonar(icon_data_t *icon, cfg_data_t *cfg, vehicle_state_t *vehicle, int tv, int type, icon_render_t *render)
{
    cfg_sonar_t    *sonar = &cfg->vm.sonar_tv;
    uint32_t length_var = cfg_get_body_length_variant(cfg);
    icon_item_t    *model = icon_get_item(icon, ICON_CAR_MODEL0 + length_var);
    icon_item_t    *item;
    uint32_t        i;


    /* ...add car model icon */
    if (model != NULL)
    {
        const int   id[4][2] = {
            { ICON_DOOR_FL_OPEN0 + length_var, ICON_DOOR_FL_CLOSED0 + length_var },
            { ICON_DOOR_FR_OPEN0 + length_var, ICON_DOOR_FR_CLOSED0 + length_var },
            { ICON_DOOR_RL_OPEN0 + length_var, ICON_DOOR_RL_CLOSED0 + length_var },
            { ICON_DOOR_RR_OPEN0 + length_var, ICON_DOOR_RR_CLOSED0 + length_var },
        };

        /* ...car body */
        CHK_API(icon_add_item(model, sonar->sonar_car_model_dst[length_var], render));

        /* ...car doors */
        for (i = 0U; i < 4U; i++)
        {
            if (vehicle->door_state[i])
            {
                if ((item = icon_get_item(icon, id[i][0])) != NULL)
                {
                    CHK_API(icon_add_item(item, sonar->sonar_door_open_dst[length_var][i], render));
                }
            }
            else
            {
                if ((item = icon_get_item(icon, id[i][1])) != NULL)
                {
                    CHK_API(icon_add_item(item, sonar->sonar_door_closed_dst[length_var][i], render));
                }
            }
        }

        /* ...trunk door */
        if (vehicle->door_state[4])
        {
            if ((item = icon_get_item(icon, ICON_TRUNK_OPEN0 + length_var)) != NULL)
            {
                CHK_API(icon_add_item(item, sonar->sonar_trunk_open_dst[length_var], render));
            }
        }
    }

    /* ...select sonars icons */
    if (pas_state_off(&vehicle->pas))
    {
        icon_item_t    *pas_off = icon_get_item(icon, ICON_PAS_OFF);

        if (pas_off != NULL)
        {
            CHK_API(icon_add_item(pas_off, sonar->sonar_pas_off_dst, render));
        }
    }
    else
    {
        icon_item_t    *sonars[6];
        uint32_t    crit[6] = {0};

        int32_t        *dst[12] = {
            sonar->sonar_fc_pas_dst[0][length_var],
            sonar->sonar_fr_pas_dst[0][length_var],
            sonar->sonar_fl_pas_dst[0][length_var],
            sonar->sonar_rc_pas_dst[0][length_var],
            sonar->sonar_rr_pas_dst[0][length_var],
            sonar->sonar_rl_pas_dst[0][length_var],
            sonar->sonar_fc_pas_dst[1][length_var],
            sonar->sonar_fr_pas_dst[1][length_var],
            sonar->sonar_fl_pas_dst[1][length_var],
            sonar->sonar_rc_pas_dst[1][length_var],
            sonar->sonar_rr_pas_dst[1][length_var],
            sonar->sonar_rl_pas_dst[1][length_var],
        };

        /* ...select sonars icons */
        icon_pas_sonars_set(icon, &vehicle->pas, sonars, crit, length_var);

        for (i = 0U; i < 6U; i++)
        {
            /* ...encode sonar icon */
            if (sonars[i])
            {
                CHK_API(icon_add_item(sonars[i], dst[i + 6*crit[i]], render));
            }
        }
    }

    /* ...update overlay every frame */
    return 1;
}

/**
 * @brief   Add car model icon including the wheels
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   front[in]       Front/rear-CTA processing
 * @param   vehicle[in]     Vehicle data pointer
 * @param   render[in]      Icon render list
 *
 * @return                  Negative on failure
 */
int icon_add_cta(icon_data_t *icon, cfg_data_t *cfg, int front, vehicle_state_t *vehicle, icon_render_t *render)
{
    cta_state_t    *cta = (front != 0 ? &vehicle->cta : &vehicle->rcta);
    icon_item_t    *item;

    if (cta->target_lh != 0U)
    {
        if ((item = icon_get_item(icon, ICON_CTA_LEFT)) != NULL)
        {
            CHK_API(icon_add_item(item, cfg->vm.cta_main.dst_left, render));
        }
    }

    if (cta->target_rh != 0U)
    {
        if ((item = icon_get_item(icon, ICON_CTA_RIGHT)) != NULL)
        {
            CHK_API(icon_add_item(item, cfg->vm.cta_main.dst_right, render));
        }
    }

    return 0;
}

/**
 * @brief   Add hitch distance overlay
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle data pointer
 * @param   render[in]      Icon render list
 *
 * @return                  Negative on failure
 */
int icon_add_hitch(icon_data_t *icon, cfg_data_t *cfg, vehicle_state_t *vehicle, icon_render_t *render)
{
    cfg_hitch_t    *hitch = &cfg->vm.hitch;
    uint8_t         progress = vehicle->tha_progress_bar;
    icon_item_t    *coupler, *bg;
    float32_t       share;

    /* ...bail out if overlay is disabled */
    if (vehicle->tha_progress_enable == 0U)
    {
        return 0;
    }

    progress = MIN(progress, 100);

    bg = (progress == 100) ? icon_get_item(icon, ICON_HITCH_SLIDER_LOCKED) : icon_get_item(icon, ICON_HITCH_SLIDER);
    coupler = (progress == 100 || progress == 0) ? icon_get_item(icon, ICON_HITCH_COUPLER_LOCKED) : icon_get_item(icon, ICON_HITCH_COUPLER);
    share = (float32_t)progress * 0.01f;

    if (bg != NULL)
    {
        CHK_API(icon_add_item(bg, hitch->slider, render));
    }

    if (coupler != NULL)
    {
        int32_t     dst[4] = {
            hitch->start[0] + (int32_t)(share * (float32_t)(hitch->stop[0] - hitch->start[0])),
            hitch->start[1] + (int32_t)(share * (float32_t)(hitch->stop[1] - hitch->start[1])),
            hitch->start[2] + (int32_t)(share * (float32_t)(hitch->stop[2] - hitch->start[2])),
            hitch->start[3] + (int32_t)(share * (float32_t)(hitch->stop[3] - hitch->start[3])),
        };

        CHK_API(icon_add_item(coupler, dst, render));
    }

    return 0;
}

/**
 * @brief   Add coupler target overlay
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle data pointer
 * @param   render[in]      Icon render list
 *
 * @return                  Negative on failure
 */
int icon_add_coupler(icon_data_t *icon, cfg_data_t *cfg, vehicle_state_t *vehicle, icon_render_t *render)
{
    int32_t         x0 = vehicle->tha_coupler_pos[0];
    int32_t         y0 = vehicle->tha_coupler_pos[1];
    icon_item_t    *coupler = icon_get_item(icon, ICON_COUPLER_TARGET);

    if (vehicle->tha_coupler_enable != 0 && coupler != NULL)
    {
        int32_t     w = 152;
        int32_t     h = 152;
        int32_t     dst[4] = { x0 - w / 2, y0 - h /2, x0 + w / 2, y0 + h / 2 };

        CHK_API(icon_add_item(coupler, dst, render));
    }

    return 0;
}

/**
 * @brief   Set tile with given offset in X direction
 */
static inline void tile_set_offset(int32_t *dst, int32_t *src, int32_t offset)
{
    dst[0] = src[0] + offset;
    dst[1] = src[1];
    dst[2] = src[2] + offset;
    dst[3] = src[3];
}

/**
 * @brief   Mirror tile around specific X coordinate
 */
static inline void tile_mirror(int32_t *dst, int32_t *src, int32_t x0)
{
    dst[0] = 2 * x0 - src[0];
    dst[1] = src[1];
    dst[2] = 2 * x0 - src[2];
    dst[3] = src[3];
}

static float32_t calc_angle(float32_t y, float32_t x)
{
    x = atan2f(y, x);

    if (x>= M_PI)
    {
        x -= M_PI*2;
    }
    else if (x < -M_PI)
    {
        x += M_PI*2;
    }
    return x;
}

void remove_angle(vbo_dynarray_t* vbo, float32_t tad_angle, float32_t pivot[2], int32_t mirror)
{
    tad_angle*=mirror;
    icon_render_object_t *vbo_data = (icon_render_object_t*)(vbo->v) - 1;
    GLfloat* vertices = vbo_data->vertex[0];

    icon_render_object_t orig = vbo_data[0];

    float32_t rectangle[4][2] = {0};
    rectangle[0][0] = mirror*(vbo_data->vertex[0][0] - pivot[0]);
    rectangle[0][1] = +(vbo_data->vertex[0][1] - pivot[1]);
    rectangle[1][0] = mirror*(vbo_data->vertex[1][0] - pivot[0]);
    rectangle[1][1] = +(vbo_data->vertex[1][1] - pivot[1]);
    rectangle[2][0] = mirror*(vbo_data->vertex[2][0] - pivot[0]);
    rectangle[2][1] = +(vbo_data->vertex[2][1] - pivot[1]);
    rectangle[3][0] = mirror*(vbo_data->vertex[5][0] - pivot[0]);
    rectangle[3][1] = +(vbo_data->vertex[5][1] - pivot[1]);

    for (uint32_t i = 0; i < 4; i++)
    {
        rectangle[i][1] = MAX(rectangle[i][1], 0.1);
        rectangle[i][0] = MAX(rectangle[i][0], 0.1);
    }

    float32_t angles[4] = {calc_angle(rectangle[0][0], rectangle[0][1]),
                           calc_angle(rectangle[1][0], rectangle[1][1]),
                           calc_angle(rectangle[2][0], rectangle[2][1]),
                           calc_angle(rectangle[3][0], rectangle[3][1])};

    uint32_t out_angles = 0;

    for (int32_t i = 0; i < 4; i++)
    {
        if (angles[i] >= tad_angle)
            out_angles++;
    }


    if (out_angles == 4)
    {
        vbo->v = (uint8_t*)vbo->v - sizeof(icon_render_object_t);
        vbo->avail++;
        return;
    }

    if (out_angles == 0)
        return;


    if (out_angles == 1)
    {
        float32_t x = rectangle[0][0];
        rectangle[0][1] = x / tan(tad_angle);
    }

    if (out_angles == 2)
    {
        float32_t y1 = rectangle[0][1];
        float32_t y2 = rectangle[1][1];
        rectangle[0][0] = y1 * tan(tad_angle);
        rectangle[1][0] = y2 * tan(tad_angle);
    }

    if (out_angles == 3)
    {
        float32_t y2 = rectangle[1][1];
        rectangle[1][0] = y2 * tan(tad_angle);
        rectangle[0][0] = rectangle[2][0];
        rectangle[0][1] = rectangle[2][1];
    }

    vbo_data->vertex[0][0] = pivot[0] + mirror*rectangle[0][0];
    vbo_data->vertex[0][1] = pivot[1] +rectangle[0][1];
    vbo_data->vertex[1][0] = pivot[0] + mirror*rectangle[1][0];
    vbo_data->vertex[1][1] = pivot[1] +rectangle[1][1];
    vbo_data->vertex[2][0] = pivot[0] + mirror*rectangle[2][0];
    vbo_data->vertex[2][1] = pivot[1] +rectangle[2][1];
    vbo_data->vertex[5][0] = pivot[0] + mirror*rectangle[3][0];
    vbo_data->vertex[5][1] = pivot[1] +rectangle[3][1];

    vbo_data->vertex[3][0] = vbo_data->vertex[2][0];
    vbo_data->vertex[3][1] = vbo_data->vertex[2][1];
    vbo_data->vertex[4][0] = vbo_data->vertex[1][0];
    vbo_data->vertex[4][1] = vbo_data->vertex[1][1];

    float32_t scx = (orig.vertex[0][2] - orig.vertex[5][2]) / (orig.vertex[0][0] - orig.vertex[5][0]);
    float32_t scy = (orig.vertex[0][3] - orig.vertex[5][3]) / (orig.vertex[0][1] - orig.vertex[5][1]);

    for (uint32_t i = 0; i < 6; i++)
    {
        vbo_data->vertex[i][2] = (vbo_data->vertex[i][0] - orig.vertex[i][0]) * scx + orig.vertex[i][2];
        vbo_data->vertex[i][3] = (vbo_data->vertex[i][1] - orig.vertex[i][1]) * scy + orig.vertex[i][3];
    }

    TRACE(0, _b("A %.1f %.1f | %.1f %.1f | %.1f %.1f | %.1f %.1f    %d"), rectangle[0][0],
        rectangle[0][1], rectangle[1][0], rectangle[1][1], rectangle[2][0],
        rectangle[2][1], rectangle[3][0], rectangle[3][1], out_angles);
}

static float32_t clamp_angle(float32_t angle, float32_t max_angle)
{
    if (fabsf(angle) > max_angle)
    {
        if (angle > 0)
            angle = max_angle;
        else
            angle = -max_angle;
    }

    return angle;
}

/**
 * @brief   Select icon id
 */
#define TRSC_ICON(base, name)   ((base) + (ICON_TRSC_##name##_SVC - ICON_TRSC_BASE_SVC))

/**
 * @brief   Add TRSC overlay
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   type[in]        TRSC graphics type
 * @param   vehicle[in]     Vehicle data pointer
 * @param   render[in]      Icon render list
 *
 * @return                  Negative on failure
 */
int icon_add_trsc(icon_data_t *icon, cfg_data_t *cfg, int type, vehicle_state_t *vehicle, icon_render_t *render)
{
    cfg_trsc_t     *trsc;
    icon_item_t    *item;
    int             base, bg;
    int             offset;
    int32_t         dst[4];
    float32_t       pivot[2];

    /* ...bail out if overlay rendering disabled */
    if (!vehicle->trsc_enable)
    {
        return 0;
    }

    float32_t angles[2] = {vehicle->trsc_angle0, vehicle->trsc_angle1};
    icons_trsc_load(icon, cfg, angles);

    /* ...select overlay configuration */
    switch (type)
    {
    case ICON_OVL_TRSC_SVC:
        trsc = &cfg->vm.trsc_svc;
        base = ICON_TRSC_BASE_TRG;
        offset = 0;
        break;

    case ICON_OVL_TRSC_TRG_R1:
    case ICON_OVL_TRSC_TRG_R2:
    case ICON_OVL_TRSC_TRG_L1:
    case ICON_OVL_TRSC_TRG_L2:
    case ICON_OVL_TRSC_TRG_C:
        trsc = &cfg->vm.trsc_trg;
        base = ICON_TRSC_BASE_TRG;
        offset = trsc->offset[type - ICON_OVL_TRSC_TRG_R1];
        break;

    default:
        TRACE(ERROR, _x("unknown type: %d"), type);
        return -1;
    }

    /* ...adjust pivot point */
    pivot[0] = trsc->pivot[0] + (float32_t)offset;
    pivot[1] = trsc->pivot[1];

    /* ...base graphics rendering; use jk-angle to decide if we render right or left side with glowing */
    bg = base + 3;

    float32_t   jk_angle = (float32_t)vehicle->trsc_jk_angle_pct * (float32_t)(M_PI_2 * 0.01);
    float32_t   tad_angle = (float32_t)vehicle->trsc_tad_angle_pct * (float32_t)(M_PI_2 * 0.01);
    float32_t   max_angle = 0;
    if (vehicle->trsc_orange_enable)
    {
        max_angle = 1.f;
    }

    if (vehicle->trsc_red_enable)
    {
        max_angle = M_PI_2;
    }

    jk_angle = clamp_angle(jk_angle, max_angle);
    tad_angle = clamp_angle(tad_angle, max_angle);

    //float32_t   max_angle = (fabsf(jk_angle) > fabsf(tad_angle) ? jk_angle : tad_angle);
    /* ...left side rendered as is */
    tile_set_offset(dst, trsc->base, offset);
    if ((item = icon_get_item(icon, base)) != NULL)
    {
        CHK_API(icon_add_item(item, dst, render));
    }

    if ((item = icon_get_item(icon, base + 2)) != NULL)
    {
        CHK_API(icon_add_item(item, dst, render));
        remove_angle(&render->vbo, jk_angle, pivot, -1);
    }

    if ((item = icon_get_item(icon, base + 3)) != NULL)
    {
        CHK_API(icon_add_item(item, dst, render));
        remove_angle(&render->vbo, tad_angle, pivot, -1);
    }

    /* ...right side is mirrored around pivot point in X-direction */
    tile_mirror(dst, dst, pivot[0]);
    if ((item = icon_get_item(icon, (base))) != NULL)
    {
        CHK_API(icon_add_item(item, dst, render));
    }

    if ((item = icon_get_item(icon, base + 2)) != NULL)
    {
        CHK_API(icon_add_item(item, dst, render));
        remove_angle(&render->vbo, jk_angle, pivot, 1);
    }

    if ((item = icon_get_item(icon, base + 3)) != NULL)
    {
        CHK_API(icon_add_item(item, dst, render));
        remove_angle(&render->vbo, tad_angle, pivot, 1);
    }

    /* ...vehicle icon rendering */
    if(base == ICON_TRSC_BASE_SVC)
    {
        if ((item = icon_get_item(icon, ICON_TRSC_VEHICLE_SVC0 + cfg_get_body_length_variant(cfg))) != NULL)
        {
            switch(cfg_get_body_length_variant(cfg))
            {
                case 2:
                    tile_set_offset(dst, trsc->q_vehicle, offset);
                    break;
                case 1:
                    tile_set_offset(dst, trsc->cs_vehicle, offset);
                    break;
                case 0:
                    tile_set_offset(dst, trsc->cl_vehicle, offset);
                    break;
                default:
                    break;
            }
            CHK_API(icon_add_item(item, dst, render));
        }
    }
    else if(base == ICON_TRSC_BASE_TRG)
    {
        if ((item = icon_get_item(icon, ICON_TRSC_VEHICLE_TRG0 + cfg_get_body_length_variant(cfg))) != NULL)
        {
            switch(cfg_get_body_length_variant(cfg))
            {
                case 2:
                    tile_set_offset(dst, trsc->q_vehicle, offset);
                    break;
                case 1:
                    tile_set_offset(dst, trsc->cs_vehicle, offset);
                    break;
                case 0:
                    tile_set_offset(dst, trsc->cl_vehicle, offset);
                    break;
                default:
                    break;
            }
            CHK_API(icon_add_item(item, dst, render));
        }
    }

    uint32_t trailer_icon = vehicle->trsc_red_trailer ? ICON_TRSC_TRAILER_RED_TRG : ICON_TRSC_TRAILER_TRG;

    /* ...trailer icon rendering */
    if ((item = icon_get_item(icon, trailer_icon)) != NULL)
    {
        float32_t   tad_angle = (float32_t)vehicle->trsc_tad_angle_pct * (float32_t)(M_PI_2 * 0.01);

        tile_set_offset(dst, trsc->trailer, offset);
        CHK_API(icon_add_item_rot(item, dst, tad_angle, pivot, 0, render));
    }

    /* ...white dotted line rendering */
    if ((item = icon_get_item(icon, TRSC_ICON(base, DOTTED))) != NULL)
    {
        float32_t   tad_angle = (float32_t)vehicle->trsc_jk_angle_pct * (float32_t)(M_PI_2 * 0.01);

        tile_set_offset(dst, trsc->dotted, offset);
        CHK_API(icon_add_item_rot(item, dst, tad_angle, pivot, 0, render));
    }

    return 0;
}

/**
 * @brief   Add aiming error icon as needed
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   type[in]        4-camera system flag
 * @param   side[in]        Side-view flag
 * @param   vehicle[in]     Vehicle data pointer
 * @param   render[in]      Icon render list
 *
 * @return                  Negative on failure
 */
int icon_add_aiming(icon_data_t *icon, cfg_data_t *cfg, int type, int side, vehicle_state_t *vehicle, icon_render_t *render)
{
    aiming_state_t     *aiming = &vehicle->aiming;
    icon_item_t        *item = icon_get_item(icon, ICON_AIMING_ERROR);
    int32_t           (*dst)[4];
    int32_t             i;

    TRACE(0, _b("add aiming: type=%d, side=%d, failure=%X, item=%p"), type, side, aiming->failure, item);

    /* ...bail out if resource is missing */
    if (!item)      return 0;

    /* ...select destination tiles pointer */
    if (type != 0)
    {
        dst = (side != 0 ? cfg->vm.aiming_error.sv_dst : cfg->vm.aiming_error.tv_dst);

        for (i = 0; i < 4; i++)
        {
            if ((aiming->failure & (3U << (i * 2))) != 0U)
            {
                CHK_API(icon_add_item(item, dst[i], render));
            }
        }
    }
    else if (side != 0)
    {
        dst = (side > 0 ? cfg->vm.aiming_error.sv_dst : cfg->vm.aiming_error.nc_dst);

        /* ...process only rear/left cameras */
        for (i = 1; i < 3; i++)
        {
            if ((aiming->failure & (3U << (i * 2))) != 0U)
            {
                CHK_API(icon_add_item(item, dst[i], render));
            }
        }
    }
    else
    {
        dst = cfg->vm.aiming_error.sc_dst;

        /* ...process only rear camera */
        if ((aiming->failure & (3U << (2 * 2))) != 0U)
        {
            CHK_API(icon_add_item(item, dst[0], render));
        }
    }

    return 0;
}

/**
 * @brief   Add border icons as needed
 *
 * @param   icon[in]        Icon data
 * @param   cfg[in]         Global configuration data
 * @param   screen_dst[in]  Screen destination tile
 * @param   side[in]        Side-view flag
 * @param   render[in]      Icon render list
 *
 * @return                  Negative on failure
 */
int icon_add_border(icon_data_t *icon, cfg_data_t *cfg, int32_t *screen_dst, icon_render_t *render)
{
    icon_item_t    *item = icon_get_item(icon, ICON_BORDER);

    int32_t     R = 16;
    int32_t     dst[4][4] = {
        [0] = { screen_dst[0], screen_dst[1], screen_dst[0] + R, screen_dst[1] + R }, // UL
        [1] = { screen_dst[2], screen_dst[1], screen_dst[2] - R, screen_dst[1] + R }, // UR
        [2] = { screen_dst[0], screen_dst[3], screen_dst[0] + R, screen_dst[3] - R }, // BL
        [3] = { screen_dst[2], screen_dst[3], screen_dst[2] - R, screen_dst[3] - R }, // BR
    };

    if (item != NULL)
    {
        /* ...render all four corners */
        CHK_API(icon_add_item(item, dst[0], render));
        CHK_API(icon_add_item(item, dst[1], render));
        CHK_API(icon_add_item(item, dst[2], render));
        CHK_API(icon_add_item(item, dst[3], render));
    }

    return 0;
}

/*******************************************************************************
 * Auxiliary functions - tbd - reorder
 ******************************************************************************/

/**
 * @brief   Get graphical resource source
 *
 * @param   icon[in]        Icons data
 * @param   id[in]          Resource id
 * @param   tex[out]        Graphical resource descriptor
 *
 * @return                  Negative on failure
 */
int icon_get_resource(icon_data_t *icon, uint32_t id, icon_item_t **item)
{
    if ((*item = icon_get_item(icon, id)) == NULL)
    {
        TRACE(ERROR, _x("icon %d not found: %s"), id, strerror(errno));
        return -1;
    }
    else
    {
        return 0;
    }
}
