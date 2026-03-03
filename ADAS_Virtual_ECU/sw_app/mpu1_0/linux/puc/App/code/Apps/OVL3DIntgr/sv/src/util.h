/*******************************************************************************
 * util.h
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

#ifndef __SRC_UTIL_H
#define __SRC_UTIL_H

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Upload GL-texture from file
 *
 * @param   fname[in]           File name
 * @param   tex[in, out]        Texture identifier (generated if 0)
 * @param   width[out]          Texture width, in pixels
 * @param   height[out]         Texture height, in pixels
 *
 * @return                      Negative on failure
 */
extern int tex_upload(const char *fname, GLuint *tex, int32_t *width, int32_t *height, int *levels);

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
extern int tex_upload_from_mem(const char *mime, void *buf, size_t size, GLuint *tex, int32_t *width, int32_t *height);

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
extern int tex_cubemap_upload(const char *fname, GLuint *tex, int32_t *width, int32_t *height, int32_t *levels);

/**
 * @brief   Read YUV-values of particular pixel
 *
 * @param   img[in]         Image descriptor
 * @param   x[in]           X-coordinate
 * @param   y[in]           Y-coordinate
 * @param   yuv[out]        Normalized YUV values
 */
extern void img_get_yuv_bt709_f32(image_data_t *img, int32_t x, int32_t y, float32_t yuv[3]);

/**> Opaque font data declaration */
typedef struct font_data    font_data_t;

/**> Opaque declaration of rendering context */
typedef struct render_context render_context_t;

/**
 * @brief   Font rendering parameters
 */
typedef struct font_render_params
{
    /**> Transform matrix (current position? - tbd) */
    float32_t           matrix[2 * 3];

    /**> Starting position */
    float32_t           start[2];

    /**> Current writing position */
    float32_t           pos[2];

    /**> Total length of text box */
    float32_t           length;

    /**> Text color */
    float32_t           color[4];

}   font_render_params_t;

/**
 * @brief   Font-file loading
 *
 * @param   name[in]        Font file name
 *
 * @return                  Negative on failure
 */
extern font_data_t * font_load(char *name);

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
extern void font_render_params_init(font_render_params_t *params, float32_t x, float32_t y, float32_t angle, float32_t sx, float32_t sy, float32_t *color);

/**
 * @brief   Font rendering function
 *
 * @param   font[in]        Font descriptor
 * @param   ctx[in]         Rendering context
 * @prama   params[in]      Font rendering parameters
 * @param   str[in]         Text string (only printable characters are shown)
 * @param   length[in]      String length
 * @param   intensity[in]   Intensity level
 */
extern int font_render_params(font_data_t *font, render_context_t *ctx, font_render_params_t *params, char *str, int length, float32_t intensity);

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
 __attribute__((format (printf, 5, 6)))
extern int font_render(font_data_t *font, render_context_t *ctx, font_render_params_t *params, float32_t intensity, char *format, ...);

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
extern void line_draw(render_context_t *ctx, float32_t *p0, float32_t *p1, float32_t *c0, float32_t *c1, float32_t width, float32_t border, float32_t intensity);

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
extern void rect_draw(render_context_t *ctx, float32_t *p0, float32_t *p1, float32_t *c0, float32_t *c1, float32_t *c2, float32_t *c3, float32_t width, float32_t border, float32_t intensity);

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
extern void poly_draw(render_context_t *ctx, float32_t (*p)[2], float32_t (*c)[4], uint32_t num, float32_t width, float32_t border, float32_t intensity);

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
extern int ellipse_draw(render_context_t *ctx, float32_t *f0, float32_t *f1, float32_t b, float32_t a0, float32_t a1, float32_t *color, float32_t width, float32_t border, float32_t intensity);


#endif  /* __SRC_UTIL_H */
