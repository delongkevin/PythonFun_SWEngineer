/*******************************************************************************
 * config.h
 *
 * Global configuration parameters
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

#ifndef __SV_CONFIG_H
#define __SV_CONFIG_H

/*******************************************************************************
 * Library version
 ******************************************************************************/

/**> Major version code */
#define SV_VERSION_MAJOR                3

/**> Minor version code */
#define SV_VERSION_MINOR                35

#define SV_VERSION_CODE(major, minor)           \
    (uint32_t)(((major) << 16U) | ((minor) & 0xFFFFU))

#define SV_VERSION_CODE_STR(major, minor)       \
    SV_VERSION_CODE_STR_(major, minor)

#define SV_VERSION_CODE_STR_(major, minor)      \
    #major "." #minor

/**> Version as numeric value */
#define SV_VERSION                      SV_VERSION_CODE(SV_VERSION_MAJOR, SV_VERSION_MINOR)

/**> Version as string literal */
#define SV_VERSION_STR                  SV_VERSION_CODE_STR(SV_VERSION_MAJOR, SV_VERSION_MINOR)

/*******************************************************************************
 * Global constants definitions
 ******************************************************************************/
/**
 * @brief   DT- Variants supported
 */
typedef enum DTCC_VARIANT_IDS {
    VAR_INVALID = 0,
    VAR1_BIGHORN_1_140WB_STD_Mirror,
    VAR2_BIGHORN_2_144WB_STD_Mirror,
    VAR3_BIGHORN_3_153WB_STD_Mirror,
    VAR4_REBEL_1_144WB_STD_Mirror,
    VAR5_REBEL_2_144WB_TOW_Mirror,
    VAR6_LARAMIE_2_144WB_STD_Mirror,
    VAR7_LARAMIE_3_153WB_STD_Mirror,
    VAR8_LARAMIE_5_144WB_TOW_Mirror,
    VAR9_LARAMIE_6_153WB_TOW_Mirror,
    VAR10_TRX_1_144WB_STD_Mirror,
    VAR11_TRX_2_144WB_TOW_Mirror,
    VAR12_LARAMIE_1_140WB_STD_Mirror,
    VAR13_LARAMIE_4_140WB_STD_Mirror,
    VAR14_TUNGSTEN_1_144WB_STD_Mirror,
    VAR15_TUNGSTEN_2_144WB_TOW_Mirror,
    VAR16_BIGHORN_4_140WB_TOW_Mirror,
    VAR17_BIGHORN_5_144WB_TOW_Mirror,
    VAR18_BIGHORN_6_153WB_TOW_Mirror,
    VAR19_WARLOCK_144WB_STD_Mirror,
    VAR_MAX_COUNT
}   DTCC_VARIANT_IDS_t;

typedef enum {
    LANG_1024_768 = 0,
    LANG_1200_900,
    POST_CONFIG,
    FCPV_POSITION_DATA,
    FCPV_ROTATION_DATA,
    FFC_GUIDELINE_DATA,
    BLIND_AREA,
    HATCHED_DATA,
    VAR_ATTR_MAX
} cfg_var_location_t;

/**
 * @brief   SV-cameras indices
 */
enum SV_CAMERA_IDS {
    SV_CAMERA_FRONT,
    SV_CAMERA_LEFT,
    SV_CAMERA_REAR,
    SV_CAMERA_RIGHT,
    SV_CAMERAS_NUMBER,
};

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**
 * @brief   Camera configuration data
 */
typedef struct cfg_camera
{
    /**> Camera friendly name */
    char               *name;

    /**> Camera identifier */
    char               *id;

    /**> Camera resolution */
    float32_t           resolution[2];

    /**> Distortion vector */
    float32_t           distortion[4];

    /**> Camera matrix 3*3; row-major order */
    float32_t           intrinsics[3 * 3];

    /**> Camera position in world */
    float32_t           position[3];

    /**> Camera rotation vector in world */
    float32_t           rotation[3];

    /**> Camera rotation matrix; row-major order */
    float32_t           rotation_matrix[3 * 3];

    /**> Rotation matrix validity flag */
    int                 rotation_matrix_valid;

    /**> Magna extrinsics format */
    int                 magna_format;

#ifdef BUILD_NATIVE
    /**> Camera position error in world */
    float32_t           err_position[3];

    /**> Camera rotation vector error in world */
    float32_t           err_rotation[3];
#endif

}   cfg_camera_t;

/*******************************************************************************
 * Color-correction configuration
 ******************************************************************************/

/**
 * @brief   Color-correction configuration data
 */
typedef struct cfg_cc
{
    /**> Enable color-correction module operation */
    int             enable;

    /**> Region on the ground for calculation of color statistics */
    float32_t       roi[SV_CAMERAS_NUMBER][4];

    /**> Clamping flag */
    int             clamp;

    /**> Averaging filter coefficients */
    float32_t       filter_coef;

    /**> Color additive term */
    float32_t       color[SV_CAMERAS_NUMBER][3];

    /**> Size of region */
    float32_t       size_mm;

    /**> X offset of region */
    float32_t       offset_x;

    /**> Y offset of region */
    float32_t       offset_y;

}   cfg_cc_t;

/*******************************************************************************
 * Vehicle parameters
 ******************************************************************************/

/**
 * @brief   Vehicle configuration
 */
typedef struct cfg_vehicle
{
    /**> Vehicle total length, mm */
    float32_t       length;

    /**> Total width without mirrors, mm */
    float32_t       width;

    /**> Total width with mirrors, mm */
    float32_t       width_mirrors;

    /**> Wheel-base, mm */
    float32_t       wheel_base;

    /**> Front overhang, mm */
    float32_t       front_overhang;

    /**> Rear overhang, mm */
    float32_t       rear_overhang;

    /**> Rear-side blind-area */
    float32_t       rear_blind_area;

    /**> Front-side blind-area */
    float32_t       front_blind_area;

    /**> Left-side blind-area */
    float32_t       left_blind_area;

    /**> Right-side blind-area */
    float32_t       right_blind_area;

    /**> Front track width, mm */
    float32_t       front_track_width;

    /**> Rear track width, mm */
    float32_t       rear_track_width;

    /**> Front wheel width, mm */
    float32_t       front_wheel_width;

    /**> Front wheel diameter, mm */
    float32_t       front_wheel_diameter;

    /**> Rear wheel width, mm */
    float32_t       rear_wheel_width;

    /**> Rear wheel diameter, mm */
    float32_t       rear_wheel_diameter;

    /**> Wheel-pulse width in mm */
    float32_t       wheel_pulse_width;

    /**> Steering angle to front wheel angle polynomial */
    float32_t       steering_coef[3];

    /**> Steering position */
    uint32_t        steering_lhd;

    /**> Parking sensor configuration */
    uint32_t        parking_sensor;

}   cfg_vehicle_t;

/**
 * @brief   CTA indicators configuration
 */
typedef struct cfg_cta
{
    /**> Left indicator destination tile */
    int32_t         dst_left[4];

    /**> Right indicator destination tile */
    int32_t         dst_right[4];

    /**> Left-outer indicator destination tile */
    int32_t         cta_left_outer_dst[4];

    /**> Left-inner indicator destination tile */
    int32_t         cta_left_inner_dst[4];

    /**> Right-outer indicator destination tile */
    int32_t         cta_right_outer_dst[4];

    /**> Right-inner indicator destination tile */
    int32_t         cta_right_inner_dst[4];

}   cfg_cta_t;

/**
 * @brief   Top-view car model overlay configuration
 */
typedef struct cfg_sonar
{
    /**> Car model destination tile */
    int32_t         sonar_car_model_dst[3][4];

    /**> Front-left wheel destination tile */
    int32_t         sonar_fl_wheel_dst[4];

    /**> Front-right wheel destination tile */
    int32_t         sonar_fr_wheel_dst[4];

    /**> Rear-left wheel destination tile */
    int32_t         sonar_rl_wheel_dst[4];

    /**> Rear-right wheel destination tile */
    int32_t         sonar_rr_wheel_dst[4];

    /**> Front-center sonar destination tile */
    int32_t         sonar_fc_pas_dst[2][3][4];

    /**> Front-right sonar destination tile */
    int32_t         sonar_fr_pas_dst[2][3][4];

    /**> Front-left sonar destination tile */
    int32_t         sonar_fl_pas_dst[2][3][4];

    /**> Rear-center sonar destination tile */
    int32_t         sonar_rc_pas_dst[2][3][4];

    /**> Rear-right sonar destination tile */
    int32_t         sonar_rr_pas_dst[2][3][4];

    /**> Rear-left sonar destination tile */
    int32_t         sonar_rl_pas_dst[2][3][4];

    /**> Front-center sonar failure destination tile */
    int32_t         sonar_fc_failure_dst[4];

    /**> Front-right sonar failure destination tile */
    int32_t         sonar_fr_failure_dst[4];

    /**> Front-left sonar failure destination tile */
    int32_t         sonar_fl_failure_dst[4];

    /**> Rear-center sonar failure destination tile */
    int32_t         sonar_rc_failure_dst[4];

    /**> Rear-right sonar failure destination tile */
    int32_t         sonar_rr_failure_dst[4];

    /**> Rear-left sonar failure destination tile */
    int32_t         sonar_rl_failure_dst[4];

    /**> Rear-left sonar destination tile */
    int32_t         sonar_pas_off_dst[4];

    /**> Sonar failure destination tile */
    int32_t         sonar_pas_failure_dst[4];

    /**> Left-side mask */
    int32_t         sonar_left_scan_dst[4];

    /**> Right-side mask */
    int32_t         sonar_right_scan_dst[4];

    /**> Door-open destination tiles */
    int32_t         sonar_door_open_dst[3][4][4];

    /**> Door-closed destination tiles */
    int32_t         sonar_door_closed_dst[3][4][4];

    /**> Trunk-open destination tiles */
    int32_t         sonar_trunk_open_dst[3][4];

}   cfg_sonar_t;

/*******************************************************************************
 * Mesh configuration
 ******************************************************************************/

/**
 * @brief   Mesh type
 */
enum mesh_type
{
    MESH_SCV = 0,
    MESH_STV = 1,
    MESH_TV = 2,
    MESH_MCV = 3,
    MESH_RAW = 4,
    MESH_RAW_MCV = 5,
    MESH_BV = 6,
    MESH_CTL = 7,
    MESH_NUMBER = 8,
};

/**
 * @brief   Generic mesh configuration
 */
typedef struct cfg_mesh_base
{
    /**> View type */
    uint32_t            type;

    /**> Destination tile */
    int32_t             dst[4];

}   cfg_mesh_base_t;

/**
 * @brief   Top-View mesh configuration
 */
typedef struct cfg_tv_mesh
{
    /**> Base mesh descriptor */
    cfg_mesh_base_t     base;

    /**> Scene scale, mm/pix */
    float32_t           scale;

    /**> Car shadow area: { Xmin, Ymin, Xmax, Ymax }, mm */
    float32_t           shadow[4];

    /**> Viewable area lengths: {Front / Left / Rear / Right}, mm */
    float32_t           area[4];

    /**> Blending zones bisectors angles, degrees */
    float32_t           angles[8];

    /**> Blending zones offsets, mm */
    float32_t           offsets[8];

    /**> Zones separator line thickness, mm */
    float32_t           separator_width;

    /**> Separator smoothness factor */
    float32_t           separator_exp;

    /**> Icon destination in pixels */
    float32_t           icon_dst[4];

}   cfg_tv_mesh_t;

/**
 * @brief   See-Through-View mesh configuration
 */
typedef struct cfg_stv_mesh
{
    /**> Base mesh descriptor */
    cfg_mesh_base_t     base;

    /**> Virtual camera position, mm */
    float32_t           position[3];

    /**> Virtual camera direction, mm */
    float32_t           look_at[3];

    /**> Rotation angles of virtual camera, degrees */
    float32_t           rotation[3];

    /**> Virtual camera (horizontal/vertical) field of view, degrees */
    float32_t           fov[2];

    /**> Car shadow area: { Xmin, Ymin, Xmax, Ymax }, mm */
    float32_t           shadow[4];

    /**> Blending zones bisectors angles, degrees */
    float32_t           angles[8];

    /**> Blending zones offsets, mm */
    float32_t           offsets[8];

    /**> Parabolic mesh parameters: { Rx, Ry, slope, smoothness} */
    float32_t           parabolic[4];

    /**> Zones separator line thickness, mm */
    float32_t           separator_width;

    /**> Separator smoothness factor */
    float32_t           separator_exp;

}   cfg_stv_mesh_t;

/**
 * @brief   Single-Camera-View mesh configuration
 */
typedef struct cfg_scv_mesh
{
    /**> Base mesh descriptor */
    cfg_mesh_base_t     base;

    /**> Camera id */
    uint32_t            id;

    /**> Position of virtual camera, mm */
    float32_t           position[3];

    /**> Orientation of virtual camera: { Roll, Pitch, Yaw }, degrees */
    float32_t           rotation[3];

    /**> Virtual camera (horizontal/vertical) field of view, degrees */
    float32_t           fov[4];

    /**> Distortion proportion (0 - rectified, 1 - fish-eye) */
    float32_t           distortion[2];

    /**> Compression ratio in horizontal direction */
    float32_t           compression[2];

    /**> Mask area on the ground: {Xmin, Ymin, Xmax, Ymax} */
    float32_t           mask[4];

    /**> Angles adjustment coefficients for steering angle */
    float32_t           fov_adj_coef[4];

    /**> Yaw-angle adjustment coefficient for steering angle */
    float32_t           yaw_adj_coef;

    float32_t           zoom;

    float32_t           zoom_point[2];

}   cfg_scv_mesh_t;

/**
 * @brief   Raw mesh configuration
 */
typedef struct cfg_raw_mesh
{
    /**> Base mesh descriptor */
    cfg_mesh_base_t     base;

    /**> Camera identifier */
    uint32_t            id;

    /**> Crop area */
    int32_t             crop[4];

}   cfg_raw_mesh_t;

/**
 * @brief   Raw mesh configuration
 */
typedef struct cfg_ctlval_mesh
{
    /**> Base mesh descriptor */
    cfg_mesh_base_t     base;

    /**> Camera mask */
    uint32_t            cameras;

    /**> dst point */
    int32_t             output_point[2];

}   cfg_ctlval_mesh_t;

/**
 * @brief   Raw mesh configuration
 */
typedef struct cfg_raw_mcv_mesh
{
    /**> Base mesh descriptor */
    cfg_mesh_base_t     base;

    /**> Number of single-camera-views */
    uint32_t            number;

    /**> Array of raw camera views */
    cfg_raw_mesh_t     *raw;

}   cfg_raw_mcv_mesh_t;

/**
 * @brief   Multi-Camera-View mesh configuration
 */
typedef struct cfg_mcv_mesh
{
    /**> Base mesh descriptor */
    cfg_mesh_base_t     base;

    /**> Number of single-camera-views */
    uint32_t            number;

    /**> Array of single-camera views */
    cfg_scv_mesh_t     *scv;

}   cfg_mcv_mesh_t;

/**
 * @brief   Bird-view mesh for historical buffer update
 */
typedef struct cfg_bv_mesh
{
    /**> Window dimensions, pixels */
    int32_t             dim[SV_CAMERAS_NUMBER][3];

    /**> Front blind area, mm */
    float32_t           front_blind_area;

    /**> Rear blind area, mm */
    float32_t           rear_blind_area;

    /**> Left blind area, mm */
    float32_t           left_blind_area;

    /**> Right blind area, mm */
    float32_t           right_blind_area;

    /**> Horizontal slice width, mm */
    float32_t           slice_width_hor;

    /**> Horizontal slice height, mm */
    float32_t           slice_height_hor;

    /**> Vertical slice width, mm */
    float32_t           slice_width_vert;

    /**> Vertical slice height, mm */
    float32_t           slice_height_vert;

}   cfg_bv_mesh_t;

/**
 * @brief   Generic mesh configuration
 */
typedef union cfg_mesh
{
    /**> Base mesh descriptor */
    cfg_mesh_base_t     base;

    /**> Single-camera view */
    cfg_scv_mesh_t      scv;

    /**> 3D-view */
    cfg_stv_mesh_t      stv;

    /**> Top-view */
    cfg_tv_mesh_t       tv;

    /**> Multi-camera view */
    cfg_mcv_mesh_t      mcv;

    /**> Raw camera view */
    cfg_raw_mesh_t      raw;

    /**> Multi-camera raw view */
    cfg_raw_mcv_mesh_t  raw_mc;

    /**> ctlval mesh */
    cfg_ctlval_mesh_t   ctl;

}   cfg_mesh_t;

/*******************************************************************************
 * Car 3D model parameters
 ******************************************************************************/

/**
 * @brief   IBL configuration
 */
typedef struct cfg_ibl
{
    /**> Use spectral harmonics for diffuse irradiance */
    char           *sh;

    /**> Diffuse irradiance cubemap */
    char           *diffuse;

    /**> Specular radiance cubemap */
    char           *specular;

    /**> BRDF look-up table */
    char           *lut;

}   cfg_ibl_t;

/**
 * @brief   Car model configuration (for OBJ file)
 */
typedef struct cfg_model
{
    /**> Car model filename */
    char           *car_model;

    /**> IBL configuration */
    cfg_ibl_t      *ibl;

    /**> Car static body groups identifiers */
    char           *car_body_groups;

    /**> Car interior groups identifiers */
    char           *car_interior_groups;

    /**> Car shadow groups identifiers */
    char           *car_shadow_groups;

    /**> Car wheels groups identifiers */
    char           *car_wheels_groups[4];

    /**> Doors animations identifiers */
    char           *anim_door[5];

    /**> Mirrors animations identifiers */
    char           *anim_mirror[2];

}   cfg_model_t;

/**
 * @brief   Car model rendering parameters
 */
typedef struct cfg_car_render
{
    /**> Vehicle front window opaqueness level */
    float32_t       window_front_opaqueness;

    /**> Vehicle rear window opaqueness level */
    float32_t       window_rear_opaqueness;

    /**> Wheels transparency gradient start height */
    float32_t       wheel_height_min;

    /**> Wheels transparency gradient stop height */
    float32_t       wheel_height_max;

    /**> Wheel height gradient exponent */
    float32_t       wheel_gradient_exp;

    /**> Body opaqueness level */
    float32_t       body_opaqueness;

    /**> Head opaqueness level */
    float32_t       head_opaqueness;

    /**> Wheel mask opaqueness level */
    float32_t       mask_opaqueness;

    /**> Rear gradient cut-off X-coordinate */
    float32_t       rear_gradient_x;

    /**> Rear gradient scale factor */
    float32_t       rear_gradient_scale;

    /**> Front gradient cut-off X-coordinate */
    float32_t       front_gradient_x;

    /**> Front gradient scale factor */
    float32_t       front_gradient_scale;

    /**> Vertical gradient cut-off Z-coordinate */
    float32_t       height_gradient_z;

    /**> Vertical gradient scale factor */
    float32_t       height_gradient_scale;

    /**> Mask rendering disable mode */
    int             mask_disable;

    /**> Front mask gradient start position */
    float32_t       front_mask_gradient_start;

    /**> Front mask gradient scale position */
    float32_t       front_mask_gradient_stop;

    /**> Front mask gradient exponent factor */
    float32_t       front_mask_gradient_exp;

    /**> Rear mask gradient start position */
    float32_t       rear_mask_gradient_start;

    /**> Rear mask gradient scale position */
    float32_t       rear_mask_gradient_stop;

    /**> Rear mask gradient exponent factor */
    float32_t       rear_mask_gradient_exp;

    /**> Front weel width scale factor */
    float32_t       front_wheel_width_scale;

    /**> Rear wheel width scale factor */
    float32_t       rear_wheel_width_scale;

    /**> Wheel-mask ambient color */
    uint8_t         mask_ambient_color[3];

    /**> Wheel ambient color */
    uint8_t         wheel_ambient_color[3];

    /**> Lights tail lens color/transmittance */
    uint8_t         lights_tail_base_color[4];

    /**> Lights tail lens color/transmittance */
    uint8_t         lights_tail_lens_color[4];

    /**> Lights tail shine color/transmittance */
    uint8_t         lights_tail_shine_color[4];

    /**> Lights tail lens color/transmittance */
    uint8_t         lights_tail_corner_color[4];

}   cfg_car_render_t;

/*******************************************************************************
 * Guidelines configuration parameters
 ******************************************************************************/

/**
 * @brief   Dynamic guidelines configuration for Front/Rear/3D views
 */
typedef struct cfg_guide_dynamic_fr
{
    /**> Total length of guideline, mm */
    float32_t       total_length;

    /**> Total width of guideline, mm */
    float32_t       vehicle_width;

    /**> Hidden area width, mm */
    float32_t       hidden_width;

    /**> Vehicle trajectory line width */
    float32_t       vehicle_trajectory_width;

    /**> Wheel lateral distance, mm */
    float32_t       wheel_lateral_distance;

    /**> Wheel trajectory width, mm */
    float32_t       wheel_width;

    /**> Wheel trajectory border width, mm */
    float32_t       wheel_border_width;

    /**> Center trajectory line width */
    float32_t       center_trajectory_width;

    /**> Center trajectory line height pos */
    float32_t       center_trajectory_z;

    /**> Distance to the close section line, mm */
    float32_t       distance_marker_1;

    /**> Distance to the middle section line, mm */
    float32_t       distance_marker_2;

    /**> Distance to the far section line, mm */
    float32_t       distance_marker_3;

    /**> Distance to the middle line, mm */
    float32_t       distance_marker_middle;

    /**> Width of the distance marker line, mm */
    float32_t       distance_marker_width;

    /**> Length of the distance marker line, mm */
    float32_t       distance_marker_length;

    /**> Horizontal line width, mm */
    float32_t       horizontal_line_width;

    /**> Fade section length for starting segment */
    float32_t       fade_section_start_length;

    /**> Fade section length for ending segment */
    float32_t       fade_section_end_length;

    /**> Side line drawing angle threshold */
    float32_t       side_angle_threshold;

    float32_t       ffc_width;
    float32_t       ffc_tire_width;
    float32_t       ffc_hidden;
    float32_t       ffc_length;

}   cfg_guide_dynamic_fr_t;

/**
 * @brief   Fixed guidelines configuration for Front/Rear-Top/STV views
 */
typedef struct cfg_guide_fixed_fr
{
    /**> Total length of guideline, mm */
    float32_t       total_length;

    /**> Total width of guideline, mm */
    float32_t       total_width;

    /**> Guideline width */
    float32_t       line_width;

    /**> Front-end gap, mm */
    float32_t       front_gap;

    /**> Rear-end gap, mm */
    float32_t       rear_gap;

    /**> Distance to the close section line, mm */
    float32_t       close_section_length;

    /**> Width of the close-section surface for front-/rear-wide views */
    float32_t       surface_close_width;

    /**> Gap between close-section surface and static line */
    float32_t       surface_close_gap;

    /**> Close interlocking line width */
    float32_t       close_interlock_width;

    /**> Close interlocking line gap */
    float32_t       close_interlock_gap;

    /**> Fade section length for starting segment */
    float32_t       fade_section_start_length;

    /**> Fade section length for ending segment */
    float32_t       fade_section_end_length;

}   cfg_guide_fixed_fr_t;

/**
 * @brief   Fixed guidelines configuration for side-views
 */
typedef struct cfg_guide_fixed_sv
{
    /**> Total length of the statis carpet */
    float32_t       total_length;

    /**> Total width of the static carpet */
    float32_t       total_width;

    /**> Guideline longitudinal (vertical) line width */
    float32_t       vert_line_width;

    /**> Guideline lateral (horizontal) line width */
    float32_t       hor_line_width;

    /**> Gap between horizontal and vertical lines */
    float32_t       hor_line_gap;

    /**> Horizontal line start position (Y-coordinate) */
    float32_t       hor_line_start;

    /**> Vertical line start position (X-coordinate) */
    float32_t       vert_line_start;

    /**> Static surface bar width */
    float32_t       bar_width;

    /**> Static surface bar gradient width */
    float32_t       bar_fade_width;

    /**> Horizontal line fading segment length */
    float32_t       hor_fade_length;

    /**> Vertical line fading segment length */
    float32_t       vert_fade_length;

}   cfg_guide_fixed_sv_t;

/**
 * @brief   Top-View guidelines configuration
 */
typedef struct cfg_guide_tv
{
    /**> Total length of guideline, mm */
    float32_t       total_length;

    /**> Total width of guideline, mm */
    float32_t       total_width;

    /**> Guideline width */
    float32_t       line_width;

    /**> Front-end gap, mm */
    float32_t       front_gap;

    /**> Rear-end gap, mm */
    float32_t       rear_gap;

    /**> Distance to the close section line, mm */
    float32_t       close_section_length;

    /**> Fade section length for starting segment */
    float32_t       fade_section_start_length;

    /**> Fade section length for ending segment */
    float32_t       fade_section_end_length;

}   cfg_guide_tv_t;

/**
 * @brief   Dynamic guidelines configuration for Front/Rear-Top/STV views
 */
typedef struct cfg_guide_dynamic_sv
{
    /**> Total length of guideline, mm */
    float32_t       total_length;

    /**> Total width of guideline, mm */
    float32_t       total_width;

    /**> Dynamic guideline width */
    float32_t       line_width;

    /**> Fade section length for starting segment */
    float32_t       fade_section_start_length;

    /**> Fade section length for ending segment */
    float32_t       fade_section_end_length;

    /**> Line width increment */
    float32_t       delta_width;

}   cfg_guide_dynamic_sv_t;

/**
 * @brief   THA guideline configuration
 */
typedef struct cfg_guide_tha
{
    /**> Ball start position (offset), mm */
    float32_t       offset[3];

    /**> Full angle of sector, degrees */
    float32_t       angle;
    
    /**> Full detection angle of sector, degrees */
    float32_t       det_angle;

    /**> Sector length, mm */
    float32_t       length;

    /**> Line width, mm */
    float32_t       line_width;

    /**> Line border width, mm */
    float32_t       border_width;

    float32_t       radius;
    float32_t       arc_len;

    /**> Canvas color, RGB */
    uint8_t         canvas_color[3];

    /**> Canvas transmittance, percents */
    uint8_t         canvas_transmittance;

    /**> Line color, RGB */
    uint8_t         line_color[3];

    /**> Line transmittance, percents */
    uint8_t         line_transmittance;

}   cfg_guide_tha_t;


#define TV_HATCHED_MAX_POINTS 8

/**
 * @brief   Top-view hatched area configuration 
 */
typedef struct cfg_guide_tv_hatched
{
    /**> knee points */
    float32_t points[TV_HATCHED_MAX_POINTS][2];

    uint32_t num_points;

    /**> rounding off parameter of each corner [0-1] */
    float32_t rounding_off_corners[TV_HATCHED_MAX_POINTS - 2U];

}   cfg_guide_tv_hatched_t;

/**
 * @brief   Guidelines configuration parameters for Front/Rear views
 */
typedef struct cfg_guide
{
    /**> Dynamic guidelines configuration for front view */
    cfg_guide_dynamic_fr_t  dynamic_front;

    /**> Dynamic guidelines configuration for rear view */
    cfg_guide_dynamic_fr_t  dynamic_rear;

    /**> Dynamic guidelines configuration for front STV-view */
    cfg_guide_dynamic_fr_t  dynamic_front_stv;

    /**> Dynamic guidelines configuration for rear STV-view */
    cfg_guide_dynamic_fr_t  dynamic_rear_stv;

    /**> Dynamic guidelines for side-view */
    cfg_guide_dynamic_sv_t  dynamic_sv;

    /**> Dynamic side-guidelines for STV-view */
    cfg_guide_dynamic_sv_t  dynamic_sv_stv;

    /**> Fixed guidelines configuration for front narrow view */
    cfg_guide_fixed_fr_t    fixed_front;

    /**> Fixed guidelines configuration for front wide view */
    cfg_guide_fixed_fr_t    fixed_front_wide;

    /**> Fixed guidelines configuration for rear narrow view */
    cfg_guide_fixed_fr_t    fixed_rear;

    /**> Fixed guidelines configuration for rear wide view */
    cfg_guide_fixed_fr_t    fixed_rear_wide;

    /**> Fixed guidelines configuration for side-view */
    cfg_guide_fixed_sv_t    fixed_sv;

    /**> Top-view guidelines configuration */
    cfg_guide_tv_t          tv;

    /**> Top-view hatched area configuration */
    cfg_guide_tv_hatched_t  tv_hatched;

    /**> THA guidelines */
    cfg_guide_tha_t         tha;

    /**> Static surface color */
    uint8_t                 static_surface_color[3];

    /**> Static surface transmittance */
    uint8_t                 static_surface_transmittance;

    /**> Static surface close section color */
    uint8_t                 static_surface_close_color[3];

    /**> Static surface close section transmittance */
    uint8_t                 static_surface_close_transmittance;

    /**> Static guideline color */
    uint8_t                 static_line_color[3];

    /**> Static line transmittance */
    uint8_t                 static_line_transmittance;

    /**> Color of the dynamic guideline close section */
    uint8_t                 dynamic_close_section_color[3];

    /**> Transmittance of the dynamic guideline close section */
    uint8_t                 dynamic_close_transmittance;

    /**> Transmittance of the dynamic guideline middle section */
    uint8_t                 dynamic_middle_transmittance;

    /**> Transmittance of the dynamic guideline far section */
    uint8_t                 dynamic_far_transmittance;

    /**> Dynamic guideline transmittance */
    uint8_t                 line_transmittance;

    /**> Color of the dynamic guideline */
    uint8_t                 dynamic_line_color[3];

    /**> Color of the TV dynamic guideline close section */
    uint8_t                 tv_close_section_color[3];

    /**> Transmittance of the TV dynamic guideline close section */
    uint8_t                 tv_close_section_transmittance;

    /**> Color of the TV dynamic guideline  */
    uint8_t                 tv_line_color[3];

    /**> Transmittance of the TV dynamic guideline */
    uint8_t                 tv_line_transmittance;

}   cfg_guide_t;

/**
 * @brief   Parking sonars configuration
 */
typedef struct cfg_stv_pas
{
    /**> Sonar origins, mm */
    float32_t       sonar_origin[6][2];

    /**> Sonars directions angles, deg */
    float32_t       sonar_direction[6];

    /**> STV PAS object transparency level, in percents */
    uint8_t         stv_pas_transparency;

    /**> STV PAS close-distance object color */
    uint8_t         stv_pas_close_color[3];

    /**>  STV PAS middle-distance object color */
    uint8_t         stv_pas_middle_color[3];

    /**> STV PAS far-distance object color */
    uint8_t         stv_pas_far_color[3];

    /**> STV PAS maximum-distance object color */
    uint8_t         stv_pas_max_color[3];

    /**> STV PAS obstacle object color */
    uint8_t         stv_obstacle_color[3];

    /**> STV PAS obstacle object transparency */
    uint8_t         stv_obstacle_transparency;

    /**> STV PAS obstacle object color */
    uint8_t         stv_obstacle_line_color[3];

    /**> STV PAS obstacle line transparency */
    uint8_t         stv_obstacle_line_transparency;

    /**> STV PAS obstacle line width */
    float32_t       stv_obstacle_line_width;

    /**> Distance to object for "close" range */
    float32_t       stv_obstacle_close_distance;

    /**> Distance to object for "middle" range */
    float32_t       stv_obstacle_middle_distance;

    /**> Distance to object for "far" range */
    float32_t       stv_obstacle_far_distance;

    /**> Distance to object for "maximal" range */
    float32_t       stv_obstacle_max_distance;

    /**> Obstacle default dimensions, mm */
    float32_t       stv_obstacle_dim[3];

    /**> Obstacle dimensions scale */
    float32_t       stv_obstacle_dim_scale[3];

    /**> Distance switch factor */
    float32_t       stv_obstacle_switch_factor;

    /**> Object fadeout duration */
    uint32_t        stv_obstacle_fadeout_duration;

}   cfg_stv_pas_t;

/*******************************************************************************
 * Icons configuration
 ******************************************************************************/

/**
 * @brief   Icon identifiers
 */
enum icon_type
{
    ICON_UNKNOWN,
    ICON_BORDER,
    ICON_CAR_MODEL0,
    ICON_CAR_MODEL1,
    ICON_CAR_MODEL2,
    ICON_CAR_MODEL_SV,
    ICON_TYRE_FRONT,
    ICON_TYRE_REAR,
    ICON_CAR_TYRE,
    ICON_SCAN_MASK,

    ICON_DOOR_FL_OPEN0,
    ICON_DOOR_FL_OPEN1,
    ICON_DOOR_FL_OPEN2,
    ICON_DOOR_FL_CLOSED0,
    ICON_DOOR_FL_CLOSED1,
    ICON_DOOR_FL_CLOSED2,
    ICON_DOOR_FR_OPEN0,
    ICON_DOOR_FR_OPEN1,
    ICON_DOOR_FR_OPEN2,
    ICON_DOOR_FR_CLOSED0,
    ICON_DOOR_FR_CLOSED1,
    ICON_DOOR_FR_CLOSED2,
    ICON_DOOR_RL_OPEN0,
    ICON_DOOR_RL_OPEN1,
    ICON_DOOR_RL_OPEN2,
    ICON_DOOR_RL_CLOSED0,
    ICON_DOOR_RL_CLOSED1,
    ICON_DOOR_RL_CLOSED2,
    ICON_DOOR_RR_OPEN0,
    ICON_DOOR_RR_OPEN1,
    ICON_DOOR_RR_OPEN2,
    ICON_DOOR_RR_CLOSED0,
    ICON_DOOR_RR_CLOSED1,
    ICON_DOOR_RR_CLOSED2,
    ICON_TRUNK_OPEN0,
    ICON_TRUNK_OPEN1,
    ICON_TRUNK_OPEN2,
    ICON_PAS_FL_CAUTION0,
    ICON_PAS_FL_CAUTION1,
    ICON_PAS_FL_CAUTION2,
    ICON_PAS_FL_CRITICAL0,
    ICON_PAS_FL_CRITICAL1,
    ICON_PAS_FL_CRITICAL2,
    ICON_PAS_FC_CAUTION0,
    ICON_PAS_FC_CAUTION1,
    ICON_PAS_FC_CAUTION2,
    ICON_PAS_FC_CRITICAL0,
    ICON_PAS_FC_CRITICAL1,
    ICON_PAS_FC_CRITICAL2,
    ICON_PAS_FR_CAUTION0,
    ICON_PAS_FR_CAUTION1,
    ICON_PAS_FR_CAUTION2,
    ICON_PAS_FR_CRITICAL0,
    ICON_PAS_FR_CRITICAL1,
    ICON_PAS_FR_CRITICAL2,
    ICON_PAS_RL_CAUTION0,
    ICON_PAS_RL_CAUTION1,
    ICON_PAS_RL_CAUTION2,
    ICON_PAS_RL_CRITICAL0,
    ICON_PAS_RL_CRITICAL1,
    ICON_PAS_RL_CRITICAL2,
    ICON_PAS_RC_CAUTION0,
    ICON_PAS_RC_CAUTION1,
    ICON_PAS_RC_CAUTION2,
    ICON_PAS_RC_CRITICAL0,
    ICON_PAS_RC_CRITICAL1,
    ICON_PAS_RC_CRITICAL2,
    ICON_PAS_RR_CAUTION0,
    ICON_PAS_RR_CAUTION1,
    ICON_PAS_RR_CAUTION2,
    ICON_PAS_RR_CRITICAL0,
    ICON_PAS_RR_CRITICAL1,
    ICON_PAS_RR_CRITICAL2,

    ICON_HITCH_COUPLER,
    ICON_HITCH_COUPLER_LOCKED,
    ICON_HITCH_SLIDER,
    ICON_HITCH_SLIDER_LOCKED,
    ICON_COUPLER_TARGET,

    ICON_TRSC_BASE_SVC,
    ICON_TRSC_ORANGE_SVC,
    ICON_TRSC_RED_SVC,
    ICON_TRSC_ORANGE_RED_SVC,
    ICON_TRSC_DOTTED_SVC,
    ICON_TRSC_TRAILER_SVC,
    ICON_TRSC_VEHICLE_SVC0,
    ICON_TRSC_VEHICLE_SVC1,
    ICON_TRSC_VEHICLE_SVC2,

    ICON_TRSC_BASE_TRG,
    ICON_TRSC_ORANGE_TRG,
    ICON_TRSC_RED_TRG,
    ICON_TRSC_ORANGE_RED_TRG,
    ICON_TRSC_DOTTED_TRG,
    ICON_TRSC_TRAILER_TRG,
    ICON_TRSC_VEHICLE_TRG0,
    ICON_TRSC_VEHICLE_TRG1,
    ICON_TRSC_VEHICLE_TRG2,
    ICON_TRSC_TRAILER_RED_TRG,

    /* ...the order of PAS icons is important; do not change - tbd */
    ICON_PAS_TV_FC_INACTIVE,
    ICON_PAS_TV_FC_CLOSE,
    ICON_PAS_TV_FC_MIDDLE,
    ICON_PAS_TV_FC_FAR,
    ICON_PAS_TV_FC_MAX,

    ICON_PAS_TV_FR_INACTIVE,
    ICON_PAS_TV_FR_CLOSE,
    ICON_PAS_TV_FR_MIDDLE,
    ICON_PAS_TV_FR_FAR,
    ICON_PAS_TV_FR_MAX,

    ICON_PAS_TV_FL_INACTIVE,
    ICON_PAS_TV_FL_CLOSE,
    ICON_PAS_TV_FL_MIDDLE,
    ICON_PAS_TV_FL_FAR,
    ICON_PAS_TV_FL_MAX,

    ICON_PAS_TV_RC_INACTIVE,
    ICON_PAS_TV_RC_CLOSE,
    ICON_PAS_TV_RC_MIDDLE,
    ICON_PAS_TV_RC_FAR,
    ICON_PAS_TV_RC_MAX,

    ICON_PAS_TV_RR_INACTIVE,
    ICON_PAS_TV_RR_CLOSE,
    ICON_PAS_TV_RR_MIDDLE,
    ICON_PAS_TV_RR_FAR,
    ICON_PAS_TV_RR_MAX,

    ICON_PAS_TV_RL_INACTIVE,
    ICON_PAS_TV_RL_CLOSE,
    ICON_PAS_TV_RL_MIDDLE,
    ICON_PAS_TV_RL_FAR,
    ICON_PAS_TV_RL_MAX,

    /* ...the order of PAS icons is important; do not change - tbd */
    ICON_PAS_SV_FC_INACTIVE,
    ICON_PAS_SV_FC_CLOSE,
    ICON_PAS_SV_FC_MIDDLE,
    ICON_PAS_SV_FC_FAR,
    ICON_PAS_SV_FC_MAX,

    ICON_PAS_SV_FR_INACTIVE,
    ICON_PAS_SV_FR_CLOSE,
    ICON_PAS_SV_FR_MIDDLE,
    ICON_PAS_SV_FR_FAR,
    ICON_PAS_SV_FR_MAX,

    ICON_PAS_SV_FL_INACTIVE,
    ICON_PAS_SV_FL_CLOSE,
    ICON_PAS_SV_FL_MIDDLE,
    ICON_PAS_SV_FL_FAR,
    ICON_PAS_SV_FL_MAX,

    ICON_PAS_SV_RC_INACTIVE,
    ICON_PAS_SV_RC_CLOSE,
    ICON_PAS_SV_RC_MIDDLE,
    ICON_PAS_SV_RC_FAR,
    ICON_PAS_SV_RC_MAX,

    ICON_PAS_SV_RR_INACTIVE,
    ICON_PAS_SV_RR_CLOSE,
    ICON_PAS_SV_RR_MIDDLE,
    ICON_PAS_SV_RR_FAR,
    ICON_PAS_SV_RR_MAX,

    ICON_PAS_SV_RL_INACTIVE,
    ICON_PAS_SV_RL_CLOSE,
    ICON_PAS_SV_RL_MIDDLE,
    ICON_PAS_SV_RL_FAR,
    ICON_PAS_SV_RL_MAX,

    ICON_PAS_OFF,
    ICON_PAS_FAILURE,
    ICON_PAS_SONAR_FAILURE,

    /* ...cross-traffic alert icons (order is important) */
    ICON_CTA_DETECTION_DARK_LEFT,
    ICON_CTA_DETECTION_BRIGHT_LEFT,
    ICON_CTA_WARNING_DARK_LEFT,
    ICON_CTA_WARNING_BRIGHT_LEFT,

    ICON_CTA_DETECTION_DARK_RIGHT,
    ICON_CTA_DETECTION_BRIGHT_RIGHT,
    ICON_CTA_WARNING_DARK_RIGHT,
    ICON_CTA_WARNING_BRIGHT_RIGHT,

    /* ...aiming view icons */
    ICON_AIMING_ERROR,
    ICON_AIMING_EXECUTION,
    ICON_AIMING_INSPECTION,
    ICON_AIMING_FRONT,
    ICON_AIMING_REAR,
    ICON_AIMING_LEFT,
    ICON_AIMING_RIGHT,

    ICON_AIMING_STEERING,
    ICON_AIMING_SPEED,
    ICON_AIMING_STATUS_PROCESSING,
    ICON_AIMING_STATUS_PAUSE,
    ICON_AIMING_STATUS_FAILURE,
    ICON_AIMING_STATUS_SUCCESS,

    ICON_AIMING_MARKER_TV,

    ICON_AIM_ARROW_GREEN,
    ICON_AIM_ARROW_RED,
    ICON_AIM_ARROW_YELLOW,
    ICON_AIM_ARROW_GRAY,
    ICON_AIM_PLAY,
    ICON_AIM_PAUSE,
    ICON_AIM_FAILURE,
    ICON_AIM_SUCCESS,
    ICON_AIM_FRAME,
    ICON_AIM_PROGRESS_0,
    ICON_AIM_PROGRESS_25,
    ICON_AIM_PROGRESS_50,
    ICON_AIM_PROGRESS_75,
    ICON_AIM_PROGRESS_100,

    ICON_CTA_LEFT,
    ICON_CTA_RIGHT,

    /* ...UI buttons */
    ICON_UI_SV3D_ACTIVE,
    ICON_UI_SV3D,
    ICON_UI_TV_ACTIVE,
    ICON_UI_TV,
    ICON_UI_FRONT_ACTIVE,
    ICON_UI_FRONT,
    ICON_UI_REAR_ACTIVE,
    ICON_UI_REAR,
    ICON_UI_CT_ACTIVE,
    ICON_UI_CT,

    ICON_GL_FFC,
    ICON_TV_HATCHED,

    ICON_RESOURCE_MAX,
};

/**
 * @brief   Icon item configuration
 */
typedef struct cfg_icon_item
{
    /**> Item identifier */
    uint32_t            id;

    /**> Source tile in GL-coordinates: <0,0> - BL, <1,1> - UR */
    float32_t           src[4];

}   cfg_icon_item_t;

/**
 * @brief   Icon configuration
 */
typedef struct cfg_icon
{
    /**> Filename containing resources */
    char               *file;

    /**> Number of items stored in a file */
    uint32_t            number;

    /**> Array of items */
    cfg_icon_item_t    *item;

}   cfg_icon_t;

/**
 * @brief   Icons set
 */
typedef struct cfg_icons
{
    /**> Number of icon files */
    uint32_t        number;

    /**> Array of icon configurations */
    cfg_icon_t     *icon;

}   cfg_icons_t;

/**
 * @brief   Aiming error icons configuration
 */
typedef struct cfg_aiming_error
{
    /**> Top-view configuration icons destinations */
    int32_t         tv_dst[4][4];

    /**> Side-view configuration icons destinations */
    int32_t         sv_dst[4][4];

    /**> Sonar-view configuration icons destinations */
    int32_t         nc_dst[4][4];

    /**> Centric view configuration icon destination */
    int32_t         sc_dst[1][4];

}   cfg_aiming_error_t;

/**
 * @brief   Aiming view configuration
 */
typedef struct cfg_aim_view
{
    /**> Aiming name destination tile */
    int32_t             name_dst[4];

    /**> Aiming status destination tile */
    int32_t             status_dst[4];

    /**> Cameras progress bar title destination tiles */
    int32_t             camera_dst[4][4];

    /**> Cameras progress bar destination tiles */
    int32_t             progress_dst[4][4];

    /**> Speed condition destination tile */
    int32_t             speed_dst[4];

    /**> Steering condition destination tile */
    int32_t             steering_dst[4];

    /**> Cameras position centers coordinates */
    int32_t             camera_pos_center[4][2];

    /**> Car model destination tile */
    int32_t             car_model_dst[4];

}   cfg_aim_view_t;

/*******************************************************************************
 * Overlays configuration
 ******************************************************************************/

/**> Overlay types */
enum ovl_type
{
    OVL_GUIDE,
    OVL_ICON,
    OVL_CAR,
    OVL_ODO,
    OVL_NUMBER,
    OVL_HV,
};

/**
 * @brief   Guideline type
 */
enum guide_type
{
    GUIDE_FRONT = 0,
    GUIDE_REAR = 1,
    GUIDE_FRONT_WIDE = 2,
    GUIDE_REAR_WIDE = 3,
    GUIDE_TOP_FRONT = 4,
    GUIDE_TOP_REAR = 5,
    GUIDE_SV_LEFT = 6,
    GUIDE_SV_RIGHT = 7,
    GUIDE_STV_FRONT = 8,
    GUIDE_STV_REAR = 9,
    GUIDE_THA = 10,
    GUIDE_FFC = 11,
    GUIDE_HATCHED = 12
};

/**
 * @brief   Guidelines overlay
 */
typedef struct cfg_ovl_guide
{
    /**> Overlay type */
    uint32_t            type;

    /**> Guideline type */
    uint32_t            subtype;

    /**> Dynamic guidelines configuration */

}   cfg_ovl_guide_t;

/**> Icon overlay type code */
enum icon_overlay_id
{
    ICON_OVL_CAR_TV = 0,
    ICON_OVL_CAR_SV = 1,
    ICON_OVL_CTA_FRONT = 2,
    ICON_OVL_CTA_REAR = 3,
    ICON_OVL_CTA_SIDE = 4,
    ICON_OVL_AIMING = 5,
    ICON_OVL_AIMING_SIDE = 6,
    ICON_OVL_HITCH = 7,
    ICON_OVL_COUPLER = 8,
    ICON_OVL_TRSC_SVC = 9,
    ICON_OVL_TRSC_TRG_R1 = 10,
    ICON_OVL_TRSC_TRG_R2 = 11,
    ICON_OVL_TRSC_TRG_L1 = 12,
    ICON_OVL_TRSC_TRG_L2 = 13,
    ICON_OVL_TRSC_TRG_C = 14,
    ICON_OVL_BORDER = 15,
    ICON_PDT_SONAR = 16
};

/**
 * @brief   Icon overlay
 */
typedef struct cfg_ovl_icon
{
    /**> Overlay type */
    uint32_t            type;

    /**> Icon type */
    uint32_t            subtype;

    /**> Destination tile (optional) */
    int32_t             dst[4];

}   cfg_ovl_icon_t;

/**
 * @brief   Car model overlay
 */
typedef struct cfg_ovl_car
{
    /**> Overlay type */
    uint32_t            type;

    /**> Car model type */
    uint32_t            subtype;

}   cfg_ovl_car_t;

/**
 * @brief   ODO overlay
 */
typedef struct cfg_ovl_odo
{
    /**> Overlay type */
    uint32_t            type;

    /**> ODO type */
    uint32_t            subtype;

}   cfg_ovl_odo_t;

/**
 * @brief   CTA overlay
 */
typedef struct cfg_ovl_cta
{
    /**> Overlay type */
    uint32_t            type;

    /**> CTA type */
    uint32_t            subtype;

}   cfg_ovl_cta_t;

/**
 * @brief   Generic overlay configuration
 */
typedef union cfg_ovl
{
    /**> Overlay type */
    uint32_t            type;

    /**> Guidelines overlay */
    cfg_ovl_guide_t     guide;

    /**> Icon overlay */
    cfg_ovl_icon_t      icon;

    /**> Car model overlay */
    cfg_ovl_car_t       car;

    /**> CTA overlay */
    cfg_ovl_car_t       cta;

    /**> ODO overlay */
    cfg_ovl_odo_t       odo;

}   cfg_ovl_t;

/**
 * @brief   Hitch configuration
 */
typedef struct cfg_hitch
{
    /**> Slider position */
    int32_t             slider[4];

    /**> Start position */
    int32_t             start[4];

    /**> Stop position */
    int32_t             stop[4];

}   cfg_hitch_t;

/**
 * @brief   TRSC configuration
 */
typedef struct cfg_trsc
{
    /**> Pivot point coordinate, pxl */
    float32_t           pivot[2];

    /**> Arcs/glows tile */
    int32_t             base[4];

    /**> Dotted line tile */
    int32_t             dotted[4];

    /**> Trailer icon tile */
    int32_t             trailer[4];

    /**> Vehicle icon tile */
    int32_t             cl_vehicle[4];
    int32_t             q_vehicle[4];
    int32_t             cs_vehicle[4];

    /**> Offset for target position - R1/R2/L1/L2/C */
    int32_t             offset[5];

}   cfg_trsc_t;

/*******************************************************************************
 * View manager configuration
 ******************************************************************************/

/**
 * @brief   View-manager configuration
 */
typedef struct cfg_vm
{
    /**> Front-view mesh configuration */
    cfg_scv_mesh_t      front_view;

    /**> Front-wide-view mesh configuration */
    cfg_scv_mesh_t      front_wide_view;

    /**> Rear-view mesh configuration */
    cfg_scv_mesh_t      rear_view;

    /**> Rear-Sonar-view mesh configuration */
    cfg_scv_mesh_t      rear_sonar_view;

    /**> Rear-wide-view mesh configuration */
    cfg_scv_mesh_t      rear_wide_view;

    /**> Side-view mesh configuration */
    cfg_mcv_mesh_t      side_view;

    /**> Debug-view mesh configuration */
    cfg_mcv_mesh_t      debug_view;

    /**> Rear-centric-view mesh configuration */
    cfg_scv_mesh_t      rear_centric_view;

    /**> Front-see-through-view mesh configuration */
    cfg_stv_mesh_t      front_stv;

    /**> Rear-see-through-view mesh configuration */
    cfg_stv_mesh_t      rear_stv;

    /**> Front-top-view mesh configuration */
    cfg_tv_mesh_t       front_tv;

    /**> Rear-top-view mesh configuration */
    cfg_tv_mesh_t       rear_tv;

    /**> Sonar-view configuration for top-view */
    cfg_sonar_t         sonar_tv;

    /**> Sonar-view configuration for side-view */
    cfg_sonar_t         sonar_sv;

    /**> Sonar-view configuration for 1/2-camera sonar view */
    cfg_sonar_t         sonar_sc;

    /**> Sonar-view configuration for 2-camera "left" side-view */
    cfg_sonar_t         sonar_lc;

    /**> Sonar-view configuration for 1-camera "sonar" side-view */
    cfg_sonar_t         sonar_nc;

    /**> CTA-Front/Rear-Wide/Narrow views indicator configuration */
    cfg_cta_t           cta_main;

    /**> CTA-Side view indicator configuration */
    cfg_cta_t           cta_side;

    /**> CTA-Rear-Sonar view indicator configuration */
    cfg_cta_t           cta_sonar;

    /**> CTA-Centric view indicator configuration */
    cfg_cta_t           cta_centric;

    /**> Hitch overlay configuration */
    cfg_hitch_t         hitch;

    /**> TRSC overlay configuration for SVC mode */
    cfg_trsc_t          trsc_svc;

    /**> TRSC overlay configuration for TRG mode */
    cfg_trsc_t          trsc_trg;

    /**> Aiming error icons configuration */
    cfg_aiming_error_t  aiming_error;

    /**> Aiming view configuration */
    cfg_aim_view_t      aiming;

    /**> Fadeout sequence duration for views transition, ms */
    uint32_t            fadeout_duration;

    /**> Default screen layout */
    uint32_t            default_layout;

    /**> Enable animated transitions */
    uint32_t            enable_animation;

    /**> Output resolution, pixels */
    uint32_t            width, height;

    /**> Global scaling factor */
    float32_t           scale;

}   cfg_vm_t;

/**
 * @brief   World object position configuration
 */
typedef struct cfg_world_position
{
    /**> Origin identifier */
    int                 origin;

    /**> Position / rotation angle */
    float32_t           loc[6];

}   cfg_world_position_t;

/**
 * @brief   World object configuration
 */
typedef struct cfg_world_object
{
    /**> Model file */
    char                   *model;

    /**> Object positions array */
    cfg_world_position_t   *position;

    /**> Number of positions */
    uint32_t                number;

}   cfg_world_object_t;

/**
 * @brief   Objects array
 */
typedef struct cfg_world_pattern
{
    /**> Pattern identifier */
    char                   *id;

    /**> Objects array */
    cfg_world_object_t     *object;

    /**> Number of objects */
    uint32_t                number;

}   cfg_world_pattern_t;

/**
 * @brief   World generator configuration
 */
typedef struct cfg_world_gen
{
    /**> Patterns array */
    cfg_world_pattern_t    *pattern;

    /**> Car model objects */
    cfg_world_object_t     *car;

    /**> Total amount of patterns */
    uint32_t                number;

    /**> Car model rendering flag */
    uint32_t                car_enable;

    /**> Shading region width */
    float32_t               lens_shading_size;

    /**> Lend shading angle, degrees */
    float32_t               lens_shading_angle_deg;

    /**> Near-plane clipping distance, mm */
    float32_t               clipping_mm;

}   cfg_world_gen_t;

/*******************************************************************************
 * UI configuration
 ******************************************************************************/

/**
 * @brief   UI button item configuration
 */
typedef struct cfg_ui_button
{
    /**> Text identifier */
    char               *id;

    /**> Button file index */
    uint32_t            idx;

    /**> Source tile in GL-coordinates: <0,0> - BL, <1,1> - UR */
    float32_t*           src;

}   cfg_ui_button_t;

/**
 * @brief   UI button file configuration
 */
typedef struct cfg_ui_file
{
    /**> Button resources file */
    char               *file;

    /**> Number of items */
    uint32_t            number;

    /**> First button index in a global buttons array */
    uint32_t            idx;

    float32_t           scale;

}   cfg_ui_file_t;

/**
 * @brief   UI button location
 */
typedef struct cfg_ui_button_pos
{
    /**> Button identifier */
    uint32_t            id;

    /**> Destination tile */
    int32_t*            dst;

    /**> Next page id */
    int32_t             action;

    /**> Visibility flag */
    uint8_t             visible;

    /**> Target value */
    uint8_t             target;
    uint8_t             back;

}   cfg_ui_button_pos_t;

/**
 * @brief   UI page configuration
 */
typedef struct cfg_ui_page
{
    /**> Page identifier (must be first) */
    char                   *id;

    /**> Number of views */
    uint32_t                views_num;

    /**> Array of views */
    cfg_mesh_t            **views;

    /**> Number of overlay arrays */
    uint32_t                ovl_num;

    /**> Overlays arrays (null-terminated second dimension) */
    cfg_ovl_t            ***ovl;

    /**> Number of buttons */
    uint32_t                buttons_num;

    /**> Buttons array */
    cfg_ui_button_pos_t    *buttons;

}   cfg_ui_page_t;

/**
 * @brief   UI configuration
 */
typedef struct cfg_ui
{
    /**> Total number of UI buttons */
    uint32_t            buttons_num;

    /**> Array of UI buttons */
    cfg_ui_button_t    *buttons;

    /**> Total number of pages */
    uint32_t            pages_num;

    /**> Array of UI pages */
    cfg_ui_page_t      *pages;

    /**> Total number of button resource files */
    uint32_t            files_num;

    /**> Array of button resource file names */
    cfg_ui_file_t      *files;

    /**> Total views number */
    uint32_t            views_num;

    /**> Total number of overlays */
    uint32_t            ovl_num[OVL_NUMBER];

}   cfg_ui_t;

/**
 * @brief   Scene update parameters for touchscreen/mouse interface
 */
typedef struct cfg_scene_params
{
    /**> Zooming factor */
    float32_t               zoom_factor;

    /**> Zooming threshold */
    float32_t               zoom_threshold;

    /**> Minimal distance from viewing point at zooming */
    float32_t               zoom_min_length;

    /**> Maximal distance from viewing point at zooming */
    float32_t               zoom_max_length;

    /**> Panoramic movement along X-corrdinate velocity factor */
    float32_t               pan_velocity_x;

    /**> Panoramic movement along Y-corrdinate velocity factor */
    float32_t               pan_velocity_y;

    /**> Maximal distance of viewing point from center at paning */
    float32_t               pan_max_length;

    /**> Rotation yaw angle velocity factor */
    float32_t               rotate_velocity_yaw;

    /**> Rotation pitch angle velocity factor */
    float32_t               rotate_velocity_pitch;

    /**> Threshold for maximal pitch value */
    float32_t               rotate_pitch_max;

    /**> Threshold for minimal pitch value */
    float32_t               rotate_pitch_min;

    /**> Rotation threshold for pitch */
    float32_t               rotate_pitch_threshold;

    /**> Rotation threshold for yaw */
    float32_t               rotate_yaw_threshold;

}   cfg_scene_params_t;

/**
 * @brief   Configuration data
 */
typedef struct cfg_data
{
    /**> Total number of cameras supported */
    int                 cameras_number;

    /**> Individual cameras configurations */
    cfg_camera_t        camera[SV_CAMERAS_NUMBER];

    /**> Color correction configuration data */
    cfg_cc_t            cc;

    /**> Vehicle configuration data */
    cfg_vehicle_t       vehicle;

    /**> Icons configuration */
    cfg_icons_t         icons;

    /**> Cell-size for mesh creation - to-be-removed */
    int                 cell_size;

    /**> Car model configuration for see-through-view */
    cfg_model_t         car_model_stv;

    /**> Car model rendering configuration */
    cfg_car_render_t    car_render;

    /**> Guidelines configuration */
    cfg_guide_t         guide;

    /**> STV-PAS configuration */
    cfg_stv_pas_t       stv_pas;

    /**> Historical view configuration */
    cfg_bv_mesh_t       hv;

    /**> View-manager configuration */
    cfg_vm_t            vm;

    /**> UI configuration */
    cfg_ui_t            ui;

    /**> Scene movement parameters for mouse */
    cfg_scene_params_t  scene_params_mouse;

    /**> Scene movement parameters for touchscreen */
    cfg_scene_params_t  scene_params_touch;

    /**> World-generator configuration */
    cfg_world_gen_t     world_gen;

}   cfg_data_t;

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Parse configuration file
 *
 * @param   cfg[in]     Configuration data structure
 * @param   fname[in]   Configuration file name
 */
extern int config_parse(cfg_data_t *cfg, char *data, uint32_t sz);
extern int variant_config_parse(cfg_data_t *cfg, unsigned int variant_id, char *fname);
extern int cfg_overide_var_data(cfg_data_t *cfg);

/**
 * @brief   Convert Magna extrinsics to ISO
 *
 * @param   cfg[in]     Global configuration data
 * @param   k[in]       Camera index
 * @param   angle[in]   Rotation angles (Magna), radians
 * @param   pos[in]     Translation vector (Magna), mm
 */
extern void camera_set_magna_extrinsics(cfg_data_t *cfg, int k, float32_t *angle, float32_t *pos);

extern uint32_t cfg_get_body_length_variant(cfg_data_t *cfg);

extern int config_change_language_runtime(uint32_t num, char* file_name);
extern void config_set_languages_path(const char* path);

extern void cfg_get_vehModel_pos_rot(uint8_t variantId, uint8_t* posSelect, uint8_t* rotSelect);
extern void cfg_get_vehModel_gl(uint8_t variantId, uint8_t* glSelect);
extern void cfg_get_vehModel_hatchedZone(uint8_t variantId, uint8_t* h_glSelect);
extern void cfg_get_vehModel_blind_area(uint8_t variantId, uint8_t* blind_area);
#endif  /* __SV_CONFIG_H */
