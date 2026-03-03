/*******************************************************************************
 * event.h
 *
 * Input events support
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

#ifndef __PLATFORM_EVENT_H
#define __PLATFORM_EVENT_H

/*******************************************************************************
 * Includes
 ******************************************************************************/


/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/* ...generic event type */
typedef enum widget_event_type
{
    WIDGET_EVENT_NONE,
    WIDGET_EVENT_KEY,
    WIDGET_EVENT_MOUSE,
    WIDGET_EVENT_TOUCH,
    WIDGET_EVENT_JOYSTICK,
    WIDGET_EVENT_FD,
    WIDGET_EVENT_GESTURE,
    WIDGET_EVENT_NUMBER,

}   widget_event_type_t;

/* ...macro for event type construction */
#define __WIDGET_EVENT_TYPE(type, subtype)  ((type) | ((subtype) << 8))
#define WIDGET_EVENT_TYPE(type)             ((type) & 0xFF)
#define WIDGET_EVENT_SUBTYPE(type)          ((type) >> 8)

/* ...keyboard event types */
#define __WIDGET_EVENT_KEY(subtype)     __WIDGET_EVENT_TYPE(WIDGET_EVENT_KEY, subtype)
#define WIDGET_EVENT_KEY_ENTER          __WIDGET_EVENT_KEY(0)
#define WIDGET_EVENT_KEY_PRESS          __WIDGET_EVENT_KEY(1)
#define WIDGET_EVENT_KEY_MODS           __WIDGET_EVENT_KEY(2)
#define WIDGET_EVENT_KEY_LEAVE          __WIDGET_EVENT_KEY(3)

/* ...keyboard event descriptor */
typedef struct widget_key_event
{
    /* ...generic event type */
    uint32_t             type;

    /* ...subtype-specific structures */
    union {
        /* ...key pressing */
        struct {
            uint32_t         code;
            uint32_t         state;
        };

        /* ...modifiers state change */
        struct {
            uint32_t         mods_on;
            uint32_t         mods_off;
            uint32_t         mods_locked;
        };
    };

}   widget_key_event_t;

/*******************************************************************************
 * Touchscreen events
 ******************************************************************************/

/* ...event subtypes */
#define __WIDGET_EVENT_TOUCH(subtype)   __WIDGET_EVENT_TYPE(WIDGET_EVENT_TOUCH, subtype)
#define WIDGET_EVENT_TOUCH_ENTER        __WIDGET_EVENT_TOUCH(0)
#define WIDGET_EVENT_TOUCH_DOWN         __WIDGET_EVENT_TOUCH(1)
#define WIDGET_EVENT_TOUCH_MOVE         __WIDGET_EVENT_TOUCH(2)
#define WIDGET_EVENT_TOUCH_UP           __WIDGET_EVENT_TOUCH(3)
#define WIDGET_EVENT_TOUCH_LEAVE        __WIDGET_EVENT_TOUCH(4)

/* ...event handle definition */
typedef struct widget_touch_event
{
    /* ...generic event type */
    uint32_t             type;

    /* ...location of the point */
    int32_t             x, y;

    /* ...identifier of the touch event */
    int32_t             id;

}   widget_touch_event_t;

/*******************************************************************************
 * Touchscreen events
 ******************************************************************************/

/* ...event subtypes */
#define __WIDGET_EVENT_GESTURE(subtype) __WIDGET_EVENT_TYPE(WIDGET_EVENT_GESTURE, subtype)
#define WIDGET_EVENT_GESTURE_TAP        __WIDGET_EVENT_GESTURE(0)
#define WIDGET_EVENT_GESTURE_PITCH      __WIDGET_EVENT_GESTURE(1)
#define WIDGET_EVENT_GESTURE_SWIPE      __WIDGET_EVENT_GESTURE(2)

/* ...event handle definition */
typedef struct widget_gesture_event
{
    /* ...generic event type */
    uint32_t            type;

    /* ...gesture-specific data */
    void               *gesture;

    /* ...identifier of the asynchronous event */
    int32_t             async;

}   widget_gesture_event_t;

/*******************************************************************************
 * Mouse events
 ******************************************************************************/

/* ...event subtypes */
#define __WIDGET_EVENT_MOUSE(subtype)   __WIDGET_EVENT_TYPE(WIDGET_EVENT_MOUSE, subtype)
#define WIDGET_EVENT_MOUSE_ENTER        __WIDGET_EVENT_MOUSE(0)
#define WIDGET_EVENT_MOUSE_MOVE         __WIDGET_EVENT_MOUSE(1)
#define WIDGET_EVENT_MOUSE_BUTTON       __WIDGET_EVENT_MOUSE(2)
#define WIDGET_EVENT_MOUSE_AXIS         __WIDGET_EVENT_MOUSE(3)
#define WIDGET_EVENT_MOUSE_LEAVE        __WIDGET_EVENT_MOUSE(4)

/* ...mouse input event */
typedef struct widget_mouse_event
{
    /* ...generic event type */
    uint32_t             type;

    /* ...subtype-specific events */
    union {
        /* ...point location / button status */
        struct {
            int32_t         x;
            int32_t         y;
            union {
                struct {
                    uint32_t         button;
                    uint32_t         state;
                };
                struct {
                    uint32_t         axis;
                    int32_t         value;
                };
            };        
        };
    };

}   widget_mouse_event_t;

/* ...joystic input event */
typedef struct widget_joystick_event
{
    /* ...generic event type */
    uint32_t                 type;

    /* ...joystick event structure pointer */
    struct js_event    *e;
    
}   widget_joystick_event_t;

/* ...generic file-descriptor event */
typedef struct widget_fd_event
{
    /* ...generic event type */
    uint32_t             type;

    /* ...file-descriptor */
    int32_t             fd;

    /* ...private data associated with a descriptor */
    void           *priv;

}   widget_fd_event_t;

/* ...widget event definition */
typedef union widget_event
{
    /* ...generic event type */
    uint32_t                    type;

    /* ...keyboard event */
    widget_key_event_t          key;

    /* ...mouse event */
    widget_mouse_event_t        mouse;

    /* ...touchscreen event */
    widget_touch_event_t        touch;

    /* ...gesture event */
    widget_gesture_event_t      gesture;

    /* ...joystick event */
    widget_joystick_event_t     js;

    /* ...generic unix file-descriptor event */
    widget_fd_event_t           fd;

}   widget_event_t;

#endif  /* __PLATFORM_EVENT_H */
