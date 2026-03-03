// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           vp1_math_types.h
 *  @brief          Common math types
 *
 *  @version        1.01
 *  @author         Mikhail Vakhrushev & Alex Orlov
 *  @date           09.08.2019
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

#ifndef VP1_TYPES_H
#define VP1_TYPES_H

#include <ctype.h> /* Header file for isdigit */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdint.h>
#include <stdbool.h>


typedef float float32_t;
typedef double float64_t;

#ifndef __INTEGRITY
#define CAMERA_INTRINSIC_OPENCV
#endif

typedef struct
{
    float32_t x;
    float32_t y;
} vec2f_t;

typedef struct
{
    float32_t x;
    float32_t y;
    float32_t z;
} vec3f_t;

typedef struct
{
    float32_t x;
    float32_t y;
    float32_t z;
    float32_t w;
} vec4f_t;

typedef struct
{
    uint8_t x;
    uint8_t y;
} vec2u8_t;

typedef struct
{
    uint8_t x;
    uint8_t y;
    uint8_t z;
} vec3u8_t;

typedef struct
{
    uint32_t x;
    uint32_t y;
    uint32_t z;
} vec3u32_t;

typedef struct
{
    int16_t x;
    int16_t y;
} vec2i16_t;

typedef struct
{
    uint16_t x;
    uint16_t y;
    uint16_t z;
} vec3u16_t;

typedef struct
{
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t w;
} vec4u32_t;

typedef struct
{
    float32_t elem[3][3];
} mat33f_t;

typedef struct
{
    float32_t elem[4][4];
} mat44f_t;

typedef struct
{
    uint8_t x;
    uint8_t y;
    uint8_t z;
    uint8_t w;
} vec4u8_t;

typedef struct
{
    int32_t x;
    int32_t y;
} vec2i32_t;

typedef struct
{
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
} rect_ui32_t;

typedef struct
{
    float32_t x; 
    float32_t y;
    float32_t z;
    float32_t w;
} vec4_t; 

typedef struct
{
    float32_t fx;
    float32_t fy;
    float32_t cx;
    float32_t cy;
    float32_t K0;
    float32_t K1;
    float32_t K2;
    float32_t K3;
    float32_t K4;
    float32_t K5;
} vp_camera_intrinsic_t;

typedef struct 
{
    uint32_t wheel_pulse_count_mask;
    float bumper_offset;
    float wheel_base;
    float wheel_rear_lr_base;
    float wheel_front_lr_base;
    float pulses_per_meter;
    float length;
    float width_mirrors;
    float width_body;
    float steering_ratio;
} vp1evo_car_parameters_t;

typedef struct
{
    vec3f_t eye;
    vec3f_t center;
} vp1evo_lookat;

typedef struct
{
    vec3f_t eye;
    vec3f_t center;
    vec3f_t up;
} vp1evo_lookat_full;

typedef struct
{
    rect_ui32_t contextual_view;
    rect_ui32_t top_view;
    rect_ui32_t fullscreen_view;
} vp1evo_layout_in;

typedef struct
{
    rect_ui32_t car_image_contextual;
    rect_ui32_t car_image_top;

} vp1evo_layout_out;

typedef struct
{
    float32_t fx;
    float32_t fy;
    float32_t cx;
    float32_t cy;
    float32_t K0;
    float32_t K1;
    float32_t K2;
    float32_t K3;
    float32_t K4;
    float32_t K5;
} vp1evo_rear_intrinsic;

typedef struct
{
    mat33f_t   rotation_mat;
    vec3f_t   translation_vec;
} vp1evo_rear_cam_extrinsic;

typedef struct
{
    float32_t angle;
    float32_t hfov;
    float32_t vfov;
    float32_t sphere_q;
    float32_t ver_shift;
    float32_t z_distortion;
} vp1evo_panoramic_config_t;

typedef struct
{
    float32_t vertical_angle_rear;
    float32_t fov_x;
    float32_t ditortion_coefficient;
    float32_t affine_offset;
    float32_t view_angle_factor;
    float32_t view_angle_factor_clamp;
} vp1evo_standard_view_parameters_t;

typedef struct
{
    float32_t blind_spot_area_mm;
    uint16_t carline_width_px;
} vp1evo_top_view_parameters_t;

typedef struct
{
    float32_t longitudinal_range_mm;
    float32_t car_to_creen_ratio;
} vp1evo_zoom_view_parameters_t;

typedef struct
{
    float32_t horizontal_distance_mm;
    float32_t distance_near_mm;   /*< distance between car bumper and 1st line */
    float32_t distance_center_mm; /*< distance between car bumper and 2nd line */
    float32_t distance_far_mm;    /*< distance between car bumper and 3rd line */
    float32_t distance_start;
    float32_t distance_end;
    float32_t color_rear_left_near_sz;
    float32_t color_rear_left_far_sz;
    float32_t color_rear_right_near_sz;
    float32_t color_rear_right_far_sz;
    float32_t color_rear_hor_near_sz;
    float32_t color_rear_hor_center_sz;
    float32_t color_rear_hor_far_sz;
    float32_t shadow_sz;          /*< size of trajectory line(shadow part)  */
    float32_t shadow_max;         /*< size maximum shadow radius*/
    float32_t shadow_color;
    float32_t h_r;
    float32_t h_g;
    float32_t h_b;
    float32_t l_r;
    float32_t l_g;
    float32_t l_b;
} vp1evo_guide_line_config_t;


typedef struct
{
    uint32_t  hv_update_dist_mm;
    uint32_t  hv_upd_bfs_dist_mm;
    uint32_t  hv_blend_area_mm;
    uint32_t  hv_blend_side_mm;
    float32_t hv_viewport_marks_l_px;
    float32_t hv_viewport_marks_d_px;
    float32_t hv_zoom_viewport_marks_l_px;
    float32_t hv_zoom_viewport_marks_d_px;
    float32_t hv_topview_hatch_thickness;
    float32_t hv_zoomview_hatch_thickness;
    uint32_t hv_bfs_delta_time_msec;
    uint32_t hv_bfs_batch_size;
    float32_t hv_bfs_ssim_threshold;
    float32_t hv_bfs_lateral_range;
    float32_t hv_bfs_patch_height;
    uint64_t hv_fade_exp_duration_ms;
    uint64_t hv_fade_old_duration_ms;
    uint64_t hv_expiration_time_ms;
    float32_t wf_def_speed;
    float32_t wf_delta_thr;
} vp1evo_hv_config_t;


typedef struct
{
    vp1evo_panoramic_config_t         panoramic_config;
    vp1evo_standard_view_parameters_t standard_view_parameters;
    vp1evo_zoom_view_parameters_t     zoom_view_parameters;
    vp1evo_top_view_parameters_t      top_view_parameters;
    vp1evo_guide_line_config_t        guide_line_config;
    vp1evo_hv_config_t                hv_config;
} vp1evo_performance_parameters_t;

typedef struct
{
    vp1evo_performance_parameters_t parameters;
    vp1evo_car_parameters_t         car_parameters;
    vp1evo_rear_cam_extrinsic       extrinsics;
    vp1evo_rear_intrinsic           intrinsics;
} vp1evo_full_cfg_t;

typedef struct
{
    int32_t ov_vpark;
    int32_t brightness;
    int32_t contrast;
} vp1evo_persistent_default_t;


typedef struct
{
    mat33f_t   rotation_mat;
    vec3f_t    translation_vec;
} vp_camera_extrinsic_t; //$

typedef struct
{
    vec3f_t eye;
    vec3f_t center;
    vec3f_t up;
} vp_lookat_full;

typedef struct
{
    uint32_t width;     /**< width */
    uint32_t height;    /**< height*/
} sizei_t;

typedef enum
{
    SC_FALSE = 0, /**< represents false */
    SC_TRUE = 1   /**< represents false */
} sc_bool_t;

typedef struct
{
    uint32_t x; /**< First element*/
    uint32_t y; /**< Second element*/
} vec2u32_t; 

typedef struct
{
    int32_t x; /**< First element*/
    int32_t y; /**< Second element*/
} vec2i_t; /* represents int32 vector */

typedef struct
{
    vec2f_t data[4];    /**< data - pointer to data with*/
} detected_rect_t;

typedef struct
{
    vec2f_t center;     /**< the rectangle mass center                        */
    vec2f_t size;       /**< width and height of the rectangle                */
    float32_t angle;    /**< the rotation angle. When the angle is 0, 90, 180,*/
} rotated_rect_t;  /* rotated rect structure */

typedef struct
{
    vec3f_t _xyz;           /**< Translation vector */
    vec3f_t _xyz_rotations; /**< x - roll; y - pitch; z - yaw */
} camera_extrinsic_iso8855_t; 

typedef struct
{
    int32_t x;      /**< upper corner x position*/
    int32_t y;      /**< upper corner y position*/
    int32_t width;  /**< width */
    int32_t height; /**< hight */
} rect_i32_t;  /* represents int32 rectangle */

typedef struct
{
    uint32_t x;      /**< rectangle upper corner x*/
    uint32_t y;      /**< rectangle  upper corner y*/
    uint32_t width;  /**< rectangle  width*/
    uint32_t height; /**< rectangle  height*/
} rect_u32_t; 

#ifdef __cplusplus
extern "C" {
#endif

static inline rect_ui32_t rect_ui32_create(uint32_t l, uint32_t t, uint32_t r, uint32_t b)
{
    rect_ui32_t ret;
    ret.x = l;
    ret.y = t;
    ret.width = r - l;
    ret.height = b - t;
    return ret;
}

#ifdef __cplusplus
}
#endif

#endif // VP1_TYPES_H
