/*******************************************************************************
 * view-manager.c
 *
 * View manager (compositor) module
 *
 * Copyright (c) 2020-2022 Cogent Embedded Inc.
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

#define MODULE_TAG                      VM

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "list.h"
#include "display.h"
#include "../libmodel/car-model.h"
#include "mesh-render.h"
#include "mesh-gen.h"
#include "guidelines.h"
#include "math-helpers.h"
#include "../libhv/hv.h"
#include "icons.h"
#include "odo.h"
#include "aiming.h"
#include "cc.h"
#include "ui.h"
#include "view-manager.h"
#include "scene.h"
#include "algo.h"
#include "../src/util.h"

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Local types definitions
 ******************************************************************************/

/**> Forward declarations */
typedef struct view_overlay     view_overlay_t;

/**
 * @brief   Rendering overlay data
 */
struct view_overlay
{
    /**> Overlay type */
    uint32_t                type;

    /**> List link item */
    __list_t                link;

    /**> Overlay update flag */
    int32_t                 invalidate;

    /**> Rendering function */
    int                   (*render)(view_manager_t *vm, view_overlay_t *ovl, texture_data_t **texture, render_context_t *ctx);

    /**> Vehicle state update function - tbd */
    int                   (*update)(view_manager_t *vm, view_overlay_t *ovl);
};

/**
 * @brief   Mesh configuration
 */
typedef struct vm_mesh_overlay
{
    /**> Generic overlay structure */
    view_overlay_t      ovl;

    /**> Mesh configuration data (own copy? - tbd) */
    cfg_mesh_t         *cfg;

    /**> Mesh run-time data */
    mesh_data_t         mesh;

    /**> HV-VBO array (tbd) */
    vbo_dynarray_t      hv_vbo[SV_CAMERAS_NUMBER];

}   vm_mesh_overlay_t;

/**
 * @brief   Car model overlay
 */
typedef struct vm_car_overlay
{
    /**> Generic overlay structure */
    view_overlay_t      ovl;

    /**> Car model overlay type */
    uint32_t            type;

    /**> Associated STV mesh configuration */
    cfg_stv_mesh_t     *stv;

    /**> Destination tile pointer (viewport) */
    int32_t            *dst;

    /**> Projection-View-Model 4*4 matrix */
    __mat4x4            PVM;

}   vm_car_overlay_t;

/**
 * @brief   Guidelines overlay
 */
typedef struct vm_guide_overlay
{
    /**> Generic overlay structure */
    view_overlay_t      ovl;

    /**> Guidelines descriptor data */
    guide_data_t        guide;

    /**> Mesh configuration data */
    cfg_mesh_t         *mesh;

    /**> Guidelines type */
    uint32_t            type;

}   vm_guide_overlay_t;

/**
 * @brief   Object-detection overlay
 */
typedef struct vm_od_overlay
{
    /**> Generic overlay structure */
    view_overlay_t      ovl;

    /**> ODO generator data */
    pas_stv_data_t      odo;

    /**> Associated STV mesh configuration */
    cfg_stv_mesh_t     *stv;

}   vm_od_overlay_t;

/**
 * @brief   Icon overlay
 */
typedef struct vm_icon_overlay
{
    /**> Generic overlay structure */
    view_overlay_t      ovl;

    /**> Icon overlay type */
    uint32_t            type;

    /**> Associated mesh destination tile */
    int32_t            *dst;

    /**> Icon render-list */
    icon_render_t       icon;
    icon_render_t       icon_back;

}   vm_icon_overlay_t;

/**
 * @brief   Aiming view overlay data
 */
typedef struct vm_aiming_overlay
{
    /**> Generic overlay structure */
    view_overlay_t      ovl;

    /**> Anything else? */

}   vm_aiming_overlay_t;

/**
 * @brief   Historical-view overlay
 */
typedef struct vm_hv_overlay
{
    /**> Generic overlay structure */
    view_overlay_t      ovl;

    /**> HV buffer data */
    //hv_data_t          *hv;

    /**> Associated STV mesh configuration? - tbd */
    //cfg_stv_mesh_t     *stv;

}   vm_hv_overlay_t;

/**
 * @brief   View manager data
 */
struct view_manager
{
    /**> Active screen layout  */
    int32_t             layout;

    /**> Next screen layout */
    int32_t             transition;

    /**> Global configuration data */
    cfg_data_t         *cfg;

    /**> Car model data */
    car_model_t        *car_model;

    /**> Icons data */
    icon_data_t        *icon;

    /**> UI data */
    ui_data_t          *ui;

    /**> Previous UI page id */
    int32_t             prev_page;

    /**> Mesh generator data */
    mesh_gen_t         *gen;

    /**> Guidelines generator data */
    guide_gen_t        *gg;

    /**> Color-correction module */
    cc_data_t          *cc;

    /**> Historical view module data */
    hv_data_t          *hv;

    /**> UI overlay */
    vm_icon_overlay_t   ovl_ui;

    /**> Historical-view overlay */
    vm_hv_overlay_t     ovl_hv;

    /**> Aiming overlay */
    vm_aiming_overlay_t ovl_aiming;

    /**> Mesh overlays array */
    vm_mesh_overlay_t  *ovl_mesh;

    /**> Guidelines overlays array */
    vm_guide_overlay_t *ovl_guide;

    /**> Icons overlays array */
    vm_icon_overlay_t  *ovl_icon;

    /**> Car model overlays array */
    vm_car_overlay_t   *ovl_car;

    /**> Object-detection overlays array */
    vm_od_overlay_t    *ovl_odo;

    /**> Render overlays list */
    __list_t            render;

    /**> Global scene intensity level */
    float32_t           intensity;

    /**> Scene transition morphing function */
    void              (*morph)(view_manager_t *vm);

    /**> Timestamp for morphing sequence start */
    uint32_t            morph_start_time;

    /**> Morphing sequence state */
    uint32_t            morph_state;

    /**> Morphing sequence source configuration */
    void               *morph_src;

    /**> Morphing sequence destination configuration */
    void               *morph_dst;

    /**> Force regeneration of the points */
    int                 cc_invalidate;

    /**> Vehicle state - tbd - interim location */
    vehicle_state_t     vehicle;

    /**> Heartbeat counter value */
    uint32_t            heartbeat_ts;

    /**> Internal data protection lock */
    pthread_mutex_t     lock;

    /**> Font data for debugging */
    font_data_t        *font;

    uint32_t           stage;

    uint32_t           ctlval_mask;
    uint32_t           ctlval_coords[2];
};

/*******************************************************************************
 * Rendering overlays creation
 ******************************************************************************/

/**
 * @brief   Reset overlays rendering list
 *
 * @param   vm[in]          View manager handle
 */
static inline void view_overlays_reset(view_manager_t *vm)
{
    /* ...clear rendering list */
    __list_init(&vm->render);
}

/**
 * @brief   Add overlay to the tail of rendering list
 *
 * @param   vm[in]          View manager handle
 * @param   ovl[in]         Overlay handle
 */
static inline void view_overlay_add(view_manager_t *vm, view_overlay_t *ovl)
{
    /* ...add overlay into tail of the render list */
    __list_push_tail(&vm->render, &ovl->link);
}

/**
 * @brief   Remove overlay from rendering list
 *
 * @param   vm[in]          View manager handle
 * @param   ovl[in]         Overlay handle
 */
static inline void view_overlay_remove(view_manager_t *vm, view_overlay_t *ovl)
{
    __list_delete(&ovl->link);
}

/*******************************************************************************
 * Heartbeat timer
 ******************************************************************************/

/**
 * @brief   Heartbeat timer for PAS state
 */
static void vm_heartbeat(view_manager_t *vm)
{
    uint32_t    ts = __get_time_usec();
    uint32_t    delta = ts - vm->heartbeat_ts;
    int         update = 0;
    int         i;

    /* ...latch new heartbeat counter value */
    vm->heartbeat_ts = ts;

    /* ...process 2.5Hz blinking PAS timer */
    vm->vehicle.pas.counter_25 += delta;

    if (vm->vehicle.pas.counter_25 >= (uint32_t)(1000000 / (2.5 * 2)))
    {
        vm->vehicle.pas.counter_25 -= (uint32_t)(1000000 / (2.5 * 2));
        vm->vehicle.pas.blink_25_on ^= 1;
        update = 1;
    }

    /* ...process 5.0Hz blinking PAS timer */
    vm->vehicle.pas.counter_50 += delta;

    if (vm->vehicle.pas.counter_50 >= (uint32_t)(1000000 / (5.0 * 2)))
    {
        vm->vehicle.pas.counter_50 -= (uint32_t)(1000000 / (5.0 * 2));
        vm->vehicle.pas.blink_50_on ^= 1;
        update = 1;
    }

    if (update != 0)
    {
    /* ...blinking for sonars is disabled of now */
        //view_manager_update_pas(vm);
        view_manager_update_ap(vm);
    }

    /* ...process doors/mirrors state */
    cc_mask_camera(vm->cc, 0, (float32_t[3]){0.0f, 0.0f, 0.0f}, vm->vehicle.calib_error);
    cc_mask_camera(vm->cc, 1, (float32_t[3]){0.0f, 0.0f, 0.0f}, vm->vehicle.door_state[0] || vm->vehicle.mirror_state[0] || vm->vehicle.calib_error);
    cc_mask_camera(vm->cc, 3, (float32_t[3]){0.0f, 0.0f, 0.0f}, vm->vehicle.door_state[1] || vm->vehicle.mirror_state[1] || vm->vehicle.calib_error);
    cc_mask_camera(vm->cc, 2, (float32_t[3]){0.0f, 0.0f, 0.0f}, vm->vehicle.door_state[4] || vm->vehicle.calib_error);

    /* ...save heartbeat counter increment (in us) */
    vm->vehicle.delta = delta;

    extern int INTENSITY_DEBUG;

    if (INTENSITY_DEBUG && vm->transition < 0)
    {
        vm->intensity = 0.5f + 0.5f * sinf(vm->heartbeat_ts * (1e-6f * 2 * M_PI / 2));
    }
}

/*******************************************************************************
 * Scene rendering
 ******************************************************************************/

static void __gfx_sample(view_manager_t *vm, render_context_t *ctx)
{
    int32_t     x0 = 32, y0 = 32;
    extern float32_t __fps;

    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);

    float32_t   yellow[4] = {1.0f, 1.0f, 0.0f, 0.7f};
    float32_t   white[4] = {1.0f, 1.0f, 1.0f, 0.7f};
    float32_t   green[4] = {0.0f, 1.0f, 0.0f, 0.7f};
    float32_t   blue[4] = {0.0f, 0.0f, 1.0f, 0.7f};
    float32_t   red[4] = {1.0f, 0.0f, 0.0f, 0.7f};

    font_render_params_t    params;

    font_render_params_init(&params, x0, y0, 0.0f, 1.0f, 1.0f, yellow);
    font_render(vm->font, ctx, &params, 1.0f, "fps: %.2f", __fps);

    params.length += 20.0f;
    memcpy(params.color, white, sizeof(white));

    font_render(vm->font, ctx, &params, 1.0f, "time: %u", __get_time_usec());

    x0 += params.length;

    line_draw(ctx, (float32_t[2]){32, 40}, (float32_t[2]){x0, 40}, yellow, white, 4.0f, 1.5f, vm->intensity);
    rect_draw(ctx, (float32_t[2]){24, 8}, (float32_t[2]){x0 + 8, 48}, red, green, blue, white, 1.0f, 0.5f, vm->intensity);

    float32_t   P[6][2] = {
        { 100, 90 },
        { 60, 200 },
        { 160, 130 },
        { 40, 130 },
        { 140, 200 },
        { 100, 90 },
    };

    float32_t   C[6][4] = {
        { 1.0f, 0.0f, 0.0f, 0.5f},
        { 1.0f, 0.0f, 0.0f, 0.8f},
        { 1.0f, 0.0f, 0.0f, 0.6f},
        { 1.0f, 0.0f, 0.0f, 0.6f},
        { 1.0f, 0.0f, 0.0f, 0.8f},
        { 1.0f, 0.0f, 0.0f, 0.5f},
    };

    poly_draw(ctx, P, C, 6, 3.0f, 0.75f, vm->intensity);

    float32_t   F0[2] = { 200.0f, 300.0f };
    float32_t   F1[2] = { 600.0f, 200.0f };

    ellipse_draw(ctx, F0, F1, 175.0f, 1.0f * 4.0 / 3.0 * M_PI, 1.0f * M_PI / 3.0, blue, 10.0f, 10.0f, vm->intensity);
    ellipse_draw(ctx, F0, F0, 10.0f, 0.0f, 0.0f, green, 3.0f, 1.0f, vm->intensity);
    ellipse_draw(ctx, F1, F1, 10.0f, 0.0f, 0.0f, green, 3.0f, 1.0f, vm->intensity);
}

static int vm_ui_render(view_manager_t *vm, view_overlay_t *ovl, texture_data_t **texture, render_context_t *ctx);

static uint32_t check_all_cameras(texture_data_t **texture)
{
    uint32_t i;
    uint32_t all_cameras_on = 1;
    for (i = 0; i < SV_CAMERAS_NUMBER; i++)
    {
        if (texture[i] == NULL)
        {
            all_cameras_on = 0;
            break;
        }
    }

    return all_cameras_on;
}


/**
 * @brief   Render screen layout and process all transitions
 *
 * @param   vm[in]          View manager handle
 * @param   texture[in]     Array of camera textures
 * @param   ctx[in]         Rendering context
 *
 * @return                  Negative on failure
 */
int view_manager_render(view_manager_t *vm, texture_data_t **texture, render_context_t *ctx)
{
    cfg_data_t     *cfg = vm->cfg;
    __list_t       *render = &vm->render;
    __list_t       *obj;

    pthread_mutex_lock(&vm->lock);

    vm->ctlval_mask = 0;

    /* ...color-correction coefficients calculations */
    if (vm->cc != NULL && cfg->cc.enable != 0 && check_all_cameras(texture))
    {
        /* ...regenerate points if required */
        if (vm->cc_invalidate)
        {
            cc_generate_points(vm->cc, cfg, mesh_gen_cameras(vm->gen));
            vm->cc_invalidate = 0;
        }

        /* ...always run statistics update */
        cc_update(vm->cc, texture);
    }

    /* ...heart-beat timer processing */
    vm_heartbeat(vm);

    vm->stage = 0;

    /* ...render all objects with current settings */
    for (obj = list_first(render); obj != list_null(render); obj = list_next(render, obj))
    {
        view_overlay_t     *ovl = container_of(obj, view_overlay_t, link);

        if (ovl->render != vm_ui_render)
            continue;

        TRACE(DEBUG, _b("render overlay %p %d..."), ovl, ovl->type);

        /* ...update overlay as needed */
        if (ovl->invalidate && ovl->update)
        {
            if ((ovl->invalidate = ovl->update(vm, ovl)) < 0)
            {
                TRACE(ERROR, _x("ovl[%p]: update failed: %s"), ovl,strerror(errno));
            }
        }

        /* ...render an overlay */
        if (ovl->render && ovl->render(vm, ovl, texture, ctx) < 0)
        {
            TRACE(ERROR, _x("ovl[%p]: rendering failed: %s"), ovl,strerror(errno));
        }
    }

    vm->stage = 1;

    for (obj = list_first(render); obj != list_null(render); obj = list_next(render, obj))
    {
        view_overlay_t     *ovl = container_of(obj, view_overlay_t, link);

        TRACE(DEBUG, _b("render overlay %p %d..."), ovl, ovl->type);

        /* ...update overlay as needed */
        if (ovl->invalidate && ovl->update)
        {
            if ((ovl->invalidate = ovl->update(vm, ovl)) < 0)
            {
                TRACE(ERROR, _x("ovl[%p]: update failed: %s"), ovl, strerror(errno));
            }
        }

        /* ...render an overlay */
        if (ovl->render && ovl->render(vm, ovl, texture, ctx) < 0)
        {
            TRACE(ERROR, _x("ovl[%p]: rendering failed: %s"), ovl, strerror(errno));
        }
    }

    TRACE(DEBUG, _b("rendering done..."));

    if (0)  __gfx_sample(vm, ctx);

    /* ...process morphing sequence */
    if (vm->morph != NULL)
    {
        vm->morph(vm);
    }

    pthread_mutex_unlock(&vm->lock);

    return 0;
}

/**
 * @brief   Mesh setup function
 *
 * @param   vm[in]          View manager data
 * @param   ovl[in]         Overlay data
 *
 * @return                  Negative on failure
 */
static int vm_mesh_setup(view_manager_t *vm, vm_mesh_overlay_t *ovl, cfg_mesh_t *mesh)
{
    cfg_data_t     *cfg = vm->cfg;

    /* ...force overlay update */
    ovl->ovl.invalidate = 1;

    /* ...set mesh configuration data (make a fresh copy?) */
    ovl->cfg = mesh;//memcpy(&ovl->cfg, mesh, sizeof(*mesh));

    /* ...fixup mesh parameters */
    if (mesh->base.type == MESH_SCV)
    {
        recalculate_position(&mesh->scv, vm->cfg);
    }
    if (mesh->base.type == MESH_TV)
    {
        calculate_shadow_from_vehicle(vm->cfg, &mesh->tv);
    }
    if (mesh->base.type == MESH_STV)
    {
        mesh_stv_fix_angles(&ovl->cfg->stv);
    }

    /* ...add overlay to rendering list */
    view_overlay_add(vm, &ovl->ovl);

    return 0;
}

/**
 * @brief   Mesh rendering function
 *
 * @param   ovl[in]         Overlay data
 * @param   cdata[in]       Client data
 * @param   intensity[in]   Scene global intensity
 *
 * @return                  Negative on failure
 */
static int vm_mesh_render(view_manager_t *vm, view_overlay_t *ovl, texture_data_t **texture, render_context_t *ctx)
{
    vm_mesh_overlay_t  *mesh = container_of(ovl, vm_mesh_overlay_t, ovl);
    cfg_data_t         *cfg = vm->cfg;
    uint32_t            type = mesh->cfg->base.type;
    float32_t         (*cc)[3][3] = (type == MESH_TV || type == MESH_STV ? cc_get_coefs(vm->cc) : NULL);

    uint32_t check = check_all_cameras(texture);

    /* ...render current mesh */
    if (type == MESH_RAW)
    {
        mesh_render_raw(texture[mesh->cfg->raw.id], &mesh->cfg->raw, ctx, vm->intensity);
    }
    else if (type == MESH_RAW_MCV)
    {
        mesh_render_raw_mcv(texture, &mesh->cfg->raw_mc, ctx, vm->intensity);
    }
    else if (type == MESH_TV)
    {
        mesh_render_tv(&mesh->mesh, texture, ctx, vm->intensity, check ? cc: NULL);
    }
    else
    {
        if (type == MESH_CTL)
        {
            vm->ctlval_mask = mesh->cfg->ctl.cameras;
            vm->ctlval_coords[0] = mesh->cfg->ctl.output_point[0];
            vm->ctlval_coords[1] = mesh->cfg->ctl.output_point[1];
        }
        mesh_render_tv(&mesh->mesh, texture, ctx, vm->intensity, cc);

#ifdef HV_ENABLE
        /* ...render historical-view as needed */
        (type == MESH_STV && vm->hv != NULL ? hv_mesh_render(vm->hv, mesh->hv_vbo) : 0);
#endif
    }

    return 0;
}

/**
 * @brief   Mesh overlay update function
 *
 * @param   ovl[in]         Overlay handle
 *
 * @return                  Negative on failure
 */
static int vm_mesh_update(view_manager_t *vm, view_overlay_t *ovl)
{
    vm_mesh_overlay_t  *mesh = container_of(ovl, vm_mesh_overlay_t, ovl);
    uint32_t            type = mesh->cfg->base.type;
    int                 r;

    /* ...regenerate same mesh with updated parameters */
    if (type == MESH_STV)
    {
        /* ...prepare historical-view mesh */
        if (0) r = mesh_prepare_hv(vm->gen, vm->cfg, vm->hv, mesh->hv_vbo);

        r = mesh_generate_stv(vm->gen, vm->cfg, &mesh->cfg->stv, &mesh->mesh);
    }
    else if (type == MESH_TV)
    {
        r = mesh_generate_tv(vm->gen, vm->cfg, &mesh->cfg->tv, &mesh->mesh);
    }
    else if (type == MESH_SCV)
    {
        r = mesh_generate_scv(vm->gen, vm->cfg, &mesh->cfg->scv, &vm->vehicle, &mesh->mesh);
    }
    else if (type == MESH_CTL)
    {
        r = mesh_generate_ctl(vm->gen, vm->cfg, &mesh->cfg->ctl, &mesh->mesh);
    }
    else if (type == MESH_RAW || type == MESH_RAW_MCV)
    {
        r = 0;
    }
    else
    {
        r = -(errno = EINVAL);
    }

    return r;
}

/**
 * @brief   Car model rendering function
 *
 * @param   ovl[in]         Overlay data
 * @param   cdata[in]       Client data
 * @param   intensity[in]   Scene global intensity
 *
 * @return                  Negative on failure
 */
static int vm_car_render(view_manager_t *vm, view_overlay_t *ovl, texture_data_t **texture, render_context_t *ctx)
{
    vm_car_overlay_t   *car = container_of(ovl, vm_car_overlay_t, ovl);

    /* ...prepare rendering context */
    render_context_set_view(ctx, car->stv->base.dst);

    /* ...render car model with given scene virtual camera matrix - tbd */
    vm->car_model ? car_model_render(vm->car_model, vm->cfg, &vm->vehicle, vm->intensity) : 0;

    return 0;
}

/**
 * @brief   Car model overlay setup for STV-view
 *
 * @param   vm[in]          View manager data
 * @param   ovl[in]         Overlay data
 * @param   cfg[in]         STV-configuration
 *
 * @return                  Negative on failure
 */
static int vm_car_update(view_manager_t *vm, view_overlay_t *ovl)
{
    vm_car_overlay_t   *car = container_of(ovl, vm_car_overlay_t, ovl);
    cfg_stv_mesh_t     *stv = car->stv;
    int                 r;

    /* ...car model matrix update */
    (vm->car_model ? car_model_update_matrix(vm->car_model, vm->cfg) : 0);

    /* ...produce rotation matrix */
    (vm->car_model ? car_model_set_viewpoint(vm->car_model, stv->position, stv->rotation, stv->fov, car->PVM) : 0);

    return 0;
}

/**
 * @brief   Car model overlay setup for 3D-view
 *
 * @param   vm[in]          View manager data
 * @param   ovl[in]         Overlay data
 * @param   cfg[in]         STV-configuration
 *
 * @return                  Negative on failure
 */
static int vm_car_setup(view_manager_t *vm, vm_car_overlay_t *car, cfg_mesh_t *mesh, cfg_ovl_car_t *overlay)
{
    /* ...save associated mesh configuration */
    car->stv = &mesh->stv;

    /* ...force overlay update flag */
    car->ovl.invalidate = 1;

    /* ...add overlay to rendering list */
    view_overlay_add(vm, &car->ovl);

    return 0;
}

/**
 * @brief   Guidelines overlay setup function
 *
 * @param   vm[in]      View manager data
 * @param   ovl[in]     Guidelines overlay data
 * @param   type[in]    Guidelines type
 *
 * @return              Negative on failure
 */
static int vm_od_setup(view_manager_t *vm, vm_od_overlay_t *odo, cfg_mesh_t *mesh, cfg_ovl_odo_t *overlay)
{
    /* ...save mesh reference */
    odo->stv = &mesh->stv;

    /* ...force guidelines update */
    odo->ovl.invalidate = 1;

    /* ...add overlay to rendering list */
    view_overlay_add(vm, &odo->ovl);

    return 0;
}

/**
 * @brief   Object-detection overlay rendering function
 *
 * @param   ovl[in]         Overlay data
 * @param   texture[in]     Array of input video buffers
 * @param   ctx[in]         Rendering context
 *
 * @return                  Negative on failure
 */
static int vm_od_render(view_manager_t *vm, view_overlay_t *ovl, texture_data_t **texture, render_context_t *ctx)
{
    vm_od_overlay_t  *odo = container_of(ovl, vm_od_overlay_t, ovl);
    cfg_stv_mesh_t   *stv = odo->stv;
    __mat4x4          PVM;

    /* ...prepare rendering context */
    render_context_set_view(ctx, stv->base.dst);

    /* ...produce rotation matrix - tbd - move to "update" */
    odo_set_viewpoint(stv->position, stv->rotation, stv->fov, PVM);

    /* ...render current mesh - tbd */
    stv_odo_render(&odo->odo, ctx, vm->cfg, PVM, vm->intensity);

    return 0;
}

/**
 * @brief   Object-detection overlay update function
 *
 * @param   vm[in]          View-manager data
 * @param   ovl[in]         Overlay handle
 *
 * @return                  Negative on failure
 */
static int vm_od_update(view_manager_t *vm, view_overlay_t *ovl)
{
    vm_od_overlay_t    *od = container_of(ovl, vm_od_overlay_t, ovl);

    /* ...generate ODO overlay */
    return stv_odo_generate(vm->cfg, &vm->vehicle, &od->odo);
}

/**
 * @brief   Guidelines rendering function
 *
 * @param   ovl[in]         Overlay data
 * @param   cdata[in]       Client data
 *
 * @return                  Negative on failure
 */
static int vm_guide_render(view_manager_t *vm, view_overlay_t *ovl, texture_data_t **texture, render_context_t *ctx)
{
    vm_guide_overlay_t  *guide = container_of(ovl, vm_guide_overlay_t, ovl);

    TRACE(0, _b("render-guide-ovl-%u: type=%u"), (int)(guide - vm->ovl_guide), guide->type);

    /* ...render current mesh */
    guide_render(&guide->guide, ctx, vm->intensity);

    return 0;
}

/**
 * @brief   Guidelines overlay update function
 *
 * @param   vm[in]          View-manager data
 * @param   ovl[in]         Overlay handle
 *
 * @return                  Negative on failure
 */
static int vm_guide_update(view_manager_t *vm, view_overlay_t *ovl)
{
    vm_guide_overlay_t *guide = container_of(ovl, vm_guide_overlay_t, ovl);
    guide_gen_t        *gen = vm->gg;
    cfg_mesh_t         *mesh = guide->mesh;
    int                 type = guide->type;
    int                 r;

    /* ...select proper guidelines generator */
    if (type == GUIDE_FRONT || type == GUIDE_REAR)
    {
        CHK_ERR(mesh->base.type == MESH_SCV, -(errno = EINVAL));
        r = guide_front_rear_generate(gen, vm->cfg, &mesh->scv, type == GUIDE_FRONT, 1, &vm->vehicle, &guide->guide);
    }
    else if (type == GUIDE_FFC)
    {
        CHK_ERR(mesh->base.type == MESH_SCV, -(errno = EINVAL));
        r = guide_ffc_generate(gen, vm->cfg, &mesh->scv, 1, 1, &vm->vehicle, &guide->guide);
    }
    else if (type == GUIDE_HATCHED)
    {
        CHK_ERR(mesh->base.type == MESH_TV, -(errno = EINVAL));

        r = guide_hatched_generate(gen, vm->cfg, &mesh->tv, &guide->guide);
    }
    else if (type == GUIDE_FRONT_WIDE || type == GUIDE_REAR_WIDE)
    {
        CHK_ERR(mesh->base.type == MESH_SCV, -(errno = EINVAL));
        r = guide_front_rear_generate(gen, vm->cfg, &mesh->scv, type == GUIDE_FRONT_WIDE, 0, &vm->vehicle, &guide->guide);
    }
    else if (type == GUIDE_TOP_FRONT || type == GUIDE_TOP_REAR)
    {
        CHK_ERR(mesh->base.type == MESH_TV, -(errno = EINVAL));
        r = guide_gen_top_view(gen, vm->cfg, &mesh->tv, type == GUIDE_TOP_FRONT, &vm->vehicle, &guide->guide);
    }
    else if (type == GUIDE_SV_LEFT || type == GUIDE_SV_RIGHT)
    {
        CHK_ERR(mesh->base.type == MESH_SCV, -(errno = EINVAL));
        r = guide_side_generate(gen, vm->cfg, &mesh->scv, type == GUIDE_SV_LEFT, &vm->vehicle, &guide->guide);
    }
    else if (type == GUIDE_STV_FRONT || type == GUIDE_STV_REAR)
    {
        CHK_ERR(mesh->base.type == MESH_STV, -(errno = EINVAL));
        r = guide_stv_generate(gen, vm->cfg, &mesh->stv, type == GUIDE_STV_FRONT, &vm->vehicle, &guide->guide);
    }
    else if (type == GUIDE_THA)
    {
        CHK_ERR(mesh->base.type == MESH_SCV, -(errno = EINVAL));
        r = guide_tha_generate(gen, vm->cfg, &mesh->scv, &vm->vehicle, &guide->guide);
    }
    else
    {
        r = -(errno = EINVAL);
    }

    return r;
}

/**
 * @brief   Guidelines overlay setup function
 *
 * @param   vm[in]      View manager data
 * @param   ovl[in]     Guidelines overlay data
 *
 * @return              Negative on failure
 */
static int vm_guide_setup(view_manager_t *vm, vm_guide_overlay_t *guide, cfg_mesh_t *mesh, cfg_ovl_guide_t *overlay)
{
    /* ...save guideline type */
    guide->type = overlay->subtype;

    /* ...save associated mesh configuration */
    guide->mesh = mesh;

    /* ...force guidelines update */
    guide->ovl.invalidate = 1;

    /* ...add overlay to rendering list */
    view_overlay_add(vm, &guide->ovl);

    return 0;
}

/**
 * @brief   Icon overlay rendering function
 *
 * @param   vm[in]          View manager data
 * @param   ovl[in]         Overlay data
 * @param   texture[in]     Input textures array
 * @param   ctx[in]         Rendering context
 *
 * @return                  Negative on failure
 */
static int vm_icon_render(view_manager_t *vm, view_overlay_t *ovl, texture_data_t **texture, render_context_t *ctx)
{
    vm_icon_overlay_t  *icon = container_of(ovl, vm_icon_overlay_t, ovl);

    /* ...render current mesh */
    icon_render(&icon->icon, ctx, vm->intensity);

    return 0;
}

/**
 * @brief   Icon overlay update function
 *
 * @param   vm[in]          View-manager data
 * @param   ovl[in]         Overlay handle
 *
 * @return                  Negative on failure
 */
static int vm_icon_update(view_manager_t *vm, view_overlay_t *ovl)
{
    vm_icon_overlay_t  *icon = container_of(ovl, vm_icon_overlay_t, ovl);
    cfg_data_t         *cfg = vm->cfg;
    int                 type = icon->type;
    uint32_t            id = vm->layout;
    int                 r;

    /* ...reset icons overlay */
    icon_reset(&icon->icon);
    icon_reset(&icon->icon_back);

    /* ...need to set position and source coordinates of the texture; build up a list of objects sorted in render order */
    if (type == ICON_OVL_CAR_TV || type == ICON_OVL_CAR_SV)
    {
        int     tv = (type == ICON_OVL_CAR_SV ? 0 : (0 ? -1 : 1));

        /* ...generate sonar-view overlay */
        r = icon_add_sonar(vm->icon, cfg, &vm->vehicle, tv, 1, &icon->icon);
    }
    else if (type == ICON_PDT_SONAR)
    {
        r = icon_add_pdc(vm->icon, cfg, &vm->vehicle, 1, 1, &icon->icon);
    }
    else if (type == ICON_OVL_CTA_FRONT || type == ICON_OVL_CTA_REAR || type == ICON_OVL_CTA_SIDE)
    {
        int     front = (type == ICON_OVL_CTA_FRONT);

        /* ...select front/rear-view and side-view */
        r = icon_add_cta(vm->icon, cfg, front, &vm->vehicle, &icon->icon);
    }
    else if (type == ICON_OVL_AIMING || type == ICON_OVL_AIMING_SIDE)
    {
        int     type = 1;
        int     side = (type == ICON_OVL_AIMING_SIDE ? 1 : 0);

        /* ...select 360-view and side-view flags */
        r = icon_add_aiming(vm->icon, cfg, type, side, &vm->vehicle, &icon->icon);
    }
    else if (type == ICON_OVL_HITCH)
    {
        r = icon_add_hitch(vm->icon, cfg, &vm->vehicle, &icon->icon);
    }
    else if (type == ICON_OVL_COUPLER)
    {
        r = icon_add_coupler(vm->icon, cfg, &vm->vehicle, &icon->icon);
    }
    else if (type >= ICON_OVL_TRSC_SVC && type <= ICON_OVL_TRSC_TRG_C)
    {
        r = icon_add_trsc(vm->icon, cfg, type, &vm->vehicle, &icon->icon);
    }
    else if (type == ICON_OVL_BORDER)
    {
        r = icon_add_border(vm->icon, cfg, icon->dst, &icon->icon);
    }
    else
    {
        r = -(errno = EINVAL);
    }

    return r;
}

/**
 * @brief   Icon overlay setup function
 *
 * @param   vm[in]      View manager data
 * @param   ovl[in]     Icon overlay data
 * @param   type[in]    Icon overlay type
 *
 * @return              Negative on failure
 */
static int vm_icon_setup(view_manager_t *vm, vm_icon_overlay_t *icon, cfg_mesh_t *mesh, cfg_ovl_icon_t *overlay)
{
    /* ...save icon type */
    icon->type = overlay->subtype;

    /* ...force overlay update */
    icon->ovl.invalidate = 1;

    /* ...save associated mesh configuration */
    icon->dst = (mesh ? mesh->base.dst : overlay->dst);

    /* ...add overlay to rendering list */
    view_overlay_add(vm, &icon->ovl);

    return 0;
}

/**
 * @brief   UI overlay setup function
 *
 * @param   vm[in]      View manager data
 * @param   ovl[in]     Icon overlay data
 * @param   type[in]    Icon overlay type
 *
 * @return              Negative on failure
 */
static int vm_ui_setup(view_manager_t *vm)
{
    vm_icon_overlay_t  *icon = &vm->ovl_ui;

    /* ...set other overlays (guidelines, PAS, CTA, car-model and so on) */
    ui_set_page(vm->ui, vm->cfg, vm->layout);

    /* ...force overlay update */
    icon->ovl.invalidate = 1;

    /* ...add overlay to rendering list */
    view_overlay_add(vm, &icon->ovl);

    return 0;
}

int vm_ui_language_reload(view_manager_t *vm, const char* path_to_ktx)
{
    ui_language_reload(vm->ui, path_to_ktx);

    return 0;
}
/**
 * @brief   Icon overlay rendering function
 *
 * @param   vm[in]          View manager data
 * @param   ovl[in]         Overlay data
 * @param   texture[in]     Input textures array
 * @param   ctx[in]         Rendering context
 *
 * @return                  Negative on failure
 */
static int vm_ui_render(view_manager_t *vm, view_overlay_t *ovl, texture_data_t **texture, render_context_t *ctx)
{
    vm_icon_overlay_t  *icon = container_of(ovl, vm_icon_overlay_t, ovl);

    /* ...render current mesh */

    if (vm->stage == 0)
    {
        icon_render(&icon->icon_back, ctx, 1.0f);
    }
    else
    {
        icon_render(&icon->icon, ctx, 1.0f);
    }
    
    return 0;
}

/**
 * @brief   Icon overlay rendering function
 *
 * @param   vm[in]          View manager data
 * @param   ovl[in]         Overlay data
 * @param   texture[in]     Input textures array
 * @param   ctx[in]         Rendering context
 *
 * @return                  Negative on failure
 */
static int vm_ui_update(view_manager_t *vm, view_overlay_t *ovl)
{
    vm_icon_overlay_t  *icon = container_of(ovl, vm_icon_overlay_t, ovl);

    /* ...reset icons overlay */
    icon_reset(&icon->icon);
    icon_reset(&icon->icon_back);

    /* ...add UI buttons */
    ui_update(vm->ui, &icon->icon, &icon->icon_back);

    return 0;
}

/**
 * @brief   Icon overlay setup function
 *
 * @param   vm[in]      View manager data
 * @param   ovl[in]     Icon overlay data
 * @param   type[in]    Icon overlay type
 *
 * @return              Negative on failure
 */
static int vm_aiming_setup(view_manager_t *vm, vm_aiming_overlay_t *aiming)
{
    /* ...add overlay to rendering list */
    view_overlay_add(vm, &aiming->ovl);

    return 0;
}

/**
 * @brief   Aiming view overlay rendering function
 *
 * @param   ovl[in]         Overlay data
 * @param   texture[in]     Array of input video buffers
 * @param   ctx[in]         Rendering context
 *
 * @return                  Negative on failure
 */
static int vm_aiming_render(view_manager_t *vm, view_overlay_t *ovl, texture_data_t **texture, render_context_t *ctx)
{
    vm_aiming_overlay_t  *aiming = container_of(ovl, vm_aiming_overlay_t, ovl);

    /* ...render current mesh */
    aiming_render(vm->icon, &vm->vehicle, vm->cfg, ctx, vm->intensity);

    return 0;
}

#ifdef ENABLE_HV
/**
 * @brief   Historcial-view overlay setup function
 *
 * @param   vm[in]      View manager data
 *
 * @return              Negative on failure
 */
static int vm_hv_setup(view_manager_t *vm)
{
    cfg_data_t         *cfg = vm->cfg;
    vm_hv_overlay_t    *hv = &vm->ovl_hv;

    /* ...force overlay update */
    hv->ovl.invalidate = 1;

    /* ...add overlay to rendering list */
    view_overlay_add(vm, &hv->ovl);

    return 0;
}

/**
 * @brief   Historical-view overlay rendering function
 *
 * @param   vm[in]          View manager data
 * @param   ovl[in]         Overlay data
 * @param   texture[in]     Input textures array
 * @param   ctx[in]         Rendering context
 *
 * @return                  Negative on failure
 */
static int vm_hv_render(view_manager_t *vm, view_overlay_t *ovl, texture_data_t **texture, render_context_t *ctx)
{
    vm_hv_overlay_t  *hv = container_of(ovl, vm_hv_overlay_t, ovl);
    float32_t       (*cc)[3][3] = cc_get_coefs(vm->cc);

    /* ...render current mesh */
    hv_process(vm->hv, vm->cfg, &vm->vehicle, texture, cc);

    return 0;
}

/**
 * @brief   Historical-view overlay update function
 *
 * @param   vm[in]          View manager data
 * @param   ovl[in]         Overlay data
 *
 * @return                  Negative on failure
 */
static int vm_hv_update(view_manager_t *vm, view_overlay_t *ovl)
{
    vm_hv_overlay_t  *hv = container_of(ovl, vm_hv_overlay_t, ovl);

    /* ...push vehicle state data? - tbd */
    CHK_API(hv_update(vm->hv, vm->cfg, &vm->vehicle, vm->gen));

    return 0;
}
#endif  /* HV_ENABLE */

/*******************************************************************************
 * Internal functions definitions
 ******************************************************************************/

/**
 * @brief   Indicate completion of morphing procedure
 *
 * @param   vm[in]      View manager handle
 */
static inline void vm_morph_complete(view_manager_t *vm)
{
    /* ...indicate transition sequence is over */
    vm->transition = -1;

    /* ...clear morphing state */
    vm->morph_state = 0;

    /* ...clear morphing hook */
    vm->morph = NULL;
}

void scv_display2cam(mesh_gen_t *gen, cfg_scv_mesh_t* scv, vehicle_state_t *vehicle, float32_t uv[2], float32_t Z, float32_t v[3], const int32_t* dst);


int view_manager_world_2_cam(view_manager_t *vm, uint32_t cam_indx, const float32_t xyz[3], float32_t camera_coords[2])
{
    if (cam_indx < SV_CAMERAS_NUMBER)
    {
        camera_data_t* cam_data = mesh_gen_cameras(vm->gen);
        return mesh_gen_w2c(&cam_data[cam_indx], xyz, camera_coords);
    }

    return -1;
}

int display_to_camera_coords_scv(view_manager_t *vm, float32_t display_xy[2], float32_t camera_xy[2], uint32_t id, float32_t Z)
{
    cfg_data_t         *cfg = vm->cfg;
    cfg_ui_page_t      *page = &cfg->ui.pages[id];
    /* ...set views overlays */

    camera_xy[0] = 0.0f;
    camera_xy[1] = 0.0f;

    for (uint32_t i = 0; i < page->views_num; i++)
    {
        cfg_mesh_t         *mesh = page->views[i];
        if (mesh->base.type == MESH_SCV)
        {
            vm_mesh_overlay_t  *ovl = &vm->ovl_mesh[i];
            if (ovl->cfg)
            {

                float32_t v1[2] = {0.0f, 0.0f};
                float32_t v2[3] = {0.0f, 0.0f, 0.f};

                int32_t* dst = mesh->base.dst;
                int32_t x0 = dst[0], y0 = dst[1], x1 = dst[2], y1 = dst[3];
                float32_t pxy[2] = {display_xy[0], display_xy[1]};
                pxy[0] = ((pxy[0] - x0) / (x1 - x0))*2 - 1;
                pxy[1] = ((pxy[1] - y0) / (y1 - y0))*2 - 1;

                if (pxy[0] < -1 || pxy[0] > 1 || pxy[1] < -1 || pxy[1] > 1)
                {
                    continue;
                }

                scv_display2cam(vm->gen, &ovl->cfg->scv, &vm->vehicle, pxy, Z, v2, dst);
                camera_xy[0] = pxy[0];
                camera_xy[1] = pxy[1];

                return 0;
            }
        }
    }

    return -1;
}

/**
 * @brief   Setup screen layout; initialize all overlays
 *
 * @param   vm[in]          View manager data
 * @param   id[in]          Screen layout id
 */
static int vm_layout_setup(view_manager_t *vm, uint32_t id)
{
    cfg_data_t         *cfg = vm->cfg;
    cfg_ui_page_t      *page = &cfg->ui.pages[id];
    int                 i;
    int                 result;

    /* ...reset current overlays list */
    view_overlays_reset(vm);

    /* ...set new layout id */
    vm->layout = id;

#ifdef HV_ENABLE
    /* ...add historical view engine */
    vm_hv_setup(vm);
#endif

    /* ...set views overlays */
    for (i = 0; i < page->views_num; i++)
    {
        cfg_mesh_t         *mesh = page->views[i];
        vm_mesh_overlay_t  *ovl = &vm->ovl_mesh[i];
        CHK_API(vm_mesh_setup(vm, ovl, mesh));
    }

    /* ...prepare to setup overlay */
    uint32_t    ovl_idx[OVL_NUMBER];
    memset(ovl_idx, 0, sizeof(ovl_idx));

    /* ...set generic overlays */
    for (i = 0; i < page->ovl_num; i++)
    {
        cfg_ovl_t         **overlay;
        cfg_mesh_t         *mesh = (i < page->views_num ? page->views[i] : NULL);

        for (overlay = page->ovl[i]; *overlay != NULL; overlay++)
        {
            uint32_t    type = (*overlay)->type;
            int         k = ovl_idx[type]++;

            BUG(k >= cfg->ui.ovl_num[type], _x("invalid overlay index: page=%d, type=%u, num=%u"), i, type, cfg->ui.ovl_num[type]);

            switch (type)
            {
            case OVL_GUIDE:
                CHK_API(vm_guide_setup(vm, &vm->ovl_guide[k], mesh, &(*overlay)->guide));
                break;

            case OVL_ICON:
                CHK_API(vm_icon_setup(vm, &vm->ovl_icon[k], mesh, &(*overlay)->icon));
                break;

            case OVL_CAR:
                CHK_API(vm_car_setup(vm, &vm->ovl_car[k], mesh, &(*overlay)->car));
                break;

            case OVL_ODO:
                CHK_API(vm_od_setup(vm, &vm->ovl_odo[k], mesh, &(*overlay)->odo));
                break;

            default:
                TRACE(ERROR, _b("unknown overlay type: %u"), type);
                return -(errno = EINVAL);
            }
        }
    }

    /* ...setup aiming overlay */
    if (!strcmp(page->id, "aiming"))
    {
        vm_aiming_setup(vm, &vm->ovl_aiming);
    }

    /* ...invalidate UI layer */
    vm_ui_setup(vm);

    TRACE(INFO, _b("set layout: %d"), vm->layout);

    return 0;
}

/**
 * @brief   Morphing using fade-out; function is called from window renderer
 *          context and is setting global luminance value for rendered scene
 *
 * @param   vm[in]      View manager handle
 */
static void vm_morph_fade(view_manager_t *vm)
{
    cfg_data_t     *cfg = vm->cfg;
    uint32_t        ts = __get_time_usec();
    uint32_t        delta = ts - vm->morph_start_time;
    float32_t       t0 = (float32_t)delta / (float32_t)(cfg->vm.fadeout_duration * 1000);
    float32_t       intensity;

    if (0)
    {
        static void *data;
        static int count;
        EGLint       w, h;
        EGLDisplay  dpy = eglGetCurrentDisplay();
        EGLSurface  surface = eglGetCurrentSurface(EGL_DRAW);
        eglQuerySurface(dpy, surface, EGL_WIDTH, &w);
        eglQuerySurface(dpy, surface, EGL_HEIGHT, &h);

        if (!data)
        {
            if (w != 0 && h != 0)
            {
                data = malloc(w * h * sizeof(uint32_t));
            }
        }

        if (data)
        {
            char buffer[256];

            snprintf(buffer, sizeof(buffer), "/tmp/transition-%d-%02u.%u.%u.rgba", count++, (int)(vm->intensity * 100), w, h);
            glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, data);
            FILE *f = fopen(buffer, "wb");
            fwrite(data, w * h * 4, 1, f);
            fclose(f);
        }
    }

    TRACE(DEBUG, _b("fading: %d -> %d"), vm->layout, vm->transition);

    if (vm->morph_state == 0)
    {
        /* ...fade-out phase of morphing sequence */
        if (t0 < 0.5f)
        {
            intensity = 1.0f - 2.0f * powf(t0, 2.0f);
        }
        else if (t0 < 1.0f)
        {
            intensity = 2.0f * powf(1.0f - t0, 2.0f);
        }
        else
        {
            /* ...fade-out sequence completed; need to render at least one black screen */
            intensity = 0.0f;

            /* ...update overlays scheme for a target view (it will be rendered black) */
            vm_layout_setup(vm, vm->transition);

            /* ...switch to fade-in sequence */
            vm->morph_state = 1;
        }
    }
    else
    {
        /* ...fade-in phase of morphing sequence */
        if (t0 < 1.5f)
        {
            intensity = 2.0f * powf(t0 - 1.0f, 2.0f);
        }
        else if (t0 < 2.0f)
        {
            intensity = 1.0f - 2.0f * powf(t0 - 2.0f, 2.0f);
        }
        else
        {
            /* ...fade-in sequence completed; transition sequence is over */
            intensity = 1.0f;

            /* ...mark the transition is over */
            vm_morph_complete(vm);
        }
    }

    /* ...apply global scene intensity */
    vm->intensity = intensity;
}

#if 0
/**
 * @brief   Morphing single-camera-view to single-camera-view using LERP
 *
 * @param   vm[in]          View manager handle
 */
static void vm_morph_scv(view_manager_t *vm)
{
    cfg_data_t     *cfg = vm->cfg;
    uint32_t        ts = __get_time_usec();
    uint32_t        delta = ts - vm->morph_start_time;
    float32_t       t0 = (float32_t)delta / (float32_t)(cfg->vm.fadeout_duration * 1000 * 2);

    TRACE(DEBUG, _b("SCV-view morphing: %d -> %d"), vm->layout, vm->transition);

    /* ...make LERP operation on two configs */
    if (t0 < 1.0f)
    {
        mesh_scv_cfg_lerp(&vm->ovl_main_mesh.scv.cfg, vm->morph_src, vm->morph_dst, t0);
    }
    else
    {
        /* ...set new layout (apply destination configuration) */
        vm_layout_setup(vm, vm->transition);

        /* ...complete sequence */
        vm_morph_complete(vm);
    }

    /* ...force overlay update */
    vm->ovl_main_mesh.ovl.invalidate = 1;

    /* ...force guidelines update */
    vm->ovl_main_gl.ovl.invalidate = 1;
}

/**
 * @brief   Morphing single-camera-view to see-through-view
 *
 * @param   vm[in]          View manager handle
 */
static void vm_morph_scv_stv(view_manager_t *vm)
{
    cfg_data_t     *cfg = vm->cfg;
    uint32_t        ts = __get_time_usec();
    uint32_t        delta = ts - vm->morph_start_time;
    float32_t       t0 = (float32_t)delta / (float32_t)(cfg->vm.fadeout_duration * 1000 * 2);

    TRACE(DEBUG, _b("SCV-to-STV morphing: %d -> %d"), vm->layout, vm->transition);

    /* ...make LERP operation on two configs */
    if (t0 < 0.5f)
    {
        /* ...first stage of morphing - keep SCV view layout */
        mesh_scv_stv_cfg_lerp_out(&vm->ovl_main_mesh.scv.cfg, vm->morph_src, vm->morph_dst, t0);
    }
    else
    {
        /* ...second stage of morphing - STV scheme is active */
        if (vm->morph_state == 0)
        {
            /* ...first stage of transition is complete; update overlays scheme for an STV view */
            vm_layout_setup(vm, vm->transition);

            /* ...switch to next state */
            vm->morph_state = 1;
        }

        /* ...update destination configuration (only virtual camera position) */
        mesh_scv_stv_cfg_lerp_in(&vm->ovl_main_mesh.stv.cfg, vm->morph_src, vm->morph_dst, MIN(t0, 1.0f));

        /* ...finish morphing scheme as needed */
        if (t0 >= 1.0f)
        {
            /* ...complete morphing sequence */
            vm_morph_complete(vm);
        }
    }

    /* ...force overlay update */
    vm->ovl_main_mesh.ovl.invalidate = 1;

    /* ...force guidelines update */
    vm->ovl_main_gl.ovl.invalidate = 1;

    /* ...force car model update */
    vm->ovl_car_stv.ovl.invalidate = 1;
}

/**
 * @brief   Morphing see-through-view to single-camera-view
 *
 * @param   vm[in]          View manager handle
 */
static void vm_morph_stv_scv(view_manager_t *vm)
{
    cfg_data_t     *cfg = vm->cfg;
    uint32_t        ts = __get_time_usec();
    uint32_t        delta = ts - vm->morph_start_time;
    float32_t       t0 = (float32_t)delta / (float32_t)(cfg->vm.fadeout_duration * 1000 * 2);

    TRACE(DEBUG, _b("STV-to-SCV morphing: %d -> %d"), vm->layout, vm->transition);

    /* ...make LERP operation on two configs */
    if (t0 < 0.5f)
    {
        /* ...first stage of morphing - keep STV view layout */
        mesh_stv_scv_cfg_lerp_out(&vm->ovl_main_mesh.stv.cfg, vm->morph_src, vm->morph_dst, t0);
    }
    else
    {
        /* ...second stage of morphing - switch to SCV scheme */
        if (vm->morph_state == 0)
        {
            /* ...first stage of transition is complete; update overlays scheme for a target view */
            vm_layout_setup(vm, vm->transition);

            /* ...switch to next state */
            vm->morph_state = 1;
        }

        /* ...update view configuration (virtual camera parameters only) */
        mesh_stv_scv_cfg_lerp_in(&vm->ovl_main_mesh.scv.cfg, vm->morph_src, vm->morph_dst, MIN(t0, 1.0f));

        /* ...finish morphing scheme as needed */
        if (t0 >= 1.0f)
        {
            /* ...complete morphing sequence */
            vm_morph_complete(vm);
        }
    }

    /* ...force overlay update */
    vm->ovl_main_mesh.ovl.invalidate = 1;

    /* ...force guidelines update */
    vm->ovl_main_gl.ovl.invalidate = 1;

    /* ...force car model update */
    vm->ovl_car_stv.ovl.invalidate = 1;
}

/**
 * @brief   Morphing see-through-view to side-view
 *
 * @param   vm[in]          View manager handle
 */
static void vm_morph_stv_side(view_manager_t *vm)
{
    /* ...for the time being use just that same fading to black - tbd */
    vm_morph_fade(vm);
}

/**
 * @brief   Morphing see-through-view to see-through-view
 *
 * @param   vm[in]          View manager handle
 */
static void vm_morph_stv_stv(view_manager_t *vm)
{
    cfg_data_t     *cfg = vm->cfg;
    uint32_t        ts = __get_time_usec();
    uint32_t        delta = ts - vm->morph_start_time;
    float32_t       t0 = (float32_t)delta / (float32_t)(cfg->vm.fadeout_duration * 1000 * 2);

    TRACE(DEBUG, _b("STV-view morphing: %d -> %d"), vm->layout, vm->transition);

#if 0
    /* ...check for a completion of first stage? */
    if (t0 >= 0.5f && vm->morph_state == 0)
    {
        vm->morph_state = 1;

        /* ...switch to new layout in the middle of transition? */
        vm_layout_setup(vm, vm->transition);
    }

    /* ...make LERP operation on two configs */
    mesh_stv_cfg_lerp(&vm->ovl_main_mesh.stv.cfg, vm->morph_src, vm->morph_dst, MIN(t0, 1.0f));

    /* ...complete morph sequence */
    if (t0 > 1.0f)
    {
        /* ...complete sequence */
        vm_morph_complete(vm);
    }
#else

    mesh_stv_cfg_lerp(&vm->ovl_main_mesh.stv.cfg, vm->morph_src, vm->morph_dst, MIN(t0, 1.0f));

    if (vm->morph_state == 0 && t0 >= 0.5f)
    {
        /* ...switch to new layout at the middle of transition */
        vm_layout_setup(vm, vm->transition);

        vm->morph_state = 1;
    }
    else if (t0 >= 1.0f)
    {
        /* ...complete sequence */
        vm_morph_complete(vm);
    }
#endif

    /* ...force overlay update */
    vm->ovl_main_mesh.ovl.invalidate = 1;

    /* ...force guidelines update */
    vm->ovl_main_gl.ovl.invalidate = 1;

    /* ...force car overlay update */
    vm->ovl_car_stv.ovl.invalidate = 1;
}
#endif

/**
 * @brief   Start transition to next screen layout
 *
 * @param   vm[in]          View manager handle
 * @param   id[in]          Target screen layout id
 *
 * @return                  Negative on failure
 */
static int view_manager_change_layout(view_manager_t *vm, uint32_t id)
{
    cfg_data_t     *cfg = vm->cfg;

    /* ...check for transitions animation flag */
    if (!cfg->vm.enable_animation)
    {
        /* ...instantly apply new layout without any transition */
        vm->intensity = 1.0f;

        return vm_layout_setup(vm, id);
    }

#if 0
    /* ...select destination layout configuration */
    vm->morph_src = vm_select_layout_cfg(vm->layout, cfg);
    vm->morph_dst = vm_select_layout_cfg(id, cfg);
#endif

    if (1)
    {
        /* ...force all transitions to go through black screen */
        vm->morph = vm_morph_fade;
    }

    /* ...prepare morphing sequence */
    vm->transition = id;
    vm->morph_start_time = __get_time_usec();

    TRACE(INFO, _b("layout transition: %d -> %d"), vm->layout, vm->transition);

    return 0;
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Get vehicle state data pointer
 *
 * @param   vm[in]          View manager handle
 *
 * @return                  Vehicle state data pointer
 */
vehicle_state_t * vm_get_vehicle_state(view_manager_t *vm)
{
    return &vm->vehicle;
}

/**
 * @brief   Get mesh-generator data pointer
 *
 * @param   vm[in]          View manager handle
 *
 * @return                  Mesh generator handle
 */
mesh_gen_t * vm_get_mesh_gen(view_manager_t *vm)
{
    return vm->gen;
}


/**
 * @brief   Lock access to view manager internal data
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_lock(view_manager_t *vm)
{
    pthread_mutex_lock(&vm->lock);
}

/**
 * @brief   Unlock access to view manager internal data
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_unlock(view_manager_t *vm)
{
    pthread_mutex_unlock(&vm->lock);
}

/**
 * @brief   Set screen layout
 *
 * @param   vm[in]          View manager handle
 * @param   layout[in]      Screen layout code (UI page identifier)
 *
 * @return                  Negative on failure
 */
int view_manager_set_layout(view_manager_t *vm, int32_t layout)
{
    cfg_data_t     *cfg = vm->cfg;

    /* ...sanity check */
    if ((uint32_t)layout >= (uint32_t)cfg->ui.pages_num)
    {
        TRACE(ERROR, _x("invalid layout code: %d"), layout);
        return -(errno = EINVAL);
    }

    /* ...check if transition to next layout is active */
    if (vm->transition >= 0)
    {
        if (vm->layout == vm->transition)
        {
            /* ...new layout has been applied already; instantly apply new layout */
            vm_layout_setup(vm, layout);
        }

        /* ...set new transition target */
        vm->transition = layout;

        return 0;
    }

    /* ...ignore transition to the same layout */
    if (layout == vm->layout)
    {
        TRACE(DEBUG, _b("ignore transition to same layout"));
        return 0;
    }

    /* ...start transition to next view */
    return view_manager_change_layout(vm, layout);
}

/**
 * @brief   Update all enabled overlays
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_update_overlays(view_manager_t *vm)
{
    __list_t       *render = &vm->render;
    __list_t       *obj;

    /* ...render all objects with current settings */
    for (obj = list_first(render); obj != list_null(render); obj = list_next(render, obj))
    {
        view_overlay_t     *ovl = container_of(obj, view_overlay_t, link);

        ovl->invalidate = 1;
    }
}

/**
 * @brief   Update color-correction module parameters
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_update_cc(view_manager_t *vm)
{
    /* ...force points regeneration? - sounds too strong */
    vm->cc_invalidate = 1;
}

/**
 * @brief   Update guide-lines overlays
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_update_guide(view_manager_t *vm)
{
    vehicle_state_t    *vehicle = &vm->vehicle;
    cfg_data_t         *cfg = vm->cfg;
    float32_t           steering = vehicle->steering;
    float32_t          *coef = cfg->vehicle.steering_coef;
    int                 i;

    /* ...calculate wheel angle */
    if (fabsf(steering) < 1.0f)
    {
        vehicle->wheel_angle = 0.0f;
    }
    else if (steering < 0.0f)
    {
        vehicle->wheel_angle = -coef[0] + coef[1] * steering - coef[2] * steering * steering;
    }
    else
    {
        vehicle->wheel_angle = coef[0] + coef[1] * steering + coef[2] * steering * steering;
    }

    __list_t       *render = &vm->render;
    __list_t       *obj;

    for (obj = list_first(render); obj != list_null(render); obj = list_next(render, obj))
    {
        view_overlay_t     *ovl = container_of(obj, view_overlay_t, link);

        if (ovl->type == OVL_GUIDE)
        {
            ovl->invalidate = 1;
        }
        else if (ovl->type == OVL_ICON)
        {
            if (((vm_icon_overlay_t*)ovl)->type == ICON_OVL_CAR_TV)
            {
                ovl->invalidate = 1;
            }
        }
        else if (ovl->type == OVL_NUMBER)
        {
            if (((vm_mesh_overlay_t *)ovl)->cfg->base.type == MESH_SCV)
            {
                ovl->invalidate = 1;
            }
        }
    }
}

/**
 * @brief   Update car model overlay
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_update_car_model(view_manager_t *vm)
{
    int     i;

    for (i = 0; i < vm->cfg->ui.ovl_num[OVL_CAR]; i++)
    {
        vm->ovl_car[i].ovl.invalidate = 1;
    }
}

/**
 * @brief   Update PAS state
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_update_pas(view_manager_t *vm)
{
    int     i;

    for (i = 0; i < vm->cfg->ui.ovl_num[OVL_ICON]; i++)
    {
        uint32_t    type = vm->ovl_icon[i].type;

        if (type == ICON_OVL_CAR_TV || type == ICON_OVL_CAR_SV)
        {
            vm->ovl_icon[i].ovl.invalidate = 1;
        }
    }

    for (i = 0; i < vm->cfg->ui.ovl_num[OVL_ODO]; i++)
    {
        vm->ovl_odo[i].ovl.invalidate = 1;
    }
}

/**
 * @brief   Update AP state
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_update_ap(view_manager_t *vm)
{
    int     i;

    for (i = 0; i < vm->cfg->ui.ovl_num[OVL_ICON]; i++)
    {
        uint32_t    type = vm->ovl_icon[i].type;

        if (type == ICON_PDT_SONAR)
        {
            vm->ovl_icon[i].ovl.invalidate = 1;
        }
    }
}

/**
 * @brief   Update CTA state
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_update_cta(view_manager_t *vm)
{
    int     i;

    for (i = 0; i < vm->cfg->ui.ovl_num[OVL_ICON]; i++)
    {
        uint32_t    type = vm->ovl_icon[i].type;

        if (type == ICON_OVL_CTA_FRONT || type == ICON_OVL_CTA_REAR || type == ICON_OVL_CTA_SIDE)
        {
            vm->ovl_icon[i].ovl.invalidate = 1;
        }
    }
}

/**
 * @brief   Update aiming error overlay state
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_update_aiming_error(view_manager_t *vm)
{
    //vm->ovl_aiming_error.ovl.invalidate = 1;
}

/**
 * @brief   Update ODO state
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_update_odo(view_manager_t *vm)
{
    int     i;

    for (i = 0; i < vm->cfg->ui.ovl_num[OVL_ODO]; i++)
    {
        vm->ovl_odo[i].ovl.invalidate = 1;
    }
}

/**
 * @brief   Update THA state
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_update_tha(view_manager_t *vm)
{
    int     i;

    for (i = 0; i < vm->cfg->ui.ovl_num[OVL_ICON]; i++)
    {
        uint32_t    type = vm->ovl_icon[i].type;

        if (type == ICON_OVL_HITCH || type == ICON_OVL_COUPLER)
        {
            vm->ovl_icon[i].ovl.invalidate = 1;
        }
    }
}

/**
 * @brief   Update TRSC state
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_update_trsc(view_manager_t *vm)
{
    int     i;

    for (i = 0; i < vm->cfg->ui.ovl_num[OVL_ICON]; i++)
    {
        uint32_t    type = vm->ovl_icon[i].type;

        if (type >= ICON_OVL_TRSC_SVC && type <= ICON_OVL_TRSC_TRG_C)
        {
            vm->ovl_icon[i].ovl.invalidate = 1;
        }
    }
}

/**
 * @brief   Update UI state
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_update_ui(view_manager_t *vm)
{
    vm->ovl_ui.ovl.invalidate = 1;
}

/**
 * @brief   Update cameras configuration
 *
 * @param   vm[in]          View manager handle
 */
void view_manager_update_cameras(view_manager_t *vm)
{
    cfg_data_t     *cfg = vm->cfg;
    int             i;

    /* ...update mesh generator parameters */
    mesh_gen_camera_setup(vm->gen, cfg->camera);

    /* ...force meshes regeneration */
    for (i = 0; i < cfg->ui.views_num; i++)
    {
        vm->ovl_mesh[i].ovl.invalidate = 1;
    }

    /* ...invalidate all algo-views */
    algo_view_invalidate_all();
}

void view_manager_raw_2_world_rear(view_manager_t *vm, float32_t raw_x, float32_t raw_y, int32_t refWorld_z, float32_t result_xy[2])
{
    float32_t cam_point[2] = {raw_x, raw_y};

    float32_t world_xyz[3] = {0,0,0};
    undistort_kannala_gen(world_xyz, cam_point, vm->gen, SV_CAMERA_REAR, refWorld_z);
    result_xy[0] = world_xyz[0];
    result_xy[1] = world_xyz[1];
}

void view_manager_raw_2_world_3D_rear_for_tha( float32_t raw_x, float32_t raw_y, int32_t refWorld_z, float32_t result_xyz[3])
{
    float32_t cam_point[2] = {raw_x, raw_y};

    float32_t world_xyz[3] = {0,0,0};
    undistort_kannala_gen_camera(world_xyz, cam_point, refWorld_z);
    result_xyz[0] = world_xyz[0];
    result_xyz[1] = world_xyz[1];
    result_xyz[2] = world_xyz[2];
}

//Converts Real world cordinates to raw cordinates normalized in (0,1)normalization format
//it accepts inputs world x,y,z cordinates in ISO(rear axle) format
int32_t view_manager_world_2_raw_v_rear_tha(const float32_t world_xyz[3], float32_t raw_coords[2])
{
    uint32_t cam_indx = SV_CAMERA_REAR; //REAR cam for THA

    if (cam_indx < SV_CAMERAS_NUMBER)
    {
        return mesh_gen_w2c_camera(cam_indx, world_xyz, raw_coords);
    }

    return -1;
}

int view_manager_mouse_tha(view_manager_t *vm, int32_t x, int32_t y)
{
    uint32_t i;

    uint32_t clicked = 0;

    cfg_data_t *cfg = vm->cfg;

    if (vm->layout == 28)
    {
        for (i = 0; i < cfg->ui.ovl_num[OVL_GUIDE]; i++)
        {
            uint32_t    type = vm->ovl_guide[i].type;
            vm_guide_overlay_t* guide = &vm->ovl_guide[i];

            if (type == GUIDE_THA)
            {

                if (vm->vehicle.tha_gl_enable != 0)
                {
                    float32_t d[2] = {x, y};
                    float32_t dr[2] = {0,0};
                    display_to_camera_coords_scv(vm, d, dr, vm->layout, vm->cfg->guide.tha.offset[2]);

                    float32_t world_xyz[3] = {0,0,0};
                    
                    undistort_kannala_gen(world_xyz, dr, vm->gen, SV_CAMERA_REAR, 0);
                    world_xyz[2] = vm->cfg->guide.tha.offset[2];

                    TRACE(1, _b("COORDS x=%d y=%d d[0]=%f d[1]=%f"), x, y, dr[0]*1920, dr[1]*1280);
                    TRACE(1, _b("WORLD x=%f y=%f z=%f"), world_xyz[0], world_xyz[1], world_xyz[2]);

                    clicked = tha_check(cfg, &vm->vehicle, world_xyz);
                    TRACE(0, _b("CLICKED %d"), clicked);
                }
            }
        }
    }
/// example how to convert display coordinates to camera coordinates
#if 0
    {
        float32_t d[2] = {x, y};
        float32_t dr[2] = {0,0};
        display_to_camera_coords_scv(vm, d, dr, vm->layout, 0);

        float32_t world_xyz[3] = {0,0,0};
        undistort_kannala_gen(world_xyz, dr, vm->gen, SV_CAMERA_REAR, 0);

        TRACE(1, _b("COORDS x=%d y=%d d[0]=%f d[1]=%f"), x, y, dr[0]*1920, dr[1]*1280);
        TRACE(1, _b("WORLD x=%f y=%f z=%f"), world_xyz[0], world_xyz[1], world_xyz[2]);

    }
#endif

    if (clicked)
    {
        vm->vehicle.mouse_zoom_x = x;
        vm->vehicle.mouse_zoom_y = y;
        // view_manager_set_layout(vm, 33); /*Note sequence of views has been updated*/
    }

    return clicked;
}



int view_manager_mouse_get_coord(view_manager_t *vm, int32_t x, int32_t y, float32_t result_xy[2])
{
    uint32_t ret = 0;

    cfg_data_t *cfg = vm->cfg;

    float32_t d[2] = {x, y};
    float32_t dr[2] = {0,0};
    ret = display_to_camera_coords_scv(vm, d, dr, vm->layout, 0);

    TRACE(1, _b("COORDS x=%d y=%d d[0]=%f d[1]=%f"), x, y, dr[0]*1920, dr[1]*1280);

    result_xy[0] = vm->cfg->camera[0].resolution[0]*dr[0];
    result_xy[1] = vm->cfg->camera[0].resolution[1]*dr[1];

    return ret;
}

/*******************************************************************************
 * UI hook
 ******************************************************************************/

#ifdef  BUILD_NATIVE
int view_manager_mouse_event(view_manager_t *vm, int32_t x, int32_t y, uint32_t button, uint32_t state)
{
    cfg_data_t     *cfg = vm->cfg;
    __list_t       *render = &vm->render;
    __list_t       *obj;
    int             done = 0;

    /* ...render all objects with current settings */
    for (obj = list_first(render); obj != list_null(render); obj = list_next(render, obj))
    {
        view_overlay_t     *ovl = container_of(obj, view_overlay_t, link);

        if (ovl->type == OVL_CAR)
        {
            cfg_stv_mesh_t  *stv = container_of(ovl, vm_car_overlay_t, ovl)->stv;
            int32_t         *dst = stv->base.dst;

            if (x >= dst[0] && x <= dst[2] && y >= dst[1] && y <= dst[3])
            {
                if (scene_stv_mouse_event(stv, &cfg->scene_params_mouse, x, y, button, state))
                {
                    /* ...force update of the mesh/car - now update everything - tbd */
                    view_manager_update_overlays(vm);
                }
            }
        }
    }

    return done;
}
#elif USE_GESTURES_FRAMEWORK
int view_manager_gesture_event(view_manager_t *vm, void *data, int async)
{
    cfg_data_t     *cfg = vm->cfg;
    __list_t       *render = &vm->render;
    __list_t       *obj;
    int             done = 0;

    /* ...render all objects with current settings */
    for (obj = list_first(render); obj != list_null(render); obj = list_next(render, obj))
    {
        view_overlay_t     *ovl = container_of(obj, view_overlay_t, link);

        if (ovl->type == OVL_CAR)
        {
            cfg_stv_mesh_t  *stv = container_of(ovl, vm_car_overlay_t, ovl)->stv;
            if (scene_stv_touch_event(stv, &cfg->scene_params_touch, data, async))
            {
                /* ...force update of the mesh/car */
                view_manager_update_overlays(vm);
                done = 1;
            }
        }
    }

    if (!done)
    {
        int32_t     action;

        /* ...process button state change */
        if (ui_gesture_process(vm->ui, cfg, data, async, &action) != 0)
        {
            if (action >= 0)
            {
                uint32_t        id = (action == 0 ? vm->prev_page : action - 1);

                /* ...set views layout */
                view_manager_set_layout(vm, id);

                /* ...force redraw of UI overlay */
                done = 1;
            }
        }
    }

    return done;
}
#else
/**
 * @param   Process CAN-input event
 *
 * @param   vm[in]          View-manager data
 * @param   x[in]           Current touch reference position, X-coordinate
 * @param   y[in]           Current touch reference position, Y-coordinate
 * @param   off_x[in]       Current offset from reference position, X-coordinate
 * @param   off_y[in]       Current offset from reference position, Y-coordinate
 * @param   stop[in]        Stop event reception
 *
 * @return                  Processing status
 */
int view_manager_input_event(view_manager_t *vm, int32_t x, int32_t y, int32_t dx, int32_t dy, uint32_t stop)
{
    cfg_data_t     *cfg = vm->cfg;
    __list_t       *render = &vm->render;
    __list_t       *obj;
    int             done = 0;

    /* ...render all objects with current settings */
    for (obj = list_first(render); obj != list_null(render); obj = list_next(render, obj))
    {
        view_overlay_t     *ovl = container_of(obj, view_overlay_t, link);

        if (ovl->type == OVL_CAR)
        {
            cfg_stv_mesh_t  *stv = container_of(ovl, vm_car_overlay_t, ovl)->stv;

            if (scene_stv_input_event(stv, &cfg->scene_params_touch, x, y, dx, dy, stop))
            {
                /* ...force update of the mesh/car */
                view_manager_update_overlays(vm);
                done = 1;
            }
        }
    }

    if (!done)
    {
        int32_t     action;

        /* ...process button state change */
        if (ui_input_process(vm->ui, cfg, x, y, dx, dy, stop, &action) != 0)
        {
            if (action >= 0)
            {
                uint32_t        id = (action == 0 ? vm->prev_page : action - 1);

                /* ...set views layout */
                view_manager_set_layout(vm, id);
                done = 1;
            }
        }
    }

    if (!done && stop)
    {
        done = view_manager_mouse_tha(vm, x, y);
    }

    return done;
}
#endif

#if BUILD_NATIVE
/**
 * @brief   Menu-processing event (touch/mouse)
 */
int view_manager_touch_event(view_manager_t *vm, int32_t x, int32_t y)
{
    cfg_data_t *cfg = vm->cfg;
    int32_t     action;
    int         update = 0;

    /* ...process button state change */
    if (ui_touch_process(vm->ui, cfg, x, y, &action) != 0)
    {
        if (action >= 0)
        {
            uint32_t        id = (action == 0 ? vm->prev_page : action - 1);

            /* ...set views layout */
            view_manager_set_layout(vm, id);

            /* ...force redraw of UI overlay */
            update = 1;
        }
    }

    if (update == 0)
        update = view_manager_mouse_tha(vm, x, y);

    return update;
}
#endif

/*******************************************************************************
 * Entry point
 ******************************************************************************/

/**
 * @brief   Create view manager
 *
 * @param   cfg[in]         Configuration data pointer
 *
 * @return                  View manager handle, or NULL on failure
 */
view_manager_t * view_manager_create(cfg_data_t *cfg)
{
    view_manager_t     *vm;
    int                 i;

    /* ...allocate view manager data */
    CHK_ERR(vm = calloc(1, sizeof(*vm)), NULL);

    /* ...save global configuration pointer */
    vm->cfg = cfg;

    /* ...initialize mesh generator */
    if ((vm->gen = mesh_gen_create(cfg)) == NULL)
    {
        TRACE(ERROR, _x("failed to create mesh generator: %s"), strerror(errno));
        goto error;
    }

    view_manager_update_cameras(vm);
    
    /* ...initialize color-correction module */
    if ((vm->cc = cc_data_create(cfg, mesh_gen_cameras(vm->gen))) == NULL)
    {
        TRACE(ERROR, _x("failed to create color-correction module: %s"), strerror(errno));
        goto error;
    }

#ifdef HV_ENABLE
    /* ...initialize historical-view module */
    if ((vm->hv = hv_create(cfg)) == NULL)
    {
        TRACE(ERROR, _x("failed to create historical-view module: %s"), strerror(errno));
        goto error;
    }

    vm->ovl_hv.ovl.type = OVL_HV;
    vm->ovl_hv.ovl.render = vm_hv_render;
    vm->ovl_hv.ovl.update = vm_hv_update;
#endif

    vm->ovl_aiming.ovl.render = vm_aiming_render;
    vm->ovl_aiming.ovl.update = NULL;

    vm->ovl_ui.ovl.render = vm_ui_render;
    vm->ovl_ui.ovl.update = vm_ui_update;

    /* ...enable color-correction by default */
    //cfg->cc.enable = 0;

    /* ...icon resources loading */
    if ((vm->icon = icons_load(cfg)) == NULL)
    {
        TRACE(ERROR, _x("failed to load icons resources: %s"), strerror(errno));
    }

    /* ...initialize guidelines generator */
    if ((vm->gg = guide_gen_create(vm->icon)) == NULL)
    {
        TRACE(ERROR, _x("failed to create guidelines generator: %s"), strerror(errno));
        goto error;
    }

    /* ...car model loading */
    if ((vm->car_model = car_model_load(cfg, vm->icon)) == NULL)
    {
        TRACE(ERROR, _x("failed to create car model overlay"));
    }

    /* ...UI creation */
    if ((vm->ui = ui_create(cfg, &vm->vehicle)) == NULL)
    {
        TRACE(ERROR, _x("failed to create UI: %s"), strerror(errno));
    }

    /* ...create mesh overlays array */
    if ((vm->ovl_mesh = calloc(cfg->ui.views_num, sizeof(*vm->ovl_mesh))) == NULL)
    {
        TRACE(ERROR, _x("failed to create mesh overlays"));
        goto error;
    }

    for (i = 0; i < cfg->ui.views_num; i++)
    {
        vm_mesh_overlay_t  *ovl = &vm->ovl_mesh[i];
        ovl->ovl.type = OVL_NUMBER;
        ovl->ovl.render = vm_mesh_render;
        ovl->ovl.update = vm_mesh_update;
    }

    /* ...create guidelines overlays array */
    if (cfg->ui.ovl_num[OVL_GUIDE] > 0)
    {
        if ((vm->ovl_guide = calloc(cfg->ui.ovl_num[OVL_GUIDE], sizeof(*vm->ovl_guide))) == NULL)
        {
            TRACE(ERROR, _x("failed to allocate %u overlays"), cfg->ui.ovl_num[OVL_GUIDE]);
            goto error;
        }
    }

    for (i = 0; i < cfg->ui.ovl_num[OVL_GUIDE]; i++)
    {
        vm_guide_overlay_t  *ovl = &vm->ovl_guide[i];

        ovl->ovl.type = OVL_GUIDE;
        ovl->ovl.render = vm_guide_render;
        ovl->ovl.update = vm_guide_update;
    }

    /* ...create generic icon overlays */
    if (cfg->ui.ovl_num[OVL_ICON] > 0)
    {
        if ((vm->ovl_icon = calloc(cfg->ui.ovl_num[OVL_ICON], sizeof(*vm->ovl_icon))) == NULL)
        {
            TRACE(ERROR, _x("failed to allocate %u overlays"), cfg->ui.ovl_num[OVL_ICON]);
            goto error;
        }
    }

    for (i = 0; i < cfg->ui.ovl_num[OVL_ICON]; i++)
    {
        vm_icon_overlay_t  *ovl = &vm->ovl_icon[i];

        ovl->ovl.type = OVL_ICON;
        ovl->ovl.render = vm_icon_render;
        ovl->ovl.update = vm_icon_update;
    }

    /* ...create car model overlays */
    if (cfg->ui.ovl_num[OVL_CAR] > 0)
    {
        if ((vm->ovl_car = calloc(cfg->ui.ovl_num[OVL_CAR], sizeof(*vm->ovl_car))) == NULL)
        {
            TRACE(ERROR, _x("failed to allocate %u overlays"), cfg->ui.ovl_num[OVL_CAR]);
            goto error;
        }
    }

    for (i = 0; i < cfg->ui.ovl_num[OVL_CAR]; i++)
    {
        vm_car_overlay_t  *ovl = &vm->ovl_car[i];

        ovl->ovl.type = OVL_CAR;
        ovl->ovl.render = vm_car_render;
        ovl->ovl.update = vm_car_update;
    }

    /* ...create generic icon overlays */
    if (cfg->ui.ovl_num[OVL_ODO] > 0)
    {
        if ((vm->ovl_odo = calloc(cfg->ui.ovl_num[OVL_ODO], sizeof(*vm->ovl_odo))) == NULL)
        {
            TRACE(ERROR, _x("failed to allocate %u overlays"), cfg->ui.ovl_num[OVL_ODO]);
            goto error;
        }
    }

    for (i = 0; i < cfg->ui.ovl_num[OVL_ODO]; i++)
    {
        vm_od_overlay_t  *ovl = &vm->ovl_odo[i];

        ovl->ovl.type = OVL_ODO;
        ovl->ovl.render = vm_od_render;
        ovl->ovl.update = vm_od_update;
    }

    /* ...initialize heartbeat timer */
    vm->heartbeat_ts = __get_time_usec();

    /* ...clear active transition flag */
    vm->transition = vm->layout = -1;

    /* ...set default screen layout */
    if (view_manager_set_layout(vm, cfg->vm.default_layout) < 0)
    {
        /* ...shall we die here? the error is sort of fatal - tbd */
        TRACE(ERROR, _x("failed to set screen layout %d: %m"), cfg->vm.default_layout);
    }

    /* ...disable blind-spot mask */
    cfg->car_render.mask_disable = 1;

    /* ...enable animations */
    cfg->vm.enable_animation = 0;

    /* ...enable labels by default */
    vm->vehicle.label_enable = 1;
    vm->vehicle.check_enable = 1;
    vm->vehicle.exit_enable = 0;
    vm->vehicle.trsc_red_enable = 1;
    vm->vehicle.trsc_orange_enable = 1;

    vm->vehicle.more_icon = 0;
    vm->vehicle.more_icon_text = 0;
    vm->vehicle.bottombutton_tvfv = 0;
    vm->vehicle.bottombutton_tvrv = 0;
    vm->vehicle.bottombutton_rcpv = 0;
    vm->vehicle.bottombutton_fcpv = 0;
    vm->vehicle.bottombutton_burv = 0;
    vm->vehicle.bottombutton_ffcv = 0;
    vm->vehicle.bottombutton_aux = 0;

    /* ...create lock */
    pthread_mutex_init(&vm->lock, NULL);

    /* ...load debug font */
    //vm->font = font_load("open-sans.bin");
    vm->font = font_load("open-serif-bold.bin");

    return vm;

error:
    /* ...destroy mesh generator */
    //(vm->gen ? mesh_gen_destroy(vm->gen) : 0);

    /* ...release memory data */
    free(vm);

    return NULL;
}

/**
 * @brief   Mirror destination tile
 *
 * @param   dst[in, out]        Pointer to destination tile
 * @param   width[in]           Display width
 */
static inline void cfg_mirror_dst(int32_t *dst, int32_t width)
{
    int32_t     x0 = dst[0], x1 = dst[2];

    dst[0] = width - x1;
    dst[2] = width - x0;
}

/**
 * @brief   Shift destination tile
 *
 * @param   dst[in, out]        Pointer to destination tile
 * @param   dx[in]              Horizontal offset
 */
static inline void cfg_shift_dst(int32_t *dst, int32_t dx)
{
    dst[0] += dx;
    dst[2] += dx;
}

// /**
//  * @brief   Mirror sonar configuration
//  *
//  * @param   sonar[in, out]      Sonar configuration
//  * @param   width[in]           Display width
//  */
// static void cfg_mirror_sonar(cfg_sonar_t *sonar, int32_t width)
// {
//     int32_t sonar_car_model_dst[4] = {0};
//     memcpy(sonar_car_model_dst, sonar->sonar_car_model_dst[cfg_get_body_length_variant(cfg)], sizeof(sonar_car_model_dst));

//     int32_t     x0 = sonar_car_model_dst[0];
//     int32_t     x1 = sonar_car_model_dst[2];
//     int32_t     dx = width - x1 - x0;

//     cfg_shift_dst(sonar_car_model_dst, dx);
//     cfg_shift_dst(sonar->sonar_fl_wheel_dst, dx);
//     cfg_shift_dst(sonar->sonar_fr_wheel_dst, dx);
//     cfg_shift_dst(sonar->sonar_rl_wheel_dst, dx);
//     cfg_shift_dst(sonar->sonar_rr_wheel_dst, dx);
//     cfg_shift_dst(sonar->sonar_fc_pas_dst, dx);
//     cfg_shift_dst(sonar->sonar_fr_pas_dst, dx);
//     cfg_shift_dst(sonar->sonar_fl_pas_dst, dx);
//     cfg_shift_dst(sonar->sonar_rc_pas_dst, dx);
//     cfg_shift_dst(sonar->sonar_rr_pas_dst, dx);
//     cfg_shift_dst(sonar->sonar_rl_pas_dst, dx);
//     cfg_shift_dst(sonar->sonar_fc_failure_dst, dx);
//     cfg_shift_dst(sonar->sonar_fr_failure_dst, dx);
//     cfg_shift_dst(sonar->sonar_fl_failure_dst, dx);
//     cfg_shift_dst(sonar->sonar_rc_failure_dst, dx);
//     cfg_shift_dst(sonar->sonar_rr_failure_dst, dx);
//     cfg_shift_dst(sonar->sonar_rl_failure_dst, dx);
//     cfg_mirror_dst(sonar->sonar_pas_off_dst, width);
//     cfg_shift_dst(sonar->sonar_pas_failure_dst, dx);
// }

/**
 * @brief   Mirror CTA configuration
 *
 * @param   cta[in, out]        CTA indicators configuration
 * @param   width[in]           Display width
 */
static void cfg_mirror_cta(cfg_cta_t *cta, int32_t width)
{
    int32_t     x0 = cta->cta_left_outer_dst[0];
    int32_t     x1 = cta->cta_right_outer_dst[2];
    int32_t     dx = width - x1 - x0;

    cfg_shift_dst(cta->cta_left_outer_dst, dx);
    cfg_shift_dst(cta->cta_left_inner_dst, dx);
    cfg_shift_dst(cta->cta_right_outer_dst, dx);
    cfg_shift_dst(cta->cta_right_inner_dst, dx);
}

/**
 * @brief   Mirror CTA configuration
 *
 * @param   cta[in, out]        CTA indicators configuration
 * @param   width[in]           Display width
 */
static void cfg_mirror_aiming(cfg_aiming_error_t *aiming, int32_t width)
{
    int32_t     dx1 = width - aiming->tv_dst[0][2] - aiming->tv_dst[0][0];
    int32_t     dx2 = width - aiming->nc_dst[0][2] - aiming->nc_dst[0][0];
    int32_t     dx4 = width - aiming->sc_dst[0][2] - aiming->sc_dst[0][0];
    int         i;

    for (i = 0; i < 4; i++)
    {
        cfg_shift_dst(aiming->tv_dst[i], dx1);
        cfg_shift_dst(aiming->nc_dst[i], dx2);
    }

    cfg_shift_dst(aiming->sc_dst[0], dx4);
}

/**
 * @brief   Adjust configuration with respect to steering position
 *
 * @param   vm[in]              View-manager data
 * @param   cfg[in]             Configuration data
 * @param   steering_lhd[in]    Steering position
 */
void view_manager_set_steering_position(view_manager_t *vm, uint32_t steering_lhd)
{
    cfg_data_t     *cfg = vm->cfg;

#if 0
    if (cfg->vehicle.steering_lhd != steering_lhd)
    {
        int32_t     width = cfg->vm.width;

        /* ...mirror destination tile */
        cfg_mirror_dst(cfg->vm.front_view.dst, width);
        cfg_mirror_dst(cfg->vm.front_wide_view.dst, width);
        cfg_mirror_dst(cfg->vm.rear_view.dst, width);
        cfg_mirror_dst(cfg->vm.rear_sonar_view.dst, width);
        cfg_mirror_dst(cfg->vm.rear_wide_view.dst, width);
        cfg_mirror_dst(cfg->vm.front_stv.dst, width);
        cfg_mirror_dst(cfg->vm.rear_stv.dst, width);
        cfg_mirror_dst(cfg->vm.front_tv.dst, width);
        cfg_mirror_dst(cfg->vm.rear_tv.dst, width);

        /* ...mirror sonar icons */
        cfg_mirror_sonar(&cfg->vm.sonar_tv, width);
        cfg_mirror_sonar(&cfg->vm.sonar_sc, width);

        /* ...mirror CTA indicators */
        cfg_mirror_cta(&cfg->vm.cta_main, width);
        cfg_mirror_cta(&cfg->vm.cta_sonar, width);

        /* ...mirror aiming error icons */
        cfg_mirror_aiming(&cfg->vm.aiming_error, width);

        cfg->vehicle.steering_lhd = steering_lhd;

        /* ...force update of all views/overlays */
        vm_layout_setup(vm, vm->layout);
    }
#endif
}


void view_manager_get_ctlval_info(view_manager_t *vm, uint32_t* ctlval_mask, uint32_t ctlval_coords[2])
{
    *ctlval_mask = vm->ctlval_mask;
    ctlval_coords[0] = vm->ctlval_coords[0];
    ctlval_coords[1] = vm->ctlval_coords[1];
}
