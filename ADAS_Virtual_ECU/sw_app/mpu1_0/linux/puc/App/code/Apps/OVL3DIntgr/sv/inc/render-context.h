/*******************************************************************************
 * render-context.h
 *
 * Rendering context abstraction
 *
 * Copyright (c) 2020 Cogent Embedded Inc.
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

#ifndef __LIBSV_RENDER_CONTEXT_H
#define __LIBSV_RENDER_CONTEXT_H

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**
 * @brief   Rendering context data
 */
typedef struct render_context
{
    /**> Output buffer width (logical) */
    uint32_t            width;

    /**> Output buffer height (logical) */
    uint32_t            height;

    /**> Scaling factor */
    float32_t           scale;
    
}   render_context_t;

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Initialize rendering context
 *
 * @param   ctx[in]     Rendering context
 * @param   width[in]   Output buffer logical width
 * @param   height[in]  Output buffer logical height
 * @param   scale[in]   Scaling factor
 */
static inline void render_context_init(render_context_t *ctx, int32_t width, int32_t height, float32_t scale)
{
    ctx->width = width;
    ctx->height = height;
    ctx->scale = scale;
}

/**> Scale algo-views to fit the screen */
#define SCALE_ALGO_VIEWS    1

/**
 * @brief   Set viewport for rendering 
 *
 * @param   ctx[in]     Rendering context
 * @param   dst[in]     Destination tile in logical coordinates
 */
static inline void render_context_set_view(render_context_t *ctx, int32_t *dst)
{
    float32_t   scale = ctx->scale;
    int32_t     W = ctx->width * scale;
    int32_t     H = ctx->height * scale;
    
    if (dst != NULL)
    {
#if SCALE_ALGO_VIEWS
        if ((uint32_t)dst[2] > ctx->width || (uint32_t)dst[3] > ctx->height)
        {
            float32_t   sx = (float32_t)dst[2] / (float32_t)ctx->width;
            float32_t   sy = (float32_t)dst[3] / (float32_t)ctx->height;

            scale /= (sx > sy ? sx : sy);
        }
#endif
        int32_t     x0 = dst[0] * scale, y0 = dst[1] * scale;
        int32_t     x1 = dst[2] * scale, y1 = dst[3] * scale;

#if USE_EXTERNAL_FBO
        glViewport(x0, y0, x1 - x0, y1 - y0);
        glScissor(x0, y0, x1 - x0, y1 - y0);
#else
        glViewport(x0, H - y1, x1 - x0, y1 - y0);
        glScissor(x0, H - y1, x1 - x0, y1 - y0);
#endif
    }
    else
    {
        glViewport(0, 0, W, H);
        glScissor(0, 0, W, H);
    }
}

/**
 * @brief   Set viewport for rendering 
 *
 * @param   ctx[in]     Rendering context
 * @param   dst[in]     Destination tile in logical coordinates
 */
static inline void render_context_set_crop(render_context_t *ctx, int32_t *dst)
{
    float32_t   scale = ctx->scale;
    int32_t     W = ctx->width * scale;
    int32_t     H = ctx->height * scale;
    
    if (dst != NULL)
    {
        int32_t     x0 = dst[0] * scale, y0 = dst[1] * scale;
        int32_t     x1 = dst[2] * scale, y1 = dst[3] * scale;

#if USE_EXTERNAL_FBO
        glScissor(x0, y0, x1 - x0, y1 - y0);
#else
        glScissor(x0, H - y1, x1 - x0, y1 - y0);
#endif
    }
    else
    {
        glScissor(0, 0, W, H);
    }
}

#endif  /* __LIBSV_RENDER_CONTEXT_H */
