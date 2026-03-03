/*******************************************************************************
 * display.c
 *
 * Display support
 *
 * Copyright (c) 2014-2020 Cogent Embedded Inc. ALL RIGHTS RESERVED.
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

#define MODULE_TAG                      DISPLAY

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stddef.h>
#include <screen/screen.h>
#include <input/screen_helpers.h>
#include "common.h"
#include "display.h"
#include "list.h"
#include "sv_api.h"
#include <gestures/double_tap.h>
#include <gestures/pinch.h>
#include <gestures/tap.h>
#include <gestures/swipe.h>
#include <gestures/press_and_tap.h>
#include <gestures/set.h>

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(EVENT, 5);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Local typedefs
 ******************************************************************************/

/* ...texture shader data */
typedef struct shader_data
{
    /* ...shader program */
    GLuint          program;

    /* ...vertex/fragment shaders */
    GLuint          v_shader, f_shader;

    /* ...array of uniforms */
    GLint           uniform[];

}   shader_data_t;

/**
 * @brief   Display data
 */
struct display_data
{
    /**> Native display handle */
    EGLNativeDisplayType        display;

    /**> EGL configuration data */
    egl_data_t                  egl;

    /**> List of attached windows */
    __list_t                    windows;

    /**> Dispatch thread handle */
    pthread_t                   thread;

    /**> Screen context */
    screen_context_t            screen_ctx;

    /**> Gestures set */
    struct gestures_set        *set;

    /**> Display lock (need that really? - tbd) */
    pthread_mutex_t             lock;
};

/**
 * @brief   Output window data
 */
struct window_data
{
    /**> Reference to a display data */
    display_data_t             *display;

    /**> Link item in the windows display list */
    __list_t                    link;

    /**> Native EGL window */
    EGLNativeWindowType         native;

    /**> Window EGL context */
    EGLContext                  user_egl_ctx;

    /**> EGL surface */
    EGLSurface                  egl;

    /**> Window information */
    const window_info_t        *info;

    /**> Client data for a callback */
    void                       *cdata;

    /**> Current window dimensions */
    int                         width, height;

    /**> Window buffers */
    screen_buffer_t            *buffers;

    /**> External framebuffers */
    fbo_data_t                **fbo;

    /**> Number of external framebuffers */
    int                         fbo_num;

    /**> Index of current FBO */
    int                         fbo_idx;

    /**> Internal data access lock */
    pthread_mutex_t             lock;

    /**> Frame-rate calculation */
    u32                         fps_ts, fps_acc;
};

/* ...set external FBO (no default FB) */
#define USE_EXTERNAL_FBO    0

/*******************************************************************************
 * EGL functions binding
 ******************************************************************************/

/* ...EGL/GLES functions */
PFNEGLCREATEIMAGEKHRPROC eglCreateImageKHR;
PFNEGLDESTROYIMAGEKHRPROC eglDestroyImageKHR;
PFNEGLCREATESYNCKHRPROC eglCreateSyncKHR;
PFNEGLDESTROYSYNCKHRPROC eglDestroySyncKHR;
PFNEGLCLIENTWAITSYNCKHRPROC eglClientWaitSyncKHR;
PFNEGLSWAPBUFFERSWITHDAMAGEEXTPROC eglSwapBuffersWithDamageEXT;
PFNGLEGLIMAGETARGETTEXTURE2DOESPROC glEGLImageTargetTexture2DOES;
PFNGLMAPBUFFEROESPROC glMapBufferOES;
PFNGLUNMAPBUFFEROESPROC glUnmapBufferOES;
PFNGLBINDVERTEXARRAYOESPROC glBindVertexArrayOES;
PFNGLDELETEVERTEXARRAYSOESPROC glDeleteVertexArraysOES;
PFNGLGENVERTEXARRAYSOESPROC glGenVertexArraysOES;
PFNGLISVERTEXARRAYOESPROC glIsVertexArrayOES;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC glRenderbufferStorageMultisampleEXT;
PFNGLFRAMEBUFFERTEXTURE2DMULTISAMPLEEXTPROC glFramebufferTexture2DMultisampleEXT;
PFNGLDISCARDFRAMEBUFFEREXTPROC glDiscardFramebufferEXT;
PFNGLCLIPCONTROLEXTPROC glClipControlEXT;

/*******************************************************************************
 * Local variables
 ******************************************************************************/

/**> This should be a singleton for now - tbd */
static display_data_t   __display;

/*******************************************************************************
 * Internal helpers
 ******************************************************************************/

/* ...get exclusive access to shared EGL context */
static inline void display_egl_ctx_get(display_data_t *display)
{
    /* ...we should not call that function in user-window context */
    BUG(eglGetCurrentContext() != EGL_NO_CONTEXT, _x("invalid egl context"));

    /* ...get shared context lock */
    pthread_mutex_lock(&display->lock);

    /* ...display context is shared with all windows; context is surfaceless */
    eglMakeCurrent(display->egl.dpy, EGL_NO_SURFACE, EGL_NO_SURFACE, display->egl.ctx);
}

/* ...release shared EGL context */
static inline void display_egl_ctx_put(display_data_t *display)
{
    /* ...display context is shared with all windows; context is surfaceless */
    eglMakeCurrent(display->egl.dpy, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);

    /* ...release shared context lock */
    pthread_mutex_unlock(&display->lock);
}

/* ...get exclusive access to shared EGL context */
static inline void display_egl_ctx_force(display_data_t *display, EGLContext *ctx, EGLSurface *read, EGLSurface *draw)
{
    /* ...save current EGL context */
    *ctx = eglGetCurrentContext(), *read = eglGetCurrentSurface(EGL_READ), *draw = eglGetCurrentSurface(EGL_DRAW);

    /* ...get shared context lock */
    pthread_mutex_lock(&display->lock);

    /* ...display context is shared with all windows; context is surfaceless */
    eglMakeCurrent(display->egl.dpy, EGL_NO_SURFACE, EGL_NO_SURFACE, display->egl.ctx);
}

/* ...release shared EGL context */
static inline void display_egl_ctx_restore(display_data_t *display, EGLContext ctx, EGLSurface read, EGLSurface draw)
{
    /* ...restore original context (probably NULL) */
    eglMakeCurrent(display->egl.dpy, draw, read, ctx);

    /* ...release shared context lock */
    pthread_mutex_unlock(&display->lock);
}

/*******************************************************************************
 * Touchscreen support
 ******************************************************************************/

static void display_gesture_event(display_data_t *display, struct gesture_base *gesture, int async)
{
    __list_t   *list = &display->windows, *item;

    for (item = list_first(list); item != list_null(list); item = list_next(list, item))
    {
        window_data_t  *window = container_of(item, window_data_t, link);

        /* ...check if destination window is found - tbd */
        if (1 /*window->native == win*/)
        {
            widget_event_t  e;

            /* ...pass event  to window input hook */
            e.type = WIDGET_EVENT_GESTURE;
            e.gesture.gesture = gesture;
            e.gesture.async = async;

            /* ...pass event to the window input handler */
            (window->info->event ? window->info->event(display, window->cdata, &e) : 0);
        }
    }
}

/**
 * @brief   Gestures processing callback
 */
static void display_gesture_cb(struct gesture_base* gesture, mtouch_event_t* event, void* param, int async)
{
    display_data_t  *display = param;
    __list_t        *list = &display->windows, *item;

    for (item = list_first(list); item != list_null(list); item = list_next(list, item))
    {
        window_data_t  *window = container_of(item, window_data_t, link);

        /* ...check if destination window is found */
        if (1 /*window->native == win*/)
        {
            widget_event_t  e;

            /* ...pass event  to window input hook */
            e.type = WIDGET_EVENT_GESTURE;
            e.gesture.gesture = gesture;
            e.gesture.async = async;

            /* ...pass event to the window input handler */
            (window->info->event ? window->info->event(display, window->cdata, &e) : 0);
        }
    }

#if 0
    switch (gesture->type)
    {
#if 0
    case GESTURE_TWO_FINGER_PAN: {
        gesture_tfpan_t* tfpan = (gesture_tfpan_t*)gesture;
        if (tfpan->base.state == GESTURE_STATE_COMPLETE)
        {
           printf("Two-finger pan gesture detected: %d, %d",
                                                   tfpan->centroid.x, tfpan->centroid.y);
        }
        break;
    }
    case GESTURE_ROTATE: {
        gesture_rotate_t* rotate = (gesture_rotate_t*)gesture;
        if (rotate->base.state == GESTURE_STATE_COMPLETE)  {
           if (rotate->angle != rotate->last_angle) {
               printf("Rotate: %d degs", rotate->angle - rotate->last_angle);
           }
        }
        break;
    }
#endif
    case GESTURE_SWIPE:
    {
        gesture_swipe_t* swipe = (gesture_swipe_t*)gesture;
        if (swipe->base.state == GESTURE_STATE_COMPLETE)  {
           if (swipe->direction & GESTURE_DIRECTION_UP) {
               TRACE(1, _b("up %d"), swipe->last_coords.y - swipe->coords.y);
           } else if (swipe->direction & GESTURE_DIRECTION_DOWN) {
               TRACE(1, _b("down %d"), swipe->coords.y - swipe->last_coords.y);
           } else if (swipe->direction & GESTURE_DIRECTION_LEFT) {
               TRACE(1, _b("left %d"), swipe->last_coords.x - swipe->coords.x);
           } else if (swipe->direction & GESTURE_DIRECTION_RIGHT) {
               TRACE(1, _b("right %d"), swipe->coords.x - swipe->last_coords.x);
           }
        }
        TRACE(1, _b("swipe-state-%d: dir=%x, dx=%d, dy=%d"), swipe->base.state,
              swipe->direction,
              swipe->last_coords.x - swipe->coords.x, wipe->last_coords.y - swipe->coords.y);

        break;
    }
    case GESTURE_PINCH: {
        gesture_pinch_t* pinch = (gesture_pinch_t*)gesture;
        if (pinch->base.state == GESTURE_STATE_COMPLETE)  {
            TRACE(1, _b("Pinch %d, %d"), (pinch->last_distance.x - pinch->distance.x),
                                  (pinch->last_distance.y - pinch->distance.y));
        }

        TRACE(1, _b("pinch-state-%d: dx=%d, dy=%d, c=%d,%d"), pinch->base.state,
              pinch->last_distance.x - pinch->distance.x,
              pinch->last_distance.x - pinch->distance.x,
              pinch->centroid.x, pinch->centroid.y);

        break;
    }
    case GESTURE_TAP: {
        gesture_tap_t* tap = (gesture_tap_t*)gesture;
        if (tap->base.state == GESTURE_STATE_COMPLETE)  {
           printf("Tap x:%d y:%d",tap->touch_coords.x, tap->touch_coords.y);
        }
        TRACE(1, _b("tap-state-%d: x=%d, y=%d"), tap->base.state,
              tap->touch_coords.x, tap->touch_coords.y);

        break;
    }
#if 0
    case GESTURE_DOUBLE_TAP: {
        gesture_double_tap_t* d_tap = (gesture_double_tap_t*)gesture;
        if (d_tap->base.state == GESTURE_STATE_COMPLETE)  {
           printf("Double tap first_touch x:%d y:%d", d_tap->first_touch.x,
                                                      d_tap->first_touch.y);
           printf("Double tap first_release x:%d y:%d", d_tap->first_release.x,
                                                        d_tap->first_release.y);
           printf("Double tap second_touch x:%d y:%d", d_tap->second_touch.x,
                                                       d_tap->second_touch.y);
           printf("Double tap second_release x:%d y:%d", d_tap->second_touch.x,
                                                         d_tap->second_release.y);
        }
        break;
    }

    case GESTURE_TRIPLE_TAP: {
        gesture_triple_tap_t* t_tap = (gesture_triple_tap_t*)gesture;
        if (t_tap->base.state == GESTURE_STATE_COMPLETE)  {
           printf("Triple tap first_touch x:%d y:%d", t_tap->first_touch.x,
                                                      t_tap->first_touch.y);
           printf("Triple tap first_release x:%d y:%d", t_tap->first_release.x,
                                                        t_tap->first_release.y);
           printf("Triple tap second_touch x:%d y:%d", t_tap->second_touch.x,
                                                       t_tap->second_touch.y);
           printf("Triple tap second_release x:%d y:%d", t_tap->second_touch.x,
                                                         t_tap->second_release.y);
           printf("Triple tap third_touch x:%d y:%d", t_tap->third_touch.x,
                                                      t_tap->second_touch.y);
           printf("Triple tap third_release x:%d y:%d", t_tap->third_touch.x,
                                                        t_tap->second_release.y);
        }
        break;
    }
#endif
    case GESTURE_PRESS_AND_TAP: {
        gesture_pt_t* pt_t = (gesture_pt_t*)gesture;
        if (pt_t->base.state == GESTURE_STATE_COMPLETE)  {
           printf("Initial press x:%d y:%d", pt_t->initial_coords[0].x,
                                             pt_t->initial_coords[0].y);
           printf("Initial tap x:%d y:%d", pt_t->initial_coords[1].x,
                                           pt_t->initial_coords[1].y);
           printf("Press x:%d y:%d", pt_t->coords[0].x, pt_t->coords[0].y);
           printf("Tap x:%d y:%d", pt_t->coords[1].x, pt_t->coords[1].y);
        }
        break;
    }
#if 0
    case GESTURE_TWO_FINGER_TAP: {
        gesture_tft_t* tft_t = (gesture_tft_t*)gesture;
        if (tft_t->base.state == GESTURE_STATE_COMPLETE)  {
           printf("Coordinates of touch event (finger 1) x:%d y:%d",
                                                         tft_t->touch_coords[0].x,
                                                         tft_t->touch_coords[0].y);
           printf("Coordinates of touch event (finger 2) x:%d y:%d",
                                                         tft_t->touch_coords[1].x,
                                                         tft_t->touch_coords[1].y);
           printf("Coordinates of release event (finger 1) x:%d y:%d",
                                                         tft_t->release_coords[0].x,
                                                         tft_t->release_coords[0].y);
           printf("Coordinates of release event (finger 2) x:%d y:%d",
                                                         tft_t->release_coords[1].x,
                                                         tft_t->release_coords[1].y);
           printf("Midpoint between two touches x:%d y:%d", tft_t->centroid.x,
                                                            tft_t->centroid.y);
        }
        break;
    }
    case GESTURE_LONG_PRESS: {
        gesture_long_press_t* lp_t = (gesture_long_press_t*)gesture;
        if (lp_t->base.state == GESTURE_STATE_COMPLETE)  {
           printf("Long press x:%d y:%d",lp_t->coords.x, lp_t->coords.y);
           printf("Timer ID:%d",lp_t->success_timer);
        }
        break;
    }
#endif

    case GESTURE_USER: {
        TRACE(1, _b("User-defined gesture detected."));
        break;
    }
    default:
        TRACE(1, _b("Unknown: %d"), gesture->type);
        break;
    }
#endif
}

/**
 * @brief   Touch event processing hook
 *
 * @param   display[in]     Display handle
 * @param   event[in]       Event data
 *
 * @return                  Negative on failure
 */
static inline int __display_mtouch_event(display_data_t *display, screen_event_t event, int32_t type, screen_window_t win)
{
    __list_t   *list = &display->windows, *item;

    TRACE(1, _b("window %p, touch-event: %d"), win, type);

    for (item = list_first(list); item != list_null(list); item = list_next(list, item))
    {
        window_data_t  *window = container_of(item, window_data_t, link);

        TRACE(1, _b("window: %p, win: %p"), window->native, win);

        /* ...check if destination window is found */
        if (window->native == win)
        {
            if (1 || window->info->event)
            {
                widget_event_t  e;

                int32_t     buttons;
                int32_t     pos[2], pos2[2];
                int32_t     size[2];
                int32_t     seq;
                int32_t     id;
                int32_t     orient;
                int32_t     pressure;
                int32_t     touch;

                screen_get_event_property_iv(event, SCREEN_PROPERTY_BUTTONS, &buttons);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_POSITION, pos);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_SOURCE_POSITION, pos2);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_SEQUENCE_ID, &seq);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_SIZE, size);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_TOUCH_ID, &id);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_TOUCH_ORIENTATION, &orient);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_TOUCH_PRESSURE, &pressure);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_TOUCH_TYPE, &touch);
                TRACE(0, _b("touch event: buttons=%x, pos=%d,%d, pos2=%d,%d, size=%d,%d, seq=%d, id=%d, orient=%d, pressure=%d, touch=%d"),
                      buttons, pos[0], pos[1], pos2[0], pos2[1], size[0], size[1], seq, id, orient, pressure, touch);
#if 0
                e.type = WIDGET_EVENT_MOUSE_MOVE;
                e.mouse.x = pos[0];
                e.mouse.y = pos[1];
                e.mouse.state = 0;  // tbd - need to understand how to map that
                e.mouse.button = button;
#endif
                /* ...pass event to the window input handler */
                (window->info->event ? window->info->event(display, window->cdata, &e) : 0);
            }

            return 0;
        }
    }

    /* ...no destination window found */
    return 0;
}

static void init_gestures(display_data_t *display)
{
    gesture_tap_t* tap;
    gesture_double_tap_t* double_tap;
    struct gestures_set * set;

    set = gestures_set_alloc();

    tap = tap_gesture_alloc(NULL, display_gesture_cb, set);
    double_tap = double_tap_gesture_alloc(NULL, display_gesture_cb, set);
    pinch_gesture_alloc(NULL, display_gesture_cb, set);

    swipe_params_t  sp = {
        .directions = ~0U,
        .off_axis_tolerance = ~0,
        .min_distance = 1,
        .min_velocity = 0,
    };

    swipe_gesture_alloc(&sp, display_gesture_cb, set);

    display->set = set;

    TRACE(1, _b("gestures inited"));
}

/*******************************************************************************
 * Display dispatch thread
 ******************************************************************************/

/**
 * @brief   Mouse event processing hook
 *
 * @param   display[in]     Display handle
 * @param   event[in]       Event data
 *
 * @return                  Negative on failure
 */
static inline int __display_mouse_event(display_data_t *display, screen_event_t event, screen_window_t win)
{
    __list_t   *list = &display->windows, *item;

    for (item = list_first(list); item != list_null(list); item = list_next(list, item))
    {
        window_data_t  *window = container_of(item, window_data_t, link);

        /* ...check if destination window is found - tbd */
        if (window->native == win)
        {
            TRACE(DEBUG, _b("window %p[%s] [%p] mouse-event"), window, (window->info->title ? : "untitled"), window->native);

            if (window->info->event)
            {
                widget_event_t  e;

                int32_t     button;
                int32_t     pos[2], pos2[2];
                int32_t     wheel;

                screen_get_event_property_iv(event, SCREEN_PROPERTY_BUTTONS, &button);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_POSITION, pos);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_SOURCE_POSITION, pos2);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_MOUSE_WHEEL, &wheel);
                TRACE(1, _b("mouse event: buttons=%x, pos=%d,%d, pos2=%d,%d, wheel=%d"),
                      button, pos[0], pos[1], pos2[0], pos2[1], wheel);

                e.type = WIDGET_EVENT_MOUSE_MOVE;
                e.mouse.x = pos[0];
                e.mouse.y = pos[1];
                e.mouse.state = 0;  // tbd - need to understand how to map that
                e.mouse.button = button;

                /* ...pass event to the window input handler */
                window->info->event(display, window->cdata, &e);
            }

            return 0;
        }
    }

    /* ...no destination window found */
    return 0;
}

/**
 * @brief   Touch event processing hook
 *
 * @param   display[in]     Display handle
 * @param   event[in]       Event data
 *
 * @return                  Negative on failure
 */
static inline int __display_mtouch_event_old(display_data_t *display, screen_event_t event, int32_t type, screen_window_t win)
{
    __list_t   *list = &display->windows, *item;

    TRACE(1, _b("window %p, touch-event: %d"), win, type);

    for (item = list_first(list); item != list_null(list); item = list_next(list, item))
    {
        window_data_t  *window = container_of(item, window_data_t, link);

        TRACE(1, _b("window: %p, win: %p"), window->native, win);

        /* ...check if destination window is found */
        if (window->native == win)
        {
            if (1 || window->info->event)
            {
                widget_event_t  e;

                int32_t     buttons;
                int32_t     pos[2], pos2[2];
                int32_t     size[2];
                int32_t     seq;
                int32_t     id;
                int32_t     orient;
                int32_t     pressure;
                int32_t     touch;

                screen_get_event_property_iv(event, SCREEN_PROPERTY_BUTTONS, &buttons);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_POSITION, pos);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_SOURCE_POSITION, pos2);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_SEQUENCE_ID, &seq);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_SIZE, size);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_TOUCH_ID, &id);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_TOUCH_ORIENTATION, &orient);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_TOUCH_PRESSURE, &pressure);
                screen_get_event_property_iv(event, SCREEN_PROPERTY_TOUCH_TYPE, &touch);
                TRACE(0, _b("touch event: buttons=%x, pos=%d,%d, pos2=%d,%d, size=%d,%d, seq=%d, id=%d, orient=%d, pressure=%d, touch=%d"),
                      buttons, pos[0], pos[1], pos2[0], pos2[1], size[0], size[1], seq, id, orient, pressure, touch);
#if 0
                e.type = WIDGET_EVENT_MOUSE_MOVE;
                e.mouse.x = pos[0];
                e.mouse.y = pos[1];
                e.mouse.state = 0;  // tbd - need to understand how to map that
                e.mouse.button = button;
#endif
                /* ...pass event to the window input handler */
                (window->info->event ? window->info->event(display, window->cdata, &e) : 0);
            }

            return 0;
        }
    }

    /* ...no destination window found */
    return 0;
}

/**
 * @brief   Display dispatch thread
 *
 * @param   arg[in]     Thread argument (display handle)
 */
static void * dispatch_thread(void *arg)
{
    display_data_t     *display = arg;
    screen_event_t      ev;
    screen_create_event(&ev);

	while (1)
    {
        int32_t     type;
        mtouch_event_t      mtouch_event;

		do
        {
            screen_window_t     window;

			/* ...wait for a next screen event (infinitely) */
			screen_get_event(display->screen_ctx, ev, -1);

			/* ...get the type of the event */
			screen_get_event_property_iv(ev, SCREEN_PROPERTY_TYPE, &type);

            /* ...get the destination window pointer */
            screen_get_event_property_pv(ev, SCREEN_PROPERTY_WINDOW, (void **)&window);

            TRACE(0, _b("event: type=%d, window=%p"), type, window);

            switch (type)
            {
            case SCREEN_EVENT_POST:
                /* ...handle SCREEN_EVENT_POST event accordingly */
                break;

            case SCREEN_EVENT_CLOSE:
                /* ...handle close event? - tbd */
                break;

            case SCREEN_EVENT_MTOUCH_TOUCH:
            case SCREEN_EVENT_MTOUCH_MOVE:
            case SCREEN_EVENT_MTOUCH_RELEASE:
                /* ...feed mtouch events to gestures library */
                if (screen_get_mtouch_event(ev, &mtouch_event, 1) == 0)
                {
                    gestures_set_process_event(display->set, &mtouch_event, display);
                }

                break;

            case SCREEN_EVENT_POINTER:
                /* ...mouse events processing */
                __display_mouse_event(display, ev, window);
                break;

            default:
                TRACE(1, _b("event type: %d"), type);
            }
		}
        while (type != SCREEN_EVENT_NONE);
	}

    TRACE(1, _b("dispatch thread terminated"));

    return NULL;
}

/*******************************************************************************
 * EGL helpers
 ******************************************************************************/

/**> EGL context attributes */
static const EGLint     __egl_context_attribs[] = {
    EGL_CONTEXT_CLIENT_VERSION, 3,
    EGL_NONE
};

/**
 * @brief   Finalize EGL context
 *
 * @param   display[in]         Display handle
 */
static void fini_egl(display_data_t *display)
{
    eglTerminate(display->egl.dpy);
    eglReleaseThread();
}

/**
 * @brief   Initialize EGL context
 *
 * @param   display[in]         Display handle
 *
 * @return                      Negative on failure
 */
static int init_egl(display_data_t *display)
{
    /* ...EGL configuration attributes */
    EGLint                  config_attribs[] = {
#if 1
        EGL_SURFACE_TYPE, EGL_PIXMAP_BIT,
#else
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
#endif
 		EGL_BUFFER_SIZE, 32,
 		EGL_DEPTH_SIZE, 24,
 		EGL_RED_SIZE, 8,
 		EGL_GREEN_SIZE, 8,
 		EGL_BLUE_SIZE, 8,
        EGL_SAMPLE_BUFFERS, 1,
        EGL_SAMPLES, 4,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
        EGL_NONE
    };

    EGLint          major, minor, n, count, i, size;
    EGLConfig      *configs;
    EGLDisplay      dpy;
    const char     *extensions;

    /* ...get EGL display */
    CHK_ERR(display->egl.dpy = dpy = eglGetDisplay(display->display), -ENOENT);

    /* ...initialize EGL module? */
    if (!eglInitialize(dpy, &major, &minor))
    {
        TRACE(ERROR, _x("failed to initialize EGL: %m (%X)"), eglGetError());
        goto error;
    }
    else if (!eglBindAPI(EGL_OPENGL_ES_API))
    {
        TRACE(ERROR, _x("failed to bind API: %m (%X)"), eglGetError());
        goto error;
    }
    else
    {
        TRACE(INIT, _b("EGL display opened: %p, major:minor=%u:%u"), dpy, major, minor);
    }

    /* ...get total number of configurations */
    if (!eglGetConfigs(dpy, NULL, 0, &count))
    {
        TRACE(ERROR, _x("failed to get EGL configs number"));
        goto error;
    }
    else if (count == 0)
    {
        TRACE(ERROR, _x("no configurations found"));
        goto error;
    }

    /* ...retrieve available configurations */
    if ((configs = calloc(count, sizeof(*configs))) == NULL)
    {
        TRACE(ERROR, _x("failed to allocate %zu bytes"), sizeof(*configs));
        goto error;
    }
    else if (!eglChooseConfig(dpy, config_attribs, configs, count, &n))
    {
        TRACE(ERROR, _x("failed to get matching configuration"));
        goto error_cfg;
    }
    else if (n == 0)
    {
        TRACE(ERROR, _x("no matching configurations"));
        goto error_cfg;
    }

    /* ...select configuration? */
    for (i = 0; i < n; i++)
    {
        EGLint      id = -1;

        eglGetConfigAttrib(dpy, configs[i], EGL_NATIVE_VISUAL_ID, &id);

        /* ...get buffer size of that configuration */
        eglGetConfigAttrib(dpy, configs[i], EGL_BUFFER_SIZE, &size);

        TRACE(INFO, _b("config[%u of %u]: id=%X, size=%X"), i, n, id, size);

        /* ...check if we have a 32-bit buffer size - tbd */
        if (size == 32)
        {
            display->egl.conf = configs[i];
            goto found;
        }
    }

    TRACE(ERROR, _x("did not find suitable configuration"));
    errno = -ENODEV;
    goto error_cfg;

found:
    /* ...bind extensions */
    eglCreateImageKHR = (void *)eglGetProcAddress("eglCreateImageKHR");
    eglDestroyImageKHR = (void *)eglGetProcAddress("eglDestroyImageKHR");
    eglSwapBuffersWithDamageEXT = (void *)eglGetProcAddress("eglSwapBuffersWithDamageEXT");
    eglCreateSyncKHR = (void *)eglGetProcAddress("eglCreateSyncKHR");
    eglDestroySyncKHR = (void *)eglGetProcAddress("eglDestroySyncKHR");
    eglClientWaitSyncKHR = (void *)eglGetProcAddress("eglClientWaitSyncKHR");


#ifndef GL_GLEXT_PROTOTYPES
    glEGLImageTargetTexture2DOES = (void *)eglGetProcAddress("glEGLImageTargetTexture2DOES");
    glMapBufferOES = (void *)eglGetProcAddress("glMapBufferOES");
    glUnmapBufferOES = (void *)eglGetProcAddress("glUnmapBufferOES");
    glBindVertexArrayOES = (void *)eglGetProcAddress("glBindVertexArrayOES");
    glDeleteVertexArraysOES = (void *)eglGetProcAddress("glDeleteVertexArraysOES");
    glGenVertexArraysOES = (void *)eglGetProcAddress("glGenVertexArraysOES");
    glIsVertexArrayOES = (void *)eglGetProcAddress("glIsVertexArrayOES");
    glRenderbufferStorageMultisampleEXT = (void *)eglGetProcAddress("glRenderbufferStorageMultisampleEXT");
    glFramebufferTexture2DMultisampleEXT = (void *)eglGetProcAddress("glFramebufferTexture2DMultisampleEXT");
    glDiscardFramebufferEXT = (void *)eglGetProcAddress("glDiscardFramebufferEXT");
    glClipControlEXT = (void *)eglGetProcAddress("glClipControlEXT");
#endif

    /* ...make sure we have eglImageKHR extension */
    BUG(!(eglCreateImageKHR && eglDestroyImageKHR), _x("breakpoint"));

    /* ...check for specific EGL extensions */
    if ((extensions = eglQueryString(display->egl.dpy, EGL_EXTENSIONS)) != NULL)
    {
        TRACE(INIT, _b("EGL extensions: %s"), extensions);
    }

    /* ...create display (shared?) EGL context */
    if ((display->egl.ctx = eglCreateContext(dpy, display->egl.conf, EGL_NO_CONTEXT, __egl_context_attribs)) == NULL)
    {
        TRACE(ERROR, _x("failed to create EGL context: 0x%X"), eglGetError());
        goto error_cfg;
    }

    /* ...free configuration array */
    free(configs);

    TRACE(INIT, _b("EGL initialized"));

    return 0;

error_cfg:
    /* ...destroy configuration array */
    free(configs);

error:
    /* ...close a display */
    fini_egl(display);

    return -1;
}

/*******************************************************************************
 * Shaders support
 ******************************************************************************/

/* ...shader compilation code */
static inline GLuint compile_shader(GLenum type, int count, const char * const *sources, char *msg, int len)
{
    GLuint      s;
    GLint       status;

    CHK_ERR(s = glCreateShader(type), GL_NONE);
    glShaderSource(s, (count ? : 1), sources, NULL);
    glCompileShader(s);
    glGetShaderiv(s, GL_COMPILE_STATUS, &status);
    if (!status)
    {
        glGetShaderInfoLog(s, len, NULL, msg);
        glDeleteShader(s);
        TRACE(ERROR, _b("shader compilation error: %s\n\n%s\n\n"), msg, sources[0]);
        return GL_NONE;
    }
    else
    {
        return s;
    }
}

/* ...create shader object */
shader_data_t * shader_create(const shader_desc_t *desc)
{
    display_data_t     *display = &__display;
    EGLContext          ctx = eglGetCurrentContext();
    shader_data_t      *shader;
    char                msg[512];
    GLint               status;
    GLuint              program;
    const char * const *attr = desc->attr;
    const char * const *uni = desc->uni;
    int                 i;

    /* ...sanity check */
    CHK_ERR(desc && desc->attr && desc->uni && desc->v_src && desc->f_src, (errno = EINVAL, NULL));

    /* ...allocate shader data structure */
    CHK_ERR(shader = calloc(1, sizeof(*shader) + sizeof(GLint) * desc->uni_num), (errno = ENOMEM, NULL));

    /* ...get GL context if needed */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    GLCHECK();

    /* ...create a program */
    if ((shader->program = program = glCreateProgram()) == GL_NONE)
    {
        TRACE(ERROR, _x("failed to create a program: %X"), glGetError());
        errno = EINVAL;
        goto error;
    }

    uint32_t    t0 = __get_time_usec(), t1, t2;

    /* ...load binary shader if needed */
    if (desc->name != NULL)
    {
        FILE    *f;

        if ((f = fopen(desc->name, "rb")) != NULL)
        {
            long    size;
            void   *buf;

            /* ...try loading the binary shader */
            fseek(f, 0, SEEK_END);
            size = ftell(f);
            fseek(f, 0, SEEK_SET);

            buf = malloc(size);
            TRACE(INFO, _b("load shader from '%s': %ld bytes"), desc->name, size);

            if (fread(buf, size, 1, f) == 1)
            {
                t1 = __get_time_usec();
                glProgramBinary(program, 0x9130, buf, size);    GLCHECK();
                fclose(f);
                free(buf);
                goto done;
            }
            else
            {
                fclose(f);
                free(buf);
            }
        }
    }

    /* ...vertex/fragment shaders compilation (single source) */
    if ((shader->v_shader = compile_shader(GL_VERTEX_SHADER, desc->v_src_num, desc->v_src, msg, sizeof(msg))) == GL_NONE)
    {
        TRACE(ERROR, _x("failed to compile vertex shader"));
        errno = EINVAL;
        goto error;
    }
    else if ((shader->f_shader = compile_shader(GL_FRAGMENT_SHADER, desc->f_src_num, desc->f_src, msg, sizeof(msg))) == GL_NONE)
    {
        TRACE(ERROR, _x("failed to compile fragment shader"));
        errno = EINVAL;
        goto error;
    }

    t1 = __get_time_usec();

    /* ...attach vertex/fragment shaders to program */
    glAttachShader(program, shader->v_shader);
    glAttachShader(program, shader->f_shader);

    /* ...bind all user-supplied attributes */
    for (i = 0; i < desc->attr_num; i++)
    {
        glBindAttribLocation(program, i, *attr++);

        /* ...emit warning if something goes wrong */
        if ((status = glGetError()) != GL_NO_ERROR)
        {
            TRACE(ERROR, _x("attribute #%d ('%s') binding failed: %X"), i, attr[-1], status);
        }
    }

    /* ...link a program */
    glLinkProgram(program);

done:
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (!status)
    {
        glGetProgramInfoLog(program, sizeof(msg), NULL, msg);
        TRACE(ERROR, _x("program link error: %s"), msg);
        errno = EINVAL;
        goto error;
    }

    t2 = __get_time_usec();

    TRACE(INFO, _b("shader '%s' compilation: %u/%u (%u)"), (desc->name ? : ""), t1 - t0, t2 - t1, t2 - t0);

    if (desc->name != NULL && shader->f_shader != 0)
    {
        /* ...save shader binary */
        uint8_t     buf[128 << 10];
        GLsizei     length;
        GLenum      format;

        GLCHECK();

        glGetProgramBinary(program, sizeof(buf), &length, &format, buf);
        if ((status = glGetError()) != GL_NO_ERROR)
        {
            TRACE(ERROR, _x("failed to get program binary: %X"), status);
        }
        else
        {
            FILE   *f;

            if ((f = fopen(desc->name, "wb")) != NULL)
            {
                fwrite(buf, length, 1, f);

                TRACE(INFO, _b("shader '%s' binary saved: format=%x, length=%u"), desc->name, format, length);
            }
        }
    }

    /* ...locate user-provided uniforms */
    for (i = 0; i < desc->uni_num; i++)
    {
        /* ...emit warning if uniform is not found */
        if ((shader->uniform[i] = glGetUniformLocation(program, *uni++)) < 0)
        {
            TRACE(DEBUG, _b("uniform #%d ('%s') not found"), i, uni[-1]);
        }
    }

    /* ...all correct; release shared context as needed */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    TRACE(INFO, _b("shader[%p] created (%d attributes, %d uniforms)"), shader, desc->attr_num, desc->uni_num);

    return shader;

error:
    /* ...destroy vertex shader as needed */
    (shader->v_shader ? glDeleteShader(shader->v_shader) : 0);

    /* ...destroy fragment shader as needed */
    (shader->f_shader ? glDeleteShader(shader->f_shader) : 0);

    /* ...destroy program */
    (shader->program ? glDeleteProgram(shader->program) : 0);

    /* ...release shared context as needed */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    /* ...free data structure */
    free(shader);

    return NULL;
}

/* ...shader destruction */
void shader_destroy(shader_data_t *shader)
{
    display_data_t     *display = &__display;
    EGLContext          ctx = eglGetCurrentContext();

    /* ...get GL context if needed */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...destroy vertex/fragment shaders */
    glDeleteShader(shader->v_shader);
    glDeleteShader(shader->f_shader);

    /* ...destroy program */
    glDeleteProgram(shader->program);

    /* ...release shared context as needed */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    /* ...free data structure */
    free(shader);

    TRACE(INFO, _b("shader[%p] destroyed"), shader);
}

/* ...get shader program */
GLuint shader_program(shader_data_t *shader)
{
    return shader->program;
}

/* ...get shader uniforms locations array */
const GLint * shader_uniforms(shader_data_t *shader)
{
    return shader->uniform;
}

/*******************************************************************************
 * Display dispatch thread
 ******************************************************************************/

egl_data_t  * display_egl_data(display_data_t *display)
{
    return &display->egl;
}

/* ...return EGL surface associated with window */
EGLSurface window_egl_surface(window_data_t *window)
{
    return window->egl;
}

EGLContext window_egl_context(window_data_t *window)
{
    return window->user_egl_ctx;
}

screen_context_t display_screen_context(display_data_t *display)
{
    return display->screen_ctx;
}

/*******************************************************************************
 * Window support
 ******************************************************************************/

/**
 * @brief   Setup window output buffers textures for usage as FBO attachments
 */
static int __window_setup_textures(window_data_t *window)
{
    display_data_t *display = window->display;
    int             num;
    int             i;
    int             ret;

    /* ...get number of window buffers */
    if (screen_get_window_property_iv(window->native, SCREEN_PROPERTY_RENDER_BUFFER_COUNT, &num) != 0)
    {
        TRACE(ERROR, _x("failed to get number of render-buffers"));
        return -(errno = EBADFD);
    }

    /* ...create required amount of FBOs */
    screen_buffer_t    *buffers;

    CHK_ERR(window->buffers = buffers = malloc(num * sizeof(*buffers)), -1);

    if (screen_get_window_property_pv(window->native, SCREEN_PROPERTY_RENDER_BUFFERS, (void **)buffers) < 0)
    {
        TRACE(ERROR, _x("failed to get render-buffers"));
        free(buffers);
        return -(errno = EBADFD);
    }

    CHK_ERR(window->fbo = calloc(window->fbo_num = num, sizeof(*window->fbo)), -1);

    for (i = 0; i < num; i++)
    {
        int     usage = SCREEN_USAGE_WRITE | SCREEN_USAGE_READ | SCREEN_USAGE_NATIVE | SCREEN_USAGE_OPENGL_ES3;
        int     size[2], stride, format;

        CHK_API(screen_get_buffer_property_iv(buffers[i], SCREEN_PROPERTY_BUFFER_SIZE, size));
        CHK_API(screen_get_buffer_property_iv(buffers[i], SCREEN_PROPERTY_STRIDE, &stride));
        CHK_API(screen_get_buffer_property_iv(buffers[i], SCREEN_PROPERTY_FORMAT, &format));

        TRACE(1, _b("screen-buffer-%d: size=%d*%d, stride=%d, format=%d"), i, size[0], size[1], stride, format);

        screen_pixmap_t     pixmap;

        CHK_API(screen_create_pixmap(&pixmap, display->screen_ctx));
        CHK_API(screen_set_pixmap_property_iv(pixmap, SCREEN_PROPERTY_USAGE, &usage));
        CHK_API(screen_set_pixmap_property_iv(pixmap, SCREEN_PROPERTY_FORMAT, &format));
        CHK_API(screen_set_pixmap_property_iv(pixmap, SCREEN_PROPERTY_BUFFER_SIZE, size));

        CHK_API(screen_attach_pixmap_buffer(pixmap, buffers[i]));

        texture_data_t     *texture;

        CHK_ERR(texture = texture_create_native(pixmap, 0), -1);

        fbo_data_t         *fbo;

        CHK_ERR(fbo = fbo_create_ext(size[0], size[1], (i == 0), 1), -1);

        if (fbo_get(fbo) < 0)
        {
            TRACE(ERROR, _x("failed to get fbo"));
            return -1;
        }

        if (fbo_attach_texture(fbo, texture, 1, 0) < 0)
        {
            TRACE(ERROR, _x("failed to attach FBO texture: %s"), strerror(errno));
            return -1;
        }

        fbo_put(fbo);

        window->fbo[i] = fbo;
    }

    /* ...move the origin to upper left */
    glClipControlEXT(GL_UPPER_LEFT_EXT, GL_NEGATIVE_ONE_TO_ONE_EXT);

    return 0;
}

/**
 * @brief   Create native window
 *
 * @param   display[in]         Display data
 * @param   info[in]            Window info structure
 * @param   cdata[in]           Client data
 *
 * @return                      Window handle, or NULL on failure
 */
window_data_t * window_create(display_data_t *display, window_info_t *info, void *cdata)
{
    int                 width = info->width;
    int                 height = info->height;
    EGLContext          ctx = eglGetCurrentContext();
    EGLSurface          read = eglGetCurrentSurface(EGL_READ);
    EGLSurface          draw = eglGetCurrentSurface(EGL_DRAW);
    window_data_t      *window;
    pthread_attr_t      attr;
    int                 r, i;

    /* ...use default desplay if set (hmm - tbd) */
    (display == NULL ? display = &__display : 0);

    /* ...allocate a window data */
    if ((window = calloc(1, sizeof(*window))) == NULL)
    {
        TRACE(ERROR, _x("failed to allocate memory"));
        errno = ENOMEM;
        return NULL;
    }

    /* ...initialize window data access lock */
    pthread_mutex_init(&window->lock, NULL);

    /* ...save display handle */
    window->display = display;

    /* ...save window info data */
    window->info = info, window->cdata = cdata;

    /* ...set window dimensions */
    window->width = width;
    window->height = height;

    /* ...reset frame-rate calculator */
    window_frame_rate_reset(window);

    /* ...create native window */
    window->native = info->native;

    BUG(!window->native, _x("failed to create native window..."));

    if (!USE_EXTERNAL_FBO)
    {
        /* ...create EGL surface for a native window */
        window->egl = eglCreateWindowSurface(display->egl.dpy, display->egl.conf, window->native, NULL);

        BUG(!window->egl, _x("failed to create EGL surface...: %X"), eglGetError());

        /* ...create window user EGL context (share textures with everything else?)*/
        window->user_egl_ctx = eglCreateContext(display->egl.dpy, display->egl.conf, display->egl.ctx, __egl_context_attribs);

        /* ...set window EGL context */
        eglMakeCurrent(display->egl.dpy, window->egl, window->egl, window->user_egl_ctx);
    }
    else
    {
        /* ...display context is shared with all windows; context is surfaceless */
        eglMakeCurrent(display->egl.dpy, EGL_NO_SURFACE, EGL_NO_SURFACE, display->egl.ctx);
    }

    TRACE(INIT, _b("GL version: %s"), (char *)glGetString(GL_VERSION));

    GLint     num_ext = 0;
    glGetIntegerv(GL_NUM_EXTENSIONS, &num_ext);
    TRACE(INIT, _b("GL extensions: %d"), num_ext);
    for (i = 0; i < num_ext; i++)
    {
        TRACE(INIT, _n("%s"), (const char*)glGetStringi(GL_EXTENSIONS, i));
    }

    /* ...set-up off-screen rendering textures for external FBOs */
    if (USE_EXTERNAL_FBO && __window_setup_textures(window) < 0)
    {
        TRACE(ERROR, _x("failed to create off-screen FBOs: %s"), strerror(errno));
        goto error;
    }

    /* ...initialize window context data */
    if (info->init)
    {
        if (info->init(display, window, cdata) < 0)
        {
            TRACE(ERROR, _x("window initialization failed: %s"), strerror(errno));
            goto error;
        }
    }

    /* ...release window EGL context */
    if (0) eglMakeCurrent(display->egl.dpy, draw, read, ctx);

    /* ...add window to global display list */
    __list_push_tail(&display->windows, &window->link);

    TRACE(INFO, _b("window created: %p:%p:%p, %u*%u"), window, window->egl, window->native, width, height);

    return window;

error:
    /* ...destroy window memory */
    free(window);
    return NULL;
}

/**
 * @brief   Destroy window
 *
 * @param   window[in]      Windod handle
 */
void window_destroy(window_data_t *window)
{
    display_data_t         *display = window->display;
    EGLDisplay              dpy = display->egl.dpy;
    EGLContext              ctx = eglGetCurrentContext();
    EGLSurface              read = eglGetCurrentSurface(EGL_READ);
    EGLSurface              draw = eglGetCurrentSurface(EGL_DRAW);
    const window_info_t    *info = window->info;

    /* ...acquire display lock */
    pthread_mutex_lock(&display->lock);

    /* ...remove window from global display list */
    __list_delete(&window->link);

    if (info->destroy)
    {
        /* ...acquire window context before doing anything */
        if (!USE_EXTERNAL_FBO)
        {
            eglMakeCurrent(dpy, window->egl, window->egl, window->user_egl_ctx);
        }

        /* ...invoke custom window destructor function as needed */
        info->destroy(window, window->cdata);

        /* ...revert EGL context before destruction */
        eglMakeCurrent(dpy, read, draw, ctx);
    }

    if (!USE_EXTERNAL_FBO)
    {
        /* ...destroy window context */
        eglDestroyContext(dpy, window->user_egl_ctx);

        /* ...destroy EGL surface */
        eglDestroySurface(dpy, window->egl);
    }

    /* ...destroy window lock */
    pthread_mutex_destroy(&window->lock);

    /* ...destroy object */
    free(window);

    pthread_mutex_unlock(&display->lock);

    TRACE(INFO, _b("window[%p] destroyed"), window);
}

/* ...return current window width */
int window_get_width(window_data_t *window)
{
    return window->width;
}

/* ...return current window height */
int window_get_height(window_data_t *window)
{
    return window->height;
}

/**
 * @brief   Schedule redrawal of the window
 *
 * @param   window[in]              Window handle
 */
void window_schedule_redraw(window_data_t *window)
{
    display_data_t *display = window->display;

    /* ...acquire window lock */
    pthread_mutex_lock(&window->lock);

    if (USE_EXTERNAL_FBO)
    {
        /* ...get next framebuffer index */
        if (fbo_get(window->fbo[window->fbo_idx]) == 0)
        {
            /* ...invoke user-supplied hook */
            if (window->info && window->info->redraw)
                window->info->redraw(display, window->cdata);
            else
                TRACE(ERROR, _x("Redraw hook not defined"));
        }
        else
        {
            TRACE(ERROR, _x("failed to acquire fbo: %s"), strerror(errno));
        }
    }
    else
    {
        /* ...re-acquire window GL context */
        eglMakeCurrent(display->egl.dpy, window->egl, window->egl, window->user_egl_ctx);

        /* ...invoke user-supplied hook */
        if (window->info && window->info->redraw)
            window->info->redraw(display, window->cdata);
        else
            TRACE(ERROR, _x("Redraw hook not defined"));
    }

    /* ...release window access lock */
    pthread_mutex_unlock(&window->lock);
}

/**
 * @brief   Submit window to a renderer
 *
 * @param   window[in]          Window handle
 */
int window_draw(window_data_t *window)
{
    display_data_t *display = window->display;
    int             W = window_get_width(window);
    int             H = window_get_height(window);
    int             i;
    int             ret = 0;

#if 0
    /* ...we should not call that function in user-window context */
    BUG(eglGetCurrentDisplay() != window->display->egl.dpy, _x("invalid egl display"));
    BUG(eglGetCurrentSurface(EGL_READ) != window->egl || window->egl == EGL_NO_SURFACE, _x("invalid egl read surface"));
    BUG(eglGetCurrentSurface(EGL_DRAW) != window->egl, _x("invalid egl draw surface"));
    BUG(eglGetCurrentContext() != window->user_egl_ctx || window->user_egl_ctx == EGL_NO_CONTEXT, _x("invalid egl context"));
#endif

    if (USE_EXTERNAL_FBO)
    {
        u32 t0 = __get_time_usec();

        /* ...unbind current FBO */
        fbo_put(window->fbo[window->fbo_idx]);

        /* ...no real need in sending this but to get input events */
        screen_post_window(window->native, window->buffers[window->fbo_idx], 0, NULL, 0);

        u32 t1 = __get_time_usec();

        /* ...advance FBO index */
        (++window->fbo_idx == window->fbo_num ? window->fbo_idx = 0 : 0);

        TRACE(DEBUG, _b("post[%p] - %d*%d: %u (error=%X)"), window, W, H, t1 - t0, eglGetError());
    }
    else
    {
        u32 t0 = __get_time_usec();

        eglSwapBuffers(display->egl.dpy, window->egl);

        u32 t1 = __get_time_usec();

        TRACE(DEBUG, _b("swap[%p] - %d*%d: %u (error=%X)"), window, W, H, t1 - t0, eglGetError());
    }

    return ret;
}

/*******************************************************************************
 * Display module initialization
 ******************************************************************************/

/* ...create display data */
display_data_t * display_create(screen_context_t screen_ctx, int width, int height)
{
    display_data_t     *display = &__display;
    pthread_attr_t      attr;
    int                 r, j, pixmap_cnt = 0;
    int                 stride, bufsize;

    if (width <= 0 || height <= 0)
        return NULL;

    /* ...reset display data */
    memset(display, 0, sizeof(*display));

    display->screen_ctx = screen_ctx;

    /* ...initialize windows list */
    __list_init(&display->windows);

    /* ...create a display command/response lock */
    pthread_mutex_init(&display->lock, NULL);

    TRACE(1, _b("initialize display..."));

    /* ...initialize EGL */
    if (init_egl(display) < 0)
    {
        TRACE(ERROR, _x("EGL initialization failed: %m"));
        goto error;
    }

    /* ...release display EGL context */
    eglMakeCurrent(display->egl.dpy, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);

    /* ...initialize thread attributes (joinable, default stack size) */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    /* ...create dispatch thread */
    r = pthread_create(&display->thread, &attr, dispatch_thread, display);
    pthread_attr_destroy(&attr);
    if (r != 0)
    {
        TRACE(ERROR, _x("thread creation failed: %m"));
        goto error;
    }

    /* ...wait until display thread starts? */
    TRACE(INIT, _b("Display interface initialized"));

    init_gestures(display);

    return display;

error:
    return NULL;
}

/*******************************************************************************
 * Textures handling
 ******************************************************************************/

/**
 * @brief   Convert video format to internal GL format
 *
 * @param   format[in]          Video format
 * @param   w[in]               Image width
 * @param   h[in]               Image height
 * @param   fmt[out]            Internal GL formats; per-plane
 * @param   W[out]              Plane widths (in pixels)
 * @param   H[out]              Plane heights
 * @param   S[out]              Plane strides (in bytes)
 * @param   O[out]              Plane offset within pixel-buffer
 * @param   size[out]           Total pixel-buffer size
 * @return                      Number of planes, or zero
 */
static inline int __pixfmt_gst_to_gl(int format, int w, int h, GLenum  *fmt, int *W, int *H, int *S, int *O, int *size)
{
    switch (format)
    {
    case GST_VIDEO_FORMAT_ARGB:
    case GST_VIDEO_FORMAT_RGBA:
    case GST_VIDEO_FORMAT_BGRA:
        O[0] = 0, W[0] = w, H[0] = h, fmt[0] = GL_RGBA;
        *size = (S[0] = w * 4) * h;
        return 1;

    case GST_VIDEO_FORMAT_RGB:
    case GST_VIDEO_FORMAT_BGR:
        O[0] = 0, W[0] = w, H[0] = h, fmt[0] = GL_RGB;
        *size = (S[0] = w * 3) * h;
        return 1;

    case GST_VIDEO_FORMAT_UYVY:
    case GST_VIDEO_FORMAT_YUY2:
    case GST_VIDEO_FORMAT_YVYU:
        O[0] = 0, W[0] = w, H[0] = h, fmt[0] = GL_RG;
        O[1] = 0, W[1] = w / 2, H[1] = h, fmt[1] = GL_RGBA;
        *size = (S[0] = S[1] = w * 2) * h;
        return 2;

    case GST_VIDEO_FORMAT_NV16:
        O[0] = 0, W[0] = w, H[0] = h, fmt[0] = GL_RED;
        O[1] = w * h, W[1] = w / 2, H[1] = h, fmt[1] = GL_RG;
        *size = (S[0] = S[1] = w) * 2 * h;
        return 2;

    case GST_VIDEO_FORMAT_NV12:
        O[0] = 0, W[0] = w, H[0] = h, fmt[0] = GL_RED;
        O[1] = w * h, W[1] = w / 2, H[1] = h / 2, fmt[1] = GL_RG;
        S[0] = w, S[1] = w;
        *size = w * h * 3 / 2;
        return 2;

    case GST_VIDEO_FORMAT_GRAY8:
        O[0] = 0, W[0] = w, H[0] = h, fmt[0] = GL_RED;
        *size = (S[0] = w) * h;
        return 1;

    case GST_VIDEO_FORMAT_I420:
    case GST_VIDEO_FORMAT_YV12:
        O[0] = 0, W[0] = w, H[0] = h, fmt[0] = GL_RED;
        O[1] = w * h, W[1] = w / 2, H[1] = h / 2, fmt[1] = GL_RED;
        O[2] = w * h + W[1] * H[1], W[2] = w / 2, H[2] = h / 2, fmt[2] = GL_RED;
        S[0] = w, S[1] = S[2] = w / 2;
        *size = w * h * 3 / 2;
        return 3;

    default:
        return TRACE(ERROR, _x("unsupported PBO format: %d"), format), 0;
    }
}

/* ...calculate cropping and viewport parameters for a texture */
void texture_set_view(texture_view_t *vcoord, int x0, int y0, int x1, int y1)
{
    (*vcoord)[0] = x0;
    (*vcoord)[1] = y0;
    (*vcoord)[2] = x1;
    (*vcoord)[3] = y1;
}

/* ...set texture cropping data */
void texture_set_crop(texture_crop_t *tcoord, int x0, int y0, int x1, int y1)
{
    (*tcoord)[0] = x0;
    (*tcoord)[1] = y0;
    (*tcoord)[2] = x1;
    (*tcoord)[3] = y1;
}

static inline int texture_view_x0(texture_view_t *v)
{
    return (*v)[0];
}

static inline int texture_view_y0(texture_view_t *v)
{
    return (*v)[1];
}

static inline int texture_view_x1(texture_view_t *v)
{
    return (*v)[2];
}

static inline int texture_view_y1(texture_view_t *v)
{
    return (*v)[3];
}

static inline float texture_view_width(texture_view_t *v)
{
    return ((*v)[2] - (*v)[0]);
}

static inline float texture_view_height(texture_view_t *v)
{
    return ((*v)[3] - (*v)[1]);
}

static inline int texture_crop_x0(texture_crop_t *c)
{
    return (*c)[0];
}

static inline int texture_crop_y0(texture_crop_t *c)
{
    return (*c)[1];
}

static inline int texture_crop_x1(texture_crop_t *c)
{
    return (*c)[2];
}

static inline int texture_crop_y1(texture_crop_t *c)
{
    return (*c)[3];
}

static inline float texture_crop_width(texture_crop_t *c)
{
    return ((*c)[2] - (*c)[0]);
}

static inline float texture_crop_height(texture_crop_t *c)
{
    return ((*c)[3] - (*c)[1]);
}

/*******************************************************************************
 * Pixel-buffer objects support
 ******************************************************************************/

/**
 * @brief   Create PBO descriptor
 *
 * @param   width[in]       Image width
 * @param   height[in]      Image height
 * @param   format[in]      Image format
 *
 * @return                  Texture handle, or NULL on failure
 */
static inline pbo_data_t * __pbo_create_desc(int width, int height, int format)
{
    pbo_data_t     *pbo;

    /* ...allocate descriptor data */
    CHK_ERR(pbo = calloc(1, sizeof(*pbo)), NULL);

    /* ...calculate buffer size and internal format */
    if ((pbo->n = __pixfmt_gst_to_gl(format, width, height, pbo->fmt, pbo->w, pbo->h, pbo->s, pbo->o, &pbo->size)) == 0)
    {
        TRACE(ERROR, _b("invalid pixel-format: %d*%d@%d"), width, height, format);
        free(pbo), pbo = NULL;
    }
    else
    {
        /* ...fill descriptor data */
        pbo->width = width;
        pbo->height = height;
        pbo->format = format;
    }

    return pbo;
}

/**
 * @brief   Generate data buffer for PBO downloading
 *
 * @param   pbo[in]         PBO handle
 *
 * @return                  Negative on failure
 */
static inline int __pbo_create_buffer(pbo_data_t *pbo)
{
    GLenum      err;

    /* ...generate buffer */
    glGenBuffers(1, &pbo->pbo);     GLCHECK();
    glBindBuffer(GL_PIXEL_PACK_BUFFER, pbo->pbo);     GLCHECK();
    glBufferData(GL_PIXEL_PACK_BUFFER, pbo->size, NULL, GL_STREAM_DRAW);
    if ((err = glGetError()) != GL_NO_ERROR)
    {
        TRACE(ERROR, _x("failed to allocate pixel-buffer: %x"), err);
        return -(errno = ENOMEM);
    }

    TRACE(INIT, _b("PBO buffer %u created (%d*%d, size=%d)"), pbo->pbo, pbo->width, pbo->height, pbo->size);

    return 0;
}

/**
 * @brief   Generate textures for PBO
 *
 * @param   pbo[in]         PBO handle
 *
 * @return                  Negative on failure
 */
static inline int __pbo_create_textures(pbo_data_t *pbo)
{
    GLenum      err;
    int         k;

    /* ...generate textures for each plane */
    glGenTextures(pbo->n, pbo->tex);     GLCHECK();

    for (k = 0; k < pbo->n; k++)
    {
        TRACE(DEBUG, _b("generate texture %u of %u: %u"), k, pbo->n, pbo->tex[k]);

        glBindTexture(GL_TEXTURE_2D, pbo->tex[k]);  GLCHECK();

        glTexImage2D(GL_TEXTURE_2D, 0, pbo->fmt[k], pbo->w[k], pbo->h[k], 0, pbo->fmt[k], GL_UNSIGNED_BYTE, NULL);
        if ((err = glGetError()) != GL_NO_ERROR)
        {
            TRACE(ERROR, _x("failed to allocate plane #%d: %d*%d@%x: %x"), k, pbo->w[k], pbo->h[k], pbo->fmt[k], err);
            return -(errno = ENOMEM);
        }
        else
        {
            TRACE(DEBUG, _b("plane-%d: %d*%d@%x, tex=%d (offset=%d)"), k, pbo->w[k], pbo->h[k], pbo->fmt[k], pbo->tex[k], pbo->o[k]);
        }

        /* ...set some default parameters */
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }

    TRACE(INIT, _b("textures %d*%d@%d created: %d/%d/%d/%d"), pbo->width, pbo->height, pbo->format, pbo->tex[0], pbo->tex[1], pbo->tex[2], pbo->tex[3]);

    return 0;
}

/**
 * @brief   Create pixel-buffer object
 *
 * @param   width[in]       Image width
 * @param   height[in]      Image height
 * @param   format[in]      Image format
 *
 * @return                  PBO handle on success or NULL
 */
pbo_data_t * pbo_create(int width, int height, int format)
{
    display_data_t     *display = &__display;
    EGLContext          ctx = eglGetCurrentContext();
    pbo_data_t         *pbo;

    /* ...create PBO descriptor */
    CHK_ERR(pbo = __pbo_create_desc(width, height, format), NULL);

    /* ...acquire rendering context as needed */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...generate PBO buffer for downloading texture */
    if (__pbo_create_buffer(pbo) < 0)
    {
        TRACE(ERROR, _x("failed to generate buffer: %m"));
        goto error;
    }
    else if (__pbo_create_textures(pbo) < 0)
    {
        TRACE(ERROR, _x("failed to generate textures: %m"));
        goto error;
    }
    else
    {
        TRACE(INFO, _b("pbo[%d] %d*%d@%d created: tex=%d/%d/%d/%d"), pbo->pbo, width, height, format, pbo->tex[0], pbo->tex[1], pbo->tex[2], pbo->tex[3]);
        goto out;
    }

error:
    /* ...destroy PBO object */
    pbo_destroy(pbo), pbo = NULL;

out:
    /* ...clear bindings */
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(GL_PIXEL_PACK_BUFFER, 0);

    /* ...release context as needed */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    return pbo;
}

/* ...destroy pixel-buffer object */
void pbo_destroy(pbo_data_t *pbo)
{
    display_data_t     *display = &__display;
    EGLContext          ctx = eglGetCurrentContext();

    /* ...get shared display context as needed */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...destroy textures objects if set */
    (pbo->tex[0] != 0 ? glDeleteTextures(pbo->n, pbo->tex) : 0);

    /* ...destroy pixel-buffer */
    (pbo->pbo != 0 ? glDeleteBuffers(1, &pbo->pbo) : 0);

    TRACE(INIT, _b("PBO[%u] object destroyed"), pbo->pbo);

    /* ...release display context */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    /* ...destroy VBO handle */
    free(pbo);
}

/**
 * @brief   Acquire pixel-buffer object mapping
 *
 * @param   pbo[in]         PBO handle
 *
 * @return                  PBO data buffer pointer, or NULL
 */
void * pbo_map(pbo_data_t *pbo)
{
    display_data_t     *display = &__display;
    EGLContext          ctx = eglGetCurrentContext();
    GLenum              err;
    void               *map;

    /* ...make sure buffer is not mapped */
    BUG(pbo->mapped, _x("invalid map: %x"), pbo->mapped);

    pbo->mapped = pthread_self();

    /* ...acquire rendering context as needed (save current in a scratch memory) */
    ((pbo->ctx = ctx) == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...bind buffer object in current EGL context */
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pbo->pbo);    GLCHECK();

    /* ...map buffer to user-space */
    map = glMapBufferRange(GL_PIXEL_UNPACK_BUFFER, 0, pbo->size, GL_MAP_WRITE_BIT | GL_MAP_READ_BIT);

    if ((err = glGetError()) != GL_NO_ERROR)
    {
        TRACE(ERROR, _x("failed to map pixel-buffer: %X"), err);
        return NULL;
    }

    /* ...unbind buffer to allow GL operations */
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);    GLCHECK();

    TRACE(DEBUG, _b("mapped pbo #%d: size=%d, map=%p"), pbo->pbo, pbo->size, map);

    return map;
}

/**
 * @brief   Synchronize PBO and associated texture
 *
 * @param   pbo[in]         PBO handle
 */
void pbo_sync(pbo_data_t *pbo)
{
    display_data_t     *display = &__display;
    EGLContext          ctx = eglGetCurrentContext();
    int                 k;

    /* ...acquire rendering context as needed */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pbo->pbo);     GLCHECK();

    /* ...upload associated textures */
    for (k = 0; k < pbo->n; k++)
    {
        glBindTexture(GL_TEXTURE_2D, pbo->tex[k]);      GLCHECK();
        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, pbo->w[k], pbo->h[k], pbo->fmt[k], GL_UNSIGNED_BYTE, (void *)(uintptr_t)pbo->o[k]); GLCHECK();
        TRACE(DEBUG, _b("upload: pbo[%u]: plane-%u[tex=%u], %d*%d@%x, offset=%u"), pbo->pbo, k, pbo->tex[k], pbo->w[k], pbo->h[k], pbo->fmt[k], pbo->o[k]);
    }

    /* ...clear bindings */
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);

    /* ...release shared display context if needed */
    (pbo->ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    TRACE(DEBUG, _b("PBO #%u synced"), pbo->pbo);
}

/**
 * @brief   Release PBO mapping
 *
 * @param   pbo[in]         PBO handle
 * @param   sync[in]        Associated texture synchronization flag
 */
void pbo_unmap(pbo_data_t *pbo, int sync)
{
    display_data_t     *display = &__display;
    EGLContext          ctx = eglGetCurrentContext();
    int                 k;

    /* ...make sure we have active GL context - sort of weird */
    BUG(ctx == EGL_NO_CONTEXT, _x("invalid context: %p"), ctx);

    /* ...unmap buffer array */
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pbo->pbo);     GLCHECK();
    glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);      GLCHECK();

    /* ...sync with associated texture as needed */
    (sync ? pbo_sync(pbo) : 0);

    /* ...clear bindings */
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);

    TRACE(DEBUG, _b("buffer #%u unmapped"), pbo->pbo);

    pbo->mapped = 0;

    /* ...release shared display context if needed */
    (pbo->ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);
}

/*******************************************************************************
 * Textures support
 ******************************************************************************/

/**
 * @brief   Map texture pixel-data
 *
 * @param   texture[in]     Texture handle
 * @param   image[out]      Image descriptor
 *
 * @return                  Negative on failure
 */
int texture_map(texture_data_t *texture, image_data_t *image)
{
    screen_pixmap_t pixmap = (screen_pixmap_t)texture->pbo;
    screen_buffer_t buffer;
    void           *data;

    /* ...make sure pixmap is available */
    CHK_ERR(pixmap != NULL, -(errno = EINVAL));

    /* ...get pixmap buffer */
    if (screen_get_pixmap_property_pv(pixmap, SCREEN_PROPERTY_RENDER_BUFFERS, (void **)&buffer) != 0)
    {
        TRACE(ERROR, _x("failed to retrieve buffer: %s"), strerror(errno));
        return -1;
    }

    /* ...get user-accessible pointer */
    if (screen_get_buffer_property_pv(buffer, SCREEN_PROPERTY_POINTER, &data) != 0)
    {
        TRACE(ERROR, _x("failed to retrieve buffer: %s"), strerror(errno));
        return -1;
    }

    int32_t planar_offsets[4] = { 0 };

    if (screen_get_buffer_property_iv(buffer, SCREEN_PROPERTY_PLANAR_OFFSETS, planar_offsets) != 0)
    {
        TRACE(ERROR, _x("failed to retrieve buffer: %s"), strerror(errno));
        return -1;
    }

    /* ...clear image descriptor */
    memset(image, 0, sizeof(*image));

    /* ...fill image mapping descriptor (for YUY2) */
    image->fourcc = texture->format;
    image->width = texture->w;
    image->height = texture->h;

    switch (texture->format)
    {
    case SCREEN_FORMAT_YUY2:
    case SCREEN_FORMAT_YVYU:
    case SCREEN_FORMAT_UYVY:
        image->size = texture->w * texture->h * 2;
        image->planes = 1;
        image->stride[0] = texture->w * 2;
        image->data[0] = data;
        break;

    case SCREEN_FORMAT_RGB888:
        image->size = texture->w * texture->h * 3;
        image->planes = 1;
        image->stride[0] = texture->w * 3;
        image->data[0] = data;
        break;

    case SCREEN_FORMAT_RGBA8888:
        image->size = texture->w * texture->h * 4;
        image->planes = 1;
        image->stride[0] = texture->w * 4;
        image->data[0] = data;
        break;

    case SCREEN_FORMAT_NV12:
        image->size = texture->w * texture->h * 3 / 2;
        image->planes = 2;
        image->stride[0] = texture->w;
        image->stride[1] = texture->w;
        image->data[0] = data;
        image->data[1] = data + planar_offsets[1];
        break;

    default:
        /* ...grayscale */
        image->size = texture->w * texture->h;
        image->planes = 1;
        image->stride[0] = texture->w;
        image->data[0] = data;
    }

    return 0;
}

/**
 * @brief   Unmap texture pixel-data
 *
 * @param   texture[in]     Texture handle
 */
void texture_unmap(texture_data_t *texture)
{
    /* ...do nothing */
}

/**
 * @brief   Create GL texture wrapping native pixmap
 */
/**
 * @brief   Create GL texture wrapping native pixmap
 */
static texture_data_t* __texture_create_native(int w, int h, int format, screen_pixmap_t pixmap, GLuint target)
{
    display_data_t *display = &__display;
    texture_data_t *texture;

    /* ...create texture data */
    CHK_ERR(texture = calloc(1, sizeof(*texture)), NULL);
    texture->w = w;
    texture->h = h;
    texture->format = format;
    texture->pbo = (pbo_data_t *)pixmap;

    /* ...create EGL image from native pixmap */
    texture->image = eglCreateImageKHR(display->egl.dpy, EGL_NO_CONTEXT, EGL_NATIVE_PIXMAP_KHR, pixmap, NULL);
    if (texture->image == EGL_NO_IMAGE_KHR)
    {
        TRACE(ERROR, _x("pixmap: %p, failed to create EGL image %d*%d@%d: %X"), pixmap, w, h, format, eglGetError());
        errno = ENOMEM;
        goto error;
    }

    glGenTextures(1, &texture->tex[0]);

    /* ...bind texture to the output device */
    glBindTexture(target, texture->tex[0]);
    glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glEGLImageTargetTexture2DOES(target, texture->image);
    glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(target, 0); GLCHECK();

    return texture;

error:
    free(texture);
    return NULL;
}

/**
 * @brief   Create native (no backing store) texture
 *
 * @param   width[in]       Image width
 * @param   height[in]      Image height
 * @param   format[in]      Image format
 *
 * @return                  Texture handle, or NULL on failure
 */
texture_data_t * texture_create(int width, int height, int format)
{
    display_data_t     *display = &__display;
    EGLDisplay          dpy = display->egl.dpy;
    EGLContext          ctx = eglGetCurrentContext();
    int32_t             size[2] = { width, height };
    int32_t             usage = SCREEN_USAGE_WRITE | SCREEN_USAGE_READ | SCREEN_USAGE_NATIVE | SCREEN_USAGE_OPENGL_ES3;
    int32_t             buffer_size;
    void               *data;
    screen_buffer_t     created_buf;
    screen_pixmap_t     pixmap;
    texture_data_t     *texture = NULL;

    /* ...create pixmap */
    CHK_ERR(screen_create_pixmap(&pixmap, display->screen_ctx) == 0, NULL);
    CHK_ERR(screen_set_pixmap_property_iv(pixmap, SCREEN_PROPERTY_USAGE, &usage) == 0, NULL);
    CHK_ERR(screen_set_pixmap_property_iv(pixmap, SCREEN_PROPERTY_FORMAT, &format) == 0, NULL);
    CHK_ERR(screen_set_pixmap_property_iv(pixmap, SCREEN_PROPERTY_BUFFER_SIZE, size) == 0, NULL);
    if (screen_create_pixmap_buffer(pixmap) != 0)
    {
        TRACE(ERROR, _x("failed to create pixmap buffer: %s"), strerror(errno));
        goto error;
    }

    /* ...get pixmap buffer parameters */
    CHK_ERR(screen_get_pixmap_property_pv(pixmap, SCREEN_PROPERTY_BUFFERS, (void**)&created_buf) == 0, NULL);
    CHK_ERR(screen_get_buffer_property_iv(created_buf, SCREEN_PROPERTY_SIZE, &buffer_size) == 0, NULL);
    CHK_ERR(screen_get_buffer_property_pv(created_buf, SCREEN_PROPERTY_POINTER, (void**)&data) == 0, NULL);

    /* ...get shared display EGL context */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    texture = __texture_create_native(size[0], size[1], format, pixmap, GL_TEXTURE_2D);

    /* ...release shared display context */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    if (texture != NULL)
    {
        TRACE(INIT, _b("texture[%u] created: %d*%d@%d, size=%u, ptr=%p"), texture->tex[0], width, height, format, buffer_size, data);
    }
    else
    {
        TRACE(ERROR, _x("failed to create texture: %s"), strerror(errno));
        goto error;
    }

    return texture;

error:
    /* ...release PBO handle */
    screen_destroy_pixmap(pixmap);

    return NULL;
}

/*************************************************************
		QNX screen textures
*************************************************************/

/**
 * @brief   Create texture from pixmap
 *
 * @param   pixmap[in]      Pixmap handle
 *
 * @return                  Texture data, or NULL on failure
 */
texture_data_t * texture_create_native(EGLClientBuffer pixmap, int ext)
{
    display_data_t         *display = &__display;
    EGLContext              ctx = eglGetCurrentContext();
    texture_data_t         *texture = NULL;
    int                     size[2];
    int                     fmt;
    screen_pixmap_t         screen_pixmap = pixmap;

    /* ...get buffer dimensions */
    CHK_ERR(screen_get_pixmap_property_iv(screen_pixmap, SCREEN_PROPERTY_BUFFER_SIZE, size) == 0, (errno = EBADFD, NULL));

    /* ...get buffer format */
    CHK_ERR(screen_get_pixmap_property_iv(screen_pixmap, SCREEN_PROPERTY_FORMAT, &fmt) == 0, (errno = EBADFD, NULL));

    /* ...get shared display EGL context */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    texture = __texture_create_native(size[0], size[1], fmt, pixmap, (ext ? GL_TEXTURE_EXTERNAL_OES : GL_TEXTURE_2D));

    TRACE(1, _b("pixmap %p: created texture %u: %d*%d@%d"), pixmap, texture->tex[0], size[0], size[1], fmt);

    /* ...release shared display context */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    return texture;
}

/**
 * @brief   Destroy texture
 *
 * @param   texture[in]     Texture handle
 */
void texture_destroy(texture_data_t *texture)
{
    display_data_t         *display = &__display;
    EGLContext              ctx = eglGetCurrentContext();

    /* ...get shared display EGL context */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    if (texture)
    {
        glDeleteTextures(sizeof(texture->tex) / sizeof(texture->tex[0]), texture->tex);
        (texture->image ? eglDestroyImageKHR(display->egl.dpy, texture->image) : 0);
    }

    /* ...release shared display context */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    /* ...destroy texture structure */
    free(texture);

    TRACE(INFO, _b("texture %p destroyed"), texture);
}

/*******************************************************************************
 * Texture rendering
 ******************************************************************************/

/**> Vertex shader construction */
#define __SH_VERTEX                             \
    SH_SETPREC                                  \
    "attribute vec2 XY;\n"                      \
    "attribute vec2 UV;\n"                      \
    "varying vec2 uv;\n"                        \
    "void main(void)\n"                         \
    "{\n"                                       \
    "   uv = UV;\n"                             \
    "   gl_Position = vec4(XY, 0.0, 1.0);\n"    \
    "}\n"

/**> Fragment shader construction */
#define __SH_FRAGMENT(format)                           \
    "#extension GL_OES_EGL_image_external : enable\n"   \
    SH_SETPREC                                          \
    "varying vec2 uv;\n"                                \
    SH_YUV2RGB                                          \
    __SHF_FETCH_##format                                \
    "uniform float alpha;\n"                            \
    "void main (void)\n"                                \
    "{\n"                                               \
    "   vec3    rgb = fetch(uv);\n"                     \
    "   gl_FragColor = vec4(rgb, alpha);\n"             \
    "}\n"

/*******************************************************************************
 * Dynamic shaders construction
 ******************************************************************************/

/**> Generic shader attributes */
#define __SHADER_ATTRIBUTES     \
    __A(XY), __A(UV)

/**> Generic shader uniforms */
#define __SHADER_UNIFORMS       \
    __U(tex), __U(alpha)

/**> Shader attributes ordinals */
#define __A(id)                 __TEX_SHADER_ATTRIBUTE_##id
enum __tex_shader_attributes {
    __SHADER_ATTRIBUTES,
    __SHADER_ATTRIBUTES_NUM
};
#undef  __A

/**> Shader uniforms ordinals */
#define __U(id)                 __TEX_SHADER_UNIFORM_##id
enum __tex_shader_uniforms {
    __SHADER_UNIFORMS,
    __SHADER_UNIFORMS_NUM
};
#undef  __U

/**> Shader attributes literals */
#define __A(id)                 #id
static const char * const __tex_shader_attributes_id[__SHADER_ATTRIBUTES_NUM + 1] = {
    __SHADER_ATTRIBUTES,
    NULL
};
#undef  __A

/**> Shader uniforms literals */
#define __U(id)                 #id
static const char * const __tex_shader_uniforms_id[__SHADER_UNIFORMS_NUM + 1] = {
    __SHADER_UNIFORMS,
    NULL
};
#undef  __U

/*******************************************************************************
 * Shader compilation
 ******************************************************************************/

/**> Supported shader formats */
enum tex_shader_type {
    TEX_SHADER_EXT,
    TEX_SHADER_RGB,
    TEX_SHADER_BGR,
    TEX_SHADER_I420,
    TEX_SHADER_NV12,
    TEX_SHADER_UYVY,
    TEX_SHADER_YV12,
    TEX_SHADER_YUYV,
    TEX_SHADER_NUMBER
};

/**
 * @brief   Compile shader for given texture format
 *
 * @param   type[in]        Shader type
 *
 * @return                  Shader pointer
 */
static shader_data_t * tex_shader_compile(int type)
{
    shader_data_t  *shader;
    shader_desc_t   desc;
    const char *    v_src;
    char *          v_strings[1] = { NULL };
    char *          f_strings[1] = { NULL };

    /* ...reset descriptor */
    memset(&desc, 0, sizeof(desc));

    /* ...prepare vertex shader program */
    v_strings[0] = __SH_VERTEX;

    switch (type)
    {
    case TEX_SHADER_RGB:
        f_strings[0] = __SH_FRAGMENT(RGB);
        break;
    case TEX_SHADER_BGR:
        f_strings[0] = __SH_FRAGMENT(BGR);
        break;
    case TEX_SHADER_I420:
        f_strings[0] = __SH_FRAGMENT(I420);
        break;
    case TEX_SHADER_NV12:
        f_strings[0] = __SH_FRAGMENT(NV12);
        break;
    case TEX_SHADER_UYVY:
        f_strings[0] = __SH_FRAGMENT(UYVY);
        break;
    case TEX_SHADER_YV12:
        f_strings[0] = __SH_FRAGMENT(YV12);
        break;
    case TEX_SHADER_YUYV:
        f_strings[0] = __SH_FRAGMENT(YUYV);
        break;
    default:
        f_strings[0] = __SH_FRAGMENT(EXT);
    }

    /* ...dump programs created */
    TRACE(DEBUG, _b("type=%d:\n\nVertex shader:\n%s\nFragment shader:\n%s"), type, v_strings[0], f_strings[0]);

    /* ...fill in shader descriptor parameters */
    desc.v_src = (const char * const *)v_strings;
    desc.v_src_num = 1;
    desc.f_src = (const char * const *)f_strings;
    desc.f_src_num = 1;

    desc.attr = __tex_shader_attributes_id;
    desc.attr_num = __SHADER_ATTRIBUTES_NUM;
    desc.uni = __tex_shader_uniforms_id;
    desc.uni_num = __SHADER_UNIFORMS_NUM;

    /* ...compile shader */
    return shader_create(&desc);
}

/**
 * @brief   Return shader for given texture format
 *
 * @param   texture[in]     Texture handle
 *
 * @return                  Shader pointer, or NULL in case of error
 */
static shader_data_t * texture_get_shader(texture_data_t *texture)
{
    static shader_data_t * __shaders[TEX_SHADER_NUMBER];

    int         idx;

    /* ...select shader index */
    if (texture->image != NULL)
    {
        idx = TEX_SHADER_EXT;
    }
    else if (texture->format == GST_VIDEO_FORMAT_RGBA || texture->format == GST_VIDEO_FORMAT_RGB)
    {
        idx = TEX_SHADER_RGB;
    }
    else if (texture->format == GST_VIDEO_FORMAT_BGRA)
    {
        idx = TEX_SHADER_BGR;
    }
    else if (texture->format == GST_VIDEO_FORMAT_I420)
    {
        idx = TEX_SHADER_I420;
    }
    else if (texture->format == GST_VIDEO_FORMAT_NV12)
    {
        idx = TEX_SHADER_NV12;
    }
    else if (texture->format == GST_VIDEO_FORMAT_UYVY)
    {
        idx = TEX_SHADER_UYVY;
    }
    else if (texture->format == GST_VIDEO_FORMAT_YV12)
    {
        idx = TEX_SHADER_YV12;
    }
    else if (texture->format == GST_VIDEO_FORMAT_YUY2)
    {
        idx = TEX_SHADER_YUYV;
    }
    else
    {
        TRACE(ERROR, _x("unknown texture format: %d"), texture->format);
        idx = TEX_SHADER_EXT;
    }

    shader_data_t  *shader = __shaders[idx];

    if (shader == NULL)
    {
        /* ...shader not found; create new one */
        CHK_ERR(shader = tex_shader_compile(idx), NULL);

        /* ...cache new shader */
        __shaders[idx] = shader;

        TRACE(INIT, _b("shader %d created: %u"), idx, shader_program(shader));
    }

    return shader;
}

#define U(id)       sh->uniform[__TEX_SHADER_UNIFORM_##id]
#define A(id)       (__TEX_SHADER_ATTRIBUTE_##id)

/**
 * @brief   Draw texture in given view-port
 *
 * @param   texture[in]         Texture data
 * @param   view[in]            Viewport parameters (NULL for full-screen)
 * @param   crop[in]            Texture crop parameters (NULL for no-crop)
 * @param   alpha[in]           Alpha value to use
 */
void texture_draw(texture_data_t *texture, texture_view_t *view, texture_crop_t *crop, GLfloat alpha)
{
    display_data_t     *display = &__display;
    shader_data_t      *sh = texture_get_shader(texture);

    /* ...identity matrix - not needed really */
    static const GLfloat    identity[4 * 4] = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1,
    };

    /* ...vertices coordinates */
    static const GLfloat    verts[] = {
        -1,  -1,
        1,  -1,
        -1,  1,
        -1,  1,
        1,  -1,
        1,  1,
    };

    /* ...triangle coordinates */
    static const GLfloat    texcoords[] = {
        0,  1,
        1,  1,
        0,  0,
        0,  0,
        1,  1,
        1,  0,
    };

    if (view)
    {
        int         i;
        GLfloat    *p = *view;

        for (i = 0; i < 12; i += 2, p += 2)
        {
            TRACE(0, _b("view[%d] = (%.2f, %.2f)"), i / 2, p[0], p[1]);
        }
    }

    if (crop)
    {
        int         i;
        GLfloat    *p = *crop;

        for (i = 0; i < 12; i += 2, p += 2)
        {
            TRACE(0, _b("crop[%d] = (%.2f, %.2f)"), i / 2, p[0], p[1]);
        }
    }

    /* ...set shader program */
    glUseProgram(sh->program);

    /* ...bind texture uniforms (up to 4) */
    //glUniform1iv(U(tex), 4, (GLint [4]){ 0, 1, 2, 3 });     GLCHECK();
    glUniform1iv(U(tex), 1, (GLint [4]){ 0, 1, 2, 3 });     GLCHECK();

    /* ...bind alpha uniform */
    glUniform1f(U(alpha), alpha);

    /* ...bind textures (up to 4) */
    if (texture->image)
    {
        /* ...assign the only external image */
        glActiveTexture(GL_TEXTURE0);   GLCHECK();
        glBindTexture(GL_TEXTURE_EXTERNAL_OES, texture->tex[0]);    GLCHECK();
    }
    else
    {
        /* ...assign auxiliary textures */
        glActiveTexture(GL_TEXTURE0);                       GLCHECK();
        glBindTexture(GL_TEXTURE_2D, texture->tex[0]);      GLCHECK();
        glActiveTexture(GL_TEXTURE1);                       GLCHECK();
        glBindTexture(GL_TEXTURE_2D, texture->tex[1]);      GLCHECK();
        glActiveTexture(GL_TEXTURE2);                       GLCHECK();
        glBindTexture(GL_TEXTURE_2D, texture->tex[2]);      GLCHECK();
        glActiveTexture(GL_TEXTURE3);                       GLCHECK();
        glBindTexture(GL_TEXTURE_2D, texture->tex[3]);      GLCHECK();
    }

    /* ...make sure no VBO binding set */
    glBindBuffer(GL_ARRAY_BUFFER, 0);    GLCHECK();

    /* ...set vertices array attribute ("position") */
    glVertexAttribPointer(A(XY), 2, GL_FLOAT, GL_FALSE, 0, (view ? *view : verts));
    glEnableVertexAttribArray(A(XY));

    /* ...set vertex coordinates attribute ("texcoord") */
    glVertexAttribPointer(A(UV), 2, GL_FLOAT, GL_FALSE, 0, (crop ? *crop : texcoords));
    glEnableVertexAttribArray(A(UV));

    /* ...render triangles on the surface */
    glDrawArrays(GL_TRIANGLES, 0, 6);   GLCHECK();

    /* ...disable generic attributes arrays */
    glDisableVertexAttribArray(A(XY));
    glDisableVertexAttribArray(A(UV));

    /* ...unbind texture */
    glBindTexture((texture->image ? GL_TEXTURE_EXTERNAL_OES : GL_TEXTURE_2D), 0);

    /* ...reset current program */
    glUseProgram(0);
}

#undef U
#undef A


/*******************************************************************************
 * Synchronization objects support
 ******************************************************************************/

/**
 * @brief   Create synchronization object
 *
 * @return                  Synchronization object handle, or NULL
 */
sync_data_t * sync_create(void)
{
    display_data_t     *display = &__display;
    EGLDisplay          dpy = display->egl.dpy;
    EGLContext          ctx = eglGetCurrentContext();
    EGLSyncKHR          sync;

    /* ...must be called from valid context */
    BUG(ctx == EGL_NO_CONTEXT, _x("invalid context"));

    /* ...acquire rendering context as needed (save current in a scratch memory) */
    //(ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...create fence sync object */
    if ((sync = eglCreateSyncKHR(dpy, EGL_SYNC_FENCE, NULL)) == EGL_NO_SYNC)
    {
        TRACE(ERROR, _x("failed to create sync: %X"), eglGetError());
        errno = EBADFD;
    }

    /* ...release shared display context if needed */
    //(ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    return (sync_data_t *)sync;
}

/**
 * @brief   Wait for a synchronization operation completion
 *
 * @param   sync[in]        Synchronization object handle
 * @param   timeout[in]     Timeout value, in nsec
 *
 * @return                  Positive if sync is complete, zero if timeout expires
 */
int sync_wait(sync_data_t *sync, uint64_t timeout)
{
    display_data_t     *display = &__display;
    EGLDisplay          dpy = display->egl.dpy;
    EGLContext          ctx = eglGetCurrentContext();
    EGLint              r;

    /* ...acquire rendering context as needed (save current in a scratch memory) */
    //(ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...wait for a sync */
    r = eglClientWaitSyncKHR(dpy, (EGLSyncKHR)sync,  EGL_SYNC_FLUSH_COMMANDS_BIT, (EGLTime)timeout);

    /* ...release shared display context if needed */
    //(ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    return (r == EGL_CONDITION_SATISFIED ? 1 : (r == EGL_TIMEOUT_EXPIRED ? 0 : -1));
}

/**
 * @brief   Destroy sync object
 *
 * @param   sync[in]        Synchronization object handle
 */
void sync_destroy(sync_data_t *sync)
{
    display_data_t     *display = &__display;
    EGLDisplay          dpy = display->egl.dpy;
    EGLContext          ctx = eglGetCurrentContext();
    EGLint              r;

    /* ...acquire rendering context as needed (save current in a scratch memory) */
    //(ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...destroy synchronization object */
    eglDestroySyncKHR(dpy, (EGLSyncKHR)sync);

    /* ...release shared display context if needed */
    //(ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);
}

/*******************************************************************************
 * Framebuffer support
 ******************************************************************************/

/* ...internal structure definition */
struct fbo_data
{
    /* ...GL framebuffer / renderbuffer objects */
    GLuint          fbo, rbo;

    /* ...depth-buffer specification (need that? - tbd) */
    int             depth_width, depth_height;

    /* ...current EGL context (scratch data) */
    EGLContext      ctx;
};

/* ...create pixmap surface for off-screen rendering */
fbo_data_t * fbo_create(int w, int h)
{
    display_data_t     *display = &__display;
    EGLContext          ctx = eglGetCurrentContext();
    fbo_data_t         *fbo;
    GLint               samples = 0;

    /* ...allocate data handle */
    CHK_ERR(fbo = malloc(sizeof(*fbo)), (errno = ENOMEM, NULL));

    /* ...save depth-buffer specification */
    fbo->depth_width = w, fbo->depth_height = h;

    /* ...clear context */
    fbo->ctx = EGL_NO_CONTEXT;

    /* ...as framebuffer objects are not shareable, we shall always use display context */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...get maximal number of samples in a multisample texture */
    glGetIntegerv(GL_MAX_SAMPLES, &samples);

    /* ...create framebuffer/renderbuffer objects in current EGL context */
    glGenFramebuffers(1, &fbo->fbo);    GLCHECK();
    glBindFramebuffer(GL_FRAMEBUFFER, fbo->fbo);    GLCHECK();

    glGenRenderbuffers(1, &fbo->rbo);   GLCHECK();
    glBindRenderbuffer(GL_RENDERBUFFER, fbo->rbo);  GLCHECK();

    /* ...specify depth buffer parameters */
    glRenderbufferStorageMultisampleEXT(GL_RENDERBUFFER, samples, GL_DEPTH_COMPONENT16, w, h); GLCHECK();

    TRACE(1, _b("attach %d-samples renderbuffer"), samples);

    /* ...attach depth buffer to the framebuffer */
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, fbo->rbo); GLCHECK();

    /* ...restore default framebuffer/renderbuffer */
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);

    TRACE(1, _b("framebuffer #%u (%p) created: (ctx=%p) (depth-buffer: %d*%d, samples: %d)"), fbo->fbo, fbo, eglGetCurrentContext(), w, h, samples);

    /* ...release context as needed */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    return fbo;
}

/* ...create pixmap surface for off-screen rendering */
fbo_data_t * fbo_create_ext(int w, int h, int depth, int msaa)
{
    display_data_t     *display = &__display;
    EGLContext          ctx = eglGetCurrentContext();
    fbo_data_t         *fbo;
    GLint               samples = 0;

    /* ...allocate data handle */
    CHK_ERR(fbo = malloc(sizeof(*fbo)), (errno = ENOMEM, NULL));

    /* ...clear context */
    fbo->ctx = EGL_NO_CONTEXT;

    /* ...as framebuffer objects are not shareable, we shall always use display context */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...get maximal number of samples in a multisample texture */
    (msaa ? glGetIntegerv(GL_MAX_SAMPLES, &samples) : 0);

    /* ...create framebuffer/renderbuffer objects in current EGL context */
    glGenFramebuffers(1, &fbo->fbo);    GLCHECK();
    glBindFramebuffer(GL_FRAMEBUFFER, fbo->fbo);    GLCHECK();

    if (depth)
    {
        glGenRenderbuffers(1, &fbo->rbo);   GLCHECK();
        glBindRenderbuffer(GL_RENDERBUFFER, fbo->rbo);  GLCHECK();

        /* ...specify depth buffer parameters */
        glRenderbufferStorageMultisampleEXT(GL_RENDERBUFFER, samples, GL_DEPTH_COMPONENT16, w, h); GLCHECK();

        TRACE(DEBUG, _b("attach %d-samples renderbuffer"), samples);

        /* ...attach depth buffer to the framebuffer */
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, fbo->rbo); GLCHECK();

        /* ...restore default renderbuffer */
        glBindRenderbuffer(GL_RENDERBUFFER, 0);
    }
    else
    {
        fbo->rbo = 0;
    }

    /* ...restore default framebuffer */
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    TRACE(INIT, _b("framebuffer #%u (%p) created: (ctx=%p) (depth-buffer: %d*%d, samples: %d)"), fbo->fbo, fbo, eglGetCurrentContext(), w, h, samples);

    /* ...release context as needed */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    return fbo;
}

/* ...acquire display context for rendering into texture */
int fbo_get(fbo_data_t *fbo)
{
    display_data_t     *display = &__display;
    EGLContext          ctx = eglGetCurrentContext();
    GLenum              err;

    /* ...acquire rendering context as needed (save current in a scratch memory) */
    ((fbo->ctx = ctx) == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...bind framebuffer/renderbuffer to current EGL context */
    glBindFramebuffer(GL_FRAMEBUFFER, fbo->fbo);

    /* ...make sure everything goes well */
    if ((err = glGetError()) != GL_NO_ERROR)
    {
        TRACE(ERROR, _x("failed to acquire framebuffer: %x"), err);

        /* ...release context as needed */
        (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

        return -(errno = EBADFD);
    }
    else
    {
        TRACE(DEBUG, _b("framebuffer %p acquired (%d,%d)"), fbo, fbo->fbo, fbo->rbo);

        return 0;
    }
}

/* ...release framebuffer from current context (triggers rendering as required) */
void fbo_put(fbo_data_t *fbo)
{
    display_data_t     *display = &__display;
    EGLContext          ctx = eglGetCurrentContext();
    GLenum              err;

    /* ...make sure we have active GL context */
    BUG(ctx == EGL_NO_CONTEXT, _x("invalid context: %p"), ctx);

    if (fbo->rbo != 0)
    {
        /* ...discard framebuffer */
        glDiscardFramebufferEXT(GL_FRAMEBUFFER, 1, (GLenum[1]){GL_DEPTH_ATTACHMENT});     GLCHECK();
    }

    /* ...unbind framebuffer/renderbuffer objects */
    glBindFramebuffer(GL_FRAMEBUFFER, 0);   GLCHECK();

    /* ...release shared display context if needed */
    (fbo->ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    TRACE(DEBUG, _b("framebuffer %p released"), fbo);
}

/* ...attach texture to the framebuffer as a color-attachment #n  */
int fbo_attach_texture(fbo_data_t *fbo, texture_data_t *texture, int msaa, int n)
{
    EGLContext      ctx = eglGetCurrentContext();
    GLenum          status;
    GLint           samples = 0;

    /* ...make sure we have active EGL context */
    BUG(ctx == EGL_NO_CONTEXT, _x("invalid context"));

    /* ...make sure we are attaching GL-RGBA texture? - tbd */
	(msaa ? glGetIntegerv(GL_MAX_SAMPLES, &samples) : 0);

    TRACE(DEBUG, _b("attach %d-samples texture: %u [%d*%d, %d]"), samples, texture->tex[0], texture->w, texture->h, texture->format);

    /* ...set texture as colour attachement #n */
    glFramebufferTexture2DMultisampleEXT(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + n, GL_TEXTURE_2D, texture->tex[0], 0, samples); GLCHECK();

    /* ...check the status of the framebuffer */
    if ((status = glCheckFramebufferStatus(GL_FRAMEBUFFER)) != GL_FRAMEBUFFER_COMPLETE)
    {
        TRACE(ERROR, _x("framebuffer %p state error: %x"), fbo, status);
        return -(errno = EINVAL);
    }
    else
    {
        TRACE(DEBUG, _b("fbo[%p]: texture[#%u(%p)] attached as #%d"), fbo, texture->tex[0], texture, n);
        return 0;
    }
}

void fbo_destroy(fbo_data_t *fbo)
{
    display_data_t     *display = &__display;
    EGLContext          ctx = eglGetCurrentContext();

    /* ...get shared display context as needed */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...destroy renderbuffer object */
    (fbo->rbo != 0 ? glDeleteRenderbuffers(1, &fbo->rbo) : 0);

    /* ...destroy framebuffer object */
    glDeleteFramebuffers(1, &fbo->fbo);

    /* ...release shared display context */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    /* ...free data structure */
    free(fbo);

    TRACE(INFO, _b("fbo[%p] destroyed"), fbo);
}

/*******************************************************************************
 * VBO support
 ******************************************************************************/

/**
 * @brief External vertex-buffer object data
 */
typedef struct vbo_data
{
    /**> Buffer array object id */
    GLuint              vbo;

    /**> Individual vertex element size */
    uint32_t            size;

    /**> Number of elements in buffer (uploaded) */
    uint32_t            number;

    /**> Allocated storage size in elements (available) */
    uint32_t            avail;

    /**> Mapped vertex-buffer-objects array */
    void               *map;

    /**> Scratch context data */
    EGLContext         *ctx;

    /**> Thread that caused mapping (still need that? - tbd) */
    pthread_t           mapped;

}   vbo_data_t;

/**
 * @brief   Create VBO object in shared display
 *
 * @param   size[in]        VBO element size
 * @param   number[in]      Number of elements to store
 * @param   p[in]           Data to upload into created buffer, or NULL
 *
 * @return                  VBO buffer handle, or NULL
 */
vbo_data_t * vbo_create(u32 size, u32 number, void *p)
{
    display_data_t     *display = &__display;
    EGLContext         *ctx = eglGetCurrentContext();
    vbo_data_t         *vbo;
    GLenum              err;

    /* ...allocate VBO handle */
    CHK_ERR(vbo = calloc(1, sizeof(*vbo)), (errno = ENOMEM, NULL));

    /* ...get display shared context */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...generate buffer-object */
    glGenBuffers(1, &vbo->vbo); GLCHECK();
    glBindBuffer(GL_ARRAY_BUFFER, vbo->vbo);    GLCHECK();
    glBufferData(GL_ARRAY_BUFFER, size * number, p, GL_STREAM_DRAW);
    if ((err = glGetError()) != GL_NO_ERROR)
    {
        TRACE(ERROR, _x("failed to allocate VBO %d*%d: %X"), size, number, err);
        goto error;
    }

    vbo->size = size;
    vbo->avail = number;
    vbo->number = (p != NULL ? number : 0);
    vbo->map = NULL;
    vbo->ctx = EGL_NO_CONTEXT;

    TRACE(INIT, _b("VBO-buffer #%u created (%d*%d)"), vbo->vbo, size, number);

    goto out;

error:
    /* ...delete pixel-buffer */
    glDeleteBuffers(1, &vbo->vbo);

    /* ...delete VBO data */
    free(vbo), vbo = NULL;

out:
    /* ...clear bindings */
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    /* ...release context as needed */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    return vbo;
}

/**
 * @brief   Reallocate VBO buffer. Buffer must be currently mapped
 *
 * @param   vbo[in]         VBO data handle
 * @param   p[in]           Current buffer cursor
 * @param   number[in]      New number of elements
 *
 * @return                  Updated position of cursor following remapping, or NULL
 */
void * vbo_realloc(vbo_data_t *vbo, void *p, u32 number)
{
    ptrdiff_t   offset = (ptrdiff_t)(p - vbo->map);
    GLuint      id;
    GLenum      err;

    TRACE(DEBUG, _b("realloc: map=%p, p=%p, offset=%u"), vbo->map, p, (u32)offset);

    /* ...make sure we have active GL context */
    BUG(eglGetCurrentContext() == EGL_NO_CONTEXT, _x("invalid context"));

    /* ...make sure we have proper binding */
    //BUG(({GLint id; glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &id); id != vbo->vbo;}), _x("invalid binding"));

    /* ...unmap current buffer and bind it to read-copy target */
    glBindBuffer(GL_ARRAY_BUFFER, vbo->vbo);     GLCHECK();
    glUnmapBuffer(GL_ARRAY_BUFFER);     GLCHECK();
    glBindBuffer(GL_COPY_READ_BUFFER, vbo->vbo);    GLCHECK();

    /* ...generate new buffer handle */
    glGenBuffers(1, &id);      GLCHECK();
    glBindBuffer(GL_ARRAY_BUFFER, id);    GLCHECK();
    glBufferData(GL_ARRAY_BUFFER, vbo->size * number, NULL, GL_DYNAMIC_DRAW);
    if ((err = glGetError()) != GL_NO_ERROR)
    {
        TRACE(ERROR, _x("failed to allocate aux-VBO %d*%d: %X"), vbo->size, number, err);
        goto error_buf;
    }

    /* ...copy data up to current cursor into new buffer */
    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_ARRAY_BUFFER, 0, 0, offset);
    if ((err = glGetError()) != GL_NO_ERROR)
    {
        TRACE(ERROR, _x("failed to copy %u bytes from #%u to %u: %X"), (u32)offset, vbo->vbo, id, err);
        goto error_buf;
    }

    /* ...remap new buffer */
    vbo->map = glMapBufferRange(GL_ARRAY_BUFFER, 0, vbo->size * number, GL_MAP_WRITE_BIT | GL_MAP_READ_BIT);
    if ((err = glGetError()) != GL_NO_ERROR)
    {
        TRACE(ERROR, _x("failed to remap VBO buffer #%d (%d*%d): %X"), id, vbo->size, number, err);
        goto error_buf;
    }

    TRACE(INFO, _b("buffer #%u (%d*%d) remapped to #%u (%d*%d): %p -> %p (copied %u bytes)"),
          vbo->vbo, vbo->size, vbo->number, id, vbo->size, number, p, vbo->map + offset, (u32)offset);

    /* ...destroy old VBO */
    glBindBuffer(GL_COPY_READ_BUFFER, 0);   GLCHECK();
    glDeleteBuffers(1, &vbo->vbo);      GLCHECK();

    /* ...set new buffer parameters and cursor position */
    vbo->vbo = id;
    vbo->avail = number;
    p = vbo->map + offset;

    return p;

error_buf:
    /* ...destroy new VBO buffer */
    glDeleteBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    return NULL;
}

/**
 * @brief   Get writable data pointer to the VBO
 *
 * @param   vbo[in]         VBO data handle
 *
 * @return                  User-accessible pointer
 */
void * vbo_map(vbo_data_t *vbo)
{
    display_data_t     *display = &__display;
    EGLContext          ctx = eglGetCurrentContext();
    void               *map;
    GLenum              err;

    BUG(vbo->mapped, _x("invalid map: %u"), vbo->mapped);
    vbo->mapped = pthread_self();

    /* ...acquire rendering context as needed (save current in a scratch memory) */
    ((vbo->ctx = ctx) == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...bind buffer object to current EGL context */
    glBindBuffer(GL_ARRAY_BUFFER, vbo->vbo);    GLCHECK();

    /* ...map buffer to user-space (read/write permissions) */
    vbo->map = map = glMapBufferRange(GL_ARRAY_BUFFER, 0, vbo->size * vbo->avail, GL_MAP_WRITE_BIT | GL_MAP_READ_BIT);

    if ((err = glGetError()) != GL_NO_ERROR)
    {
        TRACE(ERROR, _x("failed to map vbo buffer (%d*%d): %X (%p)"), vbo->size, vbo->avail, err, map);
        BUG(1, _x("break"));

        return NULL;
    }
    else
    {
        TRACE(DEBUG, _b("mapped vbo #%d: %d*%d, map=%p, ctx=%p"), vbo->vbo, vbo->size, vbo->avail, map, vbo->ctx);
        return map;
    }
}

/**
 * @brief   Unmap buffer data
 *
 * @param   vbo[in]     Buffer object handle
 */
void vbo_unmap(vbo_data_t *vbo)
{
    display_data_t     *display = &__display;
    EGLContext          ctx = eglGetCurrentContext();
    int                 k;

    /* ...make sure we have active GL context */
    BUG(ctx == EGL_NO_CONTEXT, _x("invalid context: %p"), ctx);

    /* ...unmap buffer array */
    glBindBuffer(GL_ARRAY_BUFFER, vbo->vbo);     GLCHECK();
    glUnmapBuffer(GL_ARRAY_BUFFER);      GLCHECK();

    /* ...clear binding */
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    TRACE(DEBUG, _b("vbo #%u unmapped (ctx=%p)"), vbo->vbo, vbo->ctx);

    /* ...release shared display context if needed */
    (vbo->ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);
    vbo->mapped = 0;
}

/**
 * @brief   Upload VBO buffer
 *
 * @param   vbo[in]         VBO handle
 * @param   p[in]           Buffer data
 * @param   n[in]           Number of entries contained in buffer
 *
 * @return                  Negative on failure
 */
int vbo_upload(vbo_data_t *vbo, void *p, u32 n)
{
    display_data_t     *display = &__display;
    EGLContext         *ctx = eglGetCurrentContext();
    GLenum              err;
    int                 r;

    /* ...get display shared context */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...bind array buffer */
    glBindBuffer(GL_ARRAY_BUFFER, vbo->vbo);    GLCHECK();

    /* check if buffer size is sufficient for holding the data */
    if (vbo->avail && vbo->avail >= n)
    {
        /* ...upload data; no reallocation is needed */
        glBufferSubData(GL_ARRAY_BUFFER, 0, vbo->size * n, p);
    }
    else
    {
        /* ...delete previous data storage and recreate new buffer */
        glBufferData(GL_ARRAY_BUFFER, vbo->size * n, p, GL_STREAM_DRAW);

        /* ...update internal buffer storage size */
        vbo->avail = n;
    }

    /* ...check if operation is sucessful */
    if ((err = glGetError()) != GL_NO_ERROR)
    {
        TRACE(ERROR, _x("failed to upload VBO %d*%d with %p: %X"), vbo->size, n, p, err);
        r = -(errno = ENOMEM);
    }
    else
    {
        /* ...set total number of uploaded items */
        vbo->number = n;

        /* ...indicate operation is successful */
        r = 0;
    }

    /* ...clear bindings */
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    /* ...release context as needed */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    return r;
}

/**
 * @brief   Return GL VBO buffer object
 *
 * @param   vbo[in]         VBO handle
 *
 * @return                  GL identifier of VBO
 */
GLuint vbo_get_id(vbo_data_t *vbo)
{
    return vbo->vbo;
}

/**
 * @brief   Return GL VBO buffer size
 *
 * @param   vbo[in]         VBO handle
 *
 * @return                  Number of entries in a buffer
 */
uint32_t vbo_get_num(vbo_data_t *vbo)
{
    return vbo->number;
}

/**
 * @brief   Destroy GL VBO buffer-object
 *
 * @param   vbo[in]         VBO handle
 */
void vbo_destroy(vbo_data_t *vbo)
{
    display_data_t     *display = &__display;
    EGLContext         *ctx = eglGetCurrentContext();

    /* ...get display shared context */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_get(display) : 0);

    /* ...delete buffer-object */
    glDeleteBuffers(1, &vbo->vbo);

    /* ...allocate memory (do not pass any data yet) */
    TRACE(INIT, _b("VBO[%u] object destroyed"), vbo->vbo);

    /* ...release display context */
    (ctx == EGL_NO_CONTEXT ? display_egl_ctx_put(display) : 0);

    /* ...destroy VBO handle */
    free(vbo);
}

/*******************************************************************************
 * Auxiliary frame-rate calculation functions
 ******************************************************************************/

/* ...reset FPS calculator */
void window_frame_rate_reset(window_data_t *window)
{
    /* ...reset accumulator and timestamp */
    window->fps_acc = 0, window->fps_ts = 0;
}

/* ...update FPS calculator */
float window_frame_rate_update(window_data_t *window)
{
    u32     ts_0, ts_1, delta, acc;
    float   fps;

    /* ...get current timestamp for a window frame-rate calculation */
    delta = (ts_1 = __get_time_usec()) - (ts_0 = window->fps_ts);

    /* ...check if accumulator is initialized */
    if ((acc = window->fps_acc) == 0)
    {
        if (ts_0 != 0)
        {
            /* ...initialize accumulator */
            acc = delta << 4;
        }
    }
    else
    {
        /* ...accumulator is setup already; do exponential averaging */
        acc += delta - ((acc + 8) >> 4);
    }

    /* ...calculate current frame-rate */
    if ((fps = (acc ? 1e+06 / ((acc + 8) >> 4) : 0)) != 0)
    {
        TRACE(DEBUG, _b("delta: %u, acc: %u, fps: %f"), delta, acc, fps);
    }

    /* ...update timestamp and accumulator values */
    window->fps_acc = acc, window->fps_ts = ts_1;

    return fps;
}
