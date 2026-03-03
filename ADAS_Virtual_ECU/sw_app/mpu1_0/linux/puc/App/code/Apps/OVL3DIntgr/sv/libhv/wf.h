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
 *  @file           vp1_wheels_filter.h
 *  @brief          Wheels filter for ego-motion algorithm
 *
 *  @version        1.00
 *  @author         Alex Orlov & Pavel Gaenko
 *  @date           01.09.2019
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

#ifndef WHEELS_FILTER_H
#define WHEELS_FILTER_H

//#include "vp1_internal_types.h"

typedef struct
{
    float x;
    float y;
    float width;
    float height;
} rect_float_t;


#include "vp1_math_types.h"
#include "vp1_common_math_utils.h"
#include "vp1_ackermann_model.h"


typedef struct matx88d_t {
    float64_t elem[64];
} matx88d_t;

typedef struct matx81d_t {
    float64_t elem[8];
} matx81d_t;

typedef matx81d_t vec8d_t;

struct _Wheel4Filter;
typedef struct _Wheel4Filter Wheel4Filter;

extern Wheel4Filter Wheel4Filter_create(float32_t sigmaVel, 
    uint64_t beginTime, float32_t timeFract, float32_t ticksPerMeter, 
    float32_t wheelBase, float32_t rearLRBase, float32_t forwardLRBase,
    float32_t def_speed, float32_t delta_thr);

extern void Wheel4Filter_update_pulse_per_meter(Wheel4Filter* self, float32_t ticksPerMeter);

extern void Wheel4Filter_reset(Wheel4Filter * wfilter, uint64_t resetTime);

extern vec2f_t Wheel4Filter_getPosition(const Wheel4Filter* self);
extern mat33f_t Wheel4Filter_getAffineTr(const Wheel4Filter* self);

extern void Wheel4Filter_clone(void);
extern void Wheel4Filter_recovery(int32_t mov);

extern void Wheel4Filter_add_pulse_wheel_message(Wheel4Filter* self, uint16_t FL, uint16_t FR, uint16_t RL, uint16_t RR, uint64_t ts);
extern void Wheel4Filter_add_pulse_wheel_message_forward(Wheel4Filter* self, uint16_t FL, uint16_t FR, uint64_t ts);
extern void Wheel4Filter_add_pulse_wheel_message_rear(Wheel4Filter* self, uint16_t RL, uint16_t RR, uint64_t ts);
extern void Wheel4Filter_add_steering_wheel_message(Wheel4Filter* self, float32_t angle, uint64_t ts);

extern int8_t Wheel4Filter_getMovDir(const Wheel4Filter* self);
extern float32_t Wheel4Filter_getVelocity(const Wheel4Filter* self);
extern void Wheel4Filter_setMovDir(Wheel4Filter* self, uint8_t gear);
extern void Wheel4Filter_setGear(Wheel4Filter* self, uint8_t gear);


enum Wheels
{
    WHEELS_FRONT = 0,
    WHEELS_FL    = 0,
    WHEELS_FR    = 1,
    WHEELS_REAR  = 2,
    WHEELS_RL    = 2,
    WHEELS_RR    = 3,
    WHEELS_MAX   = 4,
};

enum MovementDirection
{
    MOV_DIR_UNKNOWWN = 0,
    MOV_DIR_FORWARD = 1,
    MOV_DIR_BACKWARD = 2
};

typedef struct _Wheel4Filter 
{
    AckermannModel      model;
    matx81d_t            state;
    matx88d_t            cov;
    float32_t           sigmaVel;
    float32_t           timeFract;
    float32_t           ticksPerMeter;
    uint64_t            lastTimeStamp;
    float32_t           steeringAngle; ///! is used as front wheel angle
    float32_t           steeringRotation;
    uint64_t            rearTs;
    uint64_t            fwdTs;
    uint64_t            delta;
    float32_t           lastStateWheel[WHEELS_MAX];
    float32_t           lastBias[WHEELS_MAX];
    float32_t           wheel_rotation_angle[WHEELS_MAX];
    float32_t           speed;
    float32_t           steeringRatio;
    WheelMessage        last[WHEELS_MAX];
    int8_t              movement_direction;
    int8_t              gear;
    int16_t             ticks[WHEELS_MAX];
    float32_t           delta_thr;
    
} Wheel4Filter;

extern Wheel4Filter wheels_filter;

#endif //WHEELS_FILTER_H
