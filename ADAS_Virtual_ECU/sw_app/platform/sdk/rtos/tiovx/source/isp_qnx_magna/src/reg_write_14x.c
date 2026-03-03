/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           reg_write.c
 *  @brief          Implementation of registers writing. Platform specific.
 *
 *  @version        2.52
 *  @author         Mikhail Vakhrushev & Alexander Ronzhin
 *  @date           23.09.2021
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

/* PRQA S 0781 ++ */
/* PRQA S 1412 ++ */
/* PRQA S 1411 ++ */
/* PRQA S 1441 ++ */
/* PRQA S 1431 ++ */
/* PRQA S 1482 ++ */
/* PRQA S 3450 ++ */
/* PRQA S 1317 ++ */
/* PRQA S 3412 ++ */
/* PRQA S 0881 ++ */
/* PRQA S 3138 ++ */
/* PRQA S 0342 ++ */
/* PRQA S 3206 ++ */
/* PRQA S 1056 ++ */
/* PRQA S 1055 ++ */
/* PRQA S 0604 ++ */
/* PRQA S 0602 ++ */
/* PRQA S 3448 ++ */
/* PRQA S 3408 ++ */
/* PRQA S 2850 ++ */
/* PRQA S 2984 ++ */
/* PRQA S 3218 ++ */
/* PRQA S 3334 ++ */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <unistd.h>
#include "isp_process.h"

extern  float32_t* g_isp_log_regs;

#define MAX_REGISTER_BLOCK_NUMBER 5

typedef struct
{
    uint32_t sensor_id;
    uint32_t emb_id;
    char name[30];
}emb_sensor_params_t;

#define emb_sensor_params_sz_143 10
#define emb_sensor_params_sz_147 9
static emb_sensor_params_t emb_sensor_params[emb_sensor_params_sz_143] = {
                        {SENSOR_EXPOSURE,EMB_LINE_EXPOSURE_OUT_VAL, "exp"},
                        {AE_DLO_GAIN,EMB_LINE_DLO_GAIN_OUT_VAL, "dlo_gain"},
                        {AE_ANALOG_GAIN,EMB_LINE_ANALOG_GAIN_OUT_VAL, "again"},
                        {AE_GREEN_GAIN,EMB_LINE_GREEN_GAIN_OUT_VAL, "green"},
                        {TPG_PART1,EMB_LINE_TPG_PART1_OUT_VAL, "tpg1"},
                        {TPG_PART2,EMB_LINE_TPG_PART2_OUT_VAL, "tpg2"},
                        {SENSOR_DBLC_CONFIG,EMB_LINE_DBLC_CONFIG_OUT_VAL, "dblc"},
                        {ADD_TO_SENSOR_SENSOR_VIRTUAL_GAIN_T0_OUT_VAL,EMB_LINE_SENSOR_VIRTUAL_GAIN_T0_OUT_VAL, "T0"},
                        {ADD_TO_SENSOR_ISP_VERSION_OUT_VAL,EMB_LINE_ISP_VERSION_OUT_VAL, "isp_ver"},
                        {AE_DC_GAIN,EMB_LINE_DC_GAIN_OUT_VAL, "dc_gain"}};

static void set_register(uint32_t cam_num,
                         struct ar014x_reg sensorConfig[],
                         int32_t numConfigItems[],
                         uint16_t reg_address,
                         uint16_t reg_val)
{

    if (reg_address != 0)
    {
        sensorConfig[*numConfigItems].reg = reg_address; /* PRQA S 2814 */ /* PRQA S 2824 */
        sensorConfig[*numConfigItems].val =  reg_val; /* PRQA S 2814 */
        numConfigItems[0]++;

        if ((g_isp_log_cam == NULL) || ((uint32_t)(*g_isp_log_cam) == MAX_CAMERAS_NUM) || ((uint32_t)(*g_isp_log_cam) == cam_num))
        {
            isp_tracelog_i("[%d] sensor_change 0x%04x %d\n", cam_num, reg_address, reg_val); /* PRQA S 2743 */
        }
    }
}

static uint32_t bitfield(uint32_t val, uint32_t mask)
{
    uint32_t c = 0;
    uint32_t m = mask;
    uint32_t i;
    for (i = 0; i < 32; i++)
    {
        if ((m & 1) != 0)
            break;
        m>>= 1;
        c+=1;
    }

    return ((val & mask) >> c);
}

static void ar147_antibanding(const parameters_storage_t* storage, float32_t* pCIT)
{
    bool input_is_ok = true;

    float32_t CIT = pCIT[0];

    uint32_t vt_pix_clk_div = (uint32_t)get_param_check(storage, EMB_LINE_VT_PIX_CLK_DIV_OUT_VAL, &input_is_ok);
    uint32_t pre_pll_clk_div = (uint32_t)get_param_check(storage, EMB_LINE_PRE_PLL_CLK_DIV_OUT_VAL, &input_is_ok);
    uint32_t pll_multiplier = (uint32_t)get_param_check(storage, EMB_LINE_PLL_MULTIPLIER_OUT_VAL, &input_is_ok);
    uint32_t fll = (uint32_t)get_param_check(storage, EMB_LINE_FLL_OUT_VAL, &input_is_ok);
    uint32_t llpck = (uint32_t)get_param_check(storage, EMB_LINE_LLPCK_OUT_VAL, &input_is_ok);
    uint32_t dblc_btm_row = (uint32_t)get_param_check(storage, EMB_LINE_DBLC_BTM_ROW_OUT_VAL, &input_is_ok);
    uint32_t y_addr_start = (uint32_t)get_param_check(storage, EMB_LINE_Y_ADDR_START_OUT_VAL, &input_is_ok);
    uint32_t y_addr_end = (uint32_t)get_param_check(storage, EMB_LINE_Y_ADDR_END_OUT_VAL, &input_is_ok);
    uint32_t vertical_flip = (uint32_t)get_param_check(storage, EMB_LINE_VERTICAL_FLIP_OUT_VAL, &input_is_ok);
    uint32_t se_mode = (uint32_t)get_param_check(storage, EMB_LINE_SE_MODE_OUT_VAL, &input_is_ok);
    uint32_t ab_period = (uint32_t)get_param_check(storage, EMB_LINE_AB_PERIOD_OUT_VAL, &input_is_ok);
    uint32_t t3t4_sh_adv = (uint32_t)get_param_check(storage, EMB_LINE_T3T4_SH_ADV_OUT_VAL, &input_is_ok);
    uint32_t fit = (uint32_t)get_param_check(storage, EMB_LINE_FIT_OUT_VAL, &input_is_ok);
    uint32_t fit4 = (uint32_t)get_param_check(storage, EMB_LINE_FIT4_OUT_VAL, &input_is_ok);

    bool state0 = false;
    bool state1 = false;
    bool state2 = false;
    if (input_is_ok)
    {
        dblc_btm_row = bitfield(dblc_btm_row, (uint32_t)0x00F0);
        vertical_flip = bitfield(vertical_flip, (uint32_t)0x8000);
        se_mode = bitfield(se_mode, (uint32_t)0x0700);
        ab_period = bitfield(ab_period, (uint32_t)0x00FF);

        int32_t start_pointer = ((y_addr_start + 15)/16);

        int32_t add2dblcBtm = (dblc_btm_row != 0) ? 4 : 0;
        int32_t dblc_btm_add = 12 - (add2dblcBtm + dblc_btm_row);
        int32_t start_pointer_val = (start_pointer > 1) ? 2 : 0;
        int32_t nCIT = (int32_t) CIT;

        uint32_t ab_per_plus_1 = (ab_period+1U);
        uint32_t y_start_mod = y_addr_start%ab_per_plus_1;
        state0 = ((nCIT-1-dblc_btm_add-start_pointer_val-y_start_mod)%ab_per_plus_1) == 0;
        state1 = ((nCIT-2-dblc_btm_add-start_pointer_val-y_start_mod)%ab_per_plus_1) == 0;
        state2 = ((nCIT-3-dblc_btm_add-start_pointer_val-y_start_mod)%ab_per_plus_1) == 0;

        if (state0 || state1 || state2)
        {
            if (state1 == true)
            {
                CIT+= 2.f;
            }
            else if (state2 == true)
            {
                CIT+= 1.f;
            }
            else
            {
                CIT-= 1.f;
            }
        }

        pCIT[0] = CIT;
    }

    static uint32_t count = 255;
    count++;

    if(count == 256)
    {
        count = 0;
        isp_tracelog_sv("vt_pix_clk_div = %d\n", vt_pix_clk_div);
        isp_tracelog_sv("pre_pll_clk_div = %d\n", pre_pll_clk_div);
        isp_tracelog_sv("pll_multiplier = %d\n", pll_multiplier);
        isp_tracelog_sv("fll = %d\n", fll);
        isp_tracelog_sv("llpck = %d\n", llpck);
        isp_tracelog_sv("dblc_btm_row = %d\n", dblc_btm_row);
        isp_tracelog_sv("y_addr_start = %d\n", y_addr_start);
        isp_tracelog_sv("y_addr_end = %d\n", y_addr_end);
        isp_tracelog_sv("vertical_flip = %d\n", vertical_flip);
        isp_tracelog_sv("se_mode = %d\n", se_mode);
        isp_tracelog_sv("ab_period = %d\n", ab_period);
        isp_tracelog_sv("t3t3_sh_adv = %d\n", t3t4_sh_adv);
        isp_tracelog_sv("fit = %d\n", fit);
        isp_tracelog_sv("fit4 = %d\n", fit4);
        isp_tracelog_sv("antibanding = %d %d %d\n", (int)state0
            , (int)state1, (int)state2);
    }

}


static uint16_t ar147_calc_cit4(const parameters_storage_t* storage, float32_t CIT)
{
    bool input_is_ok = true;
    uint16_t ret = 2;
    uint32_t llpck = (uint32_t)get_param_check(storage, EMB_LINE_LLPCK_OUT_VAL, &input_is_ok);
    uint32_t dblc_btm_row = (uint32_t)get_param_check(storage, EMB_LINE_DBLC_BTM_ROW_OUT_VAL, &input_is_ok);
    uint32_t vertical_flip = (uint32_t)get_param_check(storage, EMB_LINE_VERTICAL_FLIP_OUT_VAL, &input_is_ok);
    uint32_t se_mode = (uint32_t)get_param_check(storage, EMB_LINE_SE_MODE_OUT_VAL, &input_is_ok);
    uint32_t ab_period = (uint32_t)get_param_check(storage, EMB_LINE_AB_PERIOD_OUT_VAL, &input_is_ok);
    uint32_t fit = (uint32_t)get_param_check(storage, EMB_LINE_FIT_OUT_VAL, &input_is_ok);
    uint32_t fit4 = (uint32_t)get_param_check(storage, EMB_LINE_FIT4_OUT_VAL, &input_is_ok);

    if (input_is_ok)
    {
        dblc_btm_row = bitfield(dblc_btm_row, (uint32_t)0x00F0);
        vertical_flip = bitfield(vertical_flip, (uint32_t)0x8000);
        se_mode = bitfield(se_mode, (uint32_t)0x0700);
        ab_period = bitfield(ab_period, (uint32_t)0x00FF);
        float32_t T2_Gain = 4.f;
        float32_t T2_Barrier = 3800.f;
        float32_t Min_DLO_Gain3_120dB = 1048576.f/T2_Barrier;
        float32_t T1_inPclk = (CIT - 1.f)*llpck + (float32_t)fit;
        uint32_t GCF_TG_1P5 = 0xE8;
        float32_t DCG_Ratio = (float32_t)GCF_TG_1P5/16.f;
        float32_t Max_T2_inPCLK = (T1_inPclk*DCG_Ratio + T1_inPclk + T1_inPclk)/(Min_DLO_Gain3_120dB*T2_Gain - T2_Gain);
        float32_t CIT4 = floorf(((Max_T2_inPCLK-fit4)/(llpck))+1.f);
        ret = (uint16_t)clampf32(CIT4, 2.f, 18.f);
    }
    else
    {
        isp_tracelog_e("Cannot calc CIT4, not enough embedded line inputs\n");
    }

    return ret;
}

typedef float32_t (*register_read_f)(uint32_t id, float32_t vf);
static float32_t register_read_143(uint32_t id, float32_t vf)
{
    float32_t ret = 0.f;
    uint32_t v = (uint32_t)vf;
    switch (id)
    {
    case AE_DC_GAIN:
        ret = (float32_t)(((uint32_t)v & 0x7) >> 2);
        break;
    case AE_ANALOG_GAIN:
        ret = (float32_t)((uint32_t)v >> 8);
        break;
    case ADD_TO_SENSOR_SENSOR_VIRTUAL_GAIN_T0_OUT_VAL:
        ret = convert_fixed_to_float_u(v, 16, 8);
        break;
    default:
        ret = vf;
        break;
    }

    return ret;
}

static float32_t register_read_147(uint32_t id, float32_t vf)
{
    float32_t ret = 0.f;
    uint32_t v = (uint32_t)vf;
    switch (id)
    {
    case AE_DC_GAIN:
        ret = 0.f;
        break;
    case AE_ANALOG_GAIN:
        ret = (v == 0xDE79) ? (float32_t)ANALOG_GAIN_DAY : (float32_t)ANALOG_GAIN_NIGHT;
        break;
    case ADD_TO_SENSOR_SENSOR_VIRTUAL_GAIN_T0_OUT_VAL:
        ret = convert_fixed_to_float_u(v, 16, 8);
        break;
    default:
        ret = vf;
        break;
    }

    return ret;
}


typedef uint16_t (*register_write_f)(uint32_t id, float32_t v);
static uint16_t register_write_143(uint32_t id, float32_t v)
{
    uint32_t ret = 0.f;
    uint32_t reg_val = (uint32_t) v;

    switch (id)
    {
    case AE_DC_GAIN:
        ret = reg_val + (reg_val * 2) + (reg_val * 4);
        break;
    case AE_ANALOG_GAIN:
        ret = reg_val + (reg_val * 16) + (reg_val * 16 * 16);
        break;
    case ADD_TO_SENSOR_SENSOR_VIRTUAL_GAIN_T0_OUT_VAL:
        ret = convert_float_to_fixed_u(v, 16, 8);
        break;
    default:
        ret = (uint32_t) v;
        break;
    }

    return (uint16_t)ret;
}


static uint16_t register_write_147(uint32_t id, float32_t v)
{
    uint32_t ret = 0;
    uint32_t reg_val = (uint32_t) v;

    switch (id)
    {
    case AE_ANALOG_GAIN:
        ret = reg_val == 5U ? 0xDE79 : 0xDEAB;
        break;
    case ADD_TO_SENSOR_SENSOR_VIRTUAL_GAIN_T0_OUT_VAL:
        ret = convert_float_to_fixed_u(v, 16, 8);
        break;
    default:
        ret = (uint32_t) v;
        break;
    }

    return (uint16_t)ret;
}


void set_all_sensor_params(uint32_t cam_num, magna_camera_sensor_type_t sensorType, struct ar014x_reg sensorConfig[], int32_t numConfigItems[], bool* p_exp_gain_change)
{
    parameters_storage_t* parameters_storage = get_parameters_storage(cam_num);
    uint32_t i;
    bool input_is_ok = true;
    const float32_t epsilon = 0.01f;
    bool check_val;
    uint32_t j;
    bool write = (get_param(parameters_storage, SENSOR_WRITE) > 0.0f) ? true : false;

    register_read_f register_read = (sensorType == MAGNA_CAMERA_SENSOR_AR0143) ? register_read_143: register_read_147;
    register_write_f register_write = (sensorType == MAGNA_CAMERA_SENSOR_AR0143) ? register_write_143 : register_write_147;
    uint32_t emb_sensor_params_sz = (sensorType == MAGNA_CAMERA_SENSOR_AR0143) ? emb_sensor_params_sz_143 : emb_sensor_params_sz_147;

    if (write)
    {
        for (i = 0; i < emb_sensor_params_sz; i++)
        {
            uint16_t reg_address[MAX_REGISTER_BLOCK_NUMBER] = {0};
            uint16_t reg_val[MAX_REGISTER_BLOCK_NUMBER] = {0};
            float32_t emb;
            float32_t sensor_param;

            emb = get_param_check(parameters_storage, emb_sensor_params[i].emb_id, &input_is_ok);
            sensor_param = get_param_check(parameters_storage, emb_sensor_params[i].sensor_id, &input_is_ok);

            emb = register_read(emb_sensor_params[i].sensor_id, emb);


            if ((emb_sensor_params[i].sensor_id == SENSOR_EXPOSURE)
                && (sensorType == MAGNA_CAMERA_SENSOR_AR0147))
            {
                ar147_antibanding(parameters_storage, &sensor_param);
            }

            reg_val[0] = (uint16_t)register_write(emb_sensor_params[i].sensor_id, sensor_param);

            check_val = (fabsf(sensor_param - emb) > epsilon) ? true : false;

            if (emb_sensor_params[i].sensor_id == AE_GREEN_GAIN)
            {
                float32_t emb_g = get_param(parameters_storage, EMB_LINE_GREEN_GAIN_OUT_VAL);
                float32_t emb_r = get_param(parameters_storage, EMB_LINE_RED_GAIN_OUT_VAL);
                float32_t emb_b = get_param(parameters_storage, EMB_LINE_BLUE_GAIN_OUT_VAL);
                float32_t pre_hdr_gain = get_param(parameters_storage, SENSOR_PRE_HDR_GAIN);
                float32_t sensor_param_g = get_param(parameters_storage, AE_GREEN_GAIN);
                float32_t sensor_param_r = get_param(parameters_storage, AE_RED_GAIN);
                float32_t sensor_param_b = get_param(parameters_storage, AE_BLUE_GAIN);

                float32_t max_awb_gain = ISP_MAX(ISP_MAX(sensor_param_r, sensor_param_b), sensor_param_g);
                float32_t max_pre_hdr_gain = ISP_MIN(pre_hdr_gain * max_awb_gain, 15.9921875f);
                pre_hdr_gain = max_pre_hdr_gain / max_awb_gain;
                sensor_param_g = 128.f * pre_hdr_gain * sensor_param_g;
                sensor_param_r = 128.f * pre_hdr_gain * sensor_param_r;
                sensor_param_b = 128.f * pre_hdr_gain * sensor_param_b;
                sensor_param_g = floorf(sensor_param_g + 0.5f);
                sensor_param_r = floorf(sensor_param_r + 0.5f);
                sensor_param_b = floorf(sensor_param_b + 0.5f);

                bool check_val_g = (fabsf(sensor_param_g - emb_g) > epsilon) ? true : false;
                bool check_val_r = (fabsf(sensor_param_r - emb_r) > epsilon) ? true : false;
                bool check_val_b = (fabsf(sensor_param_b - emb_b) > epsilon) ? true : false;

                if ((check_val_g)   ||
                    (check_val_r) ||
                    (check_val_b))
                {
                    reg_address[0] = AR014X_LIST_CMD;
                    reg_val[0] = 4;
                    reg_address[1] = 0x3056;
                    reg_val[1] = (uint16_t)(sensor_param_g);
                    reg_address[2] = 0x3058;
                    reg_val[2] = (uint16_t)(sensor_param_b);
                    reg_address[3] = 0x305A;
                    reg_val[3] = (uint16_t)(sensor_param_r);
                    reg_address[4] = 0x305C;
                    reg_val[4] = (uint16_t)(sensor_param_g);
                    check_val = true;

                    isp_tracelog_sv("cam %d emb %.3f %.3f %.3f %.3f %s %.3f %.3f %.3f %.3f\n", cam_num,
                                    emb,
                                    get_param(parameters_storage, EMB_LINE_BLUE_GAIN_OUT_VAL),
                                    get_param(parameters_storage, EMB_LINE_RED_GAIN_OUT_VAL),
                                    emb,
                                    emb_sensor_params[i].name,
                                    sensor_param_g,
                                    sensor_param_b,
                                    sensor_param_r,
                                    sensor_param_g);
                }
                else
                {
                    check_val = false;
                }
            }

            uint32_t num = 0;
            if((check_val) && (input_is_ok))
            {
                if (g_isp_log_regs[0] > 0.5f)
                {
                    isp_tracelog_i("SENSOR NEED TO WRITE %s: %.1f %.1f\n", get_string_from_id(emb_sensor_params[i].sensor_id), sensor_param, emb);
                }

                switch (emb_sensor_params[i].sensor_id)
                {
                    case SENSOR_EXPOSURE:
                        num = 0;
                        reg_address[num++] = 0x3012;
                        *p_exp_gain_change = true;

                        if (sensorType == MAGNA_CAMERA_SENSOR_AR0147)
                        {
                            reg_address[num] = 0x321A;
                            reg_val[num++] = ar147_calc_cit4(parameters_storage, sensor_param);
                        }

                        break;
                    case SENSOR_DBLC_CONFIG:
                        reg_address[0] = 0x3370;
                        break;
                    case AE_DLO_GAIN:
                        reg_address[0] = 0x3308;
                        *p_exp_gain_change = true;

                        break;
                    case AE_DC_GAIN:
                        if (sensorType == MAGNA_CAMERA_SENSOR_AR0143)
                        {
                            reg_address[0] = 0x3362;
                            *p_exp_gain_change = true;
                        }
                        break;
                    case TPG_PART1:
                        reg_address[0] = 0x3070;
                        break;
                    case TPG_PART2:
                        reg_address[0] = 0x3388;
                        break;
                    case AE_ANALOG_GAIN:
                        if (sensorType == MAGNA_CAMERA_SENSOR_AR0143)
                        {
                            reg_address[0] = 0x3366;
                            *p_exp_gain_change = true;
                        }
                        if (sensorType == MAGNA_CAMERA_SENSOR_AR0147)
                        {
                            reg_address[0] = 0x3366;
                            *p_exp_gain_change = true;

                            if  (((uint32_t)sensor_param) == ANALOG_GAIN_NIGHT)
                            {
                                reg_address[2] = 0x3F76;
                                reg_val[2] = 0x0ee8;
                            }

                        }
                        break;
                    case ADD_TO_SENSOR_ISP_VERSION_OUT_VAL:
                            reg_address[0] = 0x31D2;
                        break;
                    case ADD_TO_SENSOR_SENSOR_VIRTUAL_GAIN_T0_OUT_VAL:
                            reg_address[0] = 0x3216;
                        break;
                    default:
                        break;
                }

                for (j = 0; j < MAX_REGISTER_BLOCK_NUMBER; j++)
                {
                    set_register(cam_num, sensorConfig, numConfigItems, reg_address[j], reg_val[j]);
                }

                if ((g_isp_log_cam == NULL) || ((uint32_t)(*g_isp_log_cam) == MAX_CAMERAS_NUM) || ((uint32_t)(*g_isp_log_cam) == cam_num))
                {
                    isp_tracelog_sv("cam %d emb %.3f %s %.3f\n", cam_num, emb, emb_sensor_params[i].name, sensor_param);
                }
            }
        }
    }
}
