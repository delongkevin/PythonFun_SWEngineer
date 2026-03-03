/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           isp_process.h
 *  @brief          Function for asynchronously process of ISP statistic and
 *                  update of AE and AWB settings
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

/* PRQA S 1055 ++ */
/* PRQA S 1056 ++ */
/* PRQA S 3408 ++ */
/* PRQA S 0781 ++ */
/* PRQA S 3450 ++ */
/* PRQA S 0491 ++ */
/* PRQA S 0602 ++ */
/* PRQA S 3138 ++ */
/* PRQA S 0715 ++ */
/* PRQA S 0604 ++ */
/* PRQA S 1031 ++ */
/* PRQA S 3218 ++ */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "isp_process.h"
#include "third_party/fastapprox/fastpow.h"
#ifdef MAGNA_PSA
#include <pthread.h>

typedef struct
{
     uint8_t rgb[15*15*3];
}small_rgb_frame_t;


static small_rgb_frame_t dbg_dump_data[MAX_CAMERAS_NUM] = {0};
static small_rgb_frame_t dbg_dump_data_2 = {0};
static uint32_t dbg_dump_upd[MAX_CAMERAS_NUM] = {0};
static uint32_t dbg_dump_num[MAX_CAMERAS_NUM] = {0};
static pthread_mutex_t dbg_dump_mtx = PTHREAD_MUTEX_INITIALIZER; /* PRQA S 1053 */
static pthread_cond_t dbg_dump_cond = PTHREAD_COND_INITIALIZER; /* PRQA S 1053 */
static pthread_t g_dbg_dump_thrd = 0;

void* dump_debug_frame_async(void* not_used)/* PRQA S 3408 *//* PRQA S 3206 */
{
    while (ever())/* PRQA S 2870 *//* PRQA S 2740 */
    {
        uint32_t zero[MAX_CAMERAS_NUM] = {0};
        (void)pthread_mutex_lock(&dbg_dump_mtx);
        while (memcmp(dbg_dump_upd, zero, sizeof(dbg_dump_upd)) == 0)
        {
            (void)pthread_cond_wait(&dbg_dump_cond, &dbg_dump_mtx);
        }

        uint32_t cam_num = 0U;

        while (dbg_dump_upd[cam_num] == 0U)
        {
            cam_num += 1U;
        }

        dbg_dump_upd[cam_num] = 0U;
        (void)memcpy(dbg_dump_data_2.rgb, dbg_dump_data[cam_num].rgb, sizeof(small_rgb_frame_t));

        (void)pthread_mutex_unlock(&dbg_dump_mtx);

        uint32_t N = dbg_dump_num[cam_num];
        dbg_dump_num[cam_num] += 1;
        char buf[32] = {0};
        (void)sprintf(buf, "thumbnail_%d_%04d.rgb", cam_num, N);
        FILE* f = fopen(buf, "wb");
        if (f != NULL)
        {
            (void)fwrite(dbg_dump_data_2.rgb, sizeof(small_rgb_frame_t), 1, f);
            (void)fclose(f);
            isp_tracelog_i("[%d] DUMP FRAME %d\n", cam_num, N); /* PRQA S 2743 */
        }
        else
        {
            isp_tracelog_i("DUMP FRAME FAILED\n"); /* PRQA S 2743 */
        }

    }

    return NULL;
}

void dump_debug_frame_init(void)
{
    (void)pthread_mutex_init(&dbg_dump_mtx, NULL);
    (void)pthread_cond_init(&dbg_dump_cond, NULL);
    (void)pthread_create(&g_dbg_dump_thrd, 0, dump_debug_frame_async, 0); /* PRQA S 3635 */
}


#ifdef _UTESTS
static uint32_t frame_counter[MAX_CAMERAS_NUM] = {0};
#endif


static void dump_debug_frame(uint32_t cam_num, const float32_t bin_centers[], const struct ISP_data *data)
{
    const drvISP_ExpStatRecord_t* exp_data = data->expStatsData.pEntry; /* PRQA S 2814 */
    const drvISP_WbStatRecord_t* wb_data = data->wbStatsData.pEntry; /* PRQA S 2814 */

    const uint32_t width = 15;
    const uint32_t stride = width * 3; /* PRQA S 2984 */

#ifndef _UTESTS
    static uint32_t frame_counter[MAX_CAMERAS_NUM] = {0};
#endif

    if ((exp_data != NULL) &&
        (wb_data != NULL) &&
        (cam_num < MAX_CAMERAS_NUM))
    {
        uint32_t N = frame_counter[cam_num];
        frame_counter[cam_num] += 1;

        if ((N % 32) == 0)
        {
            uint32_t i;
            (void)pthread_mutex_lock(&dbg_dump_mtx);

            for (i = 0; i < ISP_AWB_NUM_ZONES; i++)
            {
                uint32_t x = i % width;
                uint32_t y = i / width;

                float32_t bin2 = 65536.0f -
                                (float32_t)exp_data[i].Bin0 -
                                (float32_t)exp_data[i].Bin1 -
                                (float32_t)exp_data[i].Bin3 -
                                (float32_t)exp_data[i].Bin4;

                float32_t Y = ((float32_t)exp_data[i].Bin0 * bin_centers[0]) + /* PRQA S 2824 */
                              ((float32_t)exp_data[i].Bin1 * bin_centers[1]) +
                              (bin2 * bin_centers[2]) +
                              ((float32_t)exp_data[i].Bin3 * bin_centers[3]) +
                              ((float32_t)exp_data[i].Bin4 * bin_centers[4]);
                Y /= 65536.0f;

                float32_t r_rat = convert_fixed_to_float(wb_data[i].Avg_RG, 8, 8);
                float32_t b_rat = convert_fixed_to_float(wb_data[i].Avg_BG, 8, 8);
                const float32_t weight_r = 0.299f;
                const float32_t weight_b = 0.114f;
                const float32_t weight_g = 1.f - weight_b - weight_r;
                float32_t g = Y / ((weight_r * r_rat) + weight_g + (weight_b * b_rat));
                float32_t r = r_rat * g;
                float32_t b = b_rat * g;

                dbg_dump_data[cam_num].rgb[(y * stride) + (x * 3) + 0] = (uint8_t)clampf32((r * 255) + 0.5f, 0.f, 255.f);  /* PRQA S 2984 */ /* PRQA S 2985 */
                dbg_dump_data[cam_num].rgb[(y * stride) + (x * 3) + 1] = (uint8_t)clampf32((g * 255) + 0.5f, 0.f, 255.f);
                dbg_dump_data[cam_num].rgb[(y * stride) + (x * 3) + 2] = (uint8_t)clampf32((b * 255) + 0.5f, 0.f, 255.f);
            }
            dbg_dump_upd[cam_num] = 1;
            (void)pthread_cond_signal(&dbg_dump_cond);
            (void)pthread_mutex_unlock(&dbg_dump_mtx);
        }
    }
}

static inline void calculate_bin_centers(float32_t bin_centers[],
                                         float32_t hist_threshold_0,
                                         float32_t hist_threshold_1,
                                         float32_t hist_threshold_3,
                                         float32_t hist_threshold_4)
{
    float32_t th_l = 0.0f;
    float32_t th_h = hist_threshold_0 / 256.0f;

    if (bin_centers != NULL)
    {
        bin_centers[0] = th_l + ((th_h - th_l) / 2);
        th_l = hist_threshold_0 / 256.0f;
        th_h = hist_threshold_1 / 256.0f;
        bin_centers[1] = th_l + ((th_h - th_l) / 2);
        th_l = hist_threshold_1 / 256.0f;
        th_h = hist_threshold_3 / 256.0f;
        bin_centers[2] = th_l + ((th_h - th_l) / 2);
        th_l = hist_threshold_3 / 256.0f;
        th_h = hist_threshold_4 / 256.0f;
        bin_centers[3] = th_l + ((th_h - th_l) / 2);
        th_l = hist_threshold_4 / 256.0f;
        th_h = 1.0f;
        bin_centers[4] = th_l + ((th_h - th_l) / 2);
    }
}
#endif

#ifdef MAGNA_PSA
static void init_awb_stats(
    const float32_t bin_centers[5],
    const struct ISP_data *data,
    const float32_t thresholds[4],
    const float32_t pix_count_threshold,
    float32_t y_low_threshold,
    float32_t y_up_threshold,
    awb_statistics_block_t blocks[])
{
    if ((bin_centers != NULL) && (data != NULL) && (blocks != NULL))
    {
        uint32_t i;

        for (i = 0U; i < ISP_AWB_NUM_ZONES; i++)
        {
            const float32_t total = 0x10000;

            drvISP_ExpStatRecord_t exp_stat = data->expStatsData.pEntry[i];
            drvISP_WbStatRecord_t wb_stat = data->wbStatsData.pEntry[i];


            float32_t histogram_5bins[5];
            histogram_5bins[0] = (float32_t)exp_stat.Bin0 / total;
            histogram_5bins[1] = (float32_t)exp_stat.Bin1 / total;
            histogram_5bins[3] = (float32_t)exp_stat.Bin3 / total;
            histogram_5bins[4] = (float32_t)exp_stat.Bin4 / total;
            histogram_5bins[2] = 1.f - histogram_5bins[0] - histogram_5bins[1] - histogram_5bins[3] - histogram_5bins[4];

            uint32_t j;
            float32_t max = 0.0f;
            uint32_t max_index = 0;
            float32_t weight[5] = {0.0f, thresholds[1], ((thresholds[1] * 0.5f) + (thresholds[2] * 0.5f)), thresholds[3], 255.0f};
            for (j = 0; j < 4; j++)
            {
                float32_t sum = histogram_5bins[j] + histogram_5bins[j + 1];
                if (max < sum)
                {
                    max = sum;
                    max_index = j;
                }
            }
            float32_t mid_brightness =
                    ((weight[max_index] / 255.f) * histogram_5bins[max_index]) +
                    ((weight[max_index + 1] / 255.f) * histogram_5bins[max_index + 1]);
            uint32_t pix_count = wb_stat.PixelCount;

            blocks[i].ratios.rg = convert_fixed_to_float(wb_stat.Avg_RG, 4,8);
            blocks[i].ratios.bg = convert_fixed_to_float(wb_stat.Avg_BG, 4,8);
            float32_t y_norm = mid_brightness;
            blocks[i].y = y_norm;
            float32_t bin4_adaptive_threshold = ISP_MAX((float32_t)data->expStatsData.Glob_Avg_Bin4, (total * 0.05f));
            blocks[i].conf = ((y_norm > y_low_threshold) && (y_norm < y_up_threshold) && ((float32_t)exp_stat.Bin4 <= bin4_adaptive_threshold) &&
                             ((float32_t)pix_count > pix_count_threshold)) ? 1.0f : 0.0f;
        }
    }
}
#else
static void init_awb_stats(
    const struct ISP_data *data,
    float32_t y_low_threshold,
    float32_t y_up_threshold,
    uint32_t cfa_pattern,
    float32_t pow_value,
    float32_t *out_ave_lr,
    float32_t *out_ave_lg,
    float32_t *out_ave_lb,
    awb_statistics_block_t blocks[])
{
    if ((data != NULL) && (blocks != NULL))
    {
        uint32_t i;
        uint32_t j;
        uint32_t z = 0;
        const float32_t max_value = (float32_t)((1u << 10u) - 1);
        float32_t inv_pix_norm_value = 1.0f / (data->n_pix * max_value);

        float32_t ave_lr = 0.0f;
        float32_t ave_lg = 0.0f;
        float32_t ave_lb = 0.0f;

        for (i = 0; i < 64; i++)
        {
            for (j = 0; j < 8; j++)
            {
                float32_t cfa[4];
                cfa[(cfa_pattern >> 6) & 3] = (float32_t)data->h3a_data->packets[i].data[j].subsampleAccum[0];
                cfa[(cfa_pattern >> 4) & 3] = (float32_t)data->h3a_data->packets[i].data[j].subsampleAccum[1];
                cfa[(cfa_pattern >> 2) & 3] = (float32_t)data->h3a_data->packets[i].data[j].subsampleAccum[2];
                cfa[(cfa_pattern >> 0) & 3] = (float32_t)data->h3a_data->packets[i].data[j].subsampleAccum[3];
                float32_t b = cfa[0];
                float32_t gb = cfa[1];
                float32_t gr = cfa[2];
                float32_t r = cfa[3];

                float32_t g_ave = (gr + gb) * 0.5f;
                float32_t gn = fasterpow(g_ave * inv_pix_norm_value, pow_value);
                float32_t rn = fasterpow(r * inv_pix_norm_value, pow_value);
                float32_t bn = fasterpow(b * inv_pix_norm_value, pow_value);
                ave_lr += fasterlog(rn);
                ave_lg += fasterlog(gn);
                ave_lb += fasterlog(bn);

                float32_t rn_clamp = clampf32(rn, y_low_threshold, y_up_threshold);
                float32_t gn_clamp = clampf32(gn, y_low_threshold, y_up_threshold);
                float32_t bn_clamp = clampf32(bn, y_low_threshold, y_up_threshold);
                bool is_valid = (rn_clamp == rn) && (gn_clamp == gn) && (bn_clamp == bn);
                blocks[z].y = gn;
                blocks[z].conf = is_valid;

                if (is_valid == false)
                {
                    blocks[z].ratios.rg = 1.f;
                    blocks[z].ratios.bg = 1.f;
                }
                else
                {
                    blocks[z].ratios.rg = rn / (gn + FLT_EPSILON);
                    blocks[z].ratios.bg = bn / (gn + FLT_EPSILON);
                }
                z++;
            }
        }

        *out_ave_lr = ave_lr / (float32_t)data->n_pix;
        *out_ave_lg = ave_lg / (float32_t)data->n_pix;
        *out_ave_lb = ave_lb / (float32_t)data->n_pix;
    }
}
#endif


#ifdef MAGNA_PSA
static uint32_t read_12bit_le(const uint8_t* row, uint32_t offset)
{
    uint16_t byte_offset = (((uint16_t)3u) * offset) / ((uint16_t)2u);
    uint16_t bitshift = (offset & (uint16_t)1u) * ((uint16_t)4u);
    uint16_t value = *((uint16_t *)&row[byte_offset]);
    value >>= bitshift;
    value &= 0xFFF;
    return value;
}

#else

static uint16_t get_uint16_t_data(const uint8_t row[], uint16_t offset)
{
    return ((*((uint16_t *)&row[(2u * offset)])) & 0xFFF);
}
#endif

#ifdef MAGNA_PSA
bool parse_histogram(const uint8_t* stat,uint32_t hist[244])
{
    bool ret = true;
    uint32_t N = (read_12bit_le(stat, 8) & (~3)) << 10;
    N |= read_12bit_le(stat, 9);
    uint32_t counter = 0;
    uint32_t i = 10;
    uint32_t sum = 0;
    float32_t black_level = 168.f;

    for (; counter < 244; i+=2, counter++)
    {
        uint32_t v1 = (read_12bit_le(stat, i) & (~3)) << 10;
        v1 |= read_12bit_le(stat, i + 1);
        hist[counter] = v1;
        sum += v1;
    }

    if (stat[0] != 0xb0 || N != sum)
    {
        ret = false;
        isp_tracelog_e("invalid hist\n");
    }
    return ret;
}
#else

bool parse_histogram(const uint8_t* stat,uint32_t hist[244], uint32_t *pixel_count)
{
    bool ret = true;
    uint32_t N = get_uint16_t_data(stat, 8) << 12;
    N |= get_uint16_t_data(stat, 9);
    uint32_t counter = 0;
    uint32_t i = 10;
    uint32_t sum = 0;

    for (; counter < 244; i+=2, counter++)
    {
        uint32_t v1 = get_uint16_t_data(stat, i) << 12;
        v1 |= get_uint16_t_data(stat, i + 1);
        hist[counter] = v1;
        sum += v1;
    }
    *pixel_count = sum;

    if (stat[0] != 0xb0 || N != sum)
    {
        ret = false;
        isp_tracelog_e("invalid hist: 0x%x %d\n", stat[0], N);
    }
    return ret;
}
#endif



static float32_t calc_white_q_from_244_hist(
    const ae_input_stats_t* stats,
    float32_t white_thresh_linear
)
{
    uint32_t first = lower_bound_f32(stats->full_sensor_hist_weight, stats->hist_bins_num, white_thresh_linear);
    const uint32_t* full_sensor_hist = stats->full_sensor_hist;

    uint32_t sum = 0;
    uint32_t i;
    if (first > 0)
    {
        float32_t l = stats->full_sensor_hist_weight[first - 1];
        float32_t r = stats->full_sensor_hist_weight[first];
        float32_t coeff = (white_thresh_linear - l) / (r - l);
        float32_t first_w = clampf32(1 - coeff, 0.f, 1.f);

        sum+= (uint32_t)(full_sensor_hist[first - 1]*first_w + 0.5f);
    }

    for (i = first; i < stats->hist_bins_num; i++)
    {
        sum+= full_sensor_hist[i];
    }

    float32_t i_pixel_count = 1.f / stats->full_sensor_hist_pix_count;

    return i_pixel_count*sum;
}

static bool calc_br_143_147(uint32_t camera_num,
                     const uint8_t* stat,
                     uint32_t white_bins_reject,
                     float32_t* brightness,
                     uint32_t full_sensor_hist[512],
                     const float32_t** weights,
                     uint32_t* bins_num,
                     uint32_t* full_sensor_hist_count,
                     float32_t *snr,
                     float32_t black_level,
                     float32_t long_exposure,
                     float32_t sensor_dg,
                     float32_t white_q_pixel_percentage)
{
    bool ret = true;
    uint32_t pixel_count = 0;
    uint32_t *hist = full_sensor_hist;

    if (sensor_custom_operations.parse_histogram)
    {
        ret = (*sensor_custom_operations.parse_histogram)(stat, hist, &pixel_count, bins_num, weights);
    }
    else
    {
        ret = false;
    }

    if (sensor_custom_operations.calc_snr)
    {
        (*sensor_custom_operations.calc_snr)(hist, pixel_count, *bins_num, sensor_dg, snr);
    }

    float32_t br = 0.f;
    int32_t i = 0;

    *full_sensor_hist_count = pixel_count;

    float32_t bright_pixels_n = 0;

    uint32_t half_pixel_num = (pixel_count * 205) >> 8;

    uint32_t N = bins_num[0];

    if (ret)
    {
        const float32_t* weight_table = *weights;
        if (g_isp_log_stats != NULL && g_isp_log_stats[0] > 0.5f)
        {
            if ((g_isp_log_cam == NULL) || ((uint32_t)(*g_isp_log_cam) == MAX_CAMERAS_NUM) || ((uint32_t)(*g_isp_log_cam) == camera_num))
            {
                for (i = 0; i < (N-1); i++)
                {
                    isp_tracelog_v("%d ", hist[i]); /* PRQA S 2743 */
                }
                isp_tracelog_v("%d\n", hist[i]); /* PRQA S 2743 */
            }
        }

        for (i = 0; i < N; i++)
        {
            if ((bright_pixels_n > half_pixel_num))
            {
                break;
            }

            float32_t pix_count = hist[i];
            float32_t pix_value = weight_table[i];
            pix_value = ISP_MAX(pix_value - black_level, 0.f);

            br += pix_value * pix_count;
            bright_pixels_n += pix_count;
        }

        bright_pixels_n = ISP_MAX(bright_pixels_n, 1.f);
        brightness[0] = (br / bright_pixels_n) / weight_table[N - 1];
    }

    return ret;
}

#ifdef MAGNA_PSA
ae_input_stats_t read_stats(const struct ISP_data* data,
                            const float32_t thresholds[4],
                            uint32_t awb_pix_count_threshold,
                            float32_t y_low_threshold,
                            float32_t y_up_threshold,
                            uint32_t dump_statistic_flag,
                            uint32_t camera_num)
{
    ae_input_stats_t ret = {0};

    if ((data != NULL) && (thresholds != NULL))
    {
        ret.histogram_5bins[0] = (float32_t)data->expStatsData.Glob_Avg_Bin0 / 0x10000;
        ret.histogram_5bins[1] = (float32_t)data->expStatsData.Glob_Avg_Bin1 / 0x10000;
        ret.histogram_5bins[3] = (float32_t)data->expStatsData.Glob_Avg_Bin3 / 0x10000;
        ret.histogram_5bins[4] = (float32_t)data->expStatsData.Glob_Avg_Bin4 / 0x10000;
        ret.histogram_5bins[2] = 1.f - ret.histogram_5bins[0] - ret.histogram_5bins[1] - ret.histogram_5bins[3] - ret.histogram_5bins[4];

        float32_t bin_centers[5] = {0.1f, 0.3f, 0.5f, 0.7f, 0.9f};
        calculate_bin_centers(bin_centers, thresholds[0],
            thresholds[1],
            thresholds[2], thresholds[3]);

        float32_t zerofix_adaptive = (1.f - (clampf32(ret.histogram_5bins[1], 0.f, 0.002f) / 0.002f)) / 255.f ;
        ret.brightness =
                (ret.histogram_5bins[0] / 255.f) +
                ((thresholds[0] / 255.f) * ret.histogram_5bins[1]) +
                ((((thresholds[1] * 0.5f) + (thresholds[2] * 0.5f)) / 255.f) * ret.histogram_5bins[2]) +
                ((thresholds[3] / 255.f) * ret.histogram_5bins[3]) +
                ret.histogram_5bins[4];

        ret.brightness -= zerofix_adaptive;

        uint32_t i;
        float32_t max = 0.0f;
        uint32_t max_index = 0;
        float32_t weight[5] = {0.0f, thresholds[1], ((thresholds[1] * 0.5f) + (thresholds[2] * 0.5f)), thresholds[3], 255.0f};
        for (i = 0; i < 4; i++)
        {
            float32_t sum = ret.histogram_5bins[i] + ret.histogram_5bins[i + 1];
            if (max < sum)
            {
                max = sum;
                max_index = i;
            }
        }

        float32_t mid_brightness =
                ((weight[max_index] / 255.f) * ret.histogram_5bins[max_index]) +
                ((weight[max_index + 1] / 255.f) * ret.histogram_5bins[max_index + 1]);

        ret.brightness = mid_brightness;

        init_awb_stats(bin_centers,
                       data,
                       thresholds,
                       (float32_t)awb_pix_count_threshold,
                       y_low_threshold,
                       y_up_threshold,
                       ret.awb_stat);

        if (g_isp_log_stats != NULL && g_isp_log_stats[0] > 0.5f)
        {
            if ((g_isp_log_cam == NULL) || ((uint32_t)(*g_isp_log_cam) == MAX_CAMERAS_NUM) || ((uint32_t)(*g_isp_log_cam) == camera_num))
            {
                isp_tracelog_i("camera %d histogram [%d %d   %d   %d %d] %.3f  %.3f \n", camera_num,  /* PRQA S 2743 */
                                                                            data->expStatsData.Glob_Avg_Bin0,
                                                                            data->expStatsData.Glob_Avg_Bin1,
                                                                            0,
                                                                            data->expStatsData.Glob_Avg_Bin3,
                                                                            data->expStatsData.Glob_Avg_Bin4,
                                                                            ret.brightness,
                                                                            (1.f / 65536.f)*((float32_t)data->expStatsData.Glob_Avg_Bin4 + data->expStatsData.Glob_Avg_Bin3)
                                                                            );
            }
        }
        if ((g_isp_log_level != NULL) &&
            ((ISP_LOG_LEVEL_DEBUG) <= *g_isp_log_level) &&
            (dump_statistic_flag > 0))
        {
            dump_debug_frame(camera_num, bin_centers, data);
        }
    }

    return ret;
}
#endif

#ifdef MAGNA_PSA
void isp_algorithms(
    uint32_t camera_num,
    uint32_t phase,
    const struct ar014x_sensor_data* sensorData,
    const struct ISP_data* ispData,
    const struct ISP_config* ispConfig,
    alg_history_data_t* hist_data,
    parameters_storage_t* storage,
    const ae_auto_tables_t* tables,
    ae_params_for_frame_t* out
    )
{
    if ((sensorData != NULL) &&
        (ispData    != NULL) &&
        (ispConfig  != NULL) &&
        (hist_data  != NULL) &&
        (storage    != NULL) &&
        (tables     != NULL) &&
        (out        != NULL))
    {
        if (phase == 0)
        {
            float32_t thresholds_exp_stat[4] = {ispConfig->expStatsCfg.Hist_Thresh_01
                , ispConfig->expStatsCfg.Hist_Thresh_12
                , ispConfig->expStatsCfg.Hist_Thresh_23
                , ispConfig->expStatsCfg.Hist_Thresh_34
                };

            bool input_is_ok = true;
            bool again_comp_is_ok = true;

            float32_t pix_count_thresh = get_param_check(storage, AWB_IN_PIX_COUNT_THRESHOLD, &input_is_ok); /* PRQA S 2983 */
            float32_t y_low_threshold = get_param_check(storage, AWB_IN_LOW_BRIGHTNESS_THRESHOLD, &input_is_ok); /* PRQA S 2983 */
            float32_t y_up_threshold = get_param_check(storage, AWB_IN_UPPER_BRIGHTNESS_THRESHOLD, &input_is_ok); /* PRQA S 2983 */
            uint32_t dump_statistic_flag = (uint32_t)get_param_check(storage, ALG_DUMP_STATISTIC, &input_is_ok); /* PRQA S 2983 */
            float32_t again_comp = get_param_check(storage, HISTORY_SENSOR_VIRTUAL_GAIN_T0, &again_comp_is_ok); /* PRQA S 2983 */
            again_comp = (again_comp_is_ok) ? again_comp : 1.f; /* PRQA S 2983 */
            ae_input_stats_t stats = read_stats(ispData,
                                                thresholds_exp_stat,
                                                (uint32_t)pix_count_thresh,
                                                y_low_threshold,
                                                y_up_threshold,
                                                dump_statistic_flag,
                                                camera_num
                                                ); /* PRQA S 2983 */
            float32_t brightness = 0;
            bool stat_ret = calc_br_143_147(camera_num, sensorData->embeddedStats[0], 4, &brightness);

            if (g_isp_log_stats != NULL && g_isp_log_stats[0] > 0.5f)
            {
                if ((g_isp_log_cam == NULL) || ((uint32_t)(*g_isp_log_cam) == MAX_CAMERAS_NUM) || ((uint32_t)(*g_isp_log_cam) == camera_num))
                {
                    isp_tracelog_i("5bin, sensor brightness, comp: %f %f %f\n", stats.brightness, brightness, brightness * again_comp); /* PRQA S 2743 */
                }
            }

            if (stat_ret == true)
            {
                set_param(storage, AVE_BR, brightness * again_comp);
            }
            set_param_if_empty(storage, ISP_INTERNAL_AVE_BR, get_param(storage, AVE_BR));

            parse_regs_from_emb_line(storage, sensorData, camera_num);

            if (input_is_ok)
            {
                algorithm_pipeline(&hist_data->ae_context, camera_num, storage, &stats
                            , tables, 0, out);
            }
            else
            {
                isp_tracelog_e("algorithm input parameters are absent\n"); /* PRQA S 2743 */
            }
        }
        else
        {
            algorithm_pipeline(&hist_data->ae_context, camera_num, storage, 0
                            , tables, phase, out);
        }
    }
}
#else
void isp_algorithms(
    uint32_t camera_num,
    uint32_t phase,
    const struct ar014x_sensor_data* sensorData,
    const struct ISP_data* ispData,
    alg_history_data_t* hist_data,
    parameters_storage_t* storage,
    const ae_auto_tables_t* tables,
    ae_params_for_frame_t* out
    )
{
    if ((sensorData != NULL) &&
        (ispData    != NULL) &&
        (hist_data  != NULL) &&
        (storage    != NULL) &&
        (tables     != NULL) &&
        (out        != NULL))
    {
        if (phase == 0)
        {

            if (sensor_custom_operations.parse_embedded_data)
            {
                (*sensor_custom_operations.parse_embedded_data)(storage, sensorData, camera_num);
            }

            bool input_is_ok = true;
            bool again_comp_is_ok = true;
            float32_t y_low_threshold = get_param_check(storage, AWB_IN_LOW_BRIGHTNESS_THRESHOLD, &input_is_ok); /* PRQA S 2983 */
            float32_t y_up_threshold = get_param_check(storage, AWB_IN_UPPER_BRIGHTNESS_THRESHOLD, &input_is_ok); /* PRQA S 2983 */
            float32_t white_q_pixel_percentage = get_param_check(storage, WHITE_Q_PIXEL_PERCENT, &input_is_ok); /* PRQA S 2983 */
            float32_t global_nm = get_param_check(storage, AE_IN_GLOBAL_NM, &input_is_ok);
            int32_t delay_nm = (int32_t)get_param_check(storage, SENSOR_IN_DELAY_NM, &input_is_ok);
            int32_t delay_dm = (int32_t)get_param_check(storage, SENSOR_IN_DELAY_DM, &input_is_ok);
            int32_t delay = cmp_f32(global_nm, 0.0f) ? delay_dm : delay_nm;
            delay = clamp(delay, 0, (circular_buffer_max_sz-1));
            float32_t again_comp = get_param_check(storage, ISP_INTERNAL_T0_PREPIPE, &again_comp_is_ok); /* PRQA S 2983 */
            float32_t black_level = get_param_check(storage, SENSOR_BLACK_LEVEL_DEFAULT, &input_is_ok); /* PRQA S 2983 */
            float32_t long_exposure_threshold = get_param_check(storage, SENSOR_LONG_EXPOSURE_THRESHOLD, &input_is_ok); /* PRQA S 2983 */
            uint32_t cfa_pattern = (uint32_t)get_param_check(storage, AWB_IN_CFA_PATTERN, &input_is_ok); /* PRQA S 2983 */
            float32_t h3a_gamma = 1.0f / get_param_check(storage, STATISTIC_IN_GAMMA, &input_is_ok); /* PRQA S 2983 */
            float32_t sensor_dg = get_param_check(storage, ISP_INTERNAL_EMB_LINE_DLO_GAIN, &input_is_ok) / 512.0f; /* PRQA S 2983 */

            again_comp = (again_comp_is_ok) ? again_comp : 1.f; /* PRQA S 2983 */
            ae_input_stats_t stats = {0};
            memset(&stats, 0, sizeof(ae_input_stats_t));
            float32_t ave_lr = 0.0f;
            float32_t ave_lg = 0.0f;
            float32_t ave_lb = 0.0f;

            init_awb_stats(ispData,
                           y_low_threshold,
                           y_up_threshold,
                           cfa_pattern,
                           h3a_gamma,
                           &ave_lr,
                           &ave_lg,
                           &ave_lb,
                           stats.awb_stat); /* PRQA S 2983 */
            float32_t brightness = 0;
            float32_t white_q = 0;
            float32_t snr = 20.0f;
            bool stat_ret = false;

            if (input_is_ok)
            {
                stat_ret = calc_br_143_147(camera_num,
                                                sensorData->embeddedStats,
                                                4,
                                                &brightness,
                                                stats.full_sensor_hist,
                                                &stats.full_sensor_hist_weight,
                                                &stats.hist_bins_num,
                                                &stats.full_sensor_hist_pix_count,
                                                &snr,
                                                black_level,
                                                long_exposure_threshold,
                                                sensor_dg,
                                                white_q_pixel_percentage);
            }


            if (stat_ret == true)
            {
                float32_t white_q_thresh = ((long_exposure_threshold - black_level) / again_comp) + black_level;
                white_q = calc_white_q_from_244_hist(&stats, white_q_thresh);
                set_param(storage, AVE_BR, brightness * again_comp);
                set_param(storage, WHITE_Q, white_q);
                float32_t snr_smooth = get_param(storage, SNR_SMOOTH);
                float32_t out_snr = snr_smooth * snr + (1.0f - snr_smooth) * get_param(storage, SNR);
                set_param(storage, SNR, out_snr);
                set_param(storage, AWB_IN_AVE_LR, ave_lr);
                set_param(storage, AWB_IN_AVE_LG, ave_lg);
                set_param(storage, AWB_IN_AVE_LB, ave_lb);

                uint32_t log_stats = (uint32_t) g_isp_log_stats[0];
                if (g_isp_log_stats != NULL && (log_stats & 1))
                {
                    if ((g_isp_log_cam == NULL) || ((uint32_t)(*g_isp_log_cam) == MAX_CAMERAS_NUM) || ((uint32_t)(*g_isp_log_cam) == camera_num))
                    {
                        isp_tracelog_e("[%d] sensor white_q brightness, comp: %f %f * %f = %f snr %f\n", camera_num, white_q, brightness, again_comp, brightness * again_comp, out_snr); /* PRQA S 2743 */
                    }
                }
            }

            set_param_if_empty(storage, ISP_INTERNAL_AVE_BR, get_param(storage, AVE_BR));
            set_param_if_empty(storage, ISP_INTERNAL_WHITE_Q, get_param(storage, WHITE_Q));
            set_param_if_empty(storage, ISP_INTERNAL_APPLIED_COMP_TO_STATS, again_comp);


            if (input_is_ok)
            {
                algorithm_pipeline(&hist_data->ae_context, camera_num, storage, &stats
                            , tables, 0, out);
            }
            else
            {
                isp_tracelog_e("algorithm input parameters are absent\n"); /* PRQA S 2743 */
            }
        }
        else
        {
            algorithm_pipeline(&hist_data->ae_context, camera_num, storage, 0
                            , tables, phase, out);
        }
    }
}

#endif
/* PRQA S 0491 -- */
/* PRQA S 0602 -- */
/* PRQA S 0604 -- */
/* PRQA S 0715 -- */
/* PRQA S 1031 -- */
/* PRQA S 1055 -- */
/* PRQA S 0781 -- */
/* PRQA S 1056 -- */
/* PRQA S 3408 -- */
/* PRQA S 3138 -- */
/* PRQA S 3450 -- */
