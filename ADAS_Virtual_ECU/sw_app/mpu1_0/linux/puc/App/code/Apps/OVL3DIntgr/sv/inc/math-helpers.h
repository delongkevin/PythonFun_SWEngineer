/*******************************************************************************
 * math-helpers.h
 *
 * Primitive matrix operations
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

#ifndef __MATH_HELPERS_H
#define __MATH_HELPERS_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <math.h>

/*******************************************************************************
 * Platform-specific bindings
 ******************************************************************************/

typedef float32_t    __MATH_FLOAT;

#define __MATH_ZERO             ((__MATH_FLOAT)0.0)
#define __MATH_ONE              ((__MATH_FLOAT)1.0)
#define __MATH_RADIANS(v)       (__MATH_FLOAT)((v) * M_PI / 180.0)
#define __MATH_DEGREES(v)       (__MATH_FLOAT)((v) * 180.0 / M_PI)
#define __MATH_COS(v)           (__MATH_FLOAT)cos(v)
#define __MATH_SIN(v)           (__MATH_FLOAT)sin(v)
#define __MATH_TAN(v)           (__MATH_FLOAT)tan(v)
#define __MATH_ATAN(v)           (__MATH_FLOAT)atan(v)
#define __MATH_FLOAT(v)         ((__MATH_FLOAT)(v))

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/* ...scalar value */
typedef __MATH_FLOAT    __scalar;

/* ...vectors */
typedef __MATH_FLOAT    __vec2[2];
typedef __MATH_FLOAT    __vec3[3];
typedef __MATH_FLOAT    __vec4[4];

/* ...column-major order matrices */
typedef __MATH_FLOAT    __mat2x2[2 * 2];
typedef __MATH_FLOAT    __mat3x3[3 * 3];
typedef __MATH_FLOAT    __mat3x2[3 * 2];
typedef __MATH_FLOAT    __mat4x4[4 * 4] __attribute__((aligned(16)));
typedef __MATH_FLOAT    __mat4x3[4 * 3];
typedef __MATH_FLOAT    __mat4x2[4 * 2];

/*******************************************************************************
 * Matrix element accessor
 ******************************************************************************/

/**> Element <i,j> accessor */
#define __M(N, m, i, j)    (m)[(j) * (N) + i]

/**> Column <*,j> accessor */
#define __M_col(N, m, j)   ((m) + (j) * (N))

/*******************************************************************************
 * Primitive scalar operations
 ******************************************************************************/

/* ...clamping value to positive integer */
static inline u16 __scalar_clamp_u16(__scalar a, int r)
{
    float   t = a * r;

    return (t < 0 ? 0 : (t > r - 1 ? (u16)(r - 1) : (u16)t));
}

/* ...clamping value to signed integer */
static inline s16 __scalar_clamp_s16(__scalar a, int r)
{
    float   t = a * r;

    return (t < 0 ? 0 : (t > r - 1 ? (s16)(r - 1) : (s16)t));
}

/* ...inverse square root approximation ("fast inverse square root" algorithm) */
static inline __scalar __scalar_invsqrt(const __scalar a, int highp)
{
    float   a2 = 0.5f * a, b = a;
    int     i = *(int *)&b;
    i = 0x5f3759df - (i >> 1);
    b = *(float *)&i;
    b = b * (1.5f - a2 * b * b);

    /* ...second Newton-Raphson iteration on request */
    (highp ? b = b * (1.5f - a2 * b * b) : 0);

    return b;
}

static inline __scalar __scalar_inv(const __scalar a)
{
    return 1.0 / a;
}

static inline __scalar __scalar_div(const __scalar a, const __scalar b)
{
    return a / b;
}

static inline __scalar __scalar_mul(const __scalar a, const __scalar b)
{
    return a * b;
}

static inline __scalar __scalar_avg(const __scalar a, const __scalar b)
{
    return (a + b) * 0.5;
}

static inline __scalar __scalar_pow2n(const __scalar a, int n)
{
    return pow(a, 1 << n);
}

static inline __scalar __scalar_clamp(const __scalar a, const __scalar min, const __scalar max)
{
    return (a < min ? min : (a > max ? max : a));
}

static inline void __scalar_dump(const __scalar a, const char *tag)
{
    char    buffer[256];
    int     n = sizeof(buffer);

    snprintf(buffer, n, "%s: %e", tag, a);

    TRACE(1, _b("%s"), buffer);
}


/*******************************************************************************
 * Primitive vectors operations
 ******************************************************************************/

static inline void __vecN_zero(const int N, __MATH_FLOAT *v)
{
    memset(v, 0, sizeof(__MATH_FLOAT) * N);
}

static inline void __vec2_zero(__vec2 v)
{
    __vecN_zero(2, v);
}

static inline void __vec3_zero(__vec3 v)
{
    __vecN_zero(3, v);
}

static inline void __vec4_zero(__vec4 v)
{
    __vecN_zero(4, v);
}

/*******************************************************************************
 * Vector addition/subtraction: S = U +(-) V
 ******************************************************************************/

static inline void __vecN_add(const int N, const __MATH_FLOAT *u, const __MATH_FLOAT *v, __MATH_FLOAT *s)
{
    int         i;

    for (i = 0; i < N; i++)
        *s++ = *u++ + *v++;
}

static inline void __vec2_add(const __vec2 u, const __vec2 v, __vec2 s)
{
    __vecN_add(2, u, v, s);
}

static inline void __vec3_add(const __vec3 u, const __vec3 v, __vec3 s)
{
    __vecN_add(3, u, v, s);
}

static inline void __vec4_add(const __vec4 u, const __vec4 v, __vec4 s)
{
    __vecN_add(4, u, v, s);
}

static inline void __vecN_sub(const int N, const __MATH_FLOAT *u, const __MATH_FLOAT *v, __MATH_FLOAT *s)
{
    int         i;

    for (i = 0; i < N; i++)
        *s++ = *u++ - *v++;
}

static inline void __vec2_sub(const __vec2 u, const __vec2 v, __vec2 s)
{
    __vecN_sub(2, u, v, s);
}

static inline void __vec3_sub(const __vec3 u, const __vec3 v, __vec3 s)
{
    __vecN_sub(3, u, v, s);
}

static inline void __vec4_sub(const __vec4 u, const __vec4 v, __vec4 s)
{
    __vecN_sub(4, u, v, s);
}

/*******************************************************************************
 * Average between two vectors: S = (U + V) / 2
 ******************************************************************************/

static inline void __vecN_avg(const int N, const __MATH_FLOAT *u, const __MATH_FLOAT *v, __MATH_FLOAT *s)
{
    int         i;

    for (i = 0; i < N; i++)
        *s++ = __scalar_avg(*u++, *v++);
}

static inline void __vec2_avg(const __vec2 u, const __vec2 v, __vec2 s)
{
    __vecN_avg(2, u, v, s);
}

static inline void __vec3_avg(const __vec3 u, const __vec3 v, __vec3 s)
{
    __vecN_avg(3, u, v, s);
}

static inline void __vec4_avg(const __vec4 u, const __vec4 v, __vec4 s)
{
    __vecN_avg(4, u, v, s);
}

/*******************************************************************************
 * Vector multiplication by constant: S = t * U
 ******************************************************************************/

static inline void __vecN_muls(const int N, const __MATH_FLOAT *u, const __MATH_FLOAT t, __MATH_FLOAT *s)
{
    int     i;

    for (i = 0; i < N; i++)
        *s++ = t * *u++;
}

static inline void __vec2_muls(const __vec2 u, const __scalar t, __vec2 s)
{
    __vecN_muls(2, u, t, s);
}

static inline void __vec3_muls(const __vec3 u, const __scalar t, __vec3 s)
{
    __vecN_muls(3, u, t, s);
}

static inline void __vec4_muls(const __vec4 u, const __scalar t, __vec3 s)
{
    __vecN_muls(4, u, t, s);
}

/*******************************************************************************
 * Vector component-wise multiplication: S[i] = U[i] * V[i]
 ******************************************************************************/

static inline void __vecN_mul(const int N, const __MATH_FLOAT *u, const __MATH_FLOAT *v, __MATH_FLOAT *s)
{
    int     i;

    for (i = 0; i < N; i++)
        *s++ = *u++ * *v++;
}

static inline void __vec2_mul(const __vec2 u, const __vec2 v, __vec2 s)
{
    __vecN_mul(2, u, v, s);
}

static inline void __vec3_mul(const __vec3 u, const __vec3 v, __vec3 s)
{
    __vecN_mul(3, u, v, s);
}

static inline void __vec4_mul(const __vec4 u, const __vec4 v, __vec3 s)
{
    __vecN_mul(4, u, v, s);
}

/*******************************************************************************
 * Vector multiplication and accumulation: S = U + t * V
 ******************************************************************************/

static inline void __vecN_mac(const int N, const __MATH_FLOAT *u, const __MATH_FLOAT *v, const __MATH_FLOAT t, __MATH_FLOAT *s)
{
    int     i;

    for (i = 0; i < N; i++)
        *s++ = *u++ + t * *v++;
}

static inline void __vec2_mac(const __vec2 u, const __vec2 v, const __scalar t, __vec2 s)
{
    __vecN_mac(2, u, v, t, s);
}

static inline void __vec3_mac(const __vec3 u, const __vec3 v, const __scalar t, __vec3 s)
{
    __vecN_mac(3, u, v, t, s);
}

static inline void __vec4_mac(const __vec4 u, const __vec4 v, const __scalar t, __vec4 s)
{
    __vecN_mac(4, u, v, t, s);
}

/*******************************************************************************
 * Vector cross-product: S = U * V
 ******************************************************************************/

static inline void __vec3_cprod(const __vec3 u, const __vec3 v, __vec3 s)
{
    s[0] = u[1] * v[2] - u[2] * v[1];
    s[1] = u[2] * v[0] - u[0] * v[2];
    s[2] = u[0] * v[1] - u[1] * v[0];
}

/*******************************************************************************
 * Vector dot-product: s = (U,V)
 ******************************************************************************/

static inline __scalar __vecN_dprod(const int N, const __MATH_FLOAT *u, const __MATH_FLOAT *v)
{
    int         i;
    __scalar    s = __MATH_ZERO;

    for (i = 0; i < N; i++)     s += *u++ * *v++;

    return s;
}

static inline __scalar __vec2_dprod(const __vec2 u, const __vec2 v)
{
    return __vecN_dprod(2, u, v);
}

static inline __scalar __vec3_dprod(const __vec3 u, const __vec3 v)
{
    return __vecN_dprod(3, u, v);
}

static inline __scalar __vec4_dprod(const __vec4 u, const __vec4 v)
{
    return __vecN_dprod(4, u, v);
}

/*******************************************************************************
 * Vector normalization
 ******************************************************************************/

static inline void __vecN_normalize(const int N, const __MATH_FLOAT *a, __MATH_FLOAT *b, __MATH_FLOAT *l)
{
    __MATH_FLOAT        s = __MATH_ZERO, v;
    const __MATH_FLOAT *t = a;
    int                 i;

    /* ...calculate vector square length */
    for (i = 0; i < N; i++)     v = *t++, s += v * v;

    /* ...calculate inverse square root */
    s = __scalar_invsqrt(s, 0);

    /* ...multiply vector by norm */
    __vecN_muls(N, a, s, b);

    (l != NULL ? *l = 1.0 / s : 0);
}

static inline void __vec2_normalize(const __vec2 a, __vec2 b)
{
    __vecN_normalize(2, a, b, NULL);
}

static inline void __vec3_normalize(const __vec3 a, __vec3 b)
{
    __vecN_normalize(3, a, b, NULL);
}

static inline void __vec4_normalize(const __vec4 a, __vec4 b)
{
    __vecN_normalize(4, a, b, NULL);
}

/*******************************************************************************
 * Vector dump
 ******************************************************************************/

static inline void __vecN_dump(const int N, const __MATH_FLOAT *v, const char *tag)
{
    int     i;
    char    buffer[256], *p = buffer;
    int     n = sizeof(buffer), k;

    p += (k = snprintf(buffer, n, "%s: ", tag)), n -= k;

    for (i = 0; i < N; i++)
        p += (k = snprintf(p, n, "%f ", *v++)), n -= k;

    TRACE(1, _b("%s"), buffer);
}

static inline void __vec2_dump(const __vec2 v, const char *tag)
{
    __vecN_dump(2, v, tag);
}

static inline void __vec3_dump(const __vec3 v, const char *tag)
{
    __vecN_dump(3, v, tag);
}

static inline void __vec4_dump(const __vec4 v, const char *tag)
{
    __vecN_dump(4, v, tag);
}

/*******************************************************************************
 * Primitive matrix operations
 ******************************************************************************/

/* ...zero matrix initialization */
static inline void __matNxN_zero(const int N, __MATH_FLOAT *m)
{
    memset(m, 0, sizeof(__MATH_FLOAT) * N * N);
}

/* ...identity matrix setting */
static inline void __matNxN_identity(const int N, __MATH_FLOAT *m)
{
    int     i;

    __matNxN_zero(N, m);
    for (i = 0; i < N; i++) __M(N, m, i, i) = __MATH_ONE;
}

static inline void __mat3x3_identity(__mat3x3 m)
{
    __matNxN_identity(3, m);
}

static inline void __mat4x4_identity(__mat4x4 m)
{
    __matNxN_identity(4, m);
}

/*******************************************************************************
 * Columns accessors
 ******************************************************************************/

static inline void __matNxN_M_column(const int N, const int M,  const int i, const __MATH_FLOAT *m, __MATH_FLOAT *v)
{
    const __MATH_FLOAT  *c = m + N * i;
    int                  j;

    for (j = 0; j < M; j++) *v++ = *c++;
}

/*******************************************************************************
 * Scale matrix setting
 ******************************************************************************/

/* ...diagonal matrix setting */
static inline void __matNxN_M_diag(const int N, const int M, __MATH_FLOAT *m, const __MATH_FLOAT s)
{
    int     i;

    __matNxN_zero(N, m);
    for (i = 0; i < M; i++) __M(N, m, i, i) = s;
    for (; i < N; i++) __M(N, m, i, i) = __MATH_ONE;
}

/* ...diagonal matrix setting */
static inline void __matNxN_M_diagv(const int N, const int M, __MATH_FLOAT *m, const __MATH_FLOAT *s)
{
    int     i;

    __matNxN_zero(N, m);
    for (i = 0; i < M; i++) __M(N, m, i, i) = *s++;
    for (; i < N; i++) __M(N, m, i, i) = __MATH_ONE;
}

/* ...rotation matrix setting */
static inline void __matNxN_rotate(const int N, __MATH_FLOAT *m, int i, int j, const __scalar deg)
{
    __MATH_FLOAT    rad = __MATH_RADIANS(deg);
    __MATH_FLOAT    c = __MATH_COS(rad);
    __MATH_FLOAT    s = __MATH_SIN(rad);

    __matNxN_identity(N, m);
    __M(N, m, i, i) = c;
    __M(N, m, j, j) = c;
    __M(N, m, i, j) = s;
    __M(N, m, j, i) = -s;
}

/*******************************************************************************
 * Matrix in-place transposition
 ******************************************************************************/

static inline void __matNxN_tr(const int N, __MATH_FLOAT *a)
{
    int     i, j;

    for (i = 0; i < N - 1; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            __MATH_FLOAT    a_ij = __M(N, a, i, j);

            __M(N, a, i, j) = __M(N, a, j, i);
            __M(N, a, j, i) = a_ij;
        }
    }
}

static inline void __mat2x2_tr(__mat2x2 a)
{
    __matNxN_tr(2, a);
}

static inline void __mat3x3_tr(__mat3x3 a)
{
    __matNxN_tr(3, a);
}

static inline void __mat4x4_tr(__mat4x4 a)
{
    __matNxN_tr(4, a);
}

/*******************************************************************************
 * Matrix multiplication: C = A * B
 ******************************************************************************/

static inline void __matNxN_mul(const int N, const __MATH_FLOAT *a, const __MATH_FLOAT *b, __MATH_FLOAT *c)
{
    int             i, j, k;
    __MATH_FLOAT    c_ij;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            for (c_ij = __MATH_ZERO, k = 0; k < N; k++)
            {
                c_ij += __M(N, a, i, k) * __M(N, b, k, j);
            }

            __M(N, c, i, j) = c_ij;
        }
    }
}

/* ...multiplication of major MxM minor of NxN "a" by MxM matrix "b" */
static inline void __matNxN_MxM_mul(const int N, const int M, const __MATH_FLOAT *a, const __MATH_FLOAT *b, __MATH_FLOAT *c)
{
    int             i, j, k;
    __MATH_FLOAT    c_ij;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            for (c_ij = __MATH_ZERO, k = 0; k < M; k++)
            {
                c_ij += __M(N, a, i, k) * __M(M, b, k, j);
            }

            __M(M, c, i, j) = c_ij;
        }
    }
}

static inline void __mat2x2_mul(const __mat2x2 a, const __mat2x2 b, __mat2x2 c)
{
    __matNxN_mul(2, a, b, c);
}

static inline void __mat3x3_mul(const __mat3x3 a, const __mat3x3 b, __mat3x3 c)
{
    __matNxN_mul(3, a, b, c);
}

static inline void __mat4x4_mul(const __mat4x4 a, const __mat4x4 b, __mat4x4 c)
{
    __matNxN_mul(4, a, b, c);
}

static inline void __mat4x4_3x3_mul(const __mat4x4 a, const __mat3x3 b, __mat3x3 c)
{
    __matNxN_MxM_mul(4, 3, a, b, c);
}

/*******************************************************************************
 * Matrix right multiplication: B = M * A
 ******************************************************************************/

static inline void __matNxN_mulv(const int N, const __MATH_FLOAT *m, const __MATH_FLOAT *a, __MATH_FLOAT *b)
{
    int             i, j;
    __MATH_FLOAT    b_i;

    for (i = 0; i < N; i++)
    {
        for (b_i = __MATH_ZERO, j = 0; j < N; j++)
        {
            b_i += __M(N, m, i, j) * a[j];
        }

        b[i] = b_i;
    }
}

static inline void __matNxN_mulvt(const int N, const __MATH_FLOAT *m, const __MATH_FLOAT *a, __MATH_FLOAT *b)
{
    int             i, j;
    __MATH_FLOAT    b_i;

    for (i = 0; i < N; i++)
    {
        for (b_i = __MATH_ZERO, j = 0; j < N; j++)
        {
            b_i += __M(N, m, j, i) * a[j];
        }

        b[i] = b_i;
    }
}

static inline void __mat2x2_mulv(const __mat2x2 a, const __vec2 b, __vec2 c)
{
    __matNxN_mulv(2, a, b, c);
}

static inline void __mat3x3_mulv(const __mat3x3 a, const __vec3 b, __vec3 c)
{
    __matNxN_mulv(3, a, b, c);
}

static inline void __mat4x4_mulv(const __mat4x4 a, const __vec4 b, __vec4 c)
{
    __matNxN_mulv(4, a, b, c);
}

/*******************************************************************************
 * Matrix multiplication by the homogenous vector
 ******************************************************************************/

static inline void __matNxN_mulvh(const int N, const __MATH_FLOAT *m, const __MATH_FLOAT *a, __MATH_FLOAT *b)
{
    int             i, j;
    __MATH_FLOAT    b_i;

    for (i = 0; i < N; i++)
    {
        for (b_i = __M(N, m, i, N - 1), j = 0; j < N - 1; j++)
        {
            b_i += __M(N, m, i, j) * a[j];
        }

        b[i] = b_i;
    }
}

static inline void __matNxN_mulvht(const int N, const __MATH_FLOAT *m, const __MATH_FLOAT *a, __MATH_FLOAT *b)
{
    int             i, j;
    __MATH_FLOAT    b_i;

    for (i = 0; i < N; i++)
    {
        for (b_i = __M(N, m, N - 1, i), j = 0; j < N - 1; j++)
        {
            b_i += __M(N, m, j, i) * a[j];
        }

        b[i] = b_i;
    }
}

static inline void __mat3x2_mulvh(const __mat3x2 a, const __vec2 b, __vec2 c)
{
    int             i, j;
    __MATH_FLOAT    b_i;
    const __MATH_FLOAT *m_a = a;
    const __MATH_FLOAT *m_b = b;
    __MATH_FLOAT *m_c = c;

    for (i = 0; i < 2; i++)
    {
        for (b_i = __M(3, m_a, i, 2), j = 0; j < 2; j++)
        {
            b_i += __M(3, m_a, i, j) * m_b[j];
        }

        m_c[i] = b_i;
    }
}

static inline void __mat3x3_mulvh(const __mat3x3 a, const __vec2 b, __vec3 c)
{
    __matNxN_mulvh(3, a, b, c);
}

static inline void __mat4x4_mulvh(const __mat4x4 a, const __vec3 b, __vec4 c)
{
    __matNxN_mulvh(4, a, b, c);
}

/*******************************************************************************
 * Multiplication of major MxM minor of NxN matrix by vector
 ******************************************************************************/

static inline void __matNxN_MxM_mulv(const int N, const int M, const __MATH_FLOAT *m, const __MATH_FLOAT *a, __MATH_FLOAT *b)
{
    int             i, j;
    __MATH_FLOAT    b_i;

    for (i = 0; i < M; i++)
    {
        for (b_i = __MATH_ZERO, j = 0; j < M; j++)
        {
            b_i += __M(N, m, i, j) * a[j];
        }

        b[i] = b_i;
    }
}

static inline void __matNxN_MxM_mulvh(const int N, const int M, const __MATH_FLOAT *m, const __MATH_FLOAT *a, __MATH_FLOAT *b)
{
    int             i, j;
    __MATH_FLOAT    b_i;

    for (i = 0; i < M; i++)
    {
        for (b_i = __M(N, m, i, M - 1), j = 0; j < M - 1; j++)
        {
            b_i += __M(N, m, i, j) * a[j];
        }

        b[i] = b_i;
    }
}

static inline void __mat4x4_3x3_mulv(const __mat4x4 m, const __vec3 a, __vec3 b)
{
    __matNxN_MxM_mulv(4, 3, m, a, b);
}

static inline void __mat4x4_3x3_mulvh(const __mat4x4 m, const __vec2 a, __vec3 b)
{
    __matNxN_MxM_mulvh(4, 3, m, a, b);
}

/*******************************************************************************
 * Multiplication of rectangular matrix by vector
 ******************************************************************************/

static inline void __matNxM_mulv(const int N, const int M, const __MATH_FLOAT * m, const __MATH_FLOAT * a, __MATH_FLOAT *b)
{
        int             i, j;
    __MATH_FLOAT    b_i;

    for (i = 0; i < N; i++)
    {
        for (b_i = __MATH_ZERO, j = 0; j < M; j++)
        {
            b_i += __M(N, m, i, j) * a[j];
        }

        b[i] = b_i;
    }
}

static inline void __matNxM_mulvh(const int N, const int M, const __MATH_FLOAT * m, const __MATH_FLOAT * a, __MATH_FLOAT *b)
{
    int             i, j;
    __MATH_FLOAT    b_i;

    for (i = 0; i < N; i++)
    {
        for (b_i = __M(N, m, i, M - 1), j = 0; j < M - 1; j++)
        {
            b_i += __M(N, m, i, j) * a[j];
        }

        b[i] = b_i;
    }
}

/*******************************************************************************
 * Matrix multiplication by scalar: U = M * b
 ******************************************************************************/

static inline void __matNxN_M_muls(const int N, const int M, const __MATH_FLOAT *m, const __MATH_FLOAT b, __MATH_FLOAT *u)
{
    int             i, j;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            __M(N, u, i, j) = __scalar_mul(__M(N, m, i, j), b);
        }
    }

    if (m != u)
    {
        for (; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                __M(N, u, i, j) = __M(N, m, i, j);
            }
        }
    }
}

/*******************************************************************************
 * Matrix inversion: B = inv(A) * det, det = det(A)
 ******************************************************************************/

/* ...don't need anything except for this yet */
static inline void __matNxN_min3x3_inv(const int N, const __MATH_FLOAT *a, __mat3x3 b, __scalar *det)
{
#define A   __M(N, a, 0, 0)
#define B   __M(N, a, 0, 1)
#define C   __M(N, a, 0, 2)
#define D   __M(N, a, 1, 0)
#define E   __M(N, a, 1, 1)
#define F   __M(N, a, 1, 2)
#define G   __M(N, a, 2, 0)
#define H   __M(N, a, 2, 1)
#define I   __M(N, a, 2, 2)

#define M00 __M(3, b, 0, 0)
#define M01 __M(3, b, 0, 1)
#define M02 __M(3, b, 0, 2)
#define M10 __M(3, b, 1, 0)
#define M11 __M(3, b, 1, 1)
#define M12 __M(3, b, 1, 2)
#define M20 __M(3, b, 2, 0)
#define M21 __M(3, b, 2, 1)
#define M22 __M(3, b, 2, 2)

    __MATH_FLOAT    m00 = E * I - F * H;
    __MATH_FLOAT    m01 = F * G - D * I;
    __MATH_FLOAT    m02 = D * H - E * G;
    __MATH_FLOAT    m10 = C * H - B * I;
    __MATH_FLOAT    m11 = A * I - C * G;
    __MATH_FLOAT    m12 = B * G - A * H;
    __MATH_FLOAT    m20 = B * F - C * E;
    __MATH_FLOAT    m21 = C * D - A * F;
    __MATH_FLOAT    m22 = A * E - B * D;
    __MATH_FLOAT    d = A * m00 + B * m01 + C * m02;

    if (det == NULL)
    {
        __MATH_FLOAT    dinv = __scalar_inv(d);

        M00 = m00 * dinv, M01 = m10 * dinv, M02 = m20 * dinv;
        M10 = m01 * dinv, M11 = m11 * dinv, M12 = m21 * dinv;
        M20 = m02 * dinv, M21 = m12 * dinv, M22 = m22 * dinv;
    }
    else
    {
        *det = d;
        M00 = m00, M01 = m10, M02 = m20;
        M10 = m01, M11 = m11, M12 = m21;
        M20 = m02, M21 = m12, M22 = m22;
    }

#undef M00
#undef M01
#undef M02
#undef M10
#undef M11
#undef M12
#undef M20
#undef M21
#undef M22

#undef A
#undef B
#undef C
#undef D
#undef E
#undef F
#undef G
#undef H
#undef I
}

/* ...get inverse of major minor of 4x4 matrix */
#if 0
static inline void __mat4x4_min3x3_inv(const __mat4x4 a, __mat3x3 b, __scalar *det)
{
    __matNxN_min3x3_inv(4, a, b, det);
}
#else
#define __mat4x4_min3x3_inv(a, b, det)  __matNxN_min3x3_inv(4, (a), (b), (det))
#endif

/* ...don't need anything except for this yet */
static inline void __mat3x3_inv(const __mat3x3 a, __mat3x3 b, __scalar *det)
{
#define A   __M(3, a, 0, 0)
#define B   __M(3, a, 0, 1)
#define C   __M(3, a, 0, 2)
#define D   __M(3, a, 1, 0)
#define E   __M(3, a, 1, 1)
#define F   __M(3, a, 1, 2)
#define G   __M(3, a, 2, 0)
#define H   __M(3, a, 2, 1)
#define I   __M(3, a, 2, 2)

#define M00 __M(3, b, 0, 0)
#define M01 __M(3, b, 0, 1)
#define M02 __M(3, b, 0, 2)
#define M10 __M(3, b, 1, 0)
#define M11 __M(3, b, 1, 1)
#define M12 __M(3, b, 1, 2)
#define M20 __M(3, b, 2, 0)
#define M21 __M(3, b, 2, 1)
#define M22 __M(3, b, 2, 2)

    __MATH_FLOAT    m00 = E * I - F * H;
    __MATH_FLOAT    m01 = F * G - D * I;
    __MATH_FLOAT    m02 = D * H - E * G;
    __MATH_FLOAT    m10 = C * H - B * I;
    __MATH_FLOAT    m11 = A * I - C * G;
    __MATH_FLOAT    m12 = B * G - A * H;
    __MATH_FLOAT    m20 = B * F - C * E;
    __MATH_FLOAT    m21 = C * D - A * F;
    __MATH_FLOAT    m22 = A * E - B * D;
    __MATH_FLOAT    d = A * m00 + B * m01 + C * m02;

    if (det == NULL)
    {
        __MATH_FLOAT    dinv = __scalar_inv(d);

        M00 = m00 * dinv, M01 = m10 * dinv, M02 = m20 * dinv;
        M10 = m01 * dinv, M11 = m11 * dinv, M12 = m21 * dinv;
        M20 = m02 * dinv, M21 = m12 * dinv, M22 = m22 * dinv;
    }
    else
    {
        *det = d;
        M00 = m00, M01 = m10, M02 = m20;
        M10 = m01, M11 = m11, M12 = m21;
        M20 = m02, M21 = m12, M22 = m22;
    }

#undef M00
#undef M01
#undef M02
#undef M10
#undef M11
#undef M12
#undef M20
#undef M21
#undef M22

#undef A
#undef B
#undef C
#undef D
#undef E
#undef F
#undef G
#undef H
#undef I
}

/* ...inversion of 4x4 matrix */
static inline void __mat4x4_inv(const __mat4x4 a, __mat4x4 b, __scalar *det)
{
#define m00 __M(4, a, 0, 0)
#define m01 __M(4, a, 0, 1)
#define m02 __M(4, a, 0, 2)
#define m03 __M(4, a, 0, 3)
#define m10 __M(4, a, 1, 0)
#define m11 __M(4, a, 1, 1)
#define m12 __M(4, a, 1, 2)
#define m13 __M(4, a, 1, 3)
#define m20 __M(4, a, 2, 0)
#define m21 __M(4, a, 2, 1)
#define m22 __M(4, a, 2, 2)
#define m23 __M(4, a, 2, 3)
#define m30 __M(4, a, 3, 0)
#define m31 __M(4, a, 3, 1)
#define m32 __M(4, a, 3, 2)
#define m33 __M(4, a, 3, 3)

#define M00 __M(4, b, 0, 0)
#define M01 __M(4, b, 0, 1)
#define M02 __M(4, b, 0, 2)
#define M03 __M(4, b, 0, 3)
#define M10 __M(4, b, 1, 0)
#define M11 __M(4, b, 1, 1)
#define M12 __M(4, b, 1, 2)
#define M13 __M(4, b, 1, 3)
#define M20 __M(4, b, 2, 0)
#define M21 __M(4, b, 2, 1)
#define M22 __M(4, b, 2, 2)
#define M23 __M(4, b, 2, 3)
#define M30 __M(4, b, 3, 0)
#define M31 __M(4, b, 3, 1)
#define M32 __M(4, b, 3, 2)
#define M33 __M(4, b, 3, 3)

    __MATH_FLOAT    _M00 = m12 * m23 * m31 - m13 * m22 * m31 + m13 * m21 * m32 - m11 * m23 * m32 - m12 * m21 * m33 + m11 * m22 * m33;
    __MATH_FLOAT    _M01 = m03 * m22 * m31 - m02 * m23 * m31 - m03 * m21 * m32 + m01 * m23 * m32 + m02 * m21 * m33 - m01 * m22 * m33;
    __MATH_FLOAT    _M02 = m02 * m13 * m31 - m03 * m12 * m31 + m03 * m11 * m32 - m01 * m13 * m32 - m02 * m11 * m33 + m01 * m12 * m33;
    __MATH_FLOAT    _M03 = m03 * m12 * m21 - m02 * m13 * m21 - m03 * m11 * m22 + m01 * m13 * m22 + m02 * m11 * m23 - m01 * m12 * m23;
    __MATH_FLOAT    _M10 = m13 * m22 * m30 - m12 * m23 * m30 - m13 * m20 * m32 + m10 * m23 * m32 + m12 * m20 * m33 - m10 * m22 * m33;
    __MATH_FLOAT    _M11 = m02 * m23 * m30 - m03 * m22 * m30 + m03 * m20 * m32 - m00 * m23 * m32 - m02 * m20 * m33 + m00 * m22 * m33;
    __MATH_FLOAT    _M12 = m03 * m12 * m30 - m02 * m13 * m30 - m03 * m10 * m32 + m00 * m13 * m32 + m02 * m10 * m33 - m00 * m12 * m33;
    __MATH_FLOAT    _M13 = m02 * m13 * m20 - m03 * m12 * m20 + m03 * m10 * m22 - m00 * m13 * m22 - m02 * m10 * m23 + m00 * m12 * m23;
    __MATH_FLOAT    _M20 = m11 * m23 * m30 - m13 * m21 * m30 + m13 * m20 * m31 - m10 * m23 * m31 - m11 * m20 * m33 + m10 * m21 * m33;
    __MATH_FLOAT    _M21 = m03 * m21 * m30 - m01 * m23 * m30 - m03 * m20 * m31 + m00 * m23 * m31 + m01 * m20 * m33 - m00 * m21 * m33;
    __MATH_FLOAT    _M22 = m01 * m13 * m30 - m03 * m11 * m30 + m03 * m10 * m31 - m00 * m13 * m31 - m01 * m10 * m33 + m00 * m11 * m33;
    __MATH_FLOAT    _M23 = m03 * m11 * m20 - m01 * m13 * m20 - m03 * m10 * m21 + m00 * m13 * m21 + m01 * m10 * m23 - m00 * m11 * m23;
    __MATH_FLOAT    _M30 = m12 * m21 * m30 - m11 * m22 * m30 - m12 * m20 * m31 + m10 * m22 * m31 + m11 * m20 * m32 - m10 * m21 * m32;
    __MATH_FLOAT    _M31 = m01 * m22 * m30 - m02 * m21 * m30 + m02 * m20 * m31 - m00 * m22 * m31 - m01 * m20 * m32 + m00 * m21 * m32;
    __MATH_FLOAT    _M32 = m02 * m11 * m30 - m01 * m12 * m30 - m02 * m10 * m31 + m00 * m12 * m31 + m01 * m10 * m32 - m00 * m11 * m32;
    __MATH_FLOAT    _M33 = m01 * m12 * m20 - m02 * m11 * m20 + m02 * m10 * m21 - m00 * m12 * m21 - m01 * m10 * m22 + m00 * m11 * m22;

    /* ...use first column; probably I should use last column instead - tbd */
    __MATH_FLOAT    d = _M00 * m00 + _M01 * m10 + _M02 * m20 + _M03 * m30;

    if (det == NULL)
    {
        __MATH_FLOAT    dinv = __scalar_inv(d);

        M00 = _M00 * dinv, M01 = _M01 * dinv, M02 = _M02 * dinv, M03 = _M03 * dinv;
        M10 = _M10 * dinv, M11 = _M11 * dinv, M12 = _M12 * dinv, M13 = _M13 * dinv;
        M20 = _M20 * dinv, M21 = _M21 * dinv, M22 = _M22 * dinv, M23 = _M23 * dinv;
        M30 = _M30 * dinv, M31 = _M31 * dinv, M32 = _M32 * dinv, M33 = _M33 * dinv;
    }
    else
    {
        *det = d;
        M00 = _M00, M01 = _M01, M02 = _M02, M03 = _M03;
        M10 = _M10, M11 = _M11, M12 = _M12, M13 = _M13;
        M20 = _M20, M21 = _M21, M22 = _M22, M23 = _M23;
        M30 = _M30, M31 = _M31, M32 = _M32, M33 = _M33;
    }

#undef  m00
#undef  m01
#undef  m02
#undef  m03
#undef  m10
#undef  m11
#undef  m12
#undef  m13
#undef  m20
#undef  m21
#undef  m22
#undef  m23
#undef  m30
#undef  m31
#undef  m32
#undef  m33

#undef  M00
#undef  M01
#undef  M02
#undef  M03
#undef  M10
#undef  M11
#undef  M12
#undef  M13
#undef  M20
#undef  M21
#undef  M22
#undef  M23
#undef  M30
#undef  M31
#undef  M32
#undef  M33
}

static inline float __mat4x4_3x3_det(const float *a)
{
#define A   __M(4, a, 0, 0)
#define B   __M(4, a, 0, 1)
#define C   __M(4, a, 0, 2)
#define D   __M(4, a, 1, 0)
#define E   __M(4, a, 1, 1)
#define F   __M(4, a, 1, 2)
#define G   __M(4, a, 2, 0)
#define H   __M(4, a, 2, 1)
#define I   __M(4, a, 2, 2)


    __MATH_FLOAT    m00 = E * I - F * H;
    __MATH_FLOAT    m01 = F * G - D * I;
    __MATH_FLOAT    m02 = D * H - E * G;
    __MATH_FLOAT    m10 = C * H - B * I;
    __MATH_FLOAT    m11 = A * I - C * G;
    __MATH_FLOAT    m12 = B * G - A * H;
    __MATH_FLOAT    m20 = B * F - C * E;
    __MATH_FLOAT    m21 = C * D - A * F;
    __MATH_FLOAT    m22 = A * E - B * D;
    __MATH_FLOAT    d = A * m00 + B * m01 + C * m02;

#undef A
#undef B
#undef C
#undef D
#undef E
#undef F
#undef G
#undef H
#undef I

    return d;
}


/*******************************************************************************
 * Matrix dump
 ******************************************************************************/

static inline void __matNxN_dump(const int N, const __MATH_FLOAT *m, const char *tag)
{
    int     i, j;
    char    buffer[256], *p;

    for (i = 0; i < N; i++)
    {
        p = buffer + sprintf(buffer, "%s[%d]: ", tag, i);

        for (j = 0; j < N; j++)
            p += sprintf(p, "%f ", *m++);

        TRACE(1, _b("%s"), buffer);
    }
}

static inline void __mat2x2_dump(const __mat2x2 m, const char *tag)
{
    __matNxN_dump(2, m, tag);
}

static inline void __mat3x3_dump(const __mat3x3 m, const char *tag)
{
    __matNxN_dump(3, m, tag);
}

static inline void __mat4x4_dump(const __mat4x4 m, const char *tag)
{
    __matNxN_dump(4, m, tag);
}

/*******************************************************************************
 * Projective transformation
 ******************************************************************************/

static inline void __proj3_div(const __vec4 a, __vec2 b)
{
    __scalar    z;

    /* ...get inverse of "w" */
    z = __scalar_inv(a[3]);

    /* ...store projection coordinates */
    b[0] = a[0] * z, b[1] = a[1] * z;
}

static inline void __proj3_mul(const __mat4x4 m, const __vec3 a, __vec2 b)
{
    __vec4      B;
    __scalar    z;

    /* ...multiply homogenous vector by matrix */
    __mat4x4_mulvh(m, a, B);

    /* ...apply scaling factor to "z" coordinate */
    z = __scalar_inv(B[3]);

    /* ...store projection coordinates */
    b[0] = B[0] * z, b[1] = B[1] * z;
}

/*******************************************************************************
 * Basic matrix transformations
 ******************************************************************************/

static inline void __mat3x3_rotation(__mat3x3 m, const __vec3 r, const __scalar a)
{
    __mat3x3    t1, t2;

    /* ...set rotation around X: m = Rx */
    __matNxN_rotate(3, m, 1, 2, r[0]);

    /* ...set rotation around Y: t1 = Ry */
    __matNxN_rotate(3, t1, 0, 2, r[1]);

    /* ...multiply: t2 = m * t1 = Rx * Ry */
    __mat3x3_mul(m, t1, t2);

    /* ...set rotation around Z: t1 = Rz */
    __matNxN_rotate(3, t1, 0, 1, r[2]);

    /* ...multiply: m = t2 * t1 = Rx * Ry * Rz */
    __mat3x3_mul(t2, t1, m);

    if (a != __MATH_ONE)
    {
        /* ...multiply: m = a * m = S * Rx * Ry * Rz */
        __matNxN_M_muls(3, 3, m, a, m);
    }
}

static inline void __mat3x3_rot2xyz(__mat3x3 r, __vec3 xyz)
{
    float tmp;

    /* θy= asin(r02), θx= atan2(−r12,r22). θz= atan2(−r01,r00) */
    xyz[0] = __MATH_DEGREES(atan2f(__M(3, r, 1, 2), __M(3, r, 2, 2)));
    xyz[1] = -__MATH_DEGREES(asinf(__M(3, r, 0, 2)));
    xyz[2] = __MATH_DEGREES(atan2f(__M(3, r, 0, 1), __M(3, r, 0, 0)));
}

static inline void __mat4x4_rotation(__mat4x4 m, const __vec3 r, const __scalar a)
{
    __mat4x4    t1, t2;

    /* ...set rotation around X: m = Rx */
    __matNxN_rotate(4, m, 1, 2, r[0]);

    /* ...set rotation around Y: t1 = Ry */
    __matNxN_rotate(4, t1, 0, 2, r[1]);

    /* ...multiply: t2 = m * t1 = Rx * Ry */
    __mat4x4_mul(m, t1, t2);

    /* ...set rotation around Z: t1 = Rz */
    __matNxN_rotate(4, t1, 0, 1, r[2]);

    /* ...multiply: m = t2 * t1 = Rx * Ry * Rz */
    __mat4x4_mul(t2, t1, m);

    if (a != __MATH_ONE)
    {
        /* ...multiply: m = a * m = S * Rx * Ry * Rz */
        __matNxN_M_muls(4, 3, m, a, m);
    }
}

/* ...translation matrix */
static inline void __mat4x4_translation(__mat4x4 m, __scalar x0, __scalar y0, __scalar z0)
{
    __mat4x4_identity(m);
    __M(4, m, 0, 3) = x0;
    __M(4, m, 1, 3) = y0;
    __M(4, m, 2, 3) = z0;
}

/*******************************************************************************
 * Perspective projection matrix generation
 ******************************************************************************/

static inline void __mat4x4_perspective(__mat4x4 m, __scalar fov, __scalar ratio, __scalar z0, __scalar z1)
{
    __MATH_FLOAT    t = __MATH_TAN(__MATH_RADIANS(fov / 2));

    __matNxN_zero(4, m);

    __M(4, m, 0, 0) = 1.0 / (ratio * t);
    __M(4, m, 1, 1) = 1.0 / t;
    __M(4, m, 2, 2) = z1 / (z0 - z1);
    __M(4, m, 2, 3) = (z0 * z1) / (z0 - z1);
    __M(4, m, 3, 2) = -1.0;
}

static inline float __vec2_length(const __vec2 in)
{
    return sqrtf(in[0] * in[0] + in[1] * in[1]);
}

static inline float __vec3_length(const __vec3 in)
{
    return sqrtf(in[0] * in[0] + in[1] * in[1] + in[2] * in[2]);
}

static inline void __mat3x3_transpose(__mat3x3 m, __mat3x3 result)
{
    __M(3, result, 0, 0) = __M(3, m, 0, 0);
    __M(3, result, 0, 1) = __M(3, m, 1, 0);
    __M(3, result, 0, 2) = __M(3, m, 2, 0);

    __M(3, result, 1, 0) = __M(3, m, 0, 1);
    __M(3, result, 1, 1) = __M(3, m, 1, 1);
    __M(3, result, 1, 2) = __M(3, m, 2, 1);

    __M(3, result, 2, 0) = __M(3, m, 0, 2);
    __M(3, result, 2, 1) = __M(3, m, 1, 2);
    __M(3, result, 2, 2) = __M(3, m, 2, 2);
}

/* ...initialize 3-vector */
static inline void __vec3_set(__vec3 v, __scalar x, __scalar y, __scalar z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}

/* ...initialize 4-vector */
static inline void __vec4_set(__vec4 v, __scalar x, __scalar y, __scalar z,  __scalar w)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = w;
}

#endif  /* __MATH_HELPERS_H */
