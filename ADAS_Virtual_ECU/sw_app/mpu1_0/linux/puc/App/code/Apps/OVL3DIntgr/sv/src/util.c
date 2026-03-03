/*******************************************************************************
 * util.c
 *
 * Auxiliary utility functions
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

#define MODULE_TAG                      UTIL

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "util.h"
#include "png-load.h"
#include "bmp-load.h"
#include <ktx.h>
#include "sv_api.h"

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Texture loading
 ******************************************************************************/

#if 0
/**
 * @brief   Load irradiance cubemap from subdirectory
 *
 * @param   ibl[in]         IBL data
 * @param   pattern[in]     File name template of the form "name-%s-%u"
 * @param   pname[in]       Path name of IBL directory
 *
 * @return                  Negative on failure
 */
static GLuint ibl_cubemap_load_2(ibl_data_t *ibl, const char *pattern, int levels)
{
    const   char   *sfx[6] = { "px", "nx", "py", "ny", "pz", "nz" };
    void           *v[6];
    int             w[6];
    int             h[6];
    int             c[6];
    int             i;
    GLuint          tex = 0;

    /* ...clear array of data pointers */
    memset(v, 0, sizeof(v));

    GLenum      iformat = GL_RGBA16F;
    GLenum      format = GL_RGBA;
    GLenum      type = GL_FLOAT;

    /* ...load HDR images for specular radiance (level-0 only) */
    for (i = 0; i < 6; i++)
    {
        char    buf[4096];

        snprintf(buf, sizeof(buf), pattern, sfx[i]);

        if ((v[i] = stbi_loadf(buf, &w[i], &h[i], &c[i], 4)) == NULL)
        {
            TRACE(ERROR, _x("hdr image '%s' loading failed: %s"), buf, strerror(errno));
            goto error;
        }
        else
        {
            TRACE(DEBUG, _b("hdr image '%s' loaded: %d*%d@%d"), buf, w[i], h[i], c[i]);
        }

        if (i != 0 && (w[i] != w[0] || h[i] != h[0]))
        {
            TRACE(ERROR, _b("invalid cubemap dimensions: %d*%d != %d*%d"), w[0], h[0], w[i], h[i]);
            goto error;
        }
    }

    /* ...create cubemap out of images */
    GLenum      error;

    glGenTextures(1, &tex);     GLCHECK();
    glBindTexture(GL_TEXTURE_CUBE_MAP, tex);    GLCHECK();
    glTexStorage2D(GL_TEXTURE_CUBE_MAP, levels, iformat, w[0], h[0]); GLCHECK();

    for (i = 0; i < 6; i++)
    {
        glTexSubImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, 0, 0, w[0], h[0], format, type, v[i]);
        if ((error = glGetError()) != GL_NO_ERROR)
        {
            TRACE(ERROR, _x("failed to upload cubemap: i=%d, ifmt=%X, fmt=%X, type=%X: %X"), i, iformat, format, type, error);
            goto error;
        }
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, (levels > 1 ? GL_LINEAR_MIPMAP_LINEAR : GL_LINEAR)); GLCHECK();
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR); GLCHECK();
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT); GLCHECK();
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_REPEAT); GLCHECK();
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_REPEAT); GLCHECK();

    if (levels > 1)
    {
        glGenerateMipmap(GL_TEXTURE_CUBE_MAP);  GLCHECK();
    }

    TRACE(INIT, _b("cubemap %d*%d (levels=%d) loaded from '%s'"), w[0], h[0], levels, pattern);

    goto out;

error:
    /* ...destroy texture as required */
    (tex ? glDeleteTextures(1, &tex), tex = 0 : 0);

out:
    /* ...free allocated buffers */
    for (i = 0; i < 6; i++)
    {
        (v[i] ? free(v[i]) : 0);
    }

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

    return tex;
}

/**
 * @brief   Load irradiance cubemap from subdirectory
 *
 * @param   ibl[in]         IBL data
 * @param   pattern[in]     File name template of the form "name-%u-%s"
 * @param   levels[in]      Number of mipmap levels
 *
 * @return                  Negative on failure
 */
static GLuint ibl_cubemap_load(ibl_data_t *ibl, const char *pattern, int levels)
{
    const   char   *sfx[6] = { "px", "nx", "py", "ny", "pz", "nz" };
    void           *v[levels][6];
    int             w[levels][6];
    int             h[levels][6];
    int             c[levels][6];
    int             i;
    int             lod;
    GLuint          tex = 0;

    /* ...clear array of data pointers */
    memset(v, 0, sizeof(*v) * levels);

    /* ...load HDR images for specular radiance */
    for (lod = 0; lod < levels; lod++)
    {
        for (i = 0; i < 6; i++)
        {
            char    buf[4096];

            if (levels > 1)
            {
                snprintf(buf, sizeof(buf), pattern, lod, sfx[i]);
            }
            else
            {
                snprintf(buf, sizeof(buf), pattern, sfx[i]);
            }

            if ((v[lod][i] = stbi_loadf(buf, &w[lod][i], &h[lod][i], &c[lod][i], 0)) == NULL)
            {
                TRACE(ERROR, _x("hdr image '%s' loading failed: %s"), buf, strerror(errno));
                goto error;
            }
            else
            {
                TRACE(1, _b("hdr image '%s' loaded: %d*%d@%d"), buf, w[lod][i], h[lod][i], c[lod][i]);
            }
        }
    }

    /* ...create cubemap out of images */
    GLenum      iformat = GL_RGB16F;
    GLenum      format = GL_RGB;
    GLenum      type = GL_FLOAT;
    GLenum      error;

    glGenTextures(1, &tex);     GLCHECK();
    glBindTexture(GL_TEXTURE_CUBE_MAP, tex);    GLCHECK();
    glTexStorage2D(GL_TEXTURE_CUBE_MAP, levels, iformat, w[0][0], h[0][0]);
    if ((error = glGetError()) != GL_NO_ERROR)
    {
        TRACE(ERROR, _x("failed to create %u*%u cubemap: lelevs=%d, ifmt=%X: %X"), w[0][0], h[0][0], levels, iformat, error);
        goto error;
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, (levels > 1 ? GL_LINEAR_MIPMAP_LINEAR : GL_LINEAR)); GLCHECK();
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR); GLCHECK();
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT); GLCHECK();
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_REPEAT); GLCHECK();
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_REPEAT); GLCHECK();

    for (lod = 0; lod < levels; lod++)
    {
        for (i = 0; i < 6; i++)
        {
            glTexSubImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, lod, 0, 0, w[lod][i], h[lod][i], format, type, v[lod][i]);
            if ((error = glGetError()) != GL_NO_ERROR)
            {
                TRACE(ERROR, _x("failed to upload cubemap: lod=%d, i=%d, ifmt=%X, fmt=%X, type=%X: %X"), lod, i, iformat, format, type, error);
                break;
            }

            TRACE(DEBUG, _b("cubemap-%d-%d: %d*%d@%x"), lod, i, w[lod][i], h[lod][i], format);
        }
    }

    TRACE(INIT, _b("cubemap %d*%d (levels=%d) loaded from '%s'"), w[0][0], h[0][0], levels, pattern);

    goto out;

error:
    /* ...destroy texture as required */
    (tex ? glDeleteTextures(1, &tex), tex = 0 : 0);

out:
    /* ...free allocated buffers */
    for (lod = 0; lod < levels; lod++)
    {
        for (i = 0; i < 6; i++)
        {
            (v[lod][i] ? free(v[lod][i]) : 0);
        }
    }

    TRACE(DEBUG, _b("cubemap: %u"), tex);

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

    return tex;
}
#endif

/**
 * @brief   Create cubemap texture
 *
 * @param   fname[in]           File name
 * @param   tex[in, out]        Texture identifier (generated if 0)
 * @param   width[out]          Texture width, in pixels
 * @param   height[out]         Texture height, in pixels
 * @param   ch[out]             Number of channels in a texture
 * @param   levels[out]         Number of levels for mipmap
 *
 * @return                      Negative on failure
 */
int tex_cubemap_upload(const char *fname, GLuint *tex, int32_t *width, int32_t *height, int32_t *levels)
{
    const char     *ext;
    int             w, h, lod, fmt;
    void           *data = NULL;

    /* ...check for a texture type */
    if ((ext = strrchr(fname, '.')) == NULL)
    {
        TRACE(ERROR, _x("unknown image file: '%s'"), fname);
        return -(errno = EINVAL);
    }

    ext++;

    if (!strcasecmp(ext, "ktx") || !strcasecmp(ext, "ktx2"))
    {
        GLenum      target, error;
        ktxTexture *texture;
        int         r;

        if ((r = ktxTexture_CreateFromNamedFile(fname, KTX_TEXTURE_CREATE_NO_FLAGS, &texture)) != KTX_SUCCESS)
        {
            TRACE(ERROR, _x("failed to load ktx from '%s': %d"), fname, r);
            return -(errno = EBADF);
        }

        if (!texture->isCubemap)
        {
            TRACE(ERROR, _x("texture '%s' is not a cubemap"), fname);
            ktxTexture_Destroy(texture);
            return -(errno = EINVAL);
        }

        if ((r = ktxTexture_GLUpload(texture, tex, &target, &error)) != KTX_SUCCESS)
        {
            TRACE(ERROR, _x("failed to upload texture: r=%d, error=%X"), r, error);
            return errno = EBADF, 0;
        }

        fmt = (texture->classId == 2 ? ((ktxTexture2 *)texture)->vkFormat : ((ktxTexture1 *)texture)->glInternalformat);
        w = texture->baseWidth;
        h = texture->baseHeight;
        lod = texture->numLevels;

        TRACE(INIT, _b("texture %u uploaded from '%s': comp=%d, target=%X, %u*%u, fmt=%X, levels=%d"), *tex, fname, texture->isCompressed, target, w, h, fmt, lod);

        ktxTexture_Destroy(texture);
    }
    else
    {
        TRACE(ERROR, _x("unsupported texture file: '%s'"), fname);
        return -(errno = EINVAL);
    }

    /* ...set default cubemap parameters */
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, (lod > 1 ? GL_LINEAR_MIPMAP_LINEAR : GL_LINEAR)); GLCHECK();
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR); GLCHECK();
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT); GLCHECK();
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_REPEAT); GLCHECK();
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_REPEAT); GLCHECK();

    /* ...save texture format */
    (width ? *width = w : 0);
    (height ? *height = h : 0);
    (levels ? *levels = lod : 0);

    TRACE(INIT, _b("cubemap '%s' uploaded: %d*%d, fmt=%d, %d levels"), fname, w, h, fmt, lod);

    return 0;
}

/**
 * @brief   Upload GL-texture from file
 *
 * @param   fname[in]           File name
 * @param   tex[in, out]        Texture identifier (generated if 0)
 * @param   width[out]          Texture width, in pixels
 * @param   height[out]         Texture height, in pixels
 * @param   ch[out]             Number of channels in a texture
 * @param   levels[out]         Number of levels for mipmap
 *
 * @return                      Negative on failure
 */
int tex_upload(const char *fname, GLuint *tex, int32_t *width, int32_t *height, int *levels)
{
    const char     *ext;
    int             format = 0;
    int             lod = 0;
    void           *data = NULL;

    /* ...check for a texture type */
    if ((ext = strrchr(fname, '.')) == NULL)
    {
        TRACE(ERROR, _x("unknown image file: '%s'"), fname);
        return -(errno = EINVAL);
    }

    ext++;

    *width = *height = 0;

    if (!strcasecmp(ext, "png"))
    {
        if (load_png(fname, width, height, &format, &data) < 0)
        {
            TRACE(ERROR, _b("failed to load icon from '%s': %s"), fname, strerror(errno));
            return -1;
        }
    }
    else if (!strcasecmp(ext, "bmp"))
    {
        if (load_bmp(fname, width, height, &format, &data) < 0)
        {
            TRACE(ERROR, _b("failed to load icon from '%s': %s"), fname, strerror(errno));
            return -1;
        }
    }
    else if (!strcasecmp(ext, "ktx") || !strcasecmp(ext, "ktx2"))
    {
        GLenum      target, error;
        ktxTexture *texture;
        int         r;

        if ((r = ktxTexture_CreateFromNamedFile(fname, KTX_TEXTURE_CREATE_NO_FLAGS, &texture)) != KTX_SUCCESS)
        {
            TRACE(ERROR, _x("failed to load ktx from '%s': %d"), fname, r);
            return -(errno = EBADF);
        }

        /* ...make sure it is a 2D-texture? */
        if ((r = ktxTexture_GLUpload(texture, tex, &target, &error)) != KTX_SUCCESS)
        {
            TRACE(ERROR, _x("failed to upload texture: r=%d, error=%X"), r, error);
            return -(errno = EBADF);
        }

        if (target != GL_TEXTURE_2D)
        {
            TRACE(ERROR, _x("invalid texture target: %X"), target);
            ktxTexture_Destroy(texture);
            return -(errno = EINVAL);
        }

        uint32_t    fmt;

        lod = texture->numLevels;
        fmt = (texture->classId == 2 ? ((ktxTexture2 *)texture)->vkFormat : ((ktxTexture1 *)texture)->glInternalformat);
        (width ? *width = texture->baseWidth : 0);
        (height ? *height = texture->baseHeight : 0);
        (levels ? *levels = lod : 0);

        TRACE(INIT, _b("texture %u uploaded from '%s': comp=%d, target=%X, %u*%u, fmt=%X, levels=%d"), *tex, fname, texture->isCompressed, target, texture->baseWidth, texture->baseHeight, fmt, texture->numLevels);

        goto setup;
    }
    else
    {
        TRACE(ERROR, _b("unknown file extension: '%s'"), fname);
        return -(errno = EINVAL);
    }

    if (*tex != 0)
    {
        glGenTextures(1, tex);      GLCHECK();
    }

    /* ...upload texture into GL context */
    glBindTexture(GL_TEXTURE_2D, *tex); GLCHECK();
    if (format == GST_VIDEO_FORMAT_GRAY8)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, *width, *height, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, data); GLCHECK();
    }
    else
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, *width, *height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); GLCHECK();
    }

setup:

    /* ...set default texture parameters */
    if (strstr(fname, "repeat") == 0)
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    }
    else
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (lod > 1 ? GL_LINEAR_MIPMAP_LINEAR : GL_LINEAR));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    TRACE(INIT, _b("texture %d*%d uploaded from '%s'"), *width, *height, fname);

    /* ...free interim data buffer */
    (data ? free(data) : 0);

    return 0;
}

/**
 * @brief   Upload GL-texture from memory buffer
 *
 * @param   mime[in]            MIME type
 * @param   buf[in]             Buffer data
 * @param   size[in]            Buffer size
 * @param   tex[in, out]        Texture identifier (generated if 0)
 * @param   width[out]          Texture width, in pixels
 * @param   height[out]         Texture height, in pixels
 *
 * @return                      Negative on failure
 */
int tex_upload_from_mem(const char *mime, void *buf, size_t size, GLuint *tex, int32_t *width, int32_t *height)
{
    int             format = 0;
    void           *data = NULL;

    *width = *height = 0;

    /* ...check for a texture type */
    if (!strncasecmp(mime, "image/png", 16))
    {
        if (load_png_from_mem(buf, size, width, height, &format, &data) < 0)
        {
            TRACE(ERROR, _b("failed to load texture: %s"), strerror(errno));
            return -1;
        }
    }
    else if (!strncasecmp(mime, "image/ktx", 16) || !strncasecmp(mime, "image/ktx2", 16))
    {
        GLenum      target, error;
        ktxTexture *texture;
        int         r;

        if ((r = ktxTexture_CreateFromMemory(buf, size, KTX_TEXTURE_CREATE_NO_FLAGS, &texture)) != KTX_SUCCESS)
        {
            TRACE(ERROR, _x("failed to load ktx: %d"), r);
            return -(errno = EBADF);
        }

        if ((r = ktxTexture_GLUpload(texture, tex, &target, &error)) != KTX_SUCCESS)
        {
            TRACE(ERROR, _x("failed to upload texture: r=%d, error=%X"), r, error);
            return errno = EBADF, 0;
        }

        if (target != GL_TEXTURE_2D)
        {
            TRACE(ERROR, _x("invalid texture target: %X"), target);
            ktxTexture_Destroy(texture);
            return -(errno = EINVAL);
        }

        uint32_t    fmt;
        int         levels;

        fmt = (texture->classId == 2 ? ((ktxTexture2 *)texture)->vkFormat : ((ktxTexture1 *)texture)->glInternalformat);
        *width = texture->baseWidth;
        *height = texture->baseHeight;
        levels = texture->numLevels;

        TRACE(INIT, _b("texture %u uploaded: comp=%d, target=%X, %u*%u, fmt=%X, levels=%d"), *tex, texture->isCompressed, target, texture->baseWidth, texture->baseHeight, fmt, levels);

        ktxTexture_Destroy(texture);

        goto setup;
    }
    else
    {
        TRACE(ERROR, _b("unknown image type '%s'"), mime);
        return -(errno = EINVAL);
    }

    if (*tex == 0)
    {
        glGenTextures(1, tex);      GLCHECK();
    }

    /* ...upload texture into GL context */
    glBindTexture(GL_TEXTURE_2D, *tex); GLCHECK();
    if (format == GST_VIDEO_FORMAT_GRAY8)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, *width, *height, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, data); GLCHECK();
    }
    else if (format == GST_VIDEO_FORMAT_RGBA || format == GST_VIDEO_FORMAT_ARGB)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, *width, *height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); GLCHECK();
    }
    else if (format == GST_VIDEO_FORMAT_RGB)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, *width, *height, 0, GL_RGB, GL_UNSIGNED_BYTE, data); GLCHECK();
    }
    else
    {
        TRACE(ERROR, _x("unknown image format %d"), format);

        /* ...free interim data buffer */
        (data ? free(data) : 0);

        return -(errno = EINVAL);
    }

setup:
    /* ...set default texture parameters */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    TRACE(INIT, _b("texture %d*%d uploaded"), *width, *height);

    /* ...free interim data buffer */
    (data ? free(data) : 0);

    return 0;
}

/*******************************************************************************
 * Pixel-data accessing
 ******************************************************************************/

/**
 * @brief   Read YUV-values of particular pixel
 *
 * @param   img[in]         Image descriptor
 * @param   x[in]           X-coordinate
 * @param   y[in]           Y-coordinate
 * @param   yuv[out]        Normalized YUV values
 */
void img_get_yuv_bt709_f32(image_data_t *img, int32_t x, int32_t y, float32_t yuv[3])
{
    if (img->fourcc == SCREEN_FORMAT_RGBA8888)
    {
        uint8_t    *rgba = (uint8_t *)(img->data[0] + img->stride[0] * y + x * sizeof(uint8_t [4]));
        float32_t   RGB[4] = {
            (float32_t)rgba[0] * (float32_t)(1.0 / 255.0),
            (float32_t)rgba[1]  * (float32_t)(1.0 / 255.0),
            (float32_t)rgba[2]  * (float32_t)(1.0 / 255.0),
            (float32_t)rgba[2]  * (float32_t)(1.0 / 255.0),
        };

        yuv[0] = RGB[0] * 0.2126f + RGB[1] * 0.7152f + RGB[2] * 0.0722f;
        yuv[1] = RGB[0] * -0.114572106f - 0.385427893f * RGB[1] + 0.5f * RGB[2];
        yuv[2] = 0.5f * RGB[0] - 0.454152908f * RGB[1] - 0.045847091f * RGB[2];

        TRACE(1, _b("pix <%d,%d> (stride=%u): RGBA=%f,%f,%f,%f"), x, y, img->stride[0], RGB[0], RGB[1], RGB[2], RGB[3]);
    }
    else if (img->fourcc == SCREEN_FORMAT_RGB888)
    {
        uint8_t    *rgb = (uint8_t *)(img->data[0] + img->stride[0] * y + x * sizeof(uint8_t [3]));
        float32_t   RGB[3] = {
            (float32_t)rgb[0] * (float32_t)(1.0 / 255.0),
            (float32_t)rgb[1]  * (float32_t)(1.0 / 255.0),
            (float32_t)rgb[2]  * (float32_t)(1.0 / 255.0),
        };

        yuv[0] = RGB[0] * 0.2126f + RGB[1] * 0.7152f + RGB[2] * 0.0722f;
        yuv[1] = RGB[0] * -0.114572106f - 0.385427893f * RGB[1] + 0.5f * RGB[2];
        yuv[2] = 0.5f * RGB[0] - 0.454152908f * RGB[1] - 0.045847091f * RGB[2];

        TRACE(0, _b("pix <%d,%d> (stride=%u): RGB=%f,%f,%f"), x, y, img->stride[0], RGB[0], RGB[1], RGB[2]);
    }
    else if (img->fourcc == SCREEN_FORMAT_NV12)
    {
        uint8_t    *data_y = (uint8_t *)img->data[0] + img->stride[0] * y + x;
        uint8_t    *data_uv = (uint8_t *)img->data[1] + img->stride[1] * (y >> 1) + (x & ~1);

        yuv[0] = (float32_t)data_y[0] * (float32_t)(1.0 / 255.0);
        yuv[1] = (float32_t)data_uv[0] * (float32_t)(1.0 / 255.0) - 0.5f;
        yuv[2] = (float32_t)data_uv[1] * (float32_t)(1.0 / 255.0) - 0.5f;
    }
    else if (img->fourcc == SCREEN_FORMAT_UYVY)
    {
        uint8_t    *data = (uint8_t *)img->data[0] + img->stride[0] * y + (x >> 1) * 4;

        yuv[0] = (float32_t)data[0 + ((x & 1) << 1)] * (float32_t)(1.0 / 255.0);
        yuv[1] = (float32_t)data[1] * (float32_t)(1.0 / 255.0) - 0.5f;
        yuv[2] = (float32_t)data[3] * (float32_t)(1.0 / 255.0) - 0.5f;
    }
    else
    {
        TRACE(ERROR, _x("unknown format: '%c%c%c%c' (%X)"), __v4l2_fmt(img->fourcc), img->fourcc);

        memset(yuv, 0, sizeof(float32_t[3]));
    }
}

/*******************************************************************************
 * Move somewhere eventually
 ******************************************************************************/

#include "render-context.h"
#include "../libsv/vbo-dynarray.h"
#include "math-neon.h"
#include <stdarg.h>

typedef struct font_symbol
{
    /**> Symbol character (informative) */
    char            sym;

    /**> Bitmap horizontal offset for a bitmap */
    uint8_t         left;

    /**> Bitmap vertical offset for a bitmap */
    uint8_t         top;

    /**> Cursor advancement in pixels for text rendering */
    uint8_t         advance;

    /**> Bitmap source tile */
    uint16_t        src[4];

}   font_symbol_t;

/**
 * @brief   Font descriptor
 */
typedef struct font_data
{
    /**> Array of symbols - only printable from 0x20 up to 0x7F ar supported */
    font_symbol_t   symbol[96];

    /**> Source tiles in GL-format */
    float32_t       src[96][4];

    /**> Grayscale pixmap texture */
    GLuint          tex;

    /**> Dynamic array for rendering fonts */
    vbo_dynarray_t  vbo;

}   font_data_t;

/**
 * @brief   Font-file loading
 *
 * @param   name[in]        Font file name
 *
 * @return                  Negative on failure
 */
font_data_t * font_load(char *name)
{
    font_data_t    *font;
    FILE           *file;
    void           *buffer = NULL;

    /* ...allocate font descriptor structure */
    CHK_ERR(font = malloc(sizeof(*font)), NULL);

    /* ...open font file */
    if ((file = fopen(name, "rb")) == NULL)
    {
        TRACE(ERROR, _x("failed to open file '%s': %s"), name, strerror(errno));
        goto error;
    }

    if (fread(font->symbol, sizeof(font->symbol), 1, file) != 1)
    {
        TRACE(ERROR, _x("failed to read symbols from '%s': %s"), name, strerror(errno));
        goto error;
    }

    long    pos = ftell(file);
    fseek(file, 0, SEEK_END);

    long    size = ftell(file) - pos;
    fseek(file, pos, SEEK_SET);

    if (size < 0 || (buffer = malloc(size)) == NULL)
    {
        TRACE(ERROR, _x("failed to allocate %ld bytes"), size);
        goto error;
    }

    if (fread(buffer, size, 1, file) != 1)
    {
        TRACE(ERROR, _x("failed to read image from '%s': %s"), name, strerror(errno));
        goto error;
    }

    int32_t width, height;
    if (tex_upload_from_mem("image/png", buffer, size, &font->tex, &width, &height) < 0)
    {
        TRACE(ERROR, _x("failed to load PNG from '%s': %s"), name, strerror(errno));
        goto error;
    }

    /* ...convert source tiles to float */
    int             n;
    for (n = 0; n < 96; n++)
    {
        float32_t  *src = font->src[n];
        uint16_t   *tile = font->symbol[n].src;

        TRACE(0, _b("sym '%c', tile: %u,%u,%u,%u"), font->symbol[n].sym, tile[0], tile[1], tile[2], tile[3]);

        src[0] = (float32_t)tile[0] / (float32_t)width;
        src[1] = (float32_t)tile[1] / (float32_t)height;
        src[2] = (float32_t)tile[2] / (float32_t)width;
        src[3] = (float32_t)tile[3] / (float32_t)height;
    }

    BUG(0, _x("break"));

    memset(&font->vbo, 0, sizeof(font->vbo));

    free(buffer);
    fclose(file);

    TRACE(INIT, _b("font loaded from '%s'"), name);

    return font;

error:
    /* ...destroy buffer as needed */
    (buffer != NULL ? free(buffer) : 0);

    /* ...close file */
    (file != NULL ? fclose(file) : 0);

    free(font);

    return NULL;
}

/*******************************************************************************
 * Vertex shader construction
 ******************************************************************************/

/**> Vertex data: {X,Y} + {U,V} */
typedef GLfloat  font_vertex_t[4];

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
    "uniform vec4 color;\n"
    "uniform sampler2D tex;\n"
    "uniform float intensity;\n"
    "varying vec2 uv;\n"
    "void main()\n"
    "{\n"
    "   vec4    rgba = texture2D(tex, uv);\n"
    "   gl_FragColor = color * rgba.r * intensity;\n"
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
    __U(scale), __U(tex), __U(color), __U(intensity),

/* ...build shader lists */
#include "shader-impl.h"

/**
 * @brief   Return shader object for mask rendering
 *
 * @return                  Shader pointer, or NULL in case of error
 */
static shader_data_t * font_get_mask_shader(void)
{
    static shader_data_t * __shader;

    if (__shader == NULL)
    {
        __shader = shader_create(&SHADER_DESC(MASK));
    }

    return __shader;
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

static void font_draw_mask(vbo_dynarray_t *vbo, GLuint tex, render_context_t *ctx, float32_t *color, float32_t intensity)
{
    void           *XY_off = vbo_dynarray_buffer(vbo, sizeof(font_vertex_t));
    void           *UV_off = XY_off + 2 * sizeof(GLfloat);
    const size_t    vbo_size = sizeof(font_vertex_t);
    shader_data_t  *shader = font_get_mask_shader();

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

    /* ...set colors */
    glUniform4fv(U(color), 1, color);

    /* ..bind texture */
    glActiveTexture(GL_TEXTURE0);  GLCHECK();
    glBindTexture(GL_TEXTURE_2D, tex);  GLCHECK();

    /* ...bind attributes */
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glEnableVertexAttribArray(A(XY));
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, vbo_size, XY_off);

    glEnableVertexAttribArray(A(UV));
    glVertexAttribPointer(A(UV), 2, GL_FLOAT, GL_FALSE, vbo_size, UV_off);

    /* ...generate closed line-strip with foreground color */
    glDrawArrays(GL_TRIANGLES, 0, vbo_dynarray_num(vbo));      GLCHECK();

    TRACE(0, _b("render %d points"), vbo_dynarray_num(vbo));

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
static inline void font_quad_encode(font_vertex_t *v, float32x4x2_t B01, float32x4x2_t B23)
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
/**
 * @brief   Add symbol item to rendering list
 *
 * @param   v[in]           VBO buffer
 * @param   S[in]           Source tile in texture:
 *                          [0]: {U0, U1}
 *                          [1]: {V0, V1}
 * @param   P[in]           Destination tile on display:
 *                          [0]: {X0, X1, X2, X3}
 *                          [1]: {Y0, Y1, Y2, Y3}
 *
 * @return                  Negative on failure
 */
static inline void font_add_quad(font_vertex_t *v, float32x2x2_t S, float32x4x2_t P)
{
    /* ...create coordinates of the corners in source tile:
     * [0]: {U0, U0, U1, U1}
     * [1]: {V0, V1, V0, V1}
     */
    float32x4x2_t   R;
    R.val[0] = vcombine_f32(vtrn1_f32(S.val[0], S.val[0]), vtrn2_f32(S.val[0], S.val[0]));
    R.val[1] = vcombine_f32(S.val[1], S.val[1]);

    TRACE(0, _b("P=%f,%f,%f,%f : %f,%f,%f,%f"), __float32x4_p(P.val[0]), __float32x4_p(P.val[1]));
    TRACE(0, _b("R=%f,%f,%f,%f : %f,%f,%f,%f"), __float32x4_p(R.val[0]), __float32x4_p(R.val[1]));

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
    font_quad_encode(v, B01, B23);
}

/**
 * @brief   Prepare font rendering parameters
 *
 * @param   params[in]          Font rendering parameters
 * @param   x[in]               Starting position, X-coordinate, pixels
 * @param   y[in]               Starting position, Y-coordinate, pixels
 * @param   angle[in]           String angle, radians
 * @param   sx[in]              Horizontal scale factor
 * @param   sy[in]              Vertical scale factor
 * @param   color[in]           Font color, RGBA
 */
void font_render_params_init(font_render_params_t *params, float32_t x, float32_t y, float32_t angle, float32_t sx, float32_t sy, float32_t *color)
{
    float32_t   c = cosf(angle);
    float32_t   s = sinf(angle);

    /* ...set transform matrix */
    params->matrix[0 * 3 + 0] = c * sx;
    params->matrix[0 * 3 + 1] = s * sy;
    params->matrix[0 * 3 + 2] = x;
    params->matrix[1 * 3 + 0] = -s * sx;
    params->matrix[1 * 3 + 1] = c * sy;
    params->matrix[1 * 3 + 2] = y;

    /* ...set text color */
    memcpy(params->color, color, sizeof(float32_t[4]));

    /* ..reset rendered length */
    params->length = 0.0f;
}

/**
 * @brief   Font rendering function
 *
 * @param   font[in]        Font descriptor
 * @prama   width[in]       Output window width, pixels
 * @prama   height[in]      Output window height, pixels
 * @param   x[in, out]      Cursor position X-coordinate
 * @param   y[in, out]      Cursor position Y-coordinate
 * @param   color[in]       Color for font rendering
 * @param   str[in]         Text string (only printable characters are shown)
 */
int font_render_params(font_data_t *font, render_context_t *ctx, font_render_params_t *params, char *str, int length, float32_t intensity)
{
    int32_t         x0 = params->length, y0 = 0;
    font_vertex_t  *v;

    /* ...reset dynamic array */
    vbo_dynarray_clear(&font->vbo, sizeof(font_vertex_t));

    /* ...allocate space for all symbols (6 points per each symbol) */
    CHK_ERR(v = vbo_dynarray_add(&font->vbo, sizeof(*v), length * 6), -1);

    float32x2x3_t   M = vld3_f32(params->matrix);

    TRACE(0, _b("M=%f,%f : %f,%f : %f,%f"), __float32x2_p(M.val[0]), __float32x2_p(M.val[1]), __float32x2_p(M.val[2]));

    /* ...render all symbols */
    while (length--)
    {
        char    sym = *str++;

        /* ...discard non-printable characters */
        uint8_t idx = (sym < 32 ? 127 : sym) - 32;

        font_symbol_t  *symbol = &font->symbol[idx];

        /* ...load symbol source tile: [0]: {U0, U1}, [1]: {V0, V1} */
        float32x2x2_t   S = vld2_f32(font->src[idx]);

        /* ...set position of a symbol: [0]: {X0, Y0}, [1]: {X1, Y1} */
        float32x2x2_t   V;
        V.val[0] = __mk_float32x2(x0 + symbol->left, y0 - symbol->top);
        V.val[1] = vadd_f32(V.val[0], __mk_float32x2(symbol->src[2] - symbol->src[0], symbol->src[3] - symbol->src[1]));

        /* ...build all 4 corners of the tile: [0]: {X0, X0, X1, X1}, [1]: {Y0, Y1, Y0, Y1} */
        float32x4x2_t   P;
        P.val[0] = vcombine_f32(vtrn1_f32(V.val[0], V.val[0]), vtrn1_f32(V.val[1], V.val[1]));
        P.val[1] = vcombine_f32(vtrn2_f32(V.val[0], V.val[1]), vtrn2_f32(V.val[0], V.val[1]));

        /* ...produce coordinates by multiplying by transformation matrix */
        float32x4x2_t   D = __mat2x3_mulvh_4_tr(M, P);

        TRACE(0, _b("V: %f,%f : %f,%f, D: %f,%f,%f,%f : %f,%f,%f,%f"), __float32x2_p(V.val[0]), __float32x2_p(V.val[1]), __float32x4_p(D.val[0]), __float32x4_p(D.val[1]));

        /* ...encode single letter */
        font_add_quad(v, S, D);

        TRACE(0, _b("sym: '%c', left=%d,top=%d,src=%d,%d,%d,%d"), sym, symbol->left, symbol->top, symbol->src[0], symbol->src[1], symbol->src[2], symbol->src[3]);

        /* ...advance x0 coordinate only */
        x0 += symbol->advance;

        /* ...advance VBO */
        v += 6;
    }

    /* ...render prepared list */
    font_draw_mask(&font->vbo, font->tex, ctx, params->color, intensity);

    /* ...update end-position */
    params->length = x0;

    return 0;
}

/**
 * @brief   Font rendering function
 *
 * @param   font[in]        Font descriptor
 * @prama   ctx[in]         Rendering context
 * @param   x[in, out]      Cursor position X-coordinate
 * @param   y[in, out]      Cursor position Y-coordinate
 * @param   color[in]       Color for font rendering
 * @param   format[in]      Text format string (only printable characters are shown)
 * @param   ...             Variable arguments
 */
int font_render(font_data_t *font, render_context_t *ctx, font_render_params_t *params, float32_t intensity, char *format, ...)
{
    va_list             args;
    static char         buffer[256];
    char               *p = buffer;
    int                 n = sizeof(buffer), k;

    /* ...output format string */
    va_start(args, format);
    k = vsnprintf(p, n, format, args);
    va_end(args);

    font_render_params(font, ctx, params, p, k, intensity);

    return 0;
}

/*******************************************************************************
 * Graphical primitives
 ******************************************************************************/

/**> Vertex data: {X,Y} + {R,G,B,A} + {Nx,Ny,D} */
typedef GLfloat  gfx_vertex_t[9];

/*******************************************************************************
 * Solid-color shader construction
 ******************************************************************************/

/* ...vertex shader */
static const char *line_vertex_shader =
    SH_SETPREC
    "attribute vec2	XY;\n"
    "attribute vec4 C;\n"
    "attribute vec3 EQ;\n"
    "uniform vec2 scale;\n"
    "varying vec2 xy;\n"
    "varying vec4 c;\n"
    "varying vec3 eq;\n"
    "void main(void)\n"
    "{\n"
    "   xy = XY;\n"
    "   c = C;\n"
    "   eq = EQ;\n"
    "	gl_Position = vec4(XY.x * scale.x - 1.0, 1.0 - XY.y * scale.y, 0.0, 1.0);\n"
    "}\n";

/* ...VBO fragment shader */
static const char *line_fragment_shader =
    SH_SETPREC
    "varying vec2 xy;\n"
    "varying vec4 c;\n"
    "varying vec3 eq;\n"
    "uniform vec2 width;\n"
    "uniform float intensity;\n"
    "void main()\n"
    "{\n"
    "   float   d = abs(dot(xy, eq.xy) - eq.z);\n"
    "   float   w = clamp((width.x - d) * width.y, 0.0, 1.0);\n"
    "   gl_FragColor = vec4(c.rgb, c.a * w) * intensity;\n"
    "}\n";

/* ...specify shader name */
#define SHADER_TAG                  LINE
#define SHADER_VERTEX_SOURCE        line_vertex_shader
#define SHADER_FRAGMENT_SOURCE      line_fragment_shader

/* ...define list of attributes */
#define SHADER_ATTRIBUTES                               \
    __A(XY), __A(C), __A(EQ),

/* ...define list of uniforms */
#define SHADER_UNIFORMS                         \
    __U(scale), __U(width), __U(intensity),

/* ...build shader lists */
#include "../src/shader-impl.h"

/**
 * @brief   Return shader object for line rendering
 *
 * @return                  Shader pointer, or NULL in case of error
 */
static shader_data_t * line_get_shader(void)
{
    static shader_data_t * __shader;

    if (__shader == NULL)
    {
        __shader = shader_create(&SHADER_DESC(LINE));
    }

    return __shader;
}

/**
 * @brief   Draw rectangle of specified width/color
 *
 * @param   ctx[in]         Rendering context
 * @param   dst[in]         Rectangle tile
 * @param   bg[in]          Background color
 * @param   intensity[in]   Global scene intensity
 */

#define U(id)       u[UNIFORM(LINE, id)]
#define A(id)       ATTRIBUTE(LINE, id)

static void gfx_draw_lines(vbo_dynarray_t *vbo, render_context_t *ctx, /*float32_t *eq,*/ float32_t width, float32_t border, float32_t intensity)
{
    void           *XY_off = vbo_dynarray_buffer(vbo, sizeof(gfx_vertex_t));
    void           *C_off = XY_off + 2 * sizeof(GLfloat);
    void           *EQ_off = C_off + 4 * sizeof(GLfloat);
    const size_t    vbo_size = sizeof(gfx_vertex_t);
    shader_data_t  *shader = line_get_shader();

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

    /* ...set equation params */
    //glUniform3fv(U(eq), 1, eq);

    /* ...set width / border width parameters */
    glUniform2fv(U(width), 1, (GLfloat [2]){ width, (border > 0.0f ? 1.0f / border : 1e+6) });

    /* ...bind attributes */
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glEnableVertexAttribArray(A(XY));
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, vbo_size, XY_off);

    glEnableVertexAttribArray(A(C));
    glVertexAttribPointer(A(C), 4, GL_FLOAT, GL_FALSE, vbo_size, C_off);

    glEnableVertexAttribArray(A(C));
    glVertexAttribPointer(A(EQ), 3, GL_FLOAT, GL_FALSE, vbo_size, EQ_off);

    /* ...generate closed line-strip with foreground color */
    glDrawArrays(GL_TRIANGLES, 0, vbo_dynarray_num(vbo));      GLCHECK();

    TRACE(0, _b("render %d points"), vbo_dynarray_num(vbo));

    /* ...clear after the program */
    glUseProgram(0);
}

#undef U
#undef A

/**
 * @brief   Encode GFX vertex
 *
 * @param   v[in]           Vertex pointer
 * @param   xy[in]          XY-coordinates (in pixels)
 * @param   c[in]           RGBA-color
 * @param   equ[in]         Line equation (a*x + b*y = c)
 *
 * @return                  Updated vertex pointer
 */
static gfx_vertex_t * gfx_add_vertex(gfx_vertex_t *v, float32_t *xy, float32_t *c, float32_t *equ)
{
    memcpy(&(*v)[0], xy, sizeof(float32_t[2]));
    memcpy(&(*v)[2], c, sizeof(float32_t[4]));
    memcpy(&(*v)[6], equ, sizeof(float32_t[3]));

    return ++v;
}

/**
 * @brief   Add line segment to a render-list
 *
 * @param   vbo[in]         Vertices dynamic array
 */
static int line_add_segment(vbo_dynarray_t *vbo, float32_t x0, float32_t y0, float32_t x1, float32_t y1, float32_t *c0, float32_t *c1, float32_t width)
{
    /* ...line equation */
    float32_t   eq[3] = {
        y0 - y1, x1 - x0, x1 * y0 - y1 * x0,
    };

    /* ...normalize coefficients */
    float32_t   norm2 = sqrtf(eq[0] * eq[0] + eq[1] * eq[1]);
    norm2 = (norm2 > 0.0f ? 1.0f / norm2 : 1.0f);
    eq[0] *= norm2, eq[1] *= norm2, eq[2] *= norm2;

    float32_t   hw = width * 0.5f + 1.0f;
    float32_t   normal[2] = { eq[0] * hw, eq[1] * hw };

    /* ...create rectangle containing the line */
    float32_t   P[4][2] = {
        [0] = { x0 + normal[0], y0 + normal[1] },
        [1] = { x0 - normal[0], y0 - normal[1] },
        [2] = { x1 + normal[0], y1 + normal[1] },
        [3] = { x1 - normal[0], y1 - normal[1] },
    };

    gfx_vertex_t   *v;

    CHK_ERR(v = vbo_dynarray_add(vbo, sizeof(*v), 6), -1);

    /* ...encode quad as two triangles {0,1,2}, {2,1,3} */
    v = gfx_add_vertex(v, P[0], c0, eq);
    v = gfx_add_vertex(v, P[1], c0, eq);
    v = gfx_add_vertex(v, P[2], c1, eq);
    v = gfx_add_vertex(v, P[2], c1, eq);
    v = gfx_add_vertex(v, P[1], c0, eq);
    v = gfx_add_vertex(v, P[3], c1, eq);

    TRACE(0, _b("add_line: equ=%f,%f,%f, P=%f,%f : %f,%f : %f,%f : %f,%f"), eq[0], eq[1], eq[2],
          P[0][0], P[0][1], P[1][0], P[1][1], P[2][0], P[2][1], P[3][0], P[3][1]);

    return 0;
}

/**
 * @brief   Draw line segment
 *
 * @param   ctx[in]         Rendering context
 * @param   p0[in]          Line start point
 * @param   p1[in]          Line stop point
 * @param   c0[in]          Start point color, RGBA
 * @param   c1[in]          Stop point color, RGBA
 * @param   width[in]       Line width, pixels
 * @param   border[in]      Line border gradient width, pixels
 * @param   intensity[in]   Scene intensity
 */
void line_draw(render_context_t *ctx, float32_t *p0, float32_t *p1, float32_t *c0, float32_t *c1, float32_t width, float32_t border, float32_t intensity)
{
    static vbo_dynarray_t  vbo;

    /* ...reset VBO array */
    vbo_dynarray_clear(&vbo, sizeof(gfx_vertex_t));

    /* ...add single line segment */
    line_add_segment(&vbo, p0[0], p0[1], p1[0], p1[1], c0, c1, width);

    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);

    /* ...render line */
    gfx_draw_lines(&vbo, ctx, width, border, intensity);
}

/**
 * @brief   Draw a rectangle
 *
 * @param   ctx[in]         Rendering context
 * @param   p0[in]          Upper-left corner
 * @param   p1[in]          Bottom-right corner
 * @param   c0[in]          UL point color, RGBA
 * @param   c1[in]          BL point color, RGBA
 * @param   c2[in]          UR point color, RGBA
 * @param   c3[in]          BR point color, RGBA
 * @param   width[in]       Line width, pixels
 * @param   border[in]      Line border gradient width, pixels
 * @param   intensity[in]   Scene intensity
 */
void rect_draw(render_context_t *ctx, float32_t *p0, float32_t *p1, float32_t *c0, float32_t *c1, float32_t *c2, float32_t *c3, float32_t width, float32_t border, float32_t intensity)
{
    static vbo_dynarray_t  vbo;

    /* ...reset VBO array */
    vbo_dynarray_clear(&vbo, sizeof(gfx_vertex_t));

    /* ...add 4 line segments */
    line_add_segment(&vbo, p0[0], p0[1], p1[0], p0[1], c0, c1, width);
    line_add_segment(&vbo, p1[0], p0[1], p1[0], p1[1], c1, c3, width);
    line_add_segment(&vbo, p1[0], p1[1], p0[0], p1[1], c3, c2, width);
    line_add_segment(&vbo, p0[0], p1[1], p0[0], p0[1], c2, c0, width);

    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);

    /* ...render line */
    gfx_draw_lines(&vbo, ctx, width, border, intensity);
}

/**
 * @brief   Render polygon
 *
 * @param   ctx[in]         Rendering context
 * @param   p[in]           Points array
 * @param   c[in]           Colors array
 * @param   num[in]         Number of points
 * @param   width[in]       Line width, pixels
 * @param   border[in]      Line border gradient width, pixels
 * @param   intensity[in]   Scene intensity
 */
void poly_draw(render_context_t *ctx, float32_t (*p)[2], float32_t (*c)[4], uint32_t num, float32_t width, float32_t border, float32_t intensity)
{
    static vbo_dynarray_t   vbo;
    int                     i;

    /* ...reset VBO array */
    vbo_dynarray_clear(&vbo, sizeof(gfx_vertex_t));

    for (i = 0; i < num - 1; i++)
    {
        line_add_segment(&vbo, p[i][0], p[i][1], p[i + 1][0], p[i + 1][1], c[i], c[i + 1], width);
    }

    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);

    /* ...render line */
    gfx_draw_lines(&vbo, ctx, width, border, intensity);
}

/*******************************************************************************
 * Ellipse/arc rendering
 ******************************************************************************/

/**> Vertex data: {X,Y} + {R,G,B,A} + {F0,F1,2a,r} */
typedef GLfloat  gfx2_vertex_t[12];

/*******************************************************************************
 * Solid-color shader construction
 ******************************************************************************/

/* ...vertex shader */
static const char *circle_vertex_shader =
    SH_SETPREC
    "attribute vec2	XY;\n"
    "attribute vec4 C;\n"
    "attribute vec4 F;\n"
    "attribute vec2 A;\n"
    "uniform vec2 scale;\n"
    "varying vec2 xy;\n"
    "varying vec4 c;\n"
    "varying vec4 f;\n"
    "varying vec2 a;\n"
    "void main(void)\n"
    "{\n"
    "   xy = XY;\n"
    "   c = C;\n"
    "   f = F;\n"
    "   a = A;\n"
    "	gl_Position = vec4(XY.x * scale.x - 1.0, 1.0 - XY.y * scale.y, 0.0, 1.0);\n"
    "}\n";

/* ...VBO fragment shader */
static const char *circle_fragment_shader =
    SH_SETPREC
    "varying vec2 xy;\n"
    "varying vec4 c;\n"
    "varying vec4 f;\n"
    "varying vec2 a;\n"
    "uniform vec2 width;\n"
    "uniform float intensity;\n"
    "void main()\n"
    "{\n"
    "   float   d = abs(length(xy - f.xy) + length(xy - f.zw) - a.x) * a.y;\n"
    "   float   w = clamp((width.x - d) * width.y, 0.0, 1.0);\n"
    //"   float   w = clamp((width.x - d / 10.0) / 1.0, 0.0, 1.0);\n"
    "   gl_FragColor = vec4(c.rgb, c.a * w) * intensity;\n"
    //"   gl_FragColor = c * intensity;\n"
    "}\n";

/* ...specify shader name */
#define SHADER_TAG                  CIRCLE
#define SHADER_VERTEX_SOURCE        circle_vertex_shader
#define SHADER_FRAGMENT_SOURCE      circle_fragment_shader

/* ...define list of attributes */
#define SHADER_ATTRIBUTES                               \
    __A(XY), __A(C), __A(F), __A(A),

/* ...define list of uniforms */
#define SHADER_UNIFORMS                         \
    __U(scale), __U(width), __U(intensity),

/* ...build shader lists */
#include "../src/shader-impl.h"

/**
 * @brief   Return shader object for circle rendering
 *
 * @return                  Shader pointer, or NULL in case of error
 */
static shader_data_t * circle_get_shader(void)
{
    static shader_data_t * __shader;

    if (__shader == NULL)
    {
        __shader = shader_create(&SHADER_DESC(CIRCLE));
    }

    return __shader;
}

/**
 * @brief   Draw rectangle of specified width/color
 *
 * @param   ctx[in]         Rendering context
 * @param   dst[in]         Rectangle tile
 * @param   bg[in]          Background color
 * @param   intensity[in]   Global scene intensity
 */

#define U(id)       u[UNIFORM(CIRCLE, id)]
#define A(id)       ATTRIBUTE(CIRCLE, id)

static void gfx_draw_circle(vbo_dynarray_t *vbo, render_context_t *ctx, float32_t width, float32_t border, float32_t intensity)
{
    void           *XY_off = vbo_dynarray_buffer(vbo, sizeof(gfx2_vertex_t));
    void           *C_off = XY_off + 2 * sizeof(GLfloat);
    void           *F_off = C_off + 4 * sizeof(GLfloat);
    void           *A_off = F_off + 4 * sizeof(GLfloat);
    const size_t    vbo_size = sizeof(gfx2_vertex_t);
    shader_data_t  *shader = circle_get_shader();

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

    /* ...set width / border width parameters */
    glUniform2fv(U(width), 1, (GLfloat [2]){ width, (border > 0.0f ? 1.0f / border : 1e+6) });

    /* ...bind attributes */
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glEnableVertexAttribArray(A(XY));
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, vbo_size, XY_off);

    glEnableVertexAttribArray(A(C));
    glVertexAttribPointer(A(C), 4, GL_FLOAT, GL_FALSE, vbo_size, C_off);

    glEnableVertexAttribArray(A(F));
    glVertexAttribPointer(A(F), 4, GL_FLOAT, GL_FALSE, vbo_size, F_off);

    glEnableVertexAttribArray(A(A));
    glVertexAttribPointer(A(A), 2, GL_FLOAT, GL_FALSE, vbo_size, A_off);

    /* ...generate closed line-strip with foreground color */
    glDrawArrays(GL_TRIANGLES, 0, vbo_dynarray_num(vbo));      GLCHECK();

    TRACE(DEBUG, _b("render %d points"), vbo_dynarray_num(vbo));

    /* ...clear after the program */
    glUseProgram(0);
}

#undef U
#undef A

/**
 * @brief   Encode circle vertex
 *
 * @param   v[in]           Vertex pointer
 * @param   xy[in]          XY-coordinates (in pixels)
 * @param   c[in]           RGBA-color
 * @param   equ[in]         Circle equation (f0.xy, f1.xy, 2*a)
 *
 * @return                  Updated vertex pointer
 */
static gfx2_vertex_t * gfx2_add_vertex(gfx2_vertex_t *v, float32_t *xy, float32_t *c, float32_t *equ)
{
    memcpy(&(*v)[0], xy, sizeof(float32_t[2]));
    memcpy(&(*v)[2], c, sizeof(float32_t[4]));
    memcpy(&(*v)[6], equ, sizeof(float32_t[6]));

    return ++v;
}

/**
 * @brief   Render elliptical arc
 *
 * @param   ctx[in]         Rendering context
 * @param   f0[in]          First focal point
 * @param   f1[in]          Second focal point
 * @param   b[in]           Minor axis length
 * @param   a0[in]          Start angle, radians
 * @param   a1[in]          End angle, radians
 * @param   color[in]       Color, RGBA
 * @param   width[in]       Line width, pixels
 * @param   border[in]      Border gradient width, pixels
 * @param   intensity[in]   Intensity level
 */
int ellipse_draw(render_context_t *ctx, float32_t *f0, float32_t *f1, float32_t b, float32_t a0, float32_t a1, float32_t *color, float32_t width, float32_t border, float32_t intensity)
{
    static vbo_dynarray_t   vbo;
    int                     i;

    /* ...reset VBO array */
    vbo_dynarray_clear(&vbo, sizeof(gfx2_vertex_t));

    /* ...center of ellipse */
    float32_t   C0[2] = { (f0[0] + f1[0]) * 0.5f, (f0[1] + f1[1]) * 0.5f };

    /* ...vector F1 - F0 */
    float32_t   df[2] = { f1[0] - f0[0], f1[1] - f0[1] };

    /* ...angle of main axis */
    float32_t   alpha = atan2f(df[1], df[0]);
    float32_t   C = cosf(alpha);
    float32_t   S = sinf(alpha);

    /* ...it could be probable somehow evaluated for radius and things - tbd */
    int         N = 32;

    float32_t   b2 = b * b;
    float32_t   a2 = b2 + (df[0] * df[0] + df[1] * df[1]) * 0.25f;

    /* ...main axis of an ellipse */
    float32_t   a = sqrtf(a2);

    /* ...convert radial angles to angle in polar coordinates */
    float32_t   A0 = atan2f(a * sinf(a0), b * cosf(a0));
    float32_t   A1 = atan2f(a * sinf(a1), b * cosf(a1));

    /* ...get theta increment */
    float32_t   da = fmodf(A1 - A0 + (float32_t)(2.0 * M_PI), (float32_t)(2.0 * M_PI));

    TRACE(1, _b("a0=%f, a1=%f, A0=%f, A1=%f, da=%f"), a0, a1, A0, A1, da);

    int         closed = (fabsf(da) < 1e-3f);
    float32_t   theta = closed ? (float32_t)(2.0 * M_PI) / N : da / (float32_t)(N - 1);

    float32_t   hw = width * 0.5f + 1.0f;
    float32_t   amin = a - hw, amax = a + hw;
    float32_t   bmin = b - hw, bmax = b + hw;

    float32_t   eq[6] = { f0[0], f0[1], f1[0], f1[1], 2.0f * a, 0.0f };

    TRACE(0, _b("equ: %f,%f,%f,%f,%f"), eq[0], eq[1], eq[2], eq[3], eq[4]);

    float32_t   P[N][2][2];

    gfx2_vertex_t  *v;

    CHK_ERR(v = vbo_dynarray_add(&vbo, sizeof(*v), (closed ? N : N - 1) * 6), -1);

    /* ...get number of segments we want to draw */
    for (i = 0; i < N; i++)
    {
        float32_t   phi = A0;
        float32_t   c = cosf(phi);
        float32_t   s = -sinf(phi);
        float32_t   x, y;

        eq[5] = sqrtf(b2 * c * c + a2 * s * s) / b;

        x = amin * c;
        y = bmin * s;
        P[i][0][0] = x * C - y * S + C0[0];
        P[i][0][1] = x * S + y * C + C0[1];

        x = amax * c;
        y = bmax * s;
        P[i][1][0] = x * C - y * S + C0[0];
        P[i][1][1] = x * S + y * C + C0[1];

        TRACE(0, _b("[%d]: P0=%f,%f, P1=%f,%f, R=%f"), i, P[i][0][0], P[i][0][1], P[i][1][0], P[i][1][1], eq[5]);

        /* ...advance angle */
        A0 += theta;

        if (i > 0)
        {
            /* ...add quad for a P[i-1] and P[i] */
            v = gfx2_add_vertex(v, P[i - 1][1], color, eq);
            v = gfx2_add_vertex(v, P[i - 1][0], color, eq);
            v = gfx2_add_vertex(v, P[i][1], color, eq);
            v = gfx2_add_vertex(v, P[i][1], color, eq);
            v = gfx2_add_vertex(v, P[i - 1][0], color, eq);
            v = gfx2_add_vertex(v, P[i][0], color, eq);
        }
    }

    if (closed)
    {
        float32_t   c = cosf(a0);
        float32_t   s = sinf(a0);

        eq[5] = sqrtf(b2 * c * c + a2 * s * s) / b;

        /* ...add quad for a P[i-1] and P[0] */
        v = gfx2_add_vertex(v, P[N - 1][1], color, eq);
        v = gfx2_add_vertex(v, P[N - 1][0], color, eq);
        v = gfx2_add_vertex(v, P[0][1], color, eq);
        v = gfx2_add_vertex(v, P[0][1], color, eq);
        v = gfx2_add_vertex(v, P[N - 1][0], color, eq);
        v = gfx2_add_vertex(v, P[0][0], color, eq);
    }

    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);

    /* ...render line */
    gfx_draw_circle(&vbo, ctx, width, border, intensity);

    return 0;
}
