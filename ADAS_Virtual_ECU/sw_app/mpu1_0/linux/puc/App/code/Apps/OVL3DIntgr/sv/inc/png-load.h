/*******************************************************************************
 * png-load.c
 *
 * PNG loading / storing support
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

#ifndef __PNG_LOAD_H
#define __PNG_LOAD_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "list.h"

/*******************************************************************************
 * Constants definitions
 ******************************************************************************/

/**> Maximal number of video streams supported */
#define PNG_CAMERAS_NUMBER          32

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**
 * @brief   PNG image descriptor
 */
typedef struct png_image_desc
{
    /**> File name */
    char           *filename;

    /**> Image width */
    int             width;

    /**> Image height */
    int             height;

    /**> Image format */
    int             format;

    /**> Private data */
    void           *priv;

}   png_image_desc_t;

/**
 * @brief   Processing job
 */
typedef struct png_job
{
    /**> Job list descriptor */
    __list_t            link;

    /**> Textures wrapping input buffers */
    texture_data_t     *texture[PNG_CAMERAS_NUMBER];

    /**> Job timestamp */
    uint64_t            timestamp;

    /**> Application private data */
    void               *priv;

}   png_job_t;

/**> Opaque declaration of PNG player */
typedef struct png_data     png_data_t;

/*******************************************************************************
 * Utility functions
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
extern int store_png(const char *path, int width, int height, int format, int vflip, void *data);

/*******************************************************************************
 * PNG loader API
 ******************************************************************************/

/**
 * @brief   Get next ready job
 *
 * @param   png[in]         PNG loader handle
 *
 * @return                  Job descriptor, or NULL on failure
 */
extern png_job_t * png_get_next_job(png_data_t *png);

/**
 * @brief   Release job
 *
 * @param   png[in]         PNG loader handle
 * @param   job[in]         Job descriptor
 */
extern void png_release_job(png_data_t *png, png_job_t *job);

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
extern png_data_t * png_loader_init(png_image_desc_t *desc, uint32_t number, uint32_t jobs, uint32_t period);

/**
 * @brief   Destroy PNG loader
 *
 * @param   mkv[in]     PNG-loader handle
 */
extern void png_loader_destroy(png_data_t *png);

/**
 * @brief   Retrieve basic video file info
 *
 * @param   png[in]         PNG loader handle
 * @param   id[in]          Stream index
 * @param   width[out]      Video-frame width
 * @param   height[out]     Video-frame height
 * @param   format[out]     Video-frame format
 * @param   data[out]       Pixel-dataCodec ID
 *
 * @return                  Negative on failure
 */
extern int png_video_stream_info(png_data_t *png, uint32_t id, uint32_t *width, uint32_t *height, int *format, void **data);

#endif  /* __PNG_LOAD_H */
