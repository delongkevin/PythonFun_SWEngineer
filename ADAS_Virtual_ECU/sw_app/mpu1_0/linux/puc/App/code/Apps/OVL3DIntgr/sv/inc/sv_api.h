#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <EGL/egl.h>
#define EGL_EGLEXT_PROTOTYPES
#include <EGL/eglext.h>
#include <GLES2/gl2.h>

#include "event.h"
#include "view-manager.h"
#include "render-context.h"
#include "png-load.h"
#include <screen/screen.h>

extern int LOG_LEVEL;

typedef enum {
  GST_VIDEO_FORMAT_UNKNOWN,
  GST_VIDEO_FORMAT_ENCODED,
  GST_VIDEO_FORMAT_I420,
  GST_VIDEO_FORMAT_YV12,
  GST_VIDEO_FORMAT_YUY2,
  GST_VIDEO_FORMAT_UYVY,
  GST_VIDEO_FORMAT_AYUV,
  GST_VIDEO_FORMAT_RGBx,
  GST_VIDEO_FORMAT_BGRx,
  GST_VIDEO_FORMAT_xRGB,
  GST_VIDEO_FORMAT_xBGR,
  GST_VIDEO_FORMAT_RGBA,
  GST_VIDEO_FORMAT_BGRA,
  GST_VIDEO_FORMAT_ARGB,
  GST_VIDEO_FORMAT_ABGR,
  GST_VIDEO_FORMAT_RGB,
  GST_VIDEO_FORMAT_BGR,
  GST_VIDEO_FORMAT_Y41B,
  GST_VIDEO_FORMAT_Y42B,
  GST_VIDEO_FORMAT_YVYU,
  GST_VIDEO_FORMAT_Y444,
  GST_VIDEO_FORMAT_v210,
  GST_VIDEO_FORMAT_v216,
  GST_VIDEO_FORMAT_NV12,
  GST_VIDEO_FORMAT_NV21,
  GST_VIDEO_FORMAT_GRAY8,
  GST_VIDEO_FORMAT_GRAY16_BE,
  GST_VIDEO_FORMAT_GRAY16_LE,
  GST_VIDEO_FORMAT_v308,
  GST_VIDEO_FORMAT_RGB16,
  GST_VIDEO_FORMAT_BGR16,
  GST_VIDEO_FORMAT_RGB15,
  GST_VIDEO_FORMAT_BGR15,
  GST_VIDEO_FORMAT_UYVP,
  GST_VIDEO_FORMAT_A420,
  GST_VIDEO_FORMAT_RGB8P,
  GST_VIDEO_FORMAT_YUV9,
  GST_VIDEO_FORMAT_YVU9,
  GST_VIDEO_FORMAT_IYU1,
  GST_VIDEO_FORMAT_ARGB64,
  GST_VIDEO_FORMAT_AYUV64,
  GST_VIDEO_FORMAT_r210,
  GST_VIDEO_FORMAT_I420_10BE,
  GST_VIDEO_FORMAT_I420_10LE,
  GST_VIDEO_FORMAT_I422_10BE,
  GST_VIDEO_FORMAT_I422_10LE,
  GST_VIDEO_FORMAT_Y444_10BE,
  GST_VIDEO_FORMAT_Y444_10LE,
  GST_VIDEO_FORMAT_GBR,
  GST_VIDEO_FORMAT_GBR_10BE,
  GST_VIDEO_FORMAT_GBR_10LE,
  GST_VIDEO_FORMAT_NV16,
  GST_VIDEO_FORMAT_NV24,
  GST_VIDEO_FORMAT_NV12_64Z32,
  GST_VIDEO_FORMAT_A420_10BE,
  GST_VIDEO_FORMAT_A420_10LE,
  GST_VIDEO_FORMAT_A422_10BE,
  GST_VIDEO_FORMAT_A422_10LE,
  GST_VIDEO_FORMAT_A444_10BE,
  GST_VIDEO_FORMAT_A444_10LE,
  GST_VIDEO_FORMAT_NV61,
} GstVideoFormat;

typedef struct display_data     display_data_t;
typedef struct window_info      window_info_t;
typedef struct window_data      window_data_t;
typedef struct sync_data        sync_data_t;


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

    EGLNativeWindowType         native;
};


extern display_data_t * display_create(screen_context_t screen_ctx, int width, int height);
extern screen_context_t display_screen_context(display_data_t *display);

extern window_data_t * window_create(display_data_t *display, window_info_t *info, void *data);
extern void window_destroy(window_data_t *window);
extern void window_close(window_data_t *window);
extern int window_draw(window_data_t *window);
extern void window_schedule_redraw(window_data_t *window);

extern texture_data_t * texture_create(int w, int h, int format);
extern int texture_update(texture_data_t *texture, void *data);

/* qnx pixmap */
extern texture_data_t * texture_create_native(EGLClientBuffer pixmap, int ext);
extern void texture_destroy_native(texture_data_t *texture);

/* ...texture cropping data */
typedef GLfloat     texture_crop_t[6 * 2];

/* ...texture viewport data */
typedef GLfloat     texture_view_t[6 * 2];

/* ...draw external texture in given view-port */
extern void texture_draw(texture_data_t *texture, texture_view_t *view, texture_crop_t *crop, GLfloat alpha);


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

extern void window_frame_rate_reset(window_data_t *window);
extern float window_frame_rate_update(window_data_t *window);

// --reorder that later - tbd
#include "../libsv/algo.h"

#ifdef __cplusplus
}
#endif
