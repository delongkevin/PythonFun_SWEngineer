/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           isp_process.h
 *  @brief          Auto exposure algorithm implementation
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
/* PRQA S 1401 ++ */
/* PRQA S 3450 ++ */
/* PRQA S 0781 ++ */
/* PRQA S 0602 ++ */
/* PRQA S 3138 ++ */
/* PRQA S 0491 ++ */
/* PRQA S 1461 ++ */
/* PRQA S 1031 ++ */
/* PRQA S 0604 ++ */

#include "isp_algo.h"


typedef struct
{
    float32_t gain_min;
    float32_t gain_max;
    float32_t exp_min;
    float32_t exp_max;
    float32_t gain_default;

} min_max_internal_t;
typedef struct
{
    float32_t exposure;
    float32_t gain;
} ae_input_sensor_settings_t;


typedef struct
{
    float32_t trg_br_dark;
    float32_t trg_br_light;
    float32_t previous_ratio;
    uint32_t cur_dir_counter;
} ae_internal_data_t;

static ae_internal_data_t* get_internal_data(
    ae_context_impl_t* context)
{
    return (ae_internal_data_t*)&context->ae_dummy.data[0]; /* PRQA S 2814 */ /* PRQA S 0310 */
}


static inline ae_input_sensor_settings_t mul_exposure_gain(const ae_input_sensor_settings_t* exp_gain, float32_t min_ex, float32_t max_ex, float32_t def_gain, float32_t mul, float32_t mingain, float32_t maxgain)
{
    ae_input_sensor_settings_t ret = *exp_gain; /* PRQA S 2814 */

    {
        float32_t ev = (ret.exposure * ret.gain * mul) / clampf32(def_gain, mingain, maxgain);
        float32_t round_exp = clampf32(ev, min_ex, max_ex);
        float32_t mgain = ev / round_exp;
        ret.exposure = floorf(round_exp + 0.5f);
        ret.gain = floorf((mgain * def_gain) + 0.5f);
        ret.gain = clampf32(ret.gain, mingain, maxgain);
    }
    return ret;
}

typedef struct
{
    float32_t analog;
    float32_t coeff;
    float32_t dc_gain;
} ae_dc_gain_table_t;


static uint32_t push_new_limits_nm(
    ae_context_impl_t* context,
    ae_input_sensor_settings_t* exp_gain,
    ae_input_sensor_settings_t new_exp_gain
    )
{
    uint32_t i = 0;
    uint32_t phases;

    if (exp_gain != NULL)
    {
        uint32_t deltaE = (uint32_t)fabsf(exp_gain->exposure - new_exp_gain.exposure);
        uint32_t deltaG = (uint32_t)fabsf(exp_gain->gain - new_exp_gain.gain);

        if (new_exp_gain.exposure > exp_gain->exposure)
        {
            phases = (deltaG + deltaE) / 200;
        }
        else
        {
            phases = (deltaG + deltaE) / 100;
        }

        isp_tracelog_i("night_day_preparation exp gain old[new] %d %d [%d %d]  phases = %d\n", /* PRQA S 2743 */
                (uint32_t)exp_gain->exposure,
                (uint32_t)exp_gain->gain,
                (uint32_t)new_exp_gain.exposure,
                (uint32_t)new_exp_gain.gain,
                phases
            );


        if (0 != phases)
        {
            for (i = 0; i < phases; i++)
            {
                float32_t exposure = interpolate_one(exp_gain->exposure, new_exp_gain.exposure, phases, i);
                exposure = floorf(exposure + 0.5f);
                float32_t gain = interpolate_one(exp_gain->gain, new_exp_gain.gain, phases, i);
                gain = floorf(gain + 0.5f);
                ae_context_push_param(context, AE_IN_MODE_SWITCHING, ISP_INTERNAL_AE_STATUS, i);
                ae_context_push_param(context, exposure, AE_EXPOSURE, i);
                ae_context_push_param(context, gain, AE_DLO_GAIN, i);
            }

            *exp_gain = new_exp_gain;
        }
    }

    return i;
}



static void push_mode_switch_operations_fast(
    ae_context_impl_t* context,
    float32_t gain_night,
    float32_t gain_day,
    uint32_t night_mode,
    uint32_t offset
    )
{
    float32_t analog = (night_mode == 1U) ? 7.f : 5.f;
    ae_context_push_param(context, analog, AE_ANALOG_GAIN, offset);
    ae_context_push_param(context, (night_mode == 1) ? 1.f: 0.f, AE_NIGHT_MODE, offset);
}


static min_max_internal_t night_mode_calc_min_max(
    float32_t exp_min_night,
    float32_t exp_max_night,
    float32_t exp_min_day,
    float32_t exp_max_day,
    bool night_mode_glob,
    bool night_mode_cur,
    float32_t min_gain_day,
    float32_t max_gain_day,
    float32_t min_gain_night,
    float32_t max_gain_night,
    float32_t def_gain
)
{
    min_max_internal_t out = {0};
    out.gain_default = def_gain;
    out.exp_min = exp_min_day;
    out.exp_max = exp_max_night;

    if (night_mode_glob != 0)
    {
        out.exp_min = exp_min_night;
        out.exp_max = exp_max_night;
    }
    else
    {
        out.exp_min = exp_min_day;
        out.exp_max = exp_max_day;
    }

    if (night_mode_cur != 0)
    {
        out.gain_min = min_gain_night;
        out.gain_max = max_gain_night;
    }
    else
    {
        out.gain_min = min_gain_day;
        out.gain_max = max_gain_day;
    }

    return out;
}


static void night_mode_handling(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t cam_num)
{
    min_max_internal_t out;
    ae_input_sensor_settings_t sensor_in;

    bool input_is_ok = true;
    sensor_in.exposure = get_param_check(storage, AE_EXPOSURE, &input_is_ok);
    sensor_in.gain = get_param_check(storage, AE_DLO_GAIN, &input_is_ok);

    const float32_t exp_min_night = get_param_check(storage, AE_IN_MIN_EXP_NM, &input_is_ok);
    const float32_t exp_max_night = get_param_check(storage, AE_IN_MAX_EXP_NM, &input_is_ok);
    const float32_t exp_min_day = get_param_check(storage, AE_IN_MIN_EXP_DM, &input_is_ok);
    const float32_t exp_max_day = get_param_check(storage, AE_IN_MAX_EXP_DM, &input_is_ok);
    const float32_t mode_threshold = get_param_check(storage, AE_IN_MODE_THRESHOLD, &input_is_ok);
    const float32_t day_target_delta = get_param_check(storage, AE_IN_DAY_TARGET_DELTA, &input_is_ok);
    const float32_t min_gain_day = get_param_check(storage, AE_IN_MIN_GAIN_DM, &input_is_ok);
    const float32_t max_gain_day = get_param_check(storage, AE_IN_MAX_GAIN_DM, &input_is_ok);
    const float32_t min_gain_night = get_param_check(storage, AE_IN_MIN_GAIN_NM, &input_is_ok);
    const float32_t max_gain_night = get_param_check(storage, AE_IN_MAX_GAIN_NM, &input_is_ok);
    const float32_t def_gain = get_param_check(storage, AE_IN_DEF_GAIN, &input_is_ok);
    const float32_t night_mode_glob = get_param_check(storage, AE_IN_GLOBAL_NM, &input_is_ok);
    const float32_t night_mode_glob_prev = get_param_check(storage, AE_OUT_GLOBAL_NM, &input_is_ok);
    uint32_t ae_test_force_nm_l = (uint32_t)get_param_check(storage, AE_TEST_FORCE_NM_L, &input_is_ok);
    uint32_t night_mode_cur = (uint32_t)get_param_check(storage, AE_NIGHT_MODE, &input_is_ok);
    float32_t night_target = get_param_check(storage, AE_IN_NIGHT_TARGET, &input_is_ok);

    float32_t sixty_hertz = get_param_check(storage, ALG_SIXTY_HERTZ, &input_is_ok);
    float32_t ms_convertion = get_param_check(storage, EXP_MS_CONVERTION, &input_is_ok);
    input_is_ok &= (ms_convertion > 0.0f);

    uint32_t id_af = (sixty_hertz > 0.0f) ? ANTI_FLICKER_60_EXP_MS_0 : ANTI_FLICKER_50_EXP_MS_0;
    float32_t min_exposure_antiflick = get_param_check(storage, id_af, &input_is_ok);

    if ((input_is_ok) &&
        (cmp_f32(get_param(storage, ISP_INTERNAL_AE_DISABLE), 1.f) == false) &&  /* PRQA S 3415 */
        (stats != NULL) &&
        (context != NULL))
    {
        min_exposure_antiflick/= ms_convertion;
        night_target = night_target*min_exposure_antiflick/exp_max_day;

        if (cmp_f32(night_mode_glob_prev, night_mode_glob) == false)
        {
            set_param_if_empty(storage, ISP_INTERNAL_GLOBAL_NM, night_mode_glob);
        }

        const float32_t ave_br = get_param(storage, AVE_BR);

        float32_t night_mode_target = night_target;
        float32_t day_mode_target = night_mode_target + day_target_delta;

        float32_t br_diff = 0;
        bool night_mode_changed_now = false;

        if (ae_test_force_nm_l == 0)
        {
            if (night_mode_cur == 1)
            {
                br_diff = ave_br - day_mode_target;
            }
            else
            {
                br_diff = ave_br - night_mode_target;
            }

            if (br_diff < 0.0f)
            {
                context->sum_br_diff += br_diff;

                if (night_mode_cur == 1)
                {
                    context->sum_br_diff = 0;
                }
                else if (context->sum_br_diff < -mode_threshold)
                {
                    night_mode_cur = 1;
                    night_mode_changed_now = true;
                }
                else
                {
                    br_diff = 0; /* PRQA S 2983 */
                }

            }
            else if ((br_diff > 0.0f))
            {
                context->sum_br_diff += br_diff;

                if (night_mode_cur == 0)
                {
                    context->sum_br_diff = 0;
                }

                else if (context->sum_br_diff > (10.f * mode_threshold))
                {
                    {
                        night_mode_cur = 0;
                        night_mode_changed_now = true;
                    }
                }
                else
                {
                    br_diff = 0; /* PRQA S 2983 */
                }
            }
            else
            {
                context->sum_br_diff = 0.0f;
            }
        }
        else
        {
            if (ae_test_force_nm_l == 1)
            {
                night_mode_changed_now = night_mode_cur != 1;
                night_mode_cur = 1;
            }
            else
            {
                night_mode_changed_now = night_mode_cur != 0;
                night_mode_cur = 0;
            }
        }


        out = night_mode_calc_min_max(exp_min_night, exp_max_night,
            exp_min_day, exp_max_day, night_mode_glob,
            night_mode_cur, min_gain_day, max_gain_day, min_gain_night, max_gain_night, def_gain);
        isp_tracelog_sv("camera: %d gain, exp: min max, cur_diff sum_diff, gl_n, cur_n: %.1f %.1f %.1f %.1f %.3f %.3f %0.1f %d\n", /* PRQA S 2743 */
            cam_num,
            out.gain_min,
            out.gain_max,
            out.exp_min,
            out.exp_max,
            br_diff,
            context->sum_br_diff,
            night_mode_glob,
            night_mode_cur);


        set_param_if_empty(storage, ISP_INTERNAL_AE_NM_EXP_MIN, out.exp_min);
        set_param_if_empty(storage, ISP_INTERNAL_AE_NM_EXP_MAX, out.exp_max);
        set_param_if_empty(storage, ISP_INTERNAL_AE_NM_GAIN_MIN, out.gain_min);
        set_param_if_empty(storage, ISP_INTERNAL_AE_NM_GAIN_MAX, out.gain_max);

        if (night_mode_changed_now)
        {
            isp_tracelog_e("switching modes new exposure limits: [%d..%d]\n", (uint32_t)out.exp_min, (uint32_t)out.exp_max); /* PRQA S 2743 */
            push_mode_switch_operations_fast(context, def_gain, out.gain_max, night_mode_cur, 0);
        }
    }
}


static inline void reset_direction(float32_t new_dir, ae_internal_data_t* hist_data_ae)
{
    hist_data_ae->cur_dir_counter = 0; /* PRQA S 2814 */
    hist_data_ae->previous_ratio = new_dir; /* PRQA S 2814 */
}

static inline float32_t one_direction_control(float32_t ratio, bool overbright, bool overdark, uint32_t dir_confirmation_number, ae_internal_data_t* hist_data, AE_STATUS cur_state)
{
    float32_t de = ratio;

    if (cur_state == AE_FINISHED)
    {
        de = 1.f;
        reset_direction(1.f, hist_data);
    }
    else
    {
        if (hist_data != NULL)
        {
            if (((de - 1)*(hist_data->previous_ratio - 1)) >= 0)
            {
                reset_direction(de, hist_data);
            }
            else
            {
                hist_data->cur_dir_counter++;

                if ((hist_data->cur_dir_counter < dir_confirmation_number) && (overbright == false) && (overdark == false))
                {
                    de = 1.f;
                }
                else
                {
                    reset_direction(de, hist_data);
                }
            }
        }
    }

    return de;
}


void AE_defaults(parameters_storage_t* s) /* PRQA S 3408 */
{
    set_param(s, AE_IN_FREQ, 1.f);
    set_param(s, AE_IN_ENABLED, 1.f);
    set_param(s, AE_IN_PHASE, 0.f);
    set_param(s, AE_IN_TARGET_LIGHT,  0.25f);
    set_param(s, AE_IN_TARGET_INDOOR,  0.08f);
    set_param(s, AE_IN_NIGHT_TARGET,  0.07);
    set_param(s, AE_IN_MODE_THRESHOLD,  0.1);
    set_param(s, AE_IN_MIN_EXP_DM, 16.f);
    set_param(s, AE_IN_MAX_EXP_DM, 1023.f);
    set_param(s, AE_IN_MIN_EXP_NM, 1023.f);
    set_param(s, AE_IN_MAX_EXP_NM, 2047.f);
    set_param(s, AE_IN_MIN_GAIN_DM, 512.0);
    set_param(s, AE_IN_MAX_GAIN_DM, 1024.0);
    set_param(s, AE_IN_MIN_GAIN_NM, 512.0);
    set_param(s, AE_IN_MAX_GAIN_NM, 512.0);
    set_param(s, AE_IN_DEF_GAIN, 512);
    set_param(s, AE_IN_TARGET_BR_LIGHT, 0.35f);
    set_param(s, AE_IN_TARGET_BR_NIGHT, 0.11f);
    set_param(s, AE_IN_SPEED, 0.4f);
    set_param(s, AE_IN_DAY_TARGET_DELTA, 0.04f);
    set_param(s, AE_IN_DARK_EXP, 200.f);
    set_param(s, AE_IN_MODE, 1.f);
    set_param(s, ANTI_FLICKER_EXPOSURE_ENABLED, 1.f);
    set_param(s, AE_TEST_FORCE_NM_L, 0.f);
    set_param(s, AE_TEST_FORCE_NM_G, 0.f);
    set_param(s, AE_EXPOSURE, 512.f);
    set_param(s, TARGET_AVE_BR, 0.3f);
    set_param(s, AVE_BR, 1.0f);
    set_param(s, WHITE_Q_PIXEL_PERCENT, 0.1f);
    set_param(s, SNR, 20.0f);
    set_param(s, SNR_SMOOTH, 0.05f);


    set_param(s, AE_OUT_GAIN, 512.f);
    set_param(s, AE_NIGHT_MODE, 0.f);
    set_param(s, AE_IN_GLOBAL_NM, 0);
    set_param(s, AE_OUT_GLOBAL_NM, 0);
    set_param(s, AE_FINISH_OUT, AE_FINISHED);
    set_param(s, SENSOR_WRITE, 1);
}

#ifdef MAGNA_PSA
static float32_t estimate_ev_gain(
    float32_t Hist_Thresh_01,
    float32_t Hist_Thresh_12,
    float32_t Hist_Thresh_23,
    float32_t Hist_Thresh_34,
    const float32_t histogram_5bins[5],
    float32_t target
)
{
    isp_tracelog_sv("estimate_ev_gain %.2f %.2f %.2f %.2f | %.2f %.2f %.2f %.2f %.2f | %.2f\n",
        Hist_Thresh_01,
        Hist_Thresh_12,
        Hist_Thresh_23,
        Hist_Thresh_34,
        histogram_5bins[0],
        histogram_5bins[1],
        histogram_5bins[2],
        histogram_5bins[3],
        histogram_5bins[4],
        target
    );
    float32_t sum = 0.f;
    int32_t i = 255;
    float32_t table[6] = {
        0.f,
        Hist_Thresh_01,
        Hist_Thresh_12,
        Hist_Thresh_23,
        Hist_Thresh_34,
        255.f
    };

    int32_t k;

    if (histogram_5bins != NULL)
    {
        for (k = 5; k > 0; k--)
        {
            float32_t cur_max = table[k];
            float32_t cur_min = table[k - 1];
            float32_t cur_step = histogram_5bins[k-1] / ((cur_max - cur_min) + 1);

            for (i = (int32_t)cur_max; i >= (int32_t)cur_min; i--)
            {
                sum+= cur_step;
                if (sum >= target)
                {
                    break;
                }
            }

            if (sum >= target)
            {
                break;
            }
        }
    }

    return (Hist_Thresh_23 / clampf32((float32_t)i, 1.f, 255.f));
}
#else

static float32_t estimate_pix_value_from_any_white_q(
    const uint32_t* hist,
    uint32_t pixel_count,
    uint32_t N,
    const float32_t* weight_table,
    float32_t target
)
{
    uint32_t pix_sum = 0;
    int32_t k;

    float32_t ret = 0.f;

    uint32_t target_pix_num = (uint32_t)(target*pixel_count);

    if ((hist != NULL) && (weight_table != NULL))
    {
        for (k = (N-1); k >= 0; k--)
        {
            pix_sum+= hist[k];

            if (pix_sum >= target_pix_num)
            {
                break;
            }
        }

        uint32_t delta_to_target = pix_sum - target_pix_num;
        float32_t delta_bin = (float32_t)hist[k];

        float32_t frac = (float32_t)delta_to_target / delta_bin;

        float32_t found_pix_v = weight_table[k+1]*frac + weight_table[k]*(1.f - frac);

        ret = found_pix_v;
    }

    return ret;
}

#endif

/// Anti-Flick exposures
///50
//   {60, 1.0},
//   {60, 3.33},
//   {60, 10},
//   {30, 30},
//   {15, 60},

//60
//   {60, 1.0},
//   {60, 3.33},
//   {60, 8.33f},
//   {30, 24.99f},
//   {15, 58.33f},
static uint32_t antiflick(ae_context_impl_t* context, parameters_storage_t* storage, uint32_t new_exp, uint32_t cur_af_exposure)
{
    uint32_t ret = cur_af_exposure;
    bool input_is_ok = true;
    float32_t sixty_hertz = get_param_check(storage, ALG_SIXTY_HERTZ, &input_is_ok);
    float32_t ms_convertion = get_param_check(storage, EXP_MS_CONVERTION, &input_is_ok);
    input_is_ok &= (ms_convertion > 0.0f);

    uint32_t table_ui32[6] = {0};
    uint32_t table_sz = 0;

    uint32_t id_af = (sixty_hertz > 0.0f) ? ANTI_FLICKER_60_EXP_MS_0 : ANTI_FLICKER_50_EXP_MS_0;

    uint32_t i;
    {
        bool read = true;
        if (input_is_ok)
        {
            for (i = 0; i < sizeof(table_ui32)/sizeof(table_ui32[0]); i++)
            {
                float32_t val = get_param_check(storage, id_af + i, &read);

                if (read && val > 0.0f)
                {
                    table_ui32[i] = (uint32_t) (val / ms_convertion);
                    table_sz++;
                }
                else
                {
                    break;
                }
            }
        }
    }

    ///print cur_af_exposure, new_exp, table_ui32[0], table_ui32[1], table_ui32[2], table_ui32[3], table_sz
    isp_tracelog_v("antiflick: cur_af_exposure=%d, new_exp=%d, table_ui32[0]=%d, table_ui32[1]=%d, table_ui32[2]=%d, table_ui32[3]=%d, table_sz=%d %.3f\n",
        cur_af_exposure, new_exp, table_ui32[0], table_ui32[1], table_ui32[2], table_ui32[3], table_sz, ms_convertion);

    if (table_sz == 0)
    {
        const ae_auto_params_table_t* table_50hz = find_table_by_id(context->adjust_tables, TABLES_AF_50hz);
        const ae_auto_params_table_t* table_60hz = find_table_by_id(context->adjust_tables, TABLES_AF_60hz);
        const ae_auto_params_table_t* table = (sixty_hertz > 0.0f) ? table_60hz : table_50hz;

        if (table == NULL || table->table_size == 0)
        {
            input_is_ok = false;
        }
        else
        {
            for (i = 0; i < table->table_size; i++)
            {
                table_ui32[i] = (uint32_t)get_table_value(table, (float32_t)i);
                table_sz++;
            }
        }
    }

    if (input_is_ok == true)
    {
        uint32_t i;

        for (i = 0; i < table_sz; i++)
        {
            int i_val = table_ui32[i];
            if (i_val < cur_af_exposure && new_exp < i_val)
            {
                return (i == 0) ? new_exp : i_val;
            }

            if (i_val > cur_af_exposure && new_exp > i_val)
            {
                ret = i_val;
            }
        }
    }

    return ret;
}

float32_t AE_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t cam_num
    )
{
    float32_t ret = -1.0f;

    night_mode_handling(context, stats, storage, cam_num);
    if (cmp_f32(get_param(storage, ISP_INTERNAL_AE_DISABLE), 1.f) == false)
    {
        ae_input_sensor_settings_t sensor_in;
        ae_input_sensor_settings_t sensor_base;
        min_max_internal_t nigh_mode_out;
        bool input_is_ok = true;

        sensor_in.exposure = get_param_check(storage, ISP_INTERNAL_EMB_LINE_EXPOSURE, &input_is_ok);
        sensor_in.gain = get_param_check(storage, ISP_INTERNAL_EMB_LINE_DLO_GAIN, &input_is_ok);

        float32_t max_exposure = get_param_check(storage, ISP_INTERNAL_AE_NM_EXP_MAX, &input_is_ok);
        nigh_mode_out.exp_min = get_param_check(storage, ISP_INTERNAL_AE_NM_EXP_MIN, &input_is_ok);
        nigh_mode_out.exp_max = get_param_check(storage, ISP_INTERNAL_AE_NM_EXP_MAX, &input_is_ok);
        nigh_mode_out.gain_min = get_param_check(storage, ISP_INTERNAL_AE_NM_GAIN_MIN, &input_is_ok);
        nigh_mode_out.gain_max = get_param_check(storage, ISP_INTERNAL_AE_NM_GAIN_MAX, &input_is_ok);
        float32_t mode = get_param_check(storage, AE_IN_MODE, &input_is_ok);
        float32_t def_gain = get_param_check(storage, AE_IN_DEF_GAIN, &input_is_ok);
        float32_t ae_target_dark = get_param_check(storage, AE_IN_TARGET_INDOOR, &input_is_ok);
        float32_t ae_target_light = get_param_check(storage, AE_IN_TARGET_LIGHT, &input_is_ok);
        float32_t ae_target_br_light = get_param_check(storage, AE_IN_TARGET_BR_LIGHT, &input_is_ok);
        float32_t ae_target_br_night = get_param_check(storage, AE_IN_TARGET_BR_NIGHT, &input_is_ok);
        float32_t ae_speed = get_param_check(storage, AE_IN_SPEED, &input_is_ok);
        float32_t black_level = get_param_check(storage, SENSOR_BLACK_LEVEL_DEFAULT, &input_is_ok); /* PRQA S 2983 */
        float32_t long_exposure_threshold = get_param_check(storage, SENSOR_LONG_EXPOSURE_THRESHOLD, &input_is_ok); /* PRQA S 2983 */
        float32_t stat_compenstation = get_param_check(storage, ISP_INTERNAL_APPLIED_COMP_TO_STATS, &input_is_ok); /* PRQA S 2983 */
        float32_t ae_prev_status = get_param_check(storage, AE_FINISH_OUT, &input_is_ok); /* PRQA S 2983 */
        bool ae_antiflick_enabled =  get_param_check(storage, ANTI_FLICKER_EXPOSURE_ENABLED, &input_is_ok) > 0.5f; /* PRQA S 2983 */
        float32_t sixty_hertz = get_param_check(storage, ALG_SIXTY_HERTZ, &input_is_ok);
        float32_t ms_convertion = get_param_check(storage, EXP_MS_CONVERTION, &input_is_ok);
        input_is_ok &= (ms_convertion > 0.0f);

        uint32_t id_af = (sixty_hertz > 0.0f) ? ANTI_FLICKER_60_EXP_MS_0 : ANTI_FLICKER_50_EXP_MS_0;
        float32_t min_exposure_antiflick = get_param_check(storage, id_af, &input_is_ok);

        float32_t ae_target = ae_target_light;



        if ((input_is_ok) && (stats != NULL) && (context != NULL))
        {
            min_exposure_antiflick/= ms_convertion;
            sensor_base.gain = def_gain;
            sensor_base.exposure = min_exposure_antiflick;
            float32_t ave_br = get_param(storage, AVE_BR);
            float32_t white_q = get_param(storage, WHITE_Q);

            bool overbright = white_q > 0.6;
            bool overdark = ave_br < 0.05;
            bool day_light = true;


            float32_t max_ev = (nigh_mode_out.gain_max/def_gain)*(max_exposure/min_exposure_antiflick);

            ae_internal_data_t* hist_data = get_internal_data(context);
            float32_t target_pix_value = estimate_pix_value_from_any_white_q(stats->full_sensor_hist, stats->full_sensor_hist_pix_count,
                stats->hist_bins_num, stats->full_sensor_hist_weight, ae_target);
            float32_t ratio_white = ((long_exposure_threshold - black_level) / stat_compenstation) / (ISP_MAX(target_pix_value - black_level, 1.f));
            float32_t current_ev =  (sensor_in.exposure/min_exposure_antiflick)*(sensor_in.gain / def_gain);
            float32_t target_ev =  ISP_MIN(ratio_white, max_ev);
            float32_t relation =  ISP_MAX(current_ev / ratio_white, ratio_white / current_ev);

            if ((int32_t)mode != 0)
            {
                float32_t lightness_criteria = 1.f - ((clampf32(target_ev, 1.f, 5.f) - 1.f) / 4.f);
                ae_target = ae_target_light*lightness_criteria + (1.f-lightness_criteria)*ae_target_dark;

                target_pix_value = estimate_pix_value_from_any_white_q(stats->full_sensor_hist, stats->full_sensor_hist_pix_count,
                    stats->hist_bins_num, stats->full_sensor_hist_weight, ae_target);
                ratio_white = ((long_exposure_threshold - black_level) / stat_compenstation) / (ISP_MAX(target_pix_value - black_level, 1.f));
                current_ev =  (sensor_in.exposure/min_exposure_antiflick)*(sensor_in.gain / def_gain);
                target_ev =  ISP_MIN(ratio_white, max_ev);
                relation =  ISP_MAX(current_ev / ratio_white, ratio_white / current_ev);
            }

            AE_STATUS status = AE_FINISHED;

            if (ae_antiflick_enabled)
            {
                ae_input_sensor_settings_t out_sensor;
                out_sensor = mul_exposure_gain(&sensor_base, nigh_mode_out.exp_min, nigh_mode_out.exp_max,
                    def_gain, target_ev, nigh_mode_out.gain_min, nigh_mode_out.gain_max);

                out_sensor.exposure = antiflick(context, storage, out_sensor.exposure, sensor_in.exposure);

                if (sensor_in.exposure != out_sensor.exposure || sensor_in.gain != out_sensor.gain)
                {
                    isp_tracelog_v("AE: antiflicker: %f %f\n", out_sensor.exposure, out_sensor.gain);
                    set_param_if_empty(storage, ISP_INTERNAL_GAIN, out_sensor.gain);
                    set_param_if_empty(storage, ISP_INTERNAL_AE_EXPOSURE, out_sensor.exposure);
                }
            }
            else
            {
                bool bFinish = relation < 0.05;
                bool bRecalibrate = relation > 0.2;
                status = ae_prev_status;


                if (bFinish)
                {
                    status = AE_FINISHED;
                }

                if (bRecalibrate)
                {
                    status = AE_IN_PROCESS;
                }

                float32_t target_ev_smooth = target_ev*(ae_speed) + (1.f-ae_speed)*current_ev;

                ae_input_sensor_settings_t out_sensor;

                out_sensor = mul_exposure_gain(&sensor_base, nigh_mode_out.exp_min, nigh_mode_out.exp_max,
                    def_gain, target_ev_smooth, nigh_mode_out.gain_min, nigh_mode_out.gain_max);
                out_sensor.gain = clampf32(out_sensor.gain, nigh_mode_out.gain_min, nigh_mode_out.gain_max);

                if (status == AE_IN_PROCESS)
                {
                    set_param_if_empty(storage, ISP_INTERNAL_GAIN, out_sensor.gain);
                    set_param_if_empty(storage, ISP_INTERNAL_AE_EXPOSURE, out_sensor.exposure);
                }
            }

            set_param_if_empty(storage, ISP_INTERNAL_AE_FINISH, (float32_t)status);
            ret = (float32_t)status;
        }
        else
        {
            isp_tracelog_e("AE unexpected problem\n");
        }
    }

    return ret;
}

/* PRQA S 1055 -- */
/* PRQA S 1056 -- */
/* PRQA S 1401 -- */
/* PRQA S 3450 -- */
/* PRQA S 0781 -- */
/* PRQA S 0602 -- */
/* PRQA S 3138 -- */
/* PRQA S 0491 -- */
/* PRQA S 1461 -- */
/* PRQA S 1031 -- */
/* PRQA S 0604 -- */
