/*******************************************************************************
 * math-neon.h
 *
 * Mathematics support library for NEON
 *
 * Copyright (c) 2015-2018 Cogent Embedded Inc.
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

#ifndef __MATH_NEON_H
#define __MATH_NEON_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "math-helpers.h"

#if defined(__aarch64__)
#include <arm_neon.h>
#elif defined(__x86_64__)
#define NEON2SSE_DISABLE_PERFORMANCE_WARNING
#include "NEON_2_SSE.h"
#else
#error "Unknown architecture"
#endif

/*******************************************************************************
 * Platform-specific fix-ups
 ******************************************************************************/

#ifdef __x86_64__
#define NEON2SSE_DISABLE_PERFORMANCE_WARNING
#include "NEON_2_SSE.h"
static inline uint8x8_t vtrn1_u8(uint8x8_t a, uint8x8_t b)
{
    return vtrn_u8(a, b).val[0];
}

static inline uint8x8_t vtrn2_u8(uint8x8_t a, uint8x8_t b)
{
    return vtrn_u8(a, b).val[1];
}

static inline uint8x8_t vzip1_u8(uint8x8_t a, uint8x8_t b)
{
    return vzip_u8(a, b).val[0];
}

static inline uint8x8_t vzip2_u8(uint8x8_t a, uint8x8_t b)
{
    return vzip_u8(a, b).val[1];
}

static inline int8x8_t vtrn1_s8(int8x8_t a, int8x8_t b)
{
    return vtrn_s8(a, b).val[0];
}

static inline int8x8_t vtrn2_s8(int8x8_t a, int8x8_t b)
{
    return vtrn_s8(a, b).val[1];
}

static inline int8x8_t vzip1_s8(int8x8_t a, int8x8_t b)
{
    return vzip_s8(a, b).val[0];
}

static inline int8x8_t vzip2_s8(int8x8_t a, int8x8_t b)
{
    return vzip_s8(a, b).val[1];
}

static inline uint16x4_t vtrn1_u16(uint16x4_t a, uint16x4_t b)
{
    return vtrn_u16(a, b).val[0];
}

static inline uint16x4_t vtrn2_u16(uint16x4_t a, uint16x4_t b)
{
    return vtrn_u16(a, b).val[1];
}

static inline uint16x4_t vzip1_u16(uint16x4_t a, uint16x4_t b)
{
    return vzip_u16(a, b).val[0];
}

static inline uint16x4_t vzip2_u16(uint16x4_t a, uint16x4_t b)
{
    return vzip_u16(a, b).val[1];
}

static inline uint32x2_t vtrn1_u32(uint32x2_t a, uint32x2_t b)
{
    return vtrn_u32(a, b).val[0];
}

static inline uint32x2_t vtrn2_u32(uint32x2_t a, uint32x2_t b)
{
    return vtrn_u32(a, b).val[1];
}

static inline uint32x2_t vzip1_u32(uint32x2_t a, uint32x2_t b)
{
    return vzip_u32(a, b).val[0];
}

static inline uint32x2_t vzip2_u32(uint32x2_t a, uint32x2_t b)
{
    return vzip_u32(a, b).val[1];
}

static inline int32x2_t vtrn1_s32(int32x2_t a, int32x2_t b)
{
    return vtrn_s32(a, b).val[0];
}

static inline int32x2_t vtrn2_s32(int32x2_t a, int32x2_t b)
{
    return vtrn_s32(a, b).val[1];
}

static inline int32x2_t vzip1_s32(int32x2_t a, int32x2_t b)
{
    return vzip_s32(a, b).val[0];
}

static inline int32x2_t vzip2_s32(int32x2_t a, int32x2_t b)
{
    return vzip_s32(a, b).val[1];
}

static inline float32x2_t vtrn1_f32(float32x2_t a, float32x2_t b)
{
    return vtrn_f32(a, b).val[0];
}

static inline float32x2_t vtrn2_f32(float32x2_t a, float32x2_t b)
{
    return vtrn_f32(a, b).val[1];
}

static inline float32x4_t vtrn1q_f32(float32x4_t a, float32x4_t b)
{
    return vcombine_f32(vtrn_f32(vget_low_f32(a), vget_low_f32(b)).val[0], vtrn_f32(vget_high_f32(a), vget_high_f32(b)).val[0]);
}

static inline float32x4_t vtrn2q_f32(float32x4_t a, float32x4_t b)
{
    return vcombine_f32(vtrn_f32(vget_low_f32(a), vget_low_f32(b)).val[1], vtrn_f32(vget_high_f32(a), vget_high_f32(b)).val[1]);
}

static inline uint32x4_t vtrn1q_u32(uint32x4_t a, uint32x4_t b)
{
    return vcombine_u32(vtrn_u32(vget_low_u32(a), vget_low_u32(b)).val[0], vtrn_u32(vget_high_u32(a), vget_high_u32(b)).val[0]);
}

static inline uint32x4_t vtrn2q_u32(uint32x4_t a, uint32x4_t b)
{
    return vcombine_u32(vtrn_u32(vget_low_u32(a), vget_low_u32(b)).val[1], vtrn_u32(vget_high_u32(a), vget_high_u32(b)).val[1]);
}

static inline float32x2_t vzip1_f32(float32x2_t a, float32x2_t b)
{
    return vzip_f32(a, b).val[0];
}

static inline float32x2_t vzip2_f32(float32x2_t a, float32x2_t b)
{
    return vzip_f32(a, b).val[1];
}

static inline float32x4_t vzip1q_f32(float32x4_t a, float32x4_t b)
{
    return vzipq_f32(a, b).val[0];
}

static inline float32x4_t vzip2q_f32(float32x4_t a, float32x4_t b)
{
    return vzipq_f32(a, b).val[1];
}

static inline uint8x16_t vqtbx1q_u8(uint8x16_t r, uint8x16_t tab, uint8x16_t idx)
{
    uint8x8x2_t t;
    t.val[0] = vget_low_u8(tab);
    t.val[1] = vget_high_u8(tab);

    uint8x8_t   r0 = vtbx2_u8(vget_low_u8(r), t, vget_low_u8(idx));
    uint8x8_t   r1 = vtbx2_u8(vget_high_u8(r), t, vget_high_u8(idx));

    return vcombine_u8(r0, r1);
}

static inline float32x2_t vdup_laneq_f32(float32x4_t a, const int k)
{
    return vmov_n_f32(vgetq_lane_f32(a, k));
}

static inline float32x4_t vdupq_laneq_f32(float32x4_t a, const int k)
{
    return vmovq_n_f32(vgetq_lane_f32(a, k));
}

static inline float32x2_t vdiv_f32(const float32x2_t a, const float32x2_t b)
{
    float32x2_t rs_proc = vrecpe_f32(b);
    rs_proc     = vmul_f32(vrecps_f32(b, rs_proc), rs_proc);
    rs_proc     = vmul_f32(vrecps_f32(b, rs_proc), rs_proc);

    return vmul_f32(a, rs_proc);
}

static inline float32x4_t vdivq_f32(const float32x4_t a, const float32x4_t b)
{
    float32x4_t rs_proc = vrecpeq_f32(b);
    rs_proc     = vmulq_f32(vrecpsq_f32(b, rs_proc), rs_proc);
    rs_proc     = vmulq_f32(vrecpsq_f32(b, rs_proc), rs_proc);

    return vmulq_f32(a, rs_proc);
}

static inline float32_t vpadds_f32(const float32x2_t a)
{
    return vget_lane_f32(a, 0) + vget_lane_f32(a, 1);
}

_NEON2SSE_INLINE float32x4_t vmulq_laneq_f32(float32x4_t a, float32x4_t v, __constrange(0,3) int l)
{
    float32_t vlane;
    vlane = (float) vgetq_lane_f32(v, l);
    return vmulq_n_f32(a,vlane);
}

_NEON2SSE_INLINE float32x2_t vmla_laneq_f32(float32x2_t a, float32x2_t b, float32x4_t v, __constrange(0,3) int l)
{
    float32_t vlane;
    float32x2_t c;
    vlane = (float) vgetq_lane_f32(v, l);
    c = vdup_n_f32(vlane);
    return vmla_f32(a,b,c);
}

_NEON2SSE_INLINE float32x4_t vmlaq_laneq_f32(float32x4_t a, float32x4_t b, float32x4_t v, __constrange(0,3) int l) // VMLA.F32 q0, q0, d0[0]
{
    float32_t vlane;
    float32x4_t c;
    vlane = vgetq_lane_f32(v, l);
    c = vdupq_n_f32(vlane);
    return vmlaq_f32(a,b,c);
}

_NEON2SSE_INLINE float32x2_t vmls_laneq_f32(float32x2_t a, float32x2_t b, float32x4_t v, __constrange(0,3) int l)
{
    float32_t vlane;
    float32x2_t c;
    vlane = (float) vgetq_lane_f32(v, l);
    c = vdup_n_f32(vlane);
    return vmls_f32(a,b,c);
}

_NEON2SSE_INLINE float32x4_t vmlsq_laneq_f32(float32x4_t a, float32x4_t b, float32x4_t v, __constrange(0,3) int l)
{
    float32_t vlane;
    float32x4_t c;
    vlane = (float) vgetq_lane_f32(v, l);
    c = vdupq_n_f32(vlane);
    return vmlsq_f32(a,b,c);
}

#define __uint8x8_p(v) (v).m64_u8[0], (v).m64_u8[1], (v).m64_u8[2], (v).m64_u8[3], (v).m64_u8[4], (v).m64_u8[5], (v).m64_u8[6], (v).m64_u8[7]
#define __uint16x4_p(v) (v).m64_u16[0], (v).m64_u16[1], (v).m64_u16[2], (v).m64_u16[3]
#define __int32x2_p(v) (v).m64_i32[0], (v).m64_i32[1]
#define __uint32x2_p(v) (v).m64_u32[0], (v).m64_u32[1]
#define __float32x2_p(v) (v).m64_f32[0], (v).m64_f32[1]
#define __uint32x4_p(v) vgetq_lane_u32((v), 0), vgetq_lane_u32((v), 1), vgetq_lane_u32((v), 2), vgetq_lane_u32((v), 3)
#define __int32x4_p(v) vgetq_lane_s32((v), 0), vgetq_lane_s32((v), 1), vgetq_lane_s32((v), 2), vgetq_lane_s32((v), 3)
#define __float32x4_p(v) vgetq_lane_f32((v), 0), vgetq_lane_f32((v), 1), vgetq_lane_f32((v), 2), vgetq_lane_f32((v), 3)

#define __mk_int16x4(a, b, c, d)    (int16x4_t){ .m64_i16 = {a, b, c, d} }
#define __mk_uint16x4(a, b, c, d)   (uint16x4_t){ .m64_u16 = {a, b, c, d} }
#define __mk_uint8x8(a, b, c, d, e, f, g, h)    (uint8x8_t){ .m64_u8 = {a, b, c, d, e, f, g, h} }
#define __mk_int32x2(a, b)          (int32x2_t){ .m64_i32 = {a, b} }
#define __mk_uint32x2(a, b)         (uint32x2_t){ .m64_u32 = {a, b} }

#define __mk_float32x2(a, b)        (float32x2_t){ .m64_f32 = {a, b} }
#define __mk_float32x4(a, b, c, d)  (float32x4_t){ a, b, c, d }

#define __mk_uint8x16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) vcombine_u8(__mk_uint8x8(a, b, c, d, e, f, g, h), __mk_uint8x8(i, j, k, l, m, n, o, p))

#else

/* ...native Aarch64 implementation */
#define __uint8x8_p(v) (v)[0], (v)[1], (v)[2], (v)[3], (v)[4], (v)[5], (v)[6], (v)[7]
#define __uint16x4_p(v) (v)[0], (v)[1], (v)[2], (v)[3]
#define __uint32x2_p(v) (v)[0], (v)[1]
#define __int32x2_p(v) (v)[0], (v)[1]
#define __float32x2_p(v) (v)[0], (v)[1]
#define __uint32x4_p(v) (v)[0], (v)[1], (v)[2], (v)[3]
#define __int32x4_p(v) (v)[0], (v)[1], (v)[2], (v)[3]
#define __float32x4_p(v) (v)[0], (v)[1], (v)[2], (v)[3]

#define __mk_int16x4(a, b, c, d)                (int16x4_t){ a, b, c, d }
#define __mk_uint16x4(a, b, c, d)               (uint16x4_t){ a, b, c, d }
#define __mk_uint8x8(a, b, c, d, e, f, g, h)    (uint8x8_t){ a, b, c, d, e, f, g, h }
#define __mk_int32x2(a, b)                      (int32x2_t){ a, b }
#define __mk_uint32x2(a, b)                     (uint32x2_t){ a, b }
#define __mk_float32x2(a, b)                    (float32x2_t){ a, b }
#define __mk_float32x4(a, b, c, d)              (float32x4_t){ a, b, c, d }
#define __mk_uint8x16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p) (uint8x16_t){a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p}

#endif

/*1/sqrt(x)*/
static inline float32x2_t vinvsqrt_f32( const float32x2_t x )
{
    float32x2_t sqrt_rs_proc = vrsqrte_f32(x);
    sqrt_rs_proc    = vmul_f32(vrsqrts_f32( vmul_f32( x, sqrt_rs_proc ), sqrt_rs_proc ), sqrt_rs_proc );
    sqrt_rs_proc    = vmul_f32(vrsqrts_f32( vmul_f32( x, sqrt_rs_proc ), sqrt_rs_proc ), sqrt_rs_proc );
    return sqrt_rs_proc;
}

/*1/sqrt(x)*/
static inline float32x4_t vinvsqrtq_f32( const float32x4_t x )
{
    float32x4_t sqrt_rs_proc = vrsqrteq_f32(x);
    sqrt_rs_proc    = vmulq_f32(vrsqrtsq_f32( vmulq_f32( x, sqrt_rs_proc ), sqrt_rs_proc ), sqrt_rs_proc );
    sqrt_rs_proc    = vmulq_f32(vrsqrtsq_f32( vmulq_f32( x, sqrt_rs_proc ), sqrt_rs_proc ), sqrt_rs_proc );
    return sqrt_rs_proc;
}

/* out = 1/input 24 bit precision */
static inline float32x4_t vinvq_f32(const float32x4_t val)
{
    float32x4_t rs_proc = vrecpeq_f32(val);
    rs_proc     = vmulq_f32(vrecpsq_f32(val, rs_proc), rs_proc);
    rs_proc     = vmulq_f32(vrecpsq_f32(val, rs_proc), rs_proc);
    return rs_proc;
}

/*******************************************************************************
 * Another portion of primitives
 ******************************************************************************/

/**
 * @brief   Multiply 3*3 matrix (with last row implied to be {0, 0, 1}) by the
 *          pair of vectors {x,y,1}, and drop last components (always 1)
 *
 * @param   M[in]       3*3 matrix in column-major order with last row dropped:
 *                      [0]: {m00, m10}
 *                      [1]: {m01, m11}
 *                      [2]: {m02, m12}
 * @param   V[in]       Pair of 2D vectors:
 *                      [0]: {x0, y0}
 *                      [1]: {x1, y1}
 *
 * @return              Pair of 2D vectors (result of multiplication):
 *                      [0]: {X0, Y0}
 *                      [1]: {X1, Y1}
 */
static inline __attribute__((__always_inline__))
float32x2x2_t __mat2x3_mulvh(float32x2x3_t M, float32x2x2_t V)
{
    float32x2x2_t   R;
    R.val[0] = vmla_lane_f32(vmla_lane_f32(M.val[2], M.val[1], V.val[0], 1), M.val[0], V.val[0], 0);
    R.val[1] = vmla_lane_f32(vmla_lane_f32(M.val[2], M.val[1], V.val[1], 1), M.val[0], V.val[1], 0);

    return R;
}

static inline __attribute__((__always_inline__))
float32x2x4_t __mat2x3_mulvh_4(float32x2x3_t M, float32x2x4_t V)
{
    float32x2x4_t   R;
    R.val[0] = vmla_lane_f32(vmla_lane_f32(M.val[2], M.val[1], V.val[0], 1), M.val[0], V.val[0], 0);
    R.val[1] = vmla_lane_f32(vmla_lane_f32(M.val[2], M.val[1], V.val[1], 1), M.val[0], V.val[1], 0);
    R.val[2] = vmla_lane_f32(vmla_lane_f32(M.val[2], M.val[1], V.val[2], 1), M.val[0], V.val[2], 0);
    R.val[3] = vmla_lane_f32(vmla_lane_f32(M.val[2], M.val[1], V.val[3], 1), M.val[0], V.val[3], 0);

    return R;
}

static inline __attribute__((__always_inline__))
float32x4x2_t __mat2x3_mulvh_4_tr(float32x2x3_t M, float32x4x2_t V)
{
    float32x2x4_t   R0;
    R0.val[0] = vmla_laneq_f32(vmla_laneq_f32(M.val[2], M.val[1], V.val[1], 0), M.val[0], V.val[0], 0);
    R0.val[1] = vmla_laneq_f32(vmla_laneq_f32(M.val[2], M.val[1], V.val[1], 1), M.val[0], V.val[0], 1);
    R0.val[2] = vmla_laneq_f32(vmla_laneq_f32(M.val[2], M.val[1], V.val[1], 2), M.val[0], V.val[0], 2);
    R0.val[3] = vmla_laneq_f32(vmla_laneq_f32(M.val[2], M.val[1], V.val[1], 3), M.val[0], V.val[0], 3);

    float32x4x2_t   R;
    R.val[0] = vcombine_f32(vtrn1_f32(R0.val[0], R0.val[1]), vtrn1_f32(R0.val[2], R0.val[3]));
    R.val[1] = vcombine_f32(vtrn2_f32(R0.val[0], R0.val[1]), vtrn2_f32(R0.val[2], R0.val[3]));

    return R;
}

/**
 * @brief   Multiply 3*3 matrix (with last row implied to be {0, 0, 1}) by the
 *          pair of vectors {x,y,1}, and drop last components (always 1)
 *
 * @param   M[in]       3*3 matrix in column-major order with last row dropped:
 *                      [0]: {m00, m10}
 *                      [1]: {m01, m11}
 *                      [2]: {m02, m12}
 * @param   V[in]       Pair of 2D vectors:
 *                      [0]: {x0, y0}
 *                      [1]: {x1, y1}
 *
 * @return              Pair of 2D vectors (result of multiplication):
 *                      [0]: {X0, Y0}
 *                      [1]: {X1, Y1}
 */
static inline __attribute__((__always_inline__))
float32x2x3_t __mat2x3_mul(float32x2x3_t R, float32x2x3_t S)
{
    float32x2x3_t   T;

    T.val[0] = vmla_lane_f32(vmul_lane_f32(R.val[0], S.val[0], 0), R.val[1], S.val[0], 1);
    T.val[1] = vmla_lane_f32(vmul_lane_f32(R.val[0], S.val[1], 0), R.val[1], S.val[1], 1);
    T.val[2] = vmla_lane_f32(vmla_lane_f32(R.val[2], R.val[0], S.val[2], 0), R.val[1], S.val[2], 1);

    return T;
}

/**
 * @brief   Calculate inverse 2x3 matrix
 *
 * @param   M[in]           2x3 matrix with last row [0, 0, 1]
 *
 * @return                  Inverse matrix
 */
static float32x2x3_t __mat2x3_inv(float32x2x3_t M)
{
#define A   vget_lane_f32(M.val[0], 0)  //__M(3, a, 0, 0)
#define B   vget_lane_f32(M.val[1], 0)  //__M(3, a, 0, 1)
#define C   vget_lane_f32(M.val[2], 0)  //__M(3, a, 0, 2)
#define D   vget_lane_f32(M.val[0], 1)  //__M(3, a, 1, 0)
#define E   vget_lane_f32(M.val[1], 1)  //__M(3, a, 1, 1)
#define F   vget_lane_f32(M.val[2], 1)  //__M(3, a, 1, 2)
#define G   0.0f
#define H   0.0f
#define I   1.0f

    float32_t       m00 = E * I - F * H;
    float32_t       m01 = F * G - D * I;
    float32_t       m02 = D * H - E * G;
    float32_t       m10 = C * H - B * I;
    float32_t       m11 = A * I - C * G;
    float32_t       m12 = B * G - A * H;
    float32_t       m20 = B * F - C * E;
    float32_t       m21 = C * D - A * F;
    float32_t       m22 = A * E - B * D;
    float32_t       d = A * m00 + B * m01 + C * m02;

    float32_t       dinv = 1.0f / d;

    float32x2x3_t   b;
    b.val[0] = vmul_n_f32(__mk_float32x2(m00, m01), dinv);
    b.val[1] = vmul_n_f32(__mk_float32x2(m10, m11), dinv);
    b.val[2] = vmul_n_f32(__mk_float32x2(m20, m21), dinv);

#undef A
#undef B
#undef C
#undef D
#undef E
#undef F
#undef G
#undef H
#undef I

    return b;
}

/**
 * @brief   Multiply matrix 3x3 matrix on 3d vector {x,y,1}:
 *              [a0 a1 a2]   [x]
 *              [a3 a4 a5] * [y]
 *              [a6 a7 a8]   [1]
 *
 * @param   X[in]       X-coordinates of the vector: {X0,X1,X2,X3}
 * @param   Y[in]       Y-coordinates of the vector: {Y0,Y1,Y2,Y3}
 * @param   a0123[in]   Matrix coefficients  0..3
 * @param   a4567[in]   Matrix coefficients  4..7
 * @param   a8[in]      Matrix coefficient 8
 *
 * @return              Multiplication result vector
 */
static inline __attribute__((__always_inline__))
float32x4x3_t mat3x3_mulvh(
    const float32x4_t X,
    const float32x4_t Y,
    const float32x4_t a0123,
    const float32x4_t a4567,
    const float32_t   a8
    )
{
    float32x4x3_t   P;

    P.val[0] = vmlaq_laneq_f32(vmlaq_laneq_f32(vdupq_laneq_f32(a0123, 2), X, a0123, 0), Y, a0123, 1);
    P.val[1] = vmlaq_laneq_f32(vmlaq_laneq_f32(vdupq_laneq_f32(a4567, 1), X, a0123, 3), Y, a4567, 0);
    P.val[2] = vmlaq_laneq_f32(vmlaq_laneq_f32(vdupq_n_f32(a8), X, a4567, 2), Y, a4567, 3);

    return P;
}

/**
 * @brief   Multiply matrix 3x3 matrix on 3d vector {x,y,z}:
 *              [a0 a1 a2]   [x]
 *              [a3 a4 a5] * [y]
 *              [a6 a7 a8]   [z]
 *
 * @param   X[in]       X-coordinates of the vector: {X0,X1,X2,X3}
 * @param   Y[in]       Y-coordinates of the vector: {Y0,Y1,Y2,Y3}
 * @param   Z[in]       Z-coordinates of the vector: {Z0,Z1,Z2,Z3}
 * @param   a0123[in]   Matrix coefficients  0..3
 * @param   a4567[in]   Matrix coefficients  4..7
 * @param   a8[in]      Matrix coefficient 8
 *
 * @return              Multiplication result vector
 */
static inline __attribute__((__always_inline__))
float32x4x3_t mat3x3_mulv(
    const float32x4_t X,
    const float32x4_t Y,
    const float32x4_t Z,
    const float32x4_t a0123,
    const float32x4_t a4567,
    const float32_t   a8
    )
{
    float32x4x3_t   P;

    P.val[0] = vmlaq_laneq_f32(vmlaq_laneq_f32(vmulq_laneq_f32(Z, a0123, 2), X, a0123, 0), Y, a0123, 1);
    P.val[1] = vmlaq_laneq_f32(vmlaq_laneq_f32(vmulq_laneq_f32(Z, a4567, 1), X, a0123, 3), Y, a4567, 0);
    P.val[2] = vmlaq_laneq_f32(vmlaq_laneq_f32(vmulq_n_f32(Z, a8), X, a4567, 2), Y, a4567, 3);

    return P;
}


static inline __attribute__((__always_inline__))
float32x4x2_t mlaq2(
    const float32x4x2_t XY,
    const float32x4_t scx,
    const float32x4_t scy,
    const float32x4_t add_x,
    const float32x4_t add_y
    )
{
    float32x4x2_t   P;
    P.val[0] = vmlaq_f32(add_x, XY.val[0], scx);
    P.val[1] = vmlaq_f32(add_y, XY.val[1], scy);
    return P;
}
/**
 * @brief   In-place transpose of 4x2 matrix
 *
 * @param   M[in]           4x2 matrix
 *
 * @return                  2*4 transposed matrix
 */
static inline float32x2x4_t mat4x2_transpose(float32x4x2_t M)
{

    float32x4_t  m0 = vtrn1q_f32(M.val[0], M.val[1]);
    float32x4_t  m1 = vtrn2q_f32(M.val[0], M.val[1]);

    float32x2x4_t   T;
    T.val[0] = vget_low_f32(m0);
    T.val[1] = vget_low_f32(m1);
    T.val[2] = vget_high_f32(m0);
    T.val[3] = vget_high_f32(m1);

    TRACE(0, _b("M=[0]:{%f,%f,%f,%f}, [1]:{%f,%f,%f,%f}"), __float32x4_p(M.val[0]), __float32x4_p(M.val[1]));
    TRACE(0, _b("T=[0]:{%f,%f}, [1]:{%f,%f}, [2]:{%f,%f}, [3]:{%f,%f}"), __float32x2_p(T.val[0]), __float32x2_p(T.val[1]), __float32x2_p(T.val[2]), __float32x2_p(T.val[3]));

    return T;
}

/**
 * @brief   In-place transpose of 4x4 matrix
 *
 * @param   M[in]           4x4 matrix
 *
 * @return                  4*4 transposed matrix
 */
static inline float32x4x4_t mat4x4_transpose(float32x4x4_t M)
{

    float32x4_t  m0 = vtrn1q_f32(M.val[0], M.val[1]);
    float32x4_t  m1 = vtrn2q_f32(M.val[0], M.val[1]);
    float32x4_t  m2 = vtrn1q_f32(M.val[2], M.val[3]);
    float32x4_t  m3 = vtrn2q_f32(M.val[2], M.val[3]);

    float32x4x4_t   T;
    T.val[0] = vcombine_f32(vget_low_f32(m0), vget_low_f32(m2));
    T.val[1] = vcombine_f32(vget_low_f32(m1), vget_low_f32(m3));
    T.val[2] = vcombine_f32(vget_high_f32(m0), vget_high_f32(m2));
    T.val[3] = vcombine_f32(vget_high_f32(m1), vget_high_f32(m3));

    TRACE(0, _b("M=[0]:{%f,%f,%f,%f}, [1]:{%f,%f,%f,%f}, [2]:{%f,%f,%f,%f}, [3]:{%f,%f,%f,%f}"), __float32x4_p(M.val[0]), __float32x4_p(M.val[1]), __float32x4_p(M.val[2]), __float32x4_p(M.val[3]));
    TRACE(0, _b("T=[0]:{%f,%f,%f,%f}, [1]:{%f,%f,%f,%f}, [2]:{%f,%f,%f,%f}, [3]:{%f,%f,%f,%f}"), __float32x4_p(T.val[0]), __float32x4_p(T.val[1]), __float32x4_p(T.val[2]), __float32x4_p(T.val[3]));

    return T;
}

/**
 * @brief   Extract k-th column of the matrix M
 *
 * @param   M[in]           4x4 matrix
 *                          [0]: {m00, m10, m20, m30}
 *                          [1]: {m01, m11, m21, m31}
 *                          [0]: {m02, m12, m22, m32}
 *                          [0]: {m03, m13, m23, m33}
 * @param   k[in]           Index of the column to return
 *
 * @return                  k-th column: {m0k, m1k, m2k, m3k}
 */
static inline float32x4_t mat4x4_get_column(float32x4x4_t M, int k)
{
    uint8x16_t  idx = __mk_uint8x16(k * 4 + 0, k * 4 + 1, k * 4 + 2, k * 4 + 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1);
    uint8x16_t  r = vdupq_n_u8(0);

    r = vqtbx1q_u8(r, vreinterpretq_u8_f32(M.val[0]), idx);
    idx = vextq_u8(idx, idx, 12);
    r = vqtbx1q_u8(r, vreinterpretq_u8_f32(M.val[1]), idx);
    idx = vextq_u8(idx, idx, 12);
    r = vqtbx1q_u8(r, vreinterpretq_u8_f32(M.val[2]), idx);
    idx = vextq_u8(idx, idx, 12);
    r = vqtbx1q_u8(r, vreinterpretq_u8_f32(M.val[3]), idx);

    return vreinterpretq_f32_u8(r);
}

/*******************************************************************************
 * Miscellaneous functions
 ******************************************************************************/

/* ...sine/cosine/log/exp */
#include "neon_mathfun.h"

/* ...atan2 */
#include "neon-atan2.h"

#endif  /* __MATH_NEON_H */
