/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           awb-impl.c
 *  @brief          Auto white balance algorithm implementation
 *
 *  @version        3.31
 *  @author         Sergey Salishev & Mikhail Vakhrushev & Alexander Ronzhin
 *  @date           12.10.2020
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

/* PRQA S 1055 ++ */
/* PRQA S 3450 ++ */
/* PRQA S 0781 ++ */
/* PRQA S 0604 ++ */
/* PRQA S 3448 ++ */
/* PRQA S 3408 ++ */
/* PRQA S 0492 ++ */
/* PRQA S 3218 ++ */

#include "awb-impl.h"
#include "third_party/fastapprox/fastlog.h"
#include "third_party/fastapprox/fastexp.h"
#include <errno.h>

#define MAX_FILTER_SIZE 24


typedef struct
{
    float32_t values[MAX_FILTER_SIZE];
    int32_t weights[MAX_FILTER_SIZE];
    uint32_t count;
    uint32_t stage;
} median_filter_t;

static inline void swap_elements_ui32(uint32_t *a, uint32_t *b)
{
    if ((a != NULL) && (b != NULL))
    {
        uint32_t t = *b;
        *b = *a;
        *a = t;
    }
}

static inline void swap_elements_i32(int32_t *a, int32_t *b)
{
    if ((a != NULL) && (b != NULL))
    {
        int32_t t = *b;
        *b = *a;
        *a = t;
    }
}

static inline void swap_elements_f32(float32_t *a, float32_t *b)
{
    if ((a != NULL) && (b != NULL))
    {
        float32_t t = *b;
        *b = *a;
        *a = t;
    }
}

static inline void vec_bubble_sort(const float32_t vec[], uint32_t *min, uint32_t *middle, uint32_t *max)
{
    if ((vec != NULL) &&
        (min != NULL) &&
        (middle != NULL) &&
        (max != NULL))
    {
        if (vec[*min] > vec[*middle])
        {
            swap_elements_ui32(min, middle);
        }

        if (vec[*middle] > vec[*max])
        {
            swap_elements_ui32(middle, max);
        }

        if (vec[*min] > vec[*middle])
        {
            swap_elements_ui32(min, middle);
        }
    }
}

static inline uint32_t sort_vec_with_weight(float32_t vec[], int32_t weight[], uint32_t left, uint32_t right, uint32_t middle, bool min_founded) /* PRQA S 1056 */
{
    uint32_t i;
    uint32_t store_index = left;

    if ((vec != NULL) && (weight != NULL))
    {
        float32_t middle_val = vec[middle];

        swap_elements_f32(&vec[middle], &vec[right]);
        swap_elements_i32(&weight[middle], &weight[right]);

        for (i = left; i <= (right - 1); i++)
        {
            float32_t cur_val = vec[i];
            uint32_t eq = (fabsf(cur_val - middle_val) < FLT_EPSILON) ? 1U : 0U;

            if ((cur_val < middle_val) || ((eq == 1U) && min_founded))
            {
                min_founded = false;
                swap_elements_f32(&vec[store_index], &vec[i]);
                swap_elements_i32(&weight[store_index], &weight[i]);
                store_index++;
            }
        }

        swap_elements_f32(&vec[store_index], &vec[right]);
        swap_elements_i32(&weight[store_index], &weight[right]);
    }

    return store_index;
}

static inline float32_t choose_median(const float32_t vec[],
                                      const int32_t weight[],
                                      uint32_t left,
                                      uint32_t right)
{
    float32_t res = 0.0f;

    if ((vec != NULL) && (weight != NULL))
    {
        res = vec[left];

        if (right != left)
        {
            if (weight[left] == weight[right])
            {
                res = (vec[left] + vec[right]) / 2.0f;
            }
            else if (weight[left] < weight[right])
            {
                res = vec[right];
            }
            else
            {
                res = vec[left];
            }
        }
    }

    return res;
}

static inline int32_t get_vec_sum(const int32_t vec[], uint32_t size)
{
    uint32_t i;
    int32_t sum = 0;

    if (vec != NULL)
    {
        for (i = 0; i < size; i++)
        {
            sum += vec[i];
        }
    }

    return sum;
}

static inline int32_t get_vec_sum_elem(const int32_t vec[], uint32_t start, uint32_t end)
{
    uint32_t i;
    int32_t sum = 0;

    if (vec != NULL)
    {
        for (i = start; i < end; i++)
        {
            sum += vec[i];
        }
    }

    return sum;
}

static inline float32_t calculate_weight_median(const float32_t filter_values[MAX_FILTER_SIZE],
                                                const int32_t weight[MAX_FILTER_SIZE])
{
    float32_t ret = 1.0f;

    if ((filter_values != NULL) && (weight != NULL))
    {
        int32_t local_weight[MAX_FILTER_SIZE];
        float32_t local_values[MAX_FILTER_SIZE];
        uint32_t first = 0;
        uint32_t last = MAX_FILTER_SIZE - 1;
        int32_t weight_sum;

        (void)memcpy(local_values, filter_values, sizeof(float32_t) * MAX_FILTER_SIZE);
        (void)memcpy(local_weight, weight, sizeof(int32_t) * MAX_FILTER_SIZE);
        weight_sum = get_vec_sum(local_weight, MAX_FILTER_SIZE);

        uint32_t i;
        for (i = 0; (i < MAX_FILTER_SIZE) && (last > (first + 1)); i++)
        {
            uint32_t middle = (first + last) >> 1;
            uint32_t min = first;
            uint32_t max = last;
            int32_t weight_right_part = 0;
            int32_t weight_left_part = 0;

            vec_bubble_sort(local_values, &min, &middle, &max);
            middle = sort_vec_with_weight(local_values, local_weight, first, last, middle, (fabsf(local_values[min] - local_values[middle]) < __FLT_EPSILON__));

            weight_left_part += get_vec_sum_elem(local_weight, first, middle);             /* PRQA S 2986 */
            weight_right_part += get_vec_sum_elem(local_weight, (middle + 1), (last + 1)); /* PRQA S 2986 */

            if (((weight_left_part * 2) < weight_sum) && ((weight_right_part * 2) < weight_sum))
            {
                last = middle;
                first = middle;
            }
            else
            {
                if (weight_left_part > weight_right_part)
                {
                    local_weight[middle] += weight_right_part;
                    last = middle;
                }
                else
                {
                    local_weight[middle] += weight_left_part;
                    first = middle;
                }
            }
        }
        ret = choose_median(local_values, local_weight, first, last);
    }

    return ret;
}

static inline void init_median_filter(float32_t value, median_filter_t filter[])
{
    if (filter != NULL)
    {
        uint32_t i;

        for (i = 0U; i < MAX_FILTER_SIZE; i++)
        {
            filter->values[i] = value;
        }
        filter->count = MAX_FILTER_SIZE;
        filter->stage = 1U;
    }
}

static inline void init_median_filter_weights(const int32_t weights[MAX_FILTER_SIZE], median_filter_t *filter)
{
    if ((filter != NULL) && (weights != NULL))
    {
        (void)memcpy(filter->weights, weights, (MAX_FILTER_SIZE * sizeof(int32_t)));
    }
}

static inline float32_t get_median(float32_t value, median_filter_t *filter)
{
    float32_t median = 0;

    if (filter != NULL)
    {
        (void)memmove(&filter->values[0], &filter->values[1], sizeof(float32_t) * (MAX_FILTER_SIZE - 1));
        filter->values[MAX_FILTER_SIZE - 1] = value;

        median = calculate_weight_median(filter->values, filter->weights);
    }

    return median;
}

// AWB algorithm internal structure
typedef struct
{
    // Prelimenary created config
    awb_config_t config;

    // WB gains in sensor on previouse iteration
    awb_ratios_t last_rg_bg;

    // WB gains in sensor on previouse iteration
    float32_t last_gains[MAX_CHANNELS];

    // WB gains in CCM on previouse iteration
    float32_t last_fine_gains[MAX_CHANNELS];

    // Weight median filter for R gain values
    median_filter_t rg_median;

    // Weight median filter for B gain values
    median_filter_t bg_median;

    // Amount of valid blocks, which is needed for calculation of results
    uint32_t min_blocks;

    // The illuminant, which was calculated on previouse iteration
    awb_ratios_t prev_illuminant;

    // The illuminant delta, which was calculated on previouse iteration
    awb_ratios_t prev_illuminant_delta;

} awb_private_context_t;

// Conversion of user-space AWB context into AWB privite
static inline awb_private_context_t *awb_private_context(awb_context_t *context)
{
    return (awb_private_context_t *)context; /* PRQA S 0310 */
}

static int32_t awb_update_config(awb_private_context_t *context, const awb_config_t *new_config)
{
    int32_t err = 0;

    if ((context != NULL) && (new_config != NULL))
    {
        context->config = *new_config;

        uint32_t cnt = 0U;
        uint32_t i;

        for (i = 0U; i < context->config.block_count; i++)
        {
            if (context->config.mask[i] > 0U) /* PRQA S 0491 */
            {
                cnt++;
            }
        }

        context->min_blocks = (uint32_t)ceilf(context->config.min_valid_blocks_ratio * (float32_t)cnt);

        if (context->min_blocks < 1)
        {
            err = EINVAL;
        }
    }
    else
    {
        err = EINVAL;
    }

    return err;
}

static int32_t awb_init(awb_private_context_t *context, const awb_config_t *config)
{
    int32_t err;

    if ((context != NULL) && (config != NULL))
    {
        err = awb_update_config(context, config);
        copy_vec3(context->config.static_gains, context->last_gains);

        float32_t one_gains[MAX_CHANNELS] = {1.0, 1.0, 1.0};
        copy_vec3(one_gains, context->last_fine_gains);

        int32_t weight[MAX_FILTER_SIZE] = {1, 8, 27,
                                           64, 125, 216,
                                           343, 512, 729,
                                           1000, 1331, 1728,
                                           2197, 2744, 3375,
                                           4096, 4913, 5832,
                                           6859, 8000, 9261,
                                           10648, 12167, 13824};
        init_median_filter_weights(weight, &context->rg_median);
        init_median_filter_weights(weight, &context->bg_median);
    }
    else
    {
        err = EINVAL;
    }

    return err;
}

typedef struct
{
    float32_t temp;

    float32_t tint;

    float32_t conf;

    uint32_t index;

} conf_block_t;

static int32_t conf_cmp_dsc(const void *a, const void *b)
{
    int32_t ret = -1;

    if ((a != NULL) && (b != NULL))
    {
        const conf_block_t *block_a = (const conf_block_t *)a; /* PRQA S 0316 */
        const conf_block_t *block_b = (const conf_block_t *)b; /* PRQA S 0316 */

        float32_t w_a = block_a->conf;
        float32_t w_b = block_b->conf;

        if (cmp_f32(w_a, w_b))
        {
            ret = 0;
        }
        else if ((w_b - w_a) > 0.0f)
        {
            ret = 1;
        }
        else
        {
            ret = -1;
        }
    }

    return ret;
}

static inline int32_t findf(const float32_t v[], uint32_t n, float32_t a)
{
    int32_t pos = -1;
    int32_t k;
    for (k = 0; k < (int32_t)n; k++)
    {
        if (v[k] > a) /* PRQA S 2824 */
        {
            pos = k - 1;
            break;
        }
    }
    return pos;
}

static inline void convert_temp_tint_to_lrg_lbg(float32_t inv_temp,
                                                float32_t tint,
                                                const float32_t temp_table[],
                                                const float32_t lrg_table[],
                                                const float32_t lbg_table[],
                                                uint32_t table_size,
                                                float32_t *lrg,
                                                float32_t *lbg)
{
    int32_t k = findf(temp_table, table_size, inv_temp);
    k = ISP_MAX(k, 0);

    float32_t s = temp_table[k + 1] - temp_table[k]; /* PRQA S 2824 */

    float32_t dt = inv_temp - temp_table[k];/* PRQA S 2824 */
    float32_t lrg0 = lrg_table[k];/* PRQA S 2824 */
    float32_t lbg0 = lbg_table[k];/* PRQA S 2824 */

    float32_t ort1 = lrg_table[k + 1] - lrg_table[k]; /* PRQA S 2824 */
    float32_t ort2 = lbg_table[k + 1] - lbg_table[k]; /* PRQA S 2824 */
    *lrg = (((ort1 * dt) - (ort2 * tint)) / s) + lrg0; /* PRQA S 2814 */
    *lbg = (((ort2 * dt) + (ort1 * tint)) / s) + lbg0; /* PRQA S 2814 */
}

void convert_lrg_lbg_to_temp_tint(float32_t lrg,
                               float32_t lbg,
                               const float32_t temp_table[],
                               const float32_t lrg_table[],
                               const float32_t lbg_table[],
                               int table_size,
                               float32_t *inv_temp,
                               float32_t *tint)
{
    float32_t dist = FLT_MAX;
    int32_t k;

    for (k = 0; k < (table_size - 1); k++)
    {
        float32_t s = temp_table[k + 1] - temp_table[k]; /* PRQA S 2824 */
        float32_t t0 = temp_table[k];
        float32_t lrgd = lrg - lrg_table[k]; /* PRQA S 2824 */
        float32_t lbgd = lbg - lbg_table[k]; /* PRQA S 2824 */

        float32_t ort1 = lrg_table[k + 1] - lrg_table[k];
        float32_t ort2 = lbg_table[k + 1] - lbg_table[k];
        float32_t norm2 = (ort1 * ort1) + (ort2 * ort2);
        float32_t new_temp = ((((ort1 * lrgd) + (ort2 * lbgd)) * s) / norm2) + t0;
        float32_t new_tint = (((-ort2 * lrgd) + (ort1 * lbgd)) * s) / norm2;

        float32_t new_dist = 0;

        if (new_temp < temp_table[k])
        {
            new_dist = temp_table[k] - new_temp;
            new_temp = temp_table[k];
        }
        else if (new_temp > temp_table[k + 1]) /* PRQA S 2004 */
        {
            new_dist = new_temp - temp_table[k + 1];
            new_temp = temp_table[k + 1];
        }
        if (new_dist < dist)
        {
            dist = new_dist;
            *tint = new_tint; /* PRQA S 2814 */
            *inv_temp = new_temp; /* PRQA S 2814 */
        }
    }
}


static inline float32_t dist_inhull(float32_t xq,  /* PRQA S 1056 */
                          float32_t yq,
                          const float32_t xv[],
                          const float32_t yv[],
                          uint32_t vn)
{
    uint32_t p;
    float32_t dist = 10000.0f;
    int32_t direction = 0;;

    for (p = 1; p < vn; p++)
    {
        float32_t x0 = xv[p - 1]; /* PRQA S 2824 */  /* PRQA S 3334 */
        float32_t x1 = xv[p]; /* PRQA S 3334 */
        float32_t y0 = yv[p - 1]; /* PRQA S 2824 */  /* PRQA S 3334 */
        float32_t y1 = yv[p]; /* PRQA S 3334 */

        float32_t a = y0 - y1;
        float32_t b = x1 - x0;
        float32_t c = -a * x0 - b * y0;
        float32_t inv_length = 1.0f / sqrtf(a * a + b * b);
        a *= inv_length;
        b *= inv_length;
        c *= inv_length;

        float32_t d = a * xq + b * yq + c;
        float32_t cur_dist = fabsf(d);

        float32_t dx = xq - a * d;
        float32_t dy = yq - b * d;
        float32_t x0_dx = (x0 - dx);
        float32_t y0_dy = (y0 - dy);
        float32_t x1_dx = (x1 - dx);
        float32_t y1_dy = (y1 - dy);
        float32_t alpha_A = x1_dx * b - y1_dy * a;
        float32_t alpha_B = -x0_dx * b + y0_dy * a;

        float32_t x0_xq = (x0 - xq);
        float32_t x1_xq = (x1 - xq);
        float32_t y0_yq = (y0 - yq);
        float32_t y1_yq = (y1 - yq);

        if (alpha_B < 0)
        {
            cur_dist = sqrtf(x1_xq * x1_xq + y0_yq * y0_yq);
        }
        else if (alpha_A < 0)
        {
            cur_dist = sqrtf(x0_xq * x0_xq + y1_yq * y1_yq);
        }

        direction += (int32_t) copysignf(1.0, (x0_xq * y1_yq) - (x1_xq * y0_yq));
        dist = ISP_MIN(dist, cur_dist);
    }

    if (abs(direction) == (vn - 1))
    {
        dist = 0.f;
    }

    return dist;
}

static inline uint32_t calculate_block_confidence(const uint8_t block_usage[],
                                                  const awb_statistics_block_t block[],
                                                  const uint32_t block_number,
                                                  const float32_t weight[],
                                                  const float32_t pre_gr,
                                                  const float32_t pre_gb,
                                                  conf_block_t confidence[],
                                                  const awb_tables_t* tables,
                                                  float32_t q6,
                                                  float32_t dist_threshold
                                                  )
{
    uint32_t block_counter = 0U;
    uint32_t i;

    if ((block_usage != NULL) &&
        (block != NULL) &&
        (weight != NULL) &&
        (confidence != NULL))
    {
        float32_t inv_temp_m = 0.0f;
        float32_t tint_m = 0.0f;

        for (i = 0U; i < block_number; i++)
        {
            float32_t inv_temp = 1.0f / 6500.0f;
            float32_t tint = 0.0f;
            float32_t block_confidence = 0.0f;

            if ((block[i].conf > 0) && (block_usage[i] > 0U))
            {
                float32_t lrg = fasterlog(block[i].ratios.rg * pre_gr);
                float32_t lbg = fasterlog(block[i].ratios.bg * pre_gb);

                convert_lrg_lbg_to_temp_tint(lrg, lbg, tables->planck_temp_table, tables->planck_lrg_table,
                                            tables->planck_lbg_table, tables->planck_len, &inv_temp, &tint);

                float32_t block_brightness = fasterlog(block[i].y);
                float32_t distance_D65 = inv_temp - (1000.0f / 6500.0f);
                float32_t inhull_check = dist_inhull(inv_temp, tint, tables->gray_hull_temp, tables->gray_hull_tint, tables->gray_hull_len); /* PRQA S 1056 */

                if (inhull_check <= dist_threshold)
                {
                    block_confidence = block[i].conf *
                                    fasterexp(
                                        (weight[0] * block_brightness) -
                                        (weight[1] * distance_D65 * distance_D65) -
                                        (weight[2] * tint * tint) -
                                        inhull_check * q6);

                    inv_temp_m += inv_temp;
                    tint_m += tint;
                    block_counter++;
                }
            }
            confidence[i].temp = inv_temp;
            confidence[i].tint = tint;
            confidence[i].conf = block_confidence;
            confidence[i].index = i;
        }

        inv_temp_m = inv_temp_m / ((float32_t)block_counter + FLT_EPSILON);
        tint_m = tint_m / ((float32_t)block_counter + FLT_EPSILON);

        for (i = 0U; i < block_number; i++)
        {
            float32_t dtemp = confidence[i].temp - inv_temp_m;
            float32_t dtint = confidence[i].tint - tint_m;
            confidence[i].conf = confidence[i].conf * fasterexp(
                -(weight[3] * dtemp * dtemp)
                -(weight[4] * dtint * dtint));
        }
    }

    return block_counter;
}

static void temp_tint_clamp(const float32_t temp_result_range_min,
                            const float32_t tint_result_range_min,
                            const float32_t temp_result_range_max,
                            const float32_t tint_result_range_max,
                            const float32_t gw_dtemp,
                            const float32_t gw_dtint,
                            const float32_t prev_inv_temp,
                            const float32_t prev_tint,
                            const awb_tables_t* tables,
                            float32_t *rg,
                            float32_t *bg,
                            float32_t *temp_nonclamp,
                            float32_t *tint_nonclamp,
                            float32_t *out_inv_temp_clamp,
                            float32_t *out_tint_clamp)
{

    float32_t inv_temp = 0;
    float32_t tint = 0;
    float32_t lrg = fasterlog(*rg); /* PRQA S 2814 */
    float32_t lbg = fasterlog(*bg); /* PRQA S 2814 */

    convert_lrg_lbg_to_temp_tint(lrg, lbg, tables->planck_temp_table, tables->planck_lrg_table, /* PRQA S 2814 */
                                 tables->planck_lbg_table, tables->planck_len, &inv_temp, &tint);

    float32_t temp = 1000.0f / inv_temp;
    *temp_nonclamp = temp;
    *tint_nonclamp = tint;
    float32_t temp_clamp = clampf32(temp, temp_result_range_min, temp_result_range_max);
    float32_t tint_clamp = clampf32(tint, tint_result_range_min, tint_result_range_max);
    float32_t inv_temp_clamp = (1000.0f / temp_clamp);

    inv_temp_clamp = clampf32(inv_temp_clamp, prev_inv_temp - gw_dtemp, prev_inv_temp + gw_dtemp);
    float32_t res_tint_clamp = clampf32(tint_clamp, prev_tint - gw_dtint, prev_tint + gw_dtint);
    isp_tracelog_v("GW: res: %f %f clamp: %f %f diff: %f %f prev: %f %f\n", 1000.0f / inv_temp_clamp, res_tint_clamp,
                                                                            temp_clamp, tint_clamp,
                                                                            gw_dtemp, gw_dtint,
                                                                            1000.0f / prev_inv_temp, tint_clamp);

    convert_temp_tint_to_lrg_lbg(inv_temp_clamp, tint_clamp, tables->planck_temp_table, tables->planck_lrg_table,
                                 tables->planck_lbg_table, tables->planck_len, &lrg, &lbg);

    *rg = fasterexp(lrg); /* PRQA S 2814 */
    *bg = fasterexp(lbg); /* PRQA S 2814 */
    *out_inv_temp_clamp = inv_temp_clamp;
    *out_tint_clamp = res_tint_clamp;
}

static inline void calculate_illuminant(const conf_block_t confidence[],
                                        const awb_statistics_block_t block[],
                                        const awb_tables_t* tables,
                                        const uint32_t block_number,
                                        const float32_t max_confidence_value,
                                        const float32_t sensor_gains[MAX_CHANNELS],
                                        const float32_t temp_result_range_min,
                                        const float32_t tint_result_range_min,
                                        const float32_t temp_result_range_max,
                                        const float32_t tint_result_range_max,
                                        const float32_t gw_dtemp,
                                        const float32_t gw_dtint,
                                        const float32_t prev_inv_temp,
                                        const float32_t prev_tint,
                                        float32_t *rg,
                                        float32_t *bg,
                                        float32_t *temp_nonclamp,
                                        float32_t *tint_nonclamp,
                                        float32_t *out_inv_temp_clamp,
                                        float32_t *out_tint_clamp)
{
    uint32_t i;
    float32_t sum[MAX_CHANNELS] = {0};

    if ((sensor_gains != NULL) &&
        (block != NULL) &&
        (rg != NULL) &&
        (bg != NULL) &&
        (confidence != NULL))
    {
        for (i = 0U; i < block_number; i++)
        {
            float32_t conf = confidence[i].conf;
            uint32_t index = confidence[i].index; /* PRQA S 3334 */

            conf = (conf < max_confidence_value) ? (conf / max_confidence_value) : 1.0f;

            float32_t g = conf / (block[index].ratios.rg + block[index].ratios.bg + 1);
            sum[RED] += block[index].ratios.rg * g;
            sum[GREEN] += g;
            sum[BLUE] += block[index].ratios.bg * g;
        }

        *rg = (sum[RED] * sensor_gains[GREEN]) / (sum[GREEN] * sensor_gains[RED]);
        *bg = (sum[BLUE] * sensor_gains[GREEN]) / (sum[GREEN] * sensor_gains[BLUE]);
        temp_tint_clamp(temp_result_range_min,
                        tint_result_range_min,
                        temp_result_range_max,
                        tint_result_range_max,
                        gw_dtemp,
                        gw_dtint,
                        prev_inv_temp,
                        prev_tint,
                        tables,
                        rg, bg,
                        temp_nonclamp, tint_nonclamp,
                        out_inv_temp_clamp, out_tint_clamp);
    }
}

int32_t estimate_illuminant(awb_private_context_t *pcontext, /* PRQA S 3673 */
                            const awb_statistics_t *statistics,
                            const awb_tables_t* tables,
                            awb_ratios_t *illuminant,
                            float32_t *conf_out,
                            float32_t *temp_nonclamp,
                            float32_t *tint_nonclamp,
                            float32_t *out_inv_temp_clamp,
                            float32_t *out_tint_clamp)
{
    int32_t err = 0;

    if ((pcontext != NULL) &&
        (statistics != NULL) &&
        (illuminant != NULL) &&
        (conf_out != NULL))
    {
        static conf_block_t ISP_FAST_LOCAL_VARIABLE confidence[ISP_AWB_NUM_ZONES]; /* PRQA S 1051 */
        (void)memset(confidence, 0, sizeof(conf_block_t) * ISP_AWB_NUM_ZONES);

        float32_t pre_gr = statistics->gains_used_for_stat[GREEN] / statistics->gains_used_for_stat[RED];
        float32_t pre_gb = statistics->gains_used_for_stat[GREEN] / statistics->gains_used_for_stat[BLUE];

        uint32_t cnt = calculate_block_confidence(pcontext->config.mask,
                                                  statistics->blocks,
                                                  pcontext->config.block_count,
                                                  pcontext->config.qda_weight,
                                                  pre_gr,
                                                  pre_gb,
                                                  confidence,
                                                  tables,
                                                  pcontext->config.q6,
                                                  pcontext->config.dist_threshold);

        *conf_out = (cnt >= pcontext->min_blocks) ? ((float32_t)cnt / (float32_t)pcontext->config.block_count) : 0.0f;

        if (*conf_out > 0.0f)
        {
            qsort(confidence, pcontext->config.block_count, sizeof(confidence[0]), conf_cmp_dsc); /* PRQA S 3650 */ /* PRQA S 3635 */ /* PRQA S 1056 */

            float32_t max_confidence_value = confidence[pcontext->min_blocks - 1].conf;
            float32_t top_confidence_value = confidence[1].conf;
            if (max_confidence_value > (pcontext->config.confidence_threshold * top_confidence_value))
            {
                calculate_illuminant(confidence,
                                     statistics->blocks,
                                     tables,
                                     pcontext->config.block_count,
                                     max_confidence_value,
                                     statistics->gains_used_for_stat,
                                     pcontext->config.temp_result_range_min,
                                     pcontext->config.tint_result_range_min,
                                     pcontext->config.temp_result_range_max,
                                     pcontext->config.tint_result_range_max,
                                     pcontext->config.gw_dtemp,
                                     pcontext->config.gw_dtint,
                                     pcontext->config.prev_inv_temp,
                                     pcontext->config.prev_tint,
                                     &illuminant->rg,
                                     &illuminant->bg,
                                     temp_nonclamp, tint_nonclamp,
                                     out_inv_temp_clamp, out_tint_clamp);
            }
            else
            {
                *conf_out = 0.0f;
            }
        }
    }

    return err;
}

static inline void calculate_second_companent_gain(const float32_t prev_gain,
                                                const float32_t *new_first_gain,
                                                float32_t *new_second_gain)
{
    if ((new_first_gain != NULL) && (new_second_gain != NULL))
    {
        *new_second_gain = *new_first_gain / prev_gain;
    }
}

static inline void calculate_optimal_gains(const float32_t gains_from_sensor[MAX_CHANNELS],
                                           const awb_ratios_t illuminant,
                                           const float32_t static_gains[MAX_CHANNELS],
                                           const float32_t second_component_threshold,
                                           const float32_t conf,
                                           awb_ratios_t *last_rg_bg,
                                           median_filter_t *rg_median,
                                           median_filter_t *bg_median,
                                           float32_t gains[MAX_CHANNELS],
                                           float32_t fine_gains[MAX_CHANNELS])
{
    awb_ratios_t smoothed;

    if ((gains_from_sensor != NULL) &&
        (static_gains != NULL) &&
        (rg_median != NULL) &&
        (bg_median != NULL) &&
        (gains != NULL) &&
        (fine_gains != NULL))
    {
        if (rg_median->stage == 0)
        {
            init_median_filter(illuminant.rg, rg_median);
            last_rg_bg->rg = illuminant.rg; /* PRQA S 2814 */
        }

        if (bg_median->stage == 0)
        {
            init_median_filter(illuminant.bg, bg_median);
            last_rg_bg->bg = illuminant.bg; /* PRQA S 2814 */
        }

        smoothed.rg = get_median(illuminant.rg, rg_median);
        smoothed.bg = get_median(illuminant.bg, bg_median);
        smoothed.rg = fasterexp((conf * fasterlog(smoothed.rg + FLT_EPSILON)) + ((1.0f - conf) * fasterlog(last_rg_bg->rg + FLT_EPSILON)));
        smoothed.bg = fasterexp((conf * fasterlog(smoothed.bg + FLT_EPSILON)) + ((1.0f - conf) * fasterlog(last_rg_bg->bg + FLT_EPSILON)));
        last_rg_bg->rg = smoothed.rg;
        last_rg_bg->bg = smoothed.bg;

        gains[GREEN] = static_gains[GREEN];
        gains[RED] = gains[GREEN] / smoothed.rg;
        gains[BLUE] = gains[GREEN] / smoothed.bg;

        bool check_second_component_r = (fabsf(log2f(gains[RED] / gains_from_sensor[RED])) < second_component_threshold) ? true : false;     /* PRQA S 1056 */
        bool check_second_component_g = (fabsf(log2f(gains[GREEN] / gains_from_sensor[GREEN])) < second_component_threshold) ? true : false; /* PRQA S 1056 */
        bool check_second_component_b = (fabsf(log2f(gains[BLUE] / gains_from_sensor[BLUE])) < second_component_threshold) ? true : false;   /* PRQA S 1056 */

        calculate_second_companent_gain(gains_from_sensor[RED],
                                        &gains[RED], &fine_gains[RED]);
        calculate_second_companent_gain(gains_from_sensor[GREEN],
                                        &gains[GREEN], &fine_gains[GREEN]);
        calculate_second_companent_gain(gains_from_sensor[BLUE],
                                        &gains[BLUE], &fine_gains[BLUE]);

        if ((check_second_component_r) && (check_second_component_g) && (check_second_component_b))
        {
            copy_vec3(gains_from_sensor, gains);
        }
    }
}

int32_t awb_process(awb_context_t *context,
                    const awb_config_t *config,
                    const awb_statistics_t *statistics,
                    const awb_tables_t* tables,
                    float32_t gains[MAX_CHANNELS],
                    float32_t fine_gains[MAX_CHANNELS],
                    uint32_t *awb_valid_blocks,
                    float32_t *temp_nonclamp,
                    float32_t *tint_nonclamp,
                    float32_t *out_inv_temp_clamp,
                    float32_t *out_tint_clamp)
{
    int32_t err = 0;

    // isp_tracelog_sv("awb luts = %d %d %.2f %.2f %.2f %.2f %.2f", tables->gray_hull_len, tables->planck_len,
    //     tables->planck_temp_table[0],
    //     tables->planck_lrg_table[0],
    //     tables->planck_lbg_table[0],
    //     tables->gray_hull_temp[0],
    //     tables->gray_hull_tint[0]
    //     );

    if ((context != NULL) &&
        (statistics != NULL) &&
        (gains != NULL) &&
        (fine_gains != NULL))
    {
        awb_private_context_t *pcontext = awb_private_context(context);

        if (pcontext != NULL)
        {
            if (context->init == 0)
            {
                (void)memset(context, 0, sizeof(awb_context_t));
                err = awb_init(pcontext, config);
                context->init = 1;
            }
            else
            {
                err = awb_update_config(pcontext, config);
            }

            if (err == 0)
            {
                awb_ratios_t illuminant = {1.0f, 1.0f};
                float32_t conf = 0.0f;

                err = estimate_illuminant(pcontext, statistics, tables, &illuminant, &conf, temp_nonclamp, tint_nonclamp, out_inv_temp_clamp, out_tint_clamp);
                isp_tracelog_v("valid blocks, illu, temp, tint: %d %f %f %f %f\n", (uint32_t)roundf(pcontext->config.block_count * conf),
                illuminant.rg, illuminant.bg, *temp_nonclamp, *tint_nonclamp);

                if (conf > 0.0f)
                {
                    *awb_valid_blocks = (uint32_t)roundf(pcontext->config.block_count * conf);
                    copy_vec3(pcontext->last_fine_gains, fine_gains);
                    calculate_optimal_gains(statistics->gains_from_sensor,
                                            illuminant,
                                            pcontext->config.static_gains,
                                            pcontext->config.second_component_threshold,
                                            conf,
                                            &pcontext->last_rg_bg,
                                            &pcontext->rg_median,
                                            &pcontext->bg_median,
                                            gains,
                                            fine_gains);
                    copy_vec3(gains, pcontext->last_gains);
                    copy_vec3(fine_gains, pcontext->last_fine_gains);
                }
                else
                {
                    copy_vec3(pcontext->last_gains, gains);
                    copy_vec3(pcontext->last_fine_gains, fine_gains);
                }
            }
        }
    }
    else
    {
        err = EINVAL;
    }

    return err;
}

/* PRQA S 0781 -- */
/* PRQA S 1055 -- */
/* PRQA S 3450 -- */
/* PRQA S 0604 -- */
/* PRQA S 3448 -- */
/* PRQA S 3408 -- */
/* PRQA S 0492 -- */
/* PRQA S 3218 -- */
