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
 *  @file           vp1_wheels_filter.c
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

#define MODULE_TAG                      WF

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "wf.h"

#if 0
#include <ctype.h> /* Header file for isdigit */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>
#include <float.h>
#include <arpa/inet.h> // @todo: implement ntohs
#include <limits.h>

#include "vp1_common.h"
#include "vp1_can.h"
#include "vp1_defaults.h"
#include "vp1_common_math_utils.h"
#include "vp1_aux.h"
#endif

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 5);

#define STABLE_TICKS_NUMBER 12U
#define PULS_CNT_MASK 16383U

//extern vp1evo_hv_config_t vp1evo_hv_config_default;
//extern vp1evo_car_parameters_t vp1evo_car_parameters_defaults;

static pthread_mutex_t intern_wf_mutex = PTHREAD_MUTEX_INITIALIZER;

static inline void mat_88_eye(float64_t m[64])
{
    for (uint8_t i = 0; i < 64U; i += 1U)
    {
        m[i] = 0.f;
    }
        

    for (uint8_t i = 0; i < 8U; i += 1U)
    {
        m[i*8 + i] = 1.f;
    }
}

static inline void mat_88_set_value(float64_t m[64], float64_t value)
{
    for (uint8_t i = 0; i < 64U; i += 1U)
    {
        m[i] = value;
    }
}

static inline void mat_88_zero(float64_t m[64])
{
    for (uint8_t i=0; i < 64U; i += 1U)
    {
        m[i] = 0.;
    }
}

static inline float64_t mat_dot_prod(const float64_t * a, const float64_t * b, const size_t size)
{
    float64_t res = 0.; 
    for (size_t i = 0; i < size; i += 1U)
    {
        res += a[i] * b[i];
    }
    return res;
}

static inline matx88d_t mtx_88_eye(void)
{
    matx88d_t out;
    mat_88_eye(&(out.elem[0]));
    return out;
}

static inline matx88d_t mtx_88_value(float64_t value)
{
    matx88d_t out;
    mat_88_set_value(&(out.elem[0]), value);
    return out;
}

static inline matx88d_t mtx_88_zero(void)
{
    matx88d_t out;
    mat_88_zero(&(out.elem[0]));
    return out;
}

static inline vec8d_t vec8_zero(void)
{
    vec8d_t out;
    for (uint8_t i = 0; i < 8U; i += 1U)
    {
        out.elem[i] = 0;
    }
    return out;
}

static inline vec8d_t vec8_value(float64_t value){
    vec8d_t out;
    for (uint8_t i = 0; i < 8U; i += 1U)
    {
        out.elem[i] = value;
    }
    return out;
}

static inline void mat_mul_88(const float64_t a[64], const float64_t b[64], float64_t c[64])
{
    for (uint8_t row = 0; row < 8U; row += 1U)
    {
        for (uint8_t col = 0; col < 8U; col += 1U)
        {   
            c[row * 8U+ col] = 0;
            for (uint8_t k = 0; k < 8U; k += 1U)
            {
                c[row * 8U + col] += a[row * 8U +  k] * b[k * 8U +  col];
            }
        }
    }
}


static inline void mat_mul_81(const float64_t a[64], const float64_t b[8], float64_t c[8])
{
    for (uint8_t row = 0; row < 8U; row += 1U)
    {   
        c[row] = 0;
        for (uint8_t k = 0; k < 8U; k += 1U)
        {
            c[row] += a[row * 8U + k] * b[k];
        }
    }
}

static inline void mat_mul_118(const float64_t a[8], const float64_t b[8], float64_t c[64])
{
    for (uint8_t row = 0; row < 8U; row += 1U)
    {
        for (uint8_t col = 0; col < 8U; col += 1U)
        {
            c[row * 8U + col] = a[row]*b[col];
        }
    }
}

static inline void mat_tr_8(const float64_t a[64], float64_t b[64])
{
    for (uint8_t row = 0; row < 8U; row += 1U)
    {
        for (uint8_t col = 0; col < 8U; col += 1U)
        {
            b[row * 8U + col] = a[col * 8U + row];
        }
    }
}

static inline void max_mul_8sc(const float64_t a[64], const float64_t value, float64_t b[64])
{
    for (uint8_t i = 0; i < 64U; i += 1U)
    {
        b[i] = a[i] * value;
    }
}

static inline void mat_mul_88_x3(const float64_t a[64], const float64_t b[64], const float64_t c[64], float64_t d[64])
{
    float64_t tmp[64];
    mat_mul_88(&(a[0]), &(b[0]), &(tmp[0]));
    mat_mul_88(&(tmp[0]), &(c[0]), &(d[0]));
}

static inline void mat_sum_88(const float64_t a[64], const float64_t b[64], float64_t c[64])
{
    for (uint8_t i = 0; i < 64U; i += 1U)
    {
        c[i] = a[i] + b[i];
    }
}

static inline void mat_sub_88(const float64_t a[64], const float64_t b[64], float64_t c[64])
{
    for (uint8_t i = 0; i < 64U; i += 1U)
    {
        c[i] = a[i] - b[i];
    }   
}

static inline matx88d_t mtx_mul_88(const matx88d_t * a, const matx88d_t * b)
{ 
    matx88d_t out; 
    mat_mul_88(&(a->elem[0]), &(b->elem[0]), &(out.elem[0]));
    return out; 
}

static inline matx88d_t mtx_mul_88_x3(const matx88d_t * a, const matx88d_t * b, const matx88d_t * c)
{ 
    matx88d_t out; 
    mat_mul_88_x3(&(a->elem[0]), &(b->elem[0]), &(c->elem[0]), &(out.elem[0]));
    return out; 
}

static inline matx88d_t mtx_sum_88(const matx88d_t * a, const matx88d_t * b)
{ 
    matx88d_t out; 
    mat_sum_88(&(a->elem[0]), &(b->elem[0]), &(out.elem[0]));
    return out; 
}

static inline vec8d_t mtx_vec_sum_8(const vec8d_t * a, const vec8d_t * b)
{ 
    vec8d_t out; 
    for (uint8_t i = 0; i < 8U; i += 1U)
    {
        out.elem[i] = a->elem[i] + b->elem[i];
    }
    return out; 
}

static inline vec8d_t mtx_81_zero(void)
{
    vec8d_t out; 
    for (uint8_t i = 0; i < 8U; i += 1U)
    {
        out.elem[i] = 0;
    }

    return out; 
}



static inline matx88d_t mtx_sub_88(const matx88d_t * a, const matx88d_t * b)
{ 
    matx88d_t out; 
    mat_sub_88(&(a->elem[0]), &(b->elem[0]), &(out.elem[0]));
    return out; 
}

static inline matx88d_t mtx_mul_8sc(const matx88d_t * a, const float64_t value)
{ 
    matx88d_t out; 
    max_mul_8sc(&(a->elem[0]), value, &(out.elem[0]));
    return out; 
}

static inline vec8d_t mtx_vec_mul_8sc(const vec8d_t * a, const float64_t value)
{ 
    vec8d_t out; 
    for (uint8_t i = 0; i < 8U; i += 1U)
    {
        out.elem[i] = a->elem[i] * value;
    }
    return out; 
}

static inline matx88d_t mtx_mul_118(const vec8d_t * a, const vec8d_t * b)
{ 
    matx88d_t out; 
    mat_mul_118(&(a->elem[0]), &(b->elem[0]), &(out.elem[0]));
    return out; 
}

static inline vec8d_t mtx_mul_811(const matx88d_t * a, const vec8d_t * b)
{ 
    vec8d_t out; 
    mat_mul_81(&(a->elem[0]), &(b->elem[0]), &(out.elem[0]));
    return out; 
}

static inline vec8d_t mtx_sum_8_vec(const vec8d_t * a, const vec8d_t * b)
{ 
    vec8d_t out; 
    for (uint8_t i = 0; i < 8U; i += 1U)
    {
        out.elem[i] = a->elem[i] + b->elem[i];
    }
    return out; 
}


static inline float64_t mtx_scal_8(const vec8d_t * a, const vec8d_t * b)
{ 
    float64_t res = mat_dot_prod(&(a->elem[0]), &(b->elem[0]), 8U);
    return res;
}

static inline void mtx_88_block_set(matx88d_t * a, size_t block_rows, size_t block_cols, size_t row, size_t col, float64_t value)
{
    for (uint8_t r = row; r < row + block_rows; r += 1U)
    {
        for (uint8_t c = col; c < col + block_cols; c += 1U)
        {
            a->elem[r * 8U + c] = value;
        }
    }
}

static inline matx88d_t mtx_tr_8(const matx88d_t * m)
{
    matx88d_t out;
    for (uint8_t row = 0; row < 8U; row += 1U)
    {
        for (uint8_t col = 0; col < 8U; col += 1U)
        {
            out.elem[row * 8U + col] = m->elem[col * 8U + row];
        }
    }
        
    return out;
}

Wheel4Filter wheels_filter;
Wheel4Filter wheels_clone_filter_f;
Wheel4Filter wheels_clone_filter_b;

static uint32_t unknown_dir = 0;

static inline float32_t Wheel4Filter_steering_wheel_degree(const uint8_t *p);
static inline void Wheel4Filter_propogate(Wheel4Filter* self, double tau);
static inline void Wheel4Filter_propogateUntil(Wheel4Filter* self, uint64_t timeStamp);

static void Wheel4Filter_apply_measure(Wheel4Filter* self, float32_t poz_wheel,
    float32_t sigmaIn, int16_t wheel);

static void Wheel4Filter_add_measure(Wheel4Filter* self, const WheelMessage* mes,
    uint8_t wheel, WheelMessage* lastMesure);

static void Wheel4Filter_add_rear(Wheel4Filter* self, WheelMessage left, WheelMessage right);
static void Wheel4Filter_add_fwd(Wheel4Filter* self, WheelMessage left, WheelMessage right);

static void Wheel4Filter_add_raw_message_psa(Wheel4Filter* self, uint32_t can_id,
    const uint8_t *msg, uint64_t ts);

static const int WHEELS_USE = 4U;
static const int STATE_SIZE = 8U; //4 + WHEELS_USE;

Wheel4Filter Wheel4Filter_create(
    float32_t sigmaVel, uint64_t beginTime, float32_t timeFract, float32_t ticksPerMeter,
    float32_t wheelBase, float32_t rearLRBase, float32_t forwardLRBase,
    float32_t def_speed, float32_t delta_thr)
{
    pthread_mutex_lock(&intern_wf_mutex);
    Wheel4Filter out = { 0 };

    out.gear = MOV_DIR_FORWARD;
    out.model = AckermannModel_create(wheelBase, rearLRBase, forwardLRBase);
    out.steeringAngle = 0.f;
    out.fwdTs = 0;
    out.delta = 0.f;
    out.state = mtx_81_zero();
    out.state.elem[WHEELS_USE] = def_speed;
    out.cov = mtx_88_eye();
    out.cov = mtx_mul_8sc(&(out.cov), 0.25f);
    out.cov.elem[WHEELS_USE * STATE_SIZE + WHEELS_USE] = 5.f * 5.f;
    out.cov.elem[(STATE_SIZE - 1) * STATE_SIZE + (STATE_SIZE - 1)] = 1e-8f;
    out.last[0] = WheelMessage_createDefault();
    out.last[1] = WheelMessage_createDefault();
    out.last[2] = WheelMessage_createDefault();
    out.last[3] = WheelMessage_createDefault();
    
#ifdef __INTEGRITY
    out.lastTimeStamp = get_timestamp();
#else
#ifdef TEST_SM
    out.lastTimeStamp = get_timestamp();
#else
    out.lastTimeStamp = beginTime;
#endif
#endif
    out.sigmaVel = sigmaVel;
    out.ticksPerMeter = ticksPerMeter;
    out.timeFract = timeFract;
    out.delta_thr = delta_thr;
    
    TRACE(INFO, _b("Wheel4Filter_create entry"));
    TRACE(INFO, _b("wfilter start %d"), (int)out.lastTimeStamp);

    pthread_mutex_unlock(&intern_wf_mutex);
    return out;
}

void Wheel4Filter_update_pulse_per_meter(Wheel4Filter* self, float32_t ticksPerMeter)
{
    TRACE(INFO, _b("Wheel4Filter_update_pulse_per_meter %f"), ticksPerMeter);
    self->ticksPerMeter = ticksPerMeter;
    return;
}

void Wheel4Filter_reset(Wheel4Filter * wfilter, uint64_t resetTime)
{
    TRACE(INFO, _b("Wheel4Filter_reset entry"));
    pthread_mutex_lock(&intern_wf_mutex);
    // wfilter->steeringAngle = 0.f;
    wfilter->fwdTs = 0;
    wfilter->delta = 0;
    wfilter->state = mtx_81_zero();
    //wfilter->state.elem[WHEELS_USE] = def_speed;
    wfilter->cov = mtx_88_eye();
    wfilter->cov = mtx_mul_8sc(&(wfilter->cov), 0.25f);
    wfilter->cov.elem[WHEELS_USE * STATE_SIZE + WHEELS_USE] = 5.f * 5.f;
    wfilter->cov.elem[(STATE_SIZE - 1) * STATE_SIZE + (STATE_SIZE - 1)] = 1e-8;
    wfilter->last[0] = WheelMessage_createDefault();
    wfilter->last[1] = WheelMessage_createDefault();
    wfilter->last[2] = WheelMessage_createDefault();
    wfilter->last[3] = WheelMessage_createDefault();
#ifndef __INTEGRITY
#ifdef TEST_SM
    wfilter->lastTimeStamp = get_timestamp();
#else
    wfilter->lastTimeStamp = resetTime;
#endif
    
#else
    wfilter->lastTimeStamp = get_timestamp();
#endif

    pthread_mutex_unlock(&intern_wf_mutex);
    Wheel4Filter_clone();

    TRACE(INFO, _b("wfilter resetTime %ld"), resetTime);
}

vec2f_t Wheel4Filter_getPosition(const Wheel4Filter* self)
{
    vec2f_t out;
    float32_t iscaler = 1.f / self->ticksPerMeter;
    pthread_mutex_lock(&intern_wf_mutex);
    out.x = self->state.elem[STATE_SIZE - 3] * iscaler;
    out.y = self->state.elem[STATE_SIZE - 2] * iscaler;
    pthread_mutex_unlock(&intern_wf_mutex);
    return out;
}

mat33f_t Wheel4Filter_getAffineTr(const Wheel4Filter* self)
{
    float32_t alphaPos = (float32_t)(self->state.elem[STATE_SIZE - 1]);

    mat33f_t res;
    mat33f_rot_z(&res, -alphaPos);
    vec2f_t pz = Wheel4Filter_getPosition(self);
    res.elem[0][2] = pz.x;
    res.elem[1][2] = pz.y;

    mat33f_t m2pix = eye33_f();
    m2pix.elem[2][2] = 1.0;
    res = mul_mat33(&res, &m2pix);

    return res;
}

int8_t Wheel4Filter_getMovDir(const Wheel4Filter* self)
{
    if (MOV_DIR_UNKNOWWN == self->movement_direction)
    {
        return self->gear;
    }
    else
    {
        return self->movement_direction;
    }
}

float32_t Wheel4Filter_getVelocity(const Wheel4Filter* self)
{
    return self->state.elem[4];
}

void Wheel4Filter_setMovDir(Wheel4Filter* self, uint8_t movement_direction)
{
    TRACE(DEBUG, _b("Wheel4Filter_setMovDir %d"), movement_direction);

    pthread_mutex_lock(&intern_wf_mutex);
    if (movement_direction != MOV_DIR_UNKNOWWN && unknown_dir != 0U)
    {
        TRACE(INFO, _b("Filter recovery to new dir %d"), movement_direction);
        Wheel4Filter_recovery(movement_direction);
        unknown_dir = 0;
    }

    self->movement_direction = movement_direction;
    pthread_mutex_unlock(&intern_wf_mutex);
}

void Wheel4Filter_setGear(Wheel4Filter* self, uint8_t gear)
{
    TRACE(INFO, _b("Wheel4Filter_setGear %d"), gear);
    pthread_mutex_lock(&intern_wf_mutex);
    self->gear = gear;
    pthread_mutex_unlock(&intern_wf_mutex);
}


static void Wheel4Filter_propogate(Wheel4Filter* self, double tau)
{   
    matx88d_t F  = mtx_88_eye();
    float32_t velocity = self->state.elem[WHEELS_USE];
    vec8d_t error = vec8_zero();

    float32_t ratios[4];
    AckermannModel_getRatios(&(self->model), self->steeringAngle, &(ratios[0]));

    for (uint8_t i = 0; i < WHEELS_USE; i += 1U)
    {
        error.elem[i] = 1.f/ratios[i] * tau;
        F.elem[i*8 + i] = 1.;
        F.elem[i*8 + WHEELS_USE] = 1.f / ratios[i] * tau;
    }
    error.elem[WHEELS_USE] = 1.;    

    float32_t radius_meter = AckermannModel_getRadius(&(self->model), self->steeringAngle, POS_REAR_CENTER); 
    float32_t radius_cnt = radius_meter * self->ticksPerMeter;
    float32_t angle_omega_rat = (radius_cnt > 0.) ? (tau / radius_cnt) : 0.;

    angle_omega_rat = (self->steeringAngle >= 0) ? -angle_omega_rat : angle_omega_rat;

    // half angle movement
    float32_t alphaBase = self->state.elem[STATE_SIZE - 1] + angle_omega_rat * velocity * 0.5;
    float32_t sinAlpa = sinf(alphaBase);
    float32_t cosAlpa = cosf(alphaBase);
        
    // X,Y posiztions    
    error.elem[WHEELS_USE + 1] = sinAlpa * tau;
    error.elem[WHEELS_USE + 2] = cosAlpa * tau;
    F.elem[(WHEELS_USE + 1) * 8 + WHEELS_USE] = sinAlpa * tau;
    F.elem[(WHEELS_USE + 2) * 8 + WHEELS_USE] = cosAlpa * tau;
        
    F.elem[(WHEELS_USE + 3) * 8 + WHEELS_USE] = angle_omega_rat;
    error.elem[WHEELS_USE + 3] = angle_omega_rat;

    float32_t sigmaRoot = sqrtf(self->sigmaVel);
    float32_t sigma = fmaxf(fminf(sigmaRoot, self->state.elem[WHEELS_USE]), 0.01);

    matx88d_t ncov = mtx_mul_118(&error, &error);
    ncov = mtx_mul_8sc(&ncov, sigma * sigma);
    self->state = mtx_mul_811( &F , &(self->state));

    // add process noise there
    
    matx88d_t propState = mtx_tr_8(&F);
    propState = mtx_mul_88(&(self->cov), &propState);
    propState = mtx_mul_88(&F, &propState);

    // add dempfer pars
    for (uint8_t i = 0; i < WHEELS_USE; i += 1U)
    {
        float32_t noise = fmaxf(0.002, 0.01 * self->state.elem[WHEELS_USE]); // @todo 0.002 ?
        ncov.elem[i * 8U + i] += noise*noise;
    }
    self->cov = mtx_sum_88(&propState , &ncov);
}

static void Wheel4Filter_propogateUntil(Wheel4Filter* self, uint64_t timeStamp)
{
    TRACE(DEBUG, _b("Wheel4Filter_propogateUntil ts %ld"), timeStamp);
    uint64_t deltaT = 0;
    if (timeStamp > self->lastTimeStamp)
    {
        deltaT = timeStamp - self->lastTimeStamp;
    }
    if (deltaT > 0)
    {
        double tau = (double)deltaT / (double)self->timeFract; // self->timeFract ms == 1. in our time scale
        Wheel4Filter_propogate(self, tau);
        self->lastTimeStamp = timeStamp;
    }
}

static void Wheel4Filter_apply_measure(Wheel4Filter* self,  float32_t poz_wheel, float32_t sigmaIn, int16_t wheel)
{
    float32_t error = poz_wheel - self->state.elem[wheel];
    vec8d_t H = vec8_zero();
    H.elem[wheel] = 1.;
    vec8d_t cov_x_H = mtx_mul_811(&(self->cov), &H);
    float32_t invS = 1.f / (sigmaIn + mtx_scal_8(&H, &cov_x_H));
    vec8d_t KGain = mtx_mul_811(&(self->cov), &H);
    KGain = mtx_vec_mul_8sc(&KGain, invS);
    vec8d_t adder_state = mtx_vec_mul_8sc(&KGain, error);

    self->state = mtx_vec_sum_8(&(self->state), &adder_state);
    matx88d_t KGain_x_H = mtx_mul_118(&KGain , &H);
    matx88d_t IKH = mtx_88_eye();
    IKH = mtx_sub_88(&IKH , &KGain_x_H); 
    matx88d_t adder = mtx_mul_118(&KGain, &KGain);
    adder = mtx_mul_8sc(&adder, sigmaIn);
    matx88d_t IKH_T = mtx_tr_8(&IKH);
    self->cov = mtx_mul_88_x3(&IKH, &(self->cov), &IKH_T);
}

static void Wheel4Filter_add_measure(Wheel4Filter * self, const WheelMessage * mes, uint8_t wheel, WheelMessage * lastMesure)
{
    TRACE(DEBUG, _b("Wheel4Filter_add_measure wheel %d, new mess: ts %ld, cnt %d,  prev mess: ts %ld cnt %d"), 
          wheel, mes->timeStamp,  mes->cnt,
          lastMesure->timeStamp,  lastMesure->cnt);

    const uint32_t wheel_pulse_count_mask = PULS_CNT_MASK;
    int32_t movement_direction = Wheel4Filter_getMovDir(self);

    if ( wheel < WHEELS_USE )
    {
        float32_t deltaTau = (mes->timeStamp - lastMesure->timeStamp) / self->timeFract;
        if (mes->cnt != lastMesure->cnt)
        {
            float32_t poz_wheel = mes->cnt - lastMesure->cnt;
            if (poz_wheel < 0)
            {
                if (mes->cnt < 10 && lastMesure->cnt > wheel_pulse_count_mask - 10)
                    // max wheel pulse count = wheel_pulse_count_mask + 1 (for ex: max 128, mask 0b111111)
                    poz_wheel += wheel_pulse_count_mask + 1;
                else
                    poz_wheel = 0;
            }
            
            poz_wheel = (movement_direction != MOV_DIR_BACKWARD) ? poz_wheel : -poz_wheel;
            float32_t bias = fminf(self->state.elem[WHEELS_USE], 1.) * 0.5;
            bias = (movement_direction != MOV_DIR_BACKWARD) ?  bias : -bias;
            self->lastBias[wheel] = bias;
            self->lastStateWheel[wheel] += poz_wheel;
            float32_t sigmaIn = 1. /(12. * deltaTau * deltaTau);
            Wheel4Filter_apply_measure(self, self->lastStateWheel[wheel] + bias, sigmaIn, wheel );
            *lastMesure = *mes;
        }
        else
        {
            float32_t delta = fabs( self->state.elem[wheel] - (self->lastStateWheel[wheel] + self->lastBias[wheel]));
            if ( (delta > self->delta_thr) )
            {
                float32_t bias = (movement_direction != MOV_DIR_BACKWARD) ? 0.5 : -0.5;
                float32_t sigmaIn = 0.25f   ;
                Wheel4Filter_apply_measure(self, self->lastStateWheel[wheel] + bias, sigmaIn, wheel);
                *lastMesure = *mes;
            }
        }    
    }
}

static void Wheel4Filter_add_rear(Wheel4Filter* self, WheelMessage left, WheelMessage right)
{
    TRACE(DEBUG, _b("Wheel4Filter_add_rear [RL ts %ld cnt %d]   [RR ts %ld cnt %d]"), 
                     left.timeStamp, left.cnt, right.timeStamp, right.cnt);

    if (self->last[0].timeStamp == 0)
    {
        self->last[0] = left;
        self->last[1] = right;
        self->lastStateWheel[0] = 0.f;
        self->lastStateWheel[1] = 0.f;
        self->lastBias[0] = 0.f;
        self->lastBias[1] = 0.f;
        self->state.elem[0] = 0.f;
        self->state.elem[1] = 0.f;
    } else 
    {
        Wheel4Filter_propogateUntil(self, left.timeStamp );
        static bool leftFirst = true;
        if (leftFirst)
        {
           Wheel4Filter_add_measure(self, &left, 0,  &self->last[0]);
           Wheel4Filter_add_measure(self, &right, 1, &self->last[1]);
        }
        else
        {
           Wheel4Filter_add_measure(self, &right, 1, &self->last[1]);
           Wheel4Filter_add_measure(self, &left, 0,  &self->last[0]);
        }
        leftFirst = !leftFirst;
    }
}

static void Wheel4Filter_add_fwd(Wheel4Filter* self, WheelMessage left, WheelMessage right)
{
    TRACE(DEBUG, _b("Wheel4Filter_add_fwd [FL ts %ld cnt %d]   [FR ts %ld cnt %d]"), 
                     left.timeStamp, left.cnt, right.timeStamp, right.cnt);

    if (self->last[0].timeStamp == 0)
    {
        self->last[2] = left;
        self->last[3] = right;
        self->lastStateWheel[2] = 0.f;
        self->lastStateWheel[3] = 0.f;
        self->lastBias[2] = 0.f;
        self->lastBias[3] = 0.f;
        self->state.elem[2] = 0.f;
        self->state.elem[3] = 0.f;
    } else 
    {
        Wheel4Filter_propogateUntil(self, left.timeStamp );

        static bool leftFirst = true;
        if (leftFirst)
        {
           Wheel4Filter_add_measure(self, &left, 2,  &self->last[2]);
           Wheel4Filter_add_measure(self, &right, 3, &self->last[3]);
        }
        else
        {
           Wheel4Filter_add_measure(self, &right, 3, &self->last[3]);
           Wheel4Filter_add_measure(self, &left, 2,  &self->last[2]);
        }
        leftFirst = !leftFirst;
    }
}

void Wheel4Filter_add_pulse_wheel_message_forward(Wheel4Filter* self, uint16_t FL, uint16_t FR, uint64_t ts)
{
    TRACE(DEBUG, _b("Wheel4Filter_add_pulse_wheel_message_forward [FL %d]  [FR %d]  ts %ld"), FL, FR, ts);
    WheelMessage FLmsg = WheelMessage_create(ts, FL);
    WheelMessage FRmsg = WheelMessage_create(ts, FR);
    Wheel4Filter_add_fwd(self, FLmsg, FRmsg);
    self->fwdTs = ts;
    self->delta = 0;
}

void Wheel4Filter_add_pulse_wheel_message_rear(Wheel4Filter* self, uint16_t RL, uint16_t RR, uint64_t ts)
{
    TRACE(DEBUG, _b("Wheel4Filter_add_pulse_wheel_message_rear [RL %d]  [RR %d]  ts %ld"), RL, RR, ts);
    WheelMessage RLmsg = WheelMessage_create(ts, RL);
    WheelMessage RRmsg = WheelMessage_create(ts, RR);
    Wheel4Filter_add_rear(self, RLmsg, RRmsg);
    self->rearTs = ts;
    self->delta = 0;
}

void Wheel4Filter_add_pulse_wheel_message(Wheel4Filter* self, uint16_t FL, uint16_t FR, uint16_t RL, uint16_t RR, uint64_t ts)
{
    pthread_mutex_lock(&intern_wf_mutex);
    if (unknown_dir == 0)
    {
        Wheel4Filter_add_pulse_wheel_message_forward(self, FL, FR, ts);
        Wheel4Filter_add_pulse_wheel_message_rear(self, RL, RR, ts);
    }
    else
    {
        Wheel4Filter_add_pulse_wheel_message_forward(&wheels_clone_filter_f, FL, FR, ts);
        Wheel4Filter_add_pulse_wheel_message_rear(&wheels_clone_filter_f, RL, RR, ts);
        Wheel4Filter_add_pulse_wheel_message_forward(&wheels_clone_filter_b, FL, FR, ts);
        Wheel4Filter_add_pulse_wheel_message_rear(&wheels_clone_filter_b, RL, RR, ts);

        Wheel4Filter_recovery(Wheel4Filter_getMovDir(self));
        unknown_dir++;
    }

    if (unknown_dir > STABLE_TICKS_NUMBER)
    {
        unknown_dir = 0;
    }
    pthread_mutex_unlock(&intern_wf_mutex);
}

void Wheel4Filter_add_steering_wheel_message(Wheel4Filter* self, float32_t angle, uint64_t ts)
{
#if 0
    if (vp1evo_car_parameters_defaults.steering_ratio > 1.01f)
    {
        self->steeringAngle = angle / vp1evo_car_parameters_defaults.steering_ratio;
    }
    else
    {
        self->steeringAngle = calc_wheel_angle_from_steering_lut_d41(angle);
    }
#else
    self->steeringAngle = angle;
#endif    
    wheels_clone_filter_b.steeringAngle = self->steeringAngle;
    wheels_clone_filter_f.steeringAngle = self->steeringAngle;

    TRACE(DEBUG, _b("Wheel4Filter_add_steering_wheel_message angle %.1f  ts %ld %.4f"), angle, ts, self->steeringAngle);
}

#if 0
void Wheel4Filter_add_raw_message(Wheel4Filter* self, const can_chunk_t* el)
{
    Wheel4Filter_add_raw_message_psa(self, el->data.raw_frame.can_id, el->data.raw_frame.data, el->ts);
}
#endif

void Wheel4Filter_clone(void)
{
    TRACE(INFO, _b("Wheel filter clone"));
    pthread_mutex_lock(&intern_wf_mutex);
    if (unknown_dir == 0)
    {
        wheels_clone_filter_f = wheels_filter;
        wheels_clone_filter_b = wheels_filter;
        unknown_dir = 1U;
        wheels_clone_filter_f.movement_direction = MOV_DIR_FORWARD;
        wheels_clone_filter_b.movement_direction = MOV_DIR_BACKWARD;
    }
    pthread_mutex_unlock(&intern_wf_mutex);
}

void Wheel4Filter_recovery(int32_t mov)
{
    if (unknown_dir != 0)
    {
        int8_t g = wheels_filter.gear;
        int8_t m = wheels_filter.movement_direction;
        wheels_filter = (mov == MOV_DIR_BACKWARD) ? wheels_clone_filter_b : wheels_clone_filter_f;
        wheels_filter.gear = g;
        wheels_filter.movement_direction = m;
    }
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

/**
 * @brief   Update wheels-filter state following vehicle state change
 *          Technically, I already have an interface for it
 *
 * @param   self[in]        Wheels-filter data
 * @prama   count[in]       Pulses count: {FL, FR, RL, RR}
 * @param   ts[in]          Timestamp data (units? - tbd)
 *
 * @return                  Negative on failure
 */
void Wheels4Filter_update_pulses(Wheel4Filter* self, uint16_t *count, uint64_t ts)
{
    float64_t    time_s = (float64_t)ts * 0.001;

    WheelMessage FLmsg = WheelMessage_create(time_s, count[0]);
    WheelMessage FRmsg = WheelMessage_create(time_s, count[1]);
    WheelMessage RLmsg = WheelMessage_create(time_s, count[2]);
    WheelMessage RRmsg = WheelMessage_create(time_s, count[3]);

    Wheel4Filter_add_fwd(self, FLmsg, FRmsg);
    Wheel4Filter_add_rear(self, RLmsg, RRmsg);

    self->rearTs = time_s;
    self->fwdTs = time_s;
    self->delta = 0;
}
