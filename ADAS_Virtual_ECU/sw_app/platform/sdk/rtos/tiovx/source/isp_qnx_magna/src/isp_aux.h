/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           isp_aux.h
 *  @brief          Interface of basic math functions and functions for fixed to float point
 *                  and back convertion
 *
 *  @version        3.31
 *  @author         Mikhail Vakhrushev & Alexander Ronzhin
 *  @date           12.10.2020
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

#ifndef ISP_AUX_H
#define ISP_AUX_H

/* PRQA S 3451 ++ */
/* PRQA S 3412 ++ */
/* PRQA S 3410 ++ */
/* PRQA S 3614 ++ */
/* PRQA S 1030 ++ */
/* PRQA S 1055 ++ */
/* PRQA S 0604 ++ */
/* PRQA S 3334 ++ */

#include <stdint.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#if defined(__TI_ARM_V7R5__)
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Timestamp.h>
#endif

#ifndef EOK
#define EOK             0      /* no error */
#endif /* EOK */

#define MAX_CAMERAS_NUM 4U


typedef float float32_t; /* PRQA S 0631 */
typedef double float64_t; /* PRQA S 0631 */

extern float32_t* g_isp_log_level;
extern float32_t* g_isp_log_emb;
extern float32_t* g_isp_log_stats;

static inline bool ever(void) /* PRQA S 1056 */
{
    return true;
}

void async_print(const char* str);
/* PRQA S 3458 ++ */
/* PRQA S 0857 ++ */

#ifdef MAGNA_PSA
#define ISP_TRACELOG(N, ...)                                        \
    do                                                              \
    {                                                               \
        if ((g_isp_log_level != NULL) && ((N) <= *g_isp_log_level)) \
        {                                                           \
            char tmp_async_buf[2048] = {0};                         \
            (void)sprintf(tmp_async_buf, __VA_ARGS__);              \
            async_print(tmp_async_buf);                             \
        }                                                           \
    } while(!ever())
#else
#if defined(__TI_ARM_V7R5__)
#include "TI/j7.h"
#include "TI/tivx.h"
#endif
#define ISP_TRACELOG(N, ...)                                        \
    do                                                              \
    {                                                               \
        if ((g_isp_log_level != NULL) && ((N) <= *g_isp_log_level)) \
        {                                                           \
            printf(__VA_ARGS__);                             \
        }                                                           \
    } while(!ever())
#endif
/* PRQA S 3458 -- */
/* PRQA S 0857 -- */

typedef enum
{
    ISP_LOG_LEVEL_ERROR               = 0,
    ISP_LOG_LEVEL_WARNING             = 1,
    ISP_LOG_LEVEL_INFO                = 2,
    ISP_LOG_LEVEL_DEBUG               = 3,
    ISP_LOG_LEVEL_VERBOSE             = 4,
    ISP_LOG_LEVEL_SUPER_VERBOSE       = 5
} isp_log_level_t;

/* PRQA S 3453 ++ */
#define isp_tracelog_e(...)  ISP_TRACELOG(ISP_LOG_LEVEL_ERROR, __VA_ARGS__)
#define isp_tracelog_w(...)  ISP_TRACELOG(ISP_LOG_LEVEL_WARNING, __VA_ARGS__)
#define isp_tracelog_i(...)  ISP_TRACELOG(ISP_LOG_LEVEL_INFO, __VA_ARGS__)
#define isp_tracelog_d(...)  ISP_TRACELOG(ISP_LOG_LEVEL_DEBUG, __VA_ARGS__)
#define isp_tracelog_v(...)  ISP_TRACELOG(ISP_LOG_LEVEL_VERBOSE, __VA_ARGS__)
#define isp_tracelog_sv(...) ISP_TRACELOG(ISP_LOG_LEVEL_SUPER_VERBOSE, __VA_ARGS__)
/* PRQA S 3453 -- */

static inline void write_uint16_to_array(uint8_t* arr, uint32_t* pos, uint32_t limit, uint16_t val, int32_t* err)
{
    if (*err == EOK)
    {
        uint32_t write_sz = sizeof(val);
        if ((pos[0] + write_sz) >= limit)
        {
            *err = EINVAL;
        }
        else
        {
            memcpy(&arr[pos[0]], &val, write_sz);
            pos[0]+=write_sz;
        }
    }
}

static inline void write_new_size(uint8_t* arr, uint32_t* pos, uint32_t limit, uint32_t* cur_sz, uint32_t new_size, int32_t* err)
{
    if (cur_sz[0] != new_size)
    {
        cur_sz[0] = new_size;
        write_uint16_to_array(arr, pos, limit, 0, err);
        write_uint16_to_array(arr, pos, limit, cur_sz[0], err);
    }
}

static inline void write_uint8_arr(uint8_t* arr, uint32_t* pos, uint32_t limit, const uint8_t* val, uint32_t write_sz, int32_t* err)
{
    if (*err == EOK)
    {
        if ((pos[0] + write_sz) >= limit)
        {
            *err = EINVAL;
        }
        else
        {
            memcpy(&arr[pos[0]], val, write_sz);
            pos[0]+=write_sz;
        }
    }
}

static inline void write_uint16_to_array_be(uint8_t* arr, uint32_t* pos, uint32_t limit, uint16_t val, int32_t* err)
{
    if (*err == EOK)
    {
        uint32_t write_sz = sizeof(val);
        if ((pos[0] + write_sz) >= limit)
        {
            *err = EINVAL;
        }
        else
        {
            uint32_t i;
            arr[pos[0]] = (val >> 8) & 0xff;
            arr[pos[0] + 1] = (val) & 0xff;
            pos[0]+=write_sz;
        }
    }
}

static inline uint16_t convert_float_to_fixed(float32_t src, uint32_t int_bits, uint32_t frac_bits)
{
    uint16_t dst = 0;
    if (src < 0)
    {
        dst = 0U;
    }
    else
    {
        uint32_t max_int_val = (1U << int_bits) - 1U;
        uint32_t max_frac_val = (1U << frac_bits) - 1U;
        const float32_t frac_mul = (float32_t)(1U << frac_bits);

        uint32_t src_i = (uint32_t)src;
        src_i = (src_i > max_int_val) ? max_int_val : src_i;

        float32_t frac_part = src - (float32_t)src_i;
        uint32_t src_f = (uint32_t)((frac_part * frac_mul) + 0.5f);
        src_f = (src_f > max_frac_val) ? max_frac_val : src_f;

        dst = (uint16_t)((src_i << frac_bits) | src_f);
    }

    return dst;
}


static inline float32_t convert_fixed_to_float(uint16_t src, uint32_t int_bits, uint32_t frac_bits)
{
    uint32_t mask_f = ((1U << frac_bits) - 1U);
    uint32_t mask_i = ((1U << int_bits) - 1U);
    uint32_t src_i = src >> frac_bits;
    uint32_t src_f = src & mask_f;
    src_i = src_i & mask_i;

    float32_t dst;

    float32_t frac_mul = 1.f / (float32_t)(1U << frac_bits);

    dst = ((float32_t)src_i) + (((float32_t)src_f) * frac_mul);
    return dst;
}

#define ISP_MIN(a, b)  ( ( ((a)) > ((b)) ) ? ((b)) : ((a)) )  /* PRQA S 3453 */
#define ISP_MAX(a, b)  ( ( ((a)) < ((b)) ) ? ((b)) : ((a)) )  /* PRQA S 3453 */
#define STRINGIFY(x) #x  /* PRQA S 0341 */
#define STRINGIFY2(x) STRINGIFY(x)  /* PRQA S 0341 */

static inline float32_t convert_fixed_to_float_m(uint32_t src, uint32_t sign_bit_num, uint32_t frac_bits)
{
    uint32_t mask = (1U << (sign_bit_num - 1U));
    float32_t neg = ((mask & src) != 0) ? -1.f : 1.f;
    uint32_t src_abs = src & (~mask);

    float32_t mult = 1.f / (float32_t)((1 << frac_bits));

    return ((float32_t)src_abs) * mult * neg;
}

static inline float32_t fsign(float32_t v)
{
    if (v < 0.f)
        return -1.f;
    return 1.f;
}

static inline float32_t convert_fixed_to_float_s(uint32_t src, uint32_t bits_number, uint32_t frac_bits)
{
    uint32_t mask = (1U << (bits_number - 1U));
    uint64_t mask_ff = 1;
    mask_ff = (mask_ff << bits_number) - 1;
    mask_ff = ~mask_ff;
    uint32_t mask_ff32 = (uint32_t)mask_ff;

    uint32_t neg = ((mask & src) != 0) ? 1U : 0U;
    uint32_t sign_val = (neg == 1U) ? (src | mask_ff32) : src;

    float32_t mult = 1.f / (float32_t)((1 << frac_bits));

    int32_t dst = (int32_t)sign_val;
    return ((float32_t)dst * mult);
}

static inline float32_t convert_fixed_to_float_u(uint32_t src, uint32_t bits_number, uint32_t frac_bits) /* PRQA S 3206 */
{
    float32_t mult = 1.f / (float32_t)((1U << frac_bits));
    return (mult * (float32_t)src);
}

static inline uint32_t convert_float_to_fixed_m(float32_t src, uint32_t sign_bit_num, uint32_t frac_bits)
{
    int64_t dst = (int64_t)roundf(src * (float32_t)(1U << frac_bits));
    dst = (dst < 0) ? (int64_t)((uint64_t)(-dst) | (1U << (sign_bit_num - 1))) : dst;
    return (uint32_t)dst;
}

static inline uint32_t convert_float_to_fixed_s(float32_t src, uint32_t bits_number, uint32_t frac_bits)
{
    int32_t dst = (int32_t)roundf(src * (float32_t)(1U << frac_bits));
    uint32_t dst_ui32 = (uint32_t)dst;
    uint32_t mask = (uint32_t)((((uint64_t)1) << bits_number) - 1);
    return (dst_ui32 & mask);
}

static inline uint32_t convert_float_to_fixed_u(float32_t src, uint32_t sign_bit_num, uint32_t frac_bits) /* PRQA S 3206 */
{
    int64_t dst = (int64_t)roundf(src * (float32_t)(1U << frac_bits));
    dst = ISP_MAX(dst, 0);
    return (uint32_t)dst;
}

void convert_ccm_from_fixed(float32_t* dst, int32_t* alg_settings);

static inline float32_t clampf32(float32_t a, float32_t min, float32_t max)
{
    float32_t ret = ISP_MIN(a, max);
    ret = ISP_MAX(ret, min);
    return ret;
}

static inline int32_t clamp(int32_t a, int32_t min, int32_t max)
{
    int32_t ret = ISP_MIN(a, max);
    ret = ISP_MAX(ret, min);
    return ret;
}

static inline uint32_t clampu(uint32_t a, uint32_t min, uint32_t max)
{
    uint32_t ret = ISP_MIN(a, max);
    ret = ISP_MAX(ret, min);
    return ret;
}

static inline float32_t interpolate_one(float32_t prev, float32_t cur, uint32_t steps_num, uint32_t cur_step)
{
    float32_t ret = cur;

    if (steps_num > 1)
    {
        float32_t inv_steps_num = 1.f / (float32_t)(steps_num);
        float32_t de_step = ((float32_t)cur - prev ) * inv_steps_num;
        ret =  (prev + (de_step * (float32_t)(cur_step + 1)));
    }

    return ret;
}
#ifdef MAGNA_PSA
static inline float64_t clockf(void)
{
    struct timespec t = {0};
    int32_t res = clock_gettime(CLOCK_MONOTONIC, &t);
    int64_t tui = (res == 0) ? (((int64_t)t.tv_sec * 1000000L) + ((int64_t)t.tv_nsec / 1000L)) : (0L);

    return ((float64_t)tui / 1000.0);
}
#else
static inline float64_t clockf(void)
{
#if 0
    Types_Timestamp64 bios_timestamp64;
    uint64_t cur_ts;
    static uint64_t freq;

    /* ...retrieve timestamp frequency as required */
    if (!freq)
    {
        Types_FreqHz frq;

        Timestamp_getFreq(&frq);
        freq = ((uint64_t)frq.hi << 32) | frq.lo;
    }

    /* ...get current clock counter */
    Timestamp_get64(&bios_timestamp64);
    cur_ts = ((uint64_t)bios_timestamp64.hi << 32) | bios_timestamp64.lo;

    /* ...translate clocks into usecs */
    return (cur_ts * 1000000ULL) / freq;
#endif
    return 0;
}
#endif

static inline void copy_vec3(const float32_t in[3], float32_t out[3])
{
    out[0] = in[0];
    out[1] = in[1];
    out[2] = in[2];
}

static inline uint32_t bisect(uint32_t x, const int32_t arr[], uint32_t len)
{
    uint32_t i;
    uint32_t ret = len;

    for (i = 0; i < len; i++)
    {
        if ((int32_t)x < arr[i])
        {
            ret = i;
            break;
        }
    }
    return ret;

}

static inline uint32_t lower_bound_f32(const float32_t arr[], uint32_t N, float32_t X)
{
    uint32_t mid;
    uint32_t low = 0;
    uint32_t high = N;

    if (X <= arr[0])
        return 0;

    if (X > arr[N - 1])
        return N;
 
    while ((low + 1) < high) 
    {
        mid = low + (high - low) / 2;
        float32_t midv = arr[mid];
 
        if (X <= midv) 
        {
            high = mid;
        }
        else 
        {
            low = mid;
        }
    }
   
    return low + 1;
}

static inline float32_t convert_trow2ms(uint32_t exp, uint32_t hts, uint32_t sclk)
{
    float32_t exp_ms = ((float32_t)hts / (float32_t)sclk) * exp;
    return exp_ms;
}

static inline float32_t convert_ms2trow(float32_t exp_ms, uint32_t hts, uint32_t sclk)
{
    float32_t exp = ((float32_t)exp_ms / (float32_t)hts) * sclk;
    return exp;
}

static inline bool check_invalid(float32_t in) /* PRQA S 1056 */
{
    return (in == FLT_MAX) ? true : false; /* PRQA S 3341 */
}

static inline bool cmp_f32(float32_t a, float32_t b) /* PRQA S 1056 */
{
    return (fabsf(a - b) < FLT_EPSILON) ? true : false;
}

static inline uint32_t get_table_index(uint32_t table_size, uint32_t* counter)
{
    uint32_t index = *counter % table_size;
    *counter /= table_size;
    return index;
}

typedef struct
{
    int32_t data[4];
}compand_table_t; /* PRQA S 3448 */

static const compand_table_t compand_table_12 = {.data = {0, 32768, 48640, 64000}}; /* PRQA S 3207 */  /* PRQA S 1053 */ /* PRQA S 3218 */  /* PRQA S 3480 */
static const compand_table_t compand_table_20 = {.data = {0, 32768, 1048576, 16777216}}; /* PRQA S 3207 */ /* PRQA S 1053 */ /* PRQA S 3218 */ /* PRQA S 3480 */

static inline uint32_t compand(uint32_t x, compand_table_t a, compand_table_t b)
{
    int32_t i = (int32_t)bisect(x, a.data, sizeof(compand_table_t) / sizeof(a.data[0])) - 1;
    int32_t ret;

    if (i < 1)
    {
        ret = (int32_t)x;
    }
    else
    {
        int32_t db = b.data[1 + i] - b.data[i];
        int32_t da = a.data[1 + i] - a.data[i];
        float32_t rel = (float32_t)db / (float32_t)da;
        ret = b.data[i] + (int32_t)floorf(((float32_t)((int32_t)x - a.data[i]) * rel) + 0.5f);
    }

    return (uint32_t)ret;
}

#ifndef MAGNA_PSA
/**
* @brief Get current time in usec (since core start-up)
*/
static inline uint64_t __get_time_us(void)
{
#if 0
     Types_Timestamp64 bios_timestamp64;
     uint64_t cur_ts;
     static uint64_t freq;

     /* ...retrieve timestamp frequency as required */
 if (!freq)

    {
         Types_FreqHz frq;

         Timestamp_getFreq(&frq);
         freq = ((uint64_t)frq.hi << 32) | frq.lo;

    }

     /* ...get current clock counter */
 Timestamp_get64(&bios_timestamp64);
     cur_ts = ((uint64_t)bios_timestamp64.hi << 32) | bios_timestamp64.lo;

     /* ...translate clocks into usecs */
 return (cur_ts * 1000000ULL) / freq;
#endif
    return 0;
}
#endif
/* PRQA S 3451 -- */
/* PRQA S 3412 -- */
/* PRQA S 3410 -- */
/* PRQA S 3614 -- */
/* PRQA S 1030 -- */
/* PRQA S 1055 -- */
/* PRQA S 0604 -- */
/* PRQA S 3334 -- */

#endif //ISP_AUX_H
