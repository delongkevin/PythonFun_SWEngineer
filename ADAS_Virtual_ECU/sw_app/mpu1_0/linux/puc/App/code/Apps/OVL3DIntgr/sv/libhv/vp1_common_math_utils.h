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
 *  @file           vp1_common_math_utils.h
 *  @brief          Common math functions
 *
 *  @version        1.01
 *  @author         Evgeniy Rzhevskiy & Alex Orlov
 *  @date           09.08.2019
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

#ifndef VP1_COMMON_MATH_UTILS
#define VP1_COMMON_MATH_UTILS


#ifdef __cplusplus
extern "C" {
#endif


#include <errno.h>

#include <ctype.h> /* Header file for isdigit */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
//#include "vp1_math_types.h"
//#include "vp1_internal_types.h"

#define VPS_MIN(a, b)  ( ( ((a)) > ((b)) ) ? ((b)) : ((a)) )
#define VPS_MAX(a, b)  ( ( ((a)) < ((b)) ) ? ((b)) : ((a)) )

#define VP_M_PI 3.14159265358979323846f /* pi */
#define VP_M_PI2 6.283185307179586f

#define DEG2RAD (VP_M_PI / 180.0f)
#define RAD2DEG (180.0f / VP_M_PI)


#define CSH_TEXTURE_RESOLUTION 256
#define CSH_TEXTURE_FILLED 64
#define CSH_TEXTURE_QUAD_SIDE (CSH_TEXTURE_FILLED * 2)
#define CSH_DEFAULT_SCALE 0.2f
#define CSH_CURRENT_SCALE (CSH_DEFAULT_SCALE / ((float32_t)CSH_TEXTURE_RESOLUTION / (float32_t)CSH_TEXTURE_QUAD_SIDE))

// #define DEG2RAD (M_PI/180.0)
// #define RAD2DEG (180.0/M_PI)

#define EPS_F     ((float32_t)(FLT_EPSILON))

#define SIGN(a)  (((a) > 0.f) ? (1): (-1))



static inline float32_t clamp_f32(float32_t a, float32_t minv, float32_t maxv)
{
    a = VPS_MAX(a, minv); 
    a = VPS_MIN(a, maxv);
    return a; 
}

static inline mat33f_t eye33(void)
{
    mat33f_t mat = {0};
    mat.elem[0][0] = 1.0f;
    mat.elem[1][1] = 1.0f;
    mat.elem[2][2] = 1.0f;
    return mat;
}

static inline mat44f_t eye44(void)
{
    mat44f_t mat = {0};
    mat.elem[0][0] = 1.0f;
    mat.elem[1][1] = 1.0f;
    mat.elem[2][2] = 1.0f;
    mat.elem[3][3] = 1.0f;
    return mat;
}

static inline float32_t to_01_diap(float32_t in)
{
    return 0.5f * (in + 1.f);
}

static inline mat33f_t eye33_f(void)
{
    mat33f_t mat = {0};
    mat.elem[0][0] = 1.0f;
    mat.elem[1][1] = 1.0f;
    mat.elem[2][2] = 1.0f;
    return mat;
}

static inline mat44f_t eye44_f(void)
{
    mat44f_t mat = {0};
    mat.elem[0][0] = 1.0f;
    mat.elem[1][1] = 1.0f;
    mat.elem[2][2] = 1.0f;
    mat.elem[3][3] = 1.0f;
    return mat;
}

static inline mat33f_t init_mat33f_t(float32_t a00, float32_t a01, float32_t a02,
    float32_t a10, float32_t a11, float32_t a12,
    float32_t a20, float32_t a21, float32_t a22)
{
    mat33f_t ret;
    ret.elem[0][0] = a00;
    ret.elem[0][1] = a01;
    ret.elem[0][2] = a02;

    ret.elem[1][0] = a10;
    ret.elem[1][1] = a11;
    ret.elem[1][2] = a12;

    ret.elem[2][0] = a20;
    ret.elem[2][1] = a21;
    ret.elem[2][2] = a22;

    return ret;
}


static inline mat33f_t set33_vp(const float32_t* src,  uint32_t src_stride) //$
{
    mat33f_t mat = {0};
    uint32_t i = 0U;
    uint32_t j = 0U;

    {
        for (i = 0; i < 3U; i++)
        {
            for (j = 0; j < 3U; j++)
            {
                mat.elem[i][j] = src[(i * src_stride) + j];
            }
        }
    }

    return mat;
}
//$$
static inline mat33f_t set33(const float32_t* src, uint32_t src_size, uint32_t src_stride)
{
    mat33f_t mat = {0};
    uint32_t i = 0U;
    uint32_t j = 0U;

    if ((src != NULL) && (src_size > 0U))
    {
        for (i = 0; i < 3U; i++)
        {
            for (j = 0; j < 3U; j++)
            {
                mat.elem[i][j] = src[(i * src_stride) + j];
            }
        }
    }

    return mat;
}

static inline mat44f_t set44(const float32_t* src, uint32_t src_size, uint32_t src_stride)
{
    mat44f_t mat = {0};
    uint32_t i = 0U;
    uint32_t j = 0U;

    if ((src != NULL) && (src_size > 0U))
    {
        for (i = 0; i < 4U; i++)
        {
            for (j = 0; j < 4U; j++)
            {
                mat.elem[i][j] = src[(i * src_stride) + j];
            }
        }
    }

    return mat;
}

static inline vec4f_t set4f(float32_t x, float32_t y, float32_t z, float32_t w)
{
    vec4f_t result = {0};
    result.x = x;
    result.y = y;
    result.z = z;
    result.w = w;
    return result;
}

static inline vec3f_t set3f(float32_t x, float32_t y, float32_t z)
{
    vec3f_t result = {0};
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}
//$$
static inline vec3f_t set3(const float32_t src[3])
{
    vec3f_t ret;

    ret.x = src[0];
    ret.y = src[1];
    ret.z = src[2];

    return ret;
}


static inline vec2f_t set2f(float32_t x, float32_t y)
{
    vec2f_t result = {0};
    result.x = x;
    result.y = y;
    return result;
}

static inline mat33f_t transpose(const mat33f_t* src)
{
    mat33f_t dst;

    for (int32_t y = 0; y < 3; y++)
    {
        for (int32_t x = 0; x < 3; x++)
        {
            dst.elem[y][x] = src->elem[x][y];
        }
    }

    return dst;
}

static inline mat33f_t copy_mat(const float32_t* src)
{
    mat33f_t dst;

    for (int32_t y = 0; y < 3; y++)
    {
        for (int32_t x = 0; x < 3; x++)
        {
            dst.elem[y][x] = src[(y * 3) + x];
        }
    }

    return dst;
}

static inline mat44f_t cvt_mat33_to_mat44(const mat33f_t* src)
{
    mat44f_t dst = eye44_f();

    for (int32_t y = 0; y < 3; y++)
    {
        for (int32_t x = 0; x < 3; x++)
        {
            dst.elem[y][x] = src->elem[y][x];
        }
    }

    return dst;
}

static inline mat33f_t cvt_mat44_to_mat33(const mat44f_t* src)
{
    mat33f_t dst;

    for (int32_t y = 0; y < 3; y++)
    {
        for (int32_t x = 0; x < 3; x++)
        {
            dst.elem[y][x] = src->elem[y][x];
        }
    }

    return dst;
}

static inline vec3f_t mul(const mat33f_t mat, const vec3f_t vec)
{
    vec3f_t ret;
    ret.x =  (mat.elem[0][0] * vec.x) + (mat.elem[0][1] * vec.y) + (mat.elem[0][2] * vec.z);
    ret.y =  (mat.elem[1][0] * vec.x) + (mat.elem[1][1] * vec.y) + (mat.elem[1][2] * vec.z);
    ret.z =  (mat.elem[2][0] * vec.x) + (mat.elem[2][1] * vec.y) + (mat.elem[2][2] * vec.z);
    return ret;
}

static inline vec3f_t mul44_vec3(const mat44f_t mat, const vec3f_t vec)
{
    vec3f_t ret;
    ret.x =  (mat.elem[0][0] * vec.x) + (mat.elem[0][1] * vec.y) + (mat.elem[0][2] * vec.z) + mat.elem[0][3];
    ret.y =  (mat.elem[1][0] * vec.x) + (mat.elem[1][1] * vec.y) + (mat.elem[1][2] * vec.z) + mat.elem[1][3];
    ret.z =  (mat.elem[2][0] * vec.x) + (mat.elem[2][1] * vec.y) + (mat.elem[2][2] * vec.z) + mat.elem[2][3];
    float32_t w = (mat.elem[3][0] * vec.x) + (mat.elem[3][1] * vec.y) + (mat.elem[3][2] * vec.z) + mat.elem[3][3];

    w = 1.f / w;

    ret.x *= w;
    ret.y *= w;
    ret.z *= w;

    return ret;
}

static inline vec3f_t mul33_vec3(const mat33f_t mat, const vec3f_t vec)
{
    vec3f_t ret;
    ret.x =  (mat.elem[0][0] * vec.x) + (mat.elem[0][1] * vec.y) + (mat.elem[0][2] * vec.z);
    ret.y =  (mat.elem[1][0] * vec.x) + (mat.elem[1][1] * vec.y) + (mat.elem[1][2] * vec.z);
    ret.z =  (mat.elem[2][0] * vec.x) + (mat.elem[2][1] * vec.y) + (mat.elem[2][2] * vec.z);

    return ret;
}

static inline vec2f_t mul33_vec2(const mat33f_t mat, const vec2f_t vec)
{
    vec2f_t ret;
    ret.x =  (mat.elem[0][0] * vec.x) + (mat.elem[0][1] * vec.y) + (mat.elem[0][2]);
    ret.y =  (mat.elem[1][0] * vec.x) + (mat.elem[1][1] * vec.y) + (mat.elem[1][2]);

    return ret;
}

static inline mat44f_t mul_mat44(const mat44f_t* a, const mat44f_t* b)
{
    int32_t i, j;

    mat44f_t r;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            r.elem[i][j] = (a->elem[i][0]*b->elem[0][j]) +
                           (a->elem[i][1]*b->elem[1][j]) +
                           (a->elem[i][2]*b->elem[2][j]) +
                           (a->elem[i][3]*b->elem[3][j]);
        }
    }

    return r;
}

static inline mat33f_t mul_mat33(const mat33f_t* a, const mat33f_t* b)
{
    int32_t i, j;

    mat33f_t r;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            r.elem[i][j] = (a->elem[i][0] * b->elem[0][j]) +
                           (a->elem[i][1] * b->elem[1][j]) +
                           (a->elem[i][2] * b->elem[2][j]);
        }
    }

    return r;
}

static inline mat33f_t muls_mat33(const mat33f_t* a, const float32_t b)
{
    int32_t i, j;

    mat33f_t r;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            r.elem[i][j] = a->elem[i][j] * b;
        }
    }

    return r;
}

static inline float32_t vp_sqrtf_vp1(float32_t in)
{
    float32_t out = 0.00001f;

    if (in >= 0.0f) {
        out = sqrtf(in);
    }

    return out;
} //$

static inline float32_t vp_sqrtf(float32_t in)
{
    float32_t out = 0.00001f;

    errno = 0;
    out = sqrtf(in);

    if (errno != 0)
    {
        out = 0.00001f;
    }

    return out;
}

static inline float32_t dist_L0_mat33(const mat33f_t* a, const mat33f_t* b)
{
    float32_t dist = 0;
    int32_t i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            dist += fabs( a->elem[i][j] - b->elem[i][j]);
        }
    }

    return dist;
}

static inline mat33f_t mul_mat33_x3(const mat33f_t* a, const mat33f_t* b, const mat33f_t* c)
{
    mat33f_t res;
    res = mul_mat33(a, b);
    res = mul_mat33(&res, c);
    return res;
}

static inline float32_t vp_arctan2f(float32_t a, float32_t b)
{
    float32_t out = 0.0f;

    out = atan2f(a, b);

    return out;
} //$
static inline float32_t vp_atan2f(float32_t a, float32_t b)
{
    float32_t out;

    out = atan2f(a, b);

    return out;
}

static inline float32_t vec_length(float32_t x, float32_t y)
{
    return vp_sqrtf((x*x) + (y*y));
}

static inline float32_t vec3f_length(vec3f_t a)
{
    return vp_sqrtf((a.x * a.x) + (a.y * a.y) + (a.z * a.z));
}

static inline float32_t mat33_det(const mat33f_t a)
{
    return  (((a.elem[0][0] * a.elem[1][1]) * a.elem[2][2]) +
            ((a.elem[1][0] * a.elem[2][1]) * a.elem[0][2]) +
            ((a.elem[2][0] * a.elem[0][1]) * a.elem[1][2])) -
            ((a.elem[0][0] * a.elem[2][1]) * a.elem[1][2]) -
            ((a.elem[2][0] * a.elem[1][1]) * a.elem[0][2]) -
            ((a.elem[1][0] * a.elem[0][1]) * a.elem[2][2]);
}

static inline int32_t mat33_inv(const mat33f_t* a, mat33f_t* b)
{
    float32_t det = mat33_det(*a);
    int32_t res = 0;

    if (det != 0.0f)
    {
        b->elem[0][0] = ((a->elem[1][1] * a->elem[2][2]) - (a->elem[1][2] * a->elem[2][1])) / det;
        b->elem[0][1] = ((a->elem[0][2] * a->elem[2][1]) - (a->elem[0][1] * a->elem[2][2])) / det;
        b->elem[0][2] = ((a->elem[0][1] * a->elem[1][2]) - (a->elem[0][2] * a->elem[1][1])) / det;

        b->elem[1][0] = ((a->elem[1][2] * a->elem[2][0]) - (a->elem[1][0] * a->elem[2][2])) / det;
        b->elem[1][1] = ((a->elem[0][0] * a->elem[2][2]) - (a->elem[0][2] * a->elem[2][0])) / det;
        b->elem[1][2] = ((a->elem[0][2] * a->elem[1][0]) - (a->elem[0][0] * a->elem[1][2])) / det;

        b->elem[2][0] = ((a->elem[1][0] * a->elem[2][1]) - (a->elem[1][1] * a->elem[2][0])) / det;
        b->elem[2][1] = ((a->elem[0][1] * a->elem[2][0]) - (a->elem[0][0] * a->elem[2][1])) / det;
        b->elem[2][2] = ((a->elem[0][0] * a->elem[1][1]) - (a->elem[0][1] * a->elem[1][0])) / det;
    }
    else
    {
        res = -1;
    }

    return res;
}
//$
static inline int32_t mat33_inv_vp(const mat33f_t a, mat33f_t *b)
{
    float32_t det = mat33_det(a);
    int32_t res = 0;

    if (det != 0.0f)
    {
        b->elem[0][0] = ((a.elem[1][1] * a.elem[2][2]) - (a.elem[1][2] * a.elem[2][1])) / det;
        b->elem[0][1] = ((a.elem[0][2] * a.elem[2][1]) - (a.elem[0][1] * a.elem[2][2])) / det;
        b->elem[0][2] = ((a.elem[0][1] * a.elem[1][2]) - (a.elem[0][2] * a.elem[1][1])) / det;

        b->elem[1][0] = ((a.elem[1][2] * a.elem[2][0]) - (a.elem[1][0] * a.elem[2][2])) / det;
        b->elem[1][1] = ((a.elem[0][0] * a.elem[2][2]) - (a.elem[0][2] * a.elem[2][0])) / det;
        b->elem[1][2] = ((a.elem[0][2] * a.elem[1][0]) - (a.elem[0][0] * a.elem[1][2])) / det;

        b->elem[2][0] = ((a.elem[1][0] * a.elem[2][1]) - (a.elem[1][1] * a.elem[2][0])) / det;
        b->elem[2][1] = ((a.elem[0][1] * a.elem[2][0]) - (a.elem[0][0] * a.elem[2][1])) / det;
        b->elem[2][2] = ((a.elem[0][0] * a.elem[1][1]) - (a.elem[0][1] * a.elem[1][0])) / det;
    }
    else
    {
        res = -1;
    }

    return res;
}

static inline mat44f_t invert_mat44(const mat44f_t* m)
{
    mat44f_t ret;

    float32_t inv[4][4], det;
    uint32_t i,j;

    inv[0][0] = (((m->elem[1][1] * m->elem[2][2] * m->elem[3][3]) -
                 ((m->elem[1][1] * m->elem[2][3]) * m->elem[3][2]) -
                 ((m->elem[2][1] * m->elem[1][2]) * m->elem[3][3]) -
                 ((m->elem[3][1] * m->elem[1][3]) * m->elem[2][2])) +
                 (((m->elem[2][1] * m->elem[1][3]) * m->elem[3][2]) +
                 ((m->elem[3][1] * m->elem[1][2]) * m->elem[2][3])));
    inv[1][0] = ((((-m->elem[1][0] * m->elem[2][2]) * m->elem[3][3]) +
                  ((m->elem[1][0] * m->elem[2][3]) * m->elem[3][2]) +
                  ((m->elem[2][0] * m->elem[1][2]) * m->elem[3][3]) +
                  ((m->elem[3][0] * m->elem[1][3]) * m->elem[2][2])) -
                  ((m->elem[2][0] * m->elem[1][3]) * m->elem[3][2]) -
                  ((m->elem[3][0] * m->elem[1][2]) * m->elem[2][3]));
    inv[2][0] = ((((m->elem[1][0] * m->elem[2][1]) * m->elem[3][3]) -
                 ((m->elem[1][0] * m->elem[2][3]) * m->elem[3][1]) -
                 ((m->elem[2][0] * m->elem[1][1]) * m->elem[3][3]) -
                 ((m->elem[3][0] * m->elem[1][3]) * m->elem[2][1])) +
                 ((m->elem[2][0] * m->elem[1][3]) * m->elem[3][1]) +
                 ((m->elem[3][0] * m->elem[1][1]) * m->elem[2][3]));
    inv[3][0] = ((((-m->elem[1][0] * m->elem[2][1]) * m->elem[3][2]) +
                  ((m->elem[1][0] * m->elem[2][2]) * m->elem[3][1]) +
                  ((m->elem[2][0] * m->elem[1][1]) * m->elem[3][2]) +
                  ((m->elem[3][0] * m->elem[1][2]) * m->elem[2][1])) -
                  ((m->elem[2][0] * m->elem[1][2]) * m->elem[3][1]) -
                  ((m->elem[3][0] * m->elem[1][1]) * m->elem[2][2]));
    inv[0][1] = ((((-m->elem[0][1] * m->elem[2][2]) * m->elem[3][3]) +
                  ((m->elem[0][1] * m->elem[2][3]) * m->elem[3][2]) +
                  ((m->elem[2][1] * m->elem[0][2]) * m->elem[3][3]) +
                  ((m->elem[3][1] * m->elem[0][3]) * m->elem[2][2])) -
                  ((m->elem[2][1] * m->elem[0][3]) * m->elem[3][2]) -
                  ((m->elem[3][1] * m->elem[0][2]) * m->elem[2][3]));
    inv[1][1] = ((((m->elem[0][0] * m->elem[2][2]) * m->elem[3][3]) -
                 ((m->elem[0][0] * m->elem[2][3]) * m->elem[3][2]) -
                 ((m->elem[2][0] * m->elem[0][2]) * m->elem[3][3]) -
                 ((m->elem[3][0] * m->elem[0][3]) * m->elem[2][2])) +
                 ((m->elem[2][0] * m->elem[0][3]) * m->elem[3][2]) +
                 ((m->elem[3][0] * m->elem[0][2]) * m->elem[2][3]));
    inv[2][1] = ((((-m->elem[0][0] * m->elem[2][1]) * m->elem[3][3]) +
                  ((m->elem[0][0] * m->elem[2][3]) * m->elem[3][1]) +
                  ((m->elem[2][0] * m->elem[0][1]) * m->elem[3][3]) +
                  ((m->elem[3][0] * m->elem[0][3]) * m->elem[2][1])) -
                  ((m->elem[2][0] * m->elem[0][3]) * m->elem[3][1]) -
                  ((m->elem[3][0] * m->elem[0][1]) * m->elem[2][3]));
    inv[3][1] = ((((m->elem[0][0] * m->elem[2][1]) * m->elem[3][2]) -
                 ((m->elem[0][0] * m->elem[2][2]) * m->elem[3][1]) -
                 ((m->elem[2][0] * m->elem[0][1]) * m->elem[3][2]) -
                 ((m->elem[3][0] * m->elem[0][2]) * m->elem[2][1])) +
                 ((m->elem[2][0] * m->elem[0][2]) * m->elem[3][1]) +
                 ((m->elem[3][0] * m->elem[0][1]) * m->elem[2][2]));
    inv[0][2] = ((((m->elem[0][1] * m->elem[1][2]) * m->elem[3][3]) -
                 ((m->elem[0][1] * m->elem[1][3]) * m->elem[3][2]) -
                 ((m->elem[1][1] * m->elem[0][2]) * m->elem[3][3]) -
                 ((m->elem[3][1] * m->elem[0][3]) * m->elem[1][2])) +
                 ((m->elem[1][1] * m->elem[0][3]) * m->elem[3][2]) +
                 ((m->elem[3][1] * m->elem[0][2]) * m->elem[1][3]));
    inv[1][2] = ((((-m->elem[0][0] * m->elem[1][2]) * m->elem[3][3]) +
                  ((m->elem[0][0] * m->elem[1][3]) * m->elem[3][2]) +
                  ((m->elem[1][0] * m->elem[0][2]) * m->elem[3][3]) +
                  ((m->elem[3][0] * m->elem[0][3]) * m->elem[1][2])) -
                  ((m->elem[1][0] * m->elem[0][3]) * m->elem[3][2]) -
                  ((m->elem[3][0] * m->elem[0][2]) * m->elem[1][3]));
    inv[2][2] = ((((m->elem[0][0] * m->elem[1][1]) * m->elem[3][3]) -
                 ((m->elem[0][0] * m->elem[1][3]) * m->elem[3][1]) -
                 ((m->elem[1][0] * m->elem[0][1]) * m->elem[3][3]) -
                 ((m->elem[3][0] * m->elem[0][3]) * m->elem[1][1])) +
                 ((m->elem[1][0] * m->elem[0][3]) * m->elem[3][1]) +
                 ((m->elem[3][0] * m->elem[0][1]) * m->elem[1][3]));
    inv[3][2] = ((((-m->elem[0][0] * m->elem[1][1]) * m->elem[3][2]) +
                  ((m->elem[0][0] * m->elem[1][2]) * m->elem[3][1]) +
                  ((m->elem[1][0] * m->elem[0][1]) * m->elem[3][2]) +
                  ((m->elem[3][0] * m->elem[0][2]) * m->elem[1][1])) -
                  ((m->elem[1][0] * m->elem[0][2]) * m->elem[3][1]) -
                  ((m->elem[3][0] * m->elem[0][1]) * m->elem[1][2]));
    inv[0][3] = ((((-m->elem[0][1] * m->elem[1][2]) * m->elem[2][3]) +
                  ((m->elem[0][1] * m->elem[1][3]) * m->elem[2][2]) +
                  ((m->elem[1][1] * m->elem[0][2]) * m->elem[2][3]) +
                  ((m->elem[2][1] * m->elem[0][3]) * m->elem[1][2])) -
                  ((m->elem[1][1] * m->elem[0][3]) * m->elem[2][2]) -
                  ((m->elem[2][1] * m->elem[0][2]) * m->elem[1][3]));
    inv[1][3] = ((((m->elem[0][0] * m->elem[1][2]) * m->elem[2][3]) -
                 ((m->elem[0][0] * m->elem[1][3]) * m->elem[2][2]) -
                 ((m->elem[1][0] * m->elem[0][2]) * m->elem[2][3]) -
                 ((m->elem[2][0] * m->elem[0][3]) * m->elem[1][2])) +
                 ((m->elem[1][0] * m->elem[0][3]) * m->elem[2][2]) +
                 ((m->elem[2][0] * m->elem[0][2]) * m->elem[1][3]));
    inv[2][3] = ((((-m->elem[0][0] * m->elem[1][1]) * m->elem[2][3]) +
                  ((m->elem[0][0] * m->elem[1][3]) * m->elem[2][1]) +
                  ((m->elem[1][0] * m->elem[0][1]) * m->elem[2][3]) +
                  ((m->elem[2][0] * m->elem[0][3]) * m->elem[1][1])) -
                  ((m->elem[1][0] * m->elem[0][3]) * m->elem[2][1]) -
                  ((m->elem[2][0] * m->elem[0][1]) * m->elem[1][3]));
    inv[3][3] = ((((m->elem[0][0] * m->elem[1][1]) * m->elem[2][2]) -
                 ((m->elem[0][0] * m->elem[1][2]) * m->elem[2][1]) -
                 ((m->elem[1][0] * m->elem[0][1]) * m->elem[2][2]) -
                 ((m->elem[2][0] * m->elem[0][2]) * m->elem[1][1])) +
                 ((m->elem[1][0] * m->elem[0][2]) * m->elem[2][1]) +
                 ((m->elem[2][0] * m->elem[0][1]) * m->elem[1][2]));

    det = (m->elem[0][0]*inv[0][0]) + (m->elem[0][1]*inv[1][0]) + (m->elem[0][2]*inv[2][0]) + (m->elem[0][3]*inv[3][0]);
    det = 1.0f / det;

    for (i = 0U; i < 4U; i++)
    {
        for (j = 0U; j < 4U; j++)
        {
            ret.elem[i][j] = (float32_t)(inv[i][j] * det);
        }
    }

    return ret;
}

static inline uint32_t ge2f(const vec2f_t a, const float32_t b)
{
    uint32_t c = 0U;
    c = (a.x >= b) ? 1U : 0U;
    c |= (a.y >= b) ? 1U : 0U;
    return c;
}

static inline uint32_t ge4f(const vec4f_t a, const float32_t b)
{
    uint32_t c = 0U;
    c = (a.x >= b) ? 1U : 0U;
    c |= (a.y >= b) ? 1U : 0U;
    c |= (a.z >= b) ? 1U : 0U;
    c |= (a.w >= b) ? 1U : 0U;
    return c;
}

static inline uint32_t ge_elm4f(const vec4f_t a, const vec4f_t b)
{
    uint32_t c = 0U;
    c = (a.x >= b.x) ? 1U : 0U;
    c |= (a.y >= b.y) ? 1U : 0U;
    c |= (a.z >= b.z) ? 1U : 0U;
    c |= (a.w >= b.w) ? 1U : 0U;
    return c;
}

static inline vec4f_t bsge4f(const vec4f_t a, const vec4f_t b)
{
    vec4f_t c;
    c.x = (a.x >= b.x) ? a.x : -1.0f;
    c.y = (a.y >= b.y) ? a.y : -1.0f;
    c.z = (a.z >= b.z) ? a.z : -1.0f;
    c.w = (a.w >= b.w) ? a.w : -1.0f;
    return c;
}


static inline vec4u32_t bsl4u32(const vec4u32_t a, const uint32_t b, const vec4u32_t c)
{
    vec4u32_t d;
    d.x = (a.x == 1U) ? b : c.x;
    d.y = (a.y == 1U) ? b : c.y;
    d.z = (a.z == 1U) ? b : c.z;
    d.w = (a.w == 1U) ? b : c.w;
    return d;
}

static inline vec4u32_t eq4f(const vec4f_t a, const vec4f_t b)
{
    vec4u32_t c;
    c.x = (a.x == b.x) ? 1U : 0U;
    c.y = (a.y == b.y) ? 1U : 0U;
    c.z = (a.z == b.z) ? 1U : 0U;
    c.w = (a.w == b.w) ? 1U : 0U;
    return c;
}


static inline vec4u32_t cage4f(const vec4f_t a, const vec4f_t b)
{
    vec4u32_t c;
    c.x = (fabsf(a.x) >= fabsf(b.x)) ? 1U : 0U;
    c.y = (fabsf(a.y) >= fabsf(b.y)) ? 1U : 0U;
    c.z = (fabsf(a.z) >= fabsf(b.z)) ? 1U : 0U;
    c.w = (fabsf(a.w) >= fabsf(b.w)) ? 1U : 0U;
    return c;
}


static inline vec4u32_t orr4u32(const vec4u32_t a, const vec4u32_t b)
{
    vec4u32_t c;
    c.x = a.x | b.x;
    c.y = a.y | b.y;
    c.z = a.z | b.z;
    c.w = a.w | b.w;
    return c;
}

static inline uint32_t orr_elm4u32(const vec4u32_t a, const vec4u32_t b)
{
    uint32_t c = 0U;
    c = a.x | b.x;
    c |= (a.y | b.y);
    c |= (a.z | b.z);
    c |= (a.w | b.w);
    return c;
}

static inline mat33f_t mat33_inv_33(const mat33f_t a)
{
    mat33f_t out = eye33();
    (void) mat33_inv(&a, &out);
    return out;
}

static inline vec2f_t add2f(const vec2f_t a, const vec2f_t b)
{
    vec2f_t c;
    c.x = b.x + a.x;
    c.y = b.y + a.y;
    return c;
}

static inline vec2f_t sub2f(const vec2f_t a, const vec2f_t b)
{
    vec2f_t c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

static inline vec3f_t add3f(const vec3f_t a, const vec3f_t b)
{
    vec3f_t c;
    c.x = b.x + a.x;
    c.y = b.y + a.y;
    c.z = b.z + a.z;
    return c;
}

/* compare vector elements to get min values */
static inline vec2f_t min2f(const vec2f_t a, const vec2f_t b)
{
    vec2f_t c;
    c.x = (a.x > b.x) ? b.x : a.x;
    c.y = (a.y > b.y) ? b.y : a.y;
    return c;
}

static inline vec4f_t min4f(const vec4f_t a, const vec4f_t b)
{
    vec4f_t c;
    c.x = (a.x > b.x) ? b.x : a.x;
    c.y = (a.y > b.y) ? b.y : a.y;
    c.z = (a.z > b.z) ? b.z : a.z;
    c.w = (a.w > b.w) ? b.w : a.w;
    return c;
}

/* compare vector elements to get max values */
static inline vec2f_t max2f(const vec2f_t a, const vec2f_t b)
{
    vec2f_t c;
    c.x = (a.x > b.x) ? a.x : b.x;
    c.y = (a.y > b.y) ? a.y : b.y;
    return c;
}

static inline vec4f_t max4f(const vec4f_t a, const vec4f_t b)
{
    vec4f_t c;
    c.x = (a.x > b.x) ? a.x : b.x;
    c.y = (a.y > b.y) ? a.y : b.y;
    c.z = (a.z > b.z) ? a.z : b.z;
    c.w = (a.w > b.w) ? a.w : b.w;
    return c;
}

static inline vec2f_t mla2f(const vec2f_t a, const vec2f_t b, const vec2f_t c)
{
    vec2f_t d;
    d.x = a.x + (b.x * c.x);
    d.y = a.y + (b.y * c.y);
    return d;
}

static inline float32_t det2f(const vec2f_t a, const vec2f_t b)
{
    float32_t c;
    c = (a.x * b.y) - (a.y * b.x);
    return c;
}

static inline vec3f_t sub3f(const vec3f_t a, const vec3f_t b)
{
    vec3f_t c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
    return c;
}

static inline vec4f_t sub4f(const vec4f_t a, const vec4f_t b)
{
    vec4f_t c;
    c.x = b.x - a.x;
    c.y = b.y - a.y;
    c.z = b.z - a.z;
    c.w = b.w - a.w;
    return c;
}

static inline vec4f_t add4f(const vec4f_t a, const vec4f_t b)
{
    vec4f_t c;
    c.x = b.x + a.x;
    c.y = b.y + a.y;
    c.z = b.z + a.z;
    c.w = b.w + a.w;
    return c;
}

static inline vec3f_t mla3f(const vec3f_t a, const vec3f_t b, const vec3f_t c)
{
    vec3f_t d;
    d.x = a.x + (b.x * c.x);
    d.y = a.y + (b.y * c.y);
    d.z = a.z + (b.z * c.z);
    return d;
}

static inline vec4f_t mla4f(const vec4f_t a, const vec4f_t b, const vec4f_t c)
{
    vec4f_t d;
    d.x = a.x + (b.x * c.x);
    d.y = a.y + (b.y * c.y);
    d.z = a.z + (b.z * c.z);
    d.w = a.w + (b.w * c.w);
    return d;
}

static inline vec4f_t mls4f(const vec4f_t a, const vec4f_t b, const vec4f_t c)
{
    vec4f_t d;
    d.x = a.x - (b.x * c.x);
    d.y = a.y - (b.y * c.y);
    d.z = a.z - (b.z * c.z);
    d.w = a.w - (b.w * c.w);
    return d;
}

static inline vec2f_t mul2f(const vec2f_t a, const vec2f_t b)
{
    vec2f_t c;
    c.x = b.x * a.x;
    c.y = b.y * a.y;
    return c;
}

static inline vec3f_t mul3f(const vec3f_t a, const vec3f_t b)
{
    vec3f_t c;
    c.x = b.x * a.x;
    c.y = b.y * a.y;
    c.z = b.z * a.z;
    return c;
}

static inline vec4f_t mul4f(const vec4f_t a, const vec4f_t b)
{
    vec4f_t c;
    c.x = b.x * a.x;
    c.y = b.y * a.y;
    c.z = b.z * a.z;
    c.w = b.w * a.w;
    return c;
}

static inline vec2f_t muls2f(const vec2f_t a, const float32_t b)
{
    vec2f_t c;
    c.x = a.x * b;
    c.y = a.y * b;
    return c;
}

static inline vec3f_t muls3f(const vec3f_t a, const float32_t b)
{
    vec3f_t c;
    c.x = a.x * b;
    c.y = a.y * b;
    c.z = a.z * b;
    return c;
}

static inline vec4f_t muls4f(const vec4f_t a, const float32_t b)
{
    vec4f_t c;
    c.x = a.x * b;
    c.y = a.y * b;
    c.z = a.z * b;
    c.w = a.w * b;
    return c;
}

static inline vec4u32_t muls4u32(const vec4u32_t a, const uint32_t b)
{
    vec4u32_t c;
    c.x = a.x * b;
    c.y = a.y * b;
    c.z = a.z * b;
    c.w = a.w * b;
    return c;
}

/* absolute difference between vectors*/
static inline vec4f_t abd4f(const vec4f_t a, const vec4f_t b)
{
    vec4f_t c;
    c.x = fabsf(a.x - b.x);
    c.y = fabsf(a.y - b.y);
    c.z = fabsf(a.z - b.z);
    c.w = fabsf(a.w - b.w);
    return c;
}

static inline void mat33f_rot_x(mat33f_t* m, float32_t ang)
{
    *m = eye33_f();
    float32_t c = cosf(ang);
    float32_t s = sinf(ang);
    m->elem[1][1] = c;
    m->elem[1][2] = -s;
    m->elem[2][1] = s;
    m->elem[2][2] = c;
}

static inline void mat33f_rot_y(mat33f_t* m, float32_t ang)
{
    *m = eye33_f();
    float32_t c = cosf(ang);
    float32_t s = sinf(ang);
    m->elem[0][0] = c;
    m->elem[0][2] = s;
    m->elem[2][0] = -s;
    m->elem[2][2] = c;
}

static inline void mat33f_rot_z(mat33f_t* m, float32_t ang)
{
    *m = eye33();
    float32_t c = cosf(ang);
    float32_t s = sinf(ang);
    m->elem[0][0] = c;
    m->elem[0][1] = -s;
    m->elem[1][0] = s;
    m->elem[1][1] = c;
} //$ vp direction

// static inline void mat33f_rot_z(mat33f_t* m, float32_t ang)
// {
//     *m = eye33_f();
//     float32_t c = cosf(ang);
//     float32_t s = sinf(ang);
//     m->elem[0][0] = c;
//     m->elem[0][1] = s;
//     m->elem[1][0] = -s;
//     m->elem[1][1] = c;
// } //$ vp1 (another direction)
//$$
static inline mat33f_t mat33f_rot_xyz(float32_t ang_z, float32_t ang_y, float32_t ang_x)
{
    mat33f_t res;
    mat33f_t rot_x;
    mat33f_t rot_y;
    mat33f_t rot_z;
    mat33f_rot_x(&rot_x, ang_x);
    mat33f_rot_y(&rot_y, ang_y);
    mat33f_rot_z(&rot_z, ang_z);
    res = mul_mat33_x3(&rot_x, &rot_y, &rot_z);
    return res;
}

static inline void mat44f_set_translation(mat44f_t* m, float32_t x, float32_t y, float32_t z)
{
    m->elem[0][3] = x;
    m->elem[1][3] = y;
    m->elem[2][3] = z;
}

static inline vec3f_t mat44f_get_translation(const mat44f_t* m)
{
    vec3f_t t;
    t.x = m->elem[0][3];
    t.y = m->elem[1][3];
    t.z = m->elem[2][3];
    return t;
}

static inline vec3f_t cross(const vec3f_t* v1, const vec3f_t* v2)
{
    vec3f_t result;
    result.x = (v1->y * v2->z) - (v1->z * v2->y);
    result.y = (v1->z * v2->x) - (v1->x * v2->z);
    result.z = (v1->x * v2->y) - (v1->y * v2->x);

    return result;
}

static inline vec4f_t get_row_mat44f(const mat44f_t* m, uint32_t row)
{
    vec4f_t r;

    r.x = m->elem[row][0];
    r.y = m->elem[row][1];
    r.z = m->elem[row][2];
    r.w = m->elem[row][3];

    return r;
}

static inline float32_t dot_vec2f_vp1(const vec2f_t* v1, const vec2f_t* v2)
{
    return ((v1->x * v2->x) + (v1->y * v2->y));
}

static inline float32_t dot_vec3f_vp1(const vec3f_t* v1, const vec3f_t* v2)
{
    return (v1->x*v2->x) + (v1->y*v2->y) + (v1->z*v2->z);
}

static inline float32_t dot_vec4f_vp1(const vec4f_t* v1, const vec4f_t* v2)
{
    return (v1->x*v2->x) + (v1->y*v2->y) + (v1->z*v2->z) + (v1->w*v2->w);
}

static inline vec3f_t calculate_triangle_center(vec3f_t v0, vec3f_t v1, vec3f_t v2)
{
    vec3f_t result;
    float32_t one_third = 1.0f / 3.0f;
    result = add3f(v0, v1);
    result = add3f(v2, result);
    result = muls3f(result, one_third);
    return result;
}

static inline void make_identity_16f(mat44f_t* m)
{
    m->elem[0][0] = 1.0f; m->elem[1][0] = 0.0f; m->elem[2][0] = 0.0f; m->elem[3][0] = 0.0f;
    m->elem[0][1] = 0.0f; m->elem[1][1] = 1.0f; m->elem[2][1] = 0.0f; m->elem[3][1] = 0.0f;
    m->elem[0][2] = 0.0f; m->elem[1][2] = 0.0f; m->elem[2][2] = 1.0f; m->elem[3][2] = 0.0f;
    m->elem[0][3] = 0.0f; m->elem[1][3] = 0.0f; m->elem[2][3] = 0.0f; m->elem[3][3] = 1.0f;
}


static inline float32_t length3f(const vec3f_t* v)
{
    return vp_sqrtf( (v->x*v->x) + (v->y*v->y) + (v->z*v->z) );
}

static inline float32_t length2f(const vec2f_t* v)
{
    return vp_sqrtf( (v->x*v->x) + (v->y*v->y) );
}

static inline float32_t dist2(const vec3f_t* a, const vec3f_t* b)
{
    vec3f_t c;
    c.x = a->x - b->x;
    c.y = a->y - b->y;
    c.z = a->z - b->z;

    return length3f(&c);
}

static inline float32_t dist2_vec2f(const vec2f_t* a, const vec2f_t* b)
{
    vec2f_t c;
    c.x = a->x - b->x;
    c.y = a->y - b->y;

    return length2f(&c);
}


static inline vec3f_t mix_vec3(const vec3f_t* a, const vec3f_t* b, float32_t alpha)
{
    vec3f_t r;
    r.x = (alpha * (b->x - a->x)) + a->x;
    r.y = (alpha * (b->y - a->y)) + a->y;
    r.z = (alpha * (b->z - a->z)) + a->z;

    return r;
}

static inline vec2f_t mix_vec2(const vec2f_t* a, const vec2f_t* b, float32_t alpha)
{
    vec2f_t r;
    r.x = (alpha * (b->x - a->x)) + a->x;
    r.y = (alpha * (b->y - a->y)) + a->y;

    return r;
}

static inline float32_t normalize_2f(vec2f_t* v)
{
    float32_t r;

    r = vp_sqrtf( (v->x*v->x) + (v->y*v->y));

    if (r != 0.0f)
    {
        v->x /= r;
        v->y /= r;
    }

    return r;
} //$ diff in returned norm

static inline float32_t normalize(vec3f_t* v)
{
    float32_t r;

    r = vp_sqrtf( (v->x*v->x) + (v->y*v->y) + (v->z*v->z) );

    if (r != 0.0f)
    {
        v->x /= r;
        v->y /= r;
        v->z /= r;
    }

    return r;
} //$ diff in returned norm

static inline vec4f_t middle_point4f(vec4f_t a, vec4f_t b)
{
    return muls4f(add4f(a, b), 0.5f);
}

static inline vec3f_t middle_point3f(vec3f_t a, vec3f_t b)
{
    return muls3f(add3f(a, b), 0.5f);
}

static inline void distance_from_point(vec2f_t p,
                                       const vec2f_t *points,
                                       float32_t* distance,
                                       uint32_t n)
{
    for (uint32_t j = 0; j < n; j++) {
        vec2f_t tmp = sub2f(p, points[j]);
        distance[j] = normalize_2f(&tmp);
    }
}

static inline sc_bool_t distance_from_line(vec2f_t p1, vec2f_t p2,
    const vec2f_t *points, float32_t* distance, size_t n)
{
    float32_t x1 = p1.x, x2 = p2.x;
    float32_t y1 = p1.y, y2 = p2.y;
    float32_t dx = x2 - x1;
    float32_t dy = y2 - y1;

    float32_t denominator2 = dx * dx + dy * dy;
    if (denominator2 == 0.0f)
    {
        return SC_FALSE;
    }

    float32_t denominator_inv = 1.0f / sqrtf(denominator2);

    for (size_t j = 0; j < n; j++)
    {
        float32_t x0 = points[j].x;
        float32_t y0 = points[j].y;

        float32_t numerator = fabs(dx * (y1 - y0) - dy * (x1 - x0));
        distance[j] = numerator  * denominator_inv;
    }

    return SC_TRUE;
}

static inline vec2f_t vec2f_from_vec3f(const vec3f_t* in)
{
    float32_t iz = (in->z != 0.f) ? (1.f / in->z) : (1.f / FLT_EPSILON);
    vec2f_t ret = {
        .x = in->x * iz,
        .y = in->y * iz
    };
    return ret;
}

static inline void add_v3f_elements_vec(vec3f_t *a, uint32_t n, const vec3f_t* b)
{
    for (uint32_t i = 0; i < n; i++)
    {
        a[i] = add3f(a[i], *b);
    }
}

static inline rect_float_t cvt_roi_to_float(rect_ui32_t r)
{
    rect_float_t ret;
    ret.x = r.x;
    ret.y = r.y;
    ret.width = r.width;
    ret.height = r.height;

    return ret;
}

static inline void add_triangle_world_point_shift(const vec3f_t* w_point, vec3f_t* local_w_p, vec3f_t shift, const uint32_t* src_index, uint32_t* dst_index, uint32_t size)
{
    uint32_t z = 0;

    for (z = 0; z < size; z++)
    {
        local_w_p[dst_index[z]] = add3f(w_point[src_index[z]], shift);
    }
}

static inline void convert_uyvy_to_nv_16(const uint8_t* p_src, uint8_t* p_dst, uint32_t stride_src, uint32_t stride_dst, uint32_t dst_offset_uv, uint32_t w, uint32_t h)
{
    for(uint32_t y = 0U; y < h; y++)
    {
        const uint8_t* src = &p_src[y*stride_src];
        uint8_t* dst = &p_dst[y*stride_dst];
        uint8_t* dstUV = &p_dst[(y*stride_dst) + dst_offset_uv];
        for (uint32_t x = 0U; x < (w - 1U); x += 2U)
        {
            dst[x] =     src[(x * 2U) + 1U];
            dst[x + 1U] = src[(x * 2U) + 3U];

            dstUV[x] = src[x * 2U];
            dstUV[x + 1U] = src[(x * 2U) + 2U];
        }
    }
}

static inline void copy_nv16_to_nv_16(const uint8_t* p_src, uint8_t* p_dst, uint32_t stride_src, uint32_t stride_dst, uint32_t src_offset_uv, uint32_t dst_offset_uv, uint32_t w, uint32_t h)
{
    for(uint32_t y = 0U; y < h; y++)
    {
        const  uint8_t* src = &p_src[y*stride_src];
        uint8_t* dst = &p_dst[y*stride_dst];
        uint8_t* dstUV = &p_dst[(y*stride_dst) + dst_offset_uv];
        const uint8_t* srcUV = &p_src[(y*stride_src) + src_offset_uv];
        for (uint32_t x = 0U; x < w; x++)
        {
            dst[x] = src[x];
            dstUV[x] = srcUV[x];
        }
    }
}

static inline void convert_uyvy_to_gray(const uint8_t* p_src, uint8_t* p_dst, uint32_t stride_src, uint32_t stride_dst, uint32_t w, uint32_t h)
{
    for(uint32_t y = 0U; y < h; y++)
    {
        const uint8_t* src = &p_src[y*stride_src];
        uint8_t* dst = &p_dst[y*stride_dst];
        for (uint32_t x = 0U; x < (w - 1U); x+= 2U)
        {
            dst[x] =     src[(x * 2U) + 1U];
            dst[x + 1U] = src[(x * 2U) + 3U];
        }
    }
}

static inline void convert_rgba_to_gray(const uint8_t* p_src, uint8_t* p_dst, uint32_t stride_src, uint32_t stride_dst, uint32_t w, uint32_t h)
{
    float32_t k_r = 0.30f; 
    float32_t k_g = 0.59f; 
    float32_t k_b = 0.11f; 

    for(uint32_t y = 0U; y < h; y++)
    {
        const uint8_t* src = &p_src[y*stride_src];
        uint8_t* dst = &p_dst[y*stride_dst];
        for (uint32_t x = 0U; x < (w - 3U); x++)
        {
            dst[x] = (uint8_t)(k_r * src[(x * 4U) + 0U] + k_g * src[(x * 4U) + 1U] + k_b * src[(x * 4U) + 2U]);
        }
    }
}


static inline void world_to_display(vec2f_t*          dst,
                                    const vec3f_t     src,
                                    const mat44f_t    PVM)
{
    vec3f_t     projection;
    projection = mul44_vec3(PVM, src);

    dst->x = projection.x;
    dst->y = projection.y;
}

static inline mat33f_t iso8855_to_cv(vec3f_t xyz)
{
    mat33f_t rotation_matrix = eye33_f();
    mat33f_t axis_replace = {0};
    axis_replace.elem[0][1] = -1.0f;
    axis_replace.elem[1][2] = -1.0f;
    axis_replace.elem[2][0] =  1.0f;

    mat33f_t rot_x;
    mat33f_t rot_y;
    mat33f_t rot_z;
    mat33f_rot_x(&rot_x, -xyz.x * DEG2RAD);
    mat33f_rot_y(&rot_y, -xyz.y * DEG2RAD);
    mat33f_rot_z(&rot_z, -xyz.z * DEG2RAD);
    rotation_matrix = mul_mat33(&rotation_matrix, &rot_x);
    rotation_matrix = mul_mat33(&rotation_matrix, &rot_y);
    rotation_matrix = mul_mat33(&rotation_matrix, &rot_z);
    rotation_matrix = mul_mat33(&axis_replace, &rotation_matrix);
    rotation_matrix = transpose(&rotation_matrix);
    return rotation_matrix;
}

static inline mat33f_t magna_to_cv(vec3f_t xyz)
{
    mat33f_t rotation_matrix = eye33_f();
    mat33f_t from_w = {0};
    mat33f_t from_gl = {0};
    from_w.elem[0][0] = -1;
    from_w.elem[1][1] = -1;
    from_w.elem[2][2] =  1;
    from_gl.elem[0][0] =  1;
    from_gl.elem[1][1] = -1;
    from_gl.elem[2][2] = -1;

    mat33f_t rot_x;
    mat33f_t rot_y;
    mat33f_t rot_z;
    mat33f_t rot_pre_roll;
    mat33f_rot_x(&rot_x, -xyz.x * DEG2RAD);
    mat33f_rot_y(&rot_y, -xyz.y * DEG2RAD);
    mat33f_rot_z(&rot_z, -xyz.z * DEG2RAD);
    mat33f_rot_z(&rot_pre_roll, -270.f * DEG2RAD);

    rotation_matrix = mul_mat33(&rotation_matrix, &rot_z);
    rotation_matrix = mul_mat33(&rotation_matrix, &rot_y);
    rotation_matrix = mul_mat33(&rotation_matrix, &rot_x);
    rotation_matrix = mul_mat33(&rotation_matrix, &rot_pre_roll);

    rotation_matrix = mul_mat33(&rotation_matrix, &from_w);
    rotation_matrix = mul_mat33(&from_gl, &rotation_matrix);
    rotation_matrix = transpose(&rotation_matrix);
    return rotation_matrix;
}

static inline float32_t norm_l1(mat33f_t m);
static inline mat33f_t sub_mat33(mat33f_t a, mat33f_t b);

static inline uint8_t is_mat_rot(mat33f_t m)
{
    mat33f_t mt = transpose(&m);
    mat33f_t mtm  = mul_mat33(&m, &mt);
    mat33f_t e = eye33_f();
    mat33f_t e_sub_mtm = sub_mat33(e, mtm);
    float32_t n = norm_l1(e_sub_mtm);
    return n < 1e-3f;
}

static inline uint8_t rotmat_to_ang(mat33f_t r, vec3f_t * ang)
{
    if (is_mat_rot(r))
    {
        mat33f_t rt = transpose(&r);
        float32_t sy = sqrtf(r.elem[0][0] * r.elem[0][0] +  r.elem[1][0] * r.elem[1][0]);
        if (sy > 1e-4)
        {
            ang->x = RAD2DEG * atan2f(rt.elem[2][1], rt.elem[2][2]);
            ang->y = RAD2DEG * atan2f(-rt.elem[2][0], sy);
            ang->z = RAD2DEG * atan2f(rt.elem[1][0], rt.elem[0][0]);

        } else 
        {
            ang->x = RAD2DEG * atan2f(-rt.elem[1][2], rt.elem[1][1]);
            ang->y = RAD2DEG * atan2f(-rt.elem[2][0], sy);
            ang->z = 0;
        }
        return 1;
    } else 
    {
        return 0;
    }
}

typedef enum
{
    Z_BACK = -3,
    Y_BACK = -2,
    X_BACK = -1,
    X_DIR = 1,
    Y_DIR = 2,
    Z_DIR = 3,
}AXIS_DIRECTION;

static inline mat33f_t from_ocv_axes(AXIS_DIRECTION forward_dst, AXIS_DIRECTION up_dst);
static mat33f_t to_world_axes(AXIS_DIRECTION forward_src, AXIS_DIRECTION up_src);
static mat33f_t to_gl_axes(AXIS_DIRECTION forward_src, AXIS_DIRECTION up_src);

static inline uint8_t cv_to_magna(mat33f_t r, float32_t preroll, vec3f_t * ang)
{
    mat33f_t from_cv_fwd_up = from_ocv_axes(X_DIR, Z_DIR);
    mat33f_t to_w_bwd_up = to_world_axes(X_BACK, Z_DIR);
    mat33f_t to_gl_fwd_up = to_gl_axes(X_DIR, Z_DIR);

    mat33f_t pre_r; mat33f_rot_z(&pre_r, -preroll * DEG2RAD);
    mat33f_t pre_rt = transpose(&pre_r);
    mat33f_t rt = transpose(&r);

    mat33f_t r_ = mul_mat33(&from_cv_fwd_up, &rt);
    r_ = mul_mat33(&r_, &to_w_bwd_up);
    r_ = mul_mat33(&to_gl_fwd_up, &r_);
    r_ = mul_mat33(&r_, &pre_rt);
    r_ = transpose(&r_);

    uint8_t res = rotmat_to_ang(r_, ang);
    if (res)
    {
        *ang = muls3f(*ang, -1.f);
    }
    return res;
}

static const vec3f_t dir_to_vec_z_back = { 0.f,  0.f, -1.f};
static const vec3f_t dir_to_vec_y_back = { 0.f, -1.f,  0.f};
static const vec3f_t dir_to_vec_x_back = {-1.f,  0.f,  0.f};
static const vec3f_t dir_to_vec_x_dir =  { 1.f,  0.f,  0.f};
static const vec3f_t dir_to_vec_y_dir =  { 0.f,  1.f,  0.f};
static const vec3f_t dir_to_vec_z_dir =  { 0.f,  0.f,  1.f};
static const vec3f_t dir_to_vec_zero  =  { 0.f,  0.f,  0.f};

static vec3f_t vec_from_dir(AXIS_DIRECTION dir)
{
    static const vec3f_t dir_to_vec_table[7] = {
        { 0.f,  0.f, -1.f},
        { 0.f, -1.f,  0.f},
        {-1.f,  0.f,  0.f},
        { 0.f,  0.f,  0.f},
        { 1.f,  0.f,  0.f},
        { 0.f,  1.f,  0.f},
        { 0.f,  0.f,  1.f},
    };

    int32_t indx = (int32_t)dir - (int32_t)Z_BACK;
    return dir_to_vec_table[indx];
}

static mat33f_t to_gl_axes(AXIS_DIRECTION forward_src, AXIS_DIRECTION up_src)
{
    vec3f_t forward = vec_from_dir(forward_src);
    vec3f_t up = vec_from_dir(up_src);

    vec3f_t side = cross(&forward, &up);
    up = cross(&side, &forward);

    float32_t res[9] = {
        side.x,side.y,side.z,
        up.x,up.y,up.z,
        -forward.x,-forward.y,-forward.z
        };

    return set33_vp(res, 3); //$
}

static mat33f_t  to_world_axes(AXIS_DIRECTION forward_src, AXIS_DIRECTION up_src)
{
    vec3f_t forward = vec_from_dir(forward_src);
    vec3f_t up = vec_from_dir(up_src);

    vec3f_t side = cross(&forward, &up);
    up = cross(&side, &forward);

    float32_t res[9] = {
        forward.x,forward.y,forward.z,
        -side.x,-side.y,-side.z,
        up.x,up.y,up.z,
        };

    return set33_vp(res, 3);
}


static inline mat44f_t mat44f_from_mat33f(const mat33f_t m)
{
    mat44f_t ret = eye44();
    ret.elem[0][0] = m.elem[0][0];
    ret.elem[0][1] = m.elem[0][1];
    ret.elem[0][2] = m.elem[0][2];
    ret.elem[1][0] = m.elem[1][0];
    ret.elem[1][1] = m.elem[1][1];
    ret.elem[1][2] = m.elem[1][2];
    ret.elem[2][0] = m.elem[2][0];
    ret.elem[2][1] = m.elem[2][1];
    ret.elem[2][2] = m.elem[2][2];

    return ret;
}

static mat33f_t to_ocv_axes(AXIS_DIRECTION forward_src, AXIS_DIRECTION up_src)
{
    vec3f_t forward = vec_from_dir(forward_src);
    vec3f_t up = vec_from_dir(up_src);

    vec3f_t side = cross(&forward, &up);
    up = cross(&side, &forward);

    float32_t res[9] = {
        side.x,side.y,side.z,
        -up.x,-up.y,-up.z,
        forward.x,forward.y,forward.z
        };

    return set33_vp(res, 3);
}

static inline mat33f_t from_gl_axes(AXIS_DIRECTION forward_dst, AXIS_DIRECTION up_dst)
{
    mat33f_t R = to_gl_axes(forward_dst, up_dst);
    return transpose(&R);
}

static inline mat33f_t from_ocv_axes(AXIS_DIRECTION forward_dst, AXIS_DIRECTION up_dst)
{
    mat33f_t R = to_ocv_axes(forward_dst, up_dst);
    return transpose(&R);
}

static inline mat33f_t from_world_axes(AXIS_DIRECTION forward_dst, AXIS_DIRECTION up_dst)
{
    mat33f_t R = to_world_axes(forward_dst, up_dst);
    return transpose(&R);
}

static inline float32_t norm_l1(mat33f_t m)
{
    float32_t res = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res += fabs(m.elem[i][j]);
        }
    }
        
    return res;
}

static inline float32_t norm_l2(mat33f_t m)
{
    float32_t res = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res += m.elem[i][j] * m.elem[i][j];
        }
    }
        
    return sqrtf(res);
}

static inline float32_t norm_linf(mat33f_t m)
{
    float32_t res = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (res < fabs(m.elem[i][j]))
            {
                res = fabs(m.elem[i][j]);
            }
        }
    }
    return res;
}

static inline mat33f_t sub_mat33(mat33f_t a, mat33f_t b)
{
    mat33f_t res;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res.elem[i][j] = a.elem[i][j] - b.elem[i][j];
        }
    }
        
    return res;
}

static inline vec3f_t sub_vec3(vec3f_t a, vec3f_t b)
{
    vec3f_t res = { .x = a.x - b.x, 
                    .y = a.y - b.y,
                    .z = a.z - b.z };
    return res;
}

#ifdef __cplusplus
}
#endif

#endif //VP1_COMMON_MATH_UTILS
