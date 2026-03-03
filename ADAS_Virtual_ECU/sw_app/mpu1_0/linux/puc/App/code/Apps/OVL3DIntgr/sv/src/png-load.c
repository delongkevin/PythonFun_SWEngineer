/*******************************************************************************
 * png-load.c
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
#include "png-load.h"
#include <png.h>
#include "sv_api.h"

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Global constants
 ******************************************************************************/

/**> Default number of PNG jobs */
#define PNG_JOBS_NUMBER         8

/*******************************************************************************
 * Local typedefs
 ******************************************************************************/

/**
 * @brief   Image descriptor
 */
typedef struct png_image_data
{
    /**> Image width */
    int                 width;

    /**> Image height */
    int                 height;

    /**> Image format - tbd - get rid of GStreamer definitions eventually */
    int                 format;

    /**> Pixel-data array */
    void               *data;

    /**> Texture data */
    texture_data_t     *texture;

}   png_image_data_t;

/**
 * @brief   PNG loader data
 */
struct png_data
{
    /**> Number of video streams */
    uint32_t                number;

    /**> Array of image descriptors */
    png_image_data_t       *image;

    /**> Current virtual presentation timestamp */
    uint64_t                pts;

    /**> Nomina frame period (in usec) */
    uint64_t                period;

    /**> Free jobs descriptors */
    __list_t                jobs_free;

    /**> Conditional variable for free jobs waiting */
    pthread_cond_t          wait;

    /**> Internal data protection lock */
    pthread_mutex_t         lock;

    /**> Job descriptors pool */
    png_job_t               job_pool[0];
};

/*******************************************************************************
 * PNG loading
 ******************************************************************************/

/**
 * @brief   PNG reader error handling routine
 */
static __attribute__((noreturn))  void __read_error(png_structp png_ptr, png_const_charp msg)
{
    jmp_buf    *jbp;

    TRACE(ERROR, _b("writepng libpng error: %s"), msg);

    if ((jbp = png_get_error_ptr(png_ptr)) == NULL)
    {
        BUG(1, _x("non-recoverable error"));
    }

    /* ...get back to the writer */
    longjmp(*jbp, EBADF);
}

/**
 * @brief   Load PNG image from proper IO
 *
 * @param   png_ptr[in]         PNG control structure
 * @param   info_ptr[in]        PNG image data
 * @param   width[in, out]      Image width pointer
 * @param   height[in, out]     Image height pointer
 * @param   format[in, out]     Image format pointer
 * @param   data[in, out]       Pointer to the pixel-data buffer
 *
 * @return                      Negative on failure
 */
static int load_png_int(png_structp png_ptr, png_infop info_ptr, int *width, int *height, int *format, void **data)
{
	int                     y, w, h, fmt, stride = 0;
	png_byte                color_type;
	png_byte                bit_depth;
	png_bytep * volatile    row_pointers = NULL;
	png_bytep               row = NULL;

    /* ...start parsing */
    png_set_sig_bytes(png_ptr, 8);
    png_read_info(png_ptr, info_ptr);

    /* ...check image parameters */
    w = png_get_image_width(png_ptr, info_ptr);
    h = png_get_image_height(png_ptr, info_ptr);
    if (!w || !h)
    {
        TRACE(ERROR, _x("invalid image: %u*%u"), w, h);
        errno = EINVAL;
		goto error_png;
    }

    /* ...check image dimensions are expected */
    if ((width && *width && *width != w) || (height && *height && *height != h))
    {
        TRACE(ERROR, _x("wrong image dimensions: %u*%u (expected: %u*%u)"), w, h, (width ? *width : 0), (height ? *height : 0));
        errno = EINVAL;
        goto error_png;
    }
    else
    {
        /* ...save image dimensions */
        (width ? *width = w : 0), (height ? *height = h : 0);
    }

    /* ...process image colorspace */
    color_type = png_get_color_type(png_ptr, info_ptr);
    bit_depth = png_get_bit_depth(png_ptr, info_ptr);
	if (bit_depth < 8 || color_type == PNG_COLOR_TYPE_PALETTE)
		png_set_expand(png_ptr);
	if (bit_depth == 16)
        png_set_strip_16(png_ptr);

    /* ...test color type */
    switch (color_type)
    {
    case PNG_COLOR_TYPE_PALETTE:
        if (!format || *format == GST_VIDEO_FORMAT_ARGB || *format == GST_VIDEO_FORMAT_RGBA || *format == GST_VIDEO_FORMAT_RGB || *format == GST_VIDEO_FORMAT_BGRA)
        {
            png_set_palette_to_rgb(png_ptr);
        }
        else
        {
            TRACE(ERROR, _b("palette image for grayscale format is disabled"));
            errno = EINVAL;
            goto error_png;
        }
        break;
	case PNG_COLOR_TYPE_GRAY_ALPHA:
	case PNG_COLOR_TYPE_GRAY:
        if (format && (*format == GST_VIDEO_FORMAT_ARGB || *format == GST_VIDEO_FORMAT_RGBA || *format == GST_VIDEO_FORMAT_RGB || *format == GST_VIDEO_FORMAT_BGRA))
        {
            png_set_gray_to_rgb(png_ptr);
        }
		break;
    case PNG_COLOR_TYPE_RGB:
        if (!format || *format == GST_VIDEO_FORMAT_ARGB || *format == GST_VIDEO_FORMAT_RGBA || *format == GST_VIDEO_FORMAT_BGRA)
        {
            png_set_add_alpha(png_ptr, 0xFF, PNG_FILLER_AFTER);
        }
        break;
    case PNG_COLOR_TYPE_RGB_ALPHA:
        if (format && *format == GST_VIDEO_FORMAT_RGB)
        {
            png_set_strip_alpha(png_ptr);
        }
        break;

	default:
		break;
	}

    /* ...native format that we use is BGRA - hmm, tbd */
    if ((color_type & PNG_COLOR_MASK_COLOR) && format && *format == GST_VIDEO_FORMAT_BGRA)
        png_set_bgr(png_ptr);

    /* ...update image info after parameters adjustment */
    png_read_update_info(png_ptr, info_ptr);
    color_type = png_get_color_type(png_ptr, info_ptr);
	switch (color_type)
    {
	case PNG_COLOR_TYPE_RGB_ALPHA:
		fmt = GST_VIDEO_FORMAT_ARGB;
		break;
	case PNG_COLOR_TYPE_RGB:
		fmt = GST_VIDEO_FORMAT_RGB;
		break;
    case PNG_COLOR_TYPE_GRAY:
        fmt = GST_VIDEO_FORMAT_GRAY8;
        break;
	default:
        TRACE(ERROR, _x("unsupported color type: %X"), color_type);
        errno = EINVAL;
        goto error_png;
	}

    /* ...if format is specified, test we have correctly set it */
    if (0 && format && *format && *format != fmt)
    {
        TRACE(ERROR, _x("wrong image colorspace: %d (expected %d)"), fmt, *format);
        errno = EINVAL;
        goto error_png;
    }

    /* ...get image stride */
    stride = png_get_rowbytes(png_ptr, info_ptr);

    /* ...make it 4-bytes aligned (why would we do that? - tbd) */
    //stride = (stride + 3) & ~3;

    /* ...set pixeldata pointer */
    if (*data == NULL)
    {
        /* ...allocate pixeldata */
        if ((row = malloc(stride * h)) == NULL)
        {
            TRACE(ERROR, _x("failed to allocate image data"));
            errno = ENOMEM;
            goto error_png;
        }
    }
    else
    {
        /* ...use provided buffer for pixeldata */
        row = *data;
    }

    /* ...allocate row pointers array */
    if ((row_pointers = malloc(sizeof(png_bytep) * h)) == NULL)
    {
        TRACE(ERROR, _x("failed to create row-pointers array"));
        errno = ENOMEM;
        goto error_png;
    }

    /* ...initialize row pointers */
    for (y = 0; y < h; y++, row += stride)
        row_pointers[y] = row;

    /* ...read image */
    png_read_image(png_ptr, row_pointers);

    /* ...save row pointer if needed */
    (*data == NULL ? *data = row_pointers[0] : 0);

    TRACE(INIT, _b("PNG image %u*%u created: %p"), w, h, *data);

    /* ...release interim memory */
	free(row_pointers);

    (format ? *format = fmt : 0);

    return 0;

error_png:
    /* ...release rows */
    (row && row != *data ? free(row) : 0), (row_pointers ? free(row_pointers) : 0);

	return -1;
}

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
int load_png(const char *path, int *width, int *height, int *format, void **data)
{
	FILE               *fp;
    unsigned char       header[8];
	png_structp         png_ptr;
    png_infop           info_ptr;
    jmp_buf             jb;
    volatile int        r = -1;

    /* ...sanity check - data buffer pointer must be provided */
    CHK_ERR(data, -EINVAL);

    /* ...open image file */
	if ((fp = fopen(path, "rb")) == NULL)
    {
        TRACE(ERROR, _x("failed to open '%s': %s"), path, strerror(errno));
        return -errno;
    }

    /* ...parse image header */
    if (fread(header, 8, 1, fp) != 1)
    {
        TRACE(ERROR, _x("failed to read header: %s"), strerror(errno));
        goto error;
    }

    if (png_sig_cmp(header, 0, 8))
    {
        TRACE(ERROR, _x("invalid image '%s'"), path);
        errno = EBADF;
        goto error;
    }

    /* ...initialize PNG library handle */
    if ((png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, &jb, __read_error, NULL)) == NULL)
    {
        TRACE(ERROR, _x("failed to read image '%s': %s"), path, strerror(errno));
        errno = EBADF;
        goto error;
    }

    /* ...allocate image info */
    if ((info_ptr = png_create_info_struct(png_ptr)) == NULL)
    {
        TRACE(ERROR, _x("failed to read image '%s': %s"), path, strerror(errno));
        errno = EBADF;
        goto error;
    }

    /* ...initialize PNG parser; prepare emergency return point */
    if ((errno = setjmp(jb)) != 0)
    {
        TRACE(ERROR, _x("operation failed"));
        goto error;
    }

    /* ...start parsing from file */
    png_init_io(png_ptr, fp);

    /* ...do actual loading */
    r = load_png_int(png_ptr, info_ptr, width, height, format, data);

error:
    /* ...destroy PNG data */
	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

    /* ...close file handle */
    fclose(fp);

    return r;
}

/**
 * @brief   Memory IO data for reading
 */
typedef struct png_read_buf
{
    /**> Current pointer */
    void           *ptr;

    /**> Remaining length */
    size_t          size;

}   png_read_buf_t;

/**> Buffer reading callback */
static void png_read_mem(png_structp png_ptr, png_bytep buf, size_t size)
{
    png_read_buf_t  *read_buf = (png_read_buf_t *)png_get_io_ptr(png_ptr);

    (size > read_buf->size ? size = read_buf->size : 0);

    if (size > 0)
    {
        memcpy(buf, read_buf->ptr, size);
        read_buf->ptr += size, read_buf->size -= size;
    }
}

/**
 * @brief   Load PNG file from memory buffer
 *
 * @param   buf[in]             Buffer pointer
 * @param   size[in]            Buffer size
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
int load_png_from_mem(void *buf, size_t size, int *width, int *height, int *format, void **data)
{
	png_structp         png_ptr;
    png_infop           info_ptr;
    jmp_buf             jb;
    volatile int        r = -1;

    /* ...sanity check - data buffer pointer must be provided */
    CHK_ERR(data, -(errno = EINVAL));

    /* ...make sure input buffer is valid */
    CHK_ERR(buf && size > 8, -(errno = EINVAL));

    /* ...check image is PNG */
    if (png_sig_cmp(buf, 0, 8))
    {
        TRACE(ERROR, _x("invalid image"));
        errno = EBADF;
        goto error;
    }

    png_read_buf_t      read_buf = { buf + 8, size - 8 };

    /* ...initialize PNG library handle */
    if ((png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, &jb, __read_error, NULL)) == NULL)
    {
        goto error;
    }

    /* ...allocate image info */
    if ((info_ptr = png_create_info_struct(png_ptr)) == NULL)
    {
        TRACE(ERROR, _x("failed to read image: %s"), strerror(errno));
        goto error;
    }

    /* ...initialize PNG parser; prepare emergency return point */
    if ((errno = setjmp(jb)) != 0)
    {
        TRACE(ERROR, _x("operation failed"));
        goto error;
    }

    /* ...set reading function */
    png_set_read_fn(png_ptr, &read_buf, png_read_mem);

    /* ...do actual loading */
    r = load_png_int(png_ptr, info_ptr, width, height, format, data);

error:
    /* ...destroy PNG data */
	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

    return r;
}

/*******************************************************************************
 * PNG storing
 ******************************************************************************/

/**
 * @brief   PNG writer error handling routine
 */
static __attribute__((noreturn))  void __write_error(png_structp png_ptr, png_const_charp msg)
{
    jmp_buf    *jbp;

    TRACE(ERROR, _b("writepng libpng error: %s"), msg);

    if ((jbp = png_get_error_ptr(png_ptr)) == NULL)
    {
        BUG(1, _x("non-recoverable error"));
    }

    /* ...get back to the writer */
    longjmp(*jbp, EBADF);
}

/**
 * @brief   Write PNG file
 *
 * @param   path[in]            File name
 * @param   width[in]           Image width
 * @param   height[in]          Image height
 * @param   format[in]          Image format
 * @param   vflip[in]           Flip image vertically
 * @param   data[in]            Pointer to the pixel-data buffer
 *
 * @return                      Negative on failure
 */
int store_png(const char *path, int width, int height, int format, int vflip, void *data)
{
	FILE           *fp;
	int             y, stride = 0;
	png_byte        color_type;
	png_byte        bit_depth;
	png_structp     png_ptr;
	png_infop       info_ptr;
	png_bytep       row = NULL;
    jmp_buf         jb;

    /* ...sanity check */
    CHK_ERR(path && width > 0 && height >= 0 && format > 0 && data, -EINVAL);

    /* ...prepare file for writing */
    if ((fp = fopen(path, "wb")) == NULL)
    {
        TRACE(ERROR, _x("failed to open file '%s': %m"), path);
        return -errno;
    }

    /* ...create write structure */
    if (!(png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, &jb, __write_error, NULL)))
    {
        TRACE(ERROR, _x("failed to create write struct: %m"));
        errno = ENOMEM;
        goto error;
    }

    if (!(info_ptr = png_create_info_struct(png_ptr)))
    {
        TRACE(ERROR, _x("failed to create info struct: %m"));
        errno = ENOMEM;
        goto error_png;
    }

    /* ...prepare emergency return point */
    if ((errno = setjmp(jb)) != 0)
    {
        TRACE(ERROR, _x("operation failed"));
        goto error_png;
    }

    /* ...initialize I/O */
    png_init_io(png_ptr, fp);

    /* ...set compression level (zlib 0 to 9) */
    //png_set_compression_level(png_ptr, 9);

    /* ...set color format */
    switch (format)
    {
    case GST_VIDEO_FORMAT_GRAY8:
        color_type = PNG_COLOR_TYPE_GRAY, bit_depth = 8;
        break;
    case GST_VIDEO_FORMAT_ARGB:
    case GST_VIDEO_FORMAT_RGBA:
        color_type = PNG_COLOR_TYPE_RGB_ALPHA, bit_depth = 32;
        break;
    case GST_VIDEO_FORMAT_RGB:
        color_type = PNG_COLOR_TYPE_RGB, bit_depth = 24;
        break;
    default:
        TRACE(ERROR, _x("unsupported format %d"), format);
        errno = EINVAL;
        goto error_png;
    }

    TRACE(DEBUG, _b("prepare writing: w=%d, h=%d, d=%d, c=%d"), width, height, bit_depth, color_type);

    /* ...native format that we use is BGRA - hmm, tbd */
    (0 & color_type & PNG_COLOR_MASK_COLOR ? png_set_bgr(png_ptr) : 0);

    /* ...write header */
    png_set_IHDR(png_ptr, info_ptr, width, height, 8, color_type, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    /* ...write info structure */
    png_write_info(png_ptr, info_ptr);

    /* ...write all image rows */
    stride = (width * bit_depth) >> 3;
    if (vflip)
    {
        row = data + stride * (height - 1);
        for (y = 0; y < height; y++, row -= stride)
            png_write_row(png_ptr, row);
    }
    else
    {
        row = data;
        for (y = 0; y < height; y++, row += stride)
            png_write_row(png_ptr, row);
    }

    /* ...mark completion of the image */
    png_write_end(png_ptr, NULL);

    TRACE(INFO, _b("written file '%s': %d*%d, format=%d"), path, width, height, format);

    /* ...cleanup after ourselves */
    png_destroy_write_struct(&png_ptr, NULL);

    fclose(fp);

    return 0;

error_png:
    /* ...destroy write structure */
    png_destroy_write_struct(&png_ptr, NULL);

error:
    /* ...close file handle */
    fclose(fp);
    return -1;
}

/*******************************************************************************
 * Replay of PNG loading support
 ******************************************************************************/

/**
 * @brief   Get next ready job
 *
 * @param   png[in]         PNG loader handle
 *
 * @return                  Job descriptor, or NULL if no descriptor found
 */
png_job_t * png_get_next_job(png_data_t *png)
{
    png_job_t  *job;

    pthread_mutex_lock(&png->lock);

    /* ...wait for a job descriptor as required */
    while (__list_is_empty(&png->jobs_free))
    {
        pthread_cond_wait(&png->wait, &png->lock);
    }

    /* ...get job from the gead of the free list */
    job = container_of(__list_pop_head(&png->jobs_free), png_job_t, link);

    /* ...set presentation timestamp */
    job->timestamp = png->pts;

    /* ...advance current timestamp */
    png->pts += png->period;

    pthread_mutex_unlock(&png->lock);

    return job;
}

/**
 * @brief   Release job
 *
 * @param   png[in]         PNG loader handle
 * @param   job[in]         Job descriptor
 */
void png_release_job(png_data_t *png, png_job_t *job)
{
    pthread_mutex_lock(&png->lock);

    __list_push_tail(&png->jobs_free, &job->link);

    pthread_mutex_unlock(&png->lock);

    /* ...notify (possibly) waiting thread on job descriptor availability */
    pthread_cond_signal(&png->wait);
}


/**
 * @brief   PNG-loader initialization
 *
 * @param   desc[in]        Array of images descriptors
 * @param   number[int]     Number of images
 * @param   jobs[in]        Number of jobs descriptors to allocate
 * @param   period[in]      Nominal frame period, usec
 *
 * @return                  PNG-loader handle, or NULL on failure
 */
png_data_t * png_loader_init(png_image_desc_t *desc, uint32_t number, uint32_t jobs, uint32_t period)
{
    png_data_t     *png;
    int             i, k;

    /* ...determine number of jobs */
    (jobs == 0U ? jobs = PNG_JOBS_NUMBER : 0);

    /* ...allocate PNG-loader data memory */
    CHK_ERR(png = calloc(1, sizeof(*png) + jobs * sizeof(png_job_t)), NULL);

    /* ...allocate image descriptors */
    if ((png->image = calloc(number, sizeof(*png->image))) == NULL)
    {
        TRACE(ERROR, _x("failed to allocate %u image descriptors"), number);
        goto error;
    }

    /* ...load all images */
    for (i = 0; i < number; i++)
    {
        png_image_data_t   *image = &png->image[i];
        char               *filename = desc[i].filename;
        int                 w = desc[i].width;
        int                 h = desc[i].height;
        int                 f = desc[i].format;
        void               *priv = desc[i].priv;

        image_data_t        img;

        /* ...create texture for an image */
        if (priv != NULL)
        {
            CHK_ERR(image->texture = texture_create_native(priv, 1), NULL);
        }
        else
        {
            CHK_ERR(image->texture = texture_create(w, h, f), NULL);
        }

        /* ...get buffer pointer */
        CHK_ERR(texture_map(image->texture, &img) >= 0, NULL);

        void       *data = img.data[0];
        uint32_t    size = img.size;

        /* ...check for a file extension */
        const char     *ext;

        if ((ext = strrchr(filename, '.')) != NULL && !strcasecmp(ext + 1, "png"))
        {
            int     format;

            if (f == SCREEN_FORMAT_RGB888)
            {
                format = GST_VIDEO_FORMAT_RGB;
            }
            else if (f == SCREEN_FORMAT_RGBA8888)
            {
                format = GST_VIDEO_FORMAT_BGRA;
            }
            else if (f == SCREEN_FORMAT_BYTE)
            {
                format = GST_VIDEO_FORMAT_GRAY8;
            }
            else
            {
                TRACE(ERROR, _x("unsupported format %u"), f);
                errno = EINVAL;
                goto error_img;
            }

            /* ...load image into interim buffer */
            if (load_png(filename, &w, &h, &format, &data) < 0)
            {
                TRACE(ERROR, _x("image-%d: failed to load PNG from '%s': %m"), i, filename);
                goto error_img;
            }
        }
        else
        {
            FILE   *file;

            /* ...load raw image */
            CHK_ERR(file = fopen(filename, "rb"), NULL);
            CHK_ERR(fread(data, size, 1, file) == 1, NULL);
            fclose(file);
        }

        texture_unmap(image->texture);

        TRACE(INIT, _b("image-%d: %d*%d@%d loaded from '%s'"), i, w, h, f, filename);
    }

    /* ...initialize internal data */
    png->number = number;
    png->period = period;

    /* ...initialize list of free jobs */
    __list_init(&png->jobs_free);
    for (k = 0; k < jobs; k++)
    {
        png_job_t  *job = &png->job_pool[k];

        for (i = 0; i < number; i++)
        {
            job->texture[i] = png->image[i].texture;
        }

        /* ...place job into the free descriptors list */
        __list_push_tail(&png->jobs_free, &job->link);

    }

    /* ...initialize mutex / conditional */
    pthread_mutex_init(&png->lock, NULL);
    pthread_cond_init(&png->wait, NULL);

    TRACE(INIT, _b("PNG loader initialized"));

    return png;

error_img:
    /* ...destroy all images */
    for (i = 0; i < number; i++)
    {
        png_image_data_t   *image = &png->image[i];

        (image->data ? free(image->data) : 0);
        (image->texture ? texture_destroy(image->texture) : 0);
    }

error:
    free(png);

    return NULL;
}

/**
 * @brief   Destroy PNG loader
 *
 * @param   png[in]     PNG-loader handle
 */
void png_loader_destroy(png_data_t *png)
{
    /* ...destroy reader data */
    free(png);

    TRACE(INIT, _b("PNG-loader destroyed"));
}
