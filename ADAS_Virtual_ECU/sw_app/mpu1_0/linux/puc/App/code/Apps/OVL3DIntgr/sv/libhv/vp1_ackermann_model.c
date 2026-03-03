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
 *  @file           vp1_ackermann_model.c
 *  @brief          Ackermann model implementation
 *
 *  @version        1.01
 *  @author         Alex Orlov & Pavel Gaenko
 *  @date           09.08.2019
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

#define MODULE_TAG                      ACK

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include <ctype.h> /* Header file for isdigit */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>
#include <float.h>
#include <limits.h>

typedef struct
{
    float x;
    float y;
    float width;
    float height;
} rect_float_t;

//#include "vp1_internal_types.h"
#include "vp1_math_types.h"
#include "vp1_common_math_utils.h"
#include "vp1_ackermann_model.h"

//#include "vp1_common.h"

WheelMessage WheelMessage_createDefault(void)
{
    WheelMessage out;
    out.timeStamp = 0;
    return out;
}

WheelMessage WheelMessage_create(uint64_t timeStamp, int cnt)
{
    WheelMessage out;
    out.timeStamp = timeStamp;
    out.cnt = cnt;
    return out;
}

AckermannModel AckermannModel_create(float32_t wheelBase, float32_t rearLRBase, float32_t forwardLRBase)
{
    AckermannModel out;
    out.wheelBase = wheelBase;
    out.rearLRBase = rearLRBase;
    out.forwardLRBase = forwardLRBase;
    return out;
}

void AckermannModel_copy(const AckermannModel * src, AckermannModel * dst)
{
    dst->forwardLRBase = src->forwardLRBase;
    dst->rearLRBase = src->rearLRBase;
    dst->wheelBase = src->wheelBase;
}

float32_t AckermannModel_getRadius(const AckermannModel* self, float32_t steerAng, Positions pz)
{
    float32_t res = 0.f;

    if (fabs(steerAng) > 1e-1f)
    {
        float32_t absRad = fabs(self->wheelBase / tanf((float32_t)(steerAng / 180.f *M_PI)));
        float32_t adder = 0;
        switch (pz)
        {
        case POS_REAR_LEFT:
        {
            adder = (steerAng > 0) ? -self->rearLRBase *0.5f : self->rearLRBase *0.5f;
            absRad += adder;
            break;
        }
        case POS_REAR_RIGHT:
        {
             adder = (steerAng < 0) ? -self->rearLRBase *0.5f: self->rearLRBase *0.5f;
             absRad += adder;
             break;
        }
        case POS_FORWARD_LEFT:
        {
             adder = (steerAng > 0) ? -self->forwardLRBase *0.5f : self->forwardLRBase *0.5f;
             absRad = sqrt((absRad + adder) * (absRad + adder) + self->wheelBase * self->wheelBase);
             break;
        }    
        case POS_FORWARD_RIGHT:
        {
            adder = (steerAng < 0) ? -self->forwardLRBase *0.5f : self->forwardLRBase *0.5f;
            absRad = sqrt((absRad + adder) * (absRad + adder) + self->wheelBase * self->wheelBase);
            break;
        }
        default:
            // no more wheels
            break;
        }
        res = absRad;
    }
    return res;
}

void AckermannModel_getRatios(const AckermannModel* self, float32_t steerAng, float32_t* ratios)
{
    float32_t rad0 = AckermannModel_getRadius(self, steerAng, POS_REAR_CENTER);
    if (0.f == rad0)
    {
        ratios[0] =1.f;
        ratios[1] =1.f;
        ratios[2] = 1.f;
        ratios[3] = 1.f;
    } else 
    {
        ratios[0] = rad0 / AckermannModel_getRadius(self, steerAng, POS_REAR_LEFT);
        ratios[1] = rad0 / AckermannModel_getRadius(self, steerAng, POS_REAR_RIGHT);
        ratios[2] = rad0 / AckermannModel_getRadius(self, steerAng, POS_FORWARD_LEFT);
        ratios[3] = rad0 / AckermannModel_getRadius(self, steerAng, POS_FORWARD_RIGHT);
    }
    return;
}

mat33f_t AckermannModel_affine_delta_poz(const AckermannModel * self, float32_t steerAng, float32_t dist)
{
    mat33f_t ret, shift, shift_inv;
    ret = eye33_f();
    shift = eye33_f();

    float32_t radius = AckermannModel_getRadius(self, steerAng, POS_REAR_CENTER);
    if (fabs(radius) < 1e-6f)
    {
        ret.elem[1][2] = dist; 
    } else 
    {
        float32_t alpha = dist / radius;
        shift.elem[0][2] = (steerAng > 0) ? radius : -radius;
        float32_t alphaout = (steerAng > 0) ? -alpha : alpha;

        mat33f_t rot;
        rot = eye33_f();
        rot.elem[0][0] =  cos(alphaout);
        rot.elem[0][1] =  sin(alphaout);
        rot.elem[1][0] = -sin(alphaout);
        rot.elem[1][1] =  cos(alphaout);
        mat33_inv(&shift, &shift_inv);
        ret = mul_mat33_x3(&shift_inv, &rot, &shift);
    }

    return ret;
}
