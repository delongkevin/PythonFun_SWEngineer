/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           def_cfg.c
 *  @brief          Functions for setup default config
 *
 *  @version        2.52
 *  @author         Mikhail Vakhrushev & Alexander Ronzhin
 *  @date           23.09.2019
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

#include "isp_process.h"

#define _A (const float32_t[]) /* PRQA S 0602 */

//cat isp.cfg | grep TABLE | sed -E "s/TABLE\s+/    TABLE(/" | sed -E "s/([^0-9])\./\1__/g" | sed -E "s/\[/\(_A{/g" | sed -E "s/\]/}\)/g" | sed "s/$/)/" > l.txt
//cat isp.cfg | grep -v TABLE | sed -E "s/(^.*)/    t.\1;/" | sed -E "s/(caFiltLutCfg.pEntry\[[^]]+\])(.*)/\1.Coeff\2/" >> l.txt
/* PRQA S 3436 ++ */
/* PRQA S 3410 ++ */
#define TABLE(NAME, _IN, _OUT, INTERP, PH, ARR_IN, ARR_OUT)      \
{                                                                \
    static const float32_t NAME##_IN##_OUT##_in[] = ARR_IN;      \
    static const float32_t NAME##_IN##_OUT##_out[] = ARR_OUT;    \
        const ae_auto_params_table_t t = {                       \
            .control = _OUT,                                     \
            .interp_type = INTERP,                               \
            .input = _IN,                                        \
            .out = NAME##_IN##_OUT##_out,                        \
            .in = NAME##_IN##_OUT##_in,                          \
            .table_size = sizeof(ARR_IN) / 4,                    \
            .freq = 1,                                           \
            .phase = PH,                                         \
            .name = STRINGIFY(NAME),                             \
            .enable = 1,                                         \
        };                                                       \
        add_tuning_table(&t);                                    \
} /* PRQA S 3458 */ /* PRQA S 0881 */ /* PRQA S 0342 */
 /* PRQA S 3436 -- */
 /* PRQA S 3410 -- */
enum  ISP_CFA{
    CFA_B_GB_GR_R = 27,
    CFA_B_GB_R_GR = 30,
    CFA_B_GR_GB_R = 39,
    CFA_B_GR_R_GB = 45,
    CFA_B_R_GB_GR = 54,
    CFA_B_R_GR_GB = 57,
    CFA_GB_B_GR_R = 75,
    CFA_GB_B_R_GR = 78,
    CFA_GB_GR_B_R = 99,
    CFA_GB_GR_R_B = 108,
    CFA_GB_R_B_GR = 114,
    CFA_GB_R_GR_B = 120,
    CFA_GR_B_GB_R = 135,
    CFA_GR_B_R_GB = 141,
    CFA_GR_GB_B_R = 147,
    CFA_GR_GB_R_B = 156,
    CFA_GR_R_GB_B = 180,
    CFA_GR_R_B_GB = 177,
    CFA_R_B_GB_GR = 198,
    CFA_R_B_GR_GB = 201,
    CFA_R_GB_GR_B = 216,
    CFA_R_GB_B_GR = 210,
    CFA_R_GR_GB_B = 228,
    CFA_R_GR_B_GB = 225,
} ;
void set_default_isp_233(uint32_t cam_num, struct ISP_config *ispConfig)
{
    if (cam_num < MAX_CAMERAS_NUM)
    {
        parameters_storage_t* s = get_parameters_storage(cam_num);
        set_param(s, CFG_VERSION, 414);
        set_param(s, ALG_SENSOR_TYPE, 233);
        set_param(s, ALG_SIXTY_HERTZ, 0);
        set_param(s, ALG_CCM_MAT_0_0, 1.9509f);
        set_param(s, ALG_CCM_MAT_0_1, -0.4965f);
        set_param(s, ALG_CCM_MAT_0_2, -0.4543f);
        set_param(s, ALG_CCM_MAT_1_0, -0.6315f);
        set_param(s, ALG_CCM_MAT_1_1, 2.0529f);
        set_param(s, ALG_CCM_MAT_1_2, -0.4214f);
        set_param(s, ALG_CCM_MAT_2_0, -0.0800f);
        set_param(s, ALG_CCM_MAT_2_1, -0.7027f);
        set_param(s, ALG_CCM_MAT_2_2, 1.7826f);
        set_param(s, AE_IN_NIGHT_TARGET, 0.05);
        set_param(s, AE_IN_MODE_THRESHOLD, 0.1);
        set_param(s, AE_IN_MIN_EXP_DM, 200.0);
        set_param(s, AE_IN_MAX_EXP_DM, 1023.0);
        set_param(s, AE_IN_MIN_EXP_NM, 1023.0);
        set_param(s, AE_IN_MAX_EXP_NM, 1800.0);
        set_param(s, AE_IN_MIN_GAIN_DM, 512.0);
        set_param(s, AE_IN_MAX_GAIN_DM, 1024.0);
        set_param(s, AE_IN_MIN_GAIN_NM, 512.0);
        set_param(s, AE_IN_MAX_GAIN_NM, 1024.0);
        set_param(s, AE_IN_DEF_GAIN, 512);
        set_param(s, AE_IN_SPEED, 0.4);
        set_param(s, AE_IN_MODE, 1);
        set_param(s, AE_IN_DARK_EXP, 300);
        set_param(s, AE_IN_DAY_TARGET_DELTA, 0.04);
        set_param(s, SENSOR_BLACK_LEVEL_DEFAULT, 168.f);
        set_param(s, SENSOR_LONG_EXPOSURE_THRESHOLD, 2047.f);
        set_param(s, AE_TEST_FORCE_NM_L, 2);
        set_param(s, AE_TEST_FORCE_NM_G, 2);
        set_param(s, TARGET_AVE_BR, 0.00390625f);
        set_param(s, AWB_IN_MODE, 1);
        set_param(s, AWB_IN_PIX_COUNT_THRESHOLD, 92.0);
        set_param(s, AWB_IN_MIN_VALID_BLOCKS_RATIO, 0.05);
        set_param(s, AWB_IN_QDA_WEIGHT_0, 0.5);
        set_param(s, AWB_IN_QDA_WEIGHT_1, 0.6);
        set_param(s, AWB_IN_QDA_WEIGHT_2, 250.0);
        set_param(s, AWB_IN_QDA_WEIGHT_3, 100.0);
        set_param(s, AWB_IN_QDA_WEIGHT_4, 20.0);
        set_param(s, AWB_IN_CFA_PATTERN, CFA_GR_R_B_GB);
        set_param(s, AWB_IN_TEMPERATURES_0, 6500.0);
        set_param(s, AWB_IN_TEMPERATURES_1, 3000.0);
        set_param(s, AWB_IN_TEMP_RANGE_MIN, 1700.0);
        set_param(s, AWB_IN_TEMP_RANGE_MAX, 25000.0);
        set_param(s, AWB_IN_TINT_RANGE_MIN, -0.15);
        set_param(s, AWB_IN_TINT_RANGE_MAX, 0.15);
        set_param(s, AWB_IN_TEMP_CALIB_COLD_RG, 0.6991);
        set_param(s, AWB_IN_TEMP_CALIB_COLD_BG, 0.7324);
        set_param(s, AWB_IN_TEMP_CALIB_WARM_RG, 1.0927);
        set_param(s, AWB_IN_TEMP_CALIB_WARM_BG, 0.4069);
        set_param(s, AWB_IN_GW_MODEL_VAL_0, 2.4882734484702356);
        set_param(s, AWB_IN_GW_MODEL_VAL_1, -0.7407727852288493);
        set_param(s, AWB_IN_GW_MODEL_VAL_2, -3.2746592791308218);
        set_param(s, AWB_IN_GW_MODEL_VAL_3, 0.19236526906911444);
        set_param(s, AWB_IN_CONFIDENCE_THRESHOLD, 0.001);
        set_param(s, AWB_IN_TINT_RESULT_RANGE_MIN, -0.055);
        set_param(s, AWB_IN_TINT_RESULT_RANGE_MAX, 0.055);
        set_param(s, DBLC_CONFIG_ON, 61709);
        set_param(s, DBLC_CONFIG_OFF, 269);
        set_param(s, ALG_FRAME_DUMP_INIT_DELAY, 100);
        set_param(s, ALG_FRAME_DUMP_AMOUNT, 3);
        set_param(s, ALG_FRAME_DUMP_FREQUENCY, 0);
        set_param(s, PINK_SUN_COMPENSATE_IN_ENABLED, 0);
        set_param(s, AGAIN_CONTROL_IN_ENABLED, 0);
        set_param(s, PREHDRGAIN_CONTROL_IN_ENABLED, 0);
        set_param(s, AG_ENABLE, 1);
        set_param(s, AE_RED_GAIN, 1.4215);
        set_param(s, AE_GREEN_GAIN, 1);
        set_param(s, AE_BLUE_GAIN, 1.3895);
        set_param(s, SAT_SHARP_OFFSET, 3.0);
        set_param(s, SAT_SHARP_SLOPE, 40.0);
        set_param(s, SINTER_IN_ENABLED, 0.f);
        set_param(s, SHARPNESS_IN_ENABLED, 0.f);
        set_param(s, SENSOR_IN_DELAY_NM, 2.f);
        set_param(s, SENSOR_IN_DELAY_DM, 3.f);
        set_param(s, ISPGAIN_CONTROL_IN_MAX_GAIN, 31.f);
        set_param(s, GAIN_IN_GAMMA, 0.8f);
        set_param(s, STATISTIC_IN_GAMMA, 0.8f * 0.625f);

        set_param(s, ROI_X_VAL, 128.0);
        set_param(s, ROI_Y_VAL, 96.0);
        set_param(s, ROI_WIDTH_VAL, 1664.0);
        set_param(s, ROI_HEIGHT_VAL, 1056.0);
    }

    struct ISP_config t = *ispConfig; /* PRQA S 2814 */ /* PRQA S 0604 */ /* PRQA S 1031 */
    TABLE(T_A_GAIN_BR, ISP_INTERNAL_AVE_BR, TABLES_ANALOG_GAIN_FROM_BR, INTERP_LINEAR_CLAMP, 1, (_A{0.017, 0.026, 0.033, 0.043, 0.05}), (_A{13,12,11, 10, 7}))
    TABLE(T_A_GAIN_BR, ISP_INTERNAL_AVE_BR, TABLES_ANALOG_GAIN_FROM_BR_PHASE, INTERP_LINEAR_CLAMP, 1, (_A{0.017, 0.026, 0.033, 0.043, 0.05}), (_A{5, 4, 3, 2, 1}))
    TABLE(T_A_GAIN_COMP, ISP_INTERNAL_NULL, TABLES_ANALOG_GAIN_COMP, INTERP_LINEAR_CLAMP, 4, (_A{5,7}), (_A{1.0, 0.5}))
    TABLE(T_AF, ISP_INTERNAL_NULL, TABLES_AF_50hz, INTERP_NEAREST, 4, (_A{0, 1, 2, 3, 4}), (_A{206, 413, 825, 1238, 1650}))
    TABLE(T_AF, ISP_INTERNAL_NULL, TABLES_AF_60hz, INTERP_NEAREST, 4, (_A{0, 1, 2, 3, 4, 5}), (_A{206, 344, 687, 1031, 1375, 1719}))
    TABLE(TABLES_AWB, ISP_INTERNAL_NULL, TABLES_AWB_PLANCK_TEMP_TABLE, INTERP_NEAREST, 4, (_A{0,1}), (_A{0.0400, 0.625}))
    TABLE(TABLES_AWB, ISP_INTERNAL_NULL, TABLES_AWB_PLANCK_LRG_TABLE, INTERP_NEAREST, 4, (_A{0,1}), (_A{-0.6443, 0.7086}))
    TABLE(TABLES_AWB, ISP_INTERNAL_NULL, TABLES_AWB_PLANCK_LBG_TABLE, INTERP_NEAREST, 4, (_A{0,1}), (_A{0.0440, -1.9697}))
    TABLE(TABLES_AWB, ISP_INTERNAL_NULL, TABLES_AWB_GRAY_HULL_TEMP, INTERP_NEAREST, 4, (_A{0,1,2,3,4,5,6,7}), (_A{0.2482, 0.4928, 0.3479, 0.0996, 0.0196, 0.0196, 0.0617, 0.2482}))
    TABLE(TABLES_AWB, ISP_INTERNAL_NULL, TABLES_AWB_GRAY_HULL_TINT, INTERP_NEAREST, 4, (_A{0,1,2,3,4,5,6,7}), (_A{-0.1550, -0.0699,  0.0511,  0.1500,  0.1500,  0.0601,  0.0098, -0.1550}))
    TABLE(TABLES_CCM, ISP_INTERNAL_NULL, TABLES_ANR_TEMP_TABLE, INTERP_NEAREST, 4, (_A{0,1,2,3,4}), (_A{2500, 3400, 4500, 6500, 10000}))
    TABLE(TABLES_ANR, ISP_INTERNAL_NULL, TABLES_ANR_TEMP_TABLE, INTERP_NEAREST, 4, (_A{0,1,2,3,4}), (_A{2500, 3400, 4500, 6500, 10000}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, lscCfg__enable, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{1, 0, 0, 0, 0, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, gammaCfg__enable, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{1, 0, 0, 0, 0, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, cfaLut16to12Cfg__enable, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{1, 0, 0, 0, 0, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, fwdPrcpCfg__enable, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{1, 0, 0, 0, 0, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, revPrcpCfg__enable, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{1, 0, 0, 0, 0, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, eeCfg__yeeEThr, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{200, 1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, glbceCfg__irStrength, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{255, 0, 0, 0, 0, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, SENSOR_EXPOSURE, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{512, 512, 512, 512, 512, 512, 512, 512, 512}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, TPG_PART1, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{0, 1, 1, 1, 1, 1, 2, 3, 256}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, TPG_PART2, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{0, 3157, 3157, 3157, 3157, 3157, 3157, 3157, 3157}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, TEST_DATA_R, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{0, 4000, 0, 4000, 0, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, TEST_DATA_GR, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{0, 4000, 0, 0, 4000, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, TEST_DATA_B, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{0, 4000, 0, 0, 0, 4000, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, TEST_DATA_GB, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{0, 4000, 0, 0, 4000, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, AGAIN_COMPENSATE_IN_ENABLED, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{1, 0, 0, 0, 0, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, ISPGAIN_CONTROL_IN_ENABLED, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{1, 0, 0, 0, 0, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, DISABLE_CCM, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{0, 1, 1, 1, 1, 1, 1, 1, 1}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, AE_IN_ENABLED, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{1, 0, 0, 0, 0, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, AWB_IN_ENABLED, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{1, 0, 0, 0, 0, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, DBLC_CONTROL_IN_ENABLED, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{1, 0, 0, 0, 0, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, SENSOR_DBLC_CONFIG, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{0, 268, 268, 268, 268, 268, 268, 268, 268}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, AWB_IN_ENABLED, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{1, 0, 0, 0, 0, 0, 0, 0, 0}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, AE_TEST_FORCE_NM_L, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{0, 2, 2, 2, 2, 2, 2, 2, 2}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, AE_TEST_FORCE_NM_G, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{2, 2, 2, 2, 2, 2, 2, 2, 2}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, AE_ANALOG_GAIN, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{5, 5, 5, 5, 5, 5, 5, 5, 5}))
    TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, dgCfg__Gain, INTERP_NEAREST, 0, (_A{0, 1, 2, 3, 4, 5, 6, 7, 8}), (_A{0, 256, 256, 256, 256, 256, 256, 256, 256}))
    // TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, decomp3Cfg__enable, INTERP_NEAREST, 0, (_A{0, 1}), (_A{1, 0}))
    //TABLE(T_TPG, ISP_INTERNAL_TPG_VAL, nsf4Cfg_tnScale_0, INTERP_NEAREST, 0, (_A{0, 1}), (_A{1, 0}))
    TABLE(T_MVMODE, ISP_INTERNAL_MVMODE_VAL, SHARPNESS_IN_ENABLED, INTERP_NEAREST, 0, (_A{0, 1}), (_A{1, 0}))
    TABLE(T_TEST, ISP_INTERNAL_TESTMODE_VAL, AE_EXPOSURE, INTERP_NEAREST, 0, (_A{0, 1, 2}), (_A{180, 180, 720}))
    TABLE(T_TEST, ISP_INTERNAL_TESTMODE_VAL, SENSOR_VIRTUAL_GAIN_T1, INTERP_NEAREST, 0, (_A{0, 1, 2}), (_A{8, 2, 2}))

    *ispConfig = t;
}
