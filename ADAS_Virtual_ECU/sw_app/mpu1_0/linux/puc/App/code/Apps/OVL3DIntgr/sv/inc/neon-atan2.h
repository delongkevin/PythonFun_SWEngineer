/*******************************************************************************
 * neon-atan2.h
 *
 * Mathematics support library for NEON - atan2 evaluation
 *
 * Copyright (c) 2020 Cogent Embedded Inc.
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

#ifndef __NEON_ATAN2_H
#define __NEON_ATAN2_H

/**
 * @brief   Evaluation of atan in the range (-1.0, 1.0)
 *
 * @param   a[in]       Arguments: {A0:A1:A2:A3}
 *
 * @return              Results: {atan(A0),atan(A1),atan(A2),atan(A3)}
 */
static inline float32x4_t  atan_v4(float32x4_t a)
{
    float32x4_t         a2 = vmulq_f32(a, a);
    float32x4_t         a3 = vmulq_f32(a2, a);

    const float32x4_t   A7 = vmovq_n_f32(-0.0464964749f);
    const float32x4_t   A5 = vmovq_n_f32(0.15931422f);
    const float32x4_t   A3 = vmovq_n_f32(-0.327622764f);

    return vmlaq_f32(a, vmlaq_f32(A3, vmlaq_f32(A5, A7, a2), a2), a3);
}

/**
 * @brief   Evalation of atan2 function; maximal error 0.0002 in (-1.f, 1.f) range
 *
 * @param   y[in]       Y-coordinate
 * @param   x[in]       X-coordinate
 *
 * @result              Function result: atan2(Y, X)
 */
static inline float32x4_t atan2_ps(float32x4_t y, float32x4_t x)
{
    float32x4_t     a_y = vabsq_f32(y);
    float32x4_t     a_x = vabsq_f32(x);
    float32x4_t     min_yx = vminq_f32(a_y, a_x);
    float32x4_t     max_yx = vmaxq_f32(vmaxq_f32(a_y, a_x), vmovq_n_f32(1e-10f));
    float32x4_t     angle = atan_v4(vdivq_f32(min_yx, max_yx));

    angle = vbslq_f32(vcaleq_f32(x, y), vsubq_f32(vmovq_n_f32(M_PI_2), angle), angle);
    angle = vbslq_f32(vcltq_f32(x, vmovq_n_f32(0.0f)), vsubq_f32(vmovq_n_f32(M_PI), angle), angle);
    angle = vbslq_f32(vcltq_f32(y, vmovq_n_f32(0.0f)), vnegq_f32(angle), angle);

    return angle;
}

/**
 * @brief   Evalation of atan2 function; maximal error 0.0002 in (-1.f, 1.f) range
 *
 * @param   x[in]       Function argument
 *
 * @result              Function result: atan(x)
 */
static inline float32x4_t atan_ps(float32x4_t y)
{
    float32x4_t     a_y = vabsq_f32(y);
    float32x4_t     a_x = vmovq_n_f32(1.0f);
    float32x4_t     min_yx = vminq_f32(a_y, a_x);
    float32x4_t     max_yx = vmaxq_f32(a_y, a_x);
    float32x4_t     angle = atan_v4(vdivq_f32(min_yx, max_yx));

    angle = vbslq_f32(vcltq_f32(a_x, a_y), vsubq_f32(vmovq_n_f32(M_PI_2), angle), angle);
    angle = vbslq_f32(vcltq_f32(y, vmovq_n_f32(0.0f)), vnegq_f32(angle), angle);

    return angle;
}

/* tbd ---keep this for some while */
#define  ATAN_POLYA7        (-0.0464964749f)
#define  ATAN_POLYA5        ( 0.15931422f  )
#define  ATAN_POLYA3        (-0.327622764f )
#define  One                ( 1.f )
#define  MOne               (-1.f )
#define  ATAN_POLYA7_v      vmovq_n_f32(  ATAN_POLYA7 )
#define  ATAN_POLYA5_v      vmovq_n_f32(  ATAN_POLYA5 )
#define  ATAN_POLYA3_v      vmovq_n_f32(  ATAN_POLYA3 )
#define  Zero_v    vmovq_n_f32( 0.f )
#define  Eps_v     vmovq_n_f32( 1e-10f )
#define  One_v     vmovq_n_f32( One )
#define  MOne_v    vmovq_n_f32( MOne )
#define  M_PI_2_v  vmovq_n_f32( M_PI_2 )

static inline float32x4_t  fast2ArcTan_v4( float32x4_t a )
{
    float32x4_t s = vmulq_f32( a , a );
    float32x4_t s3 = vmulq_f32( s , a );
    return vmlaq_f32(a, ( vmlaq_f32(ATAN_POLYA3_v, vmlaq_f32( ATAN_POLYA5_v, ATAN_POLYA7_v, s ) , s )  ), s3  );
}

/**
 * @brief Atan (max err 0.0002 - in (-1.f, 1.f) range)
 *
 *
 * @param z  - can be negative
 * @param r - is positive
 * @return float32x4_t 4 atans values
 */
static inline float32x4_t atan2_fast_v4_worker( float32x4_t z, float32x4_t r )
{
    float32x4_t abs_z = vabsq_f32( z );
    uint32x4_t  grater = vcgtq_f32( abs_z, r );
    uint32x4_t  sign_msk = vcgeq_f32( z, Zero_v );
    float32x4_t sign_z = vbslq_f32(sign_msk, One_v, MOne_v);

    float32x4_t min_ = vminq_f32(abs_z, r);
    /* eliminates zero division */
    float32x4_t max_ = vmaxq_f32( vmaxq_f32(abs_z, r), Eps_v);
    float32x4_t tan_invm = vmulq_f32( min_, vinvq_f32(max_) );
    float32x4_t tan  = vmulq_f32(tan_invm, sign_z);
    float32x4_t atan_angle = fast2ArcTan_v4(tan);

    float32x4_t angle = vbslq_f32( grater, atan_angle, vnegq_f32(atan_angle));
    float32x4_t adder = vbslq_f32( grater, Zero_v, M_PI_2_v );

    atan_angle = vaddq_f32(angle, adder);
    return atan_angle;
}

#endif
