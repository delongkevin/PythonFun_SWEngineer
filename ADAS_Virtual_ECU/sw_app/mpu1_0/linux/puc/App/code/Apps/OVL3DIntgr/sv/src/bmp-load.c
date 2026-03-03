/*******************************************************************************
 * bmp-load.c
 *
 * Copyright (c) 2015-2018 Cogent Embedded Inc.
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

#define MODULE_TAG                      PNG

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "bmp-load.h"

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Local typedefs
 ******************************************************************************/

/**
 * @brief   BMP file header
 */
typedef struct bmp_fheader
{
    u8              sig[2];
    u32             size;
    u16             reserved[2];
    u32             offset;

}  __attribute__((packed))  bmp_fheader_t;

/**
 * @brief   BMP image header
 */
typedef struct bmp_iheader
{
    u32             hsize;
    u32             width;
    u32             height;
    u16             planes;
    u16             bpp;
    u32             compression;
    u32             size;
    u32             xppm;
    u32             yppm;
    u32             colors;
    u32             imp_color_count;
    u32             r_mask;
    u32             g_mask;
    u32             b_mask;
    u32             a_mask;
    u32             cst;
    u32             r_gamma;
    u32             g_gamma;
    u32             b_gamma;
    u32             intent;
    u32             icc_profile_data;
    u32             icc_profile_size;
    u32             reserved;

} __attribute__((packed))  bmp_iheader_t;

/*******************************************************************************
 * BMP loading
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
int load_bmp(const char *path, int *width, int *height, int *format, void **data)
{
    FILE           *fp;
    bmp_fheader_t   fh;
    bmp_iheader_t   ih;
    int             channels, bpp, fmt;
    int             w, h, stride, x, y;
    u8             *rows = NULL, *row;

    /* ...sanity check - data buffer pointer must be provided */
    CHK_ERR(data, -EINVAL);

    /* ...open image file */
	if ((fp = fopen(path, "rb")) == NULL)
    {
        TRACE(ERROR, _x("failed to open '%s': %m"), path);
        return -errno;
    }

    /* ...parse image header */
    if (fread(&fh, sizeof(fh), 1, fp) != 1 || fread(&ih, sizeof(ih), 1, fp) != 1)
    {
        TRACE(ERROR, _x("failed to read header: %m"));
        goto error;
    }

    /* ...check image parameters */
    w = ih.width, h = ih.height;
    if (!w || !h)
    {
        TRACE(ERROR, _x("invalid image '%s': %u*%u"), path, w, h);
        errno = EINVAL;
		goto error;
    }

    /* ...check image dimensions are expected */
    if ((width && *width && *width != w) || (height && *height && *height != h))
    {
        TRACE(ERROR, _x("wrong image '%s' dimensions: %u*%u (expected: %u*%u)"), path, w, h, (width ? *width : 0), (height ? *height : 0));
        errno = EINVAL;
        goto error;
    }
    else
    {
        /* ...save image dimensions */
        (width ? *width = w : 0), (height ? *height = h : 0);
    }

    /* ...get channels number */
    channels = (bpp = ih.bpp) >> 3;

    TRACE(INFO, _b("channels: %d, bpp: %d"), channels, bpp);

    /* ...check the palette type? - tbd */
    //colorsNum = *(int *)(ih + 32);

    /* ...check color space format */
    switch (channels)
    {
    case 4:
        fmt = 2;//GST_VIDEO_FORMAT_ARGB;
        break;
    case 3:
        fmt = 1;//GST_VIDEO_FORMAT_RGB;
        break;
    case 1:
        fmt = 0;//GST_VIDEO_FORMAT_GRAY8;
        break;
    default:
        TRACE(ERROR, _x("unsupported color type: channels=%d (%s)"), channels, path);
        errno = EINVAL;
        goto error;
	}

    TRACE(INFO, _b("a-mask: %08X, r-mask: %08X, g-mask: %08X, b-mask: %08X"), ih.a_mask, ih.r_mask, ih.g_mask, ih.b_mask);

    /* ...if format is specified, test we have correctly set it */
    if (format && *format && *format != fmt)
    {
        TRACE(ERROR, _x("wrong image '%s' colorspace: %d (expected %d)"), path, fmt, *format);
        errno = EINVAL;
        goto error;
    }

    /* ...get image stride */
    stride = (w * channels + 3) & ~3;

    /* ...set pixeldata pointer */
    if (*data == NULL)
    {
        /* ...allocate pixeldata */
        if ((rows = malloc(stride * h)) == NULL)
        {
            TRACE(ERROR, _x("failed to allocate image data"));
            errno = ENOMEM;
            goto error;
        }
    }
    else
    {
        /* ...use provided buffer for pixeldata */
        rows = *data;
    }

    /* ...skip the gap if given */
    if ((fh.offset ? fseek(fp, fh.offset, SEEK_SET) : 0))
    {
        TRACE(ERROR, _b("failed to seek the file: %m"));
        goto error;
    }

#if 0
    /* ...read the lines starting from farthest */
    for (row = rows + (y = h) * stride; y > 0; y--)
    {
        if (fread(row -= stride, stride, 1, fp) != 1)
        {
            TRACE(ERROR, _b("failed to read data from file: %m"));
            goto error;
        }
    }
#else
    /* ...read the lines starting from farthest */
    for (row = rows + (y = 0) * stride; y < h; y++, row += stride)
    {
        if (fread(row, stride, 1, fp) != 1)
        {
            TRACE(ERROR, _b("failed to read data from file: %m"));
            goto error;
        }
    }
    row = rows;
#endif

    /* ...convert ARGB to BGRA - need that really? - tbd */
    if (fmt == 2/*GST_VIDEO_FORMAT_ARGB*/)
    {
        u8      shift_r = __builtin_ffs(ih.r_mask) - 1;
        u8      shift_g = __builtin_ffs(ih.g_mask) - 1;
        u8      shift_b = __builtin_ffs(ih.b_mask) - 1;
        u8      shift_a = __builtin_ffs(ih.a_mask) - 1;

        TRACE(1, _b("r:%d,g:%d,b:%d,a:%d"), shift_r, shift_g, shift_b, shift_a);

        for (y = 0; y < h; y++, row += stride)
        {
            for (x = 0; x < w; x++)
            {
                u32     src = *(u32 *)(row + x * 4), dst;

                dst = ((src & ih.a_mask) >> shift_a) << 24;
                dst |= ((src & ih.r_mask) >> shift_r) << 16;
                dst |= ((src & ih.g_mask) >> shift_g) << 8;
                dst |= ((src & ih.b_mask) >> shift_b) << 0;

                *(u32 *)(row + x * 4) = dst;
            }
        }
    }
    else if (fmt == 1/*GST_VIDEO_FORMAT_RGB*/)
    {
        u8      shift_r = __builtin_ffs(ih.r_mask) - 1;
        u8      shift_g = __builtin_ffs(ih.g_mask) - 1;
        u8      shift_b = __builtin_ffs(ih.b_mask) - 1;

        for (y = 0; y < h; y++, row += stride)
        {
            for (x = 0; x < w; x++)
            {
                u32     src = *(u32 *)(row + x * 3), dst;

                dst = ((src & ih.r_mask) >> shift_r) << 8;
                dst |= ((src & ih.g_mask) >> shift_g) << 16;
                dst |= ((src & ih.b_mask) >> shift_b) << 24;

                *(u32 *)(row + x * 3) = dst;
            }
        }
    }

    /* ...save row pointer if needed */
    (*data == NULL ? *data = rows : 0);

    TRACE(INIT, _b("BMP[%s] image %u*%u created: %p"), path, w, h, *data);

    /* ...close file handle */
    fclose(fp);

    return 0;

error:
    /* ...release memory if needed */
    (rows && !*data ? free(rows) : 0);

    /* ...close file handle */
    fclose(fp);

    return -errno;
}

/* ...saving interface? do I need that? - tbd */
