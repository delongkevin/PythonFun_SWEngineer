/*******************************************************************************
 * ibl.c
 *
 * Image-Based Lighting support
 *
 * Copyright (c) 2018-2021 Cogent Embedded Inc.
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

#define MODULE_TAG                      IBL

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "config.h"
#include "pbr-model.h"
#include "../src/util.h"
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
 * Debugging interface
 ******************************************************************************/

#ifdef BUILD_NATIVE

extern void dbg_cube_render(GLuint tex, float32_t alpha, float32_t *pvm, float32_t bias);
extern void dbg_tex_render_raw(GLuint tex, float32_t alpha);

/**> Debug data structure */
typedef struct ibl_dbg
{
    /**> Debug window callbacks */
    dbg_info_t          info;

    /**> Debug window data */
    dbg_window_t        dbg;

    /**> IBL cubemap */
    GLuint              tex_diff;

    /**> IBL cubemap */
    GLuint              tex_spec;

    /**> BRDF LUT */
    GLuint              tex_lut;

}   ibl_dbg_t;

/**
 * @brief   Initialize IBL debug window context
 *
 * @param   dbg_window[in]      Debug window handle
 * @param   W[in]               Window width
 * @param   H[in]               Window height
 *
 * @return                      Zero on success
 */
static int ibl_dbg_init(dbg_window_t *dbg_window, int W, int H)
{
    ibl_dbg_t      *dbg = container_of(dbg_window, ibl_dbg_t, dbg);

    /* ...nothing yet? */
    return 0;
}

/**
 * @brief   Redraw IBL debug screen
 *
 * @param   dbg_window[in]  Debug window handle
 * @param   W[in]           Window width
 * @param   H[in]           Window height
 */
static void ibl_dbg_redraw(dbg_window_t *dbg_window, int W, int H)
{
    ibl_dbg_t       *dbg = container_of(dbg_window, ibl_dbg_t, dbg);
    __mat4x4         P, V, M, PVM, t;

    /* ...clear display */
    glViewport(0, 0, W, H);
    glScissor(0, 0, W, H);

    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glDepthMask(GL_FALSE);

    glViewport(0, 0, W / 2, H);

    TRACE(1, _b("render tex: %u, %u, %u"), dbg->tex_diff, dbg->tex_spec, dbg->tex_lut);

    /* ...render cubemap */
    __mat4x4_perspective(P, 45.0f, (float)W * 0.5f / (float)H, 0*100.0f, 2 + 0*10000.0f);
    __mat4x4_translation(V, 0.0f, 0.0f, 0*-5000.0f);
    __mat4x4_rotation(M, (__vec3){dbg->dbg.rot[0], dbg->dbg.rot[2], 0.0f}, 1.0f);
    __mat4x4_mul(P, V, t);
    __mat4x4_mul(t, M, PVM);

    dbg_cube_render(dbg->tex_spec, 1.0f, PVM, fabsf(dbg->dbg.scale));

    glViewport(W / 2, 0, W / 2, H / 2);
    __mat4x4_perspective(P, 45.0f, (float)W / (float)H, 0*100.0f, 2 + 0*10000.0f);
    __mat4x4_translation(V, 0.0f, 0.0f, 0*-5000.0f);
    __mat4x4_rotation(M, (__vec3){dbg->dbg.rot[0], dbg->dbg.rot[2], 0.0f}, 1.0f);
    __mat4x4_mul(P, V, t);
    __mat4x4_mul(t, M, PVM);

    TRACE(1, _b("scale: %f"), dbg->dbg.scale);

    dbg_cube_render(dbg->tex_diff, 1.0f, PVM, 0.0f);

    glViewport(W / 2, H / 2, W, H / 2);

    dbg_tex_render_raw(dbg->tex_lut, 1.0f);

    glDepthMask(GL_TRUE);
}

/**
 * @brief   Create car debug window
 *
 * @param   width[in]       Debug window width
 * @param   height[in]      Debug window height
 * @param   title[in]       Debug window title
 *
 * @return                  Car debug data, or NULL
 */
static ibl_dbg_t * ibl_dbg_create(int width, int height, const char *title, GLuint tex_d, GLuint tex_s, GLuint tex_l)
{
    ibl_dbg_t      *dbg;
    dbg_info_t     *info;

    /* ...allocate debug structure data */
    CHK_ERR(dbg = calloc(1, sizeof(*dbg)), NULL);

    /* ...fill-in window parameters */
    info = &dbg->info;
    info->width = width;
    info->height = height;
    info->title = (title ? strdup(title) : NULL);

    /* ...set window callbacks */
    info->init = ibl_dbg_init;
    info->redraw = ibl_dbg_redraw;

    dbg->tex_diff = tex_d;
    dbg->tex_spec = tex_s;
    dbg->tex_lut = tex_l;

    /* ...create debug window */
    if (dbg_window_init(&dbg->dbg, info) != 0)
    {
        TRACE(ERROR, _x("failed to create debug window: %m"));
        free(dbg), dbg = NULL;
    }

    return dbg;
}

#endif  /* BUILD_NATIVE */

#define PRESET_HQ_COEFS_COUNT       9
#define PRESET_LQ_COEFS_COUNT       4

/*******************************************************************************
 * Local functions definitions
 ******************************************************************************/

/**
 * @brief   Read spectral harmonics coefficients from text file
 *
 * @param   fname[in]       File name
 * @param   ibl[in]         IBL data
 *
 * @return                  Negative on failure
 */
static int ibl_read_sh(const char *fname, ibl_data_t *ibl)
{
    FILE           *f;
    float32_t     (*v)[3];
    int             i;
    int             r;

    /* ...open file descriptor */
    CHK_ERR(f = fopen(fname, "r"), -1);

    /* ...allocate array of spectral harmonics */
    CHK_ERR(v = malloc(PRESET_HQ_COEFS_COUNT * sizeof(*v)), -1);

    for (i = 0; i < PRESET_HQ_COEFS_COUNT; i++)
    {
        char        buf[128];
        float32_t   R, G, B;

        if (fgets(buf, sizeof(buf), f) != NULL)
        {
            if (sscanf(buf, "%f %f %f", &R, &G, &B) != 3)
            {
                TRACE(ERROR, _b("failed to parse vector from '%s'"), buf);
                r = -(errno = EINVAL);
                goto error;
            }
            else if (R < 0.0f || R > 1.0f || G < 0.0f || G > 1.0f || B < 0.0f || B > 1.0f)
            {
                TRACE(ERROR, _b("invalid coefs: %f, %f, %f ('%s')"), R, G, B, buf);
                r = -(errno = EINVAL);
                goto error;
            }
            else
            {
                v[i][0] = R, v[i][1] = G, v[i][2] = B;
            }
        }
        else
        {
            break;
        }
    }

    if (i != PRESET_HQ_COEFS_COUNT && i != PRESET_LQ_COEFS_COUNT)
    {
        TRACE(ERROR, _b("invalid number of cefficients read: %d"), i);
        r = -(errno = EINVAL);
        goto error;
    }

    ibl->sh_irradiance_vec = v;
    ibl->sh_irradiance_vec_num = i;
    ibl->bands_count = (i == PRESET_LQ_COEFS_COUNT ? 2 : 3);

    r = 0;
    goto out;

error:
    free(v);

out:
    fclose(f);

    return r;
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Save IBL data in binary file
 *
 * @param   ibl[in]         IBL data
 * @param   fname[in]       File name
 *
 * @return                  Negative on failure
 */
int ibl_save(ibl_data_t *ibl, const char *fname)
{
    FILE   *f;
    int     r = 0;

    CHK_ERR(f = fopen(fname, "wb"), -1);

    TRACE(INIT, _b("IBL data saved into '%s'"), fname);

    fclose(f);

    return r;
}

/**
 * @brief   Load IBL configuration from file
 *
 * @param   pname[in]       Path name of IBL subdirectory
 *
 * @return                  IBL data handle, or NULL on failure
 */
ibl_data_t * ibl_load(cfg_ibl_t *cfg)
{
    ibl_data_t     *ibl;
    char            buf[4096];
    int             i;
    int             width, height, levels;

    CHK_ERR(ibl = calloc(1, sizeof(*ibl)), NULL);

    if (cfg->sh != NULL)
    {
        /* ...read diffuse spectral harmonics coefficients from text file */
        if (ibl_read_sh(cfg->sh, ibl) != 0)
        {
            TRACE(ERROR, _x("failed to get sh: %s"), strerror(errno));
            goto error;
        }
    }
    else
    {
        if (cfg->diffuse == NULL)
        {
            TRACE(ERROR, _x("diffuse irradiance file is required"));
            errno = EINVAL;
            goto error;
        }

        /* ...load HDR images for diffuse radiance */
        if (tex_cubemap_upload(cfg->diffuse, &ibl->diffuseIrradiance, &width, &height, &levels) != 0)
        {
            TRACE(ERROR, _x("failed to get diffuse irradiance cubemap: %s"), strerror(errno));
            goto error;
        }
        else
        {
            TRACE(INIT, _b("diffuse irradiance cubemap %d*%d [@%d] loaded"), width, height, levels);
        }
    }

    /* ...load HDR images for specular radiance */
    if (cfg->specular == NULL)
    {
        TRACE(ERROR, _x("specular radiance file is required"));
        errno = EINVAL;
        goto error;
    }

    if (tex_cubemap_upload(cfg->specular, &ibl->specular, &width, &height, &ibl->mipLevels) != 0)
    {
        TRACE(ERROR, _x("failed to get cubemap"));
    }
    else
    {
        TRACE(INIT, _b("specular radiance cubemap %d*%d [@%d] loaded"), width, height, ibl->mipLevels);
    }

    /* ...load KTX2 texture */
    if (cfg->lut == NULL)
    {
        TRACE(ERROR, _b("brdf LUT file is required"));
        errno = EINVAL;
        goto error;
    }

    if (tex_upload(cfg->lut, &ibl->brdfLUT, &width, &height, NULL) != 0)
    {
        TRACE(ERROR, _x("failed to create LUT texture: %s"), strerror(errno));
        goto error;
    }
    else
    {
        TRACE(INFO, _b("BRDF lut texture %d*%d uploaded"), width, height);
    }

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

#ifdef BUILD_NATIVE
    if (0) ibl_dbg_create(1280, 640, "ibl-diffuse", ibl->diffuseIrradiance, ibl->specular, ibl->brdfLUT);
#endif

    TRACE(INIT, _b("IBL scene loaded"));

    return ibl;

error:
    /* ...destroy irradiance vectors */
    (ibl->sh_irradiance_vec ? free(ibl->sh_irradiance_vec) : 0);

    /* ...destroy IBL data */
    free(ibl);

    return NULL;
}
