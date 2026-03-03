/*******************************************************************************
 * vehicle-state.h
 *
 * Vehicle state
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

#ifndef __VEHICLE_STATE_H
#define __VEHICLE_STATE_H

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**
 * @brief   PAS subsystem state
 */
enum pas_status
{
    PAS_STATE_OFF = 0,
    PAS_STATE_ON = 1,
    PAS_STATE_ON_SILENT = 2,
    PAS_STATE_ON_INVISIBLE = 3,
    PAS_STATE_TMP_FAILURE_REAR_TRAILER = 12,
    PAS_STATE_TMP_FAILURE = 13,
    PAS_STATE_INIT = 14,
    PAS_STATE_FAILURE = 15,
};

/**
 * @brief   Sonar report value
 */
enum pas_area_info
{
    PAS_AREA_INFO_NO_DETECTION = 0,
    PAS_AREA_INFO_CLOSE_DISTANCE = 1,
    PAS_AREA_INFO_MIDDLE_DISTANCE = 2,
    PAS_AREA_INFO_FAR_DISTANCE = 3,
    PAS_AREA_INFO_MAX_DISTANCE = 4,
    PAS_AREA_INFO_FREEZING = 5,
    PAS_AREA_INFO_WIRE_BREAKING = 6,
    PAS_AREA_INFO_DETECTION = 7,
};

/**
 * @brief   Sonar area code
 */
enum pas_area
{
    PAS_AREA_FRONT_CENTER = 0,
    PAS_AREA_FRONT_CORNER_R = 1,
    PAS_AREA_FRONT_CORNER_L = 2,
    PAS_AREA_REAR_CENTER = 3,
    PAS_AREA_REAR_CORNER_R = 4,
    PAS_AREA_REAR_CORNER_L = 5,
    PAS_AREA_NUMBER = 6,
};

/**
 * @brief   Parking-Assistance-Sonar state
 */
typedef struct pas_state
{
    /**> PAS state */
    uint32_t        state;

    /**> Individual sonars states */
    uint32_t        sonar_state[PAS_AREA_NUMBER];

    /**> PAS area info */
    uint32_t        area_info[PAS_AREA_NUMBER];

    /**> Blinking ON-state for 2.5Hz counter */
    int             blink_25_on;

    /**> 2.5Hz heartbeat counter */
    uint32_t        counter_25;

    /**> Blinking ON-state for 5.0Hz counter */
    int             blink_50_on;

    /**> 5.0Hz heartbeat counter */
    uint32_t        counter_50;

}   pas_state_t;

/**
 * @brief   Cross-traffic alert detector data
 */
typedef struct cta_state
{
    /**> Detection state */
    uint8_t         target_lh, target_rh;

    /**> CTA status */
    uint8_t         a_state, b_state;

    /**> Detection/warning targets */
    uint8_t         a_target_lh, a_target_rh;
    uint8_t         b_target_lh, b_target_rh;

    /**> Animation chart counters, in us */
    uint32_t        counter_lh, counter_rh;

    /**> Animation sequence state */
    int             state_lh, state_rh;

}   cta_state_t;

/**> Number of detected objects */
#define ODO_OBJECTS_NUMBER      8

/**
 * @brief   Obstacle detection data
 */
typedef struct odo_state
{
    /**> Nearest points X-coordinate (TL) */
    float32_t       near_x[ODO_OBJECTS_NUMBER];

    /**> Nearest points Y-coordinate (BL) */
    float32_t       near_y[ODO_OBJECTS_NUMBER];

    /**> Left-edge points X-coordinate */
    float32_t       left_x[ODO_OBJECTS_NUMBER];

    /**> Left-edge points Y-coordinate */
    float32_t       left_y[ODO_OBJECTS_NUMBER];

    /**> Right-edge points X-coordinate */
    float32_t       right_x[ODO_OBJECTS_NUMBER];

    /**> Right-edge points Y-coordinate */
    float32_t       right_y[ODO_OBJECTS_NUMBER];

    /**> Object height estimation */
    float32_t       zt[ODO_OBJECTS_NUMBER];

    /**> Detection reliability */
    uint8_t         reli[ODO_OBJECTS_NUMBER];

}   odo_state_t;

/**
 * @brief   Aiming procedure name
 */
enum aiming_name
{
    AIMING_EXECUTION = 0,
    AIMING_INSPECTION = 1,
};

/**
 * @brief   Aiming procedure status
 */
enum aiming_status
{
    AIM_STATUS_INACTIVE = 0,
    AIM_STATUS_PROCESSING = 1,
    AIM_STATUS_PAUSE = 2,
    AIM_STATUS_SUCCESS = 3,
    AIM_STATUS_FAILURE = 4,
};

/**
 * @brief   Aiming procedure state
 */
typedef struct aiming_state
{
    /**> Aiming/inspection indication */
    int32_t             name;

    /**> Current status */
    int32_t             status;

    /**> Speed condition threshold */
    float32_t           max_speed_value;

    /**> Steering condition threshold */
    float32_t           max_steering_angle;

    /**> Camera individual aiming status */
    int32_t             camera_status[4];

    /**> Camera progress indication, percents */
    int32_t             camera_progress[4];

    /**> Pointers to the failng camera buffers */
    uint8_t            *camera_buffer[4];

    int32_t             inv_steering;
    int32_t             inv_speed;

    /**> Marker failure flags */
    uint8_t             failure;

}   aiming_state_t;

typedef enum ap_dynamic_slot_type_e
{
    CE_SLOT_NONE = 0,
    CE_SLOT_PARALLEL = 1,
    CE_SLOT_PERP = 2,
} ap_dynamic_slot_type;

#define AP_DYNAMIC_SLOTS_NUMBER 6

typedef struct ap_dynamic_slot
{
    uint32_t x;
    uint32_t y;
    ap_dynamic_slot_type type;
    int32_t active;
}   ap_dynamic_slot_t;

/**
 * @brief   Auto parking state
 */
typedef struct ap_state
{
    uint8_t AP_BackBtn;
    uint8_t AP_Disclaimer_Core;
    uint8_t AP_ExitBtn_Not_Selected;
    uint8_t AP_ExitBtn_Selected;
    uint8_t AP_Forward_LeftBtn_Not_Selected;
    uint8_t AP_Forward_LeftBtn_Selected;
    uint8_t AP_Forward_RightBtn_Not_Selected;
    uint8_t AP_Forward_RightBtn_Selected;
    uint8_t AP_FrontInBtn_Not_Avail;
    uint8_t AP_FrontInBtn_Not_Selected;
    uint8_t AP_FrontInBtn_Selected;
    uint8_t AP_Grey_Banner1;
    uint8_t AP_Grey_Banner2;
    uint8_t AP_HMI_Top_red;
    uint8_t AP_HMI_bottom_black;
    uint8_t AP_HMI_fullscreen;
    uint8_t AP_HMI_top_black;
    uint8_t AP_Para_Exit_Core;
    uint8_t AP_ParkBtn_Not_Selected;
    uint8_t AP_ParkBtn_Selected;
    uint8_t AP_ParkIn_Done;
    uint8_t AP_Parkout_Done;
    uint8_t AP_Perp_Left_Core;
    uint8_t AP_Perp_Right_Core;
    uint8_t AP_RearInBtn_Not_Avail;
    uint8_t AP_RearInBtn_Not_Selected;
    uint8_t AP_RearInBtn_Selected;
    uint8_t AP_Scan_Keep_Moving_Forward_Text;
    uint8_t AP_Scan_Reduce_Speed_Text;
    uint8_t AP_Scan_STOP_Text;
    uint8_t AP_Scan_Searching_Text;
    uint8_t AP_Scan_Select_Space_Text;
    uint8_t AP_Scan_Space_Found_Text;
    uint8_t AP_Scanning_Core;
    uint8_t AP_BG_Main;
    uint8_t AP_dynamic;
    uint8_t BackDoorOpen_Icon_b;
    uint8_t LeftDoorFrontClose_Icon_b;
    uint8_t LeftDoorFrontOpen_Icon_b;
    uint8_t LeftDoorRearClose_Icon_b;
    uint8_t LeftDoorRearOpen_Icon_b;
    uint8_t RightDoorFrontClose_Icon_b;
    uint8_t RightDoorFrontOpen_Icon_b;
    uint8_t RightDoorRearClose_Icon_b;
    uint8_t RightDoorRearOpen_Icon_b;

    uint8_t PDC_RearLeft_Red_b;
    uint8_t PDC_RearLeft_Yellow_b;
    uint8_t PDC_FrontRight_Red_b;
    uint8_t PDC_FrontRight_Yellow_b;
    uint8_t PDC_FrontCenter_Red_b;
    uint8_t PDC_FrontCenter_Yellow_b;
    uint8_t PDC_FrontLeft_Red_b;
    uint8_t PDC_FrontLeft_Yellow_b;
    uint8_t PDC_RearRight_Red_b;
    uint8_t PDC_RearRight_Yellow_b;
    uint8_t PDC_RearCenter_Red_b;
    uint8_t PDC_RearCenter_Yellow_b;

    ap_dynamic_slot_t ap_dynamic_slots[AP_DYNAMIC_SLOTS_NUMBER];
    uint32_t reserved;

} ap_state_t;

/**
 * @brief   Vehicle state
 */
typedef struct vehicle_state
{
    /**> Current steering angle, degrees */
    float32_t           steering;

    /**> Wheel angle, degrees */
    float32_t           wheel_angle;

    /**> Current speed, km/h */
    float32_t           speed;

    /**> Front guidelines enable flag */
    uint8_t             front_gl_enable;

    /**> Rear guidelines enable flag */
    uint8_t             rear_gl_enable;

    /**> FFC guidelines enable flag */
    uint8_t             ffc_gl_enable;

    /**> Disable dynamic guidelines because of failure */
    uint8_t             gl_disable;

    /**> THA guidelines enable flag */
    uint8_t             tha_gl_enable;

    /**> Wheels pulses count: FL/FR/RL/RR */
    uint16_t            wheel_pulse_count[4];

    /**> Wheel rotation state */
    uint8_t             wheel_state[4];

    /**> Doors status */
    uint8_t             door_state[5];

    /**> Mirrors status */
    uint8_t             mirror_state[4];

    /**> Label show flag */
    uint8_t             label_enable;

    /**> Exit-button show flag */
    uint8_t             exit_enable;

    /**> Check-surrounding label show flag */
    uint8_t             check_enable;

    /**> No-camera-available label show flag */
    uint8_t             no_camera_enable[4];

    /**> THA START button status */
    uint8_t             tha_start_enable;

    /**> THA CONFIRM button status */
    uint8_t             tha_confirm_enable;

    /**> THA message id */
    uint8_t             tha_message_id;

    /**> THA button id */
    uint8_t             tha_button;

    /**> TRG audo icon id */
    uint8_t             trg_auto;

    /**> THA progress bar overlay enable status */
    uint8_t             tha_progress_enable;

    /**> THA progress bar */
    uint8_t             tha_progress_bar;

    /**> Coupler target enable */
    uint8_t             tha_coupler_enable;

    /**> Coupler target position, pixels */
    int32_t             tha_coupler_pos[2];

    /**> TRSC jack-knife angle, signed percents */
    int8_t              trsc_jk_angle_pct;

    /**> TRSC TAD angle, signed percents */
    int8_t              trsc_tad_angle_pct;

    /**> TRSC jack-knife graphics orange region enable flag */
    uint8_t             trsc_orange_enable;

    /**> TRSC jack-knife graphics red region enable flag */
    uint8_t             trsc_red_enable;

    /**> TRSC jack-knofe graphics enable flag */
    uint8_t             trsc_enable;

    float32_t           trsc_angle0;
    float32_t           trsc_angle1;
    uint8_t             trsc_red_trailer;

    /**> Vehicle pose in historical buffer */
    float32_t           pose[2 * 3];

    /**> PAS state */
    pas_state_t         pas;

    /**> Front CTA state */
    cta_state_t         cta;

    /**> Rear CTA state */
    cta_state_t         rcta;

    /**> Object-detection state */
    odo_state_t         odo;

    /**> Aiming procedure state */
    aiming_state_t      aiming;

    /**> Auto parking state */
    ap_state_t          ap;

    uint8_t zoom_icon;
    uint8_t more_icon;
    uint8_t more_icon_text;
    uint8_t bottombutton_tvfv;
    uint8_t bottombutton_tvrv;
    uint8_t bottombutton_rcpv;
    uint8_t bottombutton_fcpv;
    uint8_t bottombutton_burv;
    uint8_t bottombutton_ffcv;
    uint8_t bottombutton_aux;

    /**> To view unavailable calib erro flag */
    uint8_t             calib_error;

    /**> Heartbeat counter increment */
    uint32_t            delta;

    float32_t           mouse_zoom_x;
    float32_t           mouse_zoom_y;

}   vehicle_state_t;

#endif  /* __VEHICLE_STATE_H */
