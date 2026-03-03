/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           isp_awb_wrapper.c
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
/* PRQA S 1056 ++ */


#include "isp_algo.h"
#include "awb-impl.h"

extern const uint8_t default_node_weight[]; /* PRQA S 3447 */ /* PRQA S 3684 */

void AWB_defaults(parameters_storage_t* s) /* PRQA S 3408 */
{
    if (s != NULL)
    {
        set_param(s, STATISTIC_IN_GAMMA, 1.f);
        set_param(s, SENSOR_LPD_SPD_RATIO, 1.f);
        set_param(s, AWB_IN_FREQ, 1.f);
        set_param(s, AWB_IN_ENABLED, 1.f);
        set_param(s, AWB_OUT_ENABLED, 1.f);
        set_param(s, AWB_IN_PHASE, 0.f);
        set_param(s, AWB_IN_PIX_COUNT_THRESHOLD, 92.f);
        set_param(s, AWB_IN_MIN_VALID_BLOCKS_RATIO, 0.05f);
        set_param(s, AWB_IN_LOW_BRIGHTNESS_THRESHOLD, 3e-05);
        set_param(s, AWB_IN_UPPER_BRIGHTNESS_THRESHOLD, 0.7f);
        set_param(s, AWB_IN_QDA_WEIGHT_0, 0.5f);
        set_param(s, AWB_IN_QDA_WEIGHT_1, 0.6f);
        set_param(s, AWB_IN_QDA_WEIGHT_2, 250.f);
        set_param(s, AWB_IN_QDA_WEIGHT_3, 100.0f);
        set_param(s, AWB_IN_QDA_WEIGHT_4, 20.f);
        set_param(s, AWB_IN_TEMPERATURES_0, 6500.f);
        set_param(s, AWB_IN_TEMPERATURES_1, 3000.f);
        set_param(s, AWB_IN_TEMP_RANGE_MIN, 1700.f);
        set_param(s, AWB_IN_TEMP_RANGE_MAX, 25000.f);
        set_param(s, AWB_IN_TINT_RANGE_MIN, -0.15f);
        set_param(s, AWB_IN_TINT_RANGE_MAX, 0.15f);
        set_param(s, AWB_IN_TEMP_RESULT_RANGE_MIN, 1700.f);
        set_param(s, AWB_IN_TEMP_RESULT_RANGE_MAX, 25000.f);
        set_param(s, AWB_IN_TINT_RESULT_RANGE_MIN, -0.04f);
        set_param(s, AWB_IN_TINT_RESULT_RANGE_MAX, 0.07f);
        set_param(s, AWB_IN_CONFIDENCE_THRESHOLD, 0.001f);
        set_param(s, AWB_IN_TEMP_CALIB_COLD_RG, 0.75);
        set_param(s, AWB_IN_TEMP_CALIB_COLD_BG, 0.54);
        set_param(s, AWB_IN_TEMP_CALIB_WARM_RG, 1.08);
        set_param(s, AWB_IN_TEMP_CALIB_WARM_BG, 0.33);
        set_param(s, AWB_IN_GW_MODEL_VAL_0, 2.031583061418352);
        set_param(s, AWB_IN_GW_MODEL_VAL_1, -0.600233312669989);
        set_param(s, AWB_IN_GW_MODEL_VAL_2, -2.743797559830568);
        set_param(s, AWB_IN_GW_MODEL_VAL_3, -0.1940634379114219);
        set_param(s, AWB_IN_SECOND_COMPONENT_THRESHOLD, 0.225);
        set_param(s, AWB_IN_CFA_PATTERN, 177);
        set_param(s, AWB_IN_HULL_DIST_THRESH, 0.005f);
        set_param(s, AWB_IN_Q6, 100.0);
        set_param(s, AWB_IN_MODE, 1.0);
        set_param(s, AWB_OUT_MODE, 1.0);
        set_param(s, AWB_SKIP_COUNTER, 0.0);
        set_param(s, AWB_VALID_BLOCKS, 0.0);
        set_param(s, AWB_OUT_TEMP_NONCLAMP, 6500.f);
        set_param(s, AWB_OUT_TINT_NONCLAMP, 0.f);
        set_param(s, AWB_OUT_PREV_INV_TEMP, 1000.0f / 6500.f);
        set_param(s, AWB_OUT_PREV_TINT, 0.f);
        set_param(s, AWB_IN_AVE_LR, 0.0f);
        set_param(s, AWB_IN_AVE_LG, 0.0f);
        set_param(s, AWB_IN_AVE_LB, 0.0f);
        set_param(s, AWB_IN_SPEED, 1.0f);

        set_param(s, AWB_OUT_R, 1.0);
        set_param(s, AWB_OUT_G, 1.0);
        set_param(s, AWB_OUT_B, 1.0);
        set_param(s, AE_RED_GAIN, 1.41);
        set_param(s, AE_GREEN_GAIN, 1.0);
        set_param(s, AE_BLUE_GAIN, 2.24);
        set_param(s, ALG_CCM_MAT_0_0, 1.4650f);
        set_param(s, ALG_CCM_MAT_0_1, -0.1084f);
        set_param(s, ALG_CCM_MAT_0_2, -0.3566f);
        set_param(s, ALG_CCM_MAT_1_0, -0.5775f);
        set_param(s, ALG_CCM_MAT_1_1, 1.8165f);
        set_param(s, ALG_CCM_MAT_1_2, -0.2389f);
        set_param(s, ALG_CCM_MAT_2_0, -0.0912f);
        set_param(s, ALG_CCM_MAT_2_1, -0.2741f);
        set_param(s, ALG_CCM_MAT_2_2, 1.3653f);
        set_param(s, DISABLE_CCM, 0);
    }
}

static inline void conv_lg_to_temp_tint(float32_t model_val_0,
                                        float32_t model_val_1,
                                        float32_t model_val_2,
                                        float32_t model_val_3,
                                        float32_t in_lrg,
                                        float32_t in_lbg,
                                        float32_t *inv_temp,
                                        float32_t *tint)
{
    const float32_t d = model_val_0 * model_val_0 + model_val_2 * model_val_2;
    float32_t dlrg = in_lrg - model_val_1;
    float32_t dlbg = in_lbg - model_val_3;
    *inv_temp = (model_val_0 * dlrg + model_val_2 * dlbg) / d;
    *tint = (-model_val_2 * dlrg + model_val_0 * dlbg) / d;
}

static inline void process_gw_stats(
    parameters_storage_t* storage,
    awb_config_t *config,
    const float32_t gains_from_sensor[MAX_CHANNELS],
    const float32_t gains_from_sensor_prev[MAX_CHANNELS],
    uint32_t camera_num /* PRQA S 1330 */ /* PRQA S 3206 */
    )
{
    bool input_is_ok = true; /* PRQA S 1056 */
    float32_t ave_lr  = get_param_check(storage, AWB_IN_AVE_LR, &input_is_ok);
    float32_t ave_lg  = get_param_check(storage, AWB_IN_AVE_LG, &input_is_ok);
    float32_t ave_lb  = get_param_check(storage, AWB_IN_AVE_LB, &input_is_ok);
    float32_t prev_ave_lr  = get_buffer_param_check(storage, AWB_IN_AVE_LR, 1, &input_is_ok);
    float32_t prev_ave_lg  = get_buffer_param_check(storage, AWB_IN_AVE_LG, 1, &input_is_ok);
    float32_t prev_ave_lb  = get_buffer_param_check(storage, AWB_IN_AVE_LB, 1, &input_is_ok);
    float32_t speed  = get_param_check(storage, AWB_IN_SPEED, &input_is_ok);
    float32_t model_val_0  = get_param_check(storage, AWB_IN_GW_MODEL_VAL_0, &input_is_ok);
    float32_t model_val_1  = get_param_check(storage, AWB_IN_GW_MODEL_VAL_1, &input_is_ok);
    float32_t model_val_2  = get_param_check(storage, AWB_IN_GW_MODEL_VAL_2, &input_is_ok);
    float32_t model_val_3  = get_param_check(storage, AWB_IN_GW_MODEL_VAL_3, &input_is_ok);

    if (input_is_ok)
    {
        float32_t lrg = ave_lr - ave_lg - logf(gains_from_sensor[RED]) + logf(gains_from_sensor[GREEN]);
        float32_t lbg = ave_lb - ave_lg - logf(gains_from_sensor[BLUE]) + logf(gains_from_sensor[GREEN]);
        float32_t lrg_prev = prev_ave_lr - prev_ave_lg - logf(gains_from_sensor_prev[RED]) + logf(gains_from_sensor_prev[GREEN]);
        float32_t lbg_prev = prev_ave_lb - prev_ave_lg - logf(gains_from_sensor_prev[BLUE]) + logf(gains_from_sensor_prev[GREEN]);
        float32_t inv_temp_cur = 0.0f;
        float32_t inv_temp_prev = 0.0f;
        float32_t tint_cur = 0.0f;
        float32_t tint_prev = 0.0f;
        conv_lg_to_temp_tint(model_val_0, model_val_1, model_val_2, model_val_3, lrg, lbg, &inv_temp_cur, &tint_cur);
        conv_lg_to_temp_tint(model_val_0, model_val_1, model_val_2, model_val_3, lrg_prev, lbg_prev, &inv_temp_prev, &tint_prev);
        config->gw_dtemp = fabs(inv_temp_cur - inv_temp_prev) + speed;
        config->gw_dtint = fabs(tint_cur - tint_prev) + speed;
    }
}

float32_t AWB_run(
    ae_context_impl_t* context,
    const ae_input_stats_t* stats,
    parameters_storage_t* storage,
    uint32_t camera_num /* PRQA S 1330 */ /* PRQA S 3206 */
    )
{
    PROF_START(AWB_run);

    awb_config_t config = {0};
    bool input_is_ok = true; /* PRQA S 1056 */
    float32_t ret = -1.f;

    if ((context    != NULL) &&
        (stats      != NULL) &&
        (storage    != NULL))
    {
        config.block_count = ISP_AWB_NUM_ZONES;
        config.mask = default_node_weight;

        float32_t gains_from_sensor[MAX_CHANNELS] = {0};
        float32_t gains_from_sensor_prev[MAX_CHANNELS] = {0};

        gains_from_sensor[RED] = get_param_check(storage, ISP_INTERNAL_EMB_LINE_RED_GAIN, &input_is_ok) / 128.0f;
        gains_from_sensor[GREEN] = get_param_check(storage, ISP_INTERNAL_EMB_LINE_GREEN_GAIN, &input_is_ok) / 128.0f;
        gains_from_sensor[BLUE] = get_param_check(storage, ISP_INTERNAL_EMB_LINE_BLUE_GAIN, &input_is_ok) / 128.0f;

        gains_from_sensor_prev[RED] = get_buffer_parameter(storage, ISP_INTERNAL_EMB_LINE_RED_GAIN, 1) / 128.0f;
        gains_from_sensor_prev[GREEN] = get_buffer_parameter(storage, ISP_INTERNAL_EMB_LINE_GREEN_GAIN, 1) / 128.0f;
        gains_from_sensor_prev[BLUE] = get_buffer_parameter(storage, ISP_INTERNAL_EMB_LINE_BLUE_GAIN, 1) / 128.0f;

        if (check_invalid(gains_from_sensor_prev[RED]) ||
            check_invalid(gains_from_sensor_prev[GREEN]) ||
            check_invalid(gains_from_sensor_prev[BLUE]))
        {
            input_is_ok = false;
            isp_tracelog_i("AWB history is not gathered\n");
        }

        float32_t mingain;

        if (input_is_ok)
        {
            mingain = ISP_MIN(gains_from_sensor[RED], gains_from_sensor[GREEN]);
            mingain = ISP_MIN(mingain, gains_from_sensor[BLUE]);

            if (mingain > 0.f)
            {
                gains_from_sensor[RED] /= mingain;
                gains_from_sensor[GREEN] /= mingain;
                gains_from_sensor[BLUE] /= mingain;
            }
            else
            {
                input_is_ok = false;
            }
        }

        if (input_is_ok)
        {
            mingain = ISP_MIN(gains_from_sensor_prev[RED], gains_from_sensor_prev[GREEN]);
            mingain = ISP_MIN(mingain, gains_from_sensor_prev[BLUE]);

            if (mingain > 0.f)
            {
                gains_from_sensor_prev[RED] /= mingain;
                gains_from_sensor_prev[GREEN] /= mingain;
                gains_from_sensor_prev[BLUE] /= mingain;
            }
            else
            {
                input_is_ok = false;
            }
        }

        config.second_component_threshold =  get_param_check(storage,AWB_IN_SECOND_COMPONENT_THRESHOLD, &input_is_ok);

        config.min_valid_blocks_ratio = get_param_check(storage,AWB_IN_MIN_VALID_BLOCKS_RATIO, &input_is_ok);
        config.qda_weight[0] = get_param_check(storage,AWB_IN_QDA_WEIGHT_0, &input_is_ok);
        config.qda_weight[1] = get_param_check(storage,AWB_IN_QDA_WEIGHT_1, &input_is_ok);
        config.qda_weight[2] = get_param_check(storage,AWB_IN_QDA_WEIGHT_2, &input_is_ok);
        config.qda_weight[3] = get_param_check(storage,AWB_IN_QDA_WEIGHT_3, &input_is_ok);
        config.qda_weight[4] = get_param_check(storage,AWB_IN_QDA_WEIGHT_4, &input_is_ok);
        config.temperatures[0] = get_param_check(storage,AWB_IN_TEMPERATURES_0, &input_is_ok);
        config.temperatures[1] = get_param_check(storage,AWB_IN_TEMPERATURES_1, &input_is_ok);
        config.temp_range_min = get_param_check(storage,AWB_IN_TEMP_RANGE_MIN, &input_is_ok);
        config.temp_range_max = get_param_check(storage,AWB_IN_TEMP_RANGE_MAX, &input_is_ok);
        config.tint_range_min = get_param_check(storage,AWB_IN_TINT_RANGE_MIN, &input_is_ok);
        config.tint_range_max = get_param_check(storage,AWB_IN_TINT_RANGE_MAX, &input_is_ok);
        config.temp_result_range_min = get_param_check(storage,AWB_IN_TEMP_RESULT_RANGE_MIN, &input_is_ok);
        config.temp_result_range_max = get_param_check(storage,AWB_IN_TEMP_RESULT_RANGE_MAX, &input_is_ok);
        config.tint_result_range_min = get_param_check(storage,AWB_IN_TINT_RESULT_RANGE_MIN, &input_is_ok);
        config.tint_result_range_max = get_param_check(storage,AWB_IN_TINT_RESULT_RANGE_MAX, &input_is_ok);
        config.confidence_threshold = get_param_check(storage,AWB_IN_CONFIDENCE_THRESHOLD, &input_is_ok);
        config.points[0].rg = get_param_check(storage,AWB_IN_TEMP_CALIB_COLD_RG, &input_is_ok);
        config.points[0].bg = get_param_check(storage,AWB_IN_TEMP_CALIB_COLD_BG, &input_is_ok);
        config.points[1].rg = get_param_check(storage,AWB_IN_TEMP_CALIB_WARM_RG, &input_is_ok);
        config.points[1].bg = get_param_check(storage,AWB_IN_TEMP_CALIB_WARM_BG, &input_is_ok);
        config.dist_threshold = get_param_check(storage,AWB_IN_HULL_DIST_THRESH, &input_is_ok);
        config.q6 = get_param_check(storage,AWB_IN_Q6, &input_is_ok);
        float32_t prev_R  = get_param_check(storage,AWB_OUT_R, &input_is_ok);
        float32_t prev_G  = get_param_check(storage,AWB_OUT_G, &input_is_ok);
        float32_t prev_B  = get_param_check(storage,AWB_OUT_B, &input_is_ok);
        float32_t temp_nonclamp = get_param_check(storage,AWB_OUT_TEMP_NONCLAMP, &input_is_ok);
        float32_t tint_nonclamp = get_param_check(storage,AWB_OUT_TINT_NONCLAMP, &input_is_ok);
        config.prev_inv_temp = get_param_check(storage,AWB_OUT_PREV_INV_TEMP, &input_is_ok);
        config.prev_tint = get_param_check(storage,AWB_OUT_PREV_TINT, &input_is_ok);
        process_gw_stats(storage, &config, gains_from_sensor, gains_from_sensor_prev, camera_num);

        awb_tables_t tables = {0};

        const ae_auto_params_table_t* planck_temp_table = find_table_by_id(context->adjust_tables, TABLES_AWB_PLANCK_TEMP_TABLE);
        const ae_auto_params_table_t* planck_lrg_table = find_table_by_id(context->adjust_tables, TABLES_AWB_PLANCK_LRG_TABLE);
        const ae_auto_params_table_t* planck_lbg_table = find_table_by_id(context->adjust_tables, TABLES_AWB_PLANCK_LBG_TABLE);
        const ae_auto_params_table_t* gray_hull_temp = find_table_by_id(context->adjust_tables, TABLES_AWB_GRAY_HULL_TEMP);
        const ae_auto_params_table_t* gray_hull_tint = find_table_by_id(context->adjust_tables, TABLES_AWB_GRAY_HULL_TINT);

        uint32_t plank_len = planck_lbg_table->table_size;
        uint32_t gray_hull_len = gray_hull_temp->table_size;

        if (planck_temp_table == NULL
            || planck_lrg_table == NULL
            || planck_lbg_table == NULL
            || gray_hull_temp == NULL
            || gray_hull_tint == NULL
            )
        {
            isp_tracelog_e("ERROR awb lut is not found\n");
            input_is_ok = false;
        }

        if (input_is_ok)
        {
            if (plank_len != planck_temp_table->table_size
                || plank_len != planck_lrg_table->table_size
                || gray_hull_len != gray_hull_tint->table_size
                )
            {
                isp_tracelog_e("ERROR awb lut has a wrong size\n");
                input_is_ok = false;
            }
        }

        tables.planck_len = plank_len;
        tables.gray_hull_len = gray_hull_len;

        tables.planck_temp_table = planck_temp_table->out;
        tables.planck_lrg_table = planck_lrg_table->out;
        tables.planck_lbg_table = planck_lbg_table->out;
        tables.gray_hull_temp = gray_hull_temp->out;
        tables.gray_hull_tint = gray_hull_tint->out;

        if (input_is_ok)
        {
            {
                awb_statistics_t awb_stat = {0};
                awb_stat.blocks = &stats->awb_stat[0];
                copy_vec3(gains_from_sensor, config.static_gains);
                copy_vec3(gains_from_sensor, awb_stat.gains_from_sensor);
                copy_vec3(gains_from_sensor_prev, awb_stat.gains_used_for_stat);
                isp_tracelog_v("input sensor gains: prev: %f %f %f cur: %f %f %f\n",
                awb_stat.gains_used_for_stat[RED], awb_stat.gains_used_for_stat[GREEN], awb_stat.gains_used_for_stat[BLUE],
                awb_stat.gains_from_sensor[RED], awb_stat.gains_from_sensor[GREEN], awb_stat.gains_from_sensor[BLUE]);

                float32_t out[MAX_CHANNELS] = {0.0f, 0.0f, 0.0f};
                float32_t out2[MAX_CHANNELS] = {0.0f, 0.0f, 0.0f};
                uint32_t awb_valid_blocks = 0;

                if (awb_process(&context->awb_context, &config, &awb_stat, &tables, out, out2, &awb_valid_blocks,
                                &temp_nonclamp, &tint_nonclamp,
                                &config.prev_inv_temp, &config.prev_tint) == 0)
                {
                    set_param(storage, AWB_SKIP_COUNTER, 0);

                    if ((out[BLUE] > 0.0f) && (out[RED] > 0.0f) && (out[GREEN] > 0.0f))
                    {
                        ret = 1.f;
                        const float32_t epsilon = 0.01;
                        float32_t min_awb_gain = ISP_MIN(ISP_MIN(out[RED], out[BLUE]), out[GREEN]);
                        out[RED] /= min_awb_gain;
                        out[GREEN] /= min_awb_gain;
                        out[BLUE] /= min_awb_gain;

                        min_awb_gain = ISP_MIN(ISP_MIN(out2[RED], out2[BLUE]), out2[GREEN]);
                        out2[RED] /= min_awb_gain;
                        out2[GREEN] /= min_awb_gain;
                        out2[BLUE] /= min_awb_gain;
                        isp_tracelog_v("out wb gains: sensor: %f %f %f ccm: %f %f %f\n",
                        out[RED], out[GREEN], out[BLUE],
                        out2[RED], out2[GREEN], out2[BLUE]);

                        {
                            set_param_if_empty(storage, ISP_INTERNAL_AWB_R_SENSOR, out[RED]);
                            set_param_if_empty(storage, ISP_INTERNAL_AWB_G_SENSOR, out[GREEN]);
                            set_param_if_empty(storage, ISP_INTERNAL_AWB_B_SENSOR, out[BLUE]);
                        }

                        float32_t send_value = out2[RED];
                        if (fabs(send_value - prev_R) > epsilon)
                        {
                            set_param_if_empty(storage, ISP_INTERNAL_AWB_R, send_value);
                        }

                        send_value = out2[GREEN];
                        if (fabs(send_value - prev_G) > epsilon)
                        {
                            set_param_if_empty(storage, ISP_INTERNAL_AWB_G, send_value);
                        }

                        send_value = out2[BLUE];
                        if (fabs(send_value - prev_B) > epsilon)
                        {
                            set_param_if_empty(storage, ISP_INTERNAL_AWB_B, send_value);
                        }
                    }
                }
                else
                {
                    isp_tracelog_e("AWB failure\n");
                }

                set_param(storage, AWB_VALID_BLOCKS, awb_valid_blocks);
                set_param(storage, AWB_OUT_TEMP_NONCLAMP, temp_nonclamp);
                set_param(storage, AWB_OUT_TINT_NONCLAMP, tint_nonclamp);
                set_param(storage, AWB_OUT_PREV_INV_TEMP, config.prev_inv_temp);
                set_param(storage, AWB_OUT_PREV_TINT, config.prev_tint);
            }
        }
    }

    PROF_END(AWB_run);

    return ret;
}

/* PRQA S 0604 -- */
/* PRQA S 0781 -- */
/* PRQA S 1056 -- */
