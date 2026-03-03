/*******************************************************************************
 * display.h
 *
 * Display support
 *
 * Copyright (c) 2015-2020 Cogent Embedded Inc. ALL RIGHTS RESERVED.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *******************************************************************************/

#ifndef __SVS_DISPLAY_H
#define __SVS_DISPLAY_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "event.h"
#include "texture.h"
#if 1
#include <GLES3/gl3.h>
#include <GLES2/gl2ext.h>
#include <GLES3/gl3ext.h>
#else
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>
#endif

#include <EGL/egl.h>
#include <EGL/eglext.h>

#include <screen/screen.h>

/*******************************************************************************
 * Forward declarations
 ******************************************************************************/

typedef struct display_data     display_data_t;
typedef struct window_info      window_info_t;
typedef struct window_data      window_data_t;
typedef struct widget_info      widget_info_t;
typedef struct widget_data      widget_data_t;
typedef struct shader_data      shader_data_t;
typedef struct texture_data     texture_data_t;
typedef struct vbo_data         vbo_data_t;
typedef struct pbo_data         pbo_data_t;
typedef struct sync_data        sync_data_t;

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**
 * @brief EGL configuration data
 */
typedef struct egl_data
{
    /**> EGL display handle associated with current display */
    EGLDisplay              dpy;

    /**> Shared EGL context */
    EGLContext              ctx;

    /**> Current EGL configuration */
    EGLConfig               conf;

}   egl_data_t;

/*******************************************************************************
 * Window support
 ******************************************************************************/

#if 0
/**
 * @brief   Window configuration data
 */
struct window_info
{
    /**> Window title */
    const char         *title;

    /**> Recording file */
    const char         *video;

    /**> Fullscreen mode */
    int                 fullscreen;

    /**> Dimensions */
    uint32_t            width, height;

    /**> Output device id */
    uint32_t            output;

    /**> Icon pixmap buffer (RGBA) */
    void               *icon;

    /**> Icon pixmap buffer length, bytes */
    uint32_t            icon_length;

    /**> Context initialization function */
    int               (*init)(display_data_t *, window_data_t *, void *);

    /**> Resize hook */
    void              (*resize)(display_data_t *, void *);

    /**> Drawing function */
    void              (*redraw)(display_data_t *, void *);

    /**> Input event hook */
    void              (*event)(display_data_t *, void *, widget_event_t *);

    /**> Custom context destructor */
    void              (*destroy)(window_data_t *, void *);
};
#endif

/* ...window creation/destruction */
extern window_data_t * window_create(display_data_t *display, window_info_t *info, void *data);
extern void window_destroy(window_data_t *window);
extern void window_close(window_data_t *window);

/* ...return EGL surface associated with window */
extern EGLSurface window_egl_surface(window_data_t *window);
extern EGLContext window_egl_context(window_data_t *window);

/* ...window size query */
extern int window_get_width(window_data_t *window);
extern int window_get_height(window_data_t *window);

/* ...schedule window redrawal */
extern void window_schedule_redraw(window_data_t *window);
extern int window_draw(window_data_t *window);
extern void window_draw_native(window_data_t *window);

/* ...auxiliary helpers */
extern void window_frame_rate_reset(window_data_t *window);
extern float window_frame_rate_update(window_data_t *window);

/**
 * @brief   Make a snapshot of current window (following a page-swap)
 *
 * @param   window[in]          Window handle
 * @param   texture[in]         Texture to store the buffer in
 * @param   name[in]            Filename template "name-%d"
 * @param   k[in]               Filename template argument
 *
 * @return                      Negative on failure
 */
extern int window_screenshot(window_data_t *window, texture_data_t *texture, const char *name, int k);

/*******************************************************************************
 * GL shaders support
 ******************************************************************************/

/* ...opaque type declaration */
typedef struct shader_data  shader_data_t;

/* ...shader descriptor */
typedef struct shader_desc
{
    /* ...vertex/fragment shader source code */
    const char * const *v_src;
    int                 v_src_num;
    const char * const *f_src;
    int                 f_src_num;

    /* ...vertex/fragment shader binary blobs */
    const void         *v_bin;
    const void         *f_bin;

    /* ...attributes names array */
    const char * const *attr;

    /* ...number of attributes */
    int                 attr_num;

    /* ...uniforms names array */
    const char * const *uni;

    /* ...number of uniforms */
    int                 uni_num;

    /* ...binary shader name */
    const char *        name;

}   shader_desc_t;

/* ...create shader object */
extern shader_data_t * shader_create(const shader_desc_t *desc);

/* ...shader destruction */
extern void shader_destroy(shader_data_t *shader);

/* ...get shader program */
extern GLuint shader_program(shader_data_t *shader);

/* ...get shader uniforms locations array */
extern const GLint * shader_uniforms(shader_data_t *shader);

/*******************************************************************************
 * External textures support
 ******************************************************************************/

/**> Maximal planes number */
#define IMAGE_MAX_PLANES_NUMBER         3

/**
 * @brief   Mapped image buffer
 */
typedef struct image_data
{
    /**> Pixel format (fourcc) */
    uint32_t                fourcc;

    /**> Image width */
    uint32_t                width;

    /**> Image height */
    uint32_t                height;

    /**> Overall image buffer data size */
    uint32_t                size;

    /**> Number of planes */
    uint32_t                planes;

    /**> Strides (in bytes) */
    uint32_t                stride[IMAGE_MAX_PLANES_NUMBER];

    /**> Mapped planes buffers */
    void                   *data[IMAGE_MAX_PLANES_NUMBER];

}   image_data_t;

/* ...external texture data */
struct texture_data
{
    /* ...GL texture indices (per-plane; in shared display EGL context) */
    GLuint              tex[4];

    /* ...texture dimensions */
    int                 w, h;

    /* ...texture format */
    int                 format;

    /**> EGL image for external texture mapping */
    EGLImageKHR         image;

    /**> PBO object for pixbuf textures handling */
    pbo_data_t         *pbo;
};

/* ...internal structure definition */
struct pbo_data
{
    /**> PBO GL object */
    GLuint          pbo;

    /**> Number of planes */
    int             n;

    /**> Textures GL objects; per-plane */
    GLuint          tex[4];

    /**> Pixel-buffer dimensions; per-plane */
    int             w[4], h[4];

    /**> Planes strides in bytes; per-plane */
    int             s[4];

    /**> Planes offsets in pixel-buffer */
    int             o[4];

    /**> Pixel-buffer internal formats; per-plane */
    GLenum          fmt[4];

    /**> Pixel-buffer size */
    int             size;

    /**> Video format */
    int             format;

    /**> Image dimensions */
    int             width, height;

    /**> Current EGL context (scratch data) */
    EGLContext      ctx;

    /**> Thread that caused mapping */
    pthread_t       mapped;
};

/* ...texture cropping data */
typedef GLfloat     texture_crop_t[6 * 2];

/* ...texture viewport data */
typedef GLfloat     texture_view_t[6 * 2];

/**
 * @brief   Create texture using DMA-buffers
 *
 * @param   w[in]           Image width
 * @param   h[in]           Image height
 * @param   format[in]      Image format
 * @param   dmafd[in]       DMA-file-decriptors of image planes
 * @param   offset[in]      Image planes offsets
 * @param   stride[in]      Image planes strides
 *
 * @return                  Texture handle
 */
extern texture_data_t * texture_create_dmabuf(int w, int h, int format, int *dmafd, u32 *offset, u32 *stride);
extern texture_data_t * texture_create_pixbuf(int w, int h, int format);

/**
 * @brief   Update texture using DMA-buffers
 * @param   format[in]      Image format
 * @param   dmafd[in]       DMA-file-decriptors of image planes
 * @param   offset[in]      Image planes offsets
 * @param   stride[in]      Image planes strides
 *
 * @return                  Negative on failre
 */
extern int texture_update_dmabuf(texture_data_t *texture, int format, int *dmafd, u32 *offset, u32 *stride);
extern int texture_update_pixbuf(texture_data_t *texture, int format, const void **data, u32 *offset, u32 *stride);

/**
 * @brief   Create texture from PBO
 *
 * @param   pbo[in]         PBO buffer backing the texture / surface
 *
 * @return                  Texture handle, or NULL on failure
 */
extern texture_data_t * texture_create_pbo(pbo_data_t *pbo);

/**
 * @brief   Create native (no backing store) texture
 *
 * @param   width[in]       Image width
 * @param   height[in]      Image height
 * @param   format[in]      Image format
 *
 * @return                  Texture handle, or NULL on failure
 */
extern texture_data_t * texture_create(int w, int h, int format);

/**
 * @brief   Update native (no backing store) texture
 *
 * @param   texture[in]     Texture handle
 * @param   data[in]        Pointer to a pixel-buffer
 *
 * @return                  Negative on failure
 */
extern int texture_update(texture_data_t *texture, void *data);

/**
 * @brief   Map texture pixel-data
 *
 * @param   texture[in]     Texture handle
 * @param   image[out]      Image descriptor
 *
 * @return                  Negative on failure
 */
extern int texture_map(texture_data_t *texture, image_data_t *image);

/**
 * @brief   Unmap texture pixel-data
 *
 * @param   texture[in]     Texture handle
 */
extern void texture_unmap(texture_data_t *texture);

/**
 * @brief   Destroy texture
 *
 * @param   texture[in]     Texture handle
 */
extern void texture_destroy(texture_data_t *texture);

extern void texture_draw(texture_data_t *texture, texture_crop_t *crop, texture_view_t *view, GLfloat alpha);

/* ...texture viewport/cropping setting */
extern void texture_set_view(texture_view_t *vcoord, int x0, int y0, int x1, int y1);
extern void texture_set_crop(texture_crop_t *tcoord, int x0, int y0, int x1, int y1);

/*******************************************************************************
 * Synchronization objects handling
 ******************************************************************************/

/**
 * @brief   Create synchronization object
 *
 * @return                  Synchronization object handle, or NULL
 */
extern sync_data_t * sync_create(void);

/**
 * @brief   Wait for a synchronization operation completion
 *
 * @param   sync[in]        Synchronization object handle
 * @param   timeout[in]     Timeout value, in nsec
 *
 * @return                  Positive if sync is complete, zero if timeout expires
 */
extern int sync_wait(sync_data_t *sync, uint64_t timeout);

/**
 * @breif   Destroy synchronization object
 *
 * @param   sync[in]        Synchronization object handle
 */
extern void sync_destroy(sync_data_t *sync);

/*******************************************************************************
 * External VBO support
 ******************************************************************************/

/**
 * @brief   Create VBO object in shared display
 *
 * @param   size[in]        VBO element size
 * @param   number[in]      Number of elements to store
 * @param   p[in]           Data to upload into created buffer, or NULL
 *
 * @return                  VBO buffer handle, or NULL
 */
extern vbo_data_t * vbo_create(u32 size, u32 number, void *p);

/**
 * @brief   Upload VBO buffer
 *
 * @param   vbo[in]         VBO handle
 * @param   p[in]           Buffer data
 * @param   n[in]           Number of entries contained in buffer
 *
 * @return                  Negative on failure
 */
extern int vbo_upload(vbo_data_t *vbo, void *p, u32 n);

/**
 * @brief   Get writable data pointer to the VBO
 *
 * @param   vbo[in]         VBO data handle
 *
 * @return                  User-accessible pointer
 */
extern void * vbo_map(vbo_data_t *vbo);

/**
 * @brief   Reallocate VBO buffer. Buffer must be currently mapped
 *
 * @param   vbo[in]         VBO data handle
 * @param   p[in]           Current buffer cursor
 * @param   number[in]      New number of elements
 *
 * @return                  Updated position of cursor following remapping, or NULL
 */
extern void * vbo_realloc(vbo_data_t *vbo, void *p, u32 number);

/**
 * @brief   Unmap buffer data
 *
 * @param   vbo[in]         VBO handle
 */
extern void vbo_unmap(vbo_data_t *vbo);

/**
 * @brief   Return GL VBO buffer object
 *
 * @param   vbo[in]         VBO handle
 *
 * @return                  GL identifier of VBO
 */
extern GLuint vbo_get_id(vbo_data_t *vbo);

/**
 * @brief   Return number of filled items in VBO buffer object
 *
 * @param   vbo[in]         VBO handle
 *
 * @return                  Number of uploaded items
 */
extern uint32_t vbo_get_num(vbo_data_t *vbo);

/**
 * @brief   Return size of individual item in VBO buffer object
 *
 * @param   vbo[in]         VBO handle
 *
 * @return                  Size of VBO item
 */
extern uint32_t vbo_get_size(vbo_data_t *vbo);


/**
 * @brief   Destroy GL VBO buffer-object
 *
 * @param   vbo[in]         VBO handle
 */
extern void vbo_destroy(vbo_data_t *vbo);

/*******************************************************************************
 * Framebuffer support (rendering to texture)
 ******************************************************************************/

/* ...opaque definition */
typedef struct fbo_data fbo_data_t;

/* ...public API */
extern fbo_data_t * fbo_create(int w, int h);
extern fbo_data_t * fbo_create_ext(int w, int h, int depth, int msaa);
extern void fbo_destroy(fbo_data_t *fbo);

/* ...acquire/release framebuffer rendering context */
extern int fbo_get(fbo_data_t *fbo);
extern void fbo_put(fbo_data_t *fbo);

/* ...attach texture as color-attachment #n */
extern int fbo_attach_texture(fbo_data_t *fbo, texture_data_t *texture, int msaa, int n);

/*******************************************************************************
 * Pixel-buffer support (texture backup buffer)
 ******************************************************************************/

/**
 * @brief   Create pixel-buffer object for a video frame
 *
 * @param   width[in]       Image width
 * @param   height[in]      Image height
 * @param   format[in]      Image format
 *
 * @return                  PBO handle, or NULL on failure
 */
extern pbo_data_t * pbo_create(int w, int h, int format);

/**
 * @brief   Destroy PBO object
 *
 * @param   pbo[in]         PBO handle
 */
extern void pbo_destroy(pbo_data_t *pbo);

/**
 * @brief   Acquire pixel-buffer object mapping
 *
 * @param   pbo[in]         PBO handle
 *
 * @return                  PBO data buffer pointer, or NULL
 */
extern void * pbo_map(pbo_data_t *pbo);

/**
 * @brief   Synchronize PBO and associated texture
 *
 * @param   pbo[in]         PBO handle
 */
extern void pbo_sync(pbo_data_t *pbo);

/**
 * @brief   Release PBO mapping
 *
 * @param   pbo[in]         PBO handle
 * @param   sync[in]        Associated texture synchronization flag
 */
extern void pbo_unmap(pbo_data_t *pbo, int sync);

/*******************************************************************************
 * Public API
 ******************************************************************************/

/* ...texture creation (in shared display context) */
extern texture_data_t * texture_create_native(EGLClientBuffer pixmap, int ext);
extern void texture_destroy_native(texture_data_t *texture);

/* ...connect to a display */
extern display_data_t * display_create(screen_context_t screen_ctx, int width, int height);

/* ...get current EGL configuration data */
extern egl_data_t  * display_egl_data(display_data_t *display);

/* ...return current screen context */
extern screen_context_t display_screen_context(display_data_t *display);

/*******************************************************************************
 * Helpers
 ******************************************************************************/

#define GLCHECK()                                   \
({                                                  \
    GLint   __err = glGetError();                   \
                                                    \
    if (__err != 0)                                 \
        TRACE(ERROR, _x("gl-error: %X"), __err);    \
    __err;                                          \
})

#endif  /* __SVS_DISPLAY_H */
