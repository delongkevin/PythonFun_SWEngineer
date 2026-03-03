/*******************************************************************************
 * vm-tweak.c
 *
 * View manager (compositor) tweak-tools interface
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

#define MODULE_TAG                      TWEAK

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "config.h"
#include "tweak.h"
#include "view-manager.h"
#include "mesh-gen.h"
#include "sv_api.h"

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Tweak tool interface
 ******************************************************************************/

/**> Global configuration data pointer */
static cfg_data_t      *__cfg;

/**> View-manager data for tweak-tool interface */
static view_manager_t  *__vm;

/**> Copy of UI configuration */
static cfg_mesh_t     **__vm_cfg_mesh;

/**> Current view configuration */
static cfg_mesh_t      *__vm_tweak_view[MESH_NUMBER];

/**> Index of current configuration */
static cfg_mesh_t      *__vm_tweak_view_orig[MESH_NUMBER];

/**> Indication if current view is algo-view */
static int              __vm_tweak_view_is_algo[MESH_NUMBER];

/**> Algo-view id */
static const char      *__vm_tweak_view_id[MESH_NUMBER];

/**> Default cameras configurations */
static void * __vm_tweak_camera_cfg[SV_CAMERAS_NUMBER];

/**> Dynamic front/rear guidelines type selection */
static int  __vm_tweak_guide_dynamic_fr, __vm_tweak_guide_dynamic_sv, __vm_tweak_guide_fixed;

/**> Default vehicle configuration */
static cfg_vehicle_t __vm_tweak_vehicle_cfg;
static cfg_guide_tv_hatched_t __vm_tweak_cfg_tv_hatched;

/**> Default vehicle rendering configuration */
static cfg_car_render_t __vm_tweak_car_render_cfg;

/**> Default guidelines configuration */
static cfg_guide_t __vm_tweak_guide_cfg;

/**> Default color-correction configuration */
static cfg_cc_t __vm_tweak_cc_cfg;

/**> Default STV-PAS configuration */
static cfg_stv_pas_t    __vm_tweak_stv_pas_cfg;

/**> Sonar selector */
static int      __vm_tweak_sonar;

/**> Default scene params config */
static cfg_scene_params_t __vm_tweak_scene_params_cfg;

/**> Camera failure state update */
extern void camera_failure_update(int id, int failure);

/**> Camera test-patters state update */
extern void camera_test_update(int id, int failure);

/**> Background debug */
extern int  BACKGROUND_DEBUG;

/**> Intensity debug */
extern int  INTENSITY_DEBUG;

/**> Color-correction debug */
extern int  CC_DEBUG;

/*******************************************************************************
 * Internal API
 ******************************************************************************/

/**
 * @brief   Mirror destination config
 */
static inline void vm_tweak_mirror_dst(int32_t *dst)
{
    if (__cfg->vehicle.steering_lhd != __vm_tweak_vehicle_cfg.steering_lhd)
    {
        int32_t     width = __cfg->vm.width;
        int32_t     x0 = dst[0], x1 = dst[2];

        dst[0] = width - x1;
        dst[2] = width - x0;
    }
}

/**
 * @brief   Vehicle configuration setup
 */
static inline void vm_tweak_vehicle_setup(cfg_vehicle_t *cfg, char *tag)
{
    char    buffer[256], *p;
    int     i;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    /* ...make a copy of default configuration */
    memcpy(&__vm_tweak_vehicle_cfg, cfg, sizeof(*cfg));

    tweak_add_widget("Vehicle parameters");
    tweak_add_layout(200, 0, "");
    tweak_add_slider((strcpy(p, "length"), buffer), 100, 10000, cfg->length, 0);
    tweak_add_slider((strcpy(p, "width"), buffer), 100, 10000, cfg->width, 0);
    tweak_add_slider((strcpy(p, "width-mirrors"), buffer), 100, 10000, cfg->width_mirrors, 0);
    tweak_add_slider((strcpy(p, "wheel-base"), buffer), 100, 10000, cfg->wheel_base, 0);
    tweak_add_slider((strcpy(p, "front-overhang"), buffer), 100, 10000, cfg->front_overhang, 0);
    tweak_add_slider((strcpy(p, "rear-overhang"), buffer), 100, 10000, cfg->rear_overhang, 0);
    tweak_add_slider((strcpy(p, "rear-blind-area"), buffer), -100, 1000, cfg->rear_blind_area, 0);
    tweak_add_slider((strcpy(p, "front-blind-area"), buffer), -100, 1000, cfg->front_blind_area, 0);
    tweak_add_slider((strcpy(p, "left-blind-area"), buffer), -100, 1000, cfg->left_blind_area, 0);
    tweak_add_slider((strcpy(p, "right-blind-area"), buffer), -100, 1000, cfg->right_blind_area, 0);
    tweak_add_slider((strcpy(p, "front-track-width"), buffer), 100, 10000, cfg->front_track_width, 0);
    tweak_add_slider((strcpy(p, "rear-track-width"), buffer), 100, 10000, cfg->rear_track_width, 0);
    tweak_add_slider((strcpy(p, "front-wheel-diameter"), buffer), 100, 1000, cfg->front_wheel_diameter, 0);
    tweak_add_slider((strcpy(p, "rear-wheel-diameter"), buffer), 100, 1000, cfg->rear_wheel_diameter, 0);
    tweak_add_slider((strcpy(p, "front-wheel-width"), buffer), 100, 500, cfg->front_wheel_width, 0);
    tweak_add_slider((strcpy(p, "rear-wheel-width"), buffer), 100, 500, cfg->rear_wheel_width, 0);
    tweak_add_slider((strcpy(p, "steering-coef-0"), buffer), -1, 1, cfg->steering_coef[0], 9);
    tweak_add_slider((strcpy(p, "steering-coef-1"), buffer), -1, 1, cfg->steering_coef[1], 9);
    tweak_add_slider((strcpy(p, "steering-coef-2"), buffer), -1, 1, cfg->steering_coef[2], 9);
    tweak_add_slider((strcpy(p, "wheel-pulse-width"), buffer), 1, 100, cfg->wheel_pulse_width, 2);

    tweak_add_button((strcpy(p, "Revert"), buffer));
}



/**
 * @brief   Vehicle configuration setup
 */
static inline void vm_tweak_car_shadow_setup(cfg_guide_tv_hatched_t *cfg, char *tag)
{
    char    buffer[256], *p;
    int     i;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    /* ...make a copy of default configuration */
    memcpy(&__vm_tweak_cfg_tv_hatched, cfg, sizeof(*cfg));

    const float32_t min_coord = -9000.f;
    const float32_t max_coord =  9000.f;

    tweak_add_widget("Car shadow parameters");
    tweak_add_layout(200, 0, "");
    tweak_add_slider((strcpy(p, "num_points"), buffer), 4, 8, cfg->num_points, 0);
    tweak_add_slider((strcpy(p, "point0_y"), buffer), min_coord, max_coord, cfg->points[0][1], 0);
    tweak_add_slider((strcpy(p, "point1_y"), buffer), min_coord, max_coord, cfg->points[1][1], 0);
    tweak_add_slider((strcpy(p, "rounding_off_corner_0"), buffer), 0, 1, cfg->rounding_off_corners[0], 2);
    tweak_add_slider((strcpy(p, "point2_y"), buffer), min_coord, max_coord, cfg->points[2][1], 0);
    tweak_add_slider((strcpy(p, "rounding_off_corner_1"), buffer), 0, 1, cfg->rounding_off_corners[1], 2);
    tweak_add_slider((strcpy(p, "point3_y"), buffer), min_coord, max_coord, cfg->points[3][1], 0);
    tweak_add_slider((strcpy(p, "rounding_off_corner_2"), buffer), 0, 1, cfg->rounding_off_corners[2], 2);
    tweak_add_slider((strcpy(p, "point4_y"), buffer), min_coord, max_coord, cfg->points[4][1], 0);
    tweak_add_slider((strcpy(p, "rounding_off_corner_3"), buffer), 0, 1, cfg->rounding_off_corners[3], 2);
    tweak_add_slider((strcpy(p, "point5_y"), buffer), min_coord, max_coord, cfg->points[5][1], 0);
    tweak_add_slider((strcpy(p, "rounding_off_corner_4"), buffer), 0, 1, cfg->rounding_off_corners[4], 2);
    tweak_add_slider((strcpy(p, "point6_y"), buffer), min_coord, max_coord, cfg->points[6][1], 0);
    tweak_add_slider((strcpy(p, "rounding_off_corner_5"), buffer), 0, 1, cfg->rounding_off_corners[5], 2);
    tweak_add_slider((strcpy(p, "point7_y"), buffer), min_coord, max_coord, cfg->points[7][1], 0);

    tweak_add_slider((strcpy(p, "point0_x"), buffer), min_coord, max_coord, cfg->points[0][0], 0);
    tweak_add_slider((strcpy(p, "point1_x"), buffer), min_coord, max_coord, cfg->points[1][0], 0);
    tweak_add_slider((strcpy(p, "point2_x"), buffer), min_coord, max_coord, cfg->points[2][0], 0);
    tweak_add_slider((strcpy(p, "point3_x"), buffer), min_coord, max_coord, cfg->points[3][0], 0);
    tweak_add_slider((strcpy(p, "point4_x"), buffer), min_coord, max_coord, cfg->points[4][0], 0);
    tweak_add_slider((strcpy(p, "point5_x"), buffer), min_coord, max_coord, cfg->points[5][0], 0);
    tweak_add_slider((strcpy(p, "point6_x"), buffer), min_coord, max_coord, cfg->points[6][0], 0);
    tweak_add_slider((strcpy(p, "point7_x"), buffer), min_coord, max_coord, cfg->points[7][0], 0);

}

static int vm_tweak_car_shadow_update(cfg_guide_tv_hatched_t *cfg, const char *tag, const char *name, double value)
{
    if (!strcmp(name, "num_points"))                    cfg->num_points = value;
    else if (!strcmp(name, "point0_x"))                cfg->points[0][0] = value;
    else if (!strcmp(name, "point0_y"))                cfg->points[0][1] = value;
    else if (!strcmp(name, "point1_x"))                cfg->points[1][0] = value;
    else if (!strcmp(name, "point1_y"))                cfg->points[1][1] = value;
    else if (!strcmp(name, "rounding_off_corner_0"))                cfg->rounding_off_corners[0] = value;
    else if (!strcmp(name, "point2_x"))                cfg->points[2][0] = value;
    else if (!strcmp(name, "point2_y"))                cfg->points[2][1] = value;
    else if (!strcmp(name, "rounding_off_corner_1"))                cfg->rounding_off_corners[1] = value;
    else if (!strcmp(name, "point3_x"))                cfg->points[3][0] = value;
    else if (!strcmp(name, "point3_y"))                cfg->points[3][1] = value;
    else if (!strcmp(name, "rounding_off_corner_2"))                cfg->rounding_off_corners[2] = value;
    else if (!strcmp(name, "point4_x"))                cfg->points[4][0] = value;
    else if (!strcmp(name, "point4_y"))                cfg->points[4][1] = value;
    else if (!strcmp(name, "rounding_off_corner_3"))                cfg->rounding_off_corners[3] = value;
    else if (!strcmp(name, "point5_x"))                cfg->points[5][0] = value;
    else if (!strcmp(name, "point5_y"))                cfg->points[5][1] = value;
    else if (!strcmp(name, "rounding_off_corner_4"))                cfg->rounding_off_corners[4] = value;
    else if (!strcmp(name, "point6_x"))                cfg->points[6][0] = value;
    else if (!strcmp(name, "point6_y"))                cfg->points[6][1] = value;
    else if (!strcmp(name, "rounding_off_corner_5"))                cfg->rounding_off_corners[5] = value;
    else if (!strcmp(name, "point7_x"))                cfg->points[7][0] = value;
    else if (!strcmp(name, "point7_y"))                cfg->points[7][1] = value;

    return 1;
}

static void vm_tweak_vehicle_refresh(cfg_vehicle_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "length"), buf), cfg->length);
    tweak_set((strcpy(p, "width"), buf), cfg->width);
    tweak_set((strcpy(p, "width-mirrors"), buf), cfg->width_mirrors);
    tweak_set((strcpy(p, "wheel-base"), buf), cfg->wheel_base);
    tweak_set((strcpy(p, "front-overhang"), buf), cfg->front_overhang);
    tweak_set((strcpy(p, "rear-overhang"), buf), cfg->rear_overhang);
    tweak_set((strcpy(p, "rear-blind-area"), buf), cfg->rear_blind_area);
    tweak_set((strcpy(p, "front-blind-area"), buf), cfg->front_blind_area);
    tweak_set((strcpy(p, "left-blind-area"), buf), cfg->left_blind_area);
    tweak_set((strcpy(p, "right-blind-area"), buf), cfg->right_blind_area);
    tweak_set((strcpy(p, "front-track-width"), buf), cfg->front_track_width);
    tweak_set((strcpy(p, "rear-track-width"), buf), cfg->rear_track_width);
    tweak_set((strcpy(p, "front-wheel-diameter"), buf), cfg->front_wheel_diameter);
    tweak_set((strcpy(p, "rear-wheel-diameter"), buf), cfg->rear_wheel_diameter);
    tweak_set((strcpy(p, "front-wheel-width"), buf), cfg->front_wheel_width);
    tweak_set((strcpy(p, "rear-wheel-width"), buf), cfg->rear_wheel_width);
    tweak_set((strcpy(p, "steering-coef-0"), buf), cfg->steering_coef[0]);
    tweak_set((strcpy(p, "steering-coef-1"), buf), cfg->steering_coef[1]);
    tweak_set((strcpy(p, "steering-coef-2"), buf), cfg->steering_coef[2]);
    tweak_set((strcpy(p, "wheel-pulse-width"), buf), cfg->wheel_pulse_width);
}

static void vm_tweak_vehicle_revert(cfg_vehicle_t *cfg, const char *tag)
{
    memcpy(cfg, &__vm_tweak_vehicle_cfg, sizeof(*cfg));
    vm_tweak_vehicle_refresh(cfg, tag);
}

static int vm_tweak_vehicle_update(cfg_vehicle_t *cfg, const char *tag, const char *name, double value)
{
    if (!strcmp(name, "length"))                    cfg->length = value;
    else if (!strcmp(name, "width"))                cfg->width = value;
    else if (!strcmp(name, "width-mirrors"))        cfg->width_mirrors = value;
    else if (!strcmp(name, "front-overhang"))       cfg->front_overhang = value;
    else if (!strcmp(name, "wheel-base"))           cfg->wheel_base = value;
    else if (!strcmp(name, "rear-overhang"))        cfg->rear_overhang = value;
    else if (!strcmp(name, "rear-blind-area"))      cfg->rear_blind_area = value;
    else if (!strcmp(name, "front-blind-area"))     cfg->front_blind_area = value;
    else if (!strcmp(name, "left-blind-area"))      cfg->left_blind_area = value;
    else if (!strcmp(name, "right-blind-area"))     cfg->right_blind_area = value;
    else if (!strcmp(name, "front-track-width"))    cfg->front_track_width = value;
    else if (!strcmp(name, "rear-track-width"))     cfg->rear_track_width = value;
    else if (!strcmp(name, "front-wheel-diameter")) cfg->front_wheel_diameter = value;
    else if (!strcmp(name, "rear-wheel-diameter"))  cfg->rear_wheel_diameter = value;
    else if (!strcmp(name, "front-wheel-width"))    cfg->front_wheel_width = value;
    else if (!strcmp(name, "rear-wheel-width"))     cfg->rear_wheel_width = value;
    else if (!strcmp(name, "wheel-pulse-width"))    cfg->wheel_pulse_width = value;
    else if (!strcmp(name, "steering-coef-0"))      cfg->steering_coef[0] = value;
    else if (!strcmp(name, "steering-coef-1"))      cfg->steering_coef[1] = value;
    else if (!strcmp(name, "steering-coef-2"))      cfg->steering_coef[2] = value;
    else if (!strcmp(name, "rear-wheel-diameter"))  cfg->rear_wheel_diameter = value;
    else if (!strcmp(name, "Revert"))               vm_tweak_vehicle_revert(cfg, tag);

    else return TRACE(1, _b("unknown param: %s=%f"), name, value), 0;

    return 1;
}

/**
 * @brief   Color-correction configuration
 */
static inline void vm_tweak_cc_setup(cfg_cc_t *cfg, char *tag)
{
    char    buffer[256], *p;
    char   *id[4] = { "fl", "rl", "rr", "fr" };
    int     i;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    /* ...make a copy of default configuration */
    memcpy(&__vm_tweak_cc_cfg, cfg, sizeof(*cfg));

    tweak_add_widget("Color correction");
    //tweak_add_layout(200, 0, "");
    for (i = 0; i < 4; i++)
    {
        tweak_add_layout(200, (i == 2 ? 0 : 1), "");

        snprintf(p, sizeof(buffer) - (int)(p - buffer), "roi-%s-x0", id[i]);
        tweak_add_spinbox(buffer, -10000, 10000, cfg->roi[i][0], 0);

        snprintf(p, sizeof(buffer) - (int)(p - buffer), "roi-%s-y0", id[i]);
        tweak_add_spinbox(buffer, -10000, 10000, cfg->roi[i][1], 0);

        snprintf(p, sizeof(buffer) - (int)(p - buffer), "roi-%s-x1", id[i]);
        tweak_add_spinbox(buffer, -10000, 10000, cfg->roi[i][2], 0);

        snprintf(p, sizeof(buffer) - (int)(p - buffer), "roi-%s-y1", id[i]);
        tweak_add_spinbox(buffer, -10000, 10000, cfg->roi[i][3], 0);
    }

    tweak_add_layout(200, 0, "");
    tweak_add_checkbox((strcpy(p, "Enable"), buffer), cfg->enable);
    tweak_add_slider((strcpy(p, "size-mm"), buffer), 0, 2000, cfg->size_mm, 0);
    tweak_add_slider((strcpy(p, "offset-x"), buffer), 0, 2000, cfg->offset_x, 0);
    tweak_add_slider((strcpy(p, "offset-y"), buffer), 0, 2000, cfg->offset_y, 0);

    tweak_add_layout(200, 1, "");
    tweak_add_button((strcpy(p, "Revert"), buffer));
}

static void vm_tweak_cc_refresh(cfg_cc_t *cfg, const char *tag)
{
    char    buf[256], *p;
    char   *id[4] = { "fl", "rl", "rr", "fr" };
    int     i;

    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    for (i = 0; i < 4; i++)
    {
        snprintf(p, sizeof(buf) - (int)(p - buf), "roi-%s-x0", id[i]);
        tweak_set(buf, cfg->roi[i][0]);

        snprintf(p, sizeof(buf) - (int)(p - buf), "roi-%s-y0", id[i]);
        tweak_set(buf, cfg->roi[i][1]);

        snprintf(p, sizeof(buf) - (int)(p - buf), "roi-%s-x1", id[i]);
        tweak_set(buf, cfg->roi[i][2]);

        snprintf(p, sizeof(buf) - (int)(p - buf), "roi-%s-y1", id[i]);
        tweak_set(buf, cfg->roi[i][3]);
    }

    tweak_set((strcpy(p, "size-mm"), buf), cfg->size_mm);
    tweak_set((strcpy(p, "offset-x"), buf), cfg->offset_x);
    tweak_set((strcpy(p, "offset-y"), buf), cfg->offset_y);
}

static void vm_tweak_cc_revert(cfg_cc_t *cfg, const char *tag)
{
    memcpy(cfg, &__vm_tweak_cc_cfg, sizeof(*cfg));
    vm_tweak_cc_refresh(cfg, tag);
}

static int vm_tweak_cc_update(cfg_cc_t *cfg, const char *tag, const char *name, double value)
{
    char   *id[4] = { "fl", "rl", "rr", "fr" };
    char   *t;
    int     i;

    if (!strncmp(name, "roi-", 4))
    {
        for (i = 0; i < 4; i++)
        {
            if (!strncmp(name + 4, id[i], 2))
            {
                break;
            }
        }

        if (i >= 4 || name[6] != '-')
        {
            return TRACE(1, _b("cc unknown param: %s=%f"), name, value), 0;
        }
        else if (!strncmp(name + 7, "x0", 2))   cfg->roi[i][0] = value;
        else if (!strncmp(name + 7, "y0", 2))   cfg->roi[i][1] = value;
        else if (!strncmp(name + 7, "x1", 2))   cfg->roi[i][2] = value;
        else if (!strncmp(name + 7, "y1", 2))   cfg->roi[i][3] = value;
        else return TRACE(1, _b("cc unknown param: %s=%f"), name, value), 0;
    }
    else if (!strcmp(name, "Enable"))
    {
        cfg->enable = (int)value;
    }
    else if (!strcmp(name, "Revert"))
    {
        vm_tweak_cc_revert(cfg, tag);
    }
    else
    {
        return TRACE(1, _b("cc unknown param: %s=%f"), name, value), 0;
    }

    return 1;
}

static inline void vm_tweak_ap_setup(char *tag)
{
    char    buffer[256], *p;
    int     i;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    tweak_add_widget("AP");
    tweak_add_layout(200, 0, "");
    tweak_add_checkbox((strcpy(p, "PDC_RearLeft_Red"), buffer), 0);
    tweak_add_checkbox((strcpy(p, "PDC_RearLeft_Yellow"), buffer), 0);
    tweak_add_checkbox((strcpy(p, "PDC_FrontRight_Red"), buffer), 0);
    tweak_add_checkbox((strcpy(p, "PDC_FrontRight_Yellow"), buffer), 0);
    tweak_add_checkbox((strcpy(p, "PDC_FrontCenter_Red"), buffer), 0);
    tweak_add_checkbox((strcpy(p, "PDC_FrontCenter_Yellow"), buffer), 0);
    tweak_add_checkbox((strcpy(p, "PDC_FrontLeft_Red"), buffer), 0);
    tweak_add_checkbox((strcpy(p, "PDC_FrontLeft_Yellow"), buffer), 0);
    tweak_add_checkbox((strcpy(p, "PDC_RearRight_Red"), buffer), 0);
    tweak_add_checkbox((strcpy(p, "PDC_RearRight_Yellow"), buffer), 0);
    tweak_add_checkbox((strcpy(p, "PDC_RearCenter_Red"), buffer), 0);
    tweak_add_checkbox((strcpy(p, "PDC_RearCenter_Yellow"), buffer), 0);

    tweak_add_layout(100, 1, "");
     tweak_add_checkbox((strcpy(p, "AP_BackBtn"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Disclaimer_Core"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_ExitBtn_Not_Selected"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_ExitBtn_Selected"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Forward_LeftBtn_Not_Selected"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Forward_LeftBtn_Selected"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Forward_RightBtn_Not_Selected"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Forward_RightBtn_Selected"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_FrontInBtn_Not_Avail"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_FrontInBtn_Not_Selected"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_FrontInBtn_Selected"), buffer), 0);
    tweak_add_layout(100, 1, "");
    tweak_add_layout(200, 0, "");

     tweak_add_checkbox((strcpy(p, "AP_Grey_Banner1"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Grey_Banner2"), buffer), 0);
     tweak_add_spinbox((strcpy(p, "AP_HMI_Top_red"), buffer), 0, 7, 0, 0);
     tweak_add_spinbox((strcpy(p, "AP_HMI_bottom_black"), buffer), 0, 16, 0, 0);
     tweak_add_spinbox((strcpy(p, "AP_HMI_fullscreen"), buffer), 0, 12, 0, 0);
     tweak_add_spinbox((strcpy(p, "AP_HMI_top_black"), buffer), 0, 17, 0, 0);
     tweak_add_checkbox((strcpy(p, "AP_Para_Exit_Core"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_ParkBtn_Not_Selected"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_ParkBtn_Selected"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_ParkIn_Done"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Parkout_Done"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Perp_Left_Core"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Perp_Right_Core"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_RearInBtn_Not_Avail"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_RearInBtn_Not_Selected"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_RearInBtn_Selected"), buffer), 0);
    tweak_add_layout(100, 1, "");
     tweak_add_checkbox((strcpy(p, "AP_Scan_Keep_Moving_Forward_Text"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Scan_Reduce_Speed_Text"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Scan_STOP_Text"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Scan_Searching_Text"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Scan_Select_Space_Text"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Scan_Space_Found_Text"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_Scanning_Core"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "AP_BG_Main"), buffer), 0);
    tweak_add_layout(100, 1, "");
    tweak_add_layout(200, 0, "");
     tweak_add_checkbox((strcpy(p, "BackDoorOpen_Icon_b"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "LeftDoorFrontClose_Icon_b"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "LeftDoorFrontOpen_Icon_b"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "LeftDoorRearClose_Icon_b"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "LeftDoorRearOpen_Icon_b"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "RightDoorFrontClose_Icon_b"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "RightDoorFrontOpen_Icon_b"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "RightDoorRearClose_Icon_b"), buffer), 0);
     tweak_add_checkbox((strcpy(p, "RightDoorRearOpen_Icon_b"), buffer), 0);
    tweak_add_layout(100, 1, "");
}

static inline void vm_tweak_ap_dynamic_setup(char *tag)
{
    char    buffer[256], *p;
    int     i;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    tweak_add_widget("AP_dynamic");
    tweak_add_layout(100, 0, "");

    for (int i = 0; i < 6; i++)
    {
        char* p2;
        p2 = p + snprintf(p, 4, "%d:", i);
        tweak_add_spinbox((strcpy(p2, "x"), buffer), 0, 2048, 0, 0);
        tweak_add_spinbox((strcpy(p2, "y"), buffer), 0, 2048, 0, 0);
        tweak_add_spinbox((strcpy(p2, "type"), buffer), 0, 2, 0, 0);
        tweak_add_checkbox((strcpy(p2, "active"), buffer), 0);
    }
    tweak_add_layout(100, 1, "");
    tweak_add_layout(100, 1, "");
    tweak_add_layout(400, 0, "");
}
/**
 * @brief   PAS state configuration
 */
static inline void vm_tweak_pas_setup(cfg_stv_pas_t *cfg, pas_state_t *pas, char *tag)
{
    char    buffer[256], *p;
    int     i;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    /* ...make a copy of default configuration */
    memcpy(&__vm_tweak_stv_pas_cfg, cfg, sizeof(*cfg));

    tweak_add_widget("PAS");
    tweak_add_layout(200, 0, "");

    tweak_add_groupbox((strcpy(p, "sonar"), buffer), "front-center;front-right;front-left;rear-center;rear-right;rear-left", __vm_tweak_sonar);
    tweak_add_layout(100, 1, "");

    tweak_add_spinbox((strcpy(p, "sonar-state"), buffer), 0, 3, pas->sonar_state[__vm_tweak_sonar], 0);
    tweak_add_spinbox((strcpy(p, "area-info"), buffer), 0, 5, pas->area_info[__vm_tweak_sonar], 0);

    tweak_add_layout(200, 1, "");
    tweak_add_groupbox((strcpy(p, "PAS state"), buffer), "off;on;failure", pas->state);

    tweak_add_layout(100, 1, "Position");
    tweak_add_slider((strcpy(p, "origin-x"), buffer), -10000, 10000, cfg->sonar_origin[__vm_tweak_sonar][0], 0);
    tweak_add_slider((strcpy(p, "origin-y"), buffer), -10000, 10000, cfg->sonar_origin[__vm_tweak_sonar][1], 0);
    tweak_add_slider((strcpy(p, "direction"), buffer), -360, 360, cfg->sonar_direction[__vm_tweak_sonar], 0);

    tweak_add_layout(100, 0, "Configuration");
    tweak_add_slider((strcpy(p, "stv-obstacle-close-distance"), buffer), 0, 10000, cfg->stv_obstacle_close_distance, 0);
    tweak_add_slider((strcpy(p, "stv-obstacle-middle-distance"), buffer), 0, 10000, cfg->stv_obstacle_middle_distance, 0);
    tweak_add_slider((strcpy(p, "stv-obstacle-far-distance"), buffer), 0, 10000, cfg->stv_obstacle_far_distance, 0);
    tweak_add_slider((strcpy(p, "stv-obstacle-max-distance"), buffer), 0, 10000, cfg->stv_obstacle_max_distance, 0);
    tweak_add_slider((strcpy(p, "stv-obstacle-dim-x"), buffer), 0, 1000, cfg->stv_obstacle_dim[0], 0);
    tweak_add_slider((strcpy(p, "stv-obstacle-dim-y"), buffer), 0, 1000, cfg->stv_obstacle_dim[1], 0);
    tweak_add_slider((strcpy(p, "stv-obstacle-dim-z"), buffer), 0, 1000, cfg->stv_obstacle_dim[2], 0);
    tweak_add_slider((strcpy(p, "stv-obstacle-dim-scale-x"), buffer), 0, 10, cfg->stv_obstacle_dim_scale[0], 2);
    tweak_add_slider((strcpy(p, "stv-obstacle-dim-scale-y"), buffer), 0, 10, cfg->stv_obstacle_dim_scale[1], 2);
    tweak_add_slider((strcpy(p, "stv-obstacle-dim-scale-z"), buffer), 0, 10, cfg->stv_obstacle_dim_scale[2], 2);
    tweak_add_slider((strcpy(p, "stv-obstacle-switch-factor"), buffer), 0, 1, cfg->stv_obstacle_switch_factor, 2);
    tweak_add_spinbox((strcpy(p, "stv-obstacle-fadeout-duration"), buffer), 0, 1000, cfg->stv_obstacle_fadeout_duration, 0);

    tweak_add_layout(100, 0, "Colors");

    tweak_add_spinbox((strcpy(p, "stv-pas-close-color-R"), buffer), 0, 255, cfg->stv_pas_close_color[0], 0);
    tweak_add_spinbox((strcpy(p, "stv-pas-close-color-G"), buffer), 0, 255, cfg->stv_pas_close_color[1], 0);
    tweak_add_spinbox((strcpy(p, "stv-pas-close-color-B"), buffer), 0, 255, cfg->stv_pas_close_color[2], 0);
    tweak_add_spinbox((strcpy(p, "stv-pas-middle-color-R"), buffer), 0, 255, cfg->stv_pas_middle_color[0], 0);
    tweak_add_spinbox((strcpy(p, "stv-pas-middle-color-G"), buffer), 0, 255, cfg->stv_pas_middle_color[1], 0);
    tweak_add_spinbox((strcpy(p, "stv-pas-middle-color-B"), buffer), 0, 255, cfg->stv_pas_middle_color[2], 0);
    tweak_add_spinbox((strcpy(p, "stv-pas-far-color-R"), buffer), 0, 255, cfg->stv_pas_far_color[0], 0);
    tweak_add_spinbox((strcpy(p, "stv-pas-far-color-G"), buffer), 0, 255, cfg->stv_pas_far_color[1], 0);
    tweak_add_spinbox((strcpy(p, "stv-pas-far-color-B"), buffer), 0, 255, cfg->stv_pas_far_color[2], 0);
    tweak_add_spinbox((strcpy(p, "stv-pas-max-color-R"), buffer), 0, 255, cfg->stv_pas_max_color[0], 0);
    tweak_add_spinbox((strcpy(p, "stv-pas-max-color-G"), buffer), 0, 255, cfg->stv_pas_max_color[1], 0);
    tweak_add_spinbox((strcpy(p, "stv-pas-max-color-B"), buffer), 0, 255, cfg->stv_pas_max_color[2], 0);

    tweak_add_spinbox((strcpy(p, "stv-obstacle-color-R"), buffer), 0, 255, cfg->stv_obstacle_color[0], 0);
    tweak_add_spinbox((strcpy(p, "stv-obstacle-color-G"), buffer), 0, 255, cfg->stv_obstacle_color[1], 0);
    tweak_add_spinbox((strcpy(p, "stv-obstacle-color-B"), buffer), 0, 255, cfg->stv_obstacle_color[2], 0);
    tweak_add_spinbox((strcpy(p, "stv-obstacle-line-color-R"), buffer), 0, 255, cfg->stv_obstacle_line_color[0], 0);
    tweak_add_spinbox((strcpy(p, "stv-obstacle-line-color-G"), buffer), 0, 255, cfg->stv_obstacle_line_color[1], 0);
    tweak_add_spinbox((strcpy(p, "stv-obstacle-line-color-B"), buffer), 0, 255, cfg->stv_obstacle_line_color[2], 0);

    tweak_add_slider((strcpy(p, "stv-obstacle-transparency"), buffer), 0, 100, cfg->stv_obstacle_transparency, 0);
    tweak_add_slider((strcpy(p, "stv-obstacle-line-transparency"), buffer), 0, 100, cfg->stv_obstacle_line_transparency, 0);
    tweak_add_slider((strcpy(p, "stv-obstacle-line-width"), buffer), 0.1, 10.0f, cfg->stv_obstacle_line_width, 1);

    tweak_add_layout(100, 1, "");
    tweak_add_button((strcpy(p, "Revert"), buffer));
}

static void vm_tweak_pas_refresh(cfg_stv_pas_t *cfg, pas_state_t *pas, const char *tag)
{
    char    buf[256], *p;
    int     i;

    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "PAS state"), buf), pas->state);
    tweak_set((strcpy(p, "sonar-state"), buf), pas->sonar_state[__vm_tweak_sonar]);
    tweak_set((strcpy(p, "area-info"), buf), pas->area_info[__vm_tweak_sonar]);

    tweak_set((strcpy(p, "origin-x"), buf), cfg->sonar_origin[__vm_tweak_sonar][0]);
    tweak_set((strcpy(p, "origin-y"), buf), cfg->sonar_origin[__vm_tweak_sonar][1]);
    tweak_set((strcpy(p, "direction"), buf), cfg->sonar_direction[__vm_tweak_sonar]);

    tweak_set((strcpy(p, "stv-obstacle-close-distance"), buf), cfg->stv_obstacle_close_distance);
    tweak_set((strcpy(p, "stv-obstacle-middle-distance"), buf), cfg->stv_obstacle_middle_distance);
    tweak_set((strcpy(p, "stv-obstacle-far-distance"), buf), cfg->stv_obstacle_far_distance);
    tweak_set((strcpy(p, "stv-obstacle-max-distance"), buf), cfg->stv_obstacle_max_distance);
    tweak_set((strcpy(p, "stv-obstacle-dim-x"), buf), cfg->stv_obstacle_dim[0]);
    tweak_set((strcpy(p, "stv-obstacle-dim-y"), buf), cfg->stv_obstacle_dim[1]);
    tweak_set((strcpy(p, "stv-obstacle-dim-z"), buf), cfg->stv_obstacle_dim[2]);
    tweak_set((strcpy(p, "stv-obstacle-dim-scale-x"), buf), cfg->stv_obstacle_dim_scale[0]);
    tweak_set((strcpy(p, "stv-obstacle-dim-scale-y"), buf), cfg->stv_obstacle_dim_scale[1]);
    tweak_set((strcpy(p, "stv-obstacle-dim-scale-z"), buf), cfg->stv_obstacle_dim_scale[2]);
    tweak_set((strcpy(p, "stv-obstacle-switch-factor"), buf), cfg->stv_obstacle_switch_factor);
    tweak_set((strcpy(p, "stv-obstacle-fadeout-duration"), buf), cfg->stv_obstacle_fadeout_duration);

    tweak_set((strcpy(p, "stv-pas-close-color-R"), buf), cfg->stv_pas_close_color[0]);
    tweak_set((strcpy(p, "stv-pas-close-color-G"), buf), cfg->stv_pas_close_color[1]);
    tweak_set((strcpy(p, "stv-pas-close-color-B"), buf), cfg->stv_pas_close_color[2]);
    tweak_set((strcpy(p, "stv-pas-middle-color-R"), buf), cfg->stv_pas_middle_color[0]);
    tweak_set((strcpy(p, "stv-pas-middle-color-G"), buf), cfg->stv_pas_middle_color[1]);
    tweak_set((strcpy(p, "stv-pas-middle-color-B"), buf), cfg->stv_pas_middle_color[2]);
    tweak_set((strcpy(p, "stv-pas-far-color-R"), buf), cfg->stv_pas_far_color[0]);
    tweak_set((strcpy(p, "stv-pas-far-color-G"), buf), cfg->stv_pas_far_color[1]);
    tweak_set((strcpy(p, "stv-pas-far-color-B"), buf), cfg->stv_pas_far_color[2]);
    tweak_set((strcpy(p, "stv-pas-max-color-R"), buf), cfg->stv_pas_max_color[0]);
    tweak_set((strcpy(p, "stv-pas-max-color-G"), buf), cfg->stv_pas_max_color[1]);
    tweak_set((strcpy(p, "stv-pas-max-color-B"), buf), cfg->stv_pas_max_color[2]);

    tweak_set((strcpy(p, "stv-obstacle-color-R"), buf), cfg->stv_obstacle_color[0]);
    tweak_set((strcpy(p, "stv-obstacle-color-G"), buf), cfg->stv_obstacle_color[1]);
    tweak_set((strcpy(p, "stv-obstacle-color-B"), buf), cfg->stv_obstacle_color[2]);
    tweak_set((strcpy(p, "stv-obstacle-line-color-R"), buf), cfg->stv_obstacle_line_color[0]);
    tweak_set((strcpy(p, "stv-obstacle-line-color-G"), buf), cfg->stv_obstacle_line_color[1]);
    tweak_set((strcpy(p, "stv-obstacle-line-color-B"), buf), cfg->stv_obstacle_line_color[2]);

    tweak_set((strcpy(p, "stv-obstacle-transparency"), buf), cfg->stv_obstacle_transparency);
    tweak_set((strcpy(p, "stv-obstacle-line-transparency"), buf), cfg->stv_obstacle_line_transparency);
    tweak_set((strcpy(p, "stv-obstacle-line-width"), buf), cfg->stv_obstacle_line_width);
}

static void vm_tweak_pas_revert(cfg_stv_pas_t *cfg, pas_state_t *pas, const char *tag)
{
    memcpy(cfg, &__vm_tweak_stv_pas_cfg, sizeof(*cfg));
    vm_tweak_pas_refresh(cfg, pas, tag);
}

static int vm_tweak_ap_update(ap_state_t *ap, const char *tag, const char *name, double value)
{
    if (!strcmp(name, "PDC_RearLeft_Red"))    ap->PDC_RearLeft_Red_b = (int)value;
    else if (!strcmp(name, "PDC_RearLeft_Yellow"))    ap->PDC_RearLeft_Yellow_b = (int)value;
    else if (!strcmp(name, "PDC_FrontRight_Red"))    ap->PDC_FrontRight_Red_b = (int)value;
    else if (!strcmp(name, "PDC_FrontRight_Yellow"))    ap->PDC_FrontRight_Yellow_b = (int)value;
    else if (!strcmp(name, "PDC_FrontCenter_Red"))    ap->PDC_FrontCenter_Red_b = (int)value;
    else if (!strcmp(name, "PDC_FrontCenter_Yellow"))    ap->PDC_FrontCenter_Yellow_b = (int)value;
    else if (!strcmp(name, "PDC_FrontLeft_Red"))    ap->PDC_FrontLeft_Red_b = (int)value;
    else if (!strcmp(name, "PDC_FrontLeft_Yellow"))    ap->PDC_FrontLeft_Yellow_b = (int)value;
    else if (!strcmp(name, "PDC_RearRight_Red"))    ap->PDC_RearRight_Red_b = (int)value;
    else if (!strcmp(name, "PDC_RearRight_Yellow"))    ap->PDC_RearRight_Yellow_b = (int)value;
    else if (!strcmp(name, "PDC_RearCenter_Red"))    ap->PDC_RearCenter_Red_b = (int)value;
    else if (!strcmp(name, "PDC_RearCenter_Yellow"))    ap->PDC_RearCenter_Yellow_b = (int)value;
    else if (!strcmp(name, "AP_BackBtn"))    ap->AP_BackBtn = (int)value;
    else if (!strcmp(name, "AP_Disclaimer_Core"))    ap->AP_Disclaimer_Core = (int)value;
    else if (!strcmp(name, "AP_ExitBtn_Not_Selected"))    ap->AP_ExitBtn_Not_Selected = (int)value;
    else if (!strcmp(name, "AP_ExitBtn_Selected"))    ap->AP_ExitBtn_Selected = (int)value;
    else if (!strcmp(name, "AP_Forward_LeftBtn_Not_Selected"))    ap->AP_Forward_LeftBtn_Not_Selected = (int)value;
    else if (!strcmp(name, "AP_Forward_LeftBtn_Selected"))    ap->AP_Forward_LeftBtn_Selected = (int)value;
    else if (!strcmp(name, "AP_Forward_RightBtn_Not_Selected"))    ap->AP_Forward_RightBtn_Not_Selected = (int)value;
    else if (!strcmp(name, "AP_Forward_RightBtn_Selected"))    ap->AP_Forward_RightBtn_Selected = (int)value;
    else if (!strcmp(name, "AP_FrontInBtn_Not_Avail"))    ap->AP_FrontInBtn_Not_Avail = (int)value;
    else if (!strcmp(name, "AP_FrontInBtn_Not_Selected"))    ap->AP_FrontInBtn_Not_Selected = (int)value;
    else if (!strcmp(name, "AP_FrontInBtn_Selected"))    ap->AP_FrontInBtn_Selected = (int)value;
    else if (!strcmp(name, "AP_Grey_Banner1"))    ap->AP_Grey_Banner1 = (int)value;
    else if (!strcmp(name, "AP_Grey_Banner2"))    ap->AP_Grey_Banner2 = (int)value;
    else if (!strcmp(name, "AP_HMI_Top_red"))    ap->AP_HMI_Top_red = (int)value;
    else if (!strcmp(name, "AP_HMI_bottom_black"))    ap->AP_HMI_bottom_black = (int)value;
    else if (!strcmp(name, "AP_HMI_fullscreen"))    ap->AP_HMI_fullscreen = (int)value;
    else if (!strcmp(name, "AP_HMI_top_black"))    ap->AP_HMI_top_black = (int)value;
    else if (!strcmp(name, "AP_Para_Exit_Core"))    ap->AP_Para_Exit_Core = (int)value;
    else if (!strcmp(name, "AP_ParkBtn_Not_Selected"))    ap->AP_ParkBtn_Not_Selected = (int)value;
    else if (!strcmp(name, "AP_ParkBtn_Selected"))    ap->AP_ParkBtn_Selected = (int)value;
    else if (!strcmp(name, "AP_ParkIn_Done"))    ap->AP_ParkIn_Done = (int)value;
    else if (!strcmp(name, "AP_Parkout_Done"))    ap->AP_Parkout_Done = (int)value;
    else if (!strcmp(name, "AP_Perp_Left_Core"))    ap->AP_Perp_Left_Core = (int)value;
    else if (!strcmp(name, "AP_Perp_Right_Core"))    ap->AP_Perp_Right_Core = (int)value;
    else if (!strcmp(name, "AP_RearInBtn_Not_Avail"))    ap->AP_RearInBtn_Not_Avail = (int)value;
    else if (!strcmp(name, "AP_RearInBtn_Not_Selected"))    ap->AP_RearInBtn_Not_Selected = (int)value;
    else if (!strcmp(name, "AP_RearInBtn_Selected"))    ap->AP_RearInBtn_Selected = (int)value;
    else if (!strcmp(name, "AP_Scan_Keep_Moving_Forward_Text"))    ap->AP_Scan_Keep_Moving_Forward_Text = (int)value;
    else if (!strcmp(name, "AP_Scan_Reduce_Speed_Text"))    ap->AP_Scan_Reduce_Speed_Text = (int)value;
    else if (!strcmp(name, "AP_Scan_STOP_Text"))    ap->AP_Scan_STOP_Text = (int)value;
    else if (!strcmp(name, "AP_Scan_Searching_Text"))    ap->AP_Scan_Searching_Text = (int)value;
    else if (!strcmp(name, "AP_Scan_Select_Space_Text"))    ap->AP_Scan_Select_Space_Text = (int)value;
    else if (!strcmp(name, "AP_Scan_Space_Found_Text"))    ap->AP_Scan_Space_Found_Text = (int)value;
    else if (!strcmp(name, "AP_Scanning_Core"))    ap->AP_Scanning_Core = (int)value;
    else if (!strcmp(name, "AP_BG_Main"))    ap->AP_BG_Main = (int)value;
    else if (!strcmp(name, "BackDoorOpen_Icon_b"))    ap->BackDoorOpen_Icon_b = (int)value;
    else if (!strcmp(name, "LeftDoorFrontClose_Icon_b"))    ap->LeftDoorFrontClose_Icon_b = (int)value;
    else if (!strcmp(name, "LeftDoorFrontOpen_Icon_b"))    ap->LeftDoorFrontOpen_Icon_b = (int)value;
    else if (!strcmp(name, "LeftDoorRearClose_Icon_b"))    ap->LeftDoorRearClose_Icon_b = (int)value;
    else if (!strcmp(name, "LeftDoorRearOpen_Icon_b"))    ap->LeftDoorRearOpen_Icon_b = (int)value;
    else if (!strcmp(name, "RightDoorFrontClose_Icon_b"))    ap->RightDoorFrontClose_Icon_b = (int)value;
    else if (!strcmp(name, "RightDoorFrontOpen_Icon_b"))    ap->RightDoorFrontOpen_Icon_b = (int)value;
    else if (!strcmp(name, "RightDoorRearClose_Icon_b"))    ap->RightDoorRearClose_Icon_b = (int)value;
    else if (!strcmp(name, "RightDoorRearOpen_Icon_b"))    ap->RightDoorRearOpen_Icon_b = (int)value;
    else return 0;

    return 1;
}

static int vm_tweak_ap_dyn_update(ap_state_t *ap, uint32_t indx, const char *name, int value)
{
    ap_dynamic_slot_t* dst = &ap->ap_dynamic_slots[indx];
    if (!strcmp(name, "x"))    dst->x = value;
    else if (!strcmp(name, "y"))    dst->y = value;
    else if (!strcmp(name, "active"))   dst->active = value;
    else if (!strcmp(name, "type"))    dst->type = value;
    else return 0;

    return 1;
}

static int vm_tweak_pas_update(cfg_stv_pas_t *cfg, pas_state_t *pas, const char *tag, const char *name, double value)
{
    if (!strcmp(name, "sonar"))
    {
        if (__vm_tweak_sonar != (int)value)
        {
            __vm_tweak_sonar = (int)value;
            vm_tweak_pas_refresh(cfg, pas, tag);
        }
        return 0;
    }
    else if (!strcmp(name, "PAS state"))    pas->state = (int)value;
    else if (!strcmp(name, "sonar-state"))  pas->sonar_state[__vm_tweak_sonar] = (int)value;
    else if (!strcmp(name, "area-info"))    pas->area_info[__vm_tweak_sonar] = (int)value;

    else if (!strcmp(name, "origin-x"))     cfg->sonar_origin[__vm_tweak_sonar][0] = value;
    else if (!strcmp(name, "origin-y"))     cfg->sonar_origin[__vm_tweak_sonar][1] = value;
    else if (!strcmp(name, "direction"))    cfg->sonar_direction[__vm_tweak_sonar] = value;

    else if (!strcmp(name, "stv-obstacle-close-distance"))  cfg->stv_obstacle_close_distance = value;
    else if (!strcmp(name, "stv-obstacle-middle-distance")) cfg->stv_obstacle_middle_distance = value;
    else if (!strcmp(name, "stv-obstacle-far-distance"))    cfg->stv_obstacle_far_distance = value;
    else if (!strcmp(name, "stv-obstacle-max-distance"))    cfg->stv_obstacle_max_distance = value;
    else if (!strcmp(name, "stv-obstacle-dim-x"))           cfg->stv_obstacle_dim[0] = value;
    else if (!strcmp(name, "stv-obstacle-dim-y"))           cfg->stv_obstacle_dim[1] = value;
    else if (!strcmp(name, "stv-obstacle-dim-z"))           cfg->stv_obstacle_dim[2] = value;
    else if (!strcmp(name, "stv-obstacle-dim-scale-x"))     cfg->stv_obstacle_dim_scale[0] = value;
    else if (!strcmp(name, "stv-obstacle-dim-scale-y"))     cfg->stv_obstacle_dim_scale[1] = value;
    else if (!strcmp(name, "stv-obstacle-dim-scale-z"))     cfg->stv_obstacle_dim_scale[2] = value;
    else if (!strcmp(name, "stv-obstacle-switch-factor"))   cfg->stv_obstacle_switch_factor = value;
    else if (!strcmp(name, "stv-obstacle-fadeout-duration"))cfg->stv_obstacle_fadeout_duration = (uint32_t)value;

    else if (!strcmp(name, "stv-pas-close-color-R"))        cfg->stv_pas_close_color[0] = (uint8_t)value;
    else if (!strcmp(name, "stv-pas-close-color-G"))        cfg->stv_pas_close_color[1] = (uint8_t)value;
    else if (!strcmp(name, "stv-pas-close-color-B"))        cfg->stv_pas_close_color[2] = (uint8_t)value;
    else if (!strcmp(name, "stv-pas-middle-color-R"))       cfg->stv_pas_middle_color[0] = (uint8_t)value;
    else if (!strcmp(name, "stv-pas-middle-color-G"))       cfg->stv_pas_middle_color[1] = (uint8_t)value;
    else if (!strcmp(name, "stv-pas-middle-color-B"))       cfg->stv_pas_middle_color[2] = (uint8_t)value;
    else if (!strcmp(name, "stv-pas-far-color-R"))          cfg->stv_pas_far_color[0] = (uint8_t)value;
    else if (!strcmp(name, "stv-pas-far-color-G"))          cfg->stv_pas_far_color[1] = (uint8_t)value;
    else if (!strcmp(name, "stv-pas-far-color-B"))          cfg->stv_pas_far_color[2] = (uint8_t)value;
    else if (!strcmp(name, "stv-pas-max-color-R"))          cfg->stv_pas_max_color[0] = (uint8_t)value;
    else if (!strcmp(name, "stv-pas-max-color-G"))          cfg->stv_pas_max_color[1] = (uint8_t)value;
    else if (!strcmp(name, "stv-pas-max-color-B"))          cfg->stv_pas_max_color[2] = (uint8_t)value;

    else if (!strcmp(name, "stv-obstacle-color-R"))         cfg->stv_obstacle_color[0] = (uint8_t)value;
    else if (!strcmp(name, "stv-obstacle-color-G"))         cfg->stv_obstacle_color[1] = (uint8_t)value;
    else if (!strcmp(name, "stv-obstacle-color-B"))         cfg->stv_obstacle_color[2] = (uint8_t)value;
    else if (!strcmp(name, "stv-obstacle-line-color-R"))    cfg->stv_obstacle_line_color[0] = (uint8_t)value;
    else if (!strcmp(name, "stv-obstacle-line-color-G"))    cfg->stv_obstacle_line_color[1] = (uint8_t)value;
    else if (!strcmp(name, "stv-obstacle-line-color-B"))    cfg->stv_obstacle_line_color[2] = (uint8_t)value;
    else if (!strcmp(name, "stv-obstacle-transparency"))    cfg->stv_obstacle_transparency = (uint8_t)value;
    else if (!strcmp(name, "stv-obstacle-line-transparency"))cfg->stv_obstacle_line_transparency = (uint8_t)value;
    else if (!strcmp(name, "stv-obstacle-line-width"))      cfg->stv_obstacle_line_width = value;

    else if (!strcmp(name, "Revert"))                       vm_tweak_pas_revert(cfg, pas, tag);

    else                                    return TRACE(1, _b("pas unknown param: %s=%f"), name, value), 0;

    return 1;
}

/**
 * @brief   ODO state configuration
 */
static inline void vm_tweak_odo_setup(odo_state_t *cfg, char *tag)
{
    char    buffer[256], *p;
    int     i;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    tweak_add_widget("ODO");
    for (i = 0; i < ODO_OBJECTS_NUMBER; i++)
    {
        tweak_add_layout(200, ((i & 1) == 0 ? 0 : 1), "");

        snprintf(p, sizeof(buffer) - (int)(p - buffer), "NX-%d", i + 1);
        tweak_add_slider(buffer, -20, 20, cfg->near_x[i], 2);

        snprintf(p, sizeof(buffer) - (int)(p - buffer), "NY-%d", i + 1);
        tweak_add_slider(buffer, -20, 20, cfg->near_y[i], 2);

        snprintf(p, sizeof(buffer) - (int)(p - buffer), "LX-%d", i + 1);
        tweak_add_slider(buffer, -1.25, 1.25, cfg->left_x[i], 2);

        snprintf(p, sizeof(buffer) - (int)(p - buffer), "LY-%d", i + 1);
        tweak_add_slider(buffer, -1.25, 1.25, cfg->left_y[i], 2);

        snprintf(p, sizeof(buffer) - (int)(p - buffer), "RX-%d", i + 1);
        tweak_add_slider(buffer, -1.25, 1.25, cfg->right_x[i], 2);

        snprintf(p, sizeof(buffer) - (int)(p - buffer), "RY-%d", i + 1);
        tweak_add_slider(buffer, -1.25, 1.25, cfg->right_y[i], 2);

        snprintf(p, sizeof(buffer) - (int)(p - buffer), "Z-%d", i + 1);
        tweak_add_slider(buffer, 0, 1, cfg->zt[i], 2);

        snprintf(p, sizeof(buffer) - (int)(p - buffer), "rel-%d", i + 1);
        tweak_add_spinbox(buffer, 0, 7, cfg->reli[i], 0);
    }
}

static void vm_tweak_odo_refresh(odo_state_t *cfg, const char *tag)
{
    char    buf[256], *p;
    int     i;

    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    for (i = 0; i < ODO_OBJECTS_NUMBER; i++)
    {
        snprintf(p, sizeof(buf) - (int)(p - buf), "NX-%d", i + 1);
        tweak_set(buf, cfg->near_x[i]);
        snprintf(p, sizeof(buf) - (int)(p - buf), "NY-%d", i + 1);
        tweak_set(buf, cfg->near_y[i]);
        snprintf(p, sizeof(buf) - (int)(p - buf), "LX-%d", i + 1);
        tweak_set(buf, cfg->left_x[i]);
        snprintf(p, sizeof(buf) - (int)(p - buf), "LY-%d", i + 1);
        tweak_set(buf, cfg->left_y[i]);
        snprintf(p, sizeof(buf) - (int)(p - buf), "RX-%d", i + 1);
        tweak_set(buf, cfg->right_x[i]);
        snprintf(p, sizeof(buf) - (int)(p - buf), "RY-%d", i + 1);
        tweak_set(buf, cfg->right_y[i]);
        snprintf(p, sizeof(buf) - (int)(p - buf), "Z-%d", i + 1);
        tweak_set(buf, cfg->zt[i]);
        snprintf(p, sizeof(buf) - (int)(p - buf), "rel-%d", i + 1);
        tweak_set(buf, cfg->reli[i]);
    }
}

static int vm_tweak_odo_update(odo_state_t *cfg, const char *tag, const char *name, double value)
{
    char   *t;
    int     i;

    if (!strncmp(name, "NX-", 3))
    {
        i = strtoul(name + 3, &t, 0);
        cfg->near_x[i - 1] = value;
    }
    else if (!strncmp(name, "NY-", 3))
    {
        i = strtoul(name + 3, &t, 0);
        cfg->near_y[i - 1] = value;
    }
    else if (!strncmp(name, "LX-", 3))
    {
        i = strtoul(name + 3, &t, 0);
        cfg->left_x[i - 1] = value;
    }
    else if (!strncmp(name, "LY-", 3))
    {
        i = strtoul(name + 3, &t, 0);
        cfg->left_y[i - 1] = value;
    }
    else if (!strncmp(name, "RX-", 3))
    {
        i = strtoul(name + 3, &t, 0);
        cfg->right_x[i - 1] = value;
    }
    else if (!strncmp(name, "RY-", 3))
    {
        i = strtoul(name + 3, &t, 0);
        cfg->right_y[i - 1] = value;
    }
    else if (!strncmp(name, "Z-", 2))
    {
        i = strtoul(name + 2, &t, 0);
        cfg->zt[i - 1] = value;
    }
    else if (!strncmp(name, "rel-", 4))
    {
        i = strtoul(name + 4, &t, 0);
        cfg->reli[i - 1] = (uint8_t)value;
    }
    else
    {
        return TRACE(1, _b("pas unknown param: %s=%f"), name, value), 0;
    }

    return 1;
}

/**
 * @brief   CTA state configuration
 */
static inline void vm_tweak_cta_setup(cta_state_t *cfg, char *tag, char *id)
{
    char    buffer[256], *p;
    int     i;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    tweak_add_layout(200, 0, id);
    tweak_add_spinbox((strcpy(p, "a-state"), buffer), 0, 6, cfg->a_state, 0);
    tweak_add_spinbox((strcpy(p, "a-target-lh"), buffer), 0, 3, cfg->a_target_lh, 0);
    tweak_add_spinbox((strcpy(p, "a-target-rh"), buffer), 0, 3, cfg->a_target_rh, 0);
    tweak_add_spinbox((strcpy(p, "b-state"), buffer), 0, 6, cfg->b_state, 0);
    tweak_add_spinbox((strcpy(p, "b-target-lh"), buffer), 0, 3, cfg->b_target_lh, 0);
    tweak_add_spinbox((strcpy(p, "b-target-rh"), buffer), 0, 3, cfg->b_target_rh, 0);

    tweak_add_layout(200, 1, id);
    tweak_add_checkbox((strcpy(p, "target-lh"), buffer), cfg->target_lh);
    tweak_add_checkbox((strcpy(p, "target-rh"), buffer), cfg->target_rh);
}

static void vm_tweak_cta_refresh(cta_state_t *cfg, const char *tag)
{
    char    buf[256], *p;
    int     i;

    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "a-state"), buf), cfg->a_state);
    tweak_set((strcpy(p, "a-target-lh"), buf), cfg->a_target_lh);
    tweak_set((strcpy(p, "a-target-rh"), buf), cfg->a_target_rh);
    tweak_set((strcpy(p, "b-state"), buf), cfg->b_state);
    tweak_set((strcpy(p, "b-target-lh"), buf), cfg->b_target_lh);
    tweak_set((strcpy(p, "b-target-rh"), buf), cfg->b_target_rh);

    tweak_set((strcpy(p, "target-lh"), buf), cfg->target_lh);
    tweak_set((strcpy(p, "target-rh"), buf), cfg->target_rh);

}

static int vm_tweak_cta_update(cta_state_t *cfg, const char *tag, const char *name, double value)
{
    if (!strcmp(name, "a-state"))               cfg->a_state = (uint32_t)value;
    else if (!strcmp(name, "a-target-lh"))      cfg->a_target_lh = (uint32_t)value;
    else if (!strcmp(name, "a-target-rh"))      cfg->a_target_rh = (uint32_t)value;
    else if (!strcmp(name, "b-state"))          cfg->b_state = (uint32_t)value;
    else if (!strcmp(name, "b-target-lh"))      cfg->b_target_lh = (uint32_t)value;
    else if (!strcmp(name, "b-target-rh"))      cfg->b_target_rh = (uint32_t)value;
    else if (!strcmp(name, "target-lh"))        cfg->target_lh = (uint32_t)value;
    else if (!strcmp(name, "target-rh"))        cfg->target_rh = (uint32_t)value;
    else return TRACE(1, _b("cta unknown param: %s=%f"), name, value), 0;

    return 1;
}

/**
 * @brief   Aiming state configuration
 */
static inline void vm_tweak_aiming_setup(aiming_state_t *cfg, char *tag)
{
    char    buffer[256], *p;
    int     i;

    tweak_add_widget("Aiming");

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    tweak_add_layout(200, 0, "Aiming Execution");
    tweak_add_spinbox((strcpy(p, "name"), buffer), 0, 1, cfg->name, 0);
    tweak_add_spinbox((strcpy(p, "status"), buffer), 0, 4, cfg->status, 0);
    tweak_add_spinbox((strcpy(p, "max-speed"), buffer), 0, 100, cfg->max_speed_value, 1);
    tweak_add_spinbox((strcpy(p, "max-steering"), buffer), 0, 30, cfg->max_steering_angle, 1);
    tweak_add_spinbox((strcpy(p, "front-camera-status"), buffer), 0, 4, cfg->camera_status[0], 0);
    tweak_add_spinbox((strcpy(p, "left-camera-status"), buffer), 0, 4, cfg->camera_status[1], 0);
    tweak_add_spinbox((strcpy(p, "rear-camera-status"), buffer), 0, 4, cfg->camera_status[2], 0);
    tweak_add_spinbox((strcpy(p, "right-camera-status"), buffer), 0, 4, cfg->camera_status[3], 0);
    tweak_add_slider((strcpy(p, "front-camera-progress"), buffer), 0, 100, cfg->camera_progress[0], 0);
    tweak_add_slider((strcpy(p, "left-camera-progress"), buffer), 0, 100, cfg->camera_progress[1], 0);
    tweak_add_slider((strcpy(p, "rear-camera-progress"), buffer), 0, 100, cfg->camera_progress[2], 0);
    tweak_add_slider((strcpy(p, "right-camera-progress"), buffer), 0, 100, cfg->camera_progress[3], 0);

    tweak_add_layout(200, 1, "Aiming Failure");
    tweak_add_checkbox((strcpy(p, "marker-0"), buffer), cfg->failure & 1);
    tweak_add_checkbox((strcpy(p, "marker-1"), buffer), cfg->failure & 2);
    tweak_add_checkbox((strcpy(p, "marker-2"), buffer), cfg->failure & 4);
    tweak_add_checkbox((strcpy(p, "marker-3"), buffer), cfg->failure & 8);
    tweak_add_checkbox((strcpy(p, "marker-4"), buffer), cfg->failure & 16);
    tweak_add_checkbox((strcpy(p, "marker-5"), buffer), cfg->failure & 32);
    tweak_add_checkbox((strcpy(p, "marker-6"), buffer), cfg->failure & 64);
    tweak_add_checkbox((strcpy(p, "marker-7"), buffer), cfg->failure & 128);
}

static void vm_tweak_aiming_refresh(aiming_state_t *cfg, const char *tag)
{
    char    buf[256], *p;
    int     i;

    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "name"), buf), cfg->name);
    tweak_set((strcpy(p, "status"), buf), cfg->status);
    tweak_set((strcpy(p, "max-speed"), buf), cfg->max_speed_value);
    tweak_set((strcpy(p, "max-steering"), buf), cfg->max_steering_angle);
    tweak_set((strcpy(p, "front-camera-status"), buf), cfg->camera_status[0]);
    tweak_set((strcpy(p, "left-camera-status"), buf), cfg->camera_status[1]);
    tweak_set((strcpy(p, "rear-camera-status"), buf), cfg->camera_status[2]);
    tweak_set((strcpy(p, "right-camera-status"), buf), cfg->camera_status[3]);
    tweak_set((strcpy(p, "front-camera-progress"), buf), cfg->camera_progress[0]);
    tweak_set((strcpy(p, "left-camera-progress"), buf), cfg->camera_progress[1]);
    tweak_set((strcpy(p, "rear-camera-progress"), buf), cfg->camera_progress[2]);
    tweak_set((strcpy(p, "right-camera-progress"), buf), cfg->camera_progress[3]);

    tweak_set((strcpy(p, "marker-0"), buf), cfg->failure & 1);
    tweak_set((strcpy(p, "marker-1"), buf), cfg->failure & 2);
    tweak_set((strcpy(p, "marker-2"), buf), cfg->failure & 4);
    tweak_set((strcpy(p, "marker-3"), buf), cfg->failure & 8);
    tweak_set((strcpy(p, "marker-4"), buf), cfg->failure & 16);
    tweak_set((strcpy(p, "marker-5"), buf), cfg->failure & 32);
    tweak_set((strcpy(p, "marker-6"), buf), cfg->failure & 64);
    tweak_set((strcpy(p, "marker-7"), buf), cfg->failure & 128);
}

static int vm_tweak_aiming_update(aiming_state_t *cfg, const char *tag, const char *name, double value)
{
    if (!strcmp(name, "name"))                  cfg->name = (uint32_t)value;
    else if (!strcmp(name, "status"))           cfg->status = (uint32_t)value;
    else if (!strcmp(name, "max-speed"))        cfg->max_speed_value = value;
    else if (!strcmp(name, "max-steering"))     cfg->max_steering_angle = value;
    else if (!strcmp(name, "front-camera-status"))  cfg->camera_status[0] = (uint32_t)value;
    else if (!strcmp(name, "left-camera-status"))   cfg->camera_status[1] = (uint32_t)value;
    else if (!strcmp(name, "rear-camera-status"))   cfg->camera_status[2] = (uint32_t)value;
    else if (!strcmp(name, "right-camera-status"))  cfg->camera_status[3] = (uint32_t)value;
    else if (!strcmp(name, "front-camera-progress"))cfg->camera_progress[0] = (uint32_t)value;
    else if (!strcmp(name, "left-camera-progress")) cfg->camera_progress[1] = (uint32_t)value;
    else if (!strcmp(name, "rear-camera-progress")) cfg->camera_progress[2] = (uint32_t)value;
    else if (!strcmp(name, "right-camera-progress"))cfg->camera_progress[3] = (uint32_t)value;
    else if (!strcmp(name, "marker-0"))             cfg->failure = (cfg->failure & ~1) | ((uint32_t)value << 0);
    else if (!strcmp(name, "marker-1"))             cfg->failure = (cfg->failure & ~2) | ((uint32_t)value << 1);
    else if (!strcmp(name, "marker-2"))             cfg->failure = (cfg->failure & ~4) | ((uint32_t)value << 2);
    else if (!strcmp(name, "marker-3"))             cfg->failure = (cfg->failure & ~8) | ((uint32_t)value << 3);
    else if (!strcmp(name, "marker-4"))             cfg->failure = (cfg->failure & ~16) | ((uint32_t)value << 4);
    else if (!strcmp(name, "marker-5"))             cfg->failure = (cfg->failure & ~32) | ((uint32_t)value << 5);
    else if (!strcmp(name, "marker-6"))             cfg->failure = (cfg->failure & ~64) | ((uint32_t)value << 6);
    else if (!strcmp(name, "marker-7"))             cfg->failure = (cfg->failure & ~128) | ((uint32_t)value << 7);

    return 1;
}

/**
 * @brief   Car renderer configuration setup
 */
static inline void vm_tweak_car_renderer_setup(cfg_car_render_t *cfg, char *tag)
{
    char    buffer[256], *p;
    int     i;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    /* ...make a copy of default configuration */
    memcpy(&__vm_tweak_car_render_cfg, cfg, sizeof(*cfg));

    tweak_add_widget("Car renderer");

    tweak_add_layout(200, 0, "");
    tweak_add_spinbox((strcpy(p, "mask-ambient-color-R"), buffer), 0, 255, cfg->mask_ambient_color[0], 0);
    tweak_add_spinbox((strcpy(p, "mask-ambient-color-G"), buffer), 0, 255, cfg->mask_ambient_color[1], 0);
    tweak_add_spinbox((strcpy(p, "mask-ambient-color-B"), buffer), 0, 255, cfg->mask_ambient_color[2], 0);

    tweak_add_spinbox((strcpy(p, "wheel-ambient-color-R"), buffer), 0, 255, cfg->wheel_ambient_color[0], 0);
    tweak_add_spinbox((strcpy(p, "wheel-ambient-color-G"), buffer), 0, 255, cfg->wheel_ambient_color[1], 0);
    tweak_add_spinbox((strcpy(p, "wheel-ambient-color-B"), buffer), 0, 255, cfg->wheel_ambient_color[2], 0);

    tweak_add_spinbox((strcpy(p, "lights-tail-base-color-R"), buffer), 0, 255, cfg->lights_tail_base_color[0], 0);
    tweak_add_spinbox((strcpy(p, "lights-tail-base-color-G"), buffer), 0, 255, cfg->lights_tail_base_color[1], 0);
    tweak_add_spinbox((strcpy(p, "lights-tail-base-color-B"), buffer), 0, 255, cfg->lights_tail_base_color[2], 0);
    tweak_add_spinbox((strcpy(p, "lights-tail-base-trans"), buffer), 0, 100, cfg->lights_tail_base_color[3], 0);

    tweak_add_spinbox((strcpy(p, "lights-tail-lens-color-R"), buffer), 0, 255, cfg->lights_tail_lens_color[0], 0);
    tweak_add_spinbox((strcpy(p, "lights-tail-lens-color-G"), buffer), 0, 255, cfg->lights_tail_lens_color[1], 0);
    tweak_add_spinbox((strcpy(p, "lights-tail-lens-color-B"), buffer), 0, 255, cfg->lights_tail_lens_color[2], 0);
    tweak_add_spinbox((strcpy(p, "lights-tail-lens-trans"), buffer), 0, 100, cfg->lights_tail_lens_color[3], 0);

    tweak_add_spinbox((strcpy(p, "lights-tail-shine-color-R"), buffer), 0, 255, cfg->lights_tail_shine_color[0], 0);
    tweak_add_spinbox((strcpy(p, "lights-tail-shine-color-G"), buffer), 0, 255, cfg->lights_tail_shine_color[1], 0);
    tweak_add_spinbox((strcpy(p, "lights-tail-shine-color-B"), buffer), 0, 255, cfg->lights_tail_shine_color[2], 0);
    tweak_add_spinbox((strcpy(p, "lights-tail-shine-trans"), buffer), 0, 100, cfg->lights_tail_shine_color[3], 0);

    tweak_add_spinbox((strcpy(p, "lights-tail-corner-color-R"), buffer), 0, 255, cfg->lights_tail_corner_color[0], 0);
    tweak_add_spinbox((strcpy(p, "lights-tail-corner-color-G"), buffer), 0, 255, cfg->lights_tail_corner_color[1], 0);
    tweak_add_spinbox((strcpy(p, "lights-tail-corner-color-B"), buffer), 0, 255, cfg->lights_tail_corner_color[2], 0);
    tweak_add_spinbox((strcpy(p, "lights-tail-corner-trans"), buffer), 0, 100, cfg->lights_tail_corner_color[3], 0);

    tweak_add_layout(200, 0, "");
    tweak_add_slider((strcpy(p, "window-front-opaqueness"), buffer), 0, 1, cfg->window_front_opaqueness, 2);
    tweak_add_slider((strcpy(p, "window-rear-opaqueness"), buffer), 0, 1, cfg->window_rear_opaqueness, 2);
    tweak_add_slider((strcpy(p, "body-opaqueness"), buffer), 0, 1, cfg->body_opaqueness, 2);
    tweak_add_slider((strcpy(p, "head-opaqueness"), buffer), 0, 1, cfg->head_opaqueness, 2);
    tweak_add_slider((strcpy(p, "mask-opaqueness"), buffer), 0, 1, cfg->mask_opaqueness, 2);
    tweak_add_slider((strcpy(p, "wheel-height-min"), buffer), -1000, 1000, cfg->wheel_height_min, 0);
    tweak_add_slider((strcpy(p, "wheel-height-max"), buffer), -1000, 1000, cfg->wheel_height_max, 0);
    tweak_add_slider((strcpy(p, "wheel-gradient-exp"), buffer), 0, 10, cfg->wheel_gradient_exp, 2);
    tweak_add_slider((strcpy(p, "rear-gradient-x"), buffer), -3000, 3000, cfg->rear_gradient_x, 0);
    tweak_add_slider((strcpy(p, "rear-gradient-scale"), buffer), 0, 1, cfg->rear_gradient_scale, 4);
    tweak_add_slider((strcpy(p, "front-gradient-x"), buffer), -3000, 3000, cfg->front_gradient_x, 0);
    tweak_add_slider((strcpy(p, "front-gradient-scale"), buffer), 0, 1, cfg->front_gradient_scale, 4);

    tweak_add_slider((strcpy(p, "height-gradient-z"), buffer), 0, 3000, cfg->height_gradient_z, 0);
    tweak_add_slider((strcpy(p, "height-gradient-scale"), buffer), 0, 1, cfg->height_gradient_scale, 4);

    tweak_add_slider((strcpy(p, "front-mask-gradient-start"), buffer), -1.0, 1.0, cfg->front_mask_gradient_start, 3);
    tweak_add_slider((strcpy(p, "front-mask-gradient-stop"), buffer), -1.0, 1.0, cfg->front_mask_gradient_stop, 3);
    tweak_add_slider((strcpy(p, "front-mask-gradient-exp"), buffer), 0, 10, cfg->front_mask_gradient_exp, 4);

    tweak_add_slider((strcpy(p, "rear-mask-gradient-start"), buffer), -1.0, 1.0, cfg->rear_mask_gradient_start, 3);
    tweak_add_slider((strcpy(p, "rear-mask-gradient-stop"), buffer), -1.0, 1.0, cfg->rear_mask_gradient_stop, 3);
    tweak_add_slider((strcpy(p, "rear-mask-gradient-exp"), buffer), 0, 10, cfg->rear_mask_gradient_exp, 4);

    tweak_add_slider((strcpy(p, "front-wheel-width-scale"), buffer), 0, 2, cfg->front_wheel_width_scale, 3);
    tweak_add_slider((strcpy(p, "rear-wheel-width-scale"), buffer), 0, 2, cfg->rear_wheel_width_scale, 3);

    tweak_add_layout(200, 1, "");
    tweak_add_checkbox((strcpy(p, "mask-disable"), buffer), cfg->mask_disable);
    tweak_add_button((strcpy(p, "Revert"), buffer));
}

static void vm_tweak_car_renderer_refresh(cfg_car_render_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "window-front-opaqueness"), buf), cfg->window_front_opaqueness);
    tweak_set((strcpy(p, "window-rear-opaqueness"), buf), cfg->window_rear_opaqueness);
    tweak_set((strcpy(p, "body-opaqueness"), buf), cfg->body_opaqueness);
    tweak_set((strcpy(p, "head-opaqueness"), buf), cfg->head_opaqueness);
    tweak_set((strcpy(p, "mask-opaqueness"), buf), cfg->mask_opaqueness);
    tweak_set((strcpy(p, "wheel-height-min"), buf), cfg->wheel_height_min);
    tweak_set((strcpy(p, "wheel-height-max"), buf), cfg->wheel_height_max);
    tweak_set((strcpy(p, "wheel-gradient-exp"), buf), cfg->wheel_gradient_exp);
    tweak_set((strcpy(p, "rear-gradient-x"), buf), cfg->rear_gradient_x);
    tweak_set((strcpy(p, "rear-gradient-scale"), buf), cfg->rear_gradient_scale);
    tweak_set((strcpy(p, "front-gradient-x"), buf), cfg->front_gradient_x);
    tweak_set((strcpy(p, "front-gradient-scale"), buf), cfg->front_gradient_scale);
    tweak_set((strcpy(p, "height-gradient-z"), buf), cfg->height_gradient_z);
    tweak_set((strcpy(p, "height-gradient-scale"), buf), cfg->height_gradient_scale);
    tweak_set((strcpy(p, "front-mask-gradient-start"), buf), cfg->front_mask_gradient_start);
    tweak_set((strcpy(p, "front-mask-gradient-stop"), buf), cfg->front_mask_gradient_stop);
    tweak_set((strcpy(p, "front-mask-gradient-exp"), buf), cfg->front_mask_gradient_exp);
    tweak_set((strcpy(p, "rear-mask-gradient-start"), buf), cfg->rear_mask_gradient_start);
    tweak_set((strcpy(p, "rear-mask-gradient-stop"), buf), cfg->rear_mask_gradient_stop);
    tweak_set((strcpy(p, "rear-mask-gradient-exp"), buf), cfg->rear_mask_gradient_exp);
    tweak_set((strcpy(p, "front-wheel-width-scale"), buf), cfg->front_wheel_width_scale);
    tweak_set((strcpy(p, "rear-wheel-width-scale"), buf), cfg->rear_wheel_width_scale);

    tweak_set((strcpy(p, "mask-ambient-color-R"), buf), cfg->mask_ambient_color[0]);
    tweak_set((strcpy(p, "mask-ambient-color-G"), buf), cfg->mask_ambient_color[1]);
    tweak_set((strcpy(p, "mask-ambient-color-B"), buf), cfg->mask_ambient_color[2]);

    tweak_set((strcpy(p, "wheel-ambient-color-R"), buf), cfg->wheel_ambient_color[0]);
    tweak_set((strcpy(p, "wheel-ambient-color-G"), buf), cfg->wheel_ambient_color[1]);
    tweak_set((strcpy(p, "wheel-ambient-color-B"), buf), cfg->wheel_ambient_color[2]);

    tweak_set((strcpy(p, "lights-tail-base-color-R"), buf), cfg->lights_tail_base_color[0]);
    tweak_set((strcpy(p, "lights-tail-base-color-G"), buf), cfg->lights_tail_base_color[1]);
    tweak_set((strcpy(p, "lights-tail-base-color-B"), buf), cfg->lights_tail_base_color[2]);
    tweak_set((strcpy(p, "lights-tail-base-trans"), buf), cfg->lights_tail_base_color[3]);

    tweak_set((strcpy(p, "lights-tail-lens-color-R"), buf), cfg->lights_tail_lens_color[0]);
    tweak_set((strcpy(p, "lights-tail-lens-color-G"), buf), cfg->lights_tail_lens_color[1]);
    tweak_set((strcpy(p, "lights-tail-lens-color-B"), buf), cfg->lights_tail_lens_color[2]);
    tweak_set((strcpy(p, "lights-tail-lens-trans"), buf), cfg->lights_tail_lens_color[3]);

    tweak_set((strcpy(p, "lights-tail-shine-color-R"), buf), cfg->lights_tail_shine_color[0]);
    tweak_set((strcpy(p, "lights-tail-shine-color-G"), buf), cfg->lights_tail_shine_color[1]);
    tweak_set((strcpy(p, "lights-tail-shine-color-B"), buf), cfg->lights_tail_shine_color[2]);
    tweak_set((strcpy(p, "lights-tail-shine-trans"), buf), cfg->lights_tail_shine_color[3]);

    tweak_set((strcpy(p, "lights-tail-corner-color-R"), buf), cfg->lights_tail_corner_color[0]);
    tweak_set((strcpy(p, "lights-tail-corner-color-G"), buf), cfg->lights_tail_corner_color[1]);
    tweak_set((strcpy(p, "lights-tail-corner-color-B"), buf), cfg->lights_tail_corner_color[2]);
    tweak_set((strcpy(p, "lights-tail-corner-trans"), buf), cfg->lights_tail_corner_color[3]);

    tweak_set((strcpy(p, "mask-disable"), buf), cfg->mask_disable);
}

static void vm_tweak_car_renderer_revert(cfg_car_render_t *cfg, const char *tag)
{
    memcpy(cfg, &__vm_tweak_car_render_cfg, sizeof(*cfg));
    vm_tweak_car_renderer_refresh(cfg, tag);
}

static int vm_tweak_car_renderer_update(cfg_car_render_t *cfg, const char *tag, const char *name, double value)
{
    if (!strcmp(name, "window-front-opaqueness"))   cfg->window_front_opaqueness = value;
    else if (!strcmp(name, "window-rear-opaqueness"))cfg->window_rear_opaqueness = value;
    else if (!strcmp(name, "body-opaqueness"))      cfg->body_opaqueness = value;
    else if (!strcmp(name, "head-opaqueness"))      cfg->head_opaqueness = value;
    else if (!strcmp(name, "mask-opaqueness"))      cfg->mask_opaqueness = value;
    else if (!strcmp(name, "wheel-height-min"))     cfg->wheel_height_min = value;
    else if (!strcmp(name, "wheel-height-max"))     cfg->wheel_height_max = value;
    else if (!strcmp(name, "wheel-gradient-exp"))   cfg->wheel_gradient_exp = value;
    else if (!strcmp(name, "rear-gradient-x"))      cfg->rear_gradient_x = value;
    else if (!strcmp(name, "rear-gradient-scale"))  cfg->rear_gradient_scale = value;
    else if (!strcmp(name, "front-gradient-x"))     cfg->front_gradient_x = value;
    else if (!strcmp(name, "front-gradient-scale")) cfg->front_gradient_scale = value;
    else if (!strcmp(name, "height-gradient-z"))    cfg->height_gradient_z = value;
    else if (!strcmp(name, "height-gradient-scale"))cfg->height_gradient_scale = value;
    else if (!strcmp(name, "front-mask-gradient-start"))cfg->front_mask_gradient_start = value;
    else if (!strcmp(name, "front-mask-gradient-stop")) cfg->front_mask_gradient_stop = value;
    else if (!strcmp(name, "front-mask-gradient-exp"))  cfg->front_mask_gradient_exp = value;
    else if (!strcmp(name, "rear-mask-gradient-start")) cfg->rear_mask_gradient_start = value;
    else if (!strcmp(name, "rear-mask-gradient-stop"))  cfg->rear_mask_gradient_stop = value;
    else if (!strcmp(name, "rear-mask-gradient-exp"))   cfg->rear_mask_gradient_exp = value;
    else if (!strcmp(name, "front-wheel-width-scale"))  cfg->front_wheel_width_scale = value;
    else if (!strcmp(name, "rear-wheel-width-scale"))   cfg->rear_wheel_width_scale = value;

    else if (!strcmp(name, "mask-ambient-color-R"))cfg->mask_ambient_color[0] = (uint8_t)value;
    else if (!strcmp(name, "mask-ambient-color-G"))cfg->mask_ambient_color[1] = (uint8_t)value;
    else if (!strcmp(name, "mask-ambient-color-B"))cfg->mask_ambient_color[2] = (uint8_t)value;
    else if (!strcmp(name, "wheel-ambient-color-R"))cfg->wheel_ambient_color[0] = (uint8_t)value;
    else if (!strcmp(name, "wheel-ambient-color-G"))cfg->wheel_ambient_color[1] = (uint8_t)value;
    else if (!strcmp(name, "wheel-ambient-color-B"))cfg->wheel_ambient_color[2] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-base-color-R"))cfg->lights_tail_base_color[0] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-base-color-G"))cfg->lights_tail_base_color[1] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-base-color-B"))cfg->lights_tail_base_color[2] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-base-trans"))cfg->lights_tail_base_color[3] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-lens-color-R"))cfg->lights_tail_lens_color[0] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-lens-color-G"))cfg->lights_tail_lens_color[1] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-lens-color-B"))cfg->lights_tail_lens_color[2] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-lens-trans"))cfg->lights_tail_lens_color[3] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-shine-color-R"))cfg->lights_tail_shine_color[0] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-shine-color-G"))cfg->lights_tail_shine_color[1] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-shine-color-B"))cfg->lights_tail_shine_color[2] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-shine-trans"))cfg->lights_tail_shine_color[3] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-corner-color-R"))cfg->lights_tail_corner_color[0] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-corner-color-G"))cfg->lights_tail_corner_color[1] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-corner-color-B"))cfg->lights_tail_corner_color[2] = (uint8_t)value;
    else if (!strcmp(name, "lights-tail-corner-trans"))cfg->lights_tail_corner_color[3] = (uint8_t)value;
    else if (!strcmp(name, "mask-disable"))         cfg->mask_disable = (int)value;
    else if (!strcmp(name, "Revert"))               vm_tweak_car_renderer_revert(cfg, tag);
    else return TRACE(1, _b("unknown param: %s=%f"), name, value), 0;

    return 1;
}

static inline cfg_guide_dynamic_fr_t * vm_tweak_guide_dynamic_fr(cfg_guide_t *cfg)
{
    if (__vm_tweak_guide_dynamic_fr == 0)       return &cfg->dynamic_front;
    else if (__vm_tweak_guide_dynamic_fr == 1)  return &cfg->dynamic_rear;
    else if (__vm_tweak_guide_dynamic_fr == 2)  return &cfg->dynamic_front_stv;
    else                                        return &cfg->dynamic_rear_stv;
}

static inline cfg_guide_dynamic_sv_t * vm_tweak_guide_dynamic_sv(cfg_guide_t *cfg)
{
    if (__vm_tweak_guide_dynamic_sv == 0)   return &cfg->dynamic_sv;
    else                                    return &cfg->dynamic_sv_stv;
}

static inline cfg_guide_fixed_fr_t * vm_tweak_guide_fixed(cfg_guide_t *cfg)
{
    if (__vm_tweak_guide_fixed == 0)        return &cfg->fixed_front;
    else if (__vm_tweak_guide_fixed == 1)   return &cfg->fixed_front_wide;
    else if (__vm_tweak_guide_fixed == 2)   return &cfg->fixed_rear;
    else                                    return &cfg->fixed_rear_wide;
}

static inline cfg_guide_tha_t * vm_tweak_guide_tha(cfg_guide_t *cfg)
{
    return &cfg->tha;
}

/**
 * @brief   Guidelines configuration setup
 */
static inline void vm_tweak_guide_setup(cfg_guide_t *cfg, char *tag)
{
    char    buffer[256], *p;
    int     i;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    /* ...make a copy of default configuration */
    memcpy(&__vm_tweak_guide_cfg, cfg, sizeof(*cfg));

    tweak_add_widget("Guidelines");
    tweak_add_layout(100, 0, "Dynamic-FR");
    tweak_add_groupbox((strcpy(p, "fr:type"), buffer), "front;rear;front-stv;rear-stv", 0);

    cfg_guide_dynamic_fr_t *dynamic = vm_tweak_guide_dynamic_fr(cfg);

    tweak_add_slider((strcpy(p, "fr:total-length"), buffer), 1000, 8000, dynamic->total_length, 2);
    tweak_add_slider((strcpy(p, "fr:vehicle-width"), buffer), 1000, 3000, dynamic->vehicle_width, 2);
    tweak_add_slider((strcpy(p, "fr:hidden-width"), buffer), 0, 500, dynamic->hidden_width, 2);
    tweak_add_slider((strcpy(p, "fr:vehicle-trajectory-width"), buffer), 0, 1000, dynamic->vehicle_trajectory_width, 2);
    tweak_add_slider((strcpy(p, "fr:wheel-width"), buffer), 0, 1000, dynamic->wheel_width, 2);
    tweak_add_slider((strcpy(p, "fr:wheel-border-width"), buffer), 0, 100, dynamic->wheel_border_width, 2);
    tweak_add_slider((strcpy(p, "fr:wheel-lateral-distance"), buffer), 0, 3000, dynamic->wheel_lateral_distance, 2);
    tweak_add_slider((strcpy(p, "fr:center-trajectory-z"), buffer), 0, 400, dynamic->center_trajectory_z, 2);
    tweak_add_slider((strcpy(p, "fr:center-trajectory-width"), buffer), 0, 400, dynamic->center_trajectory_width, 2);
    tweak_add_slider((strcpy(p, "fr:distance-marker-1"), buffer), 0, 8000, dynamic->distance_marker_1, 2);
    tweak_add_slider((strcpy(p, "fr:distance-marker-2"), buffer), 0, 8000, dynamic->distance_marker_2, 2);
    tweak_add_slider((strcpy(p, "fr:distance-marker-3"), buffer), 0, 8000, dynamic->distance_marker_3, 2);
    tweak_add_slider((strcpy(p, "fr:distance-marker-middle"), buffer), 0, 8000, dynamic->distance_marker_middle, 2);
    tweak_add_slider((strcpy(p, "fr:distance-marker-width"), buffer), 0, 500, dynamic->distance_marker_width, 2);
    tweak_add_slider((strcpy(p, "fr:distance-marker-length"), buffer), 0, 3000, dynamic->distance_marker_length, 2);
    tweak_add_slider((strcpy(p, "fr:horizontal-line-width"), buffer), 0, 500, dynamic->horizontal_line_width, 2);
    tweak_add_slider((strcpy(p, "fr:fade-section-start-length"), buffer), 0, 1500, dynamic->fade_section_start_length, 0);
    tweak_add_slider((strcpy(p, "fr:fade-section-end-length"), buffer), 0, 1500, dynamic->fade_section_end_length, 0);
    tweak_add_slider((strcpy(p, "fr:side-angle-threshold"), buffer), 0, 90, dynamic->side_angle_threshold, 1);

    tweak_add_layout(100, 0, "Fixed-FR");

    cfg_guide_fixed_fr_t   *fixed = &cfg->fixed_front;
    tweak_add_groupbox((strcpy(p, "fx:type"), buffer), "front;front-wide;rear;rear-wide", 0);
    tweak_add_slider((strcpy(p, "fx:total-length"), buffer), 1000, 4000, fixed->total_length, 0);
    tweak_add_slider((strcpy(p, "fx:total-width"), buffer), 1000, 3000, fixed->total_width, 0);
    tweak_add_slider((strcpy(p, "fx:front-gap"), buffer), 0, 2000, fixed->front_gap, 0);
    tweak_add_slider((strcpy(p, "fx:rear-gap"), buffer), 0, 2000, fixed->rear_gap, 0);
    tweak_add_slider((strcpy(p, "fx:line-width"), buffer), 0, 500, fixed->line_width, 0);
    tweak_add_slider((strcpy(p, "fx:close-section-length"), buffer), 0, 4000, fixed->close_section_length, 0);
    tweak_add_slider((strcpy(p, "fx:close-interlock-width"), buffer), 0, 500, fixed->close_interlock_width, 0);
    tweak_add_slider((strcpy(p, "fx:close-interlock-gap"), buffer), 0, 500, fixed->close_interlock_gap, 0);
    tweak_add_slider((strcpy(p, "fx:surface-close-width"), buffer), 0, 500, fixed->surface_close_width, 0);
    tweak_add_slider((strcpy(p, "fx:surface-close-gap"), buffer), 0, 500, fixed->surface_close_gap, 0);
    tweak_add_slider((strcpy(p, "fx:fade-section-start-length"), buffer), 0, 1500, fixed->fade_section_start_length, 0);
    tweak_add_slider((strcpy(p, "fx:fade-section-end-length"), buffer), 0, 1500, fixed->fade_section_end_length, 0);

    cfg_guide_fixed_sv_t   *fixed_sv = &cfg->fixed_sv;
    tweak_add_layout(100, 1, "Fixed-SV");
    tweak_add_slider((strcpy(p, "fs:total-length"), buffer), 0, 6000, fixed_sv->total_length, 0);
    tweak_add_slider((strcpy(p, "fs:total-width"), buffer), 0, 2500, fixed_sv->total_width, 0);
    tweak_add_slider((strcpy(p, "fs:vert-line-width"), buffer), 0, 500, fixed_sv->vert_line_width, 0);
    tweak_add_slider((strcpy(p, "fs:hor-line-width"), buffer), 0, 500, fixed_sv->hor_line_width, 0);
    tweak_add_slider((strcpy(p, "fs:hor-line-gap"), buffer), 0, 500, fixed_sv->hor_line_gap, 0);
    tweak_add_slider((strcpy(p, "fs:hor-line-start"), buffer), 0, 1500, fixed_sv->hor_line_start, 0);
    tweak_add_slider((strcpy(p, "fs:vert-line-start"), buffer), 0, 2500, fixed_sv->vert_line_start, 0);
    tweak_add_slider((strcpy(p, "fs:bar-width"), buffer), 0, 500, fixed_sv->bar_width, 0);
    tweak_add_slider((strcpy(p, "fs:bar-fade-width"), buffer), 0, 500, fixed_sv->bar_fade_width, 0);
    tweak_add_slider((strcpy(p, "fs:hor-fade-length"), buffer), 0, 1500, fixed_sv->hor_fade_length, 0);
    tweak_add_slider((strcpy(p, "fs:vert-fade-length"), buffer), 0, 2500, fixed_sv->vert_fade_length, 0);

    tweak_add_layout(100, 0, "Dynamic-SV");
    tweak_add_groupbox((strcpy(p, "sv:type"), buffer), "sv;front-stv", 0);
    tweak_add_slider((strcpy(p, "sv:total-length"), buffer), 1000, 4000, cfg->dynamic_sv.total_length, 0);
    tweak_add_slider((strcpy(p, "sv:total-width"), buffer), 1000, 3000, cfg->dynamic_sv.total_width, 0);
    tweak_add_slider((strcpy(p, "sv:line-width"), buffer), 0, 200, cfg->dynamic_sv.line_width, 0);
    tweak_add_slider((strcpy(p, "sv:fade-section-start-length"), buffer), 0, 1500, cfg->dynamic_sv.fade_section_start_length, 0);
    tweak_add_slider((strcpy(p, "sv:fade-section-end-length"), buffer), 0, 1500, cfg->dynamic_sv.fade_section_end_length, 0);
    tweak_add_slider((strcpy(p, "sv:delta-width"), buffer), 0, 20, cfg->dynamic_sv.delta_width, 1);

    tweak_add_layout(100, 1, "Top-View");
    tweak_add_slider((strcpy(p, "tv:total-length"), buffer), 1000, 4000, cfg->tv.total_length, 0);
    tweak_add_slider((strcpy(p, "tv:total-width"), buffer), 1000, 3000, cfg->tv.total_width, 0);
    tweak_add_slider((strcpy(p, "tv:front-gap"), buffer), 0, 2000, cfg->tv.front_gap, 0);
    tweak_add_slider((strcpy(p, "tv:rear-gap"), buffer), 0, 2000, cfg->tv.rear_gap, 0);
    tweak_add_slider((strcpy(p, "tv:line-width"), buffer), 0, 500, cfg->tv.line_width, 0);
    tweak_add_slider((strcpy(p, "tv:close-section-length"), buffer), 0, 4000, cfg->tv.close_section_length, 0);
    tweak_add_slider((strcpy(p, "tv:fade-section-start-length"), buffer), 0, 1500, cfg->tv.fade_section_start_length, 0);
    tweak_add_slider((strcpy(p, "tv:fade-section-end-length"), buffer), 0, 1500, cfg->tv.fade_section_end_length, 0);

    tweak_add_layout(100, 1, "Top-View Colors");

    tweak_add_spinbox((strcpy(p, "tv-close-section-color-R"), buffer), 0, 255, cfg->tv_close_section_color[0], 0);
    tweak_add_spinbox((strcpy(p, "tv-close-section-color-G"), buffer), 0, 255, cfg->tv_close_section_color[1], 0);
    tweak_add_spinbox((strcpy(p, "tv-close-section-color-B"), buffer), 0, 255, cfg->tv_close_section_color[2], 0);
    tweak_add_slider((strcpy(p, "tv-close-section-transmittance"), buffer), 0, 100, cfg->tv_close_section_transmittance, 0);

    tweak_add_spinbox((strcpy(p, "tv-line-color-R"), buffer), 0, 255, cfg->tv_line_color[0], 0);
    tweak_add_spinbox((strcpy(p, "tv-line-color-G"), buffer), 0, 255, cfg->tv_line_color[1], 0);
    tweak_add_spinbox((strcpy(p, "tv-line-color-B"), buffer), 0, 255, cfg->tv_line_color[2], 0);
    tweak_add_slider((strcpy(p, "tv-line-transmittance"), buffer), 0, 100, cfg->tv_line_transmittance, 0);

    //tweak_add_layout(100, 0, "Fixed Colors");
    tweak_add_layout(100, 0, "Fixed Colors");
    tweak_add_spinbox((strcpy(p, "static-surface-close-color-R"), buffer), 0, 255, cfg->static_surface_close_color[0], 0);
    tweak_add_spinbox((strcpy(p, "static-surface-close-color-G"), buffer), 0, 255, cfg->static_surface_close_color[1], 0);
    tweak_add_spinbox((strcpy(p, "static-surface-close-color-B"), buffer), 0, 255, cfg->static_surface_close_color[2], 0);
    tweak_add_slider((strcpy(p, "static-surface-close-transmittance"), buffer), 0, 100, cfg->static_surface_close_transmittance, 0);

    tweak_add_spinbox((strcpy(p, "static-surface-color-R"), buffer), 0, 255, cfg->static_surface_color[0], 0);
    tweak_add_spinbox((strcpy(p, "static-surface-color-G"), buffer), 0, 255, cfg->static_surface_color[1], 0);
    tweak_add_spinbox((strcpy(p, "static-surface-color-B"), buffer), 0, 255, cfg->static_surface_color[2], 0);
    tweak_add_slider((strcpy(p, "static-surface-transmittance"), buffer), 0, 100, cfg->static_surface_transmittance, 0);

    tweak_add_spinbox((strcpy(p, "static-line-color-R"), buffer), 0, 255, cfg->static_line_color[0], 0);
    tweak_add_spinbox((strcpy(p, "static-line-color-G"), buffer), 0, 255, cfg->static_line_color[1], 0);
    tweak_add_spinbox((strcpy(p, "static-line-color-B"), buffer), 0, 255, cfg->static_line_color[2], 0);
    tweak_add_slider((strcpy(p, "static-line-transmittance"), buffer), 0, 100, cfg->static_line_transmittance, 0);

    tweak_add_layout(100, 1, "Dynamic Colors");
    tweak_add_spinbox((strcpy(p, "dynamic-close-section-color-R"), buffer), 0, 255, cfg->dynamic_close_section_color[0], 0);
    tweak_add_spinbox((strcpy(p, "dynamic-close-section-color-G"), buffer), 0, 255, cfg->dynamic_close_section_color[1], 0);
    tweak_add_spinbox((strcpy(p, "dynamic-close-section-color-B"), buffer), 0, 255, cfg->dynamic_close_section_color[2], 0);

    tweak_add_spinbox((strcpy(p, "dynamic-line-color-R"), buffer), 0, 255, cfg->dynamic_line_color[0], 0);
    tweak_add_spinbox((strcpy(p, "dynamic-line-color-G"), buffer), 0, 255, cfg->dynamic_line_color[1], 0);
    tweak_add_spinbox((strcpy(p, "dynamic-line-color-B"), buffer), 0, 255, cfg->dynamic_line_color[2], 0);
    tweak_add_slider((strcpy(p, "line-transmittance"), buffer), 0, 100, cfg->line_transmittance, 0);

    tweak_add_slider((strcpy(p, "dynamic-close-transmittance"), buffer), 0, 100, cfg->dynamic_close_transmittance, 0);
    tweak_add_slider((strcpy(p, "dynamic-middle-transmittance"), buffer), 0, 100, cfg->dynamic_middle_transmittance, 0);
    tweak_add_slider((strcpy(p, "dynamic-far-transmittance"), buffer), 0, 100, cfg->dynamic_far_transmittance, 0);

    tweak_add_layout(100, 1, "");
    tweak_add_button((strcpy(p, "Revert"), buffer));

    tweak_add_widget("THA Guidelines");

    cfg_guide_tha_t    *tha = vm_tweak_guide_tha(cfg);
    tweak_add_layout(100, 0, "Parameters");
    tweak_add_slider((strcpy(p, "tha:offset-x"), buffer), -100, 1000, tha->offset[0], 0);
    tweak_add_slider((strcpy(p, "tha:offset-y"), buffer), -500, 500, tha->offset[1], 0);
    tweak_add_slider((strcpy(p, "tha:offset-z"), buffer), 0, 1000, tha->offset[2], 0);

    tweak_add_slider((strcpy(p, "tha:angle"), buffer), 0, 180, tha->angle, 0);
    tweak_add_slider((strcpy(p, "tha:length"), buffer), 0, 10000, tha->length, 0);
    tweak_add_slider((strcpy(p, "tha:line-width"), buffer), 0, 500, tha->line_width, 0);
    tweak_add_slider((strcpy(p, "tha:border-width"), buffer), 0, 500, tha->border_width, 0);

    tweak_add_layout(100, 1, "Colors");
    tweak_add_spinbox((strcpy(p, "tha:canvas-color-R"), buffer), 0, 255, tha->canvas_color[0], 0);
    tweak_add_spinbox((strcpy(p, "tha:canvas-color-G"), buffer), 0, 255, tha->canvas_color[1], 0);
    tweak_add_spinbox((strcpy(p, "tha:canvas-color-B"), buffer), 0, 255, tha->canvas_color[2], 0);
    tweak_add_slider((strcpy(p, "tha:canvas-transmittance"), buffer), 0, 100, tha->canvas_transmittance, 0);

    tweak_add_spinbox((strcpy(p, "tha:line-color-R"), buffer), 0, 255, tha->line_color[0], 0);
    tweak_add_spinbox((strcpy(p, "tha:line-color-G"), buffer), 0, 255, tha->line_color[1], 0);
    tweak_add_spinbox((strcpy(p, "tha:line-color-B"), buffer), 0, 255, tha->line_color[2], 0);
    tweak_add_slider((strcpy(p, "tha:line-transmittance"), buffer), 0, 100, tha->line_transmittance, 0);
}

static void vm_tweak_guide_dynamic_fr_refresh(cfg_guide_dynamic_fr_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "total-length"), buf), cfg->total_length);
    tweak_set((strcpy(p, "vehicle-width"), buf), cfg->vehicle_width);
    tweak_set((strcpy(p, "hidden-width"), buf), cfg->hidden_width);
    tweak_set((strcpy(p, "vehicle-trajectory-width"), buf), cfg->vehicle_trajectory_width);
    tweak_set((strcpy(p, "wheel-width"), buf), cfg->wheel_width);
    tweak_set((strcpy(p, "wheel-border-width"), buf), cfg->wheel_border_width);
    tweak_set((strcpy(p, "wheel-lateral-distance"), buf), cfg->wheel_lateral_distance);
    tweak_set((strcpy(p, "center-trajectory-z"), buf), cfg->center_trajectory_z);
    tweak_set((strcpy(p, "center-trajectory-width"), buf), cfg->center_trajectory_width);
    tweak_set((strcpy(p, "distance-marker-1"), buf), cfg->distance_marker_1);
    tweak_set((strcpy(p, "distance-marker-2"), buf), cfg->distance_marker_2);
    tweak_set((strcpy(p, "distance-marker-3"), buf), cfg->distance_marker_3);
    tweak_set((strcpy(p, "distance-marker-middle"), buf), cfg->distance_marker_middle);
    tweak_set((strcpy(p, "distance-marker-width"), buf), cfg->distance_marker_width);
    tweak_set((strcpy(p, "distance-marker-length"), buf), cfg->distance_marker_length);
    tweak_set((strcpy(p, "horizontal-line-width"), buf), cfg->horizontal_line_width);
    tweak_set((strcpy(p, "fade-section-start-length"), buf), cfg->fade_section_start_length);
    tweak_set((strcpy(p, "fade-section-end-length"), buf), cfg->fade_section_end_length);
    tweak_set((strcpy(p, "side-angle-threshold"), buf), cfg->side_angle_threshold);
}

static void vm_tweak_guide_dynamic_sv_refresh(cfg_guide_dynamic_sv_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "total-length"), buf), cfg->total_length);
    tweak_set((strcpy(p, "total-width"), buf), cfg->total_width);
    tweak_set((strcpy(p, "line-width"), buf), cfg->line_width);
    tweak_set((strcpy(p, "fade-section-start-length"), buf), cfg->fade_section_start_length);
    tweak_set((strcpy(p, "fade-section-end-length"), buf), cfg->fade_section_end_length);
    tweak_set((strcpy(p, "delta-width"), buf), cfg->delta_width);
}

static void vm_tweak_guide_fixed_fr_refresh(cfg_guide_fixed_fr_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "total-length"), buf), cfg->total_length);
    tweak_set((strcpy(p, "total-width"), buf), cfg->total_width);
    tweak_set((strcpy(p, "line-width"), buf), cfg->line_width);
    tweak_set((strcpy(p, "front-gap"), buf), cfg->front_gap);
    tweak_set((strcpy(p, "rear-gap"), buf), cfg->rear_gap);
    tweak_set((strcpy(p, "close-section-length"), buf), cfg->close_section_length);
    tweak_set((strcpy(p, "close-interlock-width"), buf), cfg->close_interlock_width);
    tweak_set((strcpy(p, "close-interlock-gap"), buf), cfg->close_interlock_gap);
    tweak_set((strcpy(p, "static-surface-close-width"), buf), cfg->surface_close_width);
    tweak_set((strcpy(p, "static-surface-close-gap"), buf), cfg->surface_close_gap);
    tweak_set((strcpy(p, "fade-section-start-length"), buf), cfg->fade_section_start_length);
    tweak_set((strcpy(p, "fade-section-end-length"), buf), cfg->fade_section_end_length);
}

static void vm_tweak_guide_fixed_sv_refresh(cfg_guide_fixed_sv_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "total-length"), buf), cfg->total_length);
    tweak_set((strcpy(p, "total-width"), buf), cfg->total_width);
    tweak_set((strcpy(p, "vert-line-width"), buf), cfg->vert_line_width);
    tweak_set((strcpy(p, "hor-line-width"), buf), cfg->hor_line_width);
    tweak_set((strcpy(p, "hor-line-gap"), buf), cfg->hor_line_gap);
    tweak_set((strcpy(p, "hor-line-start"), buf), cfg->hor_line_start);
    tweak_set((strcpy(p, "vert-line-start"), buf), cfg->vert_line_start);
    tweak_set((strcpy(p, "bar-width"), buf), cfg->bar_width);
    tweak_set((strcpy(p, "bar-fade-width"), buf), cfg->bar_fade_width);
    tweak_set((strcpy(p, "hor-fade-length"), buf), cfg->hor_fade_length);
    tweak_set((strcpy(p, "vert-fade-length"), buf), cfg->vert_fade_length);
}

static void vm_tweak_guide_tv_refresh(cfg_guide_tv_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "total-length"), buf), cfg->total_length);
    tweak_set((strcpy(p, "total-width"), buf), cfg->total_width);
    tweak_set((strcpy(p, "line-width"), buf), cfg->line_width);
    tweak_set((strcpy(p, "front-gap"), buf), cfg->front_gap);
    tweak_set((strcpy(p, "rear-gap"), buf), cfg->rear_gap);
    tweak_set((strcpy(p, "close-section-length"), buf), cfg->close_section_length);
    tweak_set((strcpy(p, "fade-section-start-length"), buf), cfg->fade_section_start_length);
    tweak_set((strcpy(p, "fade-section-end-length"), buf), cfg->fade_section_end_length);
}

static void vm_tweak_guide_tha_refresh(cfg_guide_tha_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "offset-x"), buf), cfg->offset[0]);
    tweak_set((strcpy(p, "offset-y"), buf), cfg->offset[1]);
    tweak_set((strcpy(p, "offset-z"), buf), cfg->offset[2]);
    tweak_set((strcpy(p, "angle"), buf), cfg->angle);
    tweak_set((strcpy(p, "length"), buf), cfg->length);
    tweak_set((strcpy(p, "line-width"), buf), cfg->line_width);
    tweak_set((strcpy(p, "border-width"), buf), cfg->border_width);

    tweak_set((strcpy(p, "canvas-color-R"), buf), cfg->canvas_color[0]);
    tweak_set((strcpy(p, "canvas-color-G"), buf), cfg->canvas_color[1]);
    tweak_set((strcpy(p, "canvas-color-B"), buf), cfg->canvas_color[2]);
    tweak_set((strcpy(p, "canvas-transmittance"), buf), cfg->canvas_transmittance);

    tweak_set((strcpy(p, "line-color-R"), buf), cfg->line_color[0]);
    tweak_set((strcpy(p, "line-color-G"), buf), cfg->line_color[1]);
    tweak_set((strcpy(p, "line-color-B"), buf), cfg->line_color[2]);
    tweak_set((strcpy(p, "line-transmittance"), buf), cfg->line_transmittance);
}

static void vm_tweak_guide_refresh(cfg_guide_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    cfg_guide_dynamic_fr_t *dynamic_fr = vm_tweak_guide_dynamic_fr(cfg);
    vm_tweak_guide_dynamic_fr_refresh(dynamic_fr, (strcpy(p, "fr:"), buf));

    cfg_guide_dynamic_sv_t *dynamic_sv = vm_tweak_guide_dynamic_sv(cfg);
    vm_tweak_guide_dynamic_sv_refresh(dynamic_sv, (strcpy(p, "sv:"), buf));

    cfg_guide_fixed_fr_t   *fixed = vm_tweak_guide_fixed(cfg);
    vm_tweak_guide_fixed_fr_refresh(fixed, (strcpy(p, "fx:"), buf));
    vm_tweak_guide_fixed_sv_refresh(&cfg->fixed_sv, (strcpy(p, "fs:"), buf));
    vm_tweak_guide_tv_refresh(&cfg->tv, (strcpy(p, "tv:"), buf));
    vm_tweak_guide_tha_refresh(&cfg->tha, (strcpy(p, "tha:"), buf));

    tweak_set((strcpy(p, "static-surface-close-color-R"), buf), cfg->static_surface_close_color[0]);
    tweak_set((strcpy(p, "static-surface-close-color-G"), buf), cfg->static_surface_close_color[1]);
    tweak_set((strcpy(p, "static-surface-close-color-B"), buf), cfg->static_surface_close_color[2]);
    tweak_set((strcpy(p, "static-surface-close-transmittance"), buf), cfg->static_surface_close_transmittance);

    tweak_set((strcpy(p, "static-surface-color-R"), buf), cfg->static_surface_color[0]);
    tweak_set((strcpy(p, "static-surface-color-G"), buf), cfg->static_surface_color[1]);
    tweak_set((strcpy(p, "static-surface-color-B"), buf), cfg->static_surface_color[2]);
    tweak_set((strcpy(p, "static-surface-transmittance"), buf), cfg->static_surface_transmittance);

    tweak_set((strcpy(p, "static-line-color-R"), buf), cfg->static_line_color[0]);
    tweak_set((strcpy(p, "static-line-color-G"), buf), cfg->static_line_color[1]);
    tweak_set((strcpy(p, "static-line-color-B"), buf), cfg->static_line_color[2]);
    tweak_set((strcpy(p, "static-line-transmittance"), buf), cfg->static_line_transmittance);

    tweak_set((strcpy(p, "dynamic-close-section-color-R"), buf), cfg->dynamic_close_section_color[0]);
    tweak_set((strcpy(p, "dynamic-close-section-color-G"), buf), cfg->dynamic_close_section_color[1]);
    tweak_set((strcpy(p, "dynamic-close-section-color-B"), buf), cfg->dynamic_close_section_color[2]);

    tweak_set((strcpy(p, "dynamic-line-color-R"), buf), cfg->dynamic_line_color[0]);
    tweak_set((strcpy(p, "dynamic-line-color-G"), buf), cfg->dynamic_line_color[1]);
    tweak_set((strcpy(p, "dynamic-line-color-B"), buf), cfg->dynamic_line_color[2]);
    tweak_set((strcpy(p, "line-transmittance"), buf), cfg->line_transmittance);
    tweak_set((strcpy(p, "dynamic-close-transmittance"), buf), cfg->dynamic_close_transmittance);
    tweak_set((strcpy(p, "dynamic-middle-transmittance"), buf), cfg->dynamic_middle_transmittance);
    tweak_set((strcpy(p, "dynamic-far-transmittance"), buf), cfg->dynamic_far_transmittance);

    tweak_set((strcpy(p, "tv-close-section-color-R"), buf), cfg->tv_close_section_color[0]);
    tweak_set((strcpy(p, "tv-close-section-color-G"), buf), cfg->tv_close_section_color[1]);
    tweak_set((strcpy(p, "tv-close-section-color-B"), buf), cfg->tv_close_section_color[2]);
    tweak_set((strcpy(p, "tv-close-section-transmittance"), buf), cfg->tv_close_section_transmittance);

    tweak_set((strcpy(p, "tv-line-color-R"), buf), cfg->tv_line_color[0]);
    tweak_set((strcpy(p, "tv-line-color-G"), buf), cfg->tv_line_color[1]);
    tweak_set((strcpy(p, "tv-line-color-B"), buf), cfg->tv_line_color[2]);
    tweak_set((strcpy(p, "tv-line-transmittance"), buf), cfg->tv_line_transmittance);

}

static void vm_tweak_guide_revert(cfg_guide_t *cfg, const char *tag)
{
    memcpy(cfg, &__vm_tweak_guide_cfg, sizeof(*cfg));
    vm_tweak_guide_refresh(cfg, tag);
}

static int vm_tweak_guide_dynamic_fr_update(cfg_guide_dynamic_fr_t *cfg, const char *tag, const char *name, double value)
{
    if (!strcmp(name, "total-length"))                      cfg->total_length = value;
    else if (!strcmp(name, "vehicle-width"))                cfg->vehicle_width = value;
    else if (!strcmp(name, "hidden-width"))                 cfg->hidden_width = value;
    else if (!strcmp(name, "vehicle-trajectory-width"))     cfg->vehicle_trajectory_width = value;
    else if (!strcmp(name, "wheel-width"))                  cfg->wheel_width = value;
    else if (!strcmp(name, "wheel-border-width"))           cfg->wheel_border_width = value;
    else if (!strcmp(name, "wheel-lateral-distance"))       cfg->wheel_lateral_distance = value;
    else if (!strcmp(name, "center-trajectory-z"))      cfg->center_trajectory_z = value;
    else if (!strcmp(name, "center-trajectory-width"))      cfg->center_trajectory_width = value;
    else if (!strcmp(name, "distance-marker-1"))            cfg->distance_marker_1 = value;
    else if (!strcmp(name, "distance-marker-2"))            cfg->distance_marker_2 = value;
    else if (!strcmp(name, "distance-marker-3"))            cfg->distance_marker_3 = value;
    else if (!strcmp(name, "distance-marker-middle"))       cfg->distance_marker_middle = value;
    else if (!strcmp(name, "distance-marker-width"))        cfg->distance_marker_width = value;
    else if (!strcmp(name, "distance-marker-length"))       cfg->distance_marker_length = value;
    else if (!strcmp(name, "horizontal-line-width"))        cfg->horizontal_line_width = value;
    else if (!strcmp(name, "fade-section-start-length"))    cfg->fade_section_start_length = value;
    else if (!strcmp(name, "fade-section-end-length"))      cfg->fade_section_end_length = value;
    else if (!strcmp(name, "side-angle-threshold"))         cfg->side_angle_threshold = value;
    else return TRACE(1, _b("unknown param: %s=%f"), name, value), 0;

    return 1;
}

static int vm_tweak_guide_dynamic_sv_update(cfg_guide_dynamic_sv_t *cfg, const char *tag, const char *name, double value)
{
    if (!strcmp(name, "total-length"))                      cfg->total_length = value;
    else if (!strcmp(name, "total-width"))                  cfg->total_width = value;
    else if (!strcmp(name, "line-width"))                   cfg->line_width = value;
    else if (!strcmp(name, "fade-section-start-length"))    cfg->fade_section_start_length = value;
    else if (!strcmp(name, "fade-section-end-length"))      cfg->fade_section_end_length = value;
    else if (!strcmp(name, "delta-width"))                  cfg->delta_width = value;
    else return TRACE(1, _b("unknown param: %s=%f"), name, value), 0;

    return 1;
}

static int vm_tweak_guide_fixed_fr_update(cfg_guide_fixed_fr_t *cfg, const char *tag, const char *name, double value)
{
    if (!strcmp(name, "total-length"))                      cfg->total_length = value;
    else if (!strcmp(name, "total-width"))                  cfg->total_width = value;
    else if (!strcmp(name, "line-width"))                   cfg->line_width = value;
    else if (!strcmp(name, "front-gap"))                    cfg->front_gap = value;
    else if (!strcmp(name, "rear-gap"))                     cfg->rear_gap = value;
    else if (!strcmp(name, "close-section-length"))         cfg->close_section_length = value;
    else if (!strcmp(name, "close-interlock-width"))        cfg->close_interlock_width = value;
    else if (!strcmp(name, "close-interlock-gap"))          cfg->close_interlock_gap = value;
    else if (!strcmp(name, "surface-close-width"))          cfg->surface_close_width = value;
    else if (!strcmp(name, "surface-close-gap"))            cfg->surface_close_gap = value;
    else if (!strcmp(name, "fade-section-start-length"))    cfg->fade_section_start_length = value;
    else if (!strcmp(name, "fade-section-end-length"))      cfg->fade_section_end_length = value;
    else return TRACE(1, _b("unknown param: %s=%f"), name, value), 0;

    return 1;
}

static int vm_tweak_guide_fixed_sv_update(cfg_guide_fixed_sv_t *cfg, const char *tag, const char *name, double value)
{
    if (!strcmp(name, "total-length"))                      cfg->total_length = value;
    else if (!strcmp(name, "total-width"))                  cfg->total_width = value;
    else if (!strcmp(name, "vert-line-width"))              cfg->vert_line_width = value;
    else if (!strcmp(name, "hor-line-width"))               cfg->hor_line_width = value;
    else if (!strcmp(name, "hor-line-gap"))                 cfg->hor_line_gap = value;
    else if (!strcmp(name, "hor-line-start"))               cfg->hor_line_start = value;
    else if (!strcmp(name, "vert-line-start"))              cfg->vert_line_start = value;
    else if (!strcmp(name, "bar-width"))                    cfg->bar_width = value;
    else if (!strcmp(name, "bar-fade-width"))               cfg->bar_fade_width = value;
    else if (!strcmp(name, "hor-fade-length"))              cfg->hor_fade_length = value;
    else if (!strcmp(name, "vert-fade-length"))             cfg->vert_fade_length = value;
    else return TRACE(1, _b("unknown param: %s=%f"), name, value), 0;

    return 1;
}

static int vm_tweak_guide_tv_update(cfg_guide_tv_t *cfg, const char *tag, const char *name, double value)
{
    if (!strcmp(name, "total-length"))                      cfg->total_length = value;
    else if (!strcmp(name, "total-width"))                  cfg->total_width = value;
    else if (!strcmp(name, "line-width"))                   cfg->line_width = value;
    else if (!strcmp(name, "front-gap"))                    cfg->front_gap = value;
    else if (!strcmp(name, "rear-gap"))                     cfg->rear_gap = value;
    else if (!strcmp(name, "close-section-length"))         cfg->close_section_length = value;
    else if (!strcmp(name, "fade-section-start-length"))    cfg->fade_section_start_length = value;
    else if (!strcmp(name, "fade-section-end-length"))      cfg->fade_section_end_length = value;
    else return TRACE(1, _b("unknown param: %s=%f"), name, value), 0;

    return 1;
}

static int vm_tweak_guide_tha_update(cfg_guide_tha_t *cfg, const char *tag, const char *name, double value)
{
    if (!strcmp(name, "offset-x"))                          cfg->offset[0] = value;
    else if (!strcmp(name, "offset-y"))                     cfg->offset[1] = value;
    else if (!strcmp(name, "offset-z"))                     cfg->offset[2] = value;
    else if (!strcmp(name, "angle"))                        cfg->angle = value;
    else if (!strcmp(name, "length"))                       cfg->length = value;
    else if (!strcmp(name, "line-width"))                   cfg->line_width = value;
    else if (!strcmp(name, "border-width"))                 cfg->border_width = value;

    else if (!strcmp(name, "canvas-color-R"))               cfg->canvas_color[0] = (uint8_t)value;
    else if (!strcmp(name, "canvas-color-G"))               cfg->canvas_color[1] = (uint8_t)value;
    else if (!strcmp(name, "canvas-color-B"))               cfg->canvas_color[2] = (uint8_t)value;
    else if (!strcmp(name, "canvas-transmittance"))         cfg->canvas_transmittance = (uint8_t)value;

    else if (!strcmp(name, "line-color-R"))                 cfg->line_color[0] = (uint8_t)value;
    else if (!strcmp(name, "line-color-G"))                 cfg->line_color[1] = (uint8_t)value;
    else if (!strcmp(name, "line-color-B"))                 cfg->line_color[2] = (uint8_t)value;
    else if (!strcmp(name, "line-transmittance"))           cfg->line_transmittance = (uint8_t)value;

    else return TRACE(1, _b("unknown param: %s=%f"), name, value), 0;

    return 1;
}

static int vm_tweak_guide_update(cfg_guide_t *cfg, const char *tag, const char *name, double value)
{
    if (!strncmp(name, "fr:", 3))
    {
        if (!strcmp(name + 3, "type"))
        {
            if (__vm_tweak_guide_dynamic_fr != (int)value)
            {
                __vm_tweak_guide_dynamic_fr = (int)value;
                vm_tweak_guide_dynamic_fr_refresh(vm_tweak_guide_dynamic_fr(cfg), tag);
            }

            return 0;
        }

        return vm_tweak_guide_dynamic_fr_update(vm_tweak_guide_dynamic_fr(cfg), tag, name + 3, value);
    }
    else if (!strncmp(name, "sv:", 3))
    {
        if (!strcmp(name + 3, "type"))
        {
            if (__vm_tweak_guide_dynamic_sv != (int)value)
            {
                __vm_tweak_guide_dynamic_sv = (int)value;
                vm_tweak_guide_dynamic_sv_refresh(vm_tweak_guide_dynamic_sv(cfg), tag);
            }

            return 0;
        }

        return vm_tweak_guide_dynamic_sv_update(vm_tweak_guide_dynamic_sv(cfg), tag, name + 3, value);
    }
    else if (!strncmp(name, "fx:", 3))
    {
        if (!strcmp(name + 3, "type"))
        {
            if (__vm_tweak_guide_fixed != (int)value)
            {
                __vm_tweak_guide_fixed = (int)value;
                vm_tweak_guide_fixed_fr_refresh(vm_tweak_guide_fixed(cfg), tag);
            }

            return 0;
        }

        return vm_tweak_guide_fixed_fr_update(vm_tweak_guide_fixed(cfg), tag, name + 3, value);
    }
    else if (!strncmp(name, "fs:", 3))
    {
        return vm_tweak_guide_fixed_sv_update(&cfg->fixed_sv, tag, name + 3, value);
    }

    else if (!strncmp(name, "tv:", 3))
    {
        return vm_tweak_guide_tv_update(&cfg->tv, tag, name + 3, value);
    }

    else if (!strncmp(name, "tha:", 4))
    {
        return vm_tweak_guide_tha_update(&cfg->tha, tag, name + 4, value);
    }

    else if (!strcmp(name, "static-surface-close-color-R")) cfg->static_surface_close_color[0] = (uint8_t)value;
    else if (!strcmp(name, "static-surface-close-color-G")) cfg->static_surface_close_color[1] = (uint8_t)value;
    else if (!strcmp(name, "static-surface-close-color-B")) cfg->static_surface_close_color[2] = (uint8_t)value;
    else if (!strcmp(name, "static-surface-close-transmittance")) cfg->static_surface_close_transmittance = (uint8_t)value;

    else if (!strcmp(name, "static-surface-color-R"))       cfg->static_surface_color[0] = (uint8_t)value;
    else if (!strcmp(name, "static-surface-color-G"))       cfg->static_surface_color[1] = (uint8_t)value;
    else if (!strcmp(name, "static-surface-color-B"))       cfg->static_surface_color[2] = (uint8_t)value;
    else if (!strcmp(name, "static-surface-transmittance")) cfg->static_surface_transmittance = (uint8_t)value;

    else if (!strcmp(name, "static-line-color-R"))          cfg->static_line_color[0] = (uint8_t)value;
    else if (!strcmp(name, "static-line-color-G"))          cfg->static_line_color[1] = (uint8_t)value;
    else if (!strcmp(name, "static-line-color-B"))          cfg->static_line_color[2] = (uint8_t)value;
    else if (!strcmp(name, "static-line-transmittance"))    cfg->static_line_transmittance = (uint8_t)value;

    else if (!strcmp(name, "dynamic-close-section-color-R"))cfg->dynamic_close_section_color[0] = (uint8_t)value;
    else if (!strcmp(name, "dynamic-close-section-color-G"))cfg->dynamic_close_section_color[1] = (uint8_t)value;
    else if (!strcmp(name, "dynamic-close-section-color-B"))cfg->dynamic_close_section_color[2] = (uint8_t)value;

    else if (!strcmp(name, "dynamic-line-color-R"))         cfg->dynamic_line_color[0] = (uint8_t)value;
    else if (!strcmp(name, "dynamic-line-color-G"))         cfg->dynamic_line_color[1] = (uint8_t)value;
    else if (!strcmp(name, "dynamic-line-color-B"))         cfg->dynamic_line_color[2] = (uint8_t)value;
    else if (!strcmp(name, "line-transmittance"))           cfg->line_transmittance = (uint8_t)value;
    else if (!strcmp(name, "dynamic-close-transmittance"))  cfg->dynamic_close_transmittance = (uint8_t)value;
    else if (!strcmp(name, "dynamic-middle-transmittance")) cfg->dynamic_middle_transmittance = (uint8_t)value;
    else if (!strcmp(name, "dynamic-far-transmittance"))    cfg->dynamic_far_transmittance = (uint8_t)value;

    else if (!strcmp(name, "tv-close-section-color-R"))     cfg->tv_close_section_color[0] = (uint8_t)value;
    else if (!strcmp(name, "tv-close-section-color-G"))     cfg->tv_close_section_color[1] = (uint8_t)value;
    else if (!strcmp(name, "tv-close-section-color-B"))     cfg->tv_close_section_color[2] = (uint8_t)value;
    else if (!strcmp(name, "tv-close-section-transmittance")) cfg->tv_close_section_transmittance = (uint8_t)value;

    else if (!strcmp(name, "tv-line-color-R"))              cfg->tv_line_color[0] = (uint8_t)value;
    else if (!strcmp(name, "tv-line-color-G"))              cfg->tv_line_color[1] = (uint8_t)value;
    else if (!strcmp(name, "tv-line-color-B"))              cfg->tv_line_color[2] = (uint8_t)value;
    else if (!strcmp(name, "tv-line-transmittance"))        cfg->tv_line_transmittance = (uint8_t)value;

    else if (!strcmp(name, "Revert"))               vm_tweak_guide_revert(cfg, tag);
    else return TRACE(1, _b("unknown param: %s=%f"), name, value), 0;

    return 1;
}

/**
 * @brief   Create view selector element
 */
static void vm_tweak_view_select(cfg_ui_t *cfg, int type, char *buf, int n)
{
    char   *s = buf;
    int     i, k;

    for (i = 0; i < cfg->pages_num; i++)
    {
        cfg_ui_page_t      *page = &cfg->pages[i];

        for (k = 0; k < page->views_num; k++)
        {
            if (page->views[k]->base.type == type)
            {
                s = s + snprintf(s, n - (int)(s - buf), "%s[%d];", page->id, k);
            }
            else if (type == MESH_RAW && page->views[k]->base.type == MESH_RAW_MCV)
            {
                int     j;

                for (j = 0; j < page->views[k]->raw_mc.number; j++)
                {
                    s = s + snprintf(s, n - (int)(s - buf), "%s[%d:%d];", page->id, k, j);
                }
            }
        }
    }

    (s != buf ? s[-1] = '\0' : 0);
}

/**
 * @brief   Select view configuration for mesh update
 */
static cfg_mesh_t * vm_tweak_view_find(cfg_ui_t *cfg, int type, int idx)
{
    int     i, k;

    for (i = 0; i < cfg->pages_num; i++)
    {
        cfg_ui_page_t      *page = &cfg->pages[i];

        for (k = 0; k < page->views_num; k++)
        {
            if (page->views[k]->base.type == type)
            {
                if (idx-- == 0)
                {
                    TRACE(0, _b("selected %s[%d] - %p"), page->id, k, &__vm_cfg_mesh[i][k]);

                    __vm_tweak_view_orig[type] = &__vm_cfg_mesh[i][k];

                    __vm_tweak_view_is_algo[type] = !strncmp(page->id, "algo-", 5);
                    __vm_tweak_view_id[type] = page->id;

                    return page->views[k];
                }
            }
            else if (type == MESH_RAW && page->views[k]->base.type == MESH_RAW_MCV)
            {
                int     j;

                for (j = 0; j < page->views[k]->raw_mc.number; j++)
                {
                    if (idx-- == 0)
                    {
                        TRACE(0, _b("selected %s[%d] - %p"), page->id, k, &__vm_cfg_mesh[i][k]);

                        __vm_tweak_view_orig[type] = (cfg_mesh_t *)&__vm_cfg_mesh[i][k].raw_mc.raw[j];

                        __vm_tweak_view_is_algo[type] = !strncmp(page->id, "algo-", 5);
                        __vm_tweak_view_id[type] = page->id;

                        return (cfg_mesh_t *)&page->views[k]->raw_mc.raw[j];
                    }
                }
            }
        }
    }

    return (errno = EINVAL, NULL);
}

/**
 * @brief   Single-camera view setup
 */
static inline void vm_tweak_scv_setup(cfg_scv_mesh_t *cfg, char *tag)
{
    char    buffer[256], *p;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    /* ...destination tile always starts horizontal layout */
    tweak_add_layout(200, 0, "dst");
    tweak_add_spinbox((strcpy(p, "x0"), buffer), 0, 2048, cfg->base.dst[0], 0);
    tweak_add_spinbox((strcpy(p, "y0"), buffer), 0, 2048, cfg->base.dst[1], 0);
    tweak_add_spinbox((strcpy(p, "x1"), buffer), 0, 2048, cfg->base.dst[2], 0);
    tweak_add_spinbox((strcpy(p, "y1"), buffer), 0, 2048, cfg->base.dst[3], 0);

    tweak_add_layout(200, 1, "pose");
    tweak_add_slider((strcpy(p, "X"), buffer), -6000, 6000, cfg->position[0], 0);
    tweak_add_slider((strcpy(p, "Y"), buffer), -6000, 6000, cfg->position[1], 0);
    tweak_add_slider((strcpy(p, "Z"), buffer), -6000, 6000, cfg->position[2], 0);
    tweak_add_slider((strcpy(p, "Rx"), buffer), -180, 180, cfg->rotation[0], 0);
    tweak_add_slider((strcpy(p, "Ry"), buffer), -90, 90, cfg->rotation[1], 0);
    tweak_add_slider((strcpy(p, "Rz"), buffer), -360, 360, cfg->rotation[2], 0);

    tweak_add_layout(200, 1, "params");
    tweak_add_slider((strcpy(p, "hfov"), buffer), -180, 180, cfg->fov[0], 0);
    tweak_add_slider((strcpy(p, "vfov"), buffer), -180, 180, cfg->fov[1], 0);
    tweak_add_slider((strcpy(p, "hoff"), buffer), -180, 180, cfg->fov[2], 0);
    tweak_add_slider((strcpy(p, "voff"), buffer), -180, 180, cfg->fov[3], 0);
    tweak_add_slider((strcpy(p, "dist-x"), buffer), 0, 1, cfg->distortion[0], 2);
    tweak_add_slider((strcpy(p, "dist-y"), buffer), 0, 1, cfg->distortion[1], 2);
    tweak_add_slider((strcpy(p, "compression-x"), buffer), 0, 10, cfg->compression[0], 2);
    tweak_add_slider((strcpy(p, "compression-y"), buffer), 0, 10, cfg->compression[1], 2);
    tweak_add_slider((strcpy(p, "aspect-d"), buffer), 0, 10, mesh_tile_aspect(cfg->base.dst), 2);
    tweak_add_slider((strcpy(p, "aspect-c"), buffer), 0, 10, mesh_fov_aspect(cfg->fov), 2);
    tweak_add_groupbox((strcpy(p, "camera"), buffer), "front;left;rear;right", cfg->id);

    tweak_add_layout(200, 0, "mask");
    tweak_add_slider((strcpy(p, "TLmin"), buffer), -16000, 16000, cfg->mask[0], 0);
    tweak_add_slider((strcpy(p, "BLmin"), buffer), -16000, 16000, cfg->mask[1], 0);
    tweak_add_slider((strcpy(p, "TLmax"), buffer), -16000, 16000, cfg->mask[2], 0);
    tweak_add_slider((strcpy(p, "BLmax"), buffer), -16000, 16000, cfg->mask[3], 0);

    tweak_add_layout(200, 1, "steering coefficints");
    tweak_add_slider((strcpy(p, "hfov-adj-coef"), buffer), -1, 1, cfg->fov_adj_coef[0], 4);
    tweak_add_slider((strcpy(p, "vfov-adj-coef"), buffer), -1, 1, cfg->fov_adj_coef[1], 4);
    tweak_add_slider((strcpy(p, "hoff-adj-coef"), buffer), -1, 1, cfg->fov_adj_coef[2], 4);
    tweak_add_slider((strcpy(p, "voff-adj-coef"), buffer), -1, 1, cfg->fov_adj_coef[3], 4);
    tweak_add_slider((strcpy(p, "yaw-adj-coef"), buffer), -1, 1, cfg->yaw_adj_coef, 4);
}



/**
 * @brief   See-through-view setup
 */
static inline void vm_tweak_stv_setup(cfg_stv_mesh_t *cfg, char *tag)
{
    char buffer[256], *p;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    tweak_add_layout(200, 0, "dst");
    tweak_add_spinbox((strcpy(p, "x0"), buffer), 0, 2048, cfg->base.dst[0], 0);
    tweak_add_spinbox((strcpy(p, "y0"), buffer), 0, 2048, cfg->base.dst[1], 0);
    tweak_add_spinbox((strcpy(p, "x1"), buffer), 0, 2048, cfg->base.dst[2], 0);
    tweak_add_spinbox((strcpy(p, "y1"), buffer), 0, 2048, cfg->base.dst[3], 0);

    tweak_add_layout(200, 1, "Virtual Camera");
    tweak_add_slider((strcpy(p, "Pos-X"), buffer), -10000, 10000, cfg->position[0], 0);
    tweak_add_slider((strcpy(p, "Pos-Y"), buffer), -10000, 10000, cfg->position[1], 0);
    tweak_add_slider((strcpy(p, "Pos-Z"), buffer), -10000, 10000, cfg->position[2], 0);
    tweak_add_slider((strcpy(p, "LookAt-X"), buffer), -10000, 10000, cfg->look_at[0], 0);
    tweak_add_slider((strcpy(p, "LookAt-Y"), buffer), -10000, 10000, cfg->look_at[1], 0);
    tweak_add_slider((strcpy(p, "LookAt-Z"), buffer), -10000, 10000, cfg->look_at[2], 0);

    tweak_add_layout(200, 0, "Blend configuration");
    tweak_add_slider((strcpy(p, "Shadow-X0"), buffer), -6000, 6000, cfg->shadow[0], 0);
    tweak_add_slider((strcpy(p, "Shadow-Y0"), buffer), -6000, 6000, cfg->shadow[1], 0);
    tweak_add_slider((strcpy(p, "Shadow-X1"), buffer), -6000, 6000, cfg->shadow[2], 0);
    tweak_add_slider((strcpy(p, "Shadow-Y1"), buffer), -6000, 6000, cfg->shadow[3], 0);

    tweak_add_slider((strcpy(p, "Angle-FL0"), buffer), 0, 90, cfg->angles[0], 0);
    tweak_add_slider((strcpy(p, "Angle-FL1"), buffer), 0, 90, cfg->angles[4], 0);
    tweak_add_slider((strcpy(p, "Angle-LR0"), buffer), 90, 180, cfg->angles[1], 0);
    tweak_add_slider((strcpy(p, "Angle-LR1"), buffer), 90, 180, cfg->angles[5], 0);
    tweak_add_slider((strcpy(p, "Angle-RR0"), buffer), 180, 270, cfg->angles[2], 0);
    tweak_add_slider((strcpy(p, "Angle-RR1"), buffer), 180, 270, cfg->angles[6], 0);
    tweak_add_slider((strcpy(p, "Angle-RF0"), buffer), 270, 360, cfg->angles[3], 0);
    tweak_add_slider((strcpy(p, "Angle-RF1"), buffer), 270, 360, cfg->angles[7], 0);

    tweak_add_slider((strcpy(p, "Offset-FL0"), buffer), -500, 500, cfg->offsets[0], 0);
    tweak_add_slider((strcpy(p, "Offset-FL1"), buffer), -500, 500, cfg->offsets[4], 0);
    tweak_add_slider((strcpy(p, "Offset-LR0"), buffer), -500, 500, cfg->offsets[1], 0);
    tweak_add_slider((strcpy(p, "Offset-LR1"), buffer), -500, 500, cfg->offsets[5], 0);
    tweak_add_slider((strcpy(p, "Offset-RR0"), buffer), -500, 500, cfg->offsets[2], 0);
    tweak_add_slider((strcpy(p, "Offset-RR1"), buffer), -500, 500, cfg->offsets[6], 0);
    tweak_add_slider((strcpy(p, "Offset-RF0"), buffer), -500, 500, cfg->offsets[3], 0);
    tweak_add_slider((strcpy(p, "Offset-RF1"), buffer), -500, 500, cfg->offsets[7], 0);

    tweak_add_layout(200, 0, "params");
    tweak_add_slider((strcpy(p, "hfov"), buffer), -180, 180, cfg->fov[0], 0);
    tweak_add_slider((strcpy(p, "vfov"), buffer), 0, 180, cfg->fov[1], 0);
    tweak_add_slider((strcpy(p, "Rx"), buffer), 1, 20000, cfg->parabolic[0], 0);
    tweak_add_slider((strcpy(p, "Ry"), buffer), 1, 20000, cfg->parabolic[1], 0);
    tweak_add_slider((strcpy(p, "steep"), buffer), 1, 20000, cfg->parabolic[2], 0);
    tweak_add_slider((strcpy(p, "smooth"), buffer), 0, 2000, cfg->parabolic[3], 0);
    tweak_add_slider((strcpy(p, "separator-width"), buffer), 0, 200, cfg->separator_width, 0);
    tweak_add_slider((strcpy(p, "separator-exp"), buffer), 0, 10, cfg->separator_exp, 2);

    tweak_add_layout(200, 1, "info");
    tweak_add_slider((strcpy(p, "Roll"), buffer), -180, 180, cfg->rotation[0], 0);
    tweak_add_slider((strcpy(p, "Pitch"), buffer), -180, 180, cfg->rotation[1], 0);
    tweak_add_slider((strcpy(p, "Yaw"), buffer), -180, 180, cfg->rotation[2], 0);
    tweak_add_slider((strcpy(p, "aspect-d"), buffer), 0, 10, mesh_tile_aspect(cfg->base.dst), 2);
    tweak_add_slider((strcpy(p, "aspect-c"), buffer), 0, 10, mesh_fov_aspect(cfg->fov), 2);
}

/**
 * @brief   Top-view setup
 */
static void vm_tweak_tv_setup(cfg_tv_mesh_t *cfg, char *tag)
{
    char buffer[256], *p;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    tweak_add_layout(200, 0, "dst");
    tweak_add_spinbox((strcpy(p, "x0"), buffer), 0, 2048, cfg->base.dst[0], 0);
    tweak_add_spinbox((strcpy(p, "y0"), buffer), 0, 2048, cfg->base.dst[1], 0);
    tweak_add_spinbox((strcpy(p, "x1"), buffer), 0, 2048, cfg->base.dst[2], 0);
    tweak_add_spinbox((strcpy(p, "y1"), buffer), 0, 2048, cfg->base.dst[3], 0);

    tweak_add_layout(200, 0, "Blend configuration");
    tweak_add_slider((strcpy(p, "Shadow-X0"), buffer), -6000, 6000, cfg->shadow[0], 0);
    tweak_add_slider((strcpy(p, "Shadow-Y0"), buffer), -6000, 6000, cfg->shadow[1], 0);
    tweak_add_slider((strcpy(p, "Shadow-X1"), buffer), -6000, 6000, cfg->shadow[2], 0);
    tweak_add_slider((strcpy(p, "Shadow-Y1"), buffer), -6000, 6000, cfg->shadow[3], 0);

    tweak_add_slider((strcpy(p, "Angle-FL0"), buffer), 0, 90, cfg->angles[0], 0);
    tweak_add_slider((strcpy(p, "Angle-FL1"), buffer), 0, 90, cfg->angles[4], 0);
    tweak_add_slider((strcpy(p, "Angle-LR0"), buffer), 90, 180, cfg->angles[1], 0);
    tweak_add_slider((strcpy(p, "Angle-LR1"), buffer), 90, 180, cfg->angles[5], 0);
    tweak_add_slider((strcpy(p, "Angle-RR0"), buffer), 180, 270, cfg->angles[2], 0);
    tweak_add_slider((strcpy(p, "Angle-RR1"), buffer), 180, 270, cfg->angles[6], 0);
    tweak_add_slider((strcpy(p, "Angle-RF0"), buffer), 270, 360, cfg->angles[3], 0);
    tweak_add_slider((strcpy(p, "Angle-RF1"), buffer), 270, 360, cfg->angles[7], 0);

    tweak_add_slider((strcpy(p, "Offset-FL0"), buffer), -500, 500, cfg->offsets[0], 0);
    tweak_add_slider((strcpy(p, "Offset-FL1"), buffer), -500, 500, cfg->offsets[4], 0);
    tweak_add_slider((strcpy(p, "Offset-LR0"), buffer), -500, 500, cfg->offsets[1], 0);
    tweak_add_slider((strcpy(p, "Offset-LR1"), buffer), -500, 500, cfg->offsets[5], 0);
    tweak_add_slider((strcpy(p, "Offset-RR0"), buffer), -500, 500, cfg->offsets[2], 0);
    tweak_add_slider((strcpy(p, "Offset-RR1"), buffer), -500, 500, cfg->offsets[6], 0);
    tweak_add_slider((strcpy(p, "Offset-RF0"), buffer), -500, 500, cfg->offsets[3], 0);
    tweak_add_slider((strcpy(p, "Offset-RF1"), buffer), -500, 500, cfg->offsets[7], 0);

    tweak_add_layout(200, 0, "params");
    tweak_add_slider((strcpy(p, "Front-Length"), buffer), 0, 15000, cfg->area[0], 0);
    tweak_add_slider((strcpy(p, "Left-Length"), buffer), 0, 15000, cfg->area[1], 0);
    tweak_add_slider((strcpy(p, "Rear-Length"), buffer), 0, 15000, cfg->area[2], 0);
    tweak_add_slider((strcpy(p, "Right-Length"), buffer), 0, 15000, cfg->area[3], 0);
    tweak_add_slider((strcpy(p, "separator-width"), buffer), 0, 200, cfg->separator_width, 0);
    tweak_add_slider((strcpy(p, "separator-exp"), buffer), 0, 10, cfg->separator_exp, 2);

    tweak_add_layout(200, 1, "info");
    tweak_add_slider((strcpy(p, "scale"), buffer), 1, 50, cfg->scale, 1);
    tweak_add_spinbox((strcpy(p, "icon-x0"), buffer), 0, 2048, cfg->icon_dst[0], 0);
    tweak_add_spinbox((strcpy(p, "icon-y0"), buffer), 0, 2048, cfg->icon_dst[1], 0);
    tweak_add_spinbox((strcpy(p, "icon-x1"), buffer), 0, 2048, cfg->icon_dst[2], 0);
    tweak_add_spinbox((strcpy(p, "icon-y1"), buffer), 0, 2048, cfg->icon_dst[3], 0);
}

static void vm_tweak_scv_ro_refresh(cfg_scv_mesh_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "aspect-d"), buf), mesh_tile_aspect(cfg->base.dst));
    tweak_set((strcpy(p, "aspect-c"), buf), mesh_fov_aspect(cfg->fov));
}

static void vm_tweak_scv_revert(cfg_scv_mesh_t *cfg, cfg_scv_mesh_t *orig, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    (orig ? memcpy(cfg, orig, sizeof(*cfg)) : 0);

    /* ...fix-up destination tile basing on current steering position */
    vm_tweak_mirror_dst(cfg->base.dst);

    tweak_set((strcpy(p, "x0"), buf), cfg->base.dst[0]);
    tweak_set((strcpy(p, "y0"), buf), cfg->base.dst[1]);
    tweak_set((strcpy(p, "x1"), buf), cfg->base.dst[2]);
    tweak_set((strcpy(p, "y1"), buf), cfg->base.dst[3]);

    tweak_set((strcpy(p, "X"), buf), cfg->position[0]);
    tweak_set((strcpy(p, "Y"), buf), cfg->position[1]);
    tweak_set((strcpy(p, "Z"), buf), cfg->position[2]);

    tweak_set((strcpy(p, "Rx"), buf), cfg->rotation[0]);
    tweak_set((strcpy(p, "Ry"), buf), cfg->rotation[1]);
    tweak_set((strcpy(p, "Rz"), buf), cfg->rotation[2]);

    tweak_set((strcpy(p, "hfov"), buf), cfg->fov[0]);
    tweak_set((strcpy(p, "vfov"), buf), cfg->fov[1]);
    tweak_set((strcpy(p, "hoff"), buf), cfg->fov[2]);
    tweak_set((strcpy(p, "voff"), buf), cfg->fov[3]);
    tweak_set((strcpy(p, "dist-x"), buf), cfg->distortion[0]);
    tweak_set((strcpy(p, "dist-y"), buf), cfg->distortion[1]);
    tweak_set((strcpy(p, "compression-x"), buf), cfg->compression[0]);
    tweak_set((strcpy(p, "compression-y"), buf), cfg->compression[1]);
    tweak_set((strcpy(p, "camera"), buf), cfg->id);

    tweak_set((strcpy(p, "TLmin"), buf), cfg->mask[0]);
    tweak_set((strcpy(p, "BLmin"), buf), cfg->mask[1]);
    tweak_set((strcpy(p, "TLmax"), buf), cfg->mask[2]);
    tweak_set((strcpy(p, "BLmax"), buf), cfg->mask[3]);

    tweak_set((strcpy(p, "hfov-adj-coef"), buf), cfg->fov_adj_coef[0]);
    tweak_set((strcpy(p, "vfov-adj-coef"), buf), cfg->fov_adj_coef[1]);
    tweak_set((strcpy(p, "hoff-adj-coef"), buf), cfg->fov_adj_coef[2]);
    tweak_set((strcpy(p, "voff-adj-coef"), buf), cfg->fov_adj_coef[3]);
    tweak_set((strcpy(p, "yaw-adj-coef"), buf), cfg->yaw_adj_coef);

    vm_tweak_scv_ro_refresh(cfg, tag);
}

static int vm_tweak_scv_update(cfg_ui_t *ui, const char *tag, const char *name, double value)
{
    cfg_scv_mesh_t  *cfg = &__vm_tweak_view[MESH_SCV]->scv;

    CHK_ERR(cfg, -(errno = EINVAL));

    if (!strcmp(name, "x0"))                cfg->base.dst[0] = MIN(value, cfg->base.dst[2]);
    else if (!strcmp(name, "y0"))           cfg->base.dst[1] = MIN(value, cfg->base.dst[3]);
    else if (!strcmp(name, "x1"))           cfg->base.dst[2] = MAX(value, cfg->base.dst[0]);
    else if (!strcmp(name, "y1"))           cfg->base.dst[3] = MAX(value, cfg->base.dst[1]);
    else if (!strcmp(name, "X"))            cfg->position[0] = value;
    else if (!strcmp(name, "Y"))            cfg->position[1] = value;
    else if (!strcmp(name, "Z"))            cfg->position[2] = value;
    else if (!strcmp(name, "Rx"))           cfg->rotation[0] = value;
    else if (!strcmp(name, "Ry"))           cfg->rotation[1] = value;
    else if (!strcmp(name, "Rz"))           cfg->rotation[2] = value;
    else if (!strcmp(name, "hfov"))         cfg->fov[0] = value;
    else if (!strcmp(name, "vfov"))         cfg->fov[1] = value;
    else if (!strcmp(name, "hoff"))         cfg->fov[2] = value;
    else if (!strcmp(name, "voff"))         cfg->fov[3] = value;
    else if (!strcmp(name, "dist-x"))       cfg->distortion[0] = value;
    else if (!strcmp(name, "dist-y"))       cfg->distortion[1] = value;
    else if (!strcmp(name, "compression-x"))cfg->compression[0] = value;
    else if (!strcmp(name, "compression-y"))cfg->compression[1] = value;
    else if (!strcmp(name, "camera"))       cfg->id = (uint32_t)value;
    else if (!strcmp(name, "TLmin"))        cfg->mask[0] = value;
    else if (!strcmp(name, "BLmin"))        cfg->mask[1] = value;
    else if (!strcmp(name, "TLmax"))        cfg->mask[2] = value;
    else if (!strcmp(name, "BLmax"))        cfg->mask[3] = value;

    else if (!strcmp(name, "hfov-adj-coef"))    cfg->fov_adj_coef[0] = value;
    else if (!strcmp(name, "vfov-adj-coef"))    cfg->fov_adj_coef[1] = value;
    else if (!strcmp(name, "hoff-adj-coef"))    cfg->fov_adj_coef[2] = value;
    else if (!strcmp(name, "voff-adj-coef"))    cfg->fov_adj_coef[3] = value;
    else if (!strcmp(name, "yaw-adj-coef"))     cfg->yaw_adj_coef = value;

    else if (!strcmp(name, "Revert"))       (void)0;/*vm_tweak_scv_revert(ui, cfg);*/
    else return TRACE(1, _b("unknown param: %s=%f"), name, value), 0;

    /* ...refresh read-only parameters */
    vm_tweak_scv_ro_refresh(cfg, tag);

    return 1;
}

static void vm_tweak_tv_ro_refresh(cfg_tv_mesh_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    /* ...tbd - this doesn't look good; move somehow to mesh-gen directly */
    mesh_tv_fix_aspect(__cfg, cfg, 0);

    tweak_set((strcpy(p, "scale"), buf), cfg->scale);
    tweak_set((strcpy(p, "icon-x0"), buf), cfg->icon_dst[0]);
    tweak_set((strcpy(p, "icon-y0"), buf), cfg->icon_dst[1]);
    tweak_set((strcpy(p, "icon-x1"), buf), cfg->icon_dst[2]);
    tweak_set((strcpy(p, "icon-y1"), buf), cfg->icon_dst[3]);

}

static void vm_tweak_tv_refresh(cfg_tv_mesh_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "x0"), buf), cfg->base.dst[0]);
    tweak_set((strcpy(p, "y0"), buf), cfg->base.dst[1]);
    tweak_set((strcpy(p, "x1"), buf), cfg->base.dst[2]);
    tweak_set((strcpy(p, "y1"), buf), cfg->base.dst[3]);

    tweak_set((strcpy(p, "Shadow-X0"), buf), cfg->shadow[0]);
    tweak_set((strcpy(p, "Shadow-Y0"), buf), cfg->shadow[1]);
    tweak_set((strcpy(p, "Shadow-X1"), buf), cfg->shadow[2]);
    tweak_set((strcpy(p, "Shadow-Y1"), buf), cfg->shadow[3]);

    tweak_set((strcpy(p, "Angle-FL0"), buf), cfg->angles[0]);
    tweak_set((strcpy(p, "Angle-LR0"), buf), cfg->angles[1]);
    tweak_set((strcpy(p, "Angle-RR0"), buf), cfg->angles[2]);
    tweak_set((strcpy(p, "Angle-RF0"), buf), cfg->angles[3]);
    tweak_set((strcpy(p, "Angle-FL1"), buf), cfg->angles[4]);
    tweak_set((strcpy(p, "Angle-LR1"), buf), cfg->angles[5]);
    tweak_set((strcpy(p, "Angle-RR1"), buf), cfg->angles[6]);
    tweak_set((strcpy(p, "Angle-RF1"), buf), cfg->angles[7]);

    tweak_set((strcpy(p, "Offset-FL0"), buf), cfg->offsets[0]);
    tweak_set((strcpy(p, "Offset-LR0"), buf), cfg->offsets[1]);
    tweak_set((strcpy(p, "Offset-RR0"), buf), cfg->offsets[2]);
    tweak_set((strcpy(p, "Offset-RF0"), buf), cfg->offsets[3]);
    tweak_set((strcpy(p, "Offset-FL1"), buf), cfg->offsets[4]);
    tweak_set((strcpy(p, "Offset-LR1"), buf), cfg->offsets[5]);
    tweak_set((strcpy(p, "Offset-RR1"), buf), cfg->offsets[6]);
    tweak_set((strcpy(p, "Offset-RF1"), buf), cfg->offsets[7]);

    tweak_set((strcpy(p, "separator-width"), buf), cfg->separator_width);
    tweak_set((strcpy(p, "separator-exp"), buf), cfg->separator_exp);
    tweak_set((strcpy(p, "Front-Length"), buf), cfg->area[0]);
    tweak_set((strcpy(p, "Left-Length"), buf), cfg->area[1]);
    tweak_set((strcpy(p, "Rear-Length"), buf), cfg->area[2]);
    tweak_set((strcpy(p, "Right-Length"), buf), cfg->area[3]);

    vm_tweak_tv_ro_refresh(cfg, tag);
}

static void vm_tweak_tv_revert(cfg_tv_mesh_t *cfg, cfg_tv_mesh_t *orig, const char *tag)
{
    (orig ? memcpy(cfg, orig, sizeof(*cfg)) : 0);

    /* ...fix-up destination tile basing on current steering position */
    vm_tweak_mirror_dst(cfg->base.dst);

    vm_tweak_tv_refresh(cfg, tag);
}

static int vm_tweak_tv_update(cfg_ui_t *ui, const char *tag, const char *name, double value)
{
    cfg_tv_mesh_t *cfg = &__vm_tweak_view[MESH_TV]->tv;

    CHK_ERR(cfg, -(errno = EINVAL));

    if (!strcmp(name, "x0"))                cfg->base.dst[0] = MIN(value, cfg->base.dst[2]);
    else if (!strcmp(name, "y0"))           cfg->base.dst[1] = MIN(value, cfg->base.dst[3]);
    else if (!strcmp(name, "x1"))           cfg->base.dst[2] = MAX(value, cfg->base.dst[0]);
    else if (!strcmp(name, "y1"))           cfg->base.dst[3] = MAX(value, cfg->base.dst[1]);
    else if (!strcmp(name, "Shadow-X0"))    cfg->shadow[0] = MIN(value, cfg->shadow[2]);
    else if (!strcmp(name, "Shadow-Y0"))    cfg->shadow[1] = MIN(value, cfg->shadow[3]);
    else if (!strcmp(name, "Shadow-X1"))    cfg->shadow[2] = MAX(value, cfg->shadow[0]);
    else if (!strcmp(name, "Shadow-Y1"))    cfg->shadow[3] = MAX(value, cfg->shadow[1]);
    else if (!strcmp(name, "Angle-FL0"))    cfg->angles[0] = value;
    else if (!strcmp(name, "Angle-LR0"))    cfg->angles[1] = value;
    else if (!strcmp(name, "Angle-RR0"))    cfg->angles[2] = value;
    else if (!strcmp(name, "Angle-RF0"))    cfg->angles[3] = value;
    else if (!strcmp(name, "Angle-FL1"))    cfg->angles[4] = value;
    else if (!strcmp(name, "Angle-LR1"))    cfg->angles[5] = value;
    else if (!strcmp(name, "Angle-RR1"))    cfg->angles[6] = value;
    else if (!strcmp(name, "Angle-RF1"))    cfg->angles[7] = value;
    else if (!strcmp(name, "Offset-FL0"))    cfg->offsets[0] = value;
    else if (!strcmp(name, "Offset-LR0"))    cfg->offsets[1] = value;
    else if (!strcmp(name, "Offset-RR0"))    cfg->offsets[2] = value;
    else if (!strcmp(name, "Offset-RF0"))    cfg->offsets[3] = value;
    else if (!strcmp(name, "Offset-FL1"))    cfg->offsets[4] = value;
    else if (!strcmp(name, "Offset-LR1"))    cfg->offsets[5] = value;
    else if (!strcmp(name, "Offset-RR1"))    cfg->offsets[6] = value;
    else if (!strcmp(name, "Offset-RF1"))    cfg->offsets[7] = value;

    else if (!strcmp(name, "separator-width"))  cfg->separator_width = value;
    else if (!strcmp(name, "separator-exp"))    cfg->separator_exp = value;
    else if (!strcmp(name, "Front-Length")) cfg->area[0] = value;
    else if (!strcmp(name, "Left-Length"))  cfg->area[1] = value;
    else if (!strcmp(name, "Rear-Length"))  cfg->area[2] = value;
    else if (!strcmp(name, "Right-Length")) cfg->area[3] = value;
    else return TRACE(0, _b("unknown param: %s=%f"), name, value), 0;

    /* ...recalc view parameters if aspect ratio is set */
    vm_tweak_tv_ro_refresh(cfg, tag);

    return 1;
}

/**
 * @brief   Raw-view setup
 */
static void vm_tweak_raw_setup(cfg_raw_mesh_t *cfg, char *tag)
{
    char buffer[256], *p;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    tweak_add_layout(200, 0, "dst");
    tweak_add_spinbox((strcpy(p, "x0"), buffer), 0, 2048, cfg->base.dst[0], 0);
    tweak_add_spinbox((strcpy(p, "y0"), buffer), 0, 2048, cfg->base.dst[1], 0);
    tweak_add_spinbox((strcpy(p, "x1"), buffer), 0, 2048, cfg->base.dst[2], 0);
    tweak_add_spinbox((strcpy(p, "y1"), buffer), 0, 2048, cfg->base.dst[3], 0);

    tweak_add_layout(200, 1, "");
    tweak_add_slider((strcpy(p, "crop-x0"), buffer), 0, 2048, cfg->crop[0], 0);
    tweak_add_slider((strcpy(p, "crop-y0"), buffer), 0, 2048, cfg->crop[1], 0);
    tweak_add_slider((strcpy(p, "crop-x1"), buffer), 0, 2048, cfg->crop[2], 0);
    tweak_add_slider((strcpy(p, "crop-y1"), buffer), 0, 2048, cfg->crop[3], 0);

    tweak_add_groupbox((strcpy(p, "camera"), buffer), "front;left;rear;right", cfg->id);
}

static void vm_tweak_raw_revert(cfg_raw_mesh_t *cfg, cfg_raw_mesh_t *orig, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    (orig ? memcpy(cfg, orig, sizeof(*cfg)) : 0);

    /* ...fix-up destination tile basing on current steering position */
    vm_tweak_mirror_dst(cfg->base.dst);

    tweak_set((strcpy(p, "x0"), buf), cfg->base.dst[0]);
    tweak_set((strcpy(p, "y0"), buf), cfg->base.dst[1]);
    tweak_set((strcpy(p, "x1"), buf), cfg->base.dst[2]);
    tweak_set((strcpy(p, "y1"), buf), cfg->base.dst[3]);

    tweak_set((strcpy(p, "crop-x0"), buf), cfg->crop[0]);
    tweak_set((strcpy(p, "crop-y0"), buf), cfg->crop[1]);
    tweak_set((strcpy(p, "crop-x1"), buf), cfg->crop[2]);
    tweak_set((strcpy(p, "crop-y1"), buf), cfg->crop[3]);

    tweak_set((strcpy(p, "camera"), buf), cfg->id);
}

static int vm_tweak_raw_update(cfg_ui_t *ui, const char *tag, const char *name, double value)
{
    cfg_raw_mesh_t *cfg = &__vm_tweak_view[MESH_RAW]->raw;

    CHK_ERR(cfg, -(errno = EINVAL));

    if (!strcmp(name, "x0"))                cfg->base.dst[0] = MIN(value, cfg->base.dst[2]);
    else if (!strcmp(name, "y0"))           cfg->base.dst[1] = MIN(value, cfg->base.dst[3]);
    else if (!strcmp(name, "x1"))           cfg->base.dst[2] = MAX(value, cfg->base.dst[0]);
    else if (!strcmp(name, "y1"))           cfg->base.dst[3] = MAX(value, cfg->base.dst[1]);
    else if (!strcmp(name, "crop-x0"))      cfg->crop[0] = value;
    else if (!strcmp(name, "crop-y0"))      cfg->crop[1] = value;
    else if (!strcmp(name, "crop-x1"))      cfg->crop[2] = value;
    else if (!strcmp(name, "crop-y1"))      cfg->crop[3] = value;
    else if (!strcmp(name, "camera"))       cfg->id = (uint32_t)value;
    else return TRACE(0, _b("unknown param: %s=%f"), name, value), 0;

    return 1;
}

/**
 * @brief   Raw-MCV-view setup
 */
static void vm_tweak_raw_mcv_setup(cfg_raw_mcv_mesh_t *cfg, char *tag)
{
    char buffer[256], *p;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    tweak_add_layout(200, 0, "dst");
    tweak_add_spinbox((strcpy(p, "x0"), buffer), 0, 2048, cfg->base.dst[0], 0);
    tweak_add_spinbox((strcpy(p, "y0"), buffer), 0, 2048, cfg->base.dst[1], 0);
    tweak_add_spinbox((strcpy(p, "x1"), buffer), 0, 2048, cfg->base.dst[2], 0);
    tweak_add_spinbox((strcpy(p, "y1"), buffer), 0, 2048, cfg->base.dst[3], 0);
}

static void vm_tweak_raw_mcv_revert(cfg_raw_mcv_mesh_t *cfg, cfg_raw_mcv_mesh_t *orig, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    (orig ? memcpy(&cfg->base, &orig->base, sizeof(cfg->base)) : 0);

    /* ...fix-up destination tile basing on current steering position */
    vm_tweak_mirror_dst(cfg->base.dst);

    tweak_set((strcpy(p, "x0"), buf), cfg->base.dst[0]);
    tweak_set((strcpy(p, "y0"), buf), cfg->base.dst[1]);
    tweak_set((strcpy(p, "x1"), buf), cfg->base.dst[2]);
    tweak_set((strcpy(p, "y1"), buf), cfg->base.dst[3]);
}

static int vm_tweak_raw_mcv_update(cfg_ui_t *ui, const char *tag, const char *name, double value)
{
    cfg_raw_mcv_mesh_t *cfg = &__vm_tweak_view[MESH_RAW_MCV]->raw_mc;

    CHK_ERR(cfg, -(errno = EINVAL));

    if (!strcmp(name, "x0"))                cfg->base.dst[0] = MIN(value, cfg->base.dst[2]);
    else if (!strcmp(name, "y0"))           cfg->base.dst[1] = MIN(value, cfg->base.dst[3]);
    else if (!strcmp(name, "x1"))           cfg->base.dst[2] = MAX(value, cfg->base.dst[0]);
    else if (!strcmp(name, "y1"))           cfg->base.dst[3] = MAX(value, cfg->base.dst[1]);
    else return TRACE(0, _b("unknown param: %s=%f"), name, value), 0;

    return 1;
}

static void vm_tweak_stv_ro_refresh(cfg_stv_mesh_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    mesh_stv_fix_angles(cfg);
    tweak_set((strcpy(p, "Pos-X"), buf), cfg->position[0]);
    tweak_set((strcpy(p, "Pos-Y"), buf), cfg->position[1]);
    tweak_set((strcpy(p, "Pos-Z"), buf), cfg->position[2]);
    tweak_set((strcpy(p, "LookAt-X"), buf), cfg->look_at[0]);
    tweak_set((strcpy(p, "LookAt-Y"), buf), cfg->look_at[1]);
    tweak_set((strcpy(p, "LookAt-Z"), buf), cfg->look_at[2]);

    tweak_set((strcpy(p, "Roll"), buf), cfg->rotation[0]);
    tweak_set((strcpy(p, "Pitch"), buf), cfg->rotation[1]);
    tweak_set((strcpy(p, "Yaw"), buf), cfg->rotation[2]);
    tweak_set((strcpy(p, "aspect-d"), buf), mesh_tile_aspect(cfg->base.dst));
    tweak_set((strcpy(p, "aspect-c"), buf), mesh_fov_aspect(cfg->fov));
}

static void vm_tweak_stv_revert(cfg_stv_mesh_t *cfg, cfg_stv_mesh_t *orig, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    (orig ? memcpy(cfg, orig, sizeof(*cfg)) : 0);

    /* ...fix-up destination tile basing on current steering position */
    vm_tweak_mirror_dst(cfg->base.dst);

    tweak_set((strcpy(p, "x0"), buf), cfg->base.dst[0]);
    tweak_set((strcpy(p, "y0"), buf), cfg->base.dst[1]);
    tweak_set((strcpy(p, "x1"), buf), cfg->base.dst[2]);
    tweak_set((strcpy(p, "y1"), buf), cfg->base.dst[3]);

    tweak_set((strcpy(p, "Shadow-X0"), buf), cfg->shadow[0]);
    tweak_set((strcpy(p, "Shadow-Y0"), buf), cfg->shadow[1]);
    tweak_set((strcpy(p, "Shadow-X1"), buf), cfg->shadow[2]);
    tweak_set((strcpy(p, "Shadow-Y1"), buf), cfg->shadow[3]);

    tweak_set((strcpy(p, "Angle-FL0"), buf), cfg->angles[0]);
    tweak_set((strcpy(p, "Angle-LR0"), buf), cfg->angles[1]);
    tweak_set((strcpy(p, "Angle-RR0"), buf), cfg->angles[2]);
    tweak_set((strcpy(p, "Angle-RF0"), buf), cfg->angles[3]);
    tweak_set((strcpy(p, "Angle-FL1"), buf), cfg->angles[4]);
    tweak_set((strcpy(p, "Angle-LR1"), buf), cfg->angles[5]);
    tweak_set((strcpy(p, "Angle-RR1"), buf), cfg->angles[6]);
    tweak_set((strcpy(p, "Angle-RF1"), buf), cfg->angles[7]);

    tweak_set((strcpy(p, "Offset-FL0"), buf), cfg->offsets[0]);
    tweak_set((strcpy(p, "Offset-LR0"), buf), cfg->offsets[1]);
    tweak_set((strcpy(p, "Offset-RR0"), buf), cfg->offsets[2]);
    tweak_set((strcpy(p, "Offset-RF0"), buf), cfg->offsets[3]);
    tweak_set((strcpy(p, "Offset-FL1"), buf), cfg->offsets[4]);
    tweak_set((strcpy(p, "Offset-LR1"), buf), cfg->offsets[5]);
    tweak_set((strcpy(p, "Offset-RR1"), buf), cfg->offsets[6]);
    tweak_set((strcpy(p, "Offset-RF1"), buf), cfg->offsets[7]);

    tweak_set((strcpy(p, "Pos-X"), buf), cfg->position[0]);
    tweak_set((strcpy(p, "Pos-Y"), buf), cfg->position[1]);
    tweak_set((strcpy(p, "Pos-Z"), buf), cfg->position[2]);

    tweak_set((strcpy(p, "LookAt-X"), buf), cfg->look_at[0]);
    tweak_set((strcpy(p, "LookAt-Y"), buf), cfg->look_at[1]);
    tweak_set((strcpy(p, "LookAt-Z"), buf), cfg->look_at[2]);

    tweak_set((strcpy(p, "hfov"), buf), cfg->fov[0]);
    tweak_set((strcpy(p, "vfov"), buf), cfg->fov[1]);

    tweak_set((strcpy(p, "Rx"), buf), cfg->parabolic[0]);
    tweak_set((strcpy(p, "Ry"), buf), cfg->parabolic[1]);
    tweak_set((strcpy(p, "steep"), buf), cfg->parabolic[2]);
    tweak_set((strcpy(p, "smooth"), buf), cfg->parabolic[3]);
    tweak_set((strcpy(p, "separator-width"), buf), cfg->separator_width);
    tweak_set((strcpy(p, "separator-exp"), buf), cfg->separator_exp);

    vm_tweak_stv_ro_refresh(cfg, tag);
}

static int vm_tweak_stv_update(cfg_ui_t *ui, const char *tag, const char *name, double value)
{
    cfg_stv_mesh_t *cfg = &__vm_tweak_view[MESH_STV]->stv;

    CHK_ERR(cfg, -(errno = EINVAL));

    if (!strcmp(name, "x0"))                cfg->base.dst[0] = MIN(value, cfg->base.dst[2]);
    else if (!strcmp(name, "y0"))           cfg->base.dst[1] = MIN(value, cfg->base.dst[3]);
    else if (!strcmp(name, "x1"))           cfg->base.dst[2] = MAX(value, cfg->base.dst[0]);
    else if (!strcmp(name, "y1"))           cfg->base.dst[3] = MAX(value, cfg->base.dst[1]);
    else if (!strcmp(name, "Shadow-X0"))    cfg->shadow[0] = MIN(value, cfg->shadow[2]);
    else if (!strcmp(name, "Shadow-Y0"))    cfg->shadow[1] = MIN(value, cfg->shadow[3]);
    else if (!strcmp(name, "Shadow-X1"))    cfg->shadow[2] = MAX(value, cfg->shadow[0]);
    else if (!strcmp(name, "Shadow-Y1"))    cfg->shadow[3] = MAX(value, cfg->shadow[1]);
    else if (!strcmp(name, "Angle-FL0"))    cfg->angles[0] = value;
    else if (!strcmp(name, "Angle-LR0"))    cfg->angles[1] = value;
    else if (!strcmp(name, "Angle-RR0"))    cfg->angles[2] = value;
    else if (!strcmp(name, "Angle-RF0"))    cfg->angles[3] = value;
    else if (!strcmp(name, "Angle-FL1"))    cfg->angles[4] = value;
    else if (!strcmp(name, "Angle-LR1"))    cfg->angles[5] = value;
    else if (!strcmp(name, "Angle-RR1"))    cfg->angles[6] = value;
    else if (!strcmp(name, "Angle-RF1"))    cfg->angles[7] = value;
    else if (!strcmp(name, "Offset-FL0"))    cfg->offsets[0] = value;
    else if (!strcmp(name, "Offset-LR0"))    cfg->offsets[1] = value;
    else if (!strcmp(name, "Offset-RR0"))    cfg->offsets[2] = value;
    else if (!strcmp(name, "Offset-RF0"))    cfg->offsets[3] = value;
    else if (!strcmp(name, "Offset-FL1"))    cfg->offsets[4] = value;
    else if (!strcmp(name, "Offset-LR1"))    cfg->offsets[5] = value;
    else if (!strcmp(name, "Offset-RR1"))    cfg->offsets[6] = value;
    else if (!strcmp(name, "Offset-RF1"))    cfg->offsets[7] = value;
    else if (!strcmp(name, "Pos-X"))        cfg->position[0] = value;
    else if (!strcmp(name, "Pos-Y"))        cfg->position[1] = value;
    else if (!strcmp(name, "Pos-Z"))        cfg->position[2] = value;
    else if (!strcmp(name, "LookAt-X"))     cfg->look_at[0] = value;
    else if (!strcmp(name, "LookAt-Y"))     cfg->look_at[1] = value;
    else if (!strcmp(name, "LookAt-Z"))     cfg->look_at[2] = value;
    else if (!strcmp(name, "hfov"))         cfg->fov[0] = value;
    else if (!strcmp(name, "vfov"))         cfg->fov[1] = value;
    else if (!strcmp(name, "Rx"))           cfg->parabolic[0] = value;
    else if (!strcmp(name, "Ry"))           cfg->parabolic[1] = value;
    else if (!strcmp(name, "steep"))        cfg->parabolic[2] = value;
    else if (!strcmp(name, "smooth"))       cfg->parabolic[3] = value;
    else if (!strcmp(name, "separator-width"))  cfg->separator_width = value;
    else if (!strcmp(name, "separator-exp"))    cfg->separator_exp = value;
    else return TRACE(1, _b("unknown param: %s=%f"), name, value), 0;

    vm_tweak_stv_ro_refresh(cfg, tag);

    return 1;
}

/**
 * @brief   UI views setup
 */
static inline void vm_tweak_views_setup(cfg_ui_t *cfg, char *tag, int type, char *name)
{
    char    buffer[256], *p;
    int     i;

    p = buffer + snprintf(buffer, sizeof(buffer), "%s:", tag);

    tweak_add_widget(name);
    tweak_add_layout(200, 0, "");

    /* ...add views selector */
    char    str[4096];
    vm_tweak_view_select(cfg, type, str, sizeof(str));
    tweak_add_groupbox((strcpy(p, "view"), buffer), str, 0);

    tweak_add_layout(200, 1, "");
    tweak_add_button((strcpy(p, "Revert"), buffer));

    __vm_tweak_view[type] = vm_tweak_view_find(cfg, type, 0);
    if (__vm_tweak_view[type] != NULL)
    {
        switch (type)
        {
        case MESH_SCV:
            vm_tweak_scv_setup(&__vm_tweak_view[type]->scv, tag);
            break;

        case MESH_STV:
            vm_tweak_stv_setup(&__vm_tweak_view[type]->stv, tag);
            break;

        case MESH_TV:
            vm_tweak_tv_setup(&__vm_tweak_view[type]->tv, tag);
            break;

        case MESH_RAW:
            vm_tweak_raw_setup(&__vm_tweak_view[type]->raw, tag);
            break;

        case MESH_RAW_MCV:
            vm_tweak_raw_mcv_setup(&__vm_tweak_view[type]->raw_mc, tag);
            break;

        default:
            TRACE(ERROR, _b("invalid view type: %u"), type);
        }
    }
}

static int vm_tweak_views_update(cfg_ui_t *ui, const char *tag, const char *name, int type, double value)
{
    cfg_mesh_t     *mesh;
    int             r = 1;

    if (!strcmp(name, "view"))
    {
        CHK_ERR(__vm_tweak_view[type] = vm_tweak_view_find(ui, type, (int)value), -(errno = EINVAL));

        switch (type)
        {
        case MESH_SCV:
            vm_tweak_scv_revert(&__vm_tweak_view[type]->scv, NULL, tag);
            break;

        case MESH_STV:
            vm_tweak_stv_revert(&__vm_tweak_view[type]->stv, NULL, tag);
            break;

        case MESH_TV:
            vm_tweak_tv_revert(&__vm_tweak_view[type]->tv, NULL, tag);
            break;

        case MESH_RAW:
            vm_tweak_raw_revert(&__vm_tweak_view[type]->raw, NULL, tag);
            break;

        case MESH_RAW_MCV:
            vm_tweak_raw_mcv_revert(&__vm_tweak_view[type]->raw_mc, NULL, tag);
            break;

        default:
            TRACE(ERROR, _x("unknown configuration: %u"), type);
            return 0;
        }
    }
    else if (!strcmp(name, "Revert"))
    {
        TRACE(0, _b("restore cfg from %p"), __vm_tweak_view_orig[type]);

        switch (type)
        {
        case MESH_SCV:
            vm_tweak_scv_revert(&__vm_tweak_view[type]->scv, &__vm_tweak_view_orig[type]->scv, tag);
            break;

        case MESH_STV:
            vm_tweak_stv_revert(&__vm_tweak_view[type]->stv, &__vm_tweak_view_orig[type]->stv, tag);
            break;

        case MESH_TV:
            vm_tweak_tv_revert(&__vm_tweak_view[type]->tv, &__vm_tweak_view_orig[type]->tv, tag);
            break;

        case MESH_RAW:
            vm_tweak_raw_revert(&__vm_tweak_view[type]->raw, &__vm_tweak_view_orig[type]->raw, tag);
            break;

        case MESH_RAW_MCV:
            vm_tweak_raw_mcv_revert(&__vm_tweak_view[type]->raw_mc, &__vm_tweak_view_orig[type]->raw_mc, tag);
            break;

        default:
            TRACE(ERROR, _x("unknown configuration: %u"), type);
            return 0;
        }
    }
    else
    {
        switch (type)
        {
        case MESH_SCV:
            r = vm_tweak_scv_update(ui, tag, name, value);
            break;

        case MESH_STV:
            r = vm_tweak_stv_update(ui, tag, name, value);
            break;

        case MESH_TV:
            r = vm_tweak_tv_update(ui, tag, name, value);
            break;

        case MESH_RAW:
            r = vm_tweak_raw_update(ui, tag, name, value);
            break;

        case MESH_RAW_MCV:
            r = vm_tweak_raw_mcv_update(ui, tag, name, value);
            break;

        default:
            return 0;
        }
    }

    /* ...force algo-view update if needed */
    if (r != 0 && __vm_tweak_view_is_algo[type] != 0)
    {
        algo_view_invalidate(__vm_tweak_view_id[type]);
    }

    return r;
}

/**
 * @brief   Camera parameters setup
 */
static void vm_tweak_camera_setup(int id, cfg_camera_t *cfg)
{
    char buffer[256], *p;

    __vm_tweak_camera_cfg[id] = malloc(sizeof(*cfg));
    memcpy(__vm_tweak_camera_cfg[id], cfg, sizeof(*cfg));

    tweak_add_layout(200, 0, cfg->name);
    p = buffer + snprintf(buffer, sizeof(buffer), "camera:%u:", id);

    tweak_add_spinbox((strcpy(p, "width"), buffer), 0, 2000, cfg->resolution[0], 0);
    tweak_add_spinbox((strcpy(p, "height"), buffer), 0, 2000, cfg->resolution[1], 0);

    tweak_add_layout(200, 1, "Extrinsics");
    tweak_add_slider((strcpy(p, "X"), buffer), -10000, 10000, cfg->position[0], 1);
    tweak_add_slider((strcpy(p, "Y"), buffer), -10000, 10000, cfg->position[1], 1);
    tweak_add_slider((strcpy(p, "Z"), buffer), -10000, 10000, cfg->position[2], 1);

    tweak_add_slider((strcpy(p, "Rx"), buffer), -180, 180, cfg->rotation[0], 1);
    tweak_add_slider((strcpy(p, "Ry"), buffer), -180, 180, cfg->rotation[1], 1);
    tweak_add_slider((strcpy(p, "Rz"), buffer), -180, 180, cfg->rotation[2], 1);
#ifdef BUILD_NATIVE
    tweak_add_layout(200, 1, "Error");
    tweak_add_slider((strcpy(p, "dX"), buffer), -1000, 1000, cfg->err_position[0], 2);
    tweak_add_slider((strcpy(p, "dY"), buffer), -1000, 1000, cfg->err_position[1], 2);
    tweak_add_slider((strcpy(p, "dZ"), buffer), -1000, 1000, cfg->err_position[2], 2);

    tweak_add_slider((strcpy(p, "dRx"), buffer), -18, 18, cfg->err_rotation[0], 2);
    tweak_add_slider((strcpy(p, "dRy"), buffer), -18, 18, cfg->err_rotation[1], 2);
    tweak_add_slider((strcpy(p, "dRz"), buffer), -18, 18, cfg->err_rotation[2], 2);
#endif
    tweak_add_layout(200, 1, "Intrinsics");
    tweak_add_spinbox((strcpy(p, "Cx"), buffer), 0, 1280, cfg->intrinsics[0 * 3 + 2], 2);
    tweak_add_spinbox((strcpy(p, "Cy"), buffer), 0, 800, cfg->intrinsics[1 * 3 + 2], 2);
    tweak_add_spinbox((strcpy(p, "Fx"), buffer), 0, 1000, cfg->intrinsics[0 * 3 + 0], 3);
    tweak_add_spinbox((strcpy(p, "Fy"), buffer), 0, 1000, cfg->intrinsics[1 * 3 + 1], 3);

    tweak_add_spinbox((strcpy(p, "d0"), buffer), -1, 1, cfg->distortion[0], 12);
    tweak_add_spinbox((strcpy(p, "d1"), buffer), -1, 1, cfg->distortion[1], 12);
    tweak_add_spinbox((strcpy(p, "d2"), buffer), -1, 1, cfg->distortion[2], 12);
    tweak_add_spinbox((strcpy(p, "d3"), buffer), -1, 1, cfg->distortion[3], 12);

    tweak_add_layout(200, 1, "");
    tweak_add_button((strcpy(p, "Revert"), buffer));
}

static void vm_tweak_cameras_setup(cfg_camera_t *cfg, int num)
{
    int     id;

    tweak_add_widget("Cameras");

    for (id = 0; id < num; id++)
    {
        vm_tweak_camera_setup(id, &cfg[id]);
    }
}


static void vm_tweak_camera_ro_refresh(int id, cfg_camera_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "width"), buf), cfg->resolution[0]);
    tweak_set((strcpy(p, "height"), buf), cfg->resolution[1]);
}

static void vm_tweak_camera_intr_refresh(int id, cfg_camera_t *cfg)
{
    char    buf[256], *p = buf;
    p = buf + snprintf(buf, sizeof(buf), "camera:%u:", id);

    tweak_set((strcpy(p, "Cx"), buf), cfg->intrinsics[0 * 3 + 2]);
    tweak_set((strcpy(p, "Cy"), buf), cfg->intrinsics[1 * 3 + 2]);
    tweak_set((strcpy(p, "Fx"), buf), cfg->intrinsics[0 * 3 + 0]);
    tweak_set((strcpy(p, "Fy"), buf), cfg->intrinsics[1 * 3 + 1]);

    tweak_set((strcpy(p, "d0"), buf), cfg->distortion[0]);
    tweak_set((strcpy(p, "d1"), buf), cfg->distortion[1]);
    tweak_set((strcpy(p, "d2"), buf), cfg->distortion[2]);
    tweak_set((strcpy(p, "d3"), buf), cfg->distortion[3]);
}

static void vm_tweak_camera_revert(int id, cfg_camera_t *cfg, cfg_camera_t *orig, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    memcpy(cfg, orig, sizeof(*cfg));

    tweak_set((strcpy(p, "X"), buf), cfg->position[0]);
    tweak_set((strcpy(p, "Y"), buf), cfg->position[1]);
    tweak_set((strcpy(p, "Z"), buf), cfg->position[2]);

    tweak_set((strcpy(p, "Rx"), buf), cfg->rotation[0]);
    tweak_set((strcpy(p, "Ry"), buf), cfg->rotation[1]);
    tweak_set((strcpy(p, "Rz"), buf), cfg->rotation[2]);
#ifdef BUILD_NATIVE
    tweak_set((strcpy(p, "dX"), buf), cfg->err_position[0]);
    tweak_set((strcpy(p, "dY"), buf), cfg->err_position[1]);
    tweak_set((strcpy(p, "dZ"), buf), cfg->err_position[2]);

    tweak_set((strcpy(p, "dRx"), buf), cfg->err_rotation[0]);
    tweak_set((strcpy(p, "dRy"), buf), cfg->err_rotation[1]);
    tweak_set((strcpy(p, "dRz"), buf), cfg->err_rotation[2]);
#endif
    tweak_set((strcpy(p, "Cx"), buf), cfg->intrinsics[0 * 3 + 2]);
    tweak_set((strcpy(p, "Cy"), buf), cfg->intrinsics[1 * 3 + 2]);
    tweak_set((strcpy(p, "Fx"), buf), cfg->intrinsics[0 * 3 + 0]);
    tweak_set((strcpy(p, "Fy"), buf), cfg->intrinsics[1 * 3 + 1]);

    tweak_set((strcpy(p, "d0"), buf), cfg->distortion[0]);
    tweak_set((strcpy(p, "d1"), buf), cfg->distortion[1]);
    tweak_set((strcpy(p, "d2"), buf), cfg->distortion[2]);
    tweak_set((strcpy(p, "d3"), buf), cfg->distortion[3]);

    vm_tweak_camera_ro_refresh(id, cfg, tag);
}

static int vm_tweak_camera_update(int id, cfg_camera_t *cfg, const char *tag, const char *name, double value, cfg_camera_t *orig)
{
    if (!strcmp(name, "X"))                 cfg->position[0] = value;
    else if (!strcmp(name, "Y"))            cfg->position[1] = value;
    else if (!strcmp(name, "Z"))            cfg->position[2] = value;
    else if (!strcmp(name, "Rx"))           cfg->rotation[0] = value;
    else if (!strcmp(name, "Ry"))           cfg->rotation[1] = value;
    else if (!strcmp(name, "Rz"))           cfg->rotation[2] = value;
#ifdef BUILD_NATIVE
    else if (!strcmp(name, "dX"))           cfg->err_position[0] = value;
    else if (!strcmp(name, "dY"))           cfg->err_position[1] = value;
    else if (!strcmp(name, "dZ"))           cfg->err_position[2] = value;
    else if (!strcmp(name, "dRx"))          cfg->err_rotation[0] = value;
    else if (!strcmp(name, "dRy"))          cfg->err_rotation[1] = value;
    else if (!strcmp(name, "dRz"))          cfg->err_rotation[2] = value;
#endif
    else if (!strcmp(name, "Cx"))           cfg->intrinsics[0 * 3 + 2] = value;
    else if (!strcmp(name, "Cy"))           cfg->intrinsics[1 * 3 + 2] = value;
    else if (!strcmp(name, "Fx"))           cfg->intrinsics[0 * 3 + 0] = value;
    else if (!strcmp(name, "Fy"))           cfg->intrinsics[1 * 3 + 1] = value;
    else if (!strcmp(name, "d0"))           cfg->distortion[0] = value;
    else if (!strcmp(name, "d1"))           cfg->distortion[1] = value;
    else if (!strcmp(name, "d2"))           cfg->distortion[2] = value;
    else if (!strcmp(name, "d3"))           cfg->distortion[3] = value;
    else if (!strcmp(name, "Revert"))       return vm_tweak_camera_revert(id, cfg, orig, tag), 1;
    else return TRACE(1, _b("unknown param: %s=%f"), name, value), 0;

    return 1;
}

#ifdef BUILD_NATIVE
/**
 * @brief   World-generation setup
 */
static void vm_tweak_world_gen_setup(cfg_world_gen_t *cfg)
{
    cfg_world_pattern_t    *pattern;
    char    buffer[4096], *p = buffer;
    int     i;

    //tweak_add_widget("World generation");

    p += snprintf(buffer, sizeof(buffer), "external;");

    for (i = 0; i < cfg->number; i++)
    {
        p += snprintf(p, sizeof(buffer) - (int)(p - buffer), "%s%c", cfg->pattern[i].id, (i < cfg->number - 1 ? ';' : '\0'));
    }

    tweak_add_groupbox("world:pattern", buffer, 0);
    tweak_add_checkbox("world:car-enable", cfg->car_enable);
    tweak_add_slider("world:lens-shading-angle", 0, 360, cfg->lens_shading_angle_deg, 1);
    tweak_add_slider("world:lens-shading-size", 0, 1, cfg->lens_shading_size, 2);
    tweak_add_slider("world:clipping", 0, 10000, cfg->clipping_mm, 0);
}

static int vm_tweak_world_gen_update(cfg_world_gen_t *cfg, const char *tag, const char *name, double value)
{
    int     pattern = -1;

    if (!strcmp(name, "pattern"))                   pattern = (int)value;
    else if (!strcmp(name, "lens-shading-angle"))   cfg->lens_shading_angle_deg = value;
    else if (!strcmp(name, "lens-shading-size"))    cfg->lens_shading_size = value;
    else if (!strcmp(name, "clipping"))             cfg->clipping_mm = value;
    else if (!strcmp(name, "car-enable"))
    {
        /* ...ignore control if no car model is set */
        if (!cfg->car || cfg->car_enable == (uint32_t)value)    return 0;
        cfg->car_enable = (uint32_t)value;
    }
    else return TRACE(1, _b("world-gen unknown param: %s=%f"), name, value), 0;

    world_gen_update(pattern);

    return 1;
}
#endif

/**
 * @brief   Scene parameters configuration setup
 */
static inline void vm_tweak_scene_params_setup(cfg_scene_params_t *cfg, char *tag)
{
    char    buf[256], *p;
    int     i;

    p = buf + snprintf(buf, sizeof(buf), "%s:", tag);

    /* ...make a copy of default configuration */
    memcpy(&__vm_tweak_scene_params_cfg, cfg, sizeof(*cfg));

    tweak_add_layout(200, 0, "UI settings");
    tweak_add_spinbox((strcpy(p, "zoom-factor"), buf), 0.001, 100, cfg->zoom_factor, 3);
    tweak_add_spinbox((strcpy(p, "zoom-threshold"), buf), 0, 1000, cfg->zoom_threshold, 1);
    tweak_add_spinbox((strcpy(p, "zoom-min-length"), buf), 1000, 20000, cfg->zoom_min_length, 0);
    tweak_add_spinbox((strcpy(p, "zoom-max-length"), buf), 1000, 20000, cfg->zoom_max_length, 0);
    tweak_add_spinbox((strcpy(p, "pan-velocity-x"), buf), 1, 100, cfg->pan_velocity_x, 1);
    tweak_add_spinbox((strcpy(p, "pan-velocity-y"), buf), 1, 100, cfg->pan_velocity_y, 1);
    tweak_add_spinbox((strcpy(p, "pan-max-length"), buf), 1000, 20000, cfg->pan_max_length, 0);
    tweak_add_spinbox((strcpy(p, "rotate-velocity-yaw"), buf), 0.01, 10.0, cfg->rotate_velocity_yaw, 2);
    tweak_add_spinbox((strcpy(p, "rotate-velocity-pitch"), buf), 0.01, 10.0, cfg->rotate_velocity_pitch, 2);
    tweak_add_spinbox((strcpy(p, "rotate-pitch-max"), buf), 0.0, 90.0, cfg->rotate_pitch_max, 1);
    tweak_add_spinbox((strcpy(p, "rotate-pitch-min"), buf), 0.0, 90.0, cfg->rotate_pitch_min, 1);
    tweak_add_spinbox((strcpy(p, "rotate-pitch-threshold"), buf), 0.01, 10.0, cfg->rotate_pitch_threshold, 2);
    tweak_add_spinbox((strcpy(p, "rotate-yaw-threshold"), buf), 0.01, 10.0, cfg->rotate_yaw_threshold, 2);

    tweak_add_button((strcpy(p, "Revert"), buf));
}

static void vm_tweak_scene_params_refresh(cfg_scene_params_t *cfg, const char *tag)
{
    char    buf[256], *p;
    strcpy(buf, tag), p = strrchr(buf, ':') + 1;

    tweak_set((strcpy(p, "zoom-factor"), buf), cfg->zoom_factor);
    tweak_set((strcpy(p, "zoom-threshold"), buf), cfg->zoom_threshold);
    tweak_set((strcpy(p, "zoom-min-length"), buf), cfg->zoom_min_length);
    tweak_set((strcpy(p, "zoom-max-length"), buf), cfg->zoom_max_length);
    tweak_set((strcpy(p, "pan-velocity-x"), buf), cfg->pan_velocity_x);
    tweak_set((strcpy(p, "pan-velocity-y"), buf), cfg->pan_velocity_y);
    tweak_set((strcpy(p, "pan-max-length"), buf), cfg->pan_max_length);
    tweak_set((strcpy(p, "rotate-velocity-yaw"), buf), cfg->rotate_velocity_yaw);
    tweak_set((strcpy(p, "rotate-velocity-pitch"), buf), cfg->rotate_velocity_pitch);
    tweak_set((strcpy(p, "rotate-pitch-max"), buf), cfg->rotate_pitch_max);
    tweak_set((strcpy(p, "rotate-pitch-min"), buf), cfg->rotate_pitch_min);
    tweak_set((strcpy(p, "rotate-pitch-threshold"), buf), cfg->rotate_pitch_threshold);
    tweak_set((strcpy(p, "rotate-yaw-threshold"), buf), cfg->rotate_yaw_threshold);
}

static void vm_tweak_scene_params_revert(cfg_scene_params_t *cfg, const char *tag)
{
    memcpy(cfg, &__vm_tweak_scene_params_cfg, sizeof(*cfg));
    vm_tweak_scene_params_refresh(cfg, tag);
}

static int vm_tweak_scene_params_update(cfg_scene_params_t *cfg, const char *tag, const char *name, double value)
{
    if (!strcmp(name, "zoom-factor"))               cfg->zoom_factor = value;
    else if (!strcmp(name, "zoom-threshold"))       cfg->zoom_threshold = value;
    else if (!strcmp(name, "zoom-min-length"))      cfg->zoom_min_length = value;
    else if (!strcmp(name, "zoom-max-length"))      cfg->zoom_max_length = value;
    else if (!strcmp(name, "pan-velocity-x"))       cfg->pan_velocity_x = value;
    else if (!strcmp(name, "pan-velocity-y"))       cfg->pan_velocity_y = value;
    else if (!strcmp(name, "pan-max-length"))       cfg->pan_max_length = value;
    else if (!strcmp(name, "rotate-velocity-yaw"))  cfg->rotate_velocity_yaw = value;
    else if (!strcmp(name, "rotate-velocity-pitch"))cfg->rotate_velocity_pitch = value;
    else if (!strcmp(name, "rotate-pitch-max"))     cfg->rotate_pitch_max = value;
    else if (!strcmp(name, "rotate-pitch-min"))     cfg->rotate_pitch_min = value;
    else if (!strcmp(name, "rotate-pitch-threshold"))cfg->rotate_pitch_threshold = value;
    else if (!strcmp(name, "Revert"))               vm_tweak_scene_params_revert(cfg, tag);

    else return TRACE(1, _b("unknown param: %s=%f"), name, value), 0;

    return 1;
}

/**
 * @brief   Tweak-tool callback
 */
void tweak_on_update(const char *name)
{
    view_manager_t     *vm = __vm;

    /* ...bail out if initialization not done yet */
    if (!vm)        return;

    cfg_data_t         *cfg = __cfg;
    vehicle_state_t    *vehicle = vm_get_vehicle_state(vm);
    uint32_t            view, id;
    double              value = tweak_get(name, 0.0);
    char               *t;
    int                 update = 0;

    TRACE(0, _b("set param '%s': %f"), name, value);

    view_manager_lock(vm);

    /* ...parse name to find out what it belongs to */
    if (!strncmp(name, "stv:", 4))
    {
        update = vm_tweak_views_update(&cfg->ui, name, name + 4, MESH_STV, value);
        if (update)
        {
            view_manager_update_overlays(vm);
        }
    }
    else if (!strncmp(name, "scv:", 4))
    {
        update = vm_tweak_views_update(&cfg->ui, name, name + 4, MESH_SCV, value);
        if (update)
        {
            view_manager_update_overlays(vm);
        }
    }
    else if (!strncmp(name, "tv:", 3))
    {
        update = vm_tweak_views_update(&cfg->ui, name, name + 3, MESH_TV, value);
        if (update)
        {
            view_manager_update_overlays(vm);
        }
    }
    else if (!strncmp(name, "raw:", 4))
    {
        update = vm_tweak_views_update(&cfg->ui, name, name + 4, MESH_RAW, value);
        if (update)
        {
            view_manager_update_overlays(vm);
        }
    }
    else if (!strncmp(name, "raw-mc:", 4))
    {
        update = vm_tweak_views_update(&cfg->ui, name, name + 7, MESH_RAW_MCV, value);
        if (update)
        {
            view_manager_update_overlays(vm);
        }
    }
    else if (!strncmp(name, "camera:", 7))
    {
        id = strtoul(name + 7, &t, 0), t++;

        if (id < cfg->cameras_number)
        {
            update = vm_tweak_camera_update(id, &cfg->camera[id], name, t, value, __vm_tweak_camera_cfg[id]);
        }

        if (update)
        {
            view_manager_update_cameras(vm);
#ifdef BUILD_NATIVE
            world_gen_update(-1);
#endif
        }
    }
    else if (!strcmp(name, "layout:page"))
    {
        view_manager_set_layout(vm, (int32_t)value);
    }
    else if (!strcmp(name, "layout:language"))
    {
        char buf[256];
        config_change_language_runtime((int32_t)value, buf);
        ME_Debugger_F_Printf_v("language: %s\n", buf);

        vm_ui_language_reload(vm, buf);
        view_manager_update_ap(vm);
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "layout:Animate transitions"))
    {
        cfg->vm.enable_animation = (int32_t)value;
    }
    else if (!strcmp(name, "layout:fadeout-duration"))
    {
        cfg->vm.fadeout_duration = (uint32_t)value;
    }
    else if (!strcmp(name, "layout:steering"))
    {
        view_manager_set_steering_position(vm, (int32_t)value);
    }
    else if (!strncmp(name, "vehicle:", 8))
    {
        update = vm_tweak_vehicle_update(&cfg->vehicle, name, name + 8, value);
        if (update)
        {
            view_manager_update_overlays(vm);
        }
    }
    else if (!strncmp(name, "car_shadow:", 11))
    {
        update = vm_tweak_car_shadow_update(&cfg->guide.tv_hatched, name, name + 11, value);
        if (update)
        {
            view_manager_update_guide(vm);
        }
    }
    else if (!strncmp(name, "cc:", 3))
    {
        update = vm_tweak_cc_update(&cfg->cc, name, name + 3, value);
        if (update)
        {
            view_manager_update_cc(vm);
        }
    }
    else if (!strncmp(name, "render:", 7))
    {
        update = vm_tweak_car_renderer_update(&cfg->car_render, name, name + 7, value);
        if (update)
        {
            view_manager_update_car_model(vm);
        }
    }
    else if (!strncmp(name, "guide:", 6))
    {
        update = vm_tweak_guide_update(&cfg->guide, name, name + 6, value);
        if (update)
        {
            view_manager_update_guide(vm);
        }
    }
    else if (!strncmp(name, "pas:", 4))
    {
        update = vm_tweak_pas_update(&cfg->stv_pas, &vehicle->pas, name, name + 4, value);
        if (update)
        {
            view_manager_update_pas(vm);
        }
    }
    else if (!strncmp(name, "ap:", 3))
    {
        update = vm_tweak_ap_update(&vehicle->ap, name, name + 3, value);
        if (update)
        {
            view_manager_update_ap(vm);
            view_manager_update_ui(vm);
        }
    }
    else if (!strncmp(name, "apd:0:", 6))
    {
        update = vm_tweak_ap_dyn_update(&vehicle->ap, 0, name + 6, (int)value);
        if (update)
        {
            view_manager_update_ap(vm);
            view_manager_update_ui(vm);
        }
    }
    else if (!strncmp(name, "apd:1:", 6))
    {
        update = vm_tweak_ap_dyn_update(&vehicle->ap, 1, name + 6, (int)value);
        if (update)
        {
            view_manager_update_ap(vm);
            view_manager_update_ui(vm);
        }
    }
    else if (!strncmp(name, "apd:2:", 6))
    {
        update = vm_tweak_ap_dyn_update(&vehicle->ap, 2, name + 6, (int)value);
        if (update)
        {
            view_manager_update_ap(vm);
            view_manager_update_ui(vm);
        }
    }
    else if (!strncmp(name, "apd:3:", 6))
    {
        update = vm_tweak_ap_dyn_update(&vehicle->ap, 3, name + 6, (int)value);
        if (update)
        {
            view_manager_update_ap(vm);
            view_manager_update_ui(vm);
        }
    }
    else if (!strncmp(name, "cta:", 4))
    {
        update = vm_tweak_cta_update(&vehicle->cta, name, name + 4, value);
        if (update)
        {
            view_manager_update_cta(vm);
        }
    }
    else if (!strncmp(name, "rcta:", 5))
    {
        update = vm_tweak_cta_update(&vehicle->rcta, name, name + 5, value);
        if (update)
        {
            view_manager_update_cta(vm);
        }
    }
    else if (!strncmp(name, "odo:", 4))
    {
        update = vm_tweak_odo_update(&vehicle->odo, name, name + 4, value);
        if (update)
        {
            view_manager_update_odo(vm);
        }
    }
    else if (!strncmp(name, "aim:", 4))
    {
        update = vm_tweak_aiming_update(&vehicle->aiming, name, name + 4, value);
        if (update)
        {
            view_manager_update_aiming_error(vm);
        }
    }
#ifdef BUILD_NATIVE
    else if (!strncmp(name, "ui-mouse:", 9))
    {
        if (vm_tweak_scene_params_update(&cfg->scene_params_mouse, name, name + 9, value) != 0)
        {
            view_manager_update_overlays(vm);
        }
    }
#else
    else if (!strncmp(name, "ui-touch:", 9))
    {
        if (vm_tweak_scene_params_update(&cfg->scene_params_touch, name, name + 9, value) != 0)
        {
            view_manager_update_overlays(vm);
        }
    }
#endif
    else if (!strcmp(name, "state:Steering"))
    {
        vehicle->steering = value;
        view_manager_update_guide(vm);
    }
    else if (!strcmp(name, "state:Speed"))
    {
        vehicle->speed = value;
    }
    else if (!strcmp(name, "state:front-gl-enable"))
    {
        vehicle->front_gl_enable = (uint8_t)value;
        view_manager_update_guide(vm);
    }
    else if (!strcmp(name, "state:rear-gl-enable"))
    {
        vehicle->rear_gl_enable = (uint8_t)value;
        view_manager_update_guide(vm);
    }
    else if (!strcmp(name, "state:ffc-gl-enable"))
    {
        vehicle->ffc_gl_enable = (uint8_t)value;
        view_manager_update_guide(vm);
    }
    else if (!strcmp(name, "state:gl-disable"))
    {
        vehicle->gl_disable = (uint8_t)value;
        view_manager_update_guide(vm);
    }
    else if (!strcmp(name, "state:tha-gl-enable"))
    {
        vehicle->tha_gl_enable = (uint8_t)value;
        view_manager_update_guide(vm);
    }
    else if (!strcmp(name, "state:tha-coupler-enable"))
    {
        vehicle->tha_coupler_enable = (uint8_t)value;
        view_manager_update_tha(vm);
    }
    else if (!strcmp(name, "state:tha-coupler-pos-x"))
    {
        vehicle->tha_coupler_pos[0] = (int32_t)value;
        view_manager_update_tha(vm);
    }
    else if (!strcmp(name, "state:tha-coupler-pos-y"))
    {
        vehicle->tha_coupler_pos[1] = (int32_t)value;
        view_manager_update_tha(vm);
    }
    else if (!strcmp(name, "state:label"))
    {
        vehicle->label_enable = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:check-surroundings"))
    {
        vehicle->check_enable = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:exit-button"))
    {
        vehicle->exit_enable = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:trg-auto"))
    {
        vehicle->trg_auto = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:zoom"))
    {
        vehicle->zoom_icon = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:more_icons"))
    {
        vehicle->more_icon = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:more_icons_text"))
    {
        vehicle->more_icon_text = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:bottombutton_tvfv"))
    {
        vehicle->bottombutton_tvfv = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:bottombutton_tvrv"))
    {
        vehicle->bottombutton_tvrv = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:bottombutton_rcpv"))
    {
        vehicle->bottombutton_rcpv = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:bottombutton_fcpv"))
    {
        vehicle->bottombutton_fcpv = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:bottombutton_burv"))
    {
        vehicle->bottombutton_burv = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:bottombutton_ffcv"))
    {
        vehicle->bottombutton_ffcv = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:bottombutton_aux"))
    {
        vehicle->bottombutton_aux = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:tha-btn"))
    {
        vehicle->tha_button = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:tha-start"))
    {
        vehicle->tha_start_enable = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:tha-confirm"))
    {
        vehicle->tha_confirm_enable = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:tha-message"))
    {
        vehicle->tha_message_id = (uint8_t)value;
        view_manager_update_ui(vm);
    }
    else if (!strcmp(name, "state:tha-progress-enable"))
    {
        vehicle->tha_progress_enable = (uint8_t)value;
        view_manager_update_tha(vm);
    }
    else if (!strcmp(name, "state:wheel-state-fl"))
    {
        vehicle->wheel_state[0] = (uint8_t)value;
    }
    else if (!strcmp(name, "state:wheel-state-fr"))
    {
        vehicle->wheel_state[1] = (uint8_t)value;
    }
    else if (!strcmp(name, "state:wheel-state-rl"))
    {
        vehicle->wheel_state[2] = (uint8_t)value;
    }
    else if (!strcmp(name, "state:wheel-state-rr"))
    {
        vehicle->wheel_state[3] = (uint8_t)value;
    }
    else if (!strcmp(name, "state:tha-progress"))
    {
        vehicle->tha_progress_bar = (uint8_t)value;
        view_manager_update_tha(vm);
    }

    else if (!strcmp(name, "state:trsc-enable"))
    {
        vehicle->trsc_enable = (uint8_t)value;
        view_manager_update_trsc(vm);
    }
    else if (!strcmp(name, "state:trsc-orange-enable"))
    {
        vehicle->trsc_orange_enable = (uint8_t)value;
        view_manager_update_trsc(vm);
    }
    else if (!strcmp(name, "state:trsc-red-enable"))
    {
        vehicle->trsc_red_enable = (uint8_t)value;
        view_manager_update_trsc(vm);
    }
    else if (!strcmp(name, "state:trsc-jk-angle"))
    {
        vehicle->trsc_jk_angle_pct = (int8_t)value;
        view_manager_update_trsc(vm);
    }
    else if (!strcmp(name, "state:trsc-tad-angle"))
    {
        vehicle->trsc_tad_angle_pct = (int8_t)value;
        view_manager_update_trsc(vm);
    }
    else if (!strcmp(name, "state:trsc-angle0"))
    {
        vehicle->trsc_angle0 = (int8_t)value;
        view_manager_update_trsc(vm);
    }
    else if (!strcmp(name, "state:trsc-angle1"))
    {
        vehicle->trsc_angle1 = (int8_t)value;
        view_manager_update_trsc(vm);
    }
    else if (!strcmp(name, "trsc-red-trailer"))
    {
        vehicle->trsc_red_trailer = (int8_t)value;
        view_manager_update_trsc(vm);
    }
    else if (!strcmp(name, "state:door-fl"))
    {
        vehicle->door_state[0] = (uint8_t)value;
        view_manager_update_pas(vm);
    }
    else if (!strcmp(name, "state:door-fr"))
    {
        vehicle->door_state[1] = (uint8_t)value;
        view_manager_update_pas(vm);
    }
    else if (!strcmp(name, "state:door-rl"))
    {
        vehicle->door_state[2] = (uint8_t)value;
        view_manager_update_pas(vm);
    }
    else if (!strcmp(name, "state:door-rr"))
    {
        vehicle->door_state[3] = (uint8_t)value;
        view_manager_update_pas(vm);
    }
    else if (!strcmp(name, "state:door-b"))
    {
        vehicle->door_state[4] = (uint8_t)value;
        view_manager_update_pas(vm);
    }
    else if (!strcmp(name, "state:mirror-l"))
    {
        vehicle->mirror_state[0] = (uint8_t)value;
    }
    else if (!strcmp(name, "state:mirror-r"))
    {
        vehicle->mirror_state[1] = (uint8_t)value;
    }
    else if (!strcmp(name, "camera-failure:front"))
    {
        camera_failure_update(0, (uint32_t)value);
    }
    else if (!strcmp(name, "camera-failure:left"))
    {
        camera_failure_update(1, (uint32_t)value);
    }
    else if (!strcmp(name, "camera-failure:rear"))
    {
        camera_failure_update(2, (uint32_t)value);
    }
    else if (!strcmp(name, "camera-failure:right"))
    {
        camera_failure_update(3, (uint32_t)value);
    }
#ifndef BUILD_NATIVE
    else if (!strcmp(name, "camera-test:front"))
    {
        camera_test_update(0, (uint32_t)value);
    }
    else if (!strcmp(name, "camera-test:left"))
    {
        camera_test_update(1, (uint32_t)value);
    }
    else if (!strcmp(name, "camera-test:rear"))
    {
        camera_test_update(2, (uint32_t)value);
    }
    else if (!strcmp(name, "camera-test:right"))
    {
        camera_test_update(3, (uint32_t)value);
    }
#endif
#ifdef BUILD_NATIVE
    else if (!strncmp(name, "ui-mouse:", 9))
    {
        TRACE(1, _b("ui-mouse update: '%s'"), name);
        if (vm_tweak_scene_params_update(&cfg->scene_params_mouse, name, name + 9, value) != 0)
        {
            view_manager_update_overlays(vm);
        }
    }
    else if (!strncmp(name, "world:", 6))
    {
        vm_tweak_world_gen_update(&cfg->world_gen, name, name + 6, value);
    }
#endif
    else if (!strcmp(name, "log-level"))
    {
        LOG_LEVEL = (int)value;
    }
    else if (!strcmp(name, "background-debug"))
    {
        BACKGROUND_DEBUG = (int)value;
    }
    else if (!strcmp(name, "intensity-debug"))
    {
        INTENSITY_DEBUG = (int)value;
    }
    else if (!strcmp(name, "Save configuration"))
    {
        char    filename[4096];

        filename[0] = '\0';
        tweak_get_file_path(filename, "*.yaml", 0);

        if (filename[0] != '\0')
        {
            TRACE(1, _b("filename: '%s'"), filename);

            extern int config_store(cfg_data_t *cfg, char *fname);

            config_store(cfg, filename);
        }
    }
    else
    {
        TRACE(1, _b("unknown param '%s': %f"), name, value);
    }

    view_manager_unlock(vm);
}

/**
 * @brief   Register tweak-tool listener
 *
 * @param   vm[in]          View-manager handle
 * @param   cfg[in]         Global configuration data pointer
 */
void vm_tweak_register(view_manager_t *vm, cfg_data_t *cfg)
{
    vehicle_state_t    *vehicle = vm_get_vehicle_state(vm);
    int                 i;

    /* ...ignore subsequent registartion */
    if (__vm != NULL) return;

    /* ...create views default configurations array */
    __vm_cfg_mesh = calloc(cfg->ui.pages_num, sizeof(*__vm_cfg_mesh));

    /* ...setup server */
    tweak_add_widget("Screen layout");
    tweak_add_layout(200, 0, "");
    //tweak_add_checkbox("layout:Animate transitions", cfg->vm.enable_animation);

    /* ...avoid having more than 30 records in groupbox */
    if (cfg->ui.pages_num <= 30)
    {
        char    str[4096], *s = str;

        for (i = 0; i < cfg->ui.pages_num; i++)
        {
            s = s + snprintf(s, sizeof(str) - (int)(s - str), "%s;", cfg->ui.pages[i].id);
        }

        (s != str ? s[-1] = '\0' : 0);

        tweak_add_groupbox("layout:page", str, cfg->vm.default_layout);
    }
    else
    {
        tweak_add_spinbox("layout:page", 0, cfg->ui.pages_num, cfg->vm.default_layout, 0);
    }

    tweak_add_spinbox("layout:language", 0, 999, 0, 0);

    /* ...copy views configurations */
    for (i = 0; i < cfg->ui.pages_num; i++)
    {
        cfg_ui_page_t  *page = &cfg->ui.pages[i];
        cfg_mesh_t     *views;
        int             k;

        views = malloc(page->views_num * sizeof(*views));
        for (k = 0; k < page->views_num; k++)
        {
            if (page->views[k]->base.type == MESH_RAW_MCV)
            {
                memcpy(&views[k].base, &page->views[k]->base, sizeof(cfg_mesh_base_t));
                views[k].raw_mc.number = page->views[k]->raw_mc.number;
                views[k].raw_mc.raw = malloc(views[k].raw_mc.number * sizeof(cfg_raw_mesh_t));
                memcpy(views[k].raw_mc.raw, page->views[k]->raw_mc.raw, views[k].raw_mc.number * sizeof(cfg_raw_mesh_t));
            }
            else
            {
                memcpy(&views[k], page->views[k], sizeof(*views));
            }
        }

        views = malloc(page->views_num * sizeof(*views));
        for (k = 0; k < page->views_num; k++)
        {
            if (page->views[k]->base.type == MESH_RAW_MCV)
            {
                memcpy(&views[k].base, &page->views[k]->base, sizeof(cfg_mesh_base_t));
                views[k].raw_mc.number = page->views[k]->raw_mc.number;
                views[k].raw_mc.raw = malloc(views[k].raw_mc.number * sizeof(cfg_raw_mesh_t));
                memcpy(views[k].raw_mc.raw, page->views[k]->raw_mc.raw, views[k].raw_mc.number * sizeof(cfg_raw_mesh_t));
            }
            else
            {
                memcpy(&views[k], page->views[k], sizeof(*views));
            }
        }

        __vm_cfg_mesh[i] = views;
    }

    tweak_add_layout(200, 0, "");
    tweak_add_spinbox("layout:fadeout-duration", 0, 1000, cfg->vm.fadeout_duration, 0);
    tweak_add_groupbox("layout:steering", "RHD;LHD", cfg->vehicle.steering_lhd);
    tweak_add_spinbox("log-level", 0, 6, LOG_LEVEL, 0);
    tweak_add_checkbox("background-debug", BACKGROUND_DEBUG);
    tweak_add_checkbox("intensity-debug", INTENSITY_DEBUG);

    //tweak_add_button("Save configuration");
    //tweak_add_button("Load configuration");

#ifdef BUILD_NATIVE
    tweak_add_layout(200, 1, "");
    vm_tweak_world_gen_setup(&cfg->world_gen);
#endif

    tweak_add_layout(200, 0, "Vehicle state");
    tweak_add_slider("state:Steering", -450, +450, vehicle->steering, 0);
    tweak_add_slider("state:Speed", -20, 120, vehicle->speed, 0);
    tweak_add_spinbox("state:wheel-state-fl", 0, 3, 0, vehicle->wheel_state[0]);
    tweak_add_spinbox("state:wheel-state-fr", 0, 3, 0, vehicle->wheel_state[1]);
    tweak_add_spinbox("state:wheel-state-rl", 0, 3, 0, vehicle->wheel_state[2]);
    tweak_add_spinbox("state:wheel-state-rr", 0, 3, 0, vehicle->wheel_state[3]);

    tweak_add_layout(200, 1, "Overlays");
    tweak_add_checkbox("state:front-gl-enable", vehicle->front_gl_enable);
    tweak_add_checkbox("state:rear-gl-enable", vehicle->rear_gl_enable);
    tweak_add_checkbox("state:ffc-gl-enable", vehicle->ffc_gl_enable);
    tweak_add_checkbox("state:gl-disable", vehicle->gl_disable);
    tweak_add_checkbox("state:label", vehicle->label_enable);
    tweak_add_checkbox("state:check-surroundings", vehicle->check_enable);
    tweak_add_checkbox("state:exit-button", vehicle->exit_enable);
    tweak_add_spinbox("state:trg-auto", 0, 2, vehicle->tha_button, 0);
    tweak_add_spinbox("state:zoom", 0, 8, vehicle->zoom_icon, 0);
    tweak_add_spinbox("state:more_icons", 0, 5, vehicle->more_icon, 0);
    tweak_add_spinbox("state:more_icons_text", 0, 2, vehicle->more_icon_text, 0);
    tweak_add_layout(200, 1, "bottom_bar");
    tweak_add_spinbox("state:bottombutton_tvfv", 0, 2, vehicle->bottombutton_tvfv, 0);
    tweak_add_spinbox("state:bottombutton_tvrv", 0, 2, vehicle->bottombutton_tvrv, 0);
    tweak_add_spinbox("state:bottombutton_rcpv", 0, 2, vehicle->bottombutton_rcpv, 0);
    tweak_add_spinbox("state:bottombutton_fcpv", 0, 2, vehicle->bottombutton_fcpv, 0);
    tweak_add_spinbox("state:bottombutton_burv", 0, 2, vehicle->bottombutton_burv, 0);
    tweak_add_spinbox("state:bottombutton_ffcv", 0, 2, vehicle->bottombutton_ffcv, 0);
    tweak_add_spinbox("state:bottombutton_aux", 0, 4, vehicle->bottombutton_aux, 0);


    tweak_add_layout(200, 1, "THA overlays");
    tweak_add_spinbox("state:tha-btn", 0, 2, vehicle->trg_auto, 0);
    tweak_add_checkbox("state:tha-gl-enable", vehicle->tha_gl_enable);
    tweak_add_checkbox("state:tha-coupler-enable", vehicle->tha_coupler_enable);
    tweak_add_spinbox("state:tha-coupler-pos-x", 0, cfg->vm.width, vehicle->tha_coupler_pos[0], 0);
    tweak_add_spinbox("state:tha-coupler-pos-y", 0, cfg->vm.height, vehicle->tha_coupler_pos[1], 0);
    tweak_add_checkbox("state:tha-start", vehicle->tha_start_enable);
    tweak_add_checkbox("state:tha-confirm", vehicle->tha_confirm_enable);
    tweak_add_spinbox("state:tha-message", 0, 24, vehicle->tha_message_id, 0);
    tweak_add_checkbox("state:tha-progress-enable", vehicle->tha_progress_enable);
    tweak_add_slider("state:tha-progress", 0, 100, vehicle->tha_progress_bar, 0);

    tweak_add_layout(200, 1, "TRSC overlays");
    tweak_add_checkbox("state:trsc-enable", vehicle->trsc_enable);
    tweak_add_checkbox("state:trsc-orange-enable", vehicle->trsc_orange_enable);
    tweak_add_checkbox("state:trsc-red-enable", vehicle->trsc_red_enable);
    tweak_add_slider("state:trsc-jk-angle", -100, 100, vehicle->trsc_jk_angle_pct, 0);
    tweak_add_slider("state:trsc-tad-angle", -100, 100, vehicle->trsc_tad_angle_pct, 0);
    tweak_add_checkbox("state:trsc-red-trailer", vehicle->trsc_red_trailer);
    tweak_add_slider("state:trsc-angle0", 0, 90, vehicle->trsc_angle0, 0);
    tweak_add_slider("state:trsc-angle1", 0, 90, vehicle->trsc_angle1, 0);

#ifdef BUILD_NATIVE
    vm_tweak_scene_params_setup(&cfg->scene_params_mouse, "ui-mouse");
#else
    vm_tweak_scene_params_setup(&cfg->scene_params_touch, "ui-touch");
#endif

    tweak_add_layout(200, 1, "Animations");
    tweak_add_checkbox("state:door-fl", vehicle->door_state[0]);
    tweak_add_checkbox("state:door-fr", vehicle->door_state[1]);
    tweak_add_checkbox("state:door-rl", vehicle->door_state[2]);
    tweak_add_checkbox("state:door-rr", vehicle->door_state[3]);
    tweak_add_checkbox("state:door-b", vehicle->door_state[4]);
    tweak_add_checkbox("state:mirror-l", vehicle->mirror_state[0]);
    tweak_add_checkbox("state:mirror-r", vehicle->mirror_state[1]);

    tweak_add_layout(200, 1, "Camera failure");
    tweak_add_checkbox("camera-failure:front", 0);
    tweak_add_checkbox("camera-failure:left", 0);
    tweak_add_checkbox("camera-failure:rear", 0);
    tweak_add_checkbox("camera-failure:right", 0);

#if 0
#ifndef BUILD_NATIVE
    tweak_add_layout(200, 1, "Camera test");
    tweak_add_checkbox("camera-test:front", 0);
    tweak_add_checkbox("camera-test:left", 0);
    tweak_add_checkbox("camera-test:rear", 0);
    tweak_add_checkbox("camera-test:right", 0);
#endif
#endif

    vm_tweak_cameras_setup(cfg->camera, cfg->cameras_number);

    vm_tweak_vehicle_setup(&cfg->vehicle, "vehicle");
    vm_tweak_car_shadow_setup(&cfg->guide.tv_hatched, "car_shadow");

    vm_tweak_car_renderer_setup(&cfg->car_render, "render");

    vm_tweak_cc_setup(&cfg->cc, "cc");

    vm_tweak_guide_setup(&cfg->guide, "guide");
    vm_tweak_pas_setup(&cfg->stv_pas, &vehicle->pas, "pas");
    vm_tweak_ap_setup("ap");
    vm_tweak_ap_dynamic_setup("apd");
    tweak_add_widget("CTA");
    vm_tweak_cta_setup(&vehicle->cta, "cta", "Front CTA");
    vm_tweak_cta_setup(&vehicle->rcta, "rcta", "Rear CTA");

    vm_tweak_odo_setup(&vehicle->odo, "odo");
    vm_tweak_aiming_setup(&vehicle->aiming, "aim");

    vm_tweak_views_setup(&cfg->ui, "scv", MESH_SCV, "SCV-View");
    vm_tweak_views_setup(&cfg->ui, "stv", MESH_STV, "3D-View");
    vm_tweak_views_setup(&cfg->ui, "tv", MESH_TV, "Top-View");
    vm_tweak_views_setup(&cfg->ui, "raw", MESH_RAW, "Raw-View");
    vm_tweak_views_setup(&cfg->ui, "raw-mc", MESH_RAW_MCV, "Raw-MCV-View");

    TRACE(INFO, _b("tweak-tool layout created"));

    /* ...mark initialization is finished */
    __vm = vm;
    __cfg = cfg;
}
