/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           magna_controls.c
 *  @brief
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

/* PRQA S 0604 ++ */
/* PRQA S 0781 ++ */
/* PRQA S 1401 ++ */
/* PRQA S 1461 ++ */
/* PRQA S 3450 ++ */
/* PRQA S 3206 ++ */
/* PRQA S 1056 ++ */
/* PRQA S 1330 ++ */
/* PRQA S 3408 ++ */
/* PRQA S 0491 ++ */
/* PRQA S 1031 ++ */
/* PRQA S 1055 ++ */

#include "isp_algo.h"


void TPG_defaults(parameters_storage_t* s)
{
    set_param(s, TPG_IN_FREQ, 1.f);
    set_param(s, TPG_IN_ENABLED, 1.f);
    set_param(s, TPG_IN_PHASE, 0.f);
    set_param(s, TPG_IN_VAL, 0.f);
    /*
     System set TPG_OUT_VAL to invalid value 2 to trigger
     initialization on the first frame of tables based on TPG_IN_VAL.
    */
    set_param(s, TPG_OUT_VAL, 2.f);
}

void SINTER_defaults(parameters_storage_t* s)
{
    set_param(s, SINTER_IN_FREQ, 1.f);
    set_param(s, SINTER_IN_ENABLED, 1.f);
    set_param(s, SINTER_IN_PHASE, 6.f);
    set_param(s, NR_POWER_COEFF, 2.f);
    set_param(s, NR_RSHARP_COEFF, 0.4f);
}

void MODES_defaults(parameters_storage_t* s)
{
    set_param(s, MODES_IN_FREQ, 1.f);
    set_param(s, MODES_IN_ENABLED, 1.f);
    set_param(s, MODES_IN_PHASE, 0.f);
    set_param(s, MODES_MV_IN_VAL, 0.f);
    set_param(s, MODES_MV_OUT_VAL, 0.f);
    set_param(s, MODES_TEST_IN_VAL, 0.f);
    set_param(s, MODES_TEST_OUT_VAL, 0.f);
}

void TEMPERATURE_defaults(parameters_storage_t* s)
{
    set_param(s, TEMPERATURE_IN_FREQ, 1.f);
    set_param(s, TEMPERATURE_IN_ENABLED, 0.f);
    set_param(s, TEMPERATURE_IN_PHASE, 0.f);
    set_param(s, TEMPERATURE_IN_TSTEP, 1.f);

    set_param(s, TEMPERATURE_OUT_VAL, 0);
}

void CONTROLS_defaults(parameters_storage_t* s)
{
    set_param(s, CONTROLS_IN_FREQ, 1.f);
    set_param(s, CONTROLS_IN_ENABLED, 1.f);
    set_param(s, CONTROLS_IN_PHASE, 0.f);
    set_param(s, CONTROLS_IN_B_STEP, 410.f);
    set_param(s, CONTROLS_IN_C_STEP, 202.f);
    set_param(s, CONTROLS_IN_B_VAL, 0.f);
    set_param(s, CONTROLS_IN_C_VAL, 0.f);
    set_param(s, CONTROLS_OUT_B_VAL, 0.f);
    set_param(s, CONTROLS_OUT_C_VAL, 0.f);
}

void AGAIN_CONTROL_defaults(parameters_storage_t* s)
{
    set_param(s, AGAIN_CONTROL_IN_FREQ, 1.f);
    set_param(s, AGAIN_CONTROL_IN_ENABLED, 1.f);
    set_param(s, AGAIN_CONTROL_IN_PHASE, 2.f);
    set_param(s, AGAIN_OUT_DIR, 1.f);
    set_param(s, AE_ANALOG_GAIN, 5.f);
    set_param(s, SENSOR_PRE_HDR_GAIN, 1.f);
    set_param(s, TABLES_ANALOG_GAIN_FROM_NM, 5.f);
    set_param(s, TABLES_ANALOG_GAIN_FROM_BR_PHASE_PREV, 1.f);
    set_param(s, ANALOG_GAIN_COMPENSATION, 1.f);

}

void PREHDRGAIN_CONTROL_defaults(parameters_storage_t* s)
{
    set_param(s, PREHDRGAIN_CONTROL_IN_FREQ, 1.f);
    set_param(s, PREHDRGAIN_CONTROL_IN_ENABLED, 0.f);
    set_param(s, PREHDRGAIN_CONTROL_IN_PHASE, 2.f);
    set_param(s, PREHDRGAIN_FORCE, 0.f);
    set_param(s, AE_ANALOG_GAIN, 5.f);

    set_param(s, SENSOR_PRE_HDR_GAIN, 1.f);
    set_param(s, TABLES_ANALOG_GAIN_FROM_NM, 5.f);
    set_param(s, TABLES_ANALOG_GAIN_FROM_BR_PHASE_PREV, 1.f);
    set_param(s, ANALOG_GAIN_COMPENSATION, 1.f);
}


void ISPGAIN_CONTROL_defaults(parameters_storage_t* s)
{
    set_param(s, ISPGAIN_CONTROL_IN_FREQ, 1.f);
    set_param(s, ISPGAIN_CONTROL_IN_ENABLED, 1.f);
    set_param(s, ISPGAIN_CONTROL_IN_PHASE, 5.f);
    set_param(s, ISPGAIN_CONTROL_IN_MAX_GAIN, 31.f);
    set_param(s, ISPGAIN_CONTROL_GAMMA_VALUE, 1.f);
    set_param(s, ISPGAIN_CONTROL_GAMMA_ENABLE, 0.f);
    set_param(s, ISPGAIN_CONTROL_WEINER_ENABLE, 0.f);
    set_param(s, GAIN_IN_GAMMA, 1.f);
}

void LTM_CONTROL_defaults(parameters_storage_t* s)
{
    set_param(s, LTM_CONTROL_IN_FREQ, 1.f);
    set_param(s, LTM_CONTROL_IN_ENABLED, 1.f);
    set_param(s, LTM_CONTROL_IN_PHASE, 5.f);
    set_param(s, LTM_CONTROL_UPDATE_ENABLE, 0.f);
    set_param(s, LTM_CONTROL_CURVE_SLOPE, 35.f);
    set_param(s, LTM_CONTROL_DEFAULT_CURVE_SLOPE, 35.f);
    set_param(s, LTM_CONTROL_LOW_CURVE_SLOPE, 35.f);
    set_param(s, LTM_CONTROL_HIGH_CURVE_SLOPE, 150.f);
    set_param(s, LTM_CONTROL_LOW_THRESH, 0.0005f);
    set_param(s, LTM_CONTROL_HIGH_THRESH, 0.02f);
    set_param(s, LTM_CONTROL_ART_BLACK_LEVEL, 0.0f);
    set_param(s, LTM_CONTROL_BL_SCALE, 1.0f);
    set_param(s, LTM_CONTROL_DEFAULT_MAX_SLOPE, 235);
    set_param(s, LTM_CONTROL_ENABLE_MAX_SLOPE, 0);
    set_param(s, LTM_CONTROL_PREV_MAX_SLOPE, 235);
    set_param(s, BLACK_LEVEL_RESIDUE, 0.f);
}

void EV_CALC_defaults(parameters_storage_t* s)
{
    set_param(s, EV_CALC_IN_FREQ, 1.f);
    set_param(s, EV_CALC_IN_ENABLED, 1.f);
    set_param(s, EV_CALC_IN_PHASE, 6.f);
    set_param(s, SENSOR_EV, 1.f);
}

void SATURATION_defaults(parameters_storage_t* s)
{
    set_param(s, SATURATION_IN_FREQ, 1.f);
    set_param(s, SATURATION_IN_ENABLED, 1.f);
    set_param(s, SATURATION_IN_PHASE, 7.f);

    set_param(s, SATURATION_OUT_VAL, 100.0f);
    set_param(s, SAT_SHARP_OFFSET, 15.0f);
    set_param(s, SAT_SHARP_SLOPE, 1042.0f);
    set_param(s, SAT_TARGET_SNR, 20.0f);
    set_param(s, SAT_ALGO, 0.0f);
}

void CCM_INTERP_defaults(parameters_storage_t* s)
{
    set_param(s, CCM_INTERP_IN_FREQ, 1.f);
    set_param(s, CCM_INTERP_IN_ENABLED, 0.f);
    set_param(s, CCM_INTERP_IN_PHASE, 3.f);

    set_param(s, CCM_INTERP_NEGATIVE_TINT_STR, 1.f);
}

void SHARPNESS_defaults(parameters_storage_t* s)
{
    set_param(s, SHARPNESS_IN_FREQ, 1.f);
    set_param(s, SHARPNESS_IN_ENABLED, 1.f);
    set_param(s, SHARPNESS_IN_PHASE, 7.f);
    set_param(s, demCfg__RGGB__Sharp_Str_ud_DEFAULT, 176);
    set_param(s, demCfg__RGGB__Sharp_Str_Lu_DEFAULT, 96);
    set_param(s, demCfg__RGGB__Sharp_Str_Ldu_DEFAULT, 64);
    set_param(s, demCfg__RGGB__Sharp_Str_Ld_DEFAULT, 48);
}

void DBLC_CONTROL_defaults(parameters_storage_t* s)
{
    set_param(s, DBLC_CONTROL_IN_FREQ, 1.f);
    set_param(s, DBLC_CONTROL_IN_ENABLED, 1.f);
    set_param(s, DBLC_CONTROL_IN_PHASE, 7.f);

    set_param(s, DBLC_CONFIG_ON, 829);
    set_param(s, DBLC_CONFIG_OFF, 61);
    set_param(s, DBLC_PERIOD, 900);
    set_param(s, DBLC_FRAMES_THRESHOLD, 90);
    set_param(s, N_FRAMES_WO_CHANGES_EXP_AGAIN, 0.f);
}

void AGAIN_COMPENSATE_defaults(parameters_storage_t* s)
{
    set_param(s, AGAIN_COMPENSATE_IN_FREQ, 1.f);
    set_param(s, AGAIN_COMPENSATE_IN_ENABLED, 1.f);
    set_param(s, AGAIN_COMPENSATE_IN_PHASE, 3.f);
    set_param(s, AG_ENABLE, 1.f);
    set_param(s, T1_ENABLE, 1.f);
    set_param(s, SENSOR_VIRTUAL_GAIN_T1, 1.f);
}

void PINK_SUN_COMPENSATE_defaults(parameters_storage_t* s)
{
    set_param(s, PINK_SUN_COMPENSATE_IN_FREQ, 1.f);
    set_param(s, PINK_SUN_COMPENSATE_IN_ENABLED, 1.f);
    set_param(s, PINK_SUN_COMPENSATE_IN_PHASE, 3.f);
    set_param(s, PINK_SUN_COMP_OUT_VAL, 0);
}


void EMB_LINE_TRACE_defaults(parameters_storage_t* s)
{
    set_param(s, EMB_LINE_TRACE_IN_FREQ, 1.f);
    set_param(s, EMB_LINE_TRACE_IN_ENABLED, 1.f);
    set_param(s, EMB_LINE_TRACE_IN_PHASE, 3.f);

    set_param(s, EMB_LINE_EXPOSURE_OUT_VAL, 0);
    set_param(s, EMB_LINE_DLO_GAIN_OUT_VAL, 0);
    set_param(s, EMB_LINE_GREEN_GAIN_OUT_VAL, 0);
    set_param(s, EMB_LINE_RED_GAIN_OUT_VAL, 0);
    set_param(s, EMB_LINE_BLUE_GAIN_OUT_VAL, 0);
    set_param(s, EMB_LINE_CURRENT_TEMPERATERE_OUT_VAL, 0);
    set_param(s, EMB_LINE_TEMPSENS0_CALIB1_OUT_VAL, 0);
    set_param(s, EMB_LINE_TEMPSENS0_CALIB2_OUT_VAL, 0);
    set_param(s, EMB_LINE_DBLC_CONFIG_OUT_VAL, 0);
    set_param(s, EMB_LINE_RT1T2_OUT_VAL, 0);
    set_param(s, EMB_LINE_RT2T3_OUT_VAL, 0);
    set_param(s, EMB_LINE_RT1T4_OUT_VAL, 0);
    set_param(s, ISP_VERSION, 0);
}

void AUTO_DUMP_defaults(parameters_storage_t* s)
{
    set_param(s, AUTO_DUMP_IN_FREQ, 1.f);
    set_param(s, AUTO_DUMP_IN_ENABLED, 0.f);
    set_param(s, AUTO_DUMP_IN_PHASE, 0.f);
    set_param(s, ALG_FRAME_COUNTER, 0.f);
    set_param(s, ALG_FRAME_DUMP_INIT_DELAY, 0.0f);
    set_param(s, ALG_FRAME_DUMP_AMOUNT, 0.0f);
    set_param(s, ALG_FRAME_DUMP_FREQUENCY, 0.0f);
}


void HISTORY_ADAPTIVE_defaults(parameters_storage_t* s)
{
    set_param(s, HISTORY_ADAPTIVE_IN_FREQ, 1.f);
    set_param(s, HISTORY_ADAPTIVE_IN_ENABLED, 1.f);
    set_param(s, HISTORY_ADAPTIVE_IN_PHASE, 4.f);
    set_param(s, SENSOR_IN_DELAY_NM, 1.f);
    set_param(s, SENSOR_IN_DELAY_DM, 2.f);
    set_param(s, HISTORY_SENSOR_VIRTUAL_GAIN_T0, 1.f);
    set_param(s, HISTORY_SENSOR_VIRTUAL_GAIN_T1, 1.f);
    set_param(s, HISTORY_ADAPTIVE_SENSOR_DLO_GAIN, 512.f);
    set_param(s, HISTORY_ADAPTIVE_REAL_EXPOSURE, 512.f);
    set_param(s, HISTORY_ADAPTIVE_SENSOR_PRE_HDR_GAIN, 512.f);
    set_param(s, HISTORY_LTM_SENSOR_EXP, 512.f);
    set_param(s, HISTORY_ADAPTIVE_SENSOR_EXPOSURE, 512.f);
    set_param(s, HISTORY_LTM_SENSOR_GAIN, 512.f);
    set_param(s, HISTORY_LTM_SENSOR_ANALOG_GAIN, 5.f);
    set_param(s, HISTORY_ADAPTIVE_SENSOR_ANALOG_GAIN, 5.f);
    set_param(s, HISTORY_LTM_SENSOR_VIRTUAL_GAIN_T1, 1.f);
}

#ifdef MAGNA_PSA
void STATISTIC_UPDATE_defaults(parameters_storage_t* s)
{
    set_param(s, STATISTIC_UPDATE_IN_FREQ, 1.f);
    set_param(s, STATISTIC_UPDATE_IN_ENABLED, 1.f);
    set_param(s, STATISTIC_UPDATE_IN_PHASE, 4.f);
    set_param(s, ExpStats_Hist_Thresh_01_DEFAULT, 28.f);
    set_param(s, ExpStats_Hist_Thresh_12_DEFAULT, 73.f);
    set_param(s, ExpStats_Hist_Thresh_23_DEFAULT, 127.f);
    set_param(s, ExpStats_Hist_Thresh_34_DEFAULT, 188.f);
}
#endif

float32_t TPG_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;
    bool input_is_ok = true;
    int32_t new_val = (int32_t)get_param_check(storage, TPG_IN_VAL, &input_is_ok);
    int32_t prev = (int32_t)get_param_check(storage, TPG_OUT_VAL, &input_is_ok);

    if (new_val != 0)
    {
        set_param_if_empty(storage, ISP_INTERNAL_AE_DISABLE, 1.f);
        set_param_if_empty(storage, ISP_INTERNAL_AWB_DISABLE, 1.f);
    }
    if (input_is_ok && (new_val != prev))
    {
        isp_tracelog_e("TPG_run: %d\n", (int)new_val);
        set_param_if_empty(storage, ISP_INTERNAL_TPG_VAL, (float32_t)new_val);
    }
    else
    {
        ret = -1.0f;
    }

    return ret;
}

float32_t MODES_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;
    uint32_t i;
    bool input_is_ok = true;

    const AE_CONTROL_ITEM modes[2][3] =
    {
        {MODES_MV_IN_VAL, ISP_INTERNAL_MVMODE_VAL, MODES_MV_OUT_VAL},
        {MODES_TEST_IN_VAL, ISP_INTERNAL_TESTMODE_VAL, MODES_TEST_OUT_VAL},
    };

    const uint32_t modes_num = sizeof(modes) / (3 * sizeof(modes[0][0]));

    for (i = 0; i < modes_num; i++)
    {
        int32_t new_val = (int32_t)get_param_check(storage, modes[i][0], &input_is_ok);
        int32_t prev = (int32_t)get_param_check(storage, modes[i][2], &input_is_ok);
        if (input_is_ok && (new_val != prev))
        {
            set_param_if_empty(storage, modes[i][1], (float32_t)new_val);
        }
    }

    return ret;
}


float32_t TEMPERATURE_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;
    bool input_is_ok = true;
    float32_t prev = get_param_check(storage, TEMPERATURE_OUT_VAL, &input_is_ok);
    float32_t step = get_param_check(storage, TEMPERATURE_IN_TSTEP, &input_is_ok);
    float32_t tempsens0_calib1 = get_param_check(storage, ISP_INTERNAL_EMB_LINE_TEMPSENS0_CALIB1, &input_is_ok);
    float32_t tempsens0_calib2 = get_param_check(storage, ISP_INTERNAL_EMB_LINE_TEMPSENS0_CALIB2, &input_is_ok);
    float32_t tpm_current_temperature = get_param_check(storage, ISP_INTERNAL_EMB_LINE_CURRENT_TEMPERATERE, &input_is_ok);

    float32_t slope = (125.0f - 55.0f) /
                    (float32_t)(tempsens0_calib1 - tempsens0_calib2);
    float32_t T_0 = 55.0f - (slope * ((float32_t)tempsens0_calib2));
    float32_t new_val = (slope * (float32_t)tpm_current_temperature) - fabsf(T_0);

    bool step_check = (fabsf(new_val - prev) > step) ? true : false;

    if ((input_is_ok) && (step_check))
    {
        set_param_if_empty(storage, ISP_INTERNAL_TEMPERATURE, new_val);
    }
    else
    {
        ret = -1.0f;
    }

    return ret;
}


static int32_t get_smooth_value(int32_t input, int32_t required)
{
    int32_t delta = required - input;

    int32_t ret = input;
    int32_t step = 2;

    if (delta != 0)
    {
        if (delta < 0)
        {
            ret-=step;
            ret = ISP_MAX(required, ret);
        }
        else
        {
            ret+=step;
            ret = ISP_MIN(required, ret);
        }
    }

    return ret;
}


float32_t CONTROLS_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;
    bool input_is_ok = true;
    int32_t controls_in_b_step = (int32_t)get_param_check(storage, CONTROLS_IN_B_STEP, &input_is_ok);
    int32_t controls_in_c_step = (int32_t)get_param_check(storage, CONTROLS_IN_C_STEP, &input_is_ok);
    int32_t controls_in_b_val = (int32_t)get_param_check(storage, CONTROLS_IN_B_VAL, &input_is_ok);
    int32_t controls_in_c_val = (int32_t)get_param_check(storage, CONTROLS_IN_C_VAL, &input_is_ok);
    int32_t controls_out_b_val = (int32_t)get_param_check(storage, CONTROLS_OUT_B_VAL, &input_is_ok);
    int32_t controls_out_c_val = (int32_t)get_param_check(storage, CONTROLS_OUT_C_VAL, &input_is_ok);

    if (input_is_ok)
    {
        const int32_t max_level = 5;
        int32_t target_brightness = clamp(controls_in_b_val, -max_level, max_level);
        int32_t target_contrast = clamp(controls_in_c_val, -max_level, max_level);
        target_contrast = ((target_contrast * (controls_in_c_step / 16)) + (int32_t)((uint32_t)max_level >> 1U)) / max_level; /* PRQA S 2984 */
        target_brightness = ((target_brightness * (controls_in_b_step / 16)) + (int32_t)((uint32_t)max_level >> 1U)) / max_level; /* PRQA S 2984 */
        int32_t brightness = controls_out_b_val;
        int32_t contrast = controls_out_c_val;
        brightness = get_smooth_value(brightness, target_brightness);
        contrast = get_smooth_value(contrast, target_contrast);
        set_param_if_empty(storage, ISP_INTERNAL_CONTROLS_B_VAL, (float32_t)brightness);
        set_param_if_empty(storage, ISP_INTERNAL_CONTROLS_C_VAL, (float32_t)contrast);
    }
    else
    {
        ret = -1.f;
    }

    return ret;
}

float32_t SINTER_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;
    bool input_is_ok = true;
#ifdef MAGNA_PSA
    float32_t threshold_long = get_param_check(storage, sinterCfg__Thresh_Long, &input_is_ok);
#else
    float32_t threshold_long = 0;
#endif
    float32_t isp_gain = get_param_check(storage, dgCfg__Gain, &input_is_ok);
    float32_t dlo_gain = get_param_check(storage, HISTORY_ADAPTIVE_SENSOR_DLO_GAIN, &input_is_ok);
    float32_t total_gain = (isp_gain * dlo_gain) / (512.0f * 256.0f);
    float32_t ep_lpd_spd_ratio = get_param_check(storage, SENSOR_LPD_SPD_RATIO, &input_is_ok);
    float32_t temp_nonclamp = get_param_check(storage, AWB_OUT_TEMP_NONCLAMP, &input_is_ok);
    float32_t snr = get_param_check(storage, SNR, &input_is_ok);
    float32_t power_coeff = get_param_check(storage, NR_POWER_COEFF, &input_is_ok);
    float32_t rsharp_coeff = get_param_check(storage, NR_RSHARP_COEFF, &input_is_ok);
    const ae_auto_params_table_t* temp_table = find_table_by_id(context->adjust_tables, TABLES_ANR_TEMP_TABLE);

    if (input_is_ok)
    {
        float32_t new_val = log2f(total_gain)*10.0f;
        new_val = floorf(new_val + 0.5f);
        new_val = clampf32(new_val, 0, 100.f);

        float32_t gain = get_param_check(storage, ISP_INTERNAL_TOTAL_GAIN, &input_is_ok);
        float32_t max_dg = 256.0f;
        float32_t dg_clamped = clampf32(gain, 1.0f, max_dg);
        float32_t snr_ratio = ISP_MIN(snr / 5.0f, 1.5f);

        float32_t scaler_low_light = 1.0f + 0.5f * (dg_clamped - 1.0f) / (max_dg - 1.0f) - (1.5f - snr_ratio);
        isp_tracelog_v("low_light_scale, gain, snr_ratio: %f = 1.0 + 0.5 * (%f - 1) / (%f - 1) - (1.5 - %f)\n", scaler_low_light, dg_clamped, max_dg, snr_ratio); /* PRQA S 2743 */

        float32_t power = power_coeff * scaler_low_light;
        float32_t rsharp = rsharp_coeff * scaler_low_light;
        float32_t tn_scale_1 = clampf32(1.0f * power, 0.0f, 5.0f);
        float32_t tn_scale_2 = clampf32((power_coeff * rsharp_coeff) - power * rsharp, 0.0f, 5.0f);
        float32_t tn_scale_3 = clampf32((power_coeff * rsharp_coeff) - power * rsharp, 0.0f, 1.0f);
        set_param_if_empty(storage, ISP_INTERNAL_SINTER_SCALE_0, roundf(tn_scale_1 * 32.0f));
        set_param_if_empty(storage, ISP_INTERNAL_SINTER_SCALE_1, roundf(tn_scale_2 * 32.0f));
        set_param_if_empty(storage, ISP_INTERNAL_SINTER_SCALE_2, roundf(tn_scale_3 * 32.0f));

        if (fabsf(new_val - threshold_long) > FLT_EPSILON)
        {
            set_param_if_empty(storage, ISP_INTERNAL_SINTER_VAL, new_val);
        }

        /*Calculation of sinter noise profile ID*/
        uint32_t id = (uint32_t)TABLES_ANR_INTERP_EP_0_TEMP_1_PROFILE;
        if (ep_lpd_spd_ratio < 1.0f)
        {
            id = (uint32_t)TABLES_ANR_INTERP_EP_0_TEMP_1_PROFILE;
        }
        else
        {
            id = (uint32_t)TABLES_ANR_INTERP_EP_1_TEMP_1_PROFILE;
        }

        uint32_t index_right = lower_bound_f32(temp_table->out, temp_table->table_size, temp_nonclamp);
        index_right = clampu(index_right, 0, temp_table->table_size - 1);
        id += index_right;
        isp_tracelog_d("id, index_right, temp_nonclamp, ep_lpd_spd_ratio: %u %u %f %f\n", id, index_right, temp_nonclamp, ep_lpd_spd_ratio); /* PRQA S 2743 */
        id = clampu(id, TABLES_ANR_INTERP_EP_0_TEMP_1_PROFILE, TABLES_ANR_INTERP_EP_1_TEMP_5_PROFILE);
        set_param_if_empty(storage, ISP_INTERNAL_TABLE_ID, (float32_t)id);
    }
    else
    {
        ret = -1.f;
    }

    return ret;
}


float32_t EV_CALC_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;
    bool input_is_ok = true;
    float32_t exposure = get_param_check(storage, HISTORY_ADAPTIVE_REAL_EXPOSURE, &input_is_ok);
    float32_t gain = get_param_check(storage, HISTORY_ADAPTIVE_SENSOR_DLO_GAIN, &input_is_ok);
    float32_t dc_gain = get_param_check(storage, HISTORY_ADAPTIVE_SENSOR_DC_GAIN, &input_is_ok);
    float32_t again = get_param_check(storage, HISTORY_ADAPTIVE_SENSOR_ANALOG_GAIN, &input_is_ok);
    float32_t isp_gain = get_param_check(storage, dgCfg__Gain, &input_is_ok);
    float32_t pre_hdr_gain = get_param_check(storage, HISTORY_ADAPTIVE_SENSOR_PRE_HDR_GAIN, &input_is_ok);
#ifdef MAGNA_PSA
    float32_t prev_lmt_cc = get_buffer_parameter(storage, toneMapCfg__Collection_Correction, 1);
#else
    float32_t prev_lmt_cc = 256;
#endif

    exposure = (input_is_ok) ? exposure : 1.0f;
    gain = (input_is_ok) ? gain : 1.0f;
    dc_gain = (input_is_ok) ? dc_gain : 1.0f;
    again = (input_is_ok) ? again : 1.0f;
    isp_gain = (input_is_ok) ? isp_gain : 1.0f;
    pre_hdr_gain = (input_is_ok) ? pre_hdr_gain : 1.0f;
    float32_t prev_ev = get_param_check(storage, SENSOR_EV, &input_is_ok);

    if (input_is_ok)
    {
        float32_t again_val[9] = {0.67, 0.8, 1.0, 1.25, 1.5, 2.0, 2.33, 3.5, 4.0};
        dc_gain = (dc_gain > 0.0f) ? 2.84f : 1.0f;
        again = (again < 5) ? 5 : again;
        float32_t ev = ((gain) * dc_gain * again_val[(int32_t)again - 5] * (isp_gain) * exposure * pre_hdr_gain) / (512.0f * 256.0f * 128.0f);
        isp_tracelog_sv("camera: %d ev %f = ((%f) * %f * %f * %f * %f * %f) \n", camera_num, ev, (gain), dc_gain, again_val[(int32_t)again - 5], (isp_gain), exposure, pre_hdr_gain);
        set_param_if_empty(storage, ISP_INTERNAL_SENSOR_EV, ev);
        set_param_if_empty(storage, ISP_INTERNAL_CALC_LTM_CC_FROM_EV, (ev / prev_ev) * 256.0f);
        float32_t ltm_cc_diff = fabsf(prev_lmt_cc - ((ev / prev_ev) * 256.0f));

        if(ltm_cc_diff > 1.0f)
        {
            isp_tracelog_sv("camera: %d ltm_cc_diff %f\n", camera_num, ltm_cc_diff);
        }
    }
    else
    {
        ret = -1.f;
    }

    return ret;
}


float32_t AGAIN_CONTROL_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;
    bool input_is_ok = true;
    float32_t ag_from_nm = get_param_check(storage, TABLES_ANALOG_GAIN_FROM_NM, &input_is_ok);

    float32_t ag_from_br = get_param_check(storage, TABLES_ANALOG_GAIN_FROM_BR, &input_is_ok);
    float32_t phase = get_param_check(storage, TABLES_ANALOG_GAIN_FROM_BR_PHASE, &input_is_ok);
    float32_t phase_prev = get_param_check(storage, TABLES_ANALOG_GAIN_FROM_BR_PHASE_PREV, &input_is_ok);
    float32_t again_dir = get_param_check(storage, AGAIN_OUT_DIR, &input_is_ok);
    float32_t prev_analog_gain = get_param_check(storage, AE_ANALOG_GAIN, &input_is_ok);
    float32_t force = get_param_check(storage, PREHDRGAIN_FORCE, &input_is_ok);

    const ae_auto_params_table_t* table = find_table_by_id(context->adjust_tables, TABLES_ANALOG_GAIN_COMP);
    float32_t cur_again = 0.f;

    if (input_is_ok)
    {
        float32_t phase_delta = phase - phase_prev;
        // block to prevent oscilations
        // if it has opposite direction it needs to hit 2 levels and do it 3 times in row

        //if opposite direction and delta bigger than to items in table then check conditions
        if ((fabsf(phase_delta) > 1.5f) && ((phase_delta * again_dir) < 0.f))
        {
            /// if it is already 3rd attempt then reverse the direction
            if (fabsf(again_dir) > 2.5)
            {
                again_dir = -fsign(again_dir);
                set_param(storage, ISP_INTERNAL_AGAIN_OUT_DIR, again_dir);
            }
            else
            /// if numper of attempts less than 3 just increment attempts number
            {
                again_dir = again_dir + fsign(again_dir);
                set_param(storage, ISP_INTERNAL_AGAIN_OUT_DIR, again_dir);
            }
        }
        else
        {
            /// if no request to change direction then reset attempts number counter to 1
            if (fabsf(again_dir) > 1.5)
            {
                again_dir = fsign(again_dir);
                set_param(storage, ISP_INTERNAL_AGAIN_OUT_DIR, again_dir);
            }
        }

        if (cmp_f32(ag_from_nm, 7.f))
        {
            if ((phase_delta * again_dir) > 0.f)
            {
                cur_again = ag_from_br;
                set_param(storage, ISP_INTERNAL_SENSOR_ANALOG_GAIN, cur_again);
                set_param(storage,  ISP_INTERNAL_TABLES_ANALOG_GAIN_FROM_BR_PHASE_PREV, phase);
            }
            if (prev_analog_gain < ag_from_nm)
            {
                cur_again = ag_from_nm;
                set_param(storage, ISP_INTERNAL_SENSOR_ANALOG_GAIN, cur_again);
                set_param(storage, ISP_INTERNAL_AGAIN_OUT_DIR, 1.f);
                set_param(storage,  ISP_INTERNAL_TABLES_ANALOG_GAIN_FROM_BR_PHASE_PREV, 1.f);
            }
        }
        else
        {
            cur_again = ag_from_nm;
            set_param(storage, ISP_INTERNAL_SENSOR_ANALOG_GAIN, cur_again);
        }

        if (force)
        {
            cur_again = force;
            set_param(storage, ISP_INTERNAL_SENSOR_ANALOG_GAIN, cur_again);
        }

        if (cur_again >= (float32_t)ANALOG_GAIN_NIGHT)
        {
            float32_t compensate_gain = get_table_value(table, cur_again);
            set_param_if_empty(storage, ISP_INTERNAL_ANALOG_GAIN_COMPENSATION, compensate_gain);
        }
        else if (cur_again > 0.f)
        {
            set_param_if_empty(storage, ISP_INTERNAL_ANALOG_GAIN_COMPENSATION, 1.f);
        }
    }
    else
    {
        ret = -1.f;
    }



    return ret;
}


float32_t PREHDRGAIN_CONTROL_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;
    bool input_is_ok = true;
    float32_t ag_from_nm = get_param_check(storage, TABLES_ANALOG_GAIN_FROM_NM, &input_is_ok);

    float32_t ag_from_br = get_param_check(storage, TABLES_ANALOG_GAIN_FROM_BR, &input_is_ok);
    float32_t phase = get_param_check(storage, TABLES_ANALOG_GAIN_FROM_BR_PHASE, &input_is_ok);
    float32_t phase_prev = get_param_check(storage, TABLES_ANALOG_GAIN_FROM_BR_PHASE_PREV, &input_is_ok);
    float32_t again_dir = get_param_check(storage, AGAIN_OUT_DIR, &input_is_ok);
    float32_t prev_analog_gain = get_param_check(storage, AE_ANALOG_GAIN, &input_is_ok);
    float32_t force = get_param_check(storage, PREHDRGAIN_FORCE, &input_is_ok);

    const ae_auto_params_table_t* table = find_table_by_id(context->adjust_tables, TABLES_ANALOG_GAIN_COMP);
    float32_t analog_gain = 0.f;

    if (input_is_ok)
    {
        set_param(storage, ISP_INTERNAL_SENSOR_ANALOG_GAIN, ag_from_nm);

        float32_t phase_delta = phase - phase_prev;

        // block to prevent oscilations
        // if it has opposite direction it needs to hit 2 levels and do it 3 times in row

        //if opposite direction and delta bigger than to items in table then check conditions
        if ((fabsf(phase_delta) > 1.5f) && ((phase_delta * again_dir) < 0.f))
        {
            /// if it is already 3rd attempt then reverse the direction
            if (fabsf(again_dir) > 2.5)
            {
                again_dir = -fsign(again_dir);
                set_param(storage, ISP_INTERNAL_AGAIN_OUT_DIR, again_dir);
            }
            else
            /// if numper of attempts less than 3 just increment attempts number
            {
                again_dir = again_dir + fsign(again_dir);
                set_param(storage, ISP_INTERNAL_AGAIN_OUT_DIR, again_dir);
            }
        }
        else
        {
            /// if no request to change direction then reset attempts number counter to 1
            if (fabsf(again_dir) > 1.5)
            {
                again_dir = fsign(again_dir);
                set_param(storage, ISP_INTERNAL_AGAIN_OUT_DIR, again_dir);
            }
        }

        if (cmp_f32(ag_from_nm, 7.f))
        {
            if ((phase_delta * again_dir) > 0.f)
            {
                analog_gain = ag_from_br;
                set_param(storage,  ISP_INTERNAL_TABLES_ANALOG_GAIN_FROM_BR_PHASE_PREV, phase);
            }
            if (prev_analog_gain < ag_from_nm)
            {
                analog_gain = ag_from_nm;
                set_param(storage, ISP_INTERNAL_AGAIN_OUT_DIR, 1.f);
                set_param(storage,  ISP_INTERNAL_TABLES_ANALOG_GAIN_FROM_BR_PHASE_PREV, 1.f);
            }
        }
        else
        {
            analog_gain = ag_from_nm;
        }

        if (force)
        {
            analog_gain = force;
        }

        if (analog_gain >= (float32_t)ANALOG_GAIN_NIGHT)
        {
            float32_t compensate_gain = get_table_value(table, analog_gain);
            float32_t pre_hdr_gain = (compensate_gain > 0.f) ? 1.f / compensate_gain : 1.f;
            set_param_if_empty(storage, ISP_INTERNAL_SENSOR_PRE_HDR_GAIN, pre_hdr_gain);
            set_param_if_empty(storage, ISP_INTERNAL_ANALOG_GAIN_COMPENSATION, compensate_gain);
        }
        else if (analog_gain > 0.f)
        {
            set_param_if_empty(storage, ISP_INTERNAL_SENSOR_PRE_HDR_GAIN, 1.f);
            set_param_if_empty(storage, ISP_INTERNAL_ANALOG_GAIN_COMPENSATION, 1.f);
        }
    }
    else
    {
        ret = -1.f;
    }



    return ret;
}


float32_t PINK_SUN_COMPENSATE_run(
    ae_context_impl_t* context, /* PRQA S 3673 */
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;

    if (context != NULL)
    {
        bool input_is_ok = true;
        float32_t exposure = get_param_check(storage, AE_EXPOSURE, &input_is_ok);
        float32_t r_t1t2 = get_param_check(storage, ISP_INTERNAL_EMB_LINE_RT1T2, &input_is_ok);
        float32_t r_t2t3 = get_param_check(storage, ISP_INTERNAL_EMB_LINE_RT2T3, &input_is_ok);


        if (input_is_ok)
        {
            float32_t result = 1.0f / ISP_MIN(1.0f, ((((r_t1t2 * r_t2t3) / 1024.0f) * 0.0041f) + 0.0021f));

            if(exposure > 270.f)
            {
                result = 1.0f;
            }

            set_param(storage, ISP_INTERNAL_PINK_SUN_COMP, result);
        }
        else
        {
            ret = -1.f;
        }
    }

    return ret;
}


//static uint32_t pink_sun_dg[] = {512,576,640,704,768,832,896,960,1024,1088,1152,1216,1280,1344,1408,1472,1536,1600,1664,1728,1792,1856,1920,1984,2047};
//static uint32_t pink_sun_exp[] = {20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,400,420,440,460,480,500,520,540,560,580,600,620,640,660,680,700,720,740,760,780,800,820,840,860,880,900,920,940,960,980,1000,1020,1040,1060,1080,1100,1120,1140,1160,1180,1200,1220,1240,1260,1280,1300,1320,1340,1360,1380,1400,1420,1440,1460,1480,1500,1520,1540,1560,1580,1600,1620,1640,1660,1680,1700,1720,1740,1760,1780,1800,1820,1840,1860,1880,1900,1920,1940,1960,1980,2000,2020,2040,2047};
static uint32_t exp_50hz_lut[] = {50, 100, 200, 270, 310, 640, 970, 1300, 1630}; /* PRQA S 3218 */
static uint32_t again_lut[] = {5, 6, 7, 8, 9, 10, 11, 12, 13}; /* PRQA S 3218 */
static uint32_t dc_gain_lut[] = {0, 1}; /* PRQA S 3218 */
static uint32_t dg_lut[] = {490, 512, 1024, 2047}; /* PRQA S 3218 */

float32_t AUTO_DUMP_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    bool input_is_ok = true;
    uint32_t counter = (uint32_t)get_param_check(storage, ALG_FRAME_COUNTER, &input_is_ok);

    uint32_t table_1_size = sizeof(exp_50hz_lut) / sizeof(exp_50hz_lut[0]);
    uint32_t table_2_size = sizeof(again_lut) / sizeof(again_lut[0]);
    uint32_t table_3_size = sizeof(dc_gain_lut) / sizeof(dc_gain_lut[0]);
    uint32_t table_4_size = sizeof(dg_lut) / sizeof(dg_lut[0]);
    uint32_t table_1_index = get_table_index(table_1_size, &counter);
    uint32_t table_2_index = get_table_index(table_2_size, &counter);
    uint32_t table_3_index = get_table_index(table_3_size, &counter);
    uint32_t table_4_index = get_table_index(table_4_size, &counter);

    if (input_is_ok == true)
    {
        set_param(storage, ISP_INTERNAL_SENSOR_EXPOSURE, (float32_t)exp_50hz_lut[table_1_index]);
        set_param(storage, ISP_INTERNAL_SENSOR_ANALOG_GAIN, (float32_t)again_lut[table_2_index]);
        set_param(storage, ISP_INTERNAL_SENSOR_DC_GAIN, (float32_t)dc_gain_lut[table_3_index]);
        set_param(storage, ISP_INTERNAL_GAIN, (float32_t)dg_lut[table_4_index]);
    }

    return 1.f;
}

static void set_param_if_true(parameters_storage_t* storage, int32_t item, float32_t val, bool flag)
{
    if (flag == true)
    {
        set_param(storage, item, val);
    }
}

float32_t EMB_LINE_TRACE_run(
    ae_context_impl_t* context, /* PRQA S 3673 */
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
    {
    float32_t ret = 1.f;

    if (context != NULL)
    {
        bool status_exposure = true;
        bool status_dlo_gain = true;
        bool status_dc_gain = true;
        bool status_analog_gain = true;
        bool status_analog_gain_coarse = true;
        bool status_green_gain = true;
        bool status_red_gain = true;
        bool status_blue_gain = true;
        bool status_cur_temp = true;
        bool status_calib1_temp = true;
        bool status_calib2_temp = true;
        bool status_dblc = true;
        bool status_r_t1t2 = true;
        bool status_r_t2t3 = true;
        bool status_r_t1t4 = true;
        bool status_ae_exposure = true;
        bool status_isp_version = true;
        bool status_sensor_version = true;
        bool status_t0 = true;
        bool status_t1 = true;
        bool status_tpg_part1 = true;
        bool status_tpg_part2 = true;
        bool status_test_data_r = true;
        bool status_test_data_gr = true;
        bool status_test_data_b = true;
        bool status_test_data_gb = true;
        bool status_vt_pix_clk_div = true;
        bool status_pre_pll_clk_div = true;
        bool status_pll_multiplier = true;
        bool status_fll = true;
        bool status_llpck = true;
        bool status_dblc_btm_row = true;
        bool status_y_addr_start = true;
        bool status_y_addr_end = true;
        bool status_vertical_flip = true;
        bool status_se_mode = true;
        bool status_ab_period = true;
        bool status_t3t4_sh_adv = true;
        bool status_fit = true;
        bool status_fit4 = true;
        bool status_dcg_grim = true;
        float32_t exposure = get_param_check(storage, ISP_INTERNAL_EMB_LINE_EXPOSURE, &status_exposure);
        float32_t dlo_gain = get_param_check(storage, ISP_INTERNAL_EMB_LINE_DLO_GAIN, &status_dlo_gain);
        float32_t dc_gain = get_param_check(storage, ISP_INTERNAL_EMB_LINE_DC_GAIN, &status_dc_gain);
        float32_t analog_gain = get_param_check(storage, ISP_INTERNAL_EMB_LINE_ANALOG_GAIN, &status_analog_gain);
        float32_t analog_gain_coarse = get_param_check(storage, ISP_INTERNAL_EMB_LINE_ANALOG_GAIN_COARSE, &status_analog_gain_coarse);
        float32_t green_gain = get_param_check(storage, ISP_INTERNAL_EMB_LINE_GREEN_GAIN, &status_green_gain);
        float32_t red_gain = get_param_check(storage, ISP_INTERNAL_EMB_LINE_RED_GAIN, &status_red_gain);
        float32_t blue_gain = get_param_check(storage, ISP_INTERNAL_EMB_LINE_BLUE_GAIN, &status_blue_gain);
        float32_t cur_temp = get_param_check(storage, ISP_INTERNAL_EMB_LINE_CURRENT_TEMPERATERE, &status_cur_temp);
        float32_t calib1_temp = get_param_check(storage, ISP_INTERNAL_EMB_LINE_TEMPSENS0_CALIB1, &status_calib1_temp);
        float32_t calib2_temp = get_param_check(storage, ISP_INTERNAL_EMB_LINE_TEMPSENS0_CALIB2, &status_calib2_temp);
        float32_t dblc = get_param_check(storage, ISP_INTERNAL_EMB_LINE_DBLC_CONFIG, &status_dblc);
        float32_t r_t1t2 = get_param_check(storage, ISP_INTERNAL_EMB_LINE_RT1T2, &status_r_t1t2);
        float32_t r_t2t3 = get_param_check(storage, ISP_INTERNAL_EMB_LINE_RT2T3, &status_r_t2t3);
        float32_t r_t1t4 = get_param_check(storage, ISP_INTERNAL_EMB_LINE_RT1T4, &status_r_t1t4);
        float32_t ae_exposure = get_param_check(storage, ISP_INTERNAL_EMB_LINE_AE_EXPOSURE, &status_ae_exposure);
        float32_t isp_version = get_param_check(storage, ISP_INTERNAL_EMB_LINE_ISP_VERSION, &status_isp_version);
        float32_t sensor_version = get_param_check(storage, ISP_INTERNAL_EMB_LINE_SENSOR_VERSION, &status_sensor_version);
        float32_t t0 = get_param_check(storage, ISP_INTERNAL_EMB_LINE_SENSOR_VIRTUAL_GAIN_T0, &status_t0);
        float32_t t1 = get_param_check(storage, ISP_INTERNAL_EMB_LINE_SENSOR_VIRTUAL_GAIN_T1, &status_t1);
        float32_t tpg_part1 = get_param_check(storage, ISP_INTERNAL_EMB_LINE_TPG_PART1, &status_tpg_part1);
        float32_t tpg_part2 = get_param_check(storage, ISP_INTERNAL_EMB_LINE_TPG_PART2, &status_tpg_part2);
        float32_t test_data_r = get_param_check(storage, ISP_INTERNAL_EMB_LINE_TEST_DATA_R, &status_test_data_r);
        float32_t test_data_gr = get_param_check(storage, ISP_INTERNAL_EMB_LINE_TEST_DATA_GR, &status_test_data_gr);
        float32_t test_data_b = get_param_check(storage, ISP_INTERNAL_EMB_LINE_TEST_DATA_B, &status_test_data_b);
        float32_t test_data_gb = get_param_check(storage, ISP_INTERNAL_EMB_LINE_TEST_DATA_GB, &status_test_data_gb);
        float32_t vt_pix_clk_div = get_param_check(storage, ISP_INTERNAL_EMB_LINE_VT_PIX_CLK_DIV, &status_vt_pix_clk_div);
        float32_t pre_pll_clk_div = get_param_check(storage, ISP_INTERNAL_EMB_LINE_PRE_PLL_CLK_DIV, &status_pre_pll_clk_div);
        float32_t pll_multiplier = get_param_check(storage, ISP_INTERNAL_EMB_LINE_PLL_MULTIPLIER, &status_pll_multiplier);
        float32_t fll = get_param_check(storage, ISP_INTERNAL_EMB_LINE_FLL, &status_fll);
        float32_t llpck = get_param_check(storage, ISP_INTERNAL_EMB_LINE_LLPCK, &status_llpck);
        float32_t dblc_btm_row = get_param_check(storage, ISP_INTERNAL_EMB_LINE_DBLC_BTM_ROW, &status_dblc_btm_row);
        float32_t y_addr_start = get_param_check(storage, ISP_INTERNAL_EMB_LINE_Y_ADDR_START, &status_y_addr_start);
        float32_t y_addr_end = get_param_check(storage, ISP_INTERNAL_EMB_LINE_Y_ADDR_END, &status_y_addr_end);
        float32_t vertical_flip = get_param_check(storage, ISP_INTERNAL_EMB_LINE_VERTICAL_FLIP, &status_vertical_flip);
        float32_t se_mode = get_param_check(storage, ISP_INTERNAL_EMB_LINE_SE_MODE, &status_se_mode);
        float32_t ab_period = get_param_check(storage, ISP_INTERNAL_EMB_LINE_AB_PERIOD, &status_ab_period);
        float32_t t3t4_sh_adv = get_param_check(storage, ISP_INTERNAL_EMB_LINE_T3T4_SH_ADV, &status_t3t4_sh_adv);
        float32_t fit = get_param_check(storage, ISP_INTERNAL_EMB_LINE_FIT, &status_fit);
        float32_t fit4 = get_param_check(storage, ISP_INTERNAL_EMB_LINE_FIT4, &status_fit4);
        float32_t dcg_grim = get_param_check(storage, ISP_INTERNAL_EMB_LINE_DCG_TRIM, &status_dcg_grim);


        if (g_counters[camera_num] % 64 == 0 && g_isp_log_emb != NULL && g_isp_log_emb[0] > 0.5f)
        {
            if ((g_isp_log_cam == NULL) || ((uint32_t)(*g_isp_log_cam) == MAX_CAMERAS_NUM) || ((uint32_t)(*g_isp_log_cam) == camera_num))
            {
                isp_tracelog_i("sensor %d\n", (int32_t) camera_num);
                isp_tracelog_i("EMB_LINE: exposure = %d\n", (int32_t) exposure);
                isp_tracelog_i("EMB_LINE: dlo_gain = 0x%04X\n", (int32_t) dlo_gain);
                isp_tracelog_i("EMB_LINE: dc_gain = 0x%04X\n", (int32_t) dc_gain);
                isp_tracelog_i("EMB_LINE: analog_gain = %d\n", (int32_t) analog_gain);
                isp_tracelog_i("EMB_LINE: analog_gain_coarse = %d\n", (int32_t) analog_gain_coarse);
                isp_tracelog_i("EMB_LINE: green_gain = %d\n", (int32_t) green_gain);
                isp_tracelog_i("EMB_LINE: red_gain = %d\n", (int32_t) red_gain);
                isp_tracelog_i("EMB_LINE: blue_gain = %d\n", (int32_t) blue_gain);
                isp_tracelog_i("EMB_LINE: cur_temp = %d\n", (int32_t) cur_temp);
                isp_tracelog_i("EMB_LINE: dcg_grim = 0x%04X\n", (int32_t) dcg_grim);
                isp_tracelog_i("EMB_LINE: r_t1t2 = %d\n", (int32_t) r_t1t2);
                isp_tracelog_i("EMB_LINE: r_t2t3 = %d\n", (int32_t) r_t2t3);
                isp_tracelog_i("EMB_LINE: r_t1t4 = %d\n", (int32_t) r_t1t4);
                isp_tracelog_i("EMB_LINE: gain T0 = %.3f\n", (float32_t) t0 / 256.f);
                isp_tracelog_i("EMB_LINE: isp version = %d\n", (int32_t) isp_version);
                isp_tracelog_i("EMB_LINE: sensor revision = %d\n", (int32_t) sensor_version);
                isp_tracelog_i("EMB_LINE: fll = %d\n", (int32_t) fll);
            }
        }

        {
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_EXPOSURE, exposure, status_exposure);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_DLO_GAIN, dlo_gain, status_dlo_gain);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_DC_GAIN, dc_gain, status_dc_gain);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_ANALOG_GAIN, analog_gain, status_analog_gain);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_ANALOG_GAIN_COARSE, analog_gain_coarse, status_analog_gain_coarse);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_GREEN_GAIN, green_gain, status_green_gain);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_RED_GAIN, red_gain, status_red_gain);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_BLUE_GAIN, blue_gain, status_blue_gain);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_CURRENT_TEMPERATERE, cur_temp, status_cur_temp);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_TEMPSENS0_CALIB1, calib1_temp, status_calib1_temp);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_TEMPSENS0_CALIB2, calib2_temp, status_calib2_temp);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_DBLC_CONFIG, dblc, status_dblc);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_RT1T2, r_t1t2, status_r_t1t2);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_RT2T3, r_t2t3, status_r_t2t3);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_RT1T4, r_t1t4, status_r_t1t4);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_AE_EXPOSURE, ae_exposure, status_ae_exposure);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_ISP_VERSION, isp_version, status_isp_version);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_SENSOR_VERSION, sensor_version, status_sensor_version);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_SENSOR_VIRTUAL_GAIN_T0, t0, status_t0);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_SENSOR_VIRTUAL_GAIN_T1, t1, status_t1);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_TPG_PART1, tpg_part1, status_tpg_part1);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_TPG_PART2, tpg_part2, status_tpg_part2);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_TEST_DATA_R, test_data_r, status_test_data_r);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_TEST_DATA_GR, test_data_gr, status_test_data_gr);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_TEST_DATA_B, test_data_b, status_test_data_b);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_TEST_DATA_GB, test_data_gb, status_test_data_gb);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_DCG_TRIM, dcg_grim, status_dcg_grim);

            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_VT_PIX_CLK_DIV, vt_pix_clk_div, status_vt_pix_clk_div);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_PRE_PLL_CLK_DIV, pre_pll_clk_div, status_pre_pll_clk_div);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_PLL_MULTIPLIER, pll_multiplier, status_pll_multiplier);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_FLL, fll, status_fll);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_LLPCK, llpck, status_llpck);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_DBLC_BTM_ROW, dblc_btm_row, status_dblc_btm_row);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_Y_ADDR_START, y_addr_start, status_y_addr_start);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_Y_ADDR_END, y_addr_end, status_y_addr_end);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_VERTICAL_FLIP, vertical_flip, status_vertical_flip);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_SE_MODE, se_mode, status_se_mode);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_AB_PERIOD, ab_period, status_ab_period);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_T3T4_SH_ADV, t3t4_sh_adv, status_t3t4_sh_adv);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_FIT, fit, status_fit);
            set_param_if_true(storage, ISP_INTERNAL_TRACE_EMB_LINE_FIT4, fit4, status_fit4);
        }
    }

    return ret;
}

float32_t AGAIN_COMPENSATE_run(
    ae_context_impl_t* context, /* PRQA S 3673 */
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;

    if (context != NULL)
    {
        bool input_is_ok = true;
        float32_t ag_enabled = get_param_check(storage, AG_ENABLE, &input_is_ok);
        float32_t t1_enabled = get_param_check(storage, T1_ENABLE, &input_is_ok);
        float32_t exposure = get_param_check(storage, AE_EXPOSURE, &input_is_ok);
        float32_t ae_gain = get_param_check(storage, AE_OUT_GAIN, &input_is_ok);
        float32_t ave_br = get_param_check(storage, AVE_BR, &input_is_ok);
        float32_t target_ave_br = get_param_check(storage, TARGET_AVE_BR, &input_is_ok);
        float32_t prev_t1_gain = get_param_check(storage, SENSOR_VIRTUAL_GAIN_T1, &input_is_ok);
        float32_t gain_gamma = get_param_check(storage, GAIN_IN_GAMMA, &input_is_ok);

        float32_t gain_min = get_param_check(storage, ISP_INTERNAL_AE_NM_GAIN_MIN, &input_is_ok);
        float32_t gain_max = get_param_check(storage, ISP_INTERNAL_AE_NM_GAIN_MAX, &input_is_ok);
        float32_t max_isp_gain = get_param_check(storage, ISPGAIN_CONTROL_IN_MAX_GAIN, &input_is_ok);
        float32_t min_exposure_af = get_param_check(storage, ISP_INTERNAL_MIN_EXPOSURE_AF, &input_is_ok);
        float32_t exp_max = get_param_check(storage, ISP_INTERNAL_AE_NM_EXP_MAX, &input_is_ok);
        float32_t gain_def = get_param_check(storage, AE_IN_DEF_GAIN, &input_is_ok);
        float32_t min_again_comp = get_param_check(storage, ISP_INTERNAL_MIN_AGAIN_COMP, &input_is_ok);


        bool exposure_comp_ok = true;
        bool stat_compenstation_ok = true;
        float32_t exposure_comp = get_param_check(storage, ISP_INTERNAL_SENSOR_EXPOSURE_COMP, &exposure_comp_ok);

        if (exposure_comp_ok == false)
        {
            exposure_comp = 1.f;
        }



        bool pink_sun_comp_ok = true;
        float32_t pink_sun_comp = get_param_check(storage, ISP_INTERNAL_PINK_SUN_COMP, &pink_sun_comp_ok);

        if (pink_sun_comp_ok == false)
        {
            pink_sun_comp = 1.f;
        }

        set_param(storage, ISP_INTERNAL_SENSOR_EXPOSURE, floorf((exposure / exposure_comp) + 0.5f));
        set_param(storage, ISP_INTERNAL_DLO_GAIN,  clampf32(floorf((ae_gain * exposure_comp) + 0.5f), gain_min, gain_max));

        if ((input_is_ok))
        {
            float32_t min_possible_compensation = min_again_comp * (gain_def / gain_max) * (min_exposure_af / exp_max);
            max_isp_gain = max_isp_gain / clampf32(min_possible_compensation, 0.00001f, 1.f);
            float32_t ave_br_gain = target_ave_br / (ave_br + FLT_EPSILON);
            ave_br_gain = cmp_f32(ag_enabled, 0.f) ? 1.f : ave_br_gain;
            ave_br_gain = ISP_MIN(ave_br_gain, powf(max_isp_gain, 1.f / gain_gamma));

            float32_t new_gain = ISP_MAX(ave_br_gain, (pink_sun_comp));
            new_gain = ISP_MAX(new_gain, 1.f);

            if (t1_enabled > 0.5f)
            {
                float32_t smoothed = expf((0.1f*logf(new_gain)) + (0.9f*logf(prev_t1_gain)));
                set_param(storage, ISP_INTERNAL_SENSOR_VIRTUAL_GAIN_T1, smoothed);
            }
        }
        else
        {
            isp_tracelog_e("AGAIN failure\n");
            ret = -1.f;
        }
    }

    return ret;
}

#ifdef MAGNA_PSA

float32_t ISPGAIN_CONTROL_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;

    bool input_is_ok = true;
    bool sensor_t0_gain_is_ok = true;
    float32_t sensor_t1_gain = get_param_check(storage, HISTORY_SENSOR_VIRTUAL_GAIN_T1, &input_is_ok);
    float32_t sensor_t1_gain_future = get_param_check(storage, HISTORY_LTM_SENSOR_VIRTUAL_GAIN_T1, &input_is_ok);
    float32_t sensor_exp_future = get_param_check(storage, HISTORY_LTM_SENSOR_EXP, &input_is_ok);
    float32_t sensor_gain_future = get_param_check(storage, HISTORY_LTM_SENSOR_GAIN, &input_is_ok);
    float32_t analog_gain_future = get_param_check(storage, HISTORY_LTM_SENSOR_ANALOG_GAIN, &input_is_ok);
    float32_t sensor_exp = get_param_check(storage, HISTORY_ADAPTIVE_SENSOR_EXPOSURE, &input_is_ok);
    float32_t sensor_gain = get_param_check(storage, HISTORY_ADAPTIVE_SENSOR_DLO_GAIN, &input_is_ok);
    float32_t analog_gain = get_param_check(storage, HISTORY_ADAPTIVE_SENSOR_ANALOG_GAIN, &input_is_ok);
    float32_t max_isp_gain = get_param_check(storage, ISPGAIN_CONTROL_IN_MAX_GAIN, &input_is_ok);

    float32_t q1 = sensor_t1_gain_future/sensor_t1_gain;
    float32_t q2 = sensor_gain_future/sensor_gain;
    float32_t q3 = sensor_exp_future/sensor_exp;

    if (cmp_f32(analog_gain_future, analog_gain) == false)
    {
        if ((cmp_f32(analog_gain_future, 7.0f)) || (cmp_f32(analog_gain_future, 5.0f))) /* PRQA S 3415 */
        {
            q2 = 1.f;
        }
    }


    float32_t current_out = get_param_check(storage, dgCfg__Gain, &input_is_ok);
    float32_t sensor_t0_gain = get_param_check(storage, HISTORY_SENSOR_VIRTUAL_GAIN_T0, &sensor_t0_gain_is_ok);
    sensor_t0_gain = sensor_t0_gain_is_ok ? sensor_t0_gain : 1.f;

    if (input_is_ok)
    {
        set_param_if_empty(storage, ISP_INTERNAL_Collection_Correction, 256.f*q1*q2*q3);

        float32_t new_val = sensor_t1_gain*sensor_t0_gain;
        new_val = clampf32(new_val, 0.f, max_isp_gain);
        if (cmp_f32(current_out, new_val) == false)
        {
            set_param_if_empty(storage, ISP_INTERNAL_dgCfg__Gain, new_val*256.f);
        }
    }
    else
    {
        ret = -1.f;
    }

    return ret;
}
#else
float32_t ISPGAIN_CONTROL_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;

    bool input_is_ok = true;
    bool sensor_t0_gain_is_ok = true;
    float32_t sensor_t0_gain = get_param_check(storage, ISP_INTERNAL_T0_PREPIPE, &sensor_t0_gain_is_ok);
    float32_t sensor_t1_gain = get_param_check(storage, ISP_INTERNAL_SENSOR_VIRTUAL_GAIN_T1, &input_is_ok);
    float32_t max_isp_gain = get_param_check(storage, ISPGAIN_CONTROL_IN_MAX_GAIN, &input_is_ok);
    float32_t gain_gamma = get_param_check(storage, GAIN_IN_GAMMA, &input_is_ok);
    float32_t ave_br = get_param_check(storage, AVE_BR, &input_is_ok);
    float32_t target_ave_br = get_param_check(storage, TARGET_AVE_BR, &input_is_ok);
    float32_t prev_gamma = get_param_check(storage, ISPGAIN_CONTROL_GAMMA_VALUE, &input_is_ok);
    uint32_t gamma_enable = (uint32_t)get_param_check(storage, ISPGAIN_CONTROL_GAMMA_ENABLE, &input_is_ok);
    uint32_t weiner_enable = (uint32_t)get_param_check(storage, ISPGAIN_CONTROL_WEINER_ENABLE, &input_is_ok);
    float32_t snr = get_param_check(storage, SNR, &input_is_ok);


    if (!sensor_t0_gain_is_ok)
    {
        sensor_t0_gain = 1.f;
    }

    float32_t exp_emb = get_param_check(storage, ISP_INTERNAL_EMB_LINE_EXPOSURE, &sensor_t0_gain_is_ok);


    float32_t current_out = get_param_check(storage, dgCfg__Gain, &input_is_ok);

    if (input_is_ok)
    {
        float32_t new_val = sensor_t1_gain*sensor_t0_gain;
        float32_t w_gain = 1.0f;

        if (weiner_enable > 0)
        {
            w_gain = 1.0f / (1.0f + powf(10, (-snr / 10.0f)));
        }

        new_val *= w_gain;
        float32_t gain_after_gamma = powf(new_val, gain_gamma);
        gain_after_gamma = clampf32(gain_after_gamma, 0.01f, 15.9f);
        float32_t new_val_clamped = clampf32(new_val, 0.01f, 255.0f);
        set_param_if_empty(storage, ISP_INTERNAL_dgCfg__Gain, gain_after_gamma*256.f);
        set_param_if_empty(storage, ISP_INTERNAL_TOTAL_GAIN, new_val);

        float32_t alpha = logf(target_ave_br + FLT_EPSILON) / logf(((ave_br / sensor_t0_gain) * new_val_clamped) + FLT_EPSILON);
        float32_t smoothed = expf((0.02f * logf(alpha)) + ((1.0f - 0.02f) * logf(prev_gamma)));
        smoothed = ISP_MIN(ISP_MAX(0.001f, smoothed), 1.25f);

        if (gamma_enable == 0)
        {
            smoothed = 1.0f;
        }

        isp_tracelog_v("smooth %f ltm alpha: %f = logf(%f) / logf((%f / %f) * %f)\n", smoothed, alpha, target_ave_br, ave_br, sensor_t0_gain, new_val_clamped);
        set_param_if_empty(storage, ISP_INTERNAL_ISPGAIN_CONTROL_GAMMA_VALUE, smoothed);

        isp_tracelog_v("ISP GAIN %.2f %.2f %.2f %.2f %.2f\n",
            sensor_t0_gain,
            sensor_t1_gain,
            new_val,
            w_gain,
            exp_emb);
    }
    else
    {
        isp_tracelog_e("ISP GAIN FAILURE %.2f %.2f %.2f %.2f\n",
            sensor_t0_gain,
            sensor_t1_gain,
            max_isp_gain,
            gain_gamma);
        ret = -1.f;
    }

    return ret;
}
#endif

float32_t LTM_CONTROL_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;

    bool input_is_ok = true;
    float32_t gain = get_param_check(storage, ISP_INTERNAL_TOTAL_GAIN, &input_is_ok);
    float32_t gain_in_gamma = get_param_check(storage, ISP_INTERNAL_dgCfg__Gain, &input_is_ok) / 256.0f;
    uint32_t enable_update = (uint32_t)get_param_check(storage, LTM_CONTROL_UPDATE_ENABLE, &input_is_ok);
    float32_t white_q = get_param_check(storage, WHITE_Q, &input_is_ok);
    float32_t default_slope = get_param_check(storage, LTM_CONTROL_DEFAULT_CURVE_SLOPE, &input_is_ok);
    float32_t prev_slope = get_param_check(storage, LTM_CONTROL_CURVE_SLOPE, &input_is_ok);
    float32_t l_thresh = get_param_check(storage, LTM_CONTROL_LOW_THRESH, &input_is_ok);
    float32_t h_thresh = get_param_check(storage, LTM_CONTROL_HIGH_THRESH, &input_is_ok);
    float32_t l_slope = get_param_check(storage, LTM_CONTROL_LOW_CURVE_SLOPE, &input_is_ok);
    float32_t h_slope = get_param_check(storage, LTM_CONTROL_HIGH_CURVE_SLOPE, &input_is_ok);
    float32_t art_bl = get_param_check(storage, LTM_CONTROL_ART_BLACK_LEVEL, &input_is_ok);
    float32_t bl_scale = get_param_check(storage, LTM_CONTROL_BL_SCALE, &input_is_ok);
    uint8_t enable_max_slope = (uint8_t)get_param_check(storage, LTM_CONTROL_ENABLE_MAX_SLOPE, &input_is_ok);
    float32_t def_max_slope = get_param_check(storage, LTM_CONTROL_DEFAULT_MAX_SLOPE, &input_is_ok);
    float32_t prev_max_slope = get_param_check(storage, LTM_CONTROL_PREV_MAX_SLOPE, &input_is_ok);
    float32_t black_level_residue = get_param_check(storage, BLACK_LEVEL_RESIDUE, &input_is_ok);
    float32_t sensor_black_level = get_param_check(storage, SENSOR_BLACK_LEVEL_DEFAULT, &input_is_ok);



    if (input_is_ok)
    {
        float32_t total_white_q = white_q * gain;
        float32_t slope = l_thresh;
        if (total_white_q > h_thresh)
        {
            slope = l_slope;
        }
        else if (total_white_q < l_thresh)
        {
            slope = l_slope;
        }
        else
        {
            float32_t x = (total_white_q - l_thresh) / (h_thresh - l_thresh);
            slope = clampf32(x * 120, 90, 120);
        }

        if (enable_update == 0)
        {
            slope = default_slope;
        }

        float32_t smoothed = expf((0.01f * logf(slope)) + ((1.0f - 0.01f) * logf(prev_slope)));
        isp_tracelog_v("cam_num %d t_w_q: %f = %f * %f, slope: %f %f %f\n", camera_num, total_white_q, white_q, gain, default_slope, slope, smoothed); /* PRQA S 2743 */
        set_param_if_empty(storage, ISP_INTERNAL_LTM_CONTROL_SLOPE_VALUE, smoothed);

        float32_t ltm_bl = (art_bl+sqrtf(black_level_residue*256.f)) * gain_in_gamma * bl_scale;
        set_param_if_empty(storage, ISP_INTERNAL_LTM_CONTROL_ART_BL_VAL, art_bl);
        set_param_if_empty(storage, ISP_INTERNAL_LTM_CONTROL_BL_VAL, ltm_bl);

        isp_tracelog_v("cam_num %d ltm_bl: %f = %f * %f * %f\n", camera_num, ltm_bl, art_bl, gain_in_gamma, bl_scale); /* PRQA S 2743 */
        float32_t new_max_slope = def_max_slope;

        if (enable_max_slope > 0.0f)
        {
            new_max_slope = clampf32(def_max_slope / gain, 60.0f, def_max_slope);
            new_max_slope = expf((0.01f * logf(new_max_slope)) + ((1.0f - 0.01f) * logf(prev_max_slope)));
        }

        set_param_if_empty(storage, ISP_INTERNAL_LTM_CONTROL_MAX_SLOPE_VAL, new_max_slope);
        isp_tracelog_v("cam_num %d ltm_max_slope: %f = %f / %f\n", camera_num, new_max_slope, def_max_slope, gain); /* PRQA S 2743 */
    }

    return ret;
}

float32_t HISTORY_ADAPTIVE_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;

    bool input_is_ok = true;
    float32_t global_nm = get_param_check(storage, AE_IN_GLOBAL_NM, &input_is_ok);
    int32_t delay_nm = (int32_t)get_param_check(storage, SENSOR_IN_DELAY_NM, &input_is_ok);
    int32_t delay_dm = (int32_t)get_param_check(storage, SENSOR_IN_DELAY_DM, &input_is_ok);

    if (input_is_ok)
    {
        AE_CONTROL_ITEM t_internal[] = {
            ISP_INTERNAL_HISTORY_REAL_EXPOSURE,
            ISP_INTERNAL_HISTORY_SENSOR_EXPOSURE,
            ISP_INTERNAL_HISTORY_SENSOR_DLO_GAIN,
            ISP_INTERNAL_HISTORY_SENSOR_DC_GAIN,
            ISP_INTERNAL_HISTORY_SENSOR_ANALOG_GAIN,
            ISP_INTERNAL_HISTORY_SENSOR_PRE_HDR_GAIN,
            };

        AE_CONTROL_ITEM t0[] = {
            SENSOR_EXPOSURE,
            AE_EXPOSURE,
            AE_DLO_GAIN,
            AE_DC_GAIN,
            AE_ANALOG_GAIN,
            SENSOR_PRE_HDR_GAIN,
            };

        int32_t delay = cmp_f32(global_nm, 0.0f) ? delay_dm : delay_nm;
        delay = clamp(delay, 0, (circular_buffer_max_sz-1));

        uint32_t sz = sizeof(t_internal) / sizeof(t_internal[0]);

        uint32_t i;
        for (i = 0; i < sz; i++)
        {
            set_param_if_empty(storage, t_internal[i], get_buffer_parameter(storage, t0[i], delay));
        }

        set_param_if_empty(storage, ISP_INTERNAL_HISTORY_LTM_SENSOR_VIRTUAL_GAIN_T1, get_buffer_parameter(storage, SENSOR_VIRTUAL_GAIN_T1, delay - 1));
        set_param_if_empty(storage, ISP_INTERNAL_HISTORY_LTM_SENSOR_GAIN, get_buffer_parameter(storage, AE_DLO_GAIN, delay - 1));
        set_param_if_empty(storage, ISP_INTERNAL_HISTORY_LTM_SENSOR_EXP, get_buffer_parameter(storage, AE_EXPOSURE, delay - 1));
        set_param_if_empty(storage, ISP_INTERNAL_HISTORY_LTM_SENSOR_ANALOG_GAIN, get_buffer_parameter(storage, AE_ANALOG_GAIN, delay - 1));
    }
    else
    {
        ret = -1.f;
    }

    return ret;
}

#ifdef MAGNA_PSA
float32_t STATISTIC_UPDATE_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;

    bool sensor_t0_gain_is_ok = true;
    bool input_is_ok = true;
    float32_t thresholds[4];
    thresholds[0] = get_param_check(storage, ExpStats_Hist_Thresh_01_DEFAULT, &input_is_ok);
    thresholds[1] = get_param_check(storage, ExpStats_Hist_Thresh_12_DEFAULT, &input_is_ok);
    thresholds[2] = get_param_check(storage, ExpStats_Hist_Thresh_23_DEFAULT, &input_is_ok);
    thresholds[3] = get_param_check(storage, ExpStats_Hist_Thresh_34_DEFAULT, &input_is_ok);
    float32_t sensor_t0_gain = get_param_check(storage, SENSOR_VIRTUAL_GAIN_T0, &sensor_t0_gain_is_ok);
    sensor_t0_gain = sensor_t0_gain_is_ok ? sensor_t0_gain : 1.f;

    if (input_is_ok)
    {
        float32_t thresholds_decomp[5];
        thresholds_decomp[0] = (float32_t)compand((uint32_t)((thresholds[0] / 255.0f) * 64000.0f), compand_table_12, compand_table_20);
        thresholds_decomp[1] = (float32_t)compand((uint32_t)((thresholds[1] / 255.0f) * 64000.0f), compand_table_12, compand_table_20);
        thresholds_decomp[2] = (float32_t)compand((uint32_t)((thresholds[2] / 255.0f) * 64000.0f), compand_table_12, compand_table_20);
        thresholds_decomp[3] = (float32_t)compand((uint32_t)((thresholds[3] / 255.0f) * 64000.0f), compand_table_12, compand_table_20);
        thresholds_decomp[4] = (float32_t)compand_table_20.data[3];

        thresholds_decomp[0] = ISP_MIN((thresholds_decomp[0] / sensor_t0_gain), thresholds_decomp[4]);
        thresholds_decomp[1] = ISP_MIN((thresholds_decomp[1] / sensor_t0_gain), thresholds_decomp[4]);
        thresholds_decomp[2] = ISP_MIN((thresholds_decomp[2] / sensor_t0_gain), thresholds_decomp[4]);
        thresholds_decomp[3] = ISP_MIN((thresholds_decomp[3] / sensor_t0_gain), thresholds_decomp[4]);

        thresholds[0] = floorf((((float32_t)compand((uint32_t)thresholds_decomp[0], compand_table_20, compand_table_12) / 64000.0f) * 255.0f) + 0.5f);
        thresholds[1] = floorf((((float32_t)compand((uint32_t)thresholds_decomp[1], compand_table_20, compand_table_12) / 64000.0f) * 255.0f) + 0.5f);
        thresholds[2] = floorf((((float32_t)compand((uint32_t)thresholds_decomp[2], compand_table_20, compand_table_12) / 64000.0f) * 255.0f) + 0.5f);
        thresholds[3] = floorf((((float32_t)compand((uint32_t)thresholds_decomp[3], compand_table_20, compand_table_12) / 64000.0f) * 255.0f) + 0.5f);

        set_param_if_empty(storage, ISP_INTERNAL_expStatsCfg__Hist_Thresh_01, thresholds[0]);
        set_param_if_empty(storage, ISP_INTERNAL_expStatsCfg__Hist_Thresh_12, thresholds[1]);
        set_param_if_empty(storage, ISP_INTERNAL_expStatsCfg__Hist_Thresh_23, thresholds[2]);
        set_param_if_empty(storage, ISP_INTERNAL_expStatsCfg__Hist_Thresh_34, thresholds[3]);
    }
    else
    {
        ret = -1.f;
    }

    return ret;
}
#else
float32_t STATISTIC_UPDATE_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;
    return ret;
}
#endif
float32_t SATURATION_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;

    bool input_is_ok = true;
    uint8_t algo = get_param_check(storage, SAT_ALGO, &input_is_ok);
    float32_t current_percentage = 1.0f;

    if (algo > 0)
    {
        float32_t snr_target = get_param_check(storage, SAT_TARGET_SNR, &input_is_ok);
        float32_t snr = get_param_check(storage, SNR, &input_is_ok);
        float32_t snr_ratio = snr / (snr_target + FLT_EPSILON);
        current_percentage = clampf32(snr_ratio, 0.3f, 1.0f);
        isp_tracelog_d("sat: %f %f\n", snr_ratio, current_percentage);
    }
    else
    {
        float32_t gain = get_param_check(storage, ISP_INTERNAL_TOTAL_GAIN, &input_is_ok);
        float32_t start = get_param_check(storage, SAT_SHARP_OFFSET, &input_is_ok);
        float32_t slope = get_param_check(storage, SAT_SHARP_SLOPE, &input_is_ok);

        current_percentage = clampf32(gain - start, 0.f, 100.f) / (slope - start);
        current_percentage = 1.f - clampf32(current_percentage, 0.f, 0.7f);
    }

    if (input_is_ok)
    {
        float32_t sat_new_val = current_percentage * 100.0f;
        set_param_if_empty(storage, ISP_INTERNAL_SATURATION, sat_new_val);
    }
    else
    {
        ret = -1.f;
    }

    return ret;
}


float32_t SHARPNESS_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;

    bool input_is_ok = true;
    float32_t sharp_Str_ud = 160;//get_param_check(storage, demCfg__RGGB__Sharp_Str_ud, &input_is_ok);
    float32_t sharp_algo = 0;//get_param_check(storage, demCfg__RGGB__Sharp_Algorithm, &input_is_ok);
    float32_t ev = get_param_check(storage, SENSOR_EV, &input_is_ok);

    float32_t sharp_Str_ud_default = get_param_check(storage, demCfg__RGGB__Sharp_Str_ud_DEFAULT, &input_is_ok);
    float32_t sharp_Str_Lu_default = get_param_check(storage, demCfg__RGGB__Sharp_Str_Lu_DEFAULT, &input_is_ok);
    float32_t sharp_Str_Ldu_default = get_param_check(storage, demCfg__RGGB__Sharp_Str_Ldu_DEFAULT, &input_is_ok);
    float32_t sharp_Str_Ld_default = get_param_check(storage, demCfg__RGGB__Sharp_Str_Ld_DEFAULT, &input_is_ok);
    float32_t mv = get_param_check(storage, MODES_MV_IN_VAL, &input_is_ok);
    float32_t start = get_param_check(storage, SAT_SHARP_OFFSET, &input_is_ok);
    float32_t slope = get_param_check(storage, SAT_SHARP_SLOPE, &input_is_ok);
    float32_t current_percentage = ((slope * (start / 100.0f)) / (ev + FLT_EPSILON));

    if ((input_is_ok) && (mv < 1.0f))
    {
        if (sharp_algo > 0.0f)
        {
            float32_t sharp_Str_Lu_new_val = (current_percentage * sharp_Str_Lu_default);
            float32_t sharp_Str_Ldu_new_val = (current_percentage * sharp_Str_Ldu_default);
            float32_t sharp_Str_Ld_new_val = (current_percentage * sharp_Str_Ld_default);

            sharp_Str_Lu_new_val = ISP_MIN(sharp_Str_Lu_new_val, sharp_Str_Lu_default);
            sharp_Str_Lu_new_val = ISP_MAX(sharp_Str_Lu_new_val, 0.0f);
            sharp_Str_Ldu_new_val = ISP_MIN(sharp_Str_Ldu_new_val, sharp_Str_Ldu_default);
            sharp_Str_Ldu_new_val = ISP_MAX(sharp_Str_Ldu_new_val, 0.0f);
            sharp_Str_Ld_new_val = ISP_MIN(sharp_Str_Ld_new_val, sharp_Str_Ld_default);
            sharp_Str_Ld_new_val = ISP_MAX(sharp_Str_Ld_new_val, 0.0f);
            set_param_if_empty(storage, ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Lu, sharp_Str_Lu_new_val);
            set_param_if_empty(storage, ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Ldu, sharp_Str_Ldu_new_val);
            set_param_if_empty(storage, ISP_INTERNAL_demCfg__RGGB__Sharp_Str_Ld, sharp_Str_Ld_new_val);
        }
        else
        {
            float32_t sharp_Str_ud_new_val = current_percentage * sharp_Str_ud_default;
            sharp_Str_ud_new_val = ISP_MIN(sharp_Str_ud_new_val, sharp_Str_ud_default);
            sharp_Str_ud_new_val = ISP_MAX(sharp_Str_ud_new_val, 8.0f);
            float32_t smoothed = expf((0.1f*logf(sharp_Str_ud_new_val)) + (0.9f*logf(sharp_Str_ud)));
            set_param_if_empty(storage, ISP_INTERNAL_demCfg__RGGB__Sharp_Str_ud, smoothed);
        }
    }
    else
    {
        ret = -1.f;
    }

    return ret;
}

float32_t DBLC_CONTROL_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;

    bool input_is_ok = true;
    uint32_t frame_counter = (uint32_t)get_param_check(storage, FRAME_COUNTER, &input_is_ok);
    uint32_t dblc_period = (uint32_t)get_param_check(storage, DBLC_PERIOD, &input_is_ok);
    uint32_t dblc_config_on = (uint32_t)get_param_check(storage, DBLC_CONFIG_ON, &input_is_ok);
    uint32_t dblc_config_off = (uint32_t)get_param_check(storage, DBLC_CONFIG_OFF, &input_is_ok);
    uint32_t prev_dblc_config = (uint32_t)get_param_check(storage, SENSOR_DBLC_CONFIG, &input_is_ok);
    uint32_t dblc_frames_threshold = (uint32_t)get_param_check(storage, DBLC_FRAMES_THRESHOLD, &input_is_ok);
    uint32_t n_frames_wo_changes_exp_again = (uint32_t)get_param_check(storage, N_FRAMES_WO_CHANGES_EXP_AGAIN, &input_is_ok);


    uint32_t nm = (uint32_t)get_param_check(storage, AE_NIGHT_MODE, &input_is_ok);

    if (input_is_ok)
    {
        dblc_frames_threshold = (nm == 1u) ? (dblc_frames_threshold / 2u) : dblc_frames_threshold;
        bool silent_check = n_frames_wo_changes_exp_again >= dblc_frames_threshold;
        bool emergent_trigger = n_frames_wo_changes_exp_again == dblc_frames_threshold;
        dblc_period = (nm == 1u) ? (dblc_period / 2u) : dblc_period;
        if ((dblc_period != 0) && (((frame_counter % dblc_period) == 0) || emergent_trigger) && silent_check)
        {
            set_param_if_empty(storage, ISP_INTERNAL_DBLC_CONTROL, (float32_t)dblc_config_on);
        }
        else if (prev_dblc_config != dblc_config_off) /* PRQA S 2004 */
        {
            set_param_if_empty(storage, ISP_INTERNAL_DBLC_CONTROL, (float32_t)dblc_config_off);
        }
    }
    else
    {
        ret = -1.f;
    }

    return ret;
}

float32_t CCM_INTERP_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num
    )
{
    float32_t ret = 1.f;

    bool input_is_ok = true;
    const ae_auto_params_table_t* temp_table = find_table_by_id(context->adjust_tables, TABLES_CCM_INTERP_TEMP);
    const ae_auto_params_table_t* temp_str_table = find_table_by_id(context->adjust_tables, TABLES_CCM_INTERP_TEMP_STR);
    const ae_auto_params_table_t* link_table = find_table_by_id(context->adjust_tables, TABLES_CCM_INTERP_LINK_TEMP_CCM);
    float32_t temp_nonclamp = get_param_check(storage, AWB_OUT_TEMP_NONCLAMP, &input_is_ok);
    float32_t tint_nonclamp = get_param_check(storage, AWB_OUT_TINT_NONCLAMP, &input_is_ok);
    float32_t negative_tint_str = get_param_check(storage, CCM_INTERP_NEGATIVE_TINT_STR, &input_is_ok);

    if (input_is_ok)
    {
        int32_t index_right = 0;
        int32_t index_left = 0;
        float32_t interp_coef = 0.0f;
        float32_t inv_temp_nonclamp = 1.0f / temp_nonclamp;
        index_right = lower_bound_f32(temp_table->out, temp_table->table_size, temp_nonclamp);
        index_right = clampf32(index_right, 0, temp_table->table_size - 1);

        if ((index_right > 0) && ((fabsf(temp_table->out[index_right] - temp_nonclamp) < 1.0f) ||
                                        (index_right == temp_table->table_size)))
        {
            index_left = index_right;
        }
        else
        {
            index_left = index_right - 1;
            index_left = clampf32(index_left, 0, temp_table->table_size - 1);
        }

        if (index_left != index_right)
        {
            float32_t temp_right = 1.0f / get_table_value(temp_table, (float32_t)index_right);
            float32_t temp_left = 1.0f / get_table_value(temp_table, (float32_t)index_left);
            interp_coef = (inv_temp_nonclamp - temp_left + FLT_EPSILON) / (temp_right - temp_left + FLT_EPSILON);
        }

        isp_tracelog_d("interp params: %f %f %d %d %.2f\n", temp_nonclamp, tint_nonclamp,  index_left, index_right, interp_coef);
        const ae_auto_params_table_t* left_ccm = find_table_by_id(context->adjust_tables, (uint32_t)get_table_value(link_table, (float32_t)index_left));
        const ae_auto_params_table_t* right_ccm = find_table_by_id(context->adjust_tables, (uint32_t)get_table_value(link_table, (float32_t)index_right));
        float32_t ccm_mat_interp[9] = {};
        for (uint32_t i = 0; i < 3; i++)
        {
            uint32_t y_offset = i * 3;
            for (uint32_t j = 0; j < 3; j++)
            {
                uint32_t offset = y_offset + j;
                ccm_mat_interp[offset] = (1.0f - interp_coef) * left_ccm->out[offset] + interp_coef * right_ccm->out[offset];
            }
        }

        float32_t str_left = temp_str_table->out[index_left];
        float32_t str_right = temp_str_table->out[index_right];
        float32_t temp_str = str_left * (1.0f - interp_coef) + str_right * interp_coef;
        float32_t result_str = ISP_MAX(0, temp_str - negative_tint_str * fabsf(tint_nonclamp));
        for (uint32_t i = 0; i < 3; i++)
        {
            uint32_t y_offset = i * 3;
            for (uint32_t j = 0; j < 3; j++)
            {
                uint32_t offset = y_offset + j;
                set_param_if_empty(storage, ISP_INTERNAL_CCM_MAT_0_0 + offset, result_str * ccm_mat_interp[offset]);
            }
        }

        set_param(storage, ISP_INTERNAL_CCM_MAT_0_0, (1.0f - result_str) + result_str * ccm_mat_interp[0]);
        set_param(storage, ISP_INTERNAL_CCM_MAT_1_1, (1.0f - result_str) + result_str * ccm_mat_interp[4]);
        set_param(storage, ISP_INTERNAL_CCM_MAT_2_2, (1.0f - result_str) + result_str * ccm_mat_interp[8]);

        isp_tracelog_sv("interp ccm:\n %1.3f %1.3f %1.3f\n %1.3f %1.3f %1.3f\n %1.3f %1.3f %1.3f\n",
                        get_param(storage, ISP_INTERNAL_CCM_MAT_0_0), get_param(storage, ISP_INTERNAL_CCM_MAT_0_1), get_param(storage, ISP_INTERNAL_CCM_MAT_0_2),
                        get_param(storage, ISP_INTERNAL_CCM_MAT_1_0), get_param(storage, ISP_INTERNAL_CCM_MAT_1_1), get_param(storage, ISP_INTERNAL_CCM_MAT_1_2),
                        get_param(storage, ISP_INTERNAL_CCM_MAT_2_0), get_param(storage, ISP_INTERNAL_CCM_MAT_2_1), get_param(storage, ISP_INTERNAL_CCM_MAT_2_2));
    }
    else
    {
        ret = -1.f;
    }

    return ret;
}
/* PRQA S 0604 -- */
/* PRQA S 0781 -- */
/* PRQA S 1401 -- */
/* PRQA S 1461 -- */
/* PRQA S 3450 -- */
/* PRQA S 3206 -- */
/* PRQA S 1056 -- */
/* PRQA S 1330 -- */
/* PRQA S 3408 -- */
/* PRQA S 0491 -- */
/* PRQA S 1031 -- */
/* PRQA S 1055 -- */
