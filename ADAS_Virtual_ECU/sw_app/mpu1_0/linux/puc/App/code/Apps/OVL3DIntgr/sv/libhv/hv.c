/*******************************************************************************
 * hv.c
 *
 * Historcial-view module
 *
 * Copyright (c) 2015-2021 Cogent Embedded Inc.
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

#define MODULE_TAG                      HV

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "hv.h"
#include "../libsv/mesh-render.h"
#include "math-neon.h"
#ifdef BUILD_NATIVE
#include "debug.h"
#endif

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Local typedefs
 ******************************************************************************/

#ifdef BUILD_NATIVE
/**
 * @brief   Historical view debug data
 */
typedef struct hv_dbg
{
    /**> Debug window callbacks */
    dbg_info_t          info;

    /**> Debug window */
    dbg_window_t        dbg;
    
    /**> Configuration pointer */
    cfg_data_t         *cfg;

    /**> Vehicle pose buffer (last 1000 points?) */
    dbg_vbo_t           pose;

    /**> Last pose X coordinate */
    dbg_vbo_t           x;

    /**> Last pose Y coordinate */
    dbg_vbo_t           y;

    /**> Wheels pulses */
    dbg_vbo_t           pulse[4];
    
    /**> Pose writing cursor */
    uint32_t            cursor;

    /**> Test mesh VBO */
    vbo_dynarray_t      vbo[SV_CAMERAS_NUMBER];

    /**> Track visualization */
    int                 track[SV_CAMERAS_NUMBER];

    /**> Colors mixing */
    int                 mix;

}   hv_dbg_t;
#endif

typedef float32_t mmm[8 * 6];

/**
 * @brief   Historical view data
 */
struct hv_data
{
    /**> Historical buffers arrays */
    GLuint              tex[SV_CAMERAS_NUMBER];

    /**> Framebuffer for top-view rendering */
    GLuint              fb[SV_CAMERAS_NUMBER];

    /**> Number of historcial slices */
    int                 dim[SV_CAMERAS_NUMBER];
    
    /**> Current level index for historical buffer textures */
    int                 level[SV_CAMERAS_NUMBER];

    /**> Current base level for slices */
    int                 base[SV_CAMERAS_NUMBER];
    
    /**> Number of available levels */
    int                 avail[SV_CAMERAS_NUMBER];

    /**> Matrices for translation of WCS to slice UV-coordinates */
    float32_t           scm[SV_CAMERAS_NUMBER][2 * 3];

    /**> Current WCS-to-HCS conversion matrix */
    float32_t           W2H[2 * 3];
    
    /**> 2*3 matrices for conversion of slice coordinates: SCM*inv(Mn) */
    float32_t        (*(H2S[SV_CAMERAS_NUMBER]))[2 * 3];
    
    /**> Depth renderbuffer? - guess don't need that */
    mesh_data_t         mesh;

#ifdef  BUILD_NATIVE
    /**> Debug window interface */
    hv_dbg_t            dbg;
#endif
};

/*******************************************************************************
 * Historical view mesh rendering
 ******************************************************************************/

/* ...vertex shader program for cubemap textures visualization */
static const char * hv_vertex_shader =
    "#version 320 es\n"
    SH_SETPREC
    "in vec2 XY;\n"
    "in vec4 UVJQ;\n"
    "out vec4 uvjq;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(XY.x, -XY.y, 0.0, 1.0);\n"
    "   uvjq = UVJQ;\n"
    "}\n";

/* ...fragment shader for textures blending */
static const char * hv_fragment_shader =
    "#version 320 es\n"
    SH_SETPREC
    "in vec4 uvjq;\n"
    "out vec4 g_FragColor;\n"
    "uniform lowp sampler2DArray tex;\n"
    "uniform vec3 color;\n"
    "uniform float alpha;\n"
    "void main()\n"
    "{\n"
    "   vec3    rgb = texture(tex, vec3(uvjq.x, 1.0 - uvjq.y, uvjq.z)).rgb;\n"
    "   rgb = mix(rgb, color, alpha);\n"
//    "   g_FragColor = vec4(vec3(uvjq.w), 0.5);\n"
    "   g_FragColor = vec4(rgb, uvjq.w);\n"
    "}\n";

/* ...build color texture rendering shader */
#define SHADER_TAG                      HV
#define SHADER_VERTEX_SOURCE            hv_vertex_shader
#define SHADER_FRAGMENT_SOURCE          hv_fragment_shader

/* ...attributes definition */
#define SHADER_ATTRIBUTES                           \
    __A(XY),            /* ...vertex position */    \
    __A(UVJQ),          /* ...texture coordinate/level/weight */

/* ...uniforms definition */
#define SHADER_UNIFORMS                                         \
    __U(tex),           /* ...texture-array sampler */          \
    __U(color),         /* ...color to mix with texture data */ \
    __U(alpha),         /* ...mix factor for color */

/* ...instantiate indices/names lists */
#include "../src/shader-impl.h"

/**> Shader object */
static shader_data_t   *__hv_shader;

#define U(id)       u[UNIFORM(HV, id)]
#define A(id)       ATTRIBUTE(HV, id)

/**
 * @brief   Render historical-view mesh
 */
void hv_mesh_render(hv_data_t *hv, vbo_dynarray_t *vbo)
{
    shader_data_t  *shader = __hv_shader;

    if (shader == NULL)
    {
        if ((shader = __hv_shader = shader_create(&SHADER_DESC(HV))) == NULL)
        {
            TRACE(ERROR, _x("failed to compile shader: %s"), strerror(errno));
            return;
        }
    }

    const GLint    *u = shader_uniforms(shader);

    glUseProgram(shader_program(shader));

    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    
    int             k;

    const float32_t color[SV_CAMERAS_NUMBER][3] = {
        {   1.0f, 0.0f, 0.0f },
        {   0.0f, 1.0f, 0.0f },
        {   0.0f, 0.0f, 1.0f },
        {   1.0f, 1.0f, 0.0f },
    };
        
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        uint32_t    size = vbo_dynarray_num(&vbo[k]);
        void       *xy = vbo_dynarray_buffer(&vbo[k], sizeof(hv_vertex_t));
        void       *uvjq = (float32_t *)xy + 2;
        
        if (!size)      continue;
        
        /* ...for the moment use memory-backed buffers */
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glUniform1iv(U(tex), 1, (GLint[1]){ 0 });   GLCHECK();
        glUniform3fv(U(color), 1, color[k]);    GLCHECK();
#ifdef BUILD_NATIVE        
        glUniform1f(U(alpha), (hv->dbg.mix ? 0.2f : 0.0f));    GLCHECK();
#endif
        /* ...bind textures */
        glActiveTexture(GL_TEXTURE0);   GLCHECK();
        glBindTexture(GL_TEXTURE_2D_ARRAY, hv->tex[k]);

        /* ...bind attributes */
        glEnableVertexAttribArray(A(XY));   GLCHECK();
        glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, sizeof(hv_vertex_t), xy);   GLCHECK();
        glEnableVertexAttribArray(A(UVJQ)); GLCHECK();
        glVertexAttribPointer(A(UVJQ), 4, GL_FLOAT, GL_FALSE, sizeof(hv_vertex_t), uvjq);   GLCHECK();

        glDrawArrays(GL_TRIANGLES, 0, size); GLCHECK();
        
    }

    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
    glUseProgram(0);
}

#undef U
#undef A

/*******************************************************************************
 * Internal functions definitions
 ******************************************************************************/

#ifdef BUILD_NATIVE
/**
 * @brief   Dump vehicle pose
 *
 * @param   dbg[in]         HV debug data
 * @param   pose[in]        Current vehicle pose
 */
static void hv_dbg_dump_pose(hv_dbg_t *dbg, float32_t *pose)
{
    float32_t     (*p)[7];
    float32_t       X = pose[0 * 3 + 2] * 1e-3f;
    float32_t       Y = pose[1 * 3 + 2] * 1e-3f;
    
    (dbg->pose.vbo == NULL ? dbg_vbo_init(&dbg->pose, 2048) : 0);
    (dbg->x.vbo == NULL ? dbg_vbo_init(&dbg->x, 128) : 0);
    (dbg->y.vbo == NULL ? dbg_vbo_init(&dbg->y, 128) : 0);
    
    /* ...get point cursor */
    p = dbg_vbo_cursor(&dbg->pose, dbg->cursor);

    /* ...fill point color */
    float32_t   t = fmodf((float32_t)dbg->cursor / 128.0f, 1.0f);

    __vec4  color = { t, t, t, 1.0f };    
    (*p)[0] = X;
    (*p)[1] = Y;
    (*p)[2] = 0.5f;
    memcpy(&(*p)[3], color, sizeof(color));

    TRACE(0, _b("pose[%u]: %f,%f, color=%f, avail=%u"), dbg->cursor, X, Y, t, (uint32_t)dbg->pose.avail);
    
    /* ...advance number of points available */
    (dbg->pose.avail > 0 ? dbg->pose.avail-- : 0);
    dbg_vbo_finish(&dbg->pose);

    /* ...dump X-coordinate */
    p = dbg_vbo_cursor(&dbg->x, dbg->cursor & 0x7F);

    __vec4  color_x = { 1.0f, 0.0f, 0.0f, 1.0f };
    (*p)[0] = (float32_t)(dbg->cursor & 0x7F) / 128.0f;
    (*p)[1] = X;
    (*p)[2] = 0.0f;
    memcpy(&(*p)[3], color_x, sizeof(__vec4));

    /* ...advance number of points available */
    (dbg->x.avail > 0 ? dbg->x.avail-- : 0);
    dbg_vbo_finish(&dbg->x);

    /* ...dump Y-coordinate */
    p = dbg_vbo_cursor(&dbg->y, dbg->cursor & 0x7F);

    __vec4  color_y = { 0.0f, 1.0f, 0.0f, 1.0f };
    (*p)[0] = (float32_t)(dbg->cursor & 0x7F) / 128.0f;
    (*p)[1] = Y;
    (*p)[2] = 0.0f;
    memcpy(&(*p)[3], color_y, sizeof(__vec4));

    /* ...advance number of points available */
    (dbg->y.avail > 0 ? dbg->y.avail-- : 0);
    dbg_vbo_finish(&dbg->y);

    /* ...advance cursor position */
    (++dbg->cursor == dbg->pose.size ? dbg->cursor = 0 : 0);
}

/**
 * @brief   Dump wheels pulses counts
 *
 * @param   dbg[in]         HV debug data
 * @param   pulse[in]       Current wheels pulses counts
 */
static void hv_dbg_dump_pulse(hv_dbg_t *dbg, uint16_t *pulse)
{
    __vec4      color[4] = {
        { 0.5f, 0.2f, 0.2f, 1.0f },
        { 0.2f, 0.5f, 0.2f, 1.0f },
        { 0.0f, 0.0f, 1.0f, 1.0f },
        { 0.5f, 0.5f, 0.2f, 1.0f },
    };

    int         i;

    for (i = 0; i < 4; i++)
    {
        dbg_vbo_t      *vbo = &dbg->pulse[i];
        float32_t     (*p)[7];
        
        (vbo->vbo == NULL ? dbg_vbo_init(vbo, 128) : 0);
    
        /* ...get point cursor */
        p = dbg_vbo_cursor(vbo, dbg->cursor & 0x7F);

        (*p)[0] = (float32_t)(dbg->cursor & 0x7F) / 128.0f;
        (*p)[1] = (float32_t)(pulse[i] % 128) / 128.0;
        (*p)[2] = 0.0f;
        memcpy(&(*p)[3], color[i], sizeof(__vec4));

        /* ...advance number of points available */
        (vbo->avail > 0 ? vbo->avail-- : 0);
        dbg_vbo_finish(vbo);
    }
}

extern int hv_mesh_create_strip_2(hv_data_t *hv, vbo_dynarray_t *vbo, float32_t (*v)[3], float32_t *x, float32_t *d, int32_t n);
extern int hv_mesh_create_strip_3(hv_data_t *hv, vbo_dynarray_t *vbo, float32_t (*v)[3], float32_t *x, float32_t *d, int32_t n);


/**
 * @brief   Create historical-view mesh
 */
static int hv_dbg_mesh_create(hv_dbg_t *dbg, cfg_data_t *cfg, int N, int M)
{
    hv_data_t      *hv = container_of(dbg, hv_data_t, dbg);
    cfg_bv_mesh_t  *bv = &dbg->cfg->hv;
    int             k;

    /* ...reset VBOs */
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        if (dbg->vbo[k].size == 0)
        {
            CHK_API(vbo_dynarray_init(&dbg->vbo[k], sizeof(hv_vertex_t), 1000));
        }
        else
        {
            vbo_dynarray_clear(&dbg->vbo[k], sizeof(hv_vertex_t));
        }
    }

    float32_t   xy0[2] = { -1.0f, -1.0f };    
    float32_t   dxy[2] = { 2.0f / (float32_t)(N - 1), 2.0f / (float32_t)(M - 1) };
    float32_t   V0[N][3];
    float32_t   V1[N][3];

    float32_t   Xf = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + cfg->vehicle.front_blind_area;
    float32_t   Xr = -cfg->vehicle.rear_overhang -cfg->vehicle.rear_blind_area;
    float32_t   Yl = cfg->vehicle.width * 0.5f + cfg->vehicle.left_blind_area;
    float32_t   Yr = -cfg->vehicle.width * 0.5f - cfg->vehicle.right_blind_area;
    float32_t   Xc = (Xf + Xr) * 0.5f;
    float32_t   Yc = (Yl + Yr) * 0.5f;

    float32x2x3_t   D2W;
    D2W.val[0] = __mk_float32x2(0.0f, -(Yl - Yr) / 2.0f);
    D2W.val[1] = __mk_float32x2(-(Xf - Xr) / 2.0f, 0.0f);
    D2W.val[2] = __mk_float32x2(Xc, Yc);

    float32x2x3_t   W2H = vld3_f32(hv->W2H);
    float32x2x3_t   D2H = __mat2x3_mul(W2H, D2W);
    
    /* ...process strips */
    int     x, y;
    for (y = 0; y < M - 1; y++)
    {
        float32x2x2_t   R;
        R.val[0] = __mk_float32x2(-1.0f, -1.0f + y * dxy[1]);
        R.val[1] = __mk_float32x2(-1.0f, -1.0f + (y + 1) * dxy[1]);

        float32x2_t     dX = __mk_float32x2(dxy[0], 0.0f);
        
        float32_t       strip[2 * N][3];

        for (x = 0; x < N; x++)
        {
            float32x2x2_t   Q = __mat2x3_mulvh(D2W, R);

            vst1_f32(strip[2 * x + 0], Q.val[0]);
            vst1_f32(strip[2 * x + 1], Q.val[1]);

            TRACE(0, _b("[%d,%d]: R=[0]:%f,%f, [1]:%f,%f, Q=[0]:%f,%f, [1]:%f,%f"), x, y, __float32x2_p(R.val[0]), __float32x2_p(R.val[1]), __float32x2_p(Q.val[0]), __float32x2_p(Q.val[1]));

            R.val[0] = vadd_f32(R.val[0], dX);
            R.val[1] = vadd_f32(R.val[1], dX);
        }
        
        /* ...encode a strip */
        //CHK_API(hv_mesh_create_strip(hv, dbg->vbo, strip, (float32_t [2]){ -1.0f, -1.0f + y * dxy[1]}, dxy, N));
        CHK_API(hv_mesh_create_strip(hv, dbg->vbo, strip, (float32_t [2]){ -1.0f, -1.0f + y * dxy[1]}, dxy, N));
    }

    BUG(0, _x("break"));
    
    return 0;
}

/**
 * @brief   Draw rectangle in world coordinates
 *
 * @param   coord[in]       Rectangle coordinates
 *
 */
static inline void hv_draw_rect(float32_t *coord, float32_t *color, float32x2x3_t W2H, float32_t width, float32_t *M)
{
    float32_t       Xf = coord[0], Yl = coord[1];
    float32_t       Xr = coord[2], Yr = coord[3];
    float32_t       P[4][2];
    float32x2x2_t   Q;

    Q.val[0] = __mk_float32x2(Xf, Yl);
    Q.val[1] = __mk_float32x2(Xf, Yr);
    Q = __mat2x3_mulvh(W2H, Q);
    Q.val[0] = vmul_n_f32(Q.val[0], 1e-3f);
    Q.val[1] = vmul_n_f32(Q.val[1], 1e-3f);
    P[0][0] = vget_lane_f32(Q.val[0], 0);
    P[0][1] = vget_lane_f32(Q.val[0], 1);
    P[1][0] = vget_lane_f32(Q.val[1], 0);
    P[1][1] = vget_lane_f32(Q.val[1], 1);

    Q.val[0] = __mk_float32x2(Xr, Yr);
    Q.val[1] = __mk_float32x2(Xr, Yl);
    Q = __mat2x3_mulvh(W2H, Q);
    Q.val[0] = vmul_n_f32(Q.val[0], 1e-3f);
    Q.val[1] = vmul_n_f32(Q.val[1], 1e-3f);
    P[2][0] = vget_lane_f32(Q.val[0], 0);
    P[2][1] = vget_lane_f32(Q.val[0], 1);
    P[3][0] = vget_lane_f32(Q.val[1], 0);
    P[3][1] = vget_lane_f32(Q.val[1], 1);

    float32_t   c[4][4];
    memcpy(c[0], color, sizeof(c[0]));
    memcpy(c[1], color, sizeof(c[0]));
    memcpy(c[2], color, sizeof(c[0]));
    memcpy(c[3], color, sizeof(c[0]));

    dbg_quad_render(P, width, c, M);
}

/**
 * @brief   Redraw HV debug screen
 *
 * @param   dbg_window[in]  Debug window handle
 * @param   W[in]           Window width
 * @param   H[in]           Window height
 */
static void hv_dbg_redraw(dbg_window_t *dbg_window, int W, int H)
{
    hv_dbg_t       *dbg = container_of(dbg_window, hv_dbg_t, dbg);
    hv_data_t      *hv = container_of(dbg, hv_data_t, dbg);
    cfg_data_t     *cfg = dbg->cfg;
    cfg_bv_mesh_t  *bv = &cfg->hv;
    int             k;

    /* ...clear display */
    glViewport(0, 0, W, H);
    glScissor(0, 0, W, H);
    glDisable(GL_BLEND);
    glDisable(GL_CULL_FACE);

    /* ...render slices */
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        int         n = hv->dim[k];
        int         level = hv->level[k];
        int         j;

        glViewport(k * 2 * W / 12, 0, 2 * W / 12, H / 2);
        
        for (j = 0; j < n; j++)
        {
            int32_t     x0 = 0;
            int32_t     y0 = (int32_t)((float32_t)j / (float32_t)n * 0.5f * (float32_t)H);
            int32_t     x1 = W / 6;
            int32_t     y1 = (int32_t)((float32_t)(j + 1) / (float32_t)n * 0.5f * (float32_t)H);

            /* ...select color basing on level status */
            uint32_t    age = (level - j + n) % n;
            float32_t   factor = (age < hv->avail[k] ? age / (float32_t)n : 1.0f);

            //TRACE(1, _b("%d-%d: level=%d, avail=%d, age=%d, factor=%f"), k, j, level, hv->avail[k], age, factor);
            
            float32_t   color[4] = {
                0.0f, 0.0f, 0.0f, factor
            };
            
            dbg_texarr_render(hv->tex[k], color, (float32_t)j, x0, y0, x1, y1, 2 * W / 12, H / 2);
        }
    }

    /* ...render vehicle trajectory */
    glViewport(0, H / 2, 2 * W / 6, H / 2);
    glScissor(0, H / 2, 2 * W / 6, H / 2);
    glEnable(GL_SCISSOR_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glClearColor(15 / 255.0f, 20 / 255.0f, 65.0f / 255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    __mat4x4    M;
    __matNxN_zero(4, M);
    __M(4, M, 0, 1) = dbg->dbg.scale * 0.1 * 0.75 * -1.0f;
    __M(4, M, 1, 0) = dbg->dbg.scale * 0.1 * 0.75 * 1.0f;
    __M(4, M, 2, 2) = 1.0f;
    __M(4, M, 3, 3) = 1.0f;
    __M(4, M, 0, 3) = -dbg->dbg.rot[2] * 0.01;
    __M(4, M, 1, 3) = dbg->dbg.rot[0] * 0.01;
    dbg_grid_render(1.0f, 1.0f, 10, 10, 1.0f, M);
    dbg_vbo_render(dbg->pose.vbo, GL_POINTS, 0, dbg_vbo_count(&dbg->pose), M);

    /* ...render camera slices */
    if (1)
    {
        float32x2x2_t   Q01, Q23;
        Q01.val[0] = __mk_float32x2(0, 0);
        Q01.val[1] = __mk_float32x2(0, 1);
        Q23.val[0] = __mk_float32x2(1, 1);
        Q23.val[1] = __mk_float32x2(1, 0);

        float32_t   color[4][4] = {
            { 1.0f, 0.0f, 0.0f, 0.5f},
            { 0.0f, 1.0f, 0.0f, 0.5f},
            { 0.0f, 0.0f, 1.0f, 0.5f},
            { 1.0f, 1.0f, 0.0f, 0.5f},
        };

        for (k = 0; k < SV_CAMERAS_NUMBER; k++)
        {
            int         n = hv->dim[k];
            int         base = hv->base[k], j = base;
            int         m = hv->avail[k];

            if (dbg->track[k] != 0)  continue;
            
            while (--m > 0)
            {
                //float32x2x3_t   S2H = hv_inv_mat(hv->H2S[k][j]);
                float32x2x3_t   H2S = vld3_f32(hv->H2S[k][j]);
                float32x2x3_t   S2H = __mat2x3_inv(H2S);//hv_inv_mat(hv->H2S[k][j]);

                float32x2x2_t   R01, R23;
                R01 = __mat2x3_mulvh(S2H, Q01);
                R23 = __mat2x3_mulvh(S2H, Q23);

                float32_t       P[4][2];
                vst1_f32(P[0], vmul_n_f32(R01.val[0], 1e-3f));
                vst1_f32(P[1], vmul_n_f32(R01.val[1], 1e-3f));
                vst1_f32(P[2], vmul_n_f32(R23.val[0], 1e-3f));
                vst1_f32(P[3], vmul_n_f32(R23.val[1], 1e-3f));

                uint32_t    age = (base - j + n) % n;

                float32_t   c[4][4];
                memcpy(c[0], color[k], sizeof(float32_t[3]));
                c[0][3] = (float32_t) (age + 1) / (float32_t)(n);
                
                memcpy(c[1], c[0], sizeof(c[0]));
                memcpy(c[2], c[0], sizeof(c[0]));
                memcpy(c[3], c[0], sizeof(c[0]));

                dbg_bar_render(P, c, M);
                
                j = (j ? : n) - 1;
            }
        }
    }
    
    /* ...vehicle bounding box */
    if (1)
    {
        float32x2x3_t   W2H = vld3_f32(hv->W2H);
        float32_t       P[4];

        float32_t   Xf = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + cfg->vehicle.front_blind_area;
        float32_t   Xr = -cfg->vehicle.rear_overhang -cfg->vehicle.rear_blind_area;
        float32_t   Yl = cfg->vehicle.width * 0.5f + cfg->vehicle.left_blind_area;
        float32_t   Yr = -cfg->vehicle.width * 0.5f - cfg->vehicle.right_blind_area;

        TRACE(0, _b("W2H: %f,%f,%f : %f,%f,%f"), hv->W2H[0], hv->W2H[1], hv->W2H[2], hv->W2H[3], hv->W2H[4], hv->W2H[5]);
        
        P[0] = Xf;
        P[1] = Yl;
        P[2] = Xr;
        P[3] = Yr;        
        hv_draw_rect(P, (float32_t[4]){0.5f, 0.5f, 0.5f, 0.8f}, W2H, 1.5f, M);

        Xf = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + bv->front_blind_area;
        Xr = -cfg->vehicle.rear_overhang - bv->rear_blind_area;
        Yl = cfg->vehicle.width * 0.5f + bv->left_blind_area;
        Yr = -cfg->vehicle.width * 0.5f - bv->right_blind_area;

        float32_t   Xc = (-cfg->vehicle.rear_overhang + cfg->vehicle.wheel_base + cfg->vehicle.front_overhang) * 0.5f;
        float32_t   Yc = 0.0f;
        
        /* ...front slice position */
        P[0] = Xf + bv->slice_height_hor;
        P[1] = Yc + bv->slice_width_hor * 0.5f;
        P[2] = Xf;
        P[3] = Yc - bv->slice_width_hor * 0.5f;
        hv_draw_rect(P, (float32_t[4]){1.0f, 0.0f, 0.0f, 0.5f}, W2H, 1.0f, M);

        /* ...left slice position */
        P[0] = Xc - bv->slice_width_vert * 0.5f;
        P[1] = Yl + bv->slice_height_vert;
        P[2] = Xc + bv->slice_width_vert * 0.5f;
        P[3] = Yl;
        hv_draw_rect(P, (float32_t[4]){0.0f, 1.0f, 0.0f, 0.5f}, W2H, 1.0f, M);

        /* ...rear slice position */
        P[0] = Xr - bv->slice_height_hor;
        P[1] = Yc - bv->slice_width_hor * 0.5f;
        P[2] = Xr;
        P[3] = Yc + bv->slice_width_hor * 0.5f;
        hv_draw_rect(P, (float32_t[4]){0.0f, 0.0f, 1.0f, 0.5f}, W2H, 1.0f, M);

        /* ...right slice position */
        P[0] = Xc + bv->slice_width_vert * 0.5f;
        P[1] = Yr - bv->slice_height_vert;
        P[2] = Xc - bv->slice_width_vert * 0.5f;
        P[3] = Yr;
        hv_draw_rect(P, (float32_t[4]){1.0f, 1.0f, 0.0f, 0.5f}, W2H, 1.0f, M);
    }
    
    glViewport(2 * W / 6, H / 2, W / 3, H / 2);
    glScissor(2 * W / 6, H / 2, W / 3, H / 2);
    //glClearColor(60 / 255.0f, 60 / 255.0f, 90 / 255.0f, 1.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    __matNxN_identity(4, M);
    __M(4, M, 0, 0) = 2.0f;
    __M(4, M, 1, 1) = 0.1f * 1.0f;

    __M(4, M, 0, 3) = -1.0f;
    __M(4, M, 1, 3) = 0.0f;

    dbg_grid_render(0.1f, 1.0f, 10, 10, 1.0f, M);
    
    dbg_vbo_render(dbg->x.vbo, GL_POINTS, 0, dbg_vbo_count(&dbg->x), M);
    dbg_vbo_render(dbg->y.vbo, GL_POINTS, 0, dbg_vbo_count(&dbg->y), M);

    __matNxN_identity(4, M);
    __M(4, M, 0, 0) = 2.0f;
    __M(4, M, 1, 1) = 2.0f;
    __M(4, M, 0, 3) = -1.0f;
    __M(4, M, 1, 3) = -1.0f;
    for (k = 0; k < 4; k++)
    {
        dbg_vbo_render(dbg->pulse[k].vbo, GL_POINTS, 0, dbg_vbo_count(&dbg->pulse[k]), M);
    }

    /* ...render HV-mesh */
    glViewport(2 * W / 3, 0, W / 3, H);
    glScissor(2 * W / 3, 0, W / 3, H);

    glEnable(GL_BLEND);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_DST_ALPHA, GL_ONE, GL_ONE);    GLCHECK();
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_CULL_FACE);
    
    hv_mesh_render(hv, dbg->vbo);
}

/**
 * @brief   Input event processing
 *
 * @param   dbg[in]
 */
static int hv_dbg_event(dbg_window_t *dbg_window, widget_event_t *event)
{
    hv_dbg_t       *dbg = container_of(dbg_window, hv_dbg_t, dbg);
    hv_data_t      *hv = container_of(dbg, hv_data_t, dbg);

    if (WIDGET_EVENT_TYPE(event->type) == WIDGET_EVENT_KEY)
    {
        if (event->key.type == WIDGET_EVENT_KEY_PRESS && event->key.state)
        {
            switch (event->key.code)
            {
            case '1' ... '4':
                /* ...toggle track visibility status */
                dbg->track[event->key.code - '1'] ^= 1;
                break;

            case 'c':
            case 'C':
                /* ...clear historical buffer state */
                hv_reset(hv);
                break;

            case 'm':
            case 'M':
                /* ...toggle colors mixing flag */
                dbg->mix ^= 1;
                break;
            }
        }
    }

    return 0;
}

/**
 * @brief   Create historical view debug window
 */
static int hv_dbg_create(hv_data_t *hv, int width, int height, cfg_data_t *cfg)
{
    hv_dbg_t       *dbg = &hv->dbg;
    dbg_info_t     *info = &dbg->info;
    
    dbg->cfg = cfg;
    
    /* ...fill-in window parameters */
    info->width = width;
    info->height = height;
    info->title = "hv";

    /* ...set window callbacks */
    //info->init = hv_dbg_init;
    info->redraw = hv_dbg_redraw;
    info->event = hv_dbg_event;
    
    /* ...create debug window */
    if (dbg_window_init(&dbg->dbg, info) != 0)
    {
        TRACE(ERROR, _x("failed to create debug window: %m"));
        return -1;
    }

    return 0;
}
#endif  /* BUILD_NATIVE */

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Update HV-buffers mesh parameters
 *
 * @param   hv[in]          Historical view data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle state data
 * @param   gen[in]         Mesh generator
 *
 * @return                  Negative on failure
 */
int hv_update(hv_data_t *hv, cfg_data_t *cfg, vehicle_state_t *vehicle, mesh_gen_t *gen)
{
    /* ...generate meshes for all cameras */
    CHK_API(mesh_generate_bv(gen, cfg, &cfg->hv, &hv->mesh));

    return 0;
}

/**
 * @brief   Calculate HCS-to-UV 2*2 conversion matrix for a slice
 *
 * @param   S[in]           Slice HCS-to-UV matrix
 * @param   M[in]           Pseudo-inverted 3x2 pose matrix
 *
 * @return                  2x2 conversion matrix
 */
static inline __attribute__((__always_inline__))
float32x2x3_t calc_hcs_to_uv(float32x2x3_t S, float32x2x3_t M)
{
    return S;
}

/**
 * @brief   Process HV-buffers update
 *
 * @param   hv[in]          Historical view data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle-state data
 * @param   texture[in]     Input textures array
 *
 * @return                  Negative on failure
 */
int hv_process_old(hv_data_t *hv, cfg_data_t *cfg, vehicle_state_t *vehicle, texture_data_t **texture, float32_t (*CC)[3][3])
{
    cfg_bv_mesh_t  *bv = &cfg->hv;
    float32_t       cc[4][2][3];
    int             k;

    /* ...process vehicle pose change */
    float32_t      *pose = vehicle->pose;
    
#ifdef BUILD_NATIVE
    if (hv->dbg.info.width)
    {
        dbg_window_lock(&hv->dbg.dbg);
        hv_dbg_dump_pulse(&hv->dbg, vehicle->wheel_pulse_count);
        hv_dbg_dump_pose(&hv->dbg, pose);
    }
#endif

    /* ...update current WCS-to-HCS matrix */
    float32x2x3_t   W2H = vld3_f32(pose);
    vst3_f32(hv->W2H, W2H);
    
    /* ...calculate current HCS-to-WCS matrix (inverse) */
    float32x2x3_t   H2W;
    H2W.val[0] = vtrn1_f32(W2H.val[0], W2H.val[1]);
    H2W.val[1] = vtrn2_f32(W2H.val[0], W2H.val[1]);
    H2W.val[2] = vneg_f32(W2H.val[2]);
    H2W.val[2] = vmla_lane_f32(vmul_lane_f32(H2W.val[0], H2W.val[2], 0), H2W.val[1], H2W.val[2], 1);

    if (1)
    {
        float32x2x3_t   T = __mat2x3_mul(W2H, H2W);

        TRACE(1, _b("T1 = [0]:%f,%f, [1]:%f,%f, [2]:%f,%f"), __float32x2_p(T.val[0]), __float32x2_p(T.val[1]), __float32x2_p(T.val[2]));

        T = __mat2x3_mul(H2W, W2H);

        TRACE(1, _b("T2 = [0]:%f,%f, [1]:%f,%f, [2]:%f,%f"), __float32x2_p(T.val[0]), __float32x2_p(T.val[1]), __float32x2_p(T.val[2]));

        BUG(1, _x("break"));
    }
    
    if (0)
    {
        TRACE(1, _b("pose: %f,%f,%f : %f,%f,%f"), pose[0], pose[1], pose[2], pose[3], pose[4], pose[5]);

        TRACE(1, _b("M = [0]:%f,%f, [1]:%f,%f, [2]:%f,%f"), __float32x2_p(H2W.val[0]), __float32x2_p(H2W.val[1]), __float32x2_p(H2W.val[2]));

        float32x2x2_t   Q;
        Q.val[0] = __mk_float32x2(pose[0 * 3 + 2], pose[1 * 3 + 2]);
        Q.val[1] = __mk_float32x2(pose[0 * 3 + 2] + 4000.0f, pose[1 * 3 + 2]);

        float32x2x2_t   R;
        R = __mat2x3_mulvh(H2W, Q);
        TRACE(1, _b("R=[0]:%f,%f [1]:%f,%f"), __float32x2_p(R.val[0]), __float32x2_p(R.val[1]));
        
        BUG(0, _x("break"));
    }

    /* ...get slices centers */
    float32_t   Xf = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + bv->front_blind_area;
    float32_t   Xc = (-cfg->vehicle.rear_overhang + cfg->vehicle.wheel_base + cfg->vehicle.front_overhang) * 0.5f;
    float32_t   Xr = -cfg->vehicle.rear_overhang - bv->rear_blind_area;

    float32_t   Yl = cfg->vehicle.width * 0.5f + bv->left_blind_area;
    float32_t   Yc = 0.0f;
    float32_t   Yr = -cfg->vehicle.width * 0.5f - bv->right_blind_area;

    float32x2x2_t   C01, C23;
    C01.val[0] = __mk_float32x2(Xf + bv->slice_height_hor * 0.5f, Yc);
    C01.val[1] = __mk_float32x2(Xc + bv->slice_width_vert * 0.5f, Yl + bv->slice_height_vert * 0.5f);
    C23.val[0] = __mk_float32x2(Xr - bv->slice_height_hor * 0.5f, Yc);
    C23.val[1] = __mk_float32x2(Xc + bv->slice_width_vert * 0.5f, Yr - bv->slice_height_vert * 0.5f);

    float32x2x2_t   Q01 = __mat2x3_mulvh(W2H, C01);
    float32x2x2_t   Q23 = __mat2x3_mulvh(W2H, C23);
    
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        uint32_t        n = hv->dim[k];
        uint32_t        level = hv->level[k];
        uint32_t        base = hv->base[k];
        float32x2x3_t   H2S;

        if (n == 0)     continue;
        
        /* ...get base value of H2S for a camera */
        if (level != base)
        {
            float32x2_t     UV;
            float32_t       delta;
            
            /* ...get base slice matrix */
            H2S = vld3_f32(hv->H2S[k][base]);

            switch (k)
            {
            case 0:
                UV = __mat2x3_mulvh(H2S, Q01).val[0];
                break;
            
            case 1:
                UV = __mat2x3_mulvh(H2S, Q01).val[1];
                break;
            
            case 2:
                UV = __mat2x3_mulvh(H2S, Q23).val[0];
                break;
            
            default:
                UV = __mat2x3_mulvh(H2S, Q23).val[1];
            }

            if (vget_lane_f32(UV, 1) < 0.0f)
            {
                /* ...advance base */
                hv->base[k] = level;

                /* ...increase amount of available slices */
                (hv->avail[k] < n ? hv->avail[k]++ : 0);

                k == 0 ? TRACE(1, _b("v=%f, level-up: %d (%d)"), vget_lane_f32(UV, 1), level, hv->avail[k]) : 0;
            }
            else if (vget_lane_f32(UV, 1) > 1.0f)
            {
                /* ...drop base level; update base */
                hv->level[k] = level = base;

                /* ...set new base */
                hv->avail[k]-- > 2 ? hv->base[k] = (base ? : n) - 1 : 0;
                
                /* ...reduce amount of available slices */
                //hv->avail[k] ? hv->avail[k]-- : 0;

                k == 0 ? TRACE(1, _b("v=%f, level-down: %d (%d)"), vget_lane_f32(UV, 1), level, hv->avail[k]) : 0;
            }
            else
            {
                k == 0 ? TRACE(1, _b("v=%f, level: %d (%d)"), vget_lane_f32(UV, 1), level, hv->avail[k]) : 0;
            }
        }
        else if (hv->avail[k] > 0)
        {
            /* ...advance level */
            (++level == n ? level = 0 : 0);

            /* ...save new level (start another base tracking) */
            hv->level[k] = level;

            /* ...mark we have a base set */
            //(hv->avail[k] < n ? hv->avail[k]++ : 0);
        }
        else
        {
            /* ...set first base */
            hv->avail[k] = 1;
        }

        BUG(level != hv->level[k], _x("break: %d != %d"), level, hv->level[k]);
        
        /* ...save current matrix at selected level */
        float32x2x3_t   SCM = vld3_f32(hv->scm[k]);
        H2S = __mat2x3_mul(SCM, H2W);
        vst3_f32(hv->H2S[k][level], H2S);
        
        if (0)
        {
            if (k == 1)
            {
                TRACE(0, _b("wheel-base: %f, front-overhang: %f, front-blind-area: %f"), cfg->vehicle.wheel_base, cfg->vehicle.front_overhang, bv->front_blind_area);
                
                float32x2x2_t   V;
                //V.val[0] = __mk_float32x2(Xf + bv->slice_height_hor, Yc + bv->slice_width_hor * 0.5f);
                //V.val[1] = __mk_float32x2(Xf, Yc - bv->slice_width_hor * 0.5f);
                V.val[0] = __mk_float32x2(Xc - bv->slice_width_vert * 0.5f, Yl + bv->slice_height_vert);
                V.val[1] = __mk_float32x2(Xc + bv->slice_width_vert * 0.5f, Yl);
                
                TRACE(1, _b("pose=%f,%f,%f : %f,%f,%f"), pose[0], pose[1], pose[2], pose[3], pose[4], pose[5]);
                TRACE(1, _b("W2H=[0]:%f,%f, [1]:%f,%f, [2]:%f,%f"), __float32x2_p(W2H.val[0]), __float32x2_p(W2H.val[1]), __float32x2_p(W2H.val[2]));
                
                float32x2x2_t   R = __mat2x3_mulvh(W2H, V);
                float32x2x2_t   P = __mat2x3_mulvh(H2S, R);
                float32x2x2_t   Q = __mat2x3_mulvh(SCM, V);
                
                TRACE(1, _b("H2S(%d,%d)=[0]:%f,%f, [1]:%f,%f, [2]:%f,%f"), k, level, __float32x2_p(H2S.val[0]), __float32x2_p(H2S.val[1]), __float32x2_p(H2S.val[2]));
                TRACE(1, _b("V=[0]:%f,%f, [1]:%f,%f"), __float32x2_p(V.val[0]), __float32x2_p(V.val[1]));
                TRACE(1, _b("R=[0]:%f,%f, [1]:%f,%f"), __float32x2_p(R.val[0]), __float32x2_p(R.val[1]));
                TRACE(1, _b("P=[0]:%f,%f, [1]:%f,%f"), __float32x2_p(P.val[0]), __float32x2_p(P.val[1]));
                TRACE(1, _b("Q=[0]:%f,%f, [1]:%f,%f"), __float32x2_p(Q.val[0]), __float32x2_p(Q.val[1]));

                BUG(0, _x("break"));
            }
        }
    }

    /* ...set color-correction coefficients */
    if (CC != NULL)
    {
        memcpy(cc, CC, sizeof(cc));

        TRACE(0, _b("cc[0][0]: %f,%f,%f, cc[0][1]: %f,%f,%f"), cc[0][0][0], cc[0][0][1], cc[0][0][2], cc[0][1][0], cc[0][1][1], cc[0][1][2]);
        TRACE(0, _b("cc[1][0]: %f,%f,%f, cc[1][1]: %f,%f,%f"), cc[1][0][0], cc[1][0][1], cc[1][0][2], cc[1][1][0], cc[1][1][1], cc[1][1][2]);
        TRACE(0, _b("cc[2][0]: %f,%f,%f, cc[2][1]: %f,%f,%f"), cc[2][0][0], cc[2][0][1], cc[2][0][2], cc[2][1][0], cc[2][1][1], cc[2][1][2]);
        TRACE(0, _b("cc[3][0]: %f,%f,%f, cc[3][1]: %f,%f,%f"), cc[3][0][0], cc[3][0][1], cc[3][0][2], cc[3][1][0], cc[3][1][1], cc[3][1][2]);
    }
    else
    {
        memset(cc, 0, sizeof(cc));
    }

    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_BLEND);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);
    
    /* ...render HV-mesh for all cameras */
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        /* ...determine level for rendering the top-view slice */
        int         level = hv->level[k];
        GLenum      error;

        if (hv->dim[k] == 0)        continue;
        
        glBindFramebuffer(GL_FRAMEBUFFER, hv->fb[k]);      GLCHECK();
        glFramebufferTextureLayer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, hv->tex[k], 0, level); GLCHECK();

        /* ...check the status of the framebuffer */
        if ((error = glCheckFramebufferStatus(GL_FRAMEBUFFER)) != GL_FRAMEBUFFER_COMPLETE)
        {
            TRACE(ERROR, _x("framebuffer %u state error: %X"), hv->fb[k], error);
            continue;
        }

        glViewport(0, 0, bv->dim[k][0], bv->dim[k][1]); GLCHECK();

        mesh_render_fb(&hv->mesh, texture[k], k, &CC[k]);

        TRACE(0, _b("cam-%u: render into %u:%u[%d]: %d*%d"), k, hv->fb[k], hv->tex[k], level, bv->dim[k][0], bv->dim[k][1]);
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    
#ifdef BUILD_NATIVE
    if (hv->dbg.info.width)
    {
        /* ...create debug mesh */
        hv_dbg_mesh_create(&hv->dbg, cfg, 32 + 1, 64 + 1/*(hv->dbg.info.width / 3 + 8) / 8, (hv->dbg.info.height + 8) / 8*/);

        dbg_window_unlock(&hv->dbg.dbg);
        
        /* ...force mesh update */
        dbg_window_update(&hv->dbg.dbg);
    }
#endif

    return 0;
}

/**
 * @brief   Process HV-buffers update
 *
 * @param   hv[in]          Historical view data
 * @param   cfg[in]         Global configuration data
 * @param   vehicle[in]     Vehicle-state data
 * @param   texture[in]     Input textures array
 *
 * @return                  Negative on failure
 */
int hv_process_work(hv_data_t *hv, cfg_data_t *cfg, vehicle_state_t *vehicle, texture_data_t **texture, float32_t (*CC)[3][3])
{
    cfg_bv_mesh_t  *bv = &cfg->hv;
    float32_t       cc[4][2][3];
    int             k;

    /* ...process vehicle pose change */
    float32_t      *pose = vehicle->pose;
    
#ifdef BUILD_NATIVE
    if (hv->dbg.info.width)
    {
        dbg_window_lock(&hv->dbg.dbg);
        hv_dbg_dump_pulse(&hv->dbg, vehicle->wheel_pulse_count);
        hv_dbg_dump_pose(&hv->dbg, pose);
    }
#endif

    /* ...update current WCS-to-HCS matrix */
    float32x2x3_t   W2H = vld3_f32(pose);
    vst3_f32(hv->W2H, W2H);
    
    /* ...calculate current HCS-to-WCS matrix (inverse) */
    float32x2x3_t   H2W;
    H2W.val[0] = vtrn1_f32(W2H.val[0], W2H.val[1]);
    H2W.val[1] = vtrn2_f32(W2H.val[0], W2H.val[1]);
    H2W.val[2] = vneg_f32(W2H.val[2]);
    H2W.val[2] = vmla_lane_f32(vmul_lane_f32(H2W.val[0], H2W.val[2], 0), H2W.val[1], H2W.val[2], 1);

    /* ...get slices centers */
    float32_t   Xf = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + bv->front_blind_area;
    float32_t   Xc = (-cfg->vehicle.rear_overhang + cfg->vehicle.wheel_base + cfg->vehicle.front_overhang) * 0.5f;
    float32_t   Xr = -cfg->vehicle.rear_overhang - bv->rear_blind_area;

    float32_t   Yl = cfg->vehicle.width * 0.5f + bv->left_blind_area;
    float32_t   Yc = 0.0f;
    float32_t   Yr = -cfg->vehicle.width * 0.5f - bv->right_blind_area;

    float32x2x2_t   C[4];
    C[0].val[0] = __mk_float32x2(Xf + bv->slice_height_hor * 0.5f, Yc + bv->slice_width_hor * 0.5f);
    C[0].val[1] = __mk_float32x2(Xf + bv->slice_height_hor * 0.5f, Yc - bv->slice_width_hor * 0.5f);
    
    C[1].val[0] = __mk_float32x2(Xc - bv->slice_width_vert * 0.5f, Yl + bv->slice_height_vert * 0.5f);
    C[1].val[1] = __mk_float32x2(Xc + bv->slice_width_vert * 0.5f, Yl + bv->slice_height_vert * 0.5f);
    
    C[2].val[0] = __mk_float32x2(Xr - bv->slice_height_hor * 0.5f, Yc - bv->slice_width_hor * 0.5f);
    C[2].val[1] = __mk_float32x2(Xr - bv->slice_height_hor * 0.5f, Yc + bv->slice_width_hor * 0.5f);
    
    C[3].val[0] = __mk_float32x2(Xc + bv->slice_width_vert * 0.5f, Yr - bv->slice_height_vert * 0.5f);
    C[3].val[1] = __mk_float32x2(Xc - bv->slice_width_vert * 0.5f, Yr - bv->slice_height_vert * 0.5f);
    
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        uint32_t        n = hv->dim[k];
        uint32_t        level = hv->level[k];
        uint32_t        base = hv->base[k];
        float32x2x3_t   H2S;

        /* ...skip empty slices */
        if (n == 0)     continue;
        
        /* ...get base value of H2S for a camera */
        if (level != base)
        {
            float32x2x2_t   UV;
            
            /* ...get base slice matrix */
            H2S = vld3_f32(hv->H2S[k][base]);

            /* ...get slice reference points coordinates in base slice */
            UV = __mat2x3_mulvh(H2S, __mat2x3_mulvh(W2H, C[k]));

            /* ...get min/max shifts */
            float32x2_t     T0 = vabd_f32(UV.val[0], vmov_n_f32(0.5f));
            float32x2_t     T1 = vabd_f32(UV.val[1], vmov_n_f32(0.5f));

            T0 = vmax_f32(T0, T1);

            if (vget_lane_f32(T0, 1) > 0.5f || vget_lane_f32(T0, 0) > 0.65f)
            {
                /* ...advance base */
                hv->base[k] = level;

                /* ...increase amount of available slices */
                (hv->avail[k] < n ? hv->avail[k]++ : 0);

                k == 1 ? TRACE(1, _b("v=%f, level-up: %d (%d)"), vget_lane_f32(T0, 1), level, hv->avail[k]) : 0;
            }
            else if (vget_lane_f32(T0, 0) < 0.1f && vget_lane_f32(T0, 1) < 0.05f)
            {
                /* ...drop base level; update base */
                hv->level[k] = level = base;

                /* ...set new base */
                hv->avail[k]-- > 2 ? hv->base[k] = (base ? : n) - 1 : 0;
                
                /* ...reduce amount of available slices */
                //hv->avail[k] ? hv->avail[k]-- : 0;

                k == 1 ? TRACE(1, _b("v=%f, level-down: %d (%d)"), vget_lane_f32(T1, 1), level, hv->avail[k]) : 0;
            }
            else
            {
                k == 1 ? TRACE(1, _b("v=%f:%f, level: %d (%d)"), vget_lane_f32(T0, 1), vget_lane_f32(T1, 1), level, hv->avail[k]) : 0;
            }
                
#if 0            
            /* ...get min/max shifts */
            float32x2_t     T0 = vmin_f32(UV.val[0], UV.val[1]);
            float32x2_t     T1 = vmax_f32(UV.val[0], UV.val[1]);

            if (vget_lane_f32(T0, 1) < 0.0f || vget_lane_f32(T1, 1) > 1.0f || fabsf(vget_lane_f32(T0, 0)) > 0.15f)
            {
                /* ...advance base */
                hv->base[k] = level;

                /* ...increase amount of available slices */
                (hv->avail[k] < n ? hv->avail[k]++ : 0);

                k == 1 ? TRACE(1, _b("v=%f, level-up: %d (%d)"), vget_lane_f32(T0, 1), level, hv->avail[k]) : 0;
            }
            else if (vget_lane_f32(T1, 1) > 1.0f)
            {
                /* ...drop base level; update base */
                hv->level[k] = level = base;

                /* ...set new base */
                hv->avail[k]-- > 2 ? hv->base[k] = (base ? : n) - 1 : 0;
                
                /* ...reduce amount of available slices */
                //hv->avail[k] ? hv->avail[k]-- : 0;

                k == 1 ? TRACE(1, _b("v=%f, level-down: %d (%d)"), vget_lane_f32(T1, 1), level, hv->avail[k]) : 0;
            }
            else
            {
                k == 1 ? TRACE(1, _b("v=%f:%f, level: %d (%d)"), vget_lane_f32(T0, 1), vget_lane_f32(T1, 1), level, hv->avail[k]) : 0;
            }
#endif            
        }
        else if (hv->avail[k] > 0)
        {
            /* ...advance level */
            (++level == n ? level = 0 : 0);

            /* ...save new level (start another base tracking) */
            hv->level[k] = level;

            /* ...mark we have a base set */
            //(hv->avail[k] < n ? hv->avail[k]++ : 0);
        }
        else
        {
            /* ...set first base */
            hv->avail[k] = 1;
        }

        BUG(level != hv->level[k], _x("break: %d != %d"), level, hv->level[k]);
        
        /* ...save current matrix at selected level */
        H2S = __mat2x3_mul(vld3_f32(hv->scm[k]), H2W);
        vst3_f32(hv->H2S[k][level], H2S);
    }

    /* ...set color-correction coefficients */
    if (CC != NULL)
    {
        memcpy(cc, CC, sizeof(cc));

        TRACE(0, _b("cc[0][0]: %f,%f,%f, cc[0][1]: %f,%f,%f"), cc[0][0][0], cc[0][0][1], cc[0][0][2], cc[0][1][0], cc[0][1][1], cc[0][1][2]);
        TRACE(0, _b("cc[1][0]: %f,%f,%f, cc[1][1]: %f,%f,%f"), cc[1][0][0], cc[1][0][1], cc[1][0][2], cc[1][1][0], cc[1][1][1], cc[1][1][2]);
        TRACE(0, _b("cc[2][0]: %f,%f,%f, cc[2][1]: %f,%f,%f"), cc[2][0][0], cc[2][0][1], cc[2][0][2], cc[2][1][0], cc[2][1][1], cc[2][1][2]);
        TRACE(0, _b("cc[3][0]: %f,%f,%f, cc[3][1]: %f,%f,%f"), cc[3][0][0], cc[3][0][1], cc[3][0][2], cc[3][1][0], cc[3][1][1], cc[3][1][2]);
    }
    else
    {
        memset(cc, 0, sizeof(cc));
    }

    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_BLEND);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);
    
    /* ...render HV-mesh for all cameras */
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        /* ...determine level for rendering the top-view slice */
        int         level = hv->level[k];
        GLenum      error;

        if (hv->dim[k] == 0)        continue;
        
        glBindFramebuffer(GL_FRAMEBUFFER, hv->fb[k]);      GLCHECK();
        glFramebufferTextureLayer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, hv->tex[k], 0, level); GLCHECK();

        /* ...check the status of the framebuffer */
        if ((error = glCheckFramebufferStatus(GL_FRAMEBUFFER)) != GL_FRAMEBUFFER_COMPLETE)
        {
            TRACE(ERROR, _x("framebuffer %u state error: %X"), hv->fb[k], error);
            continue;
        }

        glViewport(0, 0, bv->dim[k][0], bv->dim[k][1]); GLCHECK();

        mesh_render_fb(&hv->mesh, texture[k], k, &CC[k]);

        TRACE(0, _b("cam-%u: render into %u:%u[%d]: %d*%d"), k, hv->fb[k], hv->tex[k], level, bv->dim[k][0], bv->dim[k][1]);
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    
#ifdef BUILD_NATIVE
    if (hv->dbg.info.width)
    {
        /* ...create debug mesh */
        hv_dbg_mesh_create(&hv->dbg, cfg, 32 + 1, 64 + 1/*(hv->dbg.info.width / 3 + 8) / 8, (hv->dbg.info.height + 8) / 8*/);

        dbg_window_unlock(&hv->dbg.dbg);
        
        /* ...force mesh update */
        dbg_window_update(&hv->dbg.dbg);
    }
#endif

    return 0;
}

/**
 * @brief   Test if point-pair in HCS is within the slice
 *
 * @param   h2s[in]         Slice H2S matrix pointer
 * @param   P[in]           Points in HCS: [0]:X0,Y0, [1]:X1,Y1
 * @param   UV[out]         Points coordinates in slice coordinates
 *
 * @return                  Non-zero if both points are inside slice
 */
static inline __attribute__((__always_inline__))
int hv_test_slice(float32_t *h2s, float32x2x2_t P, float32x2x2_t *UV)
{
    float32x2x3_t   H2S = vld3_f32(h2s);
    float32x2_t     half = vmov_n_f32(0.5f);
    float32x2_t     T;
    
    *UV = __mat2x3_mulvh(H2S, P);
    T = vmax_f32(vabd_f32(UV->val[0], half), vabd_f32(UV->val[1], half));

    return vget_lane_u64(vreinterpret_u64_u32(vcge_f32(T, half)), 0) == 0LU;
}

int hv_process(hv_data_t *hv, cfg_data_t *cfg, vehicle_state_t *vehicle, texture_data_t **texture, float32_t (*CC)[3][3])
{
    cfg_bv_mesh_t  *bv = &cfg->hv;
    float32_t       cc[4][2][3];
    int             k;

    /* ...process vehicle pose change */
    float32_t      *pose = vehicle->pose;
    
#ifdef BUILD_NATIVE
    if (hv->dbg.info.width)
    {
        dbg_window_lock(&hv->dbg.dbg);
        hv_dbg_dump_pulse(&hv->dbg, vehicle->wheel_pulse_count);
        hv_dbg_dump_pose(&hv->dbg, pose);
    }
#endif

    /* ...update current WCS-to-HCS matrix */
    float32x2x3_t   W2H = vld3_f32(pose);
    vst3_f32(hv->W2H, W2H);
    
    /* ...calculate current HCS-to-WCS matrix (inverse) */
    float32x2x3_t   H2W;
    H2W.val[0] = vtrn1_f32(W2H.val[0], W2H.val[1]);
    H2W.val[1] = vtrn2_f32(W2H.val[0], W2H.val[1]);
    H2W.val[2] = vneg_f32(W2H.val[2]);
    H2W.val[2] = vmla_lane_f32(vmul_lane_f32(H2W.val[0], H2W.val[2], 0), H2W.val[1], H2W.val[2], 1);

    /* ...get slices centers */
    float32_t   Xf = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + bv->front_blind_area;
    float32_t   Xc = (-cfg->vehicle.rear_overhang + cfg->vehicle.wheel_base + cfg->vehicle.front_overhang) * 0.5f;
    float32_t   Xr = -cfg->vehicle.rear_overhang - bv->rear_blind_area;

    float32_t   Yl = cfg->vehicle.width * 0.5f + bv->left_blind_area;
    float32_t   Yc = 0.0f;
    float32_t   Yr = -cfg->vehicle.width * 0.5f - bv->right_blind_area;

    float32x2x2_t   C[4];
    C[0].val[0] = __mk_float32x2(Xf + bv->slice_height_hor * 0.5f, Yc + bv->slice_width_hor * 0.5f - bv->slice_height_hor * 0.5f);
    C[0].val[1] = __mk_float32x2(Xf + bv->slice_height_hor * 0.5f, Yc - bv->slice_width_hor * 0.5f + bv->slice_height_hor * 0.5f);
    
    C[1].val[0] = __mk_float32x2(Xc - bv->slice_width_vert * 0.5f + bv->slice_height_vert * 0.5f, Yl + bv->slice_height_vert * 0.5f);
    C[1].val[1] = __mk_float32x2(Xc + bv->slice_width_vert * 0.5f - bv->slice_height_vert * 0.5f, Yl + bv->slice_height_vert * 0.5f);
    
    C[2].val[0] = __mk_float32x2(Xr - bv->slice_height_hor * 0.5f, Yc - bv->slice_width_hor * 0.5f + bv->slice_height_hor * 0.5f);
    C[2].val[1] = __mk_float32x2(Xr - bv->slice_height_hor * 0.5f, Yc + bv->slice_width_hor * 0.5f - bv->slice_height_hor * 0.5f);
    
    C[3].val[0] = __mk_float32x2(Xc + bv->slice_width_vert * 0.5f - bv->slice_height_vert * 0.5f, Yr - bv->slice_height_vert * 0.5f);
    C[3].val[1] = __mk_float32x2(Xc - bv->slice_width_vert * 0.5f + bv->slice_height_vert * 0.5f, Yr - bv->slice_height_vert * 0.5f);
    
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        uint32_t        n = hv->dim[k];
        uint32_t        level = hv->level[k];
        uint32_t        base = hv->base[k];
        float32x2x3_t   H2S;

        /* ...skip empty slices */
        if (n == 0)     continue;
        
        /* ...get base value of H2S for a camera */
        if (level != base)
        {
            float32x2x2_t   P = __mat2x3_mulvh(W2H, C[k]);
            int             base2 = (base ? : n) - 1;
            float32x2x2_t   UV;

            /* ...check if the control point is out of base slice */
            if (!hv_test_slice(hv->H2S[k][base], P, &UV))
            {
                int     advance = 0;
                
                (k == 0 ? TRACE(1, _b("UV=[0]:%f,%f, [1]:%f,%f"), __float32x2_p(UV.val[0]), __float32x2_p(UV.val[1])) : 0);
                
                /* ...check if we need to advance or drop level */
                if (k == 0 || k == 2)
                {
                    float32x2_t     V = vtrn2_f32(UV.val[0], UV.val[1]);

                    if (vget_lane_u64(vreinterpret_u64_u32(vcle_f32(V, vmov_n_f32(0.0f))), 0) != 0LU)
                    {
                        advance = 1;
                    }
                    else
                    {
                        advance = 0;
                    }
                }
                else
                {
                    if (hv->avail[k] >= 2 && hv_test_slice(hv->H2S[k][base2], P, &UV) != 0)
                    {
                        advance = 0;
                    }
                    else
                    {
                        advance = 1;
                    }
                }

                if (advance == 0)
                {
                    /* ...drop base level */
                    hv->level[k] = level = base;

                    /* ...set new base */
                    --hv->avail[k] > 0 ? hv->base[k] = base2 : 0;

                    k == 0 ? TRACE(1, _b("UV=[0]:%f,%f, [1]:%f,%f, level-down: %d (%d)"), __float32x2_p(UV.val[0]), __float32x2_p(UV.val[1]), level, hv->avail[k]) : 0;
                }
                else
                {
                    /* ...advance base */
                    hv->base[k] = level;

                    /* ...increase amount of available slices */
                    //(hv->avail[k] < n ? hv->avail[k]++ : 0);

                    k == 0 ? TRACE(1, _b("UV=[0]:%f,%f, [1]:%f,%f, level-up: %d (%d)"), __float32x2_p(UV.val[0]), __float32x2_p(UV.val[1]), level, hv->avail[k]) : 0;
                }
            }
            else
            {
                k == 0 ? TRACE(1, _b("UV=[0]:%f,%f, [1]:%f,%f, level: %d (%d)"), __float32x2_p(UV.val[0]), __float32x2_p(UV.val[1]), level, hv->avail[k]) : 0;
            }
        }
        else if (hv->avail[k] > 0)
        {
            /* ...advance level */
            (++level == n ? level = 0 : 0);

            /* ...save new level (start another base tracking) */
            hv->level[k] = level;

            /* ...mark we have a base set */
            (hv->avail[k] < n ? hv->avail[k]++ : 0);
        }
        else
        {
            //hv->level[k] = (level + 1 < n ? level + 1 : 0);
            
            /* ...set first base */
            hv->avail[k] = 1;
        }

        //BUG(level != hv->level[k], _x("break: %d != %d"), level, hv->level[k]);
        
        /* ...save current matrix at selected level */
        H2S = __mat2x3_mul(vld3_f32(hv->scm[k]), H2W);
        vst3_f32(hv->H2S[k][level], H2S);
    }

    /* ...set color-correction coefficients */
    if (CC != NULL)
    {
        memcpy(cc, CC, sizeof(cc));

        TRACE(0, _b("cc[0][0]: %f,%f,%f, cc[0][1]: %f,%f,%f"), cc[0][0][0], cc[0][0][1], cc[0][0][2], cc[0][1][0], cc[0][1][1], cc[0][1][2]);
        TRACE(0, _b("cc[1][0]: %f,%f,%f, cc[1][1]: %f,%f,%f"), cc[1][0][0], cc[1][0][1], cc[1][0][2], cc[1][1][0], cc[1][1][1], cc[1][1][2]);
        TRACE(0, _b("cc[2][0]: %f,%f,%f, cc[2][1]: %f,%f,%f"), cc[2][0][0], cc[2][0][1], cc[2][0][2], cc[2][1][0], cc[2][1][1], cc[2][1][2]);
        TRACE(0, _b("cc[3][0]: %f,%f,%f, cc[3][1]: %f,%f,%f"), cc[3][0][0], cc[3][0][1], cc[3][0][2], cc[3][1][0], cc[3][1][1], cc[3][1][2]);
    }
    else
    {
        memset(cc, 0, sizeof(cc));
    }

    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_BLEND);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);
    
    /* ...render HV-mesh for all cameras */
    for (k = 0; k < SV_CAMERAS_NUMBER; k++)
    {
        /* ...determine level for rendering the top-view slice */
        int         level = hv->level[k];
        GLenum      error;

        if (hv->dim[k] == 0)        continue;
        
        glBindFramebuffer(GL_FRAMEBUFFER, hv->fb[k]);      GLCHECK();
        glFramebufferTextureLayer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, hv->tex[k], 0, level); GLCHECK();

        /* ...check the status of the framebuffer */
        if ((error = glCheckFramebufferStatus(GL_FRAMEBUFFER)) != GL_FRAMEBUFFER_COMPLETE)
        {
            TRACE(ERROR, _x("framebuffer %u state error: %X"), hv->fb[k], error);
            continue;
        }

        glViewport(0, 0, bv->dim[k][0], bv->dim[k][1]); GLCHECK();

        mesh_render_fb(&hv->mesh, texture[k], k, &CC[k]);

        TRACE(0, _b("cam-%u: render into %u:%u[%d]: %d*%d"), k, hv->fb[k], hv->tex[k], level, bv->dim[k][0], bv->dim[k][1]);
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    
#ifdef BUILD_NATIVE
    if (hv->dbg.info.width)
    {
        /* ...create debug mesh */
        hv_dbg_mesh_create(&hv->dbg, cfg, 32 + 1, 64 + 1/*(hv->dbg.info.width / 3 + 8) / 8, (hv->dbg.info.height + 8) / 8*/);

        dbg_window_unlock(&hv->dbg.dbg);
        
        /* ...force mesh update */
        dbg_window_update(&hv->dbg.dbg);
    }
#endif

    return 0;
}

/**
 * @brief   Find slice in camera "k" that has a quad
 */
static inline __attribute__((__always_inline__))
float32x2x2_t hv_map_slice_2(hv_data_t *hv, int k, int j, float32x2x2_t Q)
{
    float32x2x3_t   H2S = vld3_f32(hv->H2S[k][j]);

    return __mat2x3_mulvh(H2S, Q);
}

/**
 * @brief   Find slice in camera "k" that has a quad
 */
static inline __attribute__((__always_inline__))
float32x2x4_t hv_map_quad(hv_data_t *hv, int k, int j, float32x2x2_t Q01, float32x2x2_t Q23)
{
    float32x2x3_t   H2S = vld3_f32(hv->H2S[k][j]);

    //return __mat2x3_mulvh_4(H2S, Q);
    float32x2x4_t   UV;
    
    float32x2x2_t   t = __mat2x3_mulvh(H2S, Q01);
    UV.val[0] = t.val[0], UV.val[1] = t.val[1];

    t = __mat2x3_mulvh(H2S, Q23);
    UV.val[2] = t.val[0], UV.val[3] = t.val[1];

    return UV;
}


/**
 * @brief   Find slice in camera "k" that has a quad
 */
static inline int hv_map_slice(hv_data_t *hv, int k, float32x2x2_t Q, float32x2x2_t *R)
{
    int     n = hv->dim[k];
    int     j = hv->base[k];
    int     m = hv->avail[k];

    while (m-- > 0)
    {
        float32x2x2_t   UV = hv_map_slice_2(hv, k, j, Q);
        float32x2_t     T0 = vmin_f32(UV.val[0], UV.val[1]);
        float32x2_t     T1 = vmax_f32(UV.val[0], UV.val[1]);

        if (0 && k == 0 && m == hv->avail[k] - 1) {
            
        TRACE(1, _b("UV=[0]:%f,%f, [1]:%f,%f"), __float32x2_p(UV.val[0]), __float32x2_p(UV.val[1]));
        TRACE(1, _b("T0:%f,%f, T1:%f,%f"), __float32x2_p(T0), __float32x2_p(T1));
        }
        
        uint32x2_t      r = vorr_u32(vcge_f32(T1, vmov_n_f32(1.0f)), vcle_f32(T0, vmov_n_f32(0.0f)));

        if ((uint64_t)vget_lane_u64(vreinterpret_u64_u32(r), 0) == 0LU)
        {
            /* ...quad is found in level "level" of camera "k" */
            *R = UV;
            return j;
        }

        j = (j ? : n) - 1;
    }

    return -1;
}

/**
 * @brief   Find slice in camera "k" that has a quad
 */
static inline __attribute__((__always_inline__))
int hv_map_slice_base(hv_data_t *hv, int k, float32x2x2_t Q, float32x2x2_t *R0, float32x2x2_t *R1, float32x2_t *W)
{
    int     n = hv->dim[k];
    int     j = hv->base[k];
    int     m = hv->avail[k];

    while (--m > 1)
    {
        float32x2x2_t   UV = hv_map_slice_2(hv, k, j, Q);
        float32x2_t     T0 = vmin_f32(UV.val[0], UV.val[1]);
        float32x2_t     T1 = vmax_f32(UV.val[0], UV.val[1]);

        uint32x2_t      r = vorr_u32(vcge_f32(T1, vmov_n_f32(1.0f)), vcle_f32(T0, vmov_n_f32(0.0f)));

        if ((uint64_t)vget_lane_u64(vreinterpret_u64_u32(r), 0) == 0LU)
        {
            int     j1 = (j ? : n) - 1;
            
            /* ...quad is found in level "level" of camera "k" */
            *R0 = UV;

            UV = hv_map_slice_2(hv, k, j1, Q);
            T0 = vmin_f32(UV.val[0], UV.val[1]);
            T1 = vmax_f32(UV.val[0], UV.val[1]);
            r = vorr_u32(vcge_f32(T1, vmov_n_f32(1.0f)), vcle_f32(T0, vmov_n_f32(0.0f)));

            if ((uint64_t)vget_lane_u64(vreinterpret_u64_u32(r), 0) == 0LU)
            {
                *R1 = UV;
                
                /* ...blending is permitted */
                float32x2_t v0 = vtrn2_f32(R0->val[0], R0->val[1]);
                float32x2_t v1 = vtrn2_f32(R1->val[0], R1->val[1]);
                
                *W = vdiv_f32(v0, vadd_f32(v0, v1));
            }
            else
            {
                *W = vmov_n_f32(1.0f);
            }
            
            return j;
        }

        j = (j ? : n) - 1;
    }

    return -1;
}

/**
 * @brief   Find slice in camera "k" that has a quad
 */
static inline __attribute__((__always_inline__))
int hv_map_slice_base_2(hv_data_t *hv, int k, float32x2x2_t Q01, float32x2x2_t Q23, float32x2x2_t *R01, float32x2x2_t *R23)
{
    int     n = hv->dim[k];
    int     j = hv->level[k];
    int     m = hv->avail[k];

    while (m-- > 0)
    {
        float32x2x4_t   UV = hv_map_quad(hv, k, j, Q01, Q23);
        float32x2_t     T0 = vmin_f32(vmin_f32(vmin_f32(UV.val[0], UV.val[1]), UV.val[2]), UV.val[3]);
        float32x2_t     T1 = vmax_f32(vmax_f32(vmax_f32(UV.val[0], UV.val[1]), UV.val[2]), UV.val[3]);

        uint32x2_t      r = vorr_u32(vcge_f32(T1, vmov_n_f32(1.0f)), vcle_f32(T0, vmov_n_f32(0.0f)));

        if ((uint64_t)vget_lane_u64(vreinterpret_u64_u32(r), 0) == 0LU)
        {           
            /* ...quad is found in level "j" of camera "k" */
            R01->val[0] = UV.val[0];
            R01->val[1] = UV.val[1];
            R23->val[0] = UV.val[2];
            R23->val[1] = UV.val[3];
            
            return j;
        }

        j = (j ? : n) - 1;
    }

    return -1;
}

/**
 * @brief   Find slice in camera "k" that has a quad
 */
static inline __attribute__((__always_inline__))
int hv_map_slice_base_3(hv_data_t *hv, int k, int j, float32x2x2_t Q01, float32x2x2_t Q23, float32x2x2_t *R01, float32x2x2_t *R23)
{
    int     n = hv->dim[k];

    j = (j ? : n) - 1;
    
    int     m = hv->avail[k] - (hv->level[k] - j + n) % n;

    while (m-- > 0)
    {
        float32x2x4_t   UV = hv_map_quad(hv, k, j, Q01, Q23);
        float32x2_t     T0 = vmin_f32(vmin_f32(vmin_f32(UV.val[0], UV.val[1]), UV.val[2]), UV.val[3]);
        float32x2_t     T1 = vmax_f32(vmax_f32(vmax_f32(UV.val[0], UV.val[1]), UV.val[2]), UV.val[3]);

        uint32x2_t      r = vorr_u32(vcge_f32(T1, vmov_n_f32(1.0f)), vcle_f32(T0, vmov_n_f32(0.0f)));

        if ((uint64_t)vget_lane_u64(vreinterpret_u64_u32(r), 0) == 0LU)
        {           
            /* ...quad is found in level "j" of camera "k" */
            R01->val[0] = UV.val[0];
            R01->val[1] = UV.val[1];
            R23->val[0] = UV.val[2];
            R23->val[1] = UV.val[3];
            
            return j;
        }

        j = (j ? : n) - 1;
    }

    return -1;
}

static inline __attribute__((__always_inline__, __gnu_inline__))
float32x4x3_t hv_pack_buffer(float32x2x2_t XY, const int lane, float32x2x2_t R, int j, float32_t q)
{
    float32x2_t     X = vdup_lane_f32(XY.val[0], lane);
    float32x2_t     Y = XY.val[1];
    float32x2_t     J = vdup_n_f32((float32_t)j);
    float32x2_t     Q = vdup_n_f32(q);
    
    /* ...create two vertices in interleaved order:
     * [0]: X0:V0:X0:V1
     * [1]: Y0:J0:Y1:J0
     * [2]: U0:q0:U1:q0
     */
    float32x4x3_t   B;
    B.val[0] = vcombine_f32(vtrn2_f32(X, R.val[0]), vtrn2_f32(X, R.val[1]));
    B.val[1] = vcombine_f32(vtrn1_f32(Y, J), vtrn2_f32(Y, J));
    B.val[2] = vcombine_f32(vtrn1_f32(R.val[0], Q), vtrn1_f32(R.val[1], Q));

    return B;
}

static inline __attribute__((__always_inline__, __gnu_inline__))
float32x4x3_t hv_pack_buffer_2(float32x2x2_t XY, const int lane, float32x2x2_t R, int j, float32x2_t Q)
{
    float32x2_t     X = vdup_lane_f32(XY.val[0], lane);
    float32x2_t     Y = XY.val[1];
    float32x2_t     J = vdup_n_f32((float32_t)j);
    float32x2_t     U = vtrn1_f32(R.val[0], R.val[1]);
    
    /* ...create two vertices in interleaved order:
     * [0]: X0:V0:X0:V1
     * [1]: Y0:J0:Y1:J0
     * [2]: U0:q0:U1:q1
     */
    float32x4x3_t   B;
    B.val[0] = vcombine_f32(vtrn2_f32(X, R.val[0]), vtrn2_f32(X, R.val[1]));
    B.val[1] = vcombine_f32(vtrn1_f32(Y, J), vtrn2_f32(Y, J));
    B.val[2] = vcombine_f32(vtrn1_f32(U, Q), vtrn2_f32(U, Q));

    return B;
}

/**
 * @brief   Encode quad given two point-pairs for a single camera / slice
 *
 * @param   hv[in]          Historical view data
 * @param   P[in]           Display quad coordinates: [0]={X0,X1}, [1]={Y0,Y1}
 * @param   K[in]           Camera id
 * @param   J[in]           Slice id
 * @param   R01[in]         Points 0 & 1 UV-coordinates: [0]={U00,V00}, [1]={U10,V10}
 * @param   R23[in]         Points 2 & 3 UV-coordinates: [0]={U01,V01}, [1]={U11,V11}
 * @param   q0[in]          Blending weight for points 0 & 1
 * @param   q1[in]          Blending weight for points 2 & 3
 */
static inline __attribute__((__always_inline__))
int hv_quad_encode(
    vbo_dynarray_t  *vbo,
    float32x2x2_t XY,
    int J,
    float32x2x2_t R01,
    float32x2x2_t R23,
    float32_t q0,
    float32_t q1)
{
    hv_vertex_t    *v;

    /* ...add 6 vertices (two triangles) */
    CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(hv_vertex_t), 6), -1);

    /* ...pack points 0&1 into buffer:
     * [0]: X0:V0:X0:V1
     * [1]: Y0:J0:Y1:J0
     * [2]: U0:q0:U1:q0
     */
    float32x4x3_t   B01 = hv_pack_buffer(XY, 0, R01, J, q0);

    TRACE(0, _b("B01: [0]=%f,%f,%f,%f, [1]=%f,%f,%f,%f, [2]=%f,%f,%f,%f"), __float32x4_p(B01.val[0]), __float32x4_p(B01.val[1]), __float32x4_p(B01.val[2]));
    
    /* ...pack points 2&3 into buffer:
     * [0]: X1:V2:X1:V3
     * [1]: Y0:J0:Y1:J0
     * [2]: U2:q1:U3:q1
     */
    float32x4x3_t   B23 = hv_pack_buffer(XY, 1, R23, J, q1);

    TRACE(0, _b("B23: [0]=%f,%f,%f,%f, [1]=%f,%f,%f,%f, [2]=%f,%f,%f,%f"), __float32x4_p(B23.val[0]), __float32x4_p(B23.val[1]), __float32x4_p(B23.val[2]));

    /* ...make a triangle of points {0},{1},{2} and {2},{1},{3}; place points {0},{1} first
     * [0]: X0:V0:X1:V1
     * [1]: Y0:K0:Y1:K1
     * [2]: U0:q0:U1:q1
     */
    vst3q_f32(*v, B01);
    v += 2;

    /* ...next two points to store are {2}, {2}:
     * [0]: X2:V2:X2:V2
     * [1]: Y2:K2:Y2:K2
     * [2]: U2:q2:U2:q2
     */
    float32x4x3_t   B22;
    B22.val[0] = vcombine_f32(vget_low_f32(B23.val[0]), vget_low_f32(B23.val[0]));
    B22.val[1] = vcombine_f32(vget_low_f32(B23.val[1]), vget_low_f32(B23.val[1]));
    B22.val[2] = vcombine_f32(vget_low_f32(B23.val[2]), vget_low_f32(B23.val[2]));
    vst3q_f32(*v, B22);
    v += 2;

    /* ...next two pointsa are {1},{3}:
     * [0]: X1:V1:X3:V3
     * [1]: Y1:K1:Y3:K3
     * [2]: U1:q1:U3:q3
     */
    float32x4x3_t   B13;
    B13.val[0] = vcombine_f32(vget_high_f32(B01.val[0]), vget_high_f32(B23.val[0]));
    B13.val[1] = vcombine_f32(vget_high_f32(B01.val[1]), vget_high_f32(B23.val[1]));
    B13.val[2] = vcombine_f32(vget_high_f32(B01.val[2]), vget_high_f32(B23.val[2]));
    vst3q_f32(*v, B13);
    v += 2;
    
    return 0;
}

static inline __attribute__((__always_inline__))
int hv_quad_encode_2(
    vbo_dynarray_t  *vbo,
    float32x2x2_t XY,
    int J,
    float32x2x2_t R01,
    float32x2x2_t R23,
    float32x2_t Q01,
    float32x2_t Q23)
{
    hv_vertex_t    *v;

    /* ...add 6 vertices (two triangles) */
    CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(hv_vertex_t), 6), -1);

    /* ...pack points 0&1 into buffer:
     * [0]: X0:V0:X0:V1
     * [1]: Y0:J0:Y1:J0
     * [2]: U0:q0:U1:q1
     */
    float32x4x3_t   B01 = hv_pack_buffer_2(XY, 0, R01, J, Q01);

    TRACE(0, _b("B01: [0]=%f,%f,%f,%f, [1]=%f,%f,%f,%f, [2]=%f,%f,%f,%f"), __float32x4_p(B01.val[0]), __float32x4_p(B01.val[1]), __float32x4_p(B01.val[2]));
    
    /* ...pack points 2&3 into buffer:
     * [0]: X1:V2:X1:V3
     * [1]: Y0:J0:Y1:J0
     * [2]: U2:q1:U3:q1
     */
    float32x4x3_t   B23 = hv_pack_buffer_2(XY, 1, R23, J, Q23);

    TRACE(0, _b("B23: [0]=%f,%f,%f,%f, [1]=%f,%f,%f,%f, [2]=%f,%f,%f,%f"), __float32x4_p(B23.val[0]), __float32x4_p(B23.val[1]), __float32x4_p(B23.val[2]));

    /* ...make a triangle of points {0},{1},{2} and {2},{1},{3}; place points {0},{1} first
     * [0]: X0:V0:X1:V1
     * [1]: Y0:K0:Y1:K1
     * [2]: U0:q0:U1:q1
     */
    vst3q_f32(*v, B01);
    v += 2;

    /* ...next two points to store are {2}, {2}:
     * [0]: X2:V2:X2:V2
     * [1]: Y2:K2:Y2:K2
     * [2]: U2:q2:U2:q2
     */
    float32x4x3_t   B22;
    B22.val[0] = vcombine_f32(vget_low_f32(B23.val[0]), vget_low_f32(B23.val[0]));
    B22.val[1] = vcombine_f32(vget_low_f32(B23.val[1]), vget_low_f32(B23.val[1]));
    B22.val[2] = vcombine_f32(vget_low_f32(B23.val[2]), vget_low_f32(B23.val[2]));
    vst3q_f32(*v, B22);
    v += 2;

    /* ...next two pointsa are {1},{3}:
     * [0]: X1:V1:X3:V3
     * [1]: Y1:K1:Y3:K3
     * [2]: U1:q1:U3:q3
     */
    float32x4x3_t   B13;
    B13.val[0] = vcombine_f32(vget_high_f32(B01.val[0]), vget_high_f32(B23.val[0]));
    B13.val[1] = vcombine_f32(vget_high_f32(B01.val[1]), vget_high_f32(B23.val[1]));
    B13.val[2] = vcombine_f32(vget_high_f32(B01.val[2]), vget_high_f32(B23.val[2]));
    vst3q_f32(*v, B13);
    v += 2;
    
    return 0;
}

/**
 * @brief   Create HV-mesh for single strip
 *
 * @param   hv[in]      Historical view data
 * @param   vbo[in]     Mesh VBO array
 * @param   v[in]       World-coordinates of the points in a strip
 * @param   x[in]       Strip origin {x0,y0}
 * @param   d[in]       Quad dimensions {dx, dy}
 * @param   n[in]       Number of point-pairs in a strip
 */
int hv_mesh_create_strip_3(hv_data_t *hv, vbo_dynarray_t *vbo, float32_t (*v)[3], float32_t *x, float32_t *d, int32_t n)
{
    int32_t         K = -1, k;
    int32_t         J = -1, j;
    float32x2x2_t   Q01, Q23;
    float32x2x2_t   R01, R23;
    float32x2x2_t   XY;
    int32_t         i;

    /* ...compiler issue... */
    Q01.val[0] = Q01.val[1] = vdup_n_f32(0.0f);
    R01.val[0] = R01.val[1] = vdup_n_f32(0.0f);
    
    /* ...load quad dimensions {dx, dy} */
    float32x2_t D = vld1_f32(d);

    /* ...load initial quad coordinate: {x0, y0} */
    float32x2_t P0 = vld1_f32(x);

    /* ...calculate quad corner: {x1, y1} */
    float32x2_t P1 = vadd_f32(P0, D);

    /* ...reorder points: [0]: {x0, x1}, [1]: {y0, y1} */
    XY.val[0] = vtrn1_f32(P0, P1);
    XY.val[1] = vtrn2_f32(P0, P1);

    /* ...set delta to {dx, dx} */
    D = vdup_lane_f32(D, 0);
    
    /* ...process all point-pairs in a strip */
    for (i = 0; i < n; i++)
    {
        float32x2x3_t   P = vld3_f32(*v);

        /* ...reorder point coordinates: [0]:X0,Y0, [1]:X1,Y1 */
        Q23.val[0] = vtrn1_f32(P.val[0], P.val[1]);
        Q23.val[1] = vtrn2_f32(P.val[0], P.val[1]);

        TRACE(0, _b("P=[0]:%f,%f, [1]:%f,%f"), __float32x2_p(P.val[0]), __float32x2_p(P.val[1]));
        TRACE(0, _b("Q=[0]:%f,%f, [1]:%f,%f"), __float32x2_p(Q23.val[0]), __float32x2_p(Q23.val[1]));
        
        /* ...find mapping for a quad in cameras */
        if ((j = hv_map_slice(hv, SV_CAMERA_FRONT, Q23, &R23)) >= 0)
        {
            k = SV_CAMERA_FRONT;
        }
        else if ((j = hv_map_slice(hv, SV_CAMERA_REAR, Q23, &R23)) >= 0)
        {
            k = SV_CAMERA_REAR;
        }
        else if ((j = hv_map_slice(hv, SV_CAMERA_LEFT, Q23, &R23)) >= 0)
        {
            k = SV_CAMERA_LEFT;
        }
        else if ((j = hv_map_slice(hv, SV_CAMERA_RIGHT, Q23, &R23)) >= 0)
        {
            k = SV_CAMERA_RIGHT;
        }
        else
        {
            R23.val[0] = R23.val[1] = vdup_n_f32(0.0f);
            k = -1;
        }

        0 && k == 0 ? TRACE(1, _b("XY=[0]:%f,%f, [1]:%f,%f, strip[%d]: k=%d,j=%d"), __float32x2_p(XY.val[0]), __float32x2_p(XY.val[1]), i, k, j) : 0;
        
        /* ...encode quads as needed */
        if (i > 0)
        {
            if (k == K && j == J)
            {
                /* ...quad completely resides in slice[k][j] */
                if (K >= 0)
                {
                    if (1 && hv->avail[K] > 2)
                    {

                        J = (J ? : hv->dim[K]) - 1;

                        float32x2x2_t   r01 = hv_map_slice_2(hv, K, J, Q01);
                        float32x2x2_t   r23 = hv_map_slice_2(hv, K, J, Q23);

                        float32x2_t     T0 = vmin_f32(vmin_f32(vmin_f32(r01.val[0], r01.val[1]), r23.val[0]), r23.val[1]);
                        float32x2_t     T1 = vmax_f32(vmax_f32(vmax_f32(r01.val[0], r01.val[1]), r23.val[0]), r23.val[1]);

                        uint32x2_t      r = vorr_u32(vcge_f32(T1, vmov_n_f32(1.0f)), vcle_f32(T0, vmov_n_f32(0.0f)));

                        if ((uint64_t)vget_lane_u64(vreinterpret_u64_u32(r), 0) == 0LU)
                        {
                            float32_t   q0 = 0.7f;
                            CHK_API(hv_quad_encode(&vbo[K], XY, j, R01, R23, q0, q0));

                            q0 = 1.0f - q0;
                            CHK_API(hv_quad_encode(&vbo[K], XY, J, r01, r23, q0, q0));
                        }
                        else
                        {
                            CHK_API(hv_quad_encode(&vbo[K], XY, j, R01, R23, 1.0f, 1.0f));
                        }
                    }
                    else
                    {
                        CHK_API(hv_quad_encode(&vbo[K], XY, J, R01, R23, 1.0f, 1.0f));
                    }
                }
            }
            else
            {
                /* ...quad is at the boundary of two different slices; add cross-fading */
                float32x2x2_t   R;

                if (0 && K >= 0)
                {
                    R = hv_map_slice_2(hv, K, J, Q23);
                    CHK_API(hv_quad_encode(&vbo[K], XY, J, R01, R, 0.8f, 0.2f));
                }

                if (0 && k >= 0)
                {
                    R = hv_map_slice_2(hv, k, j, Q01);
                    CHK_API(hv_quad_encode(&vbo[k], XY, j, R, R23, 1.0f, 1.0f));
                }
            }
        }

        /* ...advance to next point-pair in a strip */
        K = k, J = j, Q01 = Q23, R01 = R23;

        /* ...advance quad display coordinates */
        XY.val[0] = vadd_f32(XY.val[0], D);

        v += 2;
    }

    return 0;
}

/**
 * @brief   Create HV-mesh for single strip
 *
 * @param   hv[in]      Historical view data
 * @param   vbo[in]     Mesh VBO array
 * @param   v[in]       World-coordinates of the points in a strip
 * @param   x[in]       Strip origin {x0,y0}
 * @param   d[in]       Quad dimensions {dx, dy}
 * @param   n[in]       Number of point-pairs in a strip
 */
int hv_mesh_create_strip_2(hv_data_t *hv, vbo_dynarray_t *vbo, float32_t (*v)[3], float32_t *x, float32_t *d, int32_t n)
{
    int32_t         K = -1, k;
    int32_t         J = -1, j;
    float32x2x2_t   Q01, Q23;
    float32x2x2_t   R01, R23, r01, r23;
    float32x2_t     W01, W23;
    float32x2x2_t   XY;
    int32_t         i;

    /* ...compiler issue... */
    Q01.val[0] = Q01.val[1] = vdup_n_f32(0.0f);
    R01.val[0] = R01.val[1] = vdup_n_f32(0.0f);
    r01.val[0] = r01.val[1] = vdup_n_f32(0.0f);
    W01 = vdup_n_f32(0.0f);
    
    /* ...load quad dimensions {dx, dy} */
    float32x2_t D = vld1_f32(d);

    /* ...load initial quad coordinate: {x0, y0} */
    float32x2_t P0 = vld1_f32(x);

    /* ...calculate quad corner: {x1, y1} */
    float32x2_t P1 = vadd_f32(P0, D);

    /* ...reorder points: [0]: {x0, x1}, [1]: {y0, y1} */
    XY.val[0] = vtrn1_f32(P0, P1);
    XY.val[1] = vtrn2_f32(P0, P1);

    /* ...set delta to {dx, dx} */
    D = vdup_lane_f32(D, 0);
    
    /* ...process all point-pairs in a strip */
    for (i = 0; i < n; i++)
    {
        float32x2x3_t   P = vld3_f32(*v);

        /* ...reorder point coordinates: [0]:X0,Y0, [1]:X1,Y1 */
        Q23.val[0] = vtrn1_f32(P.val[0], P.val[1]);
        Q23.val[1] = vtrn2_f32(P.val[0], P.val[1]);

        TRACE(0, _b("P=[0]:%f,%f, [1]:%f,%f"), __float32x2_p(P.val[0]), __float32x2_p(P.val[1]));
        TRACE(0, _b("Q=[0]:%f,%f, [1]:%f,%f"), __float32x2_p(Q23.val[0]), __float32x2_p(Q23.val[1]));
        
        /* ...find mapping for a quad in cameras */
        if ((j = hv_map_slice_base(hv, SV_CAMERA_FRONT, Q23, &R23, &r23, &W23)) >= 0)
        {
            k = SV_CAMERA_FRONT;
        }
        else if ((j = hv_map_slice_base(hv, SV_CAMERA_REAR, Q23, &R23, &r23, &W23)) >= 0)
        {
            k = SV_CAMERA_REAR;
        }
        else if ((j = hv_map_slice_base(hv, SV_CAMERA_LEFT, Q23, &R23, &r23, &W23)) >= 0)
        {
            k = SV_CAMERA_LEFT;
        }
        else if ((j = hv_map_slice_base(hv, SV_CAMERA_RIGHT, Q23, &R23, &r23, &W23)) >= 0)
        {
            k = SV_CAMERA_RIGHT;
        }
        else
        {
            R23.val[0] = R23.val[1] = vdup_n_f32(0.0f);
            k = -1;
        }

        0 && k == 0 ? TRACE(1, _b("XY=[0]:%f,%f, [1]:%f,%f, strip[%d]: k=%d,j=%d"), __float32x2_p(XY.val[0]), __float32x2_p(XY.val[1]), i, k, j) : 0;
        
        /* ...encode quads as needed */
        if (i > 0)
        {
            if (k == K && j == J)
            {
                /* ...quad completely resides in slice[k][j] */
                if (K >= 0)
                {
                    CHK_API(hv_quad_encode_2(&vbo[K], XY, j, R01, R23, W01, W23));

                    J = (j ? : n) - 1;
                    
                    CHK_API(hv_quad_encode_2(&vbo[K], XY, J, r01, r23, vsub_f32(vmov_n_f32(1.0f), W01), vsub_f32(vmov_n_f32(1.0f), W23)));
                }
            }
            else
            {
                /* ...quad is at the boundary of two different slices; add cross-fading */
                float32x2x2_t   R;

                if (0 && K >= 0)
                {
                    R = hv_map_slice_2(hv, K, J, Q23);
                    CHK_API(hv_quad_encode(&vbo[K], XY, J, R01, R, 0.8f, 0.2f));
                }

                if (0 && k >= 0)
                {
                    R = hv_map_slice_2(hv, k, j, Q01);
                    CHK_API(hv_quad_encode(&vbo[k], XY, j, R, R23, 1.0f, 1.0f));
                }
            }
        }

        /* ...advance to next point-pair in a strip */
        K = k, J = j, Q01 = Q23, R01 = R23, r01 = r23, W01 = W23;

        /* ...advance quad display coordinates */
        XY.val[0] = vadd_f32(XY.val[0], D);

        v += 2;
    }

    return 0;
}

/**
 * @breif   Calculate blend ratio for two quads
 *
 * @param   R01[in]         First quad coordinates: {0,1}
 * @param   R23[in]         First quad coordinates: {2,3}
 * @param   r01[in]         Second quad coordinates: {0,1}
 * @param   r23[in]         Second quad coordinates: {2,3}
 *
 * @return                  Blend coefficients [0]={Q0,Q1}, [1]={Q2,Q3}
 */
static inline __attribute__((__always_inline__))
float32x2x2_t hv_calc_blend(float32x2x2_t R01, float32x2x2_t R23, float32x2x2_t r01, float32x2x2_t r23)
{
    float32x2_t     C = vmov_n_f32(0.5f);
    float32x2x2_t   W;

    /* ...{|Y0 - 0.5|,|Y1 - 0.5|}, {|y0 - 0.5|,|y1 - 0.5|} */
    float32x2_t     v0 = vabd_f32(vtrn2_f32(R01.val[0], R01.val[1]), C);
    float32x2_t     v1 = vabd_f32(vtrn2_f32(r01.val[0], r01.val[1]), C);
    
    /* ...found quad in next slide */
    W.val[0] = vdiv_f32(v1, vadd_f32(v0, v1));

    /* ...{|Y2 - 0.5|,|Y3 - 0.5|}, {|y2 - 0.5|,|y3 - 0.5|} */
    v0 = vabd_f32(vtrn2_f32(R23.val[0], R23.val[1]), C);
    v1 = vabd_f32(vtrn2_f32(r23.val[0], r23.val[1]), C);

    /* ...found quad in next slide */
    W.val[1] = vdiv_f32(v1, vadd_f32(v0, v1));

    return W;
}

/**
 * @brief   Create HV-mesh for single strip
 *
 * @param   hv[in]      Historical view data
 * @param   vbo[in]     Mesh VBO array
 * @param   v[in]       World-coordinates of the points in a strip
 * @param   x[in]       Strip origin {x0,y0}
 * @param   d[in]       Quad dimensions {dx, dy}
 * @param   n[in]       Number of point-pairs in a strip
 */
int hv_mesh_create_strip(hv_data_t *hv, vbo_dynarray_t *vbo, float32_t (*v)[3], float32_t *x, float32_t *d, int32_t n)
{
    int32_t         K = -1, k;
    int32_t         J = -1, j;
    float32x2x2_t   Q01, Q23;
    float32x2x2_t   R01, R23, r01, r23;
    float32x2_t     W01, W23;
    float32x2x2_t   XY;
    int32_t         i;

    /* ...compiler issue... */
    Q01.val[0] = Q01.val[1] = vdup_n_f32(0.0f);
    R01.val[0] = R01.val[1] = vdup_n_f32(0.0f);
    r01.val[0] = r01.val[1] = vdup_n_f32(0.0f);
    W01 = vdup_n_f32(0.0f);
    
    /* ...load quad dimensions {dx, dy} */
    float32x2_t D = vld1_f32(d);

    /* ...load initial quad coordinate: {x0, y0} */
    float32x2_t P0 = vld1_f32(x);

    /* ...calculate quad corner: {x1, y1} */
    float32x2_t P1 = vadd_f32(P0, D);

    /* ...reorder points: [0]: {x0, x1}, [1]: {y0, y1} */
    XY.val[0] = vtrn1_f32(P0, P1);
    XY.val[1] = vtrn2_f32(P0, P1);

    /* ...set delta to {dx, dx} */
    D = vdup_lane_f32(D, 0);

    float32x2x3_t   W2H = vld3_f32(hv->W2H);
    float32x2x3_t   P;

    P = vld3_f32(*v), v += 2;
    
    /* ...get first point-pair: [0]:X0,Y0, [1]:X1,Y1 */
    Q01.val[0] = vtrn1_f32(P.val[0], P.val[1]);
    Q01.val[1] = vtrn2_f32(P.val[0], P.val[1]);

    Q01 = __mat2x3_mulvh(W2H, Q01);
    
    /* ...process all point-pairs in a strip */
    for (i = 1; i < n; i++)
    {
        /* ...read next point-pair */
        P = vld3_f32(*v), v += 2;

        /* ...reorder point coordinates: [0]:X2,Y2, [1]:X3,Y3 */
        Q23.val[0] = vtrn1_f32(P.val[0], P.val[1]);
        Q23.val[1] = vtrn2_f32(P.val[0], P.val[1]);

        /* ...world-to-historical mapping */
        Q23 = __mat2x3_mulvh(W2H, Q23);

        /* ...find mapping for a quad in cameras */
        if ((j = hv_map_slice_base_2(hv, SV_CAMERA_FRONT, Q01, Q23, &R01, &R23)) >= 0)
        {
            k = SV_CAMERA_FRONT;
        }
        else if ((j = hv_map_slice_base_2(hv, SV_CAMERA_REAR, Q01, Q23, &R01, &R23)) >= 0)
        {
            k = SV_CAMERA_REAR;
        }
        else if ((j = hv_map_slice_base_2(hv, SV_CAMERA_LEFT, Q01, Q23, &R01, &R23)) >= 0)
        {
            k = SV_CAMERA_LEFT;
        }
        else if ((j = hv_map_slice_base_2(hv, SV_CAMERA_RIGHT, Q01, Q23, &R01, &R23)) >= 0)
        {
            k = SV_CAMERA_RIGHT;
        }
        else
        {
            R23.val[0] = R23.val[1] = vdup_n_f32(0.0f);
            k = -1;
        }

        /* ...encode quads as needed */
        if (k >= 0)
        {
            float32x2x2_t   r01, r23;
            float32x2x2_t   W;

            /* ...find second quad in the same camera */
            if ((J = hv_map_slice_base_3(hv, k, j, Q01, Q23, &r01, &r23)) >= 0)
            {
                K = k;
            }
            else if ((k & 1) == 0)
            {
                if ((J = hv_map_slice_base_2(hv, k ^ 1, Q01, Q23, &r01, &r23)) >= 0)
                {
                    K = k ^ 1;
                }
                else if ((J = hv_map_slice_base_2(hv, k ^ 3, Q01, Q23, &r01, &r23)) >= 0)
                {
                    K = k ^ 3;
                }
            }
            else
            {
                if ((J = hv_map_slice_base_2(hv, k ^ 2, Q01, Q23, &r01, &r23)) >= 0)
                {
                    K = k ^ 2;
                }
            }

            /* ...use blending if found */
            if (J >= 0)
            {
                W = hv_calc_blend(R01, R23, r01, r23);
                
                CHK_API(hv_quad_encode_2(&vbo[k], XY, j, R01, R23, W.val[0], W.val[1]));

                W.val[0] = vsub_f32(vmov_n_f32(1.0f), W.val[0]);
                W.val[1] = vsub_f32(vmov_n_f32(1.0f), W.val[1]);

                CHK_API(hv_quad_encode_2(&vbo[K], XY, J, r01, r23, W.val[0], W.val[1]));
            }
            else
            {
                W.val[0] = W.val[1] = vmov_n_f32(1.0f);

                CHK_API(hv_quad_encode_2(&vbo[k], XY, j, R01, R23, W.val[0], W.val[1]));
            }
        }

        /* ...advance to next point-pair in a strip */
        Q01 = Q23;
        
        /* ...advance quad display coordinates */
        XY.val[0] = vadd_f32(XY.val[0], D);
   }

    return 0;
}

/**
 * @brief   Reset HV-module operation
 *
 * @param   hv[in]          Historical view module data
 */
void hv_reset(hv_data_t *hv)
{
    /* ...clear all current levels */
    memset(hv->level, 0, sizeof(hv->level));
    memset(hv->base, 0, sizeof(hv->base));
    memset(hv->avail, 0, sizeof(hv->avail));
}

/**
 * @brief   Update slice WCS-to-UV conversion matrices
 *
 * @param   hv[in]          Historical view module data
 * @param   cfg[in]         Configuration data
 */
void hv_matrix_update(hv_data_t *hv, cfg_data_t *cfg)
{
    cfg_bv_mesh_t  *bv = &cfg->hv;

    float32_t   Xf = cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + bv->front_blind_area;
    float32_t   Xc = (-cfg->vehicle.rear_overhang + cfg->vehicle.wheel_base + cfg->vehicle.front_overhang) * 0.5f;
    float32_t   Xr = -cfg->vehicle.rear_overhang - bv->rear_blind_area;

    float32_t   Yl = cfg->vehicle.width * 0.5f + bv->left_blind_area;
    float32_t   Yc = 0.0f;
    float32_t   Yr = -cfg->vehicle.width * 0.5f - bv->right_blind_area;

    float32_t   SUfr = 1.0f / bv->slice_width_hor;
    float32_t   SVfr = 1.0f / bv->slice_height_hor;
    float32_t   SUlr = 1.0f / bv->slice_width_vert;
    float32_t   SVlr = 1.0f / bv->slice_height_vert;

    float32_t   scm[SV_CAMERAS_NUMBER][2 * 3] = {
        [SV_CAMERA_FRONT] = {
            0.0f, -SUfr, Yc * SUfr + 0.5f,
            -SVfr, 0.0f, Xf * SVfr + 1.0f,
        },
        [SV_CAMERA_LEFT] = {
            SUlr, 0.0f, Xc * -SUlr + 0.5f,
            0.0f, -SVlr, Yl * SVlr + 1.0f,
        },
        [SV_CAMERA_REAR] = {
            0.0f, SUfr, Yc * -SVfr + 0.5f,
            SVfr, 0.0f, Xr * -SVfr + 1.0f,
        },
        [SV_CAMERA_RIGHT] = {
            -SUlr, 0.0f, Xc * SUlr + 0.5f,
            0.0f, SVlr, Yr * -SVlr + 1.0f,
        },
    };

    /* ...save WCS-to-UV matrices for all slices (column-major) */
    memcpy(hv->scm, scm, sizeof(scm));

    if (1)
    {
        float32x2x3_t   M;
        float32x2x2_t   Q;
        float32x2x2_t   R;

        TRACE(1, _b("wheel-base: %f, front-overhang: %f, front-blind-area: %f"), cfg->vehicle.wheel_base, cfg->vehicle.front_overhang, bv->front_blind_area);

        M = vld3_f32(hv->scm[0]);
        Q.val[0] = __mk_float32x2(Xf + bv->slice_height_hor, Yc + bv->slice_width_hor * 0.5f);
        Q.val[1] = __mk_float32x2(Xf, Yc - bv->slice_width_hor * 0.5f);
        R = __mat2x3_mulvh(M, Q);
        TRACE(1, _b("slice: %f,%f"), bv->slice_width_hor, bv->slice_height_hor);
        TRACE(1, _b("M=[0]:%f,%f, [1]:%f,%f, [2]:%f,%f"), __float32x2_p(M.val[0]), __float32x2_p(M.val[1]), __float32x2_p(M.val[2]));
        TRACE(1, _b("Q=[0]:%f,%f, [1]:%f,%f"), __float32x2_p(Q.val[0]), __float32x2_p(Q.val[1]));
        TRACE(1, _b("front: %f,%f - %f,%f"), __float32x2_p(R.val[0]), __float32x2_p(R.val[1]));

        M = vld3_f32(hv->scm[1]);
        Q.val[0] = __mk_float32x2(Xc - bv->slice_width_vert * 0.5f, Yl + bv->slice_height_vert);
        Q.val[1] = __mk_float32x2(Xc + bv->slice_width_vert * 0.5f, Yl);
        R = __mat2x3_mulvh(M, Q);
        TRACE(1, _b("left: %f,%f - %f,%f"), __float32x2_p(R.val[0]), __float32x2_p(R.val[1]));

        M = vld3_f32(hv->scm[2]);
        Q.val[0] = __mk_float32x2(Xr - bv->slice_height_hor, Yc - bv->slice_width_hor * 0.5f);
        Q.val[1] = __mk_float32x2(Xr, Yc + bv->slice_width_hor * 0.5f);
        R = __mat2x3_mulvh(M, Q);
        TRACE(1, _b("rear: %f,%f - %f,%f"), __float32x2_p(R.val[0]), __float32x2_p(R.val[1]));

        M = vld3_f32(hv->scm[3]);
        Q.val[0] = __mk_float32x2(Xc + bv->slice_width_vert * 0.5f, Yr - bv->slice_height_vert);
        Q.val[1] = __mk_float32x2(Xc - bv->slice_width_vert * 0.5f, Yr);
        R = __mat2x3_mulvh(M, Q);
        TRACE(1, _b("right: %f,%f - %f,%f"), __float32x2_p(R.val[0]), __float32x2_p(R.val[1]));

        BUG(0, _x("break"));
    }
}

/**
 * @brief   Create HV-module
 *
 * @param   cfg[in]         Global configuration data
 *
 * @return                  Historical view data, or NULL on failure
 */
hv_data_t * hv_create(cfg_data_t *cfg)
{
    hv_data_t      *hv;
    cfg_bv_mesh_t  *bv = &cfg->hv;
    int             i;
    
    CHK_ERR(hv = calloc(1, sizeof(*hv)), NULL);

    /* ...update matrices */
    hv_matrix_update(hv, cfg);
    
    /* ...generate 2d-textures array for historical buffers */
    glGenTextures(SV_CAMERAS_NUMBER, hv->tex); GLCHECK();
        
    for (i = 0; i < SV_CAMERAS_NUMBER; i++)
    {
        int32_t    *dim = cfg->hv.dim[i];
        GLenum      error;

        if ((hv->dim[i] = dim[2]) <= 0)     continue;
        
        /* ...create HCS-to-UV conversion matrices array */
        hv->H2S[i] = calloc(dim[2], sizeof(*hv->H2S[i]));

        /* ...allocate storage for texture array */
        glBindTexture(GL_TEXTURE_2D_ARRAY, hv->tex[i]);     GLCHECK();
        glTexStorage3D(GL_TEXTURE_2D_ARRAY, 1, GL_RGBA8, dim[0], dim[1], dim[2]);
        if ((error = glGetError()) != GL_NO_ERROR)
        {
            TRACE(ERROR, _x("failed to allocated HVB-%d storage: %u*%u*%u: %X"), i, dim[0], dim[1], dim[2], error);
            goto error;
        }
                
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR);     GLCHECK();
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR);     GLCHECK();
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);  GLCHECK();
        glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);  GLCHECK();

        /* ...reset layer with predefined solid-color pattern? - tbd */
        if (0)
        {
            uint32_t  *data = malloc(dim[0] * dim[1] * 4);

            for (int j = 0; j < dim[2]; j++)
            {
                uint8_t     v = (uint8_t)(255.0 * (1.0 - (float32_t)j / (dim[2] - 1)));
                uint32_t    fill = ~0U;
                    
                if (i == 0)         fill = (v << 0) | (0 << 8) | (0 << 16) | (0xFF << 24);
                else if (i == 1)    fill = (0 << 0) | (v << 8) | (0 << 16) | (0xFF << 24);
                else if (i == 2)    fill = (0 << 0) | (0 << 8) | (v << 16) | (0xFF << 24);
                else if (i == 3)    fill = (v << 0) | (0 << 8) | (v << 16) | (0xFF << 24);                    

                for (int b = 0; b < dim[0] * dim[1]; b++)
                {
                    data[b] = fill;
                }

                glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, j, dim[0], dim[1], 1, GL_RGBA, GL_UNSIGNED_BYTE, data); GLCHECK();
            }

            free(data);
        }
    }

    /* ...create framebuffer for historical buffers rendering */
    glGenFramebuffers(SV_CAMERAS_NUMBER, hv->fb);   GLCHECK();

#ifdef BUILD_NATIVE
    (getenv("HV_DEBUG") ? hv_dbg_create(hv, 640 * 3, 640 * 2, cfg) : 0);
#endif
    
    /* ...no more tears */
    TRACE(INIT, _b("HV initialized"));
    
    return hv;

error:
    free(hv);
    return NULL;
}

