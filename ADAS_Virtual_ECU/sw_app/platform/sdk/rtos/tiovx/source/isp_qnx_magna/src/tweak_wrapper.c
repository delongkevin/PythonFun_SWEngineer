#include "tweak_wrapper.h"
#ifdef USE_TWEAK

#include <tweak2/tweak2.h>
#include <tweak2/log.h>

static tweak_id tweak_add_slider_flt_int(const char* str, float32_t minv, float32_t maxv, float32_t def, uint32_t precision);
void tweak_on_update_v2(tweak_id id, void* cookie);

#endif

tweak_context_t g_tweak_context = {0};


#define default_red_gain 181
#define default_green_gain 128
#define default_blue_gain 287

uint32_t MAKE_TYPE(PARAM_TYPE type, uint32_t sz_or_sign, uint32_t frac)
{
    return (sz_or_sign << 12) | (frac << 4) | (uint32_t)type;
}

#define MT_U(X,Y) MAKE_TYPE(TYPE_U, X, Y)  /* PRQA S 3453 */
#define MT_S(X,Y) MAKE_TYPE(TYPE_S, X, Y)  /* PRQA S 3453 */
#define MT_M(X,Y) MAKE_TYPE(TYPE_M, X, Y)  /* PRQA S 3453 */
#define MT_AUTO 0

static const tweak_table_ui16_t tw_tab_233_ui16[] = {
    {{0}, "Exposure",                 0x3012, 0, 0, 2047,    600 },
    {{0}, "Green1Gain",               0x3056, 0, 0, 2047, default_green_gain },
    {{0}, "BlueGain",                 0x3058, 0, 0, 2047, default_blue_gain },
    {{0}, "RedGain",                  0x305A, 0, 0, 2047, default_red_gain },
    {{0}, "Green2Gain",               0x305C, 0, 0, 2047, default_green_gain },
    {{0}, "PostDLO_Gain",             0x3308, 0, 0, 2047, 1*512 },
    {{0}, "HDR_Bypass",               0x3110, 0, 0, 2047, 17},
    {{0}, "DC_GAIN",                  0x3362, 0, 0, 65535, 0x0D02},
    {{0}, "AnalogGain",               0x3366, 0, 0, 65535, 0xDE79 }
};

void tweak_context_init(tweak_context_t* p, tweak_table_isp_create_t create_table_func, ae_auto_tables_t* tables)
{
    p->create_table_func = create_table_func;
    p->common_isp_auto_tables = tables;
    p->table_sensor = tw_tab_233_ui16;
    p->table_sensor_sz = sizeof(tw_tab_233_ui16) / sizeof(tw_tab_233_ui16[0]);

    tweak_table_isp_t* tw_tab_isp = p->table_isp;

    size_t i = 0;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_DPCOTF_CFG, "Enable ISP blocks", "dpc__Enable", dpcOtfCfg__enable, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_LSC_CFG, "Enable ISP blocks", "lsc__Enable", lscCfg__enable, 0,0,0); i++;
    // tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_TONEMAPGAIN_CFG, "Enable ISP blocks", "toneMapGainCfg__Enable", toneMapGainCfg__Enable, 0,0,0); i++;
    // tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_GAMMABE0_CFG, "Enable ISP blocks", "gammaBe0Cfg__Enable", gammaBe0Cfg__Enable, 0,0,0); i++;
    // tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_GAMMABE1_CFG, "Enable ISP blocks", "gammaBe1Cfg__Enable", gammaBe1Cfg__Enable, 0,0,0); i++;
    // tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_GAMMA_CFG, "Enable ISP blocks", "gammaCfg__Enable", gammaCfg__Enable, 0,0,0); i++;
    // tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_GAMMADL_CFG, "Enable ISP blocks", "gammaDlCfg__Enable", gammaDlCfg__Enable, 0,0,0); i++;
    // tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_INVGAMMADL_CFG, "Enable ISP blocks", "invGammaDlCfg__Enable", invGammaDlCfg__Enable, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_GAMMA_CFG, "Enable ISP blocks", "gammaCfg__enable",gammaCfg__enable, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_CFALUT16TO12_CFG, "Enable ISP blocks", "cfaLut16to12Cfg__enable",cfaLut16to12Cfg__enable, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_TONEMAPPREGAMMALUT_CFG, "Enable ISP blocks", "fwdPrcpCfg__enable",fwdPrcpCfg__enable, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_TONEMAPPOSTGAMMALUT_CFG, "Enable ISP blocks", "revPrcpCfg__enable",revPrcpCfg__enable, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_DECOMP3_CFG, "Enable ISP blocks", "decomp3Cfg__enable", decomp3Cfg__enable, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_PWL3_CFG, "Enable ISP blocks", "pwlCfg3__enable", pwlCfg3__enable, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_EE_CFG, "Enable ISP blocks", "eeCfg__enable", eeCfg__enable, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_NSF4_CFG, "Enable ISP blocks", "nsf4Cfg__lsccCfg__enable", nsf4Cfg__lsccCfg__enable, 0,0,0); i++;
    // tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_RAWFE_CFG, "Enable ISP blocks", "rawFeCfg__Enable", rawFeCfg__Enable, 0,0,0); i++;
    // tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_SINTER_CFG, "Enable ISP blocks", "sinterCfg__Enable", sinterCfg__Enable, 0,0,0); i++;
    // tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_SINTERRS_CFG, "Enable ISP blocks", "sinterRsCfg__Enable", sinterRsCfg__Enable, 0,0,0); i++;
    // tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_TONEMAP_CFG, "Enable ISP blocks", "toneMapCfg__Enable", toneMapCfg__Enable, 0,0,0); i++;
    // tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_DEM_CFG, "Enable ISP blocks", "demCfg_ENABLE", demCfg__Enable, 0,0,0); i++;
    // tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_DEM_CFG, "Enable ISP blocks", "demCfg_ENABLE", demCfg__Enable, 0,0,0); i++;
    // tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_WB_CFG, "Enable ISP blocks", "wbCfg_ENABLE", wbCfg__Enable, 0,0,0); i++;
    // tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,  1     ,0,FLAG_ISP_OUTFORM_CFG, "Enable ISP blocks", "gamma_lut", outFormCfg__HSRGBYUV__LUT__Enable, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO   ,0,4    ,0,FLAG_ISP_NSF4_CFG, "NSF4", "nsf4Cfg__lsccCfg__setSel", (uint32_t)nsf4Cfg__lsccCfg__setSel, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(9, 5)   ,0,511.9    ,0,FLAG_ISP_NSF4_CFG, "NSF4", "nsf4Cfg__lsccCfg__gMaxCfg", (uint32_t)nsf4Cfg__lsccCfg__gMaxCfg, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(4, 0)   ,0,16    ,0,FLAG_ISP_NSF4_CFG, "NSF4", "nsf4Cfg__lsccCfg__tCfg", (uint32_t)nsf4Cfg__lsccCfg__tCfg, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(8, 6)   ,0,255.9    ,0,FLAG_ISP_NSF4_CFG, "NSF4", "nsf4Cfg__lsccCfg__khCfg", (uint32_t)nsf4Cfg__lsccCfg__khCfg, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(8, 6)   ,0,255.9    ,0,FLAG_ISP_NSF4_CFG, "NSF4", "nsf4Cfg__lsccCfg__kvCfg", (uint32_t)nsf4Cfg__lsccCfg__kvCfg, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_S(14, 0)   ,-8192,8191    ,0,FLAG_ISP_NSF4_CFG, "NSF4", "nsf4Cfg__lsccCfg__lensCenterX", (uint32_t)nsf4Cfg__lsccCfg__lensCenterX, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_S(14, 0)   ,-8192,8191    ,0,FLAG_ISP_NSF4_CFG, "NSF4", "nsf4Cfg__lsccCfg__lensCenterY", (uint32_t)nsf4Cfg__lsccCfg__lensCenterY, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(8, 5)   ,0,7.9    ,2,FLAG_ISP_NSF4_CFG, "NSF4", "nsf4Cfg__tnScale_0", (uint32_t)nsf4Cfg__tnScale_0, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(8, 5)   ,0,7.9    ,2,FLAG_ISP_NSF4_CFG, "NSF4", "nsf4Cfg__tnScale_1", (uint32_t)nsf4Cfg__tnScale_1, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(8, 5)   ,0,7.9    ,2,FLAG_ISP_NSF4_CFG, "NSF4", "nsf4Cfg__tnScale_2", (uint32_t)nsf4Cfg__tnScale_2, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(0, 6)   ,0,0.64    ,1,FLAG_ISP_NSF4_CFG, "NSF4", "nsf4Cfg__tKnee", (uint32_t)nsf4Cfg__tKnee, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(13, 9)   ,0,15.9    ,1,FLAG_ISP_NSF4_CFG, "NSF4", "nsf4Cfg__gains", (uint32_t)nsf4Cfg__gains, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_S(32, 0)   ,-65535,65535  ,0,FLAG_ISP_PWL3_CFG, "PWL3", "pwlCfg3__offset", (uint32_t)pwlCfg3__offset, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(13, 9)   ,0,15.9    ,0,FLAG_ISP_NSF4_CFG, "NSF4", "dgCfg__Gain", (uint32_t)dgCfg__Gain, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(10, 0)   ,0,1023    ,0,FLAG_ISP_EE_CFG, "EE", "eeCfg__yeeEThr", (uint32_t)eeCfg__yeeEThr, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(8, 6)   ,0,3.9    ,0,FLAG_ISP_EE_CFG, "EE", "eeCfg__yesGGain", (uint32_t)eeCfg__yesGGain, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(12, 6)   ,0,63.9    ,0,FLAG_ISP_EE_CFG, "EE", "eeCfg__yesEGain", (uint32_t)eeCfg__yesEGain, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(16, 6)   ,0,1023.9    ,0,FLAG_ISP_EE_CFG, "EE", "eeCfg__yesEThr1", (uint32_t)eeCfg__yesEThr1, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(10, 0)   ,0,1023    ,0,FLAG_ISP_EE_CFG, "EE", "eeCfg__yesEThr2", (uint32_t)eeCfg__yesEThr2, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_U(10, 0)   ,0,1023    ,0,FLAG_ISP_EE_CFG, "EE", "eeCfg__yesGOfset", (uint32_t)eeCfg__yesGOfset, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,65535  ,0,FLAG_ISP_TONEMAP_CFG, "TONEMAP_CFG", "glbceCfg__blackLevel", (uint32_t)glbceCfg__blackLevel, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,15     ,0,FLAG_ISP_TONEMAP_CFG, "TONEMAP_CFG", "glbceCfg__brightAmplLimit", (uint32_t)glbceCfg__brightAmplLimit, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,15     ,0,FLAG_ISP_TONEMAP_CFG, "TONEMAP_CFG", "glbceCfg__intensityVariance", (uint32_t)glbceCfg__intensityVariance, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,15   ,0,FLAG_ISP_TONEMAP_CFG, "TONEMAP_CFG", "glbceCfg__darkAmplLimit", (uint32_t)glbceCfg__darkAmplLimit, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,1     ,0,FLAG_ISP_TONEMAP_CFG, "TONEMAP_CFG", "glbceCfg__dither", (uint32_t)glbceCfg__dither, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,255     ,0,FLAG_ISP_TONEMAP_CFG, "TONEMAP_CFG", "glbceCfg__irStrength", (uint32_t)glbceCfg__irStrength, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,255     ,0,FLAG_ISP_TONEMAP_CFG, "TONEMAP_CFG", "glbceCfg__maxSlopeLimit", (uint32_t)glbceCfg__maxSlopeLimit, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,255     ,0,FLAG_ISP_TONEMAP_CFG, "TONEMAP_CFG", "glbceCfg__minSlopeLimit", (uint32_t)glbceCfg__minSlopeLimit, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,15     ,0,FLAG_ISP_TONEMAP_CFG, "TONEMAP_CFG", "glbceCfg__spaceVariance", (uint32_t)glbceCfg__spaceVariance, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,65535,0,FLAG_ISP_TONEMAP_CFG, "TONEMAP_CFG", "glbceCfg__whiteLevel", (uint32_t)glbceCfg__whiteLevel, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,255,0,0, "TONEMAP_CFG", "LTM_CONTROL_CURVE_SLOPE", (uint32_t)LTM_CONTROL_CURVE_SLOPE, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,65535,0,FLAG_ISP_WB_CFG, "TONEMAP_CFG", "wbCfg__offset", (uint32_t)wbCfg__offset, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO       ,0,65535,0,0, "TONEMAP_CFG", "black_level_residue", (uint32_t)BLACK_LEVEL_RESIDUE, 0,0,0); i++;


    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 255 ,0,0, "log_settings",   "alg_log_level",  ALG_LOG_LEVEL, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,0,0, "log_settings",   "alg_log_EMB",  ALG_LOG_EMB, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,0,0, "log_settings",   "alg_log_regs",  ALG_LOG_REGS, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 7 ,0,0, "log_settings",   "alg_log_stats",  ALG_LOG_STATS, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 255 ,0,0, "log_settings",   "TEST_NUM",  ALG_LOG_TEST_NUM, 0,0,0); i++;

    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 255 ,0,0, "log_settings",   "alg_dump_statistic",  ALG_DUMP_STATISTIC, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 255 ,0,0, "log_settings",   "alg_log_cam",  ALG_LOG_CAM, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,0,0, "log_settings",   "TOOLS_DUMP_SETTINGS",  TOOLS_DUMP_SETTINGS, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,0,0, "ALGORITHMS",   "ae_in_experemental_mode",  AE_IN_MODE, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 2 ,2,0, "ALGORITHMS",   "ae_in_mode_threshold",  AE_IN_MODE_THRESHOLD, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 2 ,2,0, "ALGORITHMS",   "ae_in_target_light",  AE_IN_TARGET_LIGHT, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 2 ,2,0, "ALGORITHMS",   "ae_in_target_indoor",  AE_IN_TARGET_INDOOR, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 2 ,2,0, "ALGORITHMS",   "ae_in_target_br_light",  AE_IN_TARGET_BR_LIGHT, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 2 ,2,0, "ALGORITHMS",   "ae_in_target_br_dark",  AE_IN_TARGET_BR_NIGHT, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 2 ,2,0, "ALGORITHMS",   "ae_in_speed",  AE_IN_SPEED, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 2 ,2,0, "ALGORITHMS",   "ae_in_night_target",  AE_IN_NIGHT_TARGET, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 2 ,2,0, "ALGORITHMS",   "ae_in_day_target_delta",  AE_IN_DAY_TARGET_DELTA, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,0,0, "ALGORITHMS",   "awb_mode",  AWB_IN_MODE, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,0,0, "ALGORITHMS",   "AG_ENABLE",  AG_ENABLE, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,0,0, "ALGORITHMS",   "T1_ENABLE",  T1_ENABLE, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,0,0, "ALGORITHMS",   "DISABLE_CCM",  DISABLE_CCM, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 13.0 ,0,0, "ALGORITHMS",   "PRE_HDR_GAIN",  PREHDRGAIN_FORCE, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 4.0 ,0,0, "ALGORITHMS",   "SENSOR_IN_DELAY_DM",  SENSOR_IN_DELAY_DM, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 8.0 ,0,0, "ALGORITHMS",   "TPG_IN_VAL",  TPG_IN_VAL, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 8.0 ,1,0, "ALGORITHMS",   "NR_POWER_COEFF",  NR_POWER_COEFF, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 8.0 ,1,0, "ALGORITHMS",   "NR_RSHARP_COEFF",  NR_RSHARP_COEFF, 0,0,0); i++;

    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,2,0, "ALGORITHMS",   "AWB_IN_SECOND_COMPONENT_THRESHOLD",  AWB_IN_SECOND_COMPONENT_THRESHOLD, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, -1.0, 1 ,3,0, "ALGORITHMS",   "AWB_IN_TINT_RANGE_MIN",  AWB_IN_TINT_RANGE_MIN, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, -1.0, 1 ,3,0, "ALGORITHMS",   "AWB_IN_TINT_RANGE_MAX",  AWB_IN_TINT_RANGE_MAX, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 12000 ,0,0, "ALGORITHMS",   "AWB_IN_TEMP_RESULT_RANGE_MIN",  AWB_IN_TEMP_RESULT_RANGE_MIN, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 12000 ,0,0, "ALGORITHMS",   "AWB_IN_TEMP_RESULT_RANGE_MAX",  AWB_IN_TEMP_RESULT_RANGE_MAX, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, -1.0, 1 ,3,0, "ALGORITHMS",   "AWB_IN_TINT_RESULT_RANGE_MIN",  AWB_IN_TINT_RESULT_RANGE_MIN, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, -1.0, 1 ,3,0, "ALGORITHMS",   "AWB_IN_TINT_RESULT_RANGE_MAX",  AWB_IN_TINT_RESULT_RANGE_MAX, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1000 ,2,0, "ALGORITHMS",   "AWB_IN_QDA_WEIGHT_0",  AWB_IN_QDA_WEIGHT_0, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1000 ,2,0, "ALGORITHMS",   "AWB_IN_QDA_WEIGHT_1",  AWB_IN_QDA_WEIGHT_1, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1000 ,2,0, "ALGORITHMS",   "AWB_IN_QDA_WEIGHT_2",  AWB_IN_QDA_WEIGHT_2, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1000 ,2,0, "ALGORITHMS",   "AWB_IN_QDA_WEIGHT_3",  AWB_IN_QDA_WEIGHT_3, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1000 ,2,0, "ALGORITHMS",   "AWB_IN_QDA_WEIGHT_4",  AWB_IN_QDA_WEIGHT_4, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 3 ,0,0, "ALGORITHMS",   "AE_TEST_FORCE_NM_L",  AE_TEST_FORCE_NM_L, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 3 ,0,0, "ALGORITHMS",   "AE_TEST_FORCE_NM_G",  AE_TEST_FORCE_NM_G, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 3 ,0,0, "ALGORITHMS",   "MODES_TEST_IN_VAL",  MODES_TEST_IN_VAL, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 10, 2047 ,0,0, "ALGORITHMS",   "AE_IN_MIN_EXP_DM",  AE_IN_MIN_EXP_DM, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 16, 2047 ,0,0, "ALGORITHMS",   "AE_EXPOSURE",  AE_EXPOSURE, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,0,0, "ALGORITHMS",   "alg_sixty_hertz_enable",  ALG_SIXTY_HERTZ, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,0,0, "ALGORITHMS",   "SENSOR_WRITE", SENSOR_WRITE, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,4,0, "ALGORITHMS",   "AWB_IN_CONFIDENCE_THRESHOLD",  AWB_IN_CONFIDENCE_THRESHOLD, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,2,0, "ALGORITHMS",   "TARGET_AVE_BR",  TARGET_AVE_BR, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 1000, 65535 ,0,0, "ALGORITHMS",   "SENSOR_LONG_EXPOSURE_THRESHOLD",  SENSOR_LONG_EXPOSURE_THRESHOLD, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 100 ,1,0, "ALGORITHMS",   "SAT_SHARP_OFFSET",  SAT_SHARP_OFFSET, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 4096 ,1,0, "ALGORITHMS",   "SAT_SHARP_SLOPE",  SAT_SHARP_SLOPE, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 100 ,1,0, "ALGORITHMS",   "SAT_TARGET_SNR",  SAT_TARGET_SNR, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1   ,0,0, "ALGORITHMS",   "SAT_ALGO",  SAT_ALGO, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 900 ,0,0, "ALGORITHMS",   "DBLC_PERIOD",  DBLC_PERIOD, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 900 ,0,0, "ALGORITHMS",   "DBLC_FRAMES_THRESHOLD",  DBLC_FRAMES_THRESHOLD, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0.0, 1 ,4,0, "ALGORITHMS",   "LTM_CONTROL_LOW_THRESH",  LTM_CONTROL_LOW_THRESH, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0.0, 1 ,4,0, "ALGORITHMS",   "LTM_CONTROL_HIGH_THRESH",  LTM_CONTROL_HIGH_THRESH, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 255 ,1,0, "ALGORITHMS",   "LTM_CONTROL_LOW_CURVE_SLOPE",  LTM_CONTROL_LOW_CURVE_SLOPE, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 255 ,1,0, "ALGORITHMS",   "LTM_CONTROL_HIGH_CURVE_SLOPE",  LTM_CONTROL_HIGH_CURVE_SLOPE, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 65535 ,0,0, "ALGORITHMS",   "LTM_CONTROL_ART_BLACK_LEVEL",  LTM_CONTROL_ART_BLACK_LEVEL, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,3,0, "ALGORITHMS",   "LTM_CONTROL_BL_SCALE",  LTM_CONTROL_BL_SCALE, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 255 ,0,0, "ALGORITHMS",   "LTM_CONTROL_DEFAULT_MAX_SLOPE",  LTM_CONTROL_DEFAULT_MAX_SLOPE, 0,0,0); i++;
    tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,0,0, "ALGORITHMS",   "LTM_CONTROL_ENABLE_MAX_SLOPE",  LTM_CONTROL_ENABLE_MAX_SLOPE, 0,0,0); i++;





    #define ALGO_IMPL(NAME) tw_tab_isp[i] = create_table_func(MT_AUTO, 0, 1 ,0,0, "ALGORITHMS",   STRINGIFY(NAME##_IN_ENABLED),  NAME##_IN_ENABLED, 0,0,0); i++; /* PRQA S 0842 */

    #include "algo_reg.h"

    if (i > table_isp_max_sz)
    {
        isp_tracelog_e("MEMORY corruption detected\n"); /* PRQA S 2743 */
    }

    p->table_isp_sz = i;
}



void tweak_init(tweak_table_isp_create_t create_table_func, ae_auto_tables_t* tables)
{
    tweak_context_init(&g_tweak_context, create_table_func, tables);
#ifdef USE_TWEAK

    printf("tweak_initialize_library\n");
    tweak_initialize_library("rpmsg", "role=server", "rpmsg://tweak/19");
    tweak_set_item_change_listener(tweak_on_update_v2, NULL);

    uint32_t tw_tab_ui16_sz = g_tweak_context.table_sensor_sz;
    tweak_table_ui16_t* tw_tab_ui16 = g_tweak_context.table_sensor;

    char buf1[256];

    size_t i;
    for (i = 0; i < tw_tab_ui16_sz; i++)
    {
        sprintf(buf1, "/sensor/%s", tw_tab_ui16[i].name);
        tw_tab_ui16[i].tweak_id = tweak_add_slider_flt_int(buf1, tw_tab_ui16[i].minv, tw_tab_ui16[i].maxv, tw_tab_ui16[i].val, 0);
    }

    const char* cur_tab = 0;

    uint32_t tw_tab_isp_sz = g_tweak_context.table_isp_sz;
    tweak_table_isp_t* tw_tab_isp = g_tweak_context.table_isp;

    for (i = 0; i < tw_tab_isp_sz; i++)
    {
        if (i == 0 || strcmp(tw_tab_isp[i].name_tab, tw_tab_isp[i - 1].name_tab) != 0)
        {
            cur_tab = tw_tab_isp[i].name_tab;
        }

        if (i == 0 || tw_tab_isp[i-1].p_next == 0)
        {
            if (tw_tab_isp[i].minv == 0 && tw_tab_isp[i].maxv == 1.f && tw_tab_isp[i].prec == 0)
            {
                sprintf(buf1, "/%s/%s", cur_tab, tw_tab_isp[i].name);
                tw_tab_isp[i].tweak_id = tweak_add_scalar_bool(buf1, "", "{}", tw_tab_isp[i].val > 0.5);
                tw_tab_isp[i].checkbox = true;
            }
            else
            {
                sprintf(buf1, "/%s/%s", cur_tab, tw_tab_isp[i].name);
                tw_tab_isp[i].tweak_id = tweak_add_slider_flt_int(buf1, tw_tab_isp[i].minv, tw_tab_isp[i].maxv, tw_tab_isp[i].val, tw_tab_isp[i].prec);
                tw_tab_isp[i].checkbox = false;
            }
        }
    }

//     tweak_add_widget("tuning_table");
//     tweak_add_layout(400, 0, "tuning_table");

    cur_tab = "tuning_table";
    for (i = 0; i < g_tweak_context.common_isp_auto_tables->ae_auto_table_num; i++)
    {
        const ae_auto_params_table_t* t = &g_tweak_context.common_isp_auto_tables->ae_auto_table[i];

        bool duplicate = false;
        if (i != 0)
        {
            duplicate = strcmp(g_tweak_context.common_isp_auto_tables->ae_auto_table[i-1].name,
                g_tweak_context.common_isp_auto_tables->ae_auto_table[i].name) == 0;
        }

        if (duplicate == false)
        {
            sprintf(buf1, "/%s/%s", cur_tab, t->name);
            g_tweak_context.common_isp_auto_tables_tweak_handle[i] = tweak_add_scalar_bool(buf1, "", "{}", true);
        }
    }

//     tweak_add_widget("tools");
//     tweak_add_layout(400, 0, "tools");

//     tweak_add_checkbox("load_cfg", 0);
//     tweak_add_checkbox("save_cfg", 0);
//     tweak_add_checkbox("load_regs", 0);
//     tweak_add_checkbox("load_wl", 0);
//     tweak_add_checkbox("dump_regs", 0);
//     tweak_add_checkbox("dump_bayer", 0);
//     tweak_add_checkbox("test_dump", 0);

//     tweak_add_widget("API_test");
//     tweak_add_layout(400, 0, "API_test");
//     tweak_add_slider("brightness", -5, 5, 0, 0);
//     tweak_add_slider("contrast", -5, 5, 0, 0);
//     tweak_add_slider("frame_rate", 1, 6, 1, 0);
//     tweak_add_slider("tpg", 0, 1, 0, 0);
//     //tweak_add_slider("test_awb", 0, 1, 1, 0);
//     tweak_add_slider("alg_machine_vision", 0, 1, 0, 0);

//     usleep(5000000);
       g_tweak_context.tweak_established = 1;
#endif
}



#ifdef USE_TWEAK

bool tweak_is_established(void)
{
    return g_tweak_context.tweak_established != 0;
}

tweak_table_isp_t* tweak_get_isp_tables(uint32_t* sz)
{
    if (sz != NULL)
    {
        *sz = g_tweak_context.table_isp_sz;
    }

    return g_tweak_context.table_isp;
}

tweak_table_ui16_t* tweak_get_sensor_tables(uint32_t* sz)
{
    if (sz != NULL)
    {
        *sz = g_tweak_context.table_sensor_sz;
    }

    return g_tweak_context.table_sensor;
}


void tweak_on_update_v2(tweak_id id, void* cookie)
{
    if (!tweak_is_established())
    {
        return;
    }


    uint32_t tw_tab_ui16_sz = 0;
    uint32_t tw_tab_isp_sz = 0;
    tweak_table_ui16_t *tw_tab_ui16 = tweak_get_sensor_tables(&tw_tab_ui16_sz);
    tweak_table_isp_t *tw_tab_isp = tweak_get_isp_tables(&tw_tab_isp_sz);

    uint32_t i;
    for (i = 0; i < tw_tab_ui16_sz; i++)
    {
        if (tw_tab_ui16[i].tweak_id == id)
        {
            float32_t recv_val  = tweak_get_scalar_int32(id);
            tw_tab_ui16[i].val = (uint16_t)recv_val;

            printf("Changes from tweak_tool %s = %d\n", tw_tab_ui16[i].name, (int)recv_val);

            uint32_t cam = 0;

            for (; cam < MAX_CAMERAS_NUM; cam++)
            {
                tw_tab_ui16[i].val_upd[cam] = 1;
            }
            break;
        }
    }


    bool b_next = false;

    for (i = 0; i < tw_tab_isp_sz; i++)
    {
        if (id == tw_tab_isp[i].tweak_id || b_next)
        {
            float32_t recv_val;
            if (tw_tab_isp[i].checkbox)
            {
                bool bval = tweak_get_scalar_bool(id);
                recv_val = bval ? 1.f : 0.f;
                printf("Changes from tweak_tool %s = %df\n", tw_tab_isp[i].name, (int)bval);
            }
            else
            {
                if (tw_tab_isp[i].prec > 0)
                {
                    recv_val = tweak_get_scalar_float(id);
                }
                else
                {
                    recv_val = tweak_get_scalar_int32(id);
                }
            }

            printf("Changes from tweak_tool %s = %.1f\n", tw_tab_isp[i].name, recv_val);
            tw_tab_isp[i].val = recv_val;

            uint32_t cam = 0;

            for (; cam < MAX_CAMERAS_NUM; cam++)
            {
                tw_tab_isp[i].val_upd[cam] = 1;
            }

            if (tw_tab_isp[i].p_next == 0)
            {
                break;
            }
            else
            {
                b_next = true;
            }
        }
    }

    for (i = 0; i < g_tweak_context.common_isp_auto_tables->ae_auto_table_num; i++)
    {
        ae_auto_params_table_t* t = &g_tweak_context.common_isp_auto_tables->ae_auto_table[i];
        if (g_tweak_context.common_isp_auto_tables_tweak_handle[i] == id)
        {
            t->enable  = (uint32_t)tweak_get_scalar_bool(id);
        }
    }
}


static tweak_id tweak_add_slider_flt_int(const char* str, float32_t minv, float32_t maxv, float32_t def, uint32_t precision)
{
    char buf2[256];

    if (precision > 0)
    {
        sprintf(buf2, "{\"readonly\":false, \"min\":%.5f, \"max\":%.5f, \"decimals\":%d}", minv, maxv, precision);
        return tweak_add_scalar_float(str, "", buf2, def);
    }
    else
    {
        sprintf(buf2, "{\"readonly\":false, \"min\":%d, \"max\":%d}", (int)minv, (int)maxv);
        return tweak_add_scalar_int32(str, "", buf2, def);
    }
}

#endif
