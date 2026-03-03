/*******************************************************************************
 * bmp-load.c
 *
 * BMP loading / storing support
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

#ifndef __BMP_LOAD_H
#define __BMP_LOAD_H

/*******************************************************************************
 * Utility functions
 ******************************************************************************/

/**
 * @brief   Load BMP file
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
extern int load_bmp(const char *path, int *width, int *height, int *format, void **data);

/**
 * @brief   Write BMP file
 *
 * @param   path[in]            File name
 * @param   width[in, out]      Image width
 * @param   height[in, out]     Image height
 * @param   format[in, out]     Image format
 * @param   data[in, out]       Pointer to the pixel-data buffer
 *
 * @return                      Negative on failure
 */
extern int store_bmp(const char *path, int width, int height, int format, void *data);

#endif  /* __BMP_LOAD_H */
