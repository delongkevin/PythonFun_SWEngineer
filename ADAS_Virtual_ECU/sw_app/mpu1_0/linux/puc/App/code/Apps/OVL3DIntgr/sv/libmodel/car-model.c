/*******************************************************************************
 * car-model.c
 *
 * Car model loader
 *
 * Copyright (c) 2020-2021 Cogent Embedded Inc.
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

#define MODULE_TAG                      CAR-MODEL

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "car-model.h"
#include "math-helpers.h"
#include "pbr-model.h"

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Local types definitions
 ******************************************************************************/

/**
 * @brief   Animation data
 */
typedef struct car_animation
{
    /**> Animation descriptor */
    pbr_animation_t    *dsc;

    /**> Sequence start timestamp */
    uint32_t            start;

    /**> Running state */
    uint8_t             state;

}   car_animation_t;


/**
 * @brief   Car model data
 */
struct car_model
{
    /**> Car model configuration data */
    cfg_model_t        *cfg;

    /**> Car object dimensions: [0]={Xmin,Ymin,Zmin}, [1]={Xmax,Ymax,Zmax} */
    float32_t           dim[2][3];

    /**> IBL data for exterior */
    ibl_data_t         *ibl;

    /**> Rendering scene */
    render_scene_t     *scene;

    /**> Renedering nodes */
    render_node_t      *body, *wheel[4], *shadow, *interior;

    /**> Animations descriptors */
    car_animation_t     anim_door[5], anim_mirror[2];

    /**> Previous state of the door */
    uint8_t             door_state[5], mirror_state[2];

    /**> Virtual camera position */
    float32_t           T[3];

    /**> Scene projection matrix */
    __mat4x4            P;

    /**> Scene View-Model matrix */
    __mat4x4            VM;

    /**> Car model matrix */
    __mat4x4            model_matrix;

    /**> Shadow model matrix */
    __mat4x4            shadow_matrix;

    /**> Wheels center points */
    __vec3              wc[4];

    /**> Wheels rotation angles */
    __vec3              wa[4];

    /**> Last latched timestamp for wheels rotation - tbd */
    uint32_t            last_ts;
};

/*******************************************************************************
 * Internal functions definitions
 ******************************************************************************/

/**
 * @brief   Initialize quaternion
 *
 * @param   angle[in]       Rotation angle (degrees)
 * @param   x[in]           Rotation axis X-coordinate
 * @param   y[in]           Rotation axis Y-coordinate
 * @param   z[in]           Rotation axis Z-coordinate
 * @param   q[out]          Quaternion data
 */
static inline void quat_init(float32_t angle, float32_t x, float32_t y, float32_t z, float32_t q[4])
{
    float32_t   a = angle * (float32_t)(0.5 * M_PI / 180.0);
    float32_t   c = cosf(a);
    float32_t   s = sinf(a);

    q[0] = c;
    q[1] = x * s;
    q[2] = y * s;
    q[3] = z * s;
}

/**
 * @param   Multiply quaternions: C = A * B
 *
 * @param   A[in]           First parameter
 * @param   B[in]           Second parameter
 * @param   C[out]          Result of operation
 */
static inline void quat_mul(float32_t A[4], float32_t B[4], float32_t C[4])
{
    C[0] = A[0] * B[0] - A[1] * B[1] - A[2] * B[2] - A[3] * B[3];
    C[1] = A[0] * B[1] + A[1] * B[0] + A[2] * B[3] - A[3] * B[2];
    C[2] = A[0] * B[2] - A[1] * B[3] + A[2] * B[0] + A[3] * B[1];
    C[3] = A[0] * B[3] + A[1] * B[2] - A[2] * B[1] + A[3] * B[0];
}

/**
 * @brief   Calculate wheel angle change
 *
 * @param   speed[in]           Current vehicle speed
 * @param   delta[in]           Time interval in usec
 *
 * @return                      Angle change, in degrees
 */
static inline float32_t car_wheel_calc_angle(float32_t speed, uint32_t delta)
{
    float32_t   t = fabsf(speed);

    /* ...limit the speed value to avoid aliasing effect */
    if (t <= 0.5f)
    {
        t = 0.0f;
    }
    else
    {
        //t = (t <= 5.0f ? 1.0f : 2.0f);
        (speed < 0.0f ? t = -t : 0);
        t *= (float32_t)delta * (float32_t)(180.0 / (3600.0 * 370.0 * M_PI));
    }

    return t;
}

/**
 * @brief   Process animation sequence
 */
static void car_animation_start(car_animation_t *anim, uint32_t ts)
{
    pbr_animation_t    *dsc = anim->dsc;

    if (anim->state != 0)
    {
        /* ...abort current animation sequence */
        float32_t   delta = (uint32_t)(ts - anim->start) * 1e-6f;

        delta = dsc->input[dsc->count - 1] - delta;

        (delta < 0.0f ? delta = 0.0f : 0);

        /* ...adjust starting point of animation */
        anim->start = ts - (uint32_t)(delta * 1e+6f);
    }
    else
    {
        /* ...start animation sequence */
        anim->start = ts;
        anim->state = 1;
    }
}

/**
 * @brief   Check if animation sequence is running
 */
static int car_animation_active(car_animation_t *anim, uint32_t ts, float32_t *t, int dir)
{
    pbr_animation_t    *dsc = anim->dsc;

    if (anim->state != 0)
    {
        float32_t   duration = dsc->input[dsc->count - 1];
        float32_t   t0;

        t0 = (float32_t)(uint32_t)(ts - anim->start) * 1e-6f;

        /* ...stop sequence when completed */
        (t0 >= duration ? anim->state = 0 : 0);

        /* ...invert time as needed */
        *t = (dir ? duration - t0 : t0);

        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief   Update car model matrices depending on vehicle state
 *
 * @param   car[in]         Car model data
 * @param   state[in]       Vehicle state
 */
static void car_model_update(car_model_t *car, vehicle_state_t *state)
{
    uint32_t        ts = __get_time_usec();
    uint32_t        delta = (uint32_t)(ts - car->last_ts);
    float32_t       rot_y = fabsf(state->speed) * (float32_t)delta * (float32_t)(180.0 / (3600.0 * 370.0 * M_PI));
    float32_t       rot_z = 180.0f - state->wheel_angle;
    uint32_t        i;

    /* ...set steering angle for front wheels */
    car->wa[0][2] = car->wa[1][2] = rot_z;
    car->wa[2][2] = car->wa[3][2] = 180.0f - 0.0f;

    /* ...set angle for wheels rotation depending on instant speed (km / h) */
    for (i = 0; i < 4; i++)
    {
        /* ...select rotation direction basing on wheel state */
        if (state->wheel_state[i] == 1)
        {
            car->wa[i][1] += rot_y;
        }
        else if (state->wheel_state[i] == 2)
        {
            car->wa[i][1] -= rot_y;
        }

        car->wa[i][0] = 0.0f;
        car->wa[i][1] = fmodf(car->wa[i][1], 360.0f);

        if (car->wheel[i])
        {
            float32_t       q_rot_y[4], q_rot_z[4];

            quat_init(car->wa[i][1], 0.0f, 1.0f, 0.0f, q_rot_y);
            quat_init(car->wa[i][2], -1.0f, 0.0f, 0.0f, q_rot_z);
            quat_mul(q_rot_y, q_rot_z, car->wheel[i]->xform.rotation);
        }
    }

    /* ...process doors animations */
    for (i = 0; i < 5; i++)
    {
        car_animation_t    *anim = &car->anim_door[i];
        float32_t           t;

        /* ...skip animation sequence if not defined */
        if (anim->dsc == NULL)  continue;

        if (state->door_state[i] != car->door_state[i])
        {
            car_animation_start(anim, ts);

            car->door_state[i] = state->door_state[i];
        }

        if (car_animation_active(anim, ts, &t, !car->door_state[i]))
        {
            render_animation_process(anim->dsc, &car->scene->rn[anim->dsc->node], t);
        }
    }

    /* ...process mirrors animations */
    for (i = 0; i < 2; i++)
    {
        car_animation_t    *anim = &car->anim_mirror[i];
        float32_t           t;

        /* ...skip animation sequence if not defined */
        if (anim->dsc == NULL)  continue;

        if (state->mirror_state[i] != car->mirror_state[i])
        {
            car_animation_start(anim, ts);
            car->mirror_state[i] = state->mirror_state[i];
        }

        if (car_animation_active(anim, ts, &t, !car->mirror_state[i]))
        {
            render_animation_process(anim->dsc, &car->scene->rn[anim->dsc->node], t);
        }
    }

    /* ...latch last timestamp */
    car->last_ts = ts;
}

static inline int str_cmp(const char *a, char *b)
{
    return b != NULL && !strcmp(a, b);
}

/**
 * @brief   Rendering node loading callback
 */
static int car_model_object_load_gltf(void *cdata, render_node_t *rn, const char *name)
{
    car_model_t    *car = cdata;
    cfg_model_t    *cfg = car->cfg;

    if (str_cmp(name, cfg->car_body_groups))            car->body = rn;
    else if (str_cmp(name, cfg->car_wheels_groups[0]))  car->wheel[0] = rn;
    else if (str_cmp(name, cfg->car_wheels_groups[1]))  car->wheel[1] = rn;
    else if (str_cmp(name, cfg->car_wheels_groups[2]))  car->wheel[2] = rn;
    else if (str_cmp(name, cfg->car_wheels_groups[3]))  car->wheel[3] = rn;
    else if (str_cmp(name, cfg->car_shadow_groups))     car->shadow = rn;
    else if (str_cmp(name, cfg->car_interior_groups))   car->interior = rn;

    return 1;
}

/**
 * @brief   Animation loading callback
 */
static int car_model_anim_load_cb(void *cdata, pbr_animation_t *anim, const char *name)
{
    car_model_t    *car = cdata;
    cfg_model_t    *cfg = car->cfg;

    TRACE(INIT, _b("animation: '%s'"), name);

    if (str_cmp(name, cfg->anim_door[0]))           car->anim_door[0].dsc = anim;
    else if (str_cmp(name, cfg->anim_door[1]))      car->anim_door[1].dsc = anim;
    else if (str_cmp(name, cfg->anim_door[2]))      car->anim_door[2].dsc = anim;
    else if (str_cmp(name, cfg->anim_door[3]))      car->anim_door[3].dsc = anim;
    else if (str_cmp(name, cfg->anim_door[4]))      car->anim_door[4].dsc = anim;
    else if (str_cmp(name, cfg->anim_mirror[0]))    car->anim_mirror[0].dsc = anim;
    else if (str_cmp(name, cfg->anim_mirror[1]))    car->anim_mirror[1].dsc = anim;
    else                                            return 0;

    return 1;
}

/**
 * @brief   Render object saving callback
 *
 * @param   cdata[in]       Client data
 * @prama   scene[in]       Render scene data
 * @param   f[in]           File handle
 *
 * @return                  Negative on failure
 */
static int car_model_object_save_gltf(void *cdata, render_scene_t *scene, FILE *f)
{
    car_model_t    *car = cdata;
    int             id;
    int             i;

    /* ...save car-body render object (why do I need that?) */
    id = (car->body != NULL ? (int)(car->body - scene->rn) : -1);
    CHK_ERR(fwrite(&id, sizeof(int), 1, f) == 1, -1);

    /* ...save wheels render objects ids */
    for (i = 0; i < 4; i++)
    {
        id = (car->wheel[i] != NULL ? (int)(car->wheel[i] - scene->rn) : -1);
        CHK_ERR(fwrite(&id, sizeof(int), 1, f) == 1, -1);
    }

    id = (car->interior != NULL ? (int)(car->interior - scene->rn) : -1);
    CHK_ERR(fwrite(&id, sizeof(int), 1, f) == 1, -1);

    id = (car->shadow != NULL ? (int)(car->shadow - scene->rn) : -1);
    CHK_ERR(fwrite(&id, sizeof(int), 1, f) == 1, -1);

    /* ...save animations */
    for (i = 0; i < 5; i++)
    {
        id = (car->anim_door[i].dsc != NULL ? (int)(car->anim_door[i].dsc - scene->anim) : -1);
        CHK_ERR(fwrite(&id, sizeof(int), 1, f) == 1, -1);
    }

    for (i = 0; i < 2; i++)
    {
        id = (car->anim_mirror[i].dsc != NULL ? (int)(car->anim_mirror[i].dsc - scene->anim) : -1);
        CHK_ERR(fwrite(&id, sizeof(int), 1, f) == 1, -1);
    }

    return 0;
}

/**> GLTF model loading callback */
static render_load_cb_t gltf_load_cb = {
    .load = car_model_object_load_gltf,
    .anim = car_model_anim_load_cb,
    .save = car_model_object_save_gltf,
};

/**
 * @brief   Binary model render object loading callback
 *
 * @param   cdata[in]       Client data
 * @param   scene[in]       Rendering scene data
 * @param   f[in]           File handle
 *
 * @retunr                  Negative on failure
 */
static int car_model_object_load_bin(void *cdata, render_scene_t *scene, FILE *f)
{
    car_model_t    *car = cdata;
    int             body, wheel[4], interior, shadow, id;
    int             i;

    CHK_ERR(fread(&body, sizeof(int), 1, f) == 1, -1);
    CHK_ERR(fread(wheel, 4 * sizeof(int), 1, f) == 1, -1);
    CHK_ERR(fread(&interior, sizeof(int), 1, f) == 1, -1);
    CHK_ERR(fread(&shadow, sizeof(int), 1, f) == 1, -1);

    car->body = (body >= 0 ? &scene->rn[body] : NULL);

    for (i = 0; i < 4; i++)
    {
        car->wheel[i] = (wheel[i] >= 0 ? &scene->rn[wheel[i]] : NULL);
    }

    car->interior = (interior >= 0 ? &scene->rn[interior] : NULL);
    car->shadow = (shadow >= 0 ? &scene->rn[shadow] : NULL);

    /* ...load animations */
    for (i = 0; i < 5; i++)
    {
        CHK_ERR(fread(&id, sizeof(int), 1, f) == 1, -1);
        car->anim_door[i].dsc = (id >= 0 ? &scene->anim[id] : NULL);
    }

    for (i = 0; i < 2; i++)
    {
        CHK_ERR(fread(&id, sizeof(int), 1, f) == 1, -1);
        car->anim_mirror[i].dsc = (id >= 0 ? &scene->anim[id] : NULL);
    }

    return 0;
}

/**
 * @brief   Set IBL for all objects
 *
 * @param   cdata[in]       Client data
 * @param   rn[in]          Rendering node
 */
static int car_ibl_set_cb(void *cdata, render_node_t *rn)
{
    car_model_t        *car = cdata;
    render_scene_t     *scene = car->scene;

    if (rn == car->interior)
    {
        /* ...stop descending into this node */
        return 0;
    }
    else
    {
        rn->ibl = car->ibl;

        return 1;
    }
}

/**
 * @brief   Initialize shadow subnodes
 *
 * @param   cdata[in]       Client data
 * @param   rn[in]          Rendering node
 */
static int car_shadow_prepare_cb(void *cdata, render_node_t *rn)
{
    car_model_t        *car = cdata;
    render_scene_t     *scene = car->scene;

    if (rn->mesh >= 0)
    {
        render_object_t    *ro = &scene->ro[rn->mesh];
        int                 i;

        for (i = 0; i < ro->num; i++)
        {
            int     material = ro->prim[i].material;

            /* ...make shadow material unlit */
            (material >= 0 ? scene->material[material].is_unlit = 1 : 0);
        }
    }

    return 1;
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Load car model
 *
 * @param   cfg[in]         Global configuration data
 * @param   icon[in]        Icon data
 *
 * @return                  Car model data, or NULL on failure
 */
car_model_t * car_model_load(cfg_data_t *cfg, icon_data_t *icon)
{
    car_model_t    *car;
    const char     *fname = cfg->car_model_stv.car_model;
    const char     *ext;

    /* ...bail out if no car model given */
    if (!fname)     return NULL;

    /* ...allocate car model data */
    CHK_ERR(car = calloc(1, sizeof(*car)), NULL);

    car->cfg = &cfg->car_model_stv;

    /* ...load IBL-scene data */
    if (car->cfg->ibl != NULL)
    {
        car->ibl = ibl_load(car->cfg->ibl);
    }

    /* ...check for a file type */
    if ((ext = strrchr(fname, '.')) != NULL)
    {
        ext++;
        if (!strcasecmp(ext, "bin"))
        {
            /* ...load raw binary model */
            CHK_ERR(car->scene = pbr_model_load(fname, car_model_object_load_bin, car), NULL);
        }
#ifdef BUILD_NATIVE
        else if (!strcasecmp(ext, "glb"))
        {
            /* ...load GLTF binary model */
            CHK_ERR(car->scene = gltf_load(fname, &gltf_load_cb, car), NULL);
        }
#endif
        else
        {
            TRACE(ERROR, _x("unrecognized file format: '%s'"), fname);
            errno = EINVAL;
            goto error;
        }
    }
    else
    {
        TRACE(ERROR, _x("unrecognized file format: '%s'"), fname);
        errno = EINVAL;
        goto error;
    }

    /* ...car shadow is skipped from general rendering procedure */
    (car->shadow ? car->shadow->skip = 1 : 0);

    if (car->body != NULL)
    {
        render_node_iterate(car->scene, car->body, car_ibl_set_cb, car);
    }

    /* ...prepare car shadow rendering parameters */
    if (car->shadow != NULL)
    {
        render_node_iterate(car->scene, car->shadow, car_shadow_prepare_cb, car);
    }

    /* ...set car model matrices */
    car_model_update_matrix(car, cfg);

    /* ...initialize rendering shader */
    render_node_iterate(car->scene, car->scene->root, render_create_shader_cb, car->scene);

    if (car->shadow != NULL)
    {
        render_node_iterate(car->scene, car->shadow, render_create_shader_cb, car->scene);
    }

    TRACE(INIT, _b("car-model loaded from '%s'"), car->cfg->car_model);

    return car;

error:
    free(car);
    return NULL;
}

/**
 * @brief   Set car model and car shadow matrices
 *
 * @param   car[in]         Car model data
 * @param   cfg[in]         Global configuration data pointer
 */
void car_model_update_matrix(car_model_t *car, cfg_data_t *cfg)
{
    render_scene_t     *scene = car->scene;

    /* ...set vehicle rectangle */
    float32_t   vehicle[4] = {
        -cfg->vehicle.rear_overhang,
        -cfg->vehicle.width_mirrors * 0.5f,
        cfg->vehicle.wheel_base + cfg->vehicle.front_overhang,
        cfg->vehicle.width_mirrors * 0.5f,
    };

    /* ...set shadow rectangle */
    float32_t   shadow[4] = {
        -cfg->vehicle.rear_overhang - cfg->vehicle.rear_blind_area,
        -cfg->vehicle.width * 0.5f - cfg->vehicle.right_blind_area,
        cfg->vehicle.wheel_base + cfg->vehicle.front_overhang + cfg->vehicle.front_blind_area,
        cfg->vehicle.width * 0.5f + cfg->vehicle.left_blind_area,
    };

    /* ...calculate car model matrix - assume vehicle scale is correct */
    __mat4x4_identity(car->model_matrix);
    __M(4, car->model_matrix, 0, 0) = 1.0f;
    __M(4, car->model_matrix, 1, 1) = 1.0f;
    __M(4, car->model_matrix, 0, 3) = (vehicle[0] + vehicle[2]) * 0.5e-3f;
    __M(4, car->model_matrix, 1, 3) = (vehicle[1] + vehicle[3]) * 0.5e-3f;

    /* ...calculate shadow matrix */
    __mat4x4_identity(car->shadow_matrix);
    __M(4, car->shadow_matrix, 0, 0) = (shadow[2] - shadow[0]) / (vehicle[2] - vehicle[0]);
    __M(4, car->shadow_matrix, 1, 1) = (shadow[3] - shadow[1]) / (vehicle[3] - vehicle[1]);
    __M(4, car->shadow_matrix, 0, 3) = (shadow[0] + shadow[2]) * 0.5e-3f;
    __M(4, car->shadow_matrix, 1, 3) = (shadow[1] + shadow[3]) * 0.5e-3f;
}

/**
 * @brief   Calculate PVM matrices for specified viewing position
 *
 * @param   car[in]         Car model data
 * @param   position[in]    Virtual camera position
 * @param   rotation[in]    Rotation angles
 * @param   fov[in]         Horizontal/vertical field-of-view, in degrees
 * @param   pvm[out]        PVM matrix
 */
void car_model_set_viewpoint(car_model_t *car, float32_t *position, float32_t *rotation, float32_t *fov, float32_t *pvm)
{
    float32_t   z0 = 100.0f, z1 = 20000.0f;
    float32_t   hfov2 = fov[0] * (float32_t)(0.5 * M_PI / 180.0);
    float32_t   vfov2 = fov[1] * (float32_t)(0.5 * M_PI / 180.0);

    /* ...set perspective projection matrix */
    __matNxN_zero(4, car->P);
    __M(4, car->P, 0, 0) = 1.0f / tanf(hfov2);
    __M(4, car->P, 1, 1) = 1.0f / tanf(vfov2);
    __M(4, car->P, 2, 2) = z1 / (z0 - z1);
    __M(4, car->P, 2, 3) = (z0 * z1) / (z0 - z1) * 1.0e-3f;
    __M(4, car->P, 3, 2) = -1.0f;

    __mat4x4    T, R, m;
    __mat4x4_translation(T, -position[0], -position[1], -position[2]);
    __mat4x4_rotation(R, (__vec3){rotation[0], -rotation[1], rotation[2]}, __MATH_ONE);
    __mat4x4_mul(R, T, m);

    /* ...convert coordinates from world to display (GL) coordinate system */
    const __mat4x4  S = {
        0.0f, 0.0f, -1.0f, 0.0f,
        -1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, +1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };

    __mat4x4_mul(S, m, car->VM);

    /* ...produce PVM matrix */
    __mat4x4_mul(car->P, car->VM, pvm);

    /* ...save camera location (in model coordinate system) */
    __mat4x4_translation(T, -position[0] * 1.0e-3f, -position[1] * 1.0e-3f, -position[2] * 1.0e-3f);
    __mat4x4_mul(R, T, m);
    __mat4x4_mul(S, m, car->VM);
    __vec3_muls(position, 1.0e-3f, car->T);
    //__mat4x4_dump(car->VM, "VM");
}

/*******************************************************************************
 * Rendering API
 ******************************************************************************/

/**
 * @brief   Render car image
 *
 * @param   car[in]         Car model data
 * @param   cfg[in]         Global configuration data pointer
 * @param   vehicle[in]     Vehicle state data
 * @param   intensity[in]   Global scene intensity
 */
void car_model_render(car_model_t *car, cfg_data_t *cfg, vehicle_state_t *vehicle, float32_t intensity)
{
    render_scene_t     *scene = car->scene;

    TRACE(0, _b("render model: body=%p, wheels=%p/%p/%p/%p"), car->body, car->wheel[0], car->wheel[1], car->wheel[2], car->wheel[3]);

    scene->exposure = intensity;

    /* ...update wheels matrices depending on current vehicle state */
    car_model_update(car, vehicle);

    /* ...cull-face enable - tbd - this stuff needs to be considered carefully */
    glEnable(GL_SCISSOR_TEST);
    glCullFace((car->P[0] < 0.0f ? GL_FRONT : GL_BACK)); GLCHECK();
    glFrontFace(GL_CCW); GLCHECK();
    glEnable(GL_DEPTH_TEST);    GLCHECK();

    __mat4x4    PV;

    /* ...calculate global PV matrix */
    __mat4x4_mul(car->P, car->VM, PV);

    /* ...calculate global matrices for all objects */
    pbr_scene_xform(scene, scene->root, car->model_matrix);

    /* ...render whole hierarchy (without shadow) */
    render_node_process(scene, scene->root, PV, car->T, intensity);

    /* ...render shadow */
    if (car->shadow)
    {
        /* ...set shadow scene matrix */
        pbr_scene_xform(scene, car->shadow, car->shadow_matrix);

        /* ...render node subtree */
        render_node_process(scene, car->shadow, PV, car->T, intensity);
    }
}
