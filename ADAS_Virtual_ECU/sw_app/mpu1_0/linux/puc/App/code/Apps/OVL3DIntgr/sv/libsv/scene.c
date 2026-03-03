/*******************************************************************************
 * scene.c
 *
 * Scene transformations for user input
 *
 * Copyright (c) 2021 Cogent Embedded Inc.
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

#define MODULE_TAG                      SCENE

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "scene.h"
#include "mesh-gen.h"
#include "math-helpers.h"

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Zoom 3D scene into specified point
 *
 * @param   stv[in]         STV-view configuration
 * @param   cfg[in]         Scene parameters update configuration
 * @param   x[in]           X coordinate of the zoom-point, pixels
 * @param   y[in]           Y coordinate of the zoom-point, pixels
 * @param   scale[in]       Zooming scale
 *
 * @return                  Non-zero if view update is required
 */
static int scene_stv_zoom(cfg_stv_mesh_t *stv, cfg_scene_params_t *cfg, int32_t x, int32_t y, float32_t scale)
{
    int32_t    *dst = stv->base.dst;
    int         update = 0;

    __vec2  uv = {
        2.0f * (float32_t)(x - dst[0]) / (float32_t)(dst[2] - dst[0]) - 1.0f,
        2.0f * (float32_t)(y - dst[1]) / (float32_t)(dst[3] - dst[1]) - 1.0f,
    };

    __vec3  xyz;

    /* ...zoom-in/out event */
    if (mesh_stv_map_uv(stv, uv, xyz) > 0.0f)
    {
        float32_t   mix = scale - 1.0f;

        /* ...adjust the current look-at point position and virtual camera position */
        __vec3      diff, la, q;
        __vec3_sub(xyz, stv->look_at, diff);
        __vec3_mac(stv->look_at, diff, mix, la);
        __vec3_sub(xyz, stv->position, q);

        /* ...calculate movement of virtual camera */
        __vec2      xy = { q[0] / q[2], q[1] / q[2] };
        diff[2] = -mix * (stv->position[2] - la[2]);
        diff[0] = xy[0] * diff[2];
        diff[1] = xy[1] * diff[2];

        __vec3      p;
        __vec3_add(stv->position, diff, p);

        /* ...calculate distance of virtual camera position from viewing point */
        __vec3_sub(p, la, diff);

        TRACE(0, _b("mix: %f, la: %f,%f,%f, p: %f,%f,%f, d:%f,%f,%f"), mix, la[0], la[1], la[2], p[0], p[1], p[2], diff[0], diff[1], diff[2]);

        float32_t   d = __vec3_length(diff);

        /* ...check if the distance from viewing point is within the limits - tbd - should be configurable*/
        if (d >= cfg->zoom_min_length && d <= cfg->zoom_max_length)
        {
            /* ...accept the point */
            memcpy(stv->look_at, la, sizeof(la));
            memcpy(stv->position, p, sizeof(p));

            TRACE(0, _b("look-at: %f,%f,%f, position: %f,%f,%f, d: %f"), la[0], la[1], la[2], p[0], p[1], p[2], d);

            /* ...force update of the mesh/car */
            update = 1;
        }
        else
        {
            TRACE(0, _b("zoom: ignore (d=%f)"), d);
        }
    }

    return update;
}

/**
 * @brief   Rotate STV-scene around current look-at position
 *
 * @param   stv[in]         STV-view configuration
 * @param   dx[in]          X coordinate delta, pixels
 * @param   dy[in]          Y coordinate delta, pixels
 *
 * @return                  Non-zero if view update is required
 */
static int scene_stv_rotate(cfg_stv_mesh_t *stv, cfg_scene_params_t *cfg, int32_t dx, int32_t dy)
{
    int         update = 0;

    if ((dx | dy) != 0)
    {
        float32_t   pitch, yaw;

        /* ...translate vertical movement into pitch angle (tbd - hardcoded coefs) */
        yaw = cfg->rotate_velocity_yaw * (float32_t)dx;
        pitch = -cfg->rotate_velocity_pitch * (float32_t)dy;

        /* ...limit the pitch to 0 .. 90 (tbd - hardcoded coefs) */
        float32_t   angle = stv->rotation[1] - pitch;

        TRACE(0, _b("rotation=%f, pitch=%f, angle=%f"), stv->rotation[1], pitch, angle);

        if (angle > cfg->rotate_pitch_max)
        {
            pitch = stv->rotation[1] - cfg->rotate_pitch_max;
        }
        else if (angle < cfg->rotate_pitch_min)
        {
            pitch = stv->rotation[1] - cfg->rotate_pitch_min;
        }

        TRACE(0, _b("dx=%d, dy=%d, pitch=%f, yaw=%f"), dx, dy, pitch, yaw);

        /* ...check if adjustments exceed the thresholds */
        if (fabsf(yaw) >= cfg->rotate_yaw_threshold || fabsf(pitch) >= cfg->rotate_pitch_threshold)
        {
            __vec3      delta, q;
            __vec3_sub(stv->look_at, stv->position, delta);

            float32_t   d = __vec3_length(delta);

            /* ...rotate current camera position around look-at point */
            __mat3x3    R;
            __mat3x3_rotation(R, (__vec3){ 0.0f, -stv->rotation[1], stv->rotation[2] }, __MATH_ONE);

            __vec3      v = { d, 0.0f, 0.0f };
            __matNxN_mulv(3, R, delta, q);
            TRACE(0, _b("delta=%f,%f,%f, q=%f,%f,%f, v=%f,%f,%f"), delta[0], delta[1], delta[2], q[0], q[1], q[2], v[0], v[1], v[2]);

            stv->rotation[1] -= pitch;
            stv->rotation[2] -= yaw;

            __mat3x3_rotation(R, (__vec3){ 0.0f, -stv->rotation[1], stv->rotation[2] }, __MATH_ONE);
            __matNxN_mulvt(3, R, v, q);

            TRACE(0, _b("q=%f,%f,%f, v=%f,%f,%f"), q[0], q[1], q[2], v[0], v[1], v[2]);

            __vec3_sub(stv->look_at, q, stv->position);

            TRACE(DEBUG, _b("rotate: look-at: %f,%f,%f, position: %f,%f,%f"),
                  stv->look_at[0], stv->look_at[1], stv->look_at[2],
                  stv->position[0], stv->position[1], stv->position[2]);

            update = 1;
        }
        else
        {
            TRACE(DEBUG, _b("rotate: ignore"));
        }
    }

    return update;
}

/**
 * @brief   Move STV-scene (simultaneously shift look-at and viewing position)
 *
 * @param   stv[in]         STV-view configuration
 * @param   dx[in]          X coordinate delta, pixels
 * @param   dy[in]          Y coordinate delta, pixels
 *
 * @return                  Non-zero if view update is required
 */
static int scene_stv_pan(cfg_stv_mesh_t *stv, cfg_scene_params_t *cfg, int32_t dx, int32_t dy)
{
    int         update = 0;

    if ((dx | dy) != 0)
    {
        float32_t   shift_x, shift_y;

        /* ...get horizontal / vertical movement in mm (tbd - hardcode coefs) */
        shift_x = cfg->pan_velocity_x * (float32_t)dx;
        shift_y = cfg->pan_velocity_y * (float32_t)dy;

        /* ...calculate vector for translating horizontal shift in camera space to world */
        __mat3x3    R;
        __mat3x3_rotation(R, (__vec3){ stv->rotation[0], -stv->rotation[1], stv->rotation[2] }, __MATH_ONE);
        __mat3x3_tr(R);

        __vec3      delta_u;
        __vec3_muls(__M_col(3, R, 1), shift_x, delta_u);

        /* ...calculate vector for vertical shift in camera space; shall be parallel to the ground */
        __vec3      delta_v = { __M(3, R, 1, 1), -__M(3, R, 0, 1), 0.0f };
        __vec3_muls(delta_v, shift_y, delta_v);

        /* ...sum two vectors */
        __vec3      delta;
        __vec3_add(delta_u, delta_v, delta);

        __vec3      la, p;
        __vec3_add(stv->look_at, delta, la);
        __vec3_add(stv->position, delta, p);

        TRACE(0, _b("delta: %f,%f,%f, look-at: %f,%f,%f, position: %f,%f,%f"), delta[0], delta[1], delta[2], la[0], la[1], la[2], p[0], p[1], p[2]);

        /* ...check the limits of the viewing point - tbd - hardcode the limits */
        float32_t   d = __vec3_length(p);

        if (d < cfg->pan_max_length)
        {
            memcpy(stv->position, p, sizeof(p));
            memcpy(stv->look_at, la, sizeof(la));

            TRACE(DEBUG, _b("pan: look-at: %f,%f,%f, position: %f,%f,%f"), la[0], la[1], la[2], p[0], p[1], p[2]);

            update = 1;
        }
        else
        {
            TRACE(DEBUG, _b("pan: ignore"));
        }
    }

    return update;
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

#ifdef  BUILD_NATIVE
/**
 * @brief   Process mouse event
 *
 * @param   stv[in]         STV-configuration
 * @param   x[in]           Current mouse position, X-coordinate
 * @param   y[in]           Current mouse position, Y-coordinate
 * @param   button[in]      Button code
 * @param   button[in]      Buttons state
 *
 * @return                  Non-zero is view update is required
 */
int scene_stv_mouse_event(cfg_stv_mesh_t *stv, cfg_scene_params_t *cfg, int32_t x, int32_t y, uint32_t button, uint32_t state)
{
    static int32_t  last_pos[2] = { -1, -1 };
    int             update = 0;

    /* ...update last mouse pointer position */
    (last_pos[0] < 0 ? last_pos[0] = x, last_pos[1] = y : 0);

    int32_t         dx = x - last_pos[0];
    int32_t         dy = y - last_pos[1];

    if ((button == Button4 || button == Button5) && state == 1)
    {
        float32_t   scale = 1.0f + (button == Button4 ? 0.025 : -0.025);

        update = scene_stv_zoom(stv, cfg, x, y, scale);
    }
    else if (button == Button2 && (state & Button2Mask))
    {
        update = scene_stv_rotate(stv, cfg, dx, dy);
    }
    else if (button == Button1 && state != 0)
    {
        update = scene_stv_pan(stv, cfg, dx, dy);
    }

    if (state == 0)
    {
        /* ...reset last mouse position */
        last_pos[0] = last_pos[1] = -1;
    }
    else
    {
        /* ...latch last mouse position */
        last_pos[0] = x, last_pos[1] = y;
    }

    if (update != 0)
    {
        mesh_stv_fix_angles(stv);
    }

    return update;
}
#elif USE_GESTURES_FRAMEWORK
#include    <gestures/pinch.h>
#include    <gestures/tap.h>
#include    <gestures/swipe.h>
/**
 * @brief   Process gesture event
 *
 * @param   stv[in]         STV-configuration
 * @param   data[in]        Gesture-specific information
 * @param   async[in]       Asynchronous gestrure recognition flag
 *
 * @return                  Non-zero is view update is required
 */
int scene_stv_touch_event(cfg_stv_mesh_t *stv, cfg_scene_params_t *cfg, void *data, int async)
{
    int32_t                *dst = stv->base.dst;
    struct gesture_base    *base = data;
    int                     update = 0;

    if (base->type == GESTURE_PINCH)
    {
        gesture_pinch_t    *pinch = (gesture_pinch_t *)base;

        /* ...process only recognized composite gesture */
        if (base->state < GESTURE_STATE_RECOGNIZED)
        {
            return 0;
        }

        static int32_t  last_pos[2] = { -1, -1 };
        int32_t         x = pinch->centroid.x;
        int32_t         y = pinch->centroid.y;

        (last_pos[0] < 0 ? last_pos[0] = x, last_pos[1] = y : 0);

        int32_t         dx = x - last_pos[0];
        int32_t         dy = y - last_pos[1];

        if (!(x >= dst[0] && x <= dst[2] && y >= dst[1] && y <= dst[3]))
        {
            last_pos[0] = last_pos[1] = -1;
            return 0;
        }

        /* ...latch last centroid position */
        if (base->state == GESTURE_STATE_COMPLETE)
        {
            last_pos[0] = last_pos[1] = -1;
        }
        else
        {
            last_pos[0] = x, last_pos[1] = y;
        }

        /* ...process zooming */
        float32_t       d0 = powf(pinch->last_distance.x, 2.0f) + powf(pinch->last_distance.y, 2.0f);
        float32_t       d1 = powf(pinch->distance.x, 2.0f) + powf(pinch->distance.y, 2.0f);

        if (dx == 0 && dy == 0 && d0 == d1)
        {
            return 0;
        }

        TRACE(0, _b("pinch(%d): x=%d, y=%d, dx=%d, dy=%d, d0=%f, d1=%f, zoom: %d"), base->state, x, y, dx, dy, d0, d1, fabsf(d0 - d1) > cfg->zoom_threshold);

        if (d0 != 0 && fabsf(d0 - d1) > cfg->zoom_threshold)
        {
            update |= scene_stv_zoom(stv, cfg, x, y, 1.0f + (d0 < d1 ? cfg->zoom_factor : -cfg->zoom_factor));
        }

        if (1)
        {
            /* ...process panning */
            update |= scene_stv_pan(stv, cfg, dx, dy);
        }
    }
    else if (base->type == GESTURE_SWIPE)
    {
        gesture_swipe_t    *swipe = (gesture_swipe_t *)base;

        static int32_t  last_pos[2] = { -1, -1 };
        int32_t         x = swipe->coords.x;
        int32_t         y = swipe->coords.y;

        if (base->state == GESTURE_STATE_RECOGNIZED)
        {
            last_pos[0] = x, last_pos[1] = y;
        }

        int32_t         dx = x - last_pos[0];
        int32_t         dy = y - last_pos[1];

        last_pos[0] = x, last_pos[1] = y;

        if ((dx | dy) == 0)
        {
            return 0;
        }

        TRACE(0, _b("swipe(%d): x=%d, y=%d, dx=%d, dy=%d"), base->state, x, y, dx, dy);

        if (!(x >= dst[0] && x <= dst[2] && y >= dst[1] && y <= dst[3]))
        {
            return 0;
        }

        update = scene_stv_rotate(stv, cfg, dx, dy);
    }

    if (update != 0)
    {
        mesh_stv_fix_angles(stv);
    }

    return update;
}
#else
/**
 * @brief   Process CAN-input event
 *
 * @param   stv[in]         STV-configuration
 * @param   x0[in]          Current touch reference position, X-coordinate
 * @param   y0[in]          Current touch reference position, Y-coordinate
 * @param   off_x[in]       Current offset from reference position, X-coordinate
 * @param   off_y[in]       Current offset from reference position, Y-coordinate
 * @param   stop[in]        Stop event reception
 *
 * @return                  Non-zero is view update is required
 */
int scene_stv_input_event(cfg_stv_mesh_t *stv, cfg_scene_params_t *cfg, int32_t x0, int32_t y0, int32_t off_x, int32_t off_y, uint32_t stop)
{
    static int32_t  last_pos[2][2] = { { -1, -1 }, { -1, -1 } };
    int             update = 0;
    int32_t         x = x0 + off_x;
    int32_t         y = y0 + off_y;

    /* ...detect start of new event */
    if (last_pos[0][0] != x0 || last_pos[0][1] != y0)
    {
        /* ...new event started; get the reference touch coordinate */
        last_pos[0][0] = x0, last_pos[0][1] = y0;
        last_pos[1][0] = x0, last_pos[1][1] = y0;
    }

    /* ...get delta from last event processing */
    int32_t         dx = x - last_pos[1][0];
    int32_t         dy = y - last_pos[1][1];

    if (!stop)
    {
        /* ...process just a rotation if "stop" event is not delivered */
        update = scene_stv_rotate(stv, cfg, dx, dy);

        /* ...update last touch position */
        last_pos[1][0] = x, last_pos[1][1] = y;
    }
    else
    {
        /* ...reset last touch position */
        last_pos[0][0] = last_pos[0][1] = -1;
    }

    if (update != 0)
    {
        mesh_stv_fix_angles(stv);
    }

    return update;
}

#endif
