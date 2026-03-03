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
/* #include <pthread.h> */
#include <math.h>
/* #include <unistd.h> */
#include "isp_process.h"
#include "registers_setup_233.h"

extern  float32_t* g_isp_log_regs;

#define MAX_REGISTER_BLOCK_NUMBER 5

static const uint32_t ar0233_sclk = 105000U;

typedef struct
{
    uint32_t sensor_id;
    uint32_t emb_id;
    char name[30];
}emb_sensor_params_t;

#define emb_sensor_params_sz_233 11
static emb_sensor_params_t emb_sensor_params[emb_sensor_params_sz_233] = {
                        {SENSOR_EXPOSURE,EMB_LINE_EXPOSURE_OUT_VAL, "exp"},
                        {AE_DLO_GAIN,EMB_LINE_DLO_GAIN_OUT_VAL, "dlo_gain"},
                        {AE_ANALOG_GAIN,EMB_LINE_ANALOG_GAIN_OUT_VAL, "again"},
                        {AE_GREEN_GAIN,EMB_LINE_GREEN_GAIN_OUT_VAL, "green"},
                        {TPG_PART1,EMB_LINE_TPG_PART1_OUT_VAL, "tpg1"},
                        {TPG_PART2,EMB_LINE_TPG_PART2_OUT_VAL, "tpg2"},
                        {TEST_DATA_R,EMB_LINE_TEST_DATA_R_OUT_VAL, "test_data_r"},
                        {TEST_DATA_GR,EMB_LINE_TEST_DATA_GR_OUT_VAL, "test_data_gr"},
                        {TEST_DATA_B,EMB_LINE_TEST_DATA_B_OUT_VAL, "test_data_b"},
                        {TEST_DATA_GB,EMB_LINE_TEST_DATA_GB_OUT_VAL, "test_data_gb"},
                        {SENSOR_DBLC_CONFIG,EMB_LINE_DBLC_CONFIG_OUT_VAL, "dblc"}};

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
    }
}

typedef float32_t (*register_read_f)(uint32_t id, float32_t vf);
static float32_t register_read_233(uint32_t id, float32_t vf)
{
    float32_t ret = 0.f;
    uint32_t v = (uint32_t)vf;
    switch (id)
    {
    case AE_ANALOG_GAIN:
    {
        uint32_t fine_long_ag = (v & 0xf);
        ret = (fine_long_ag == 15) ? (float32_t)ANALOG_GAIN_NIGHT : (float32_t)ANALOG_GAIN_DAY;
        break;
    }
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
static uint16_t register_write_233(uint32_t id, float32_t v)
{
    uint32_t ret = 0.f;
    uint32_t reg_val = (uint32_t) v;

    switch (id)
    {
    case AE_ANALOG_GAIN:
        ret = reg_val == ANALOG_GAIN_DAY ? default_analog_gain : (default_analog_gain | 15);
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

static float32_t calculate_real_analog_gain(uint8_t c_ag, uint8_t f_ag)
{
    float32_t readl_f_ag;
    switch (c_ag)
    {
    case 0:
    case 1:
        readl_f_ag = 32.0f / (32.0f - (float32_t)f_ag);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        readl_f_ag = 32.0f / (32.0f - 2.0f * floorf((float32_t)f_ag / 2.0f));
        break;

    default:
        readl_f_ag = 32.0f / (32.0f - (float32_t)f_ag);
        break;
    }
    return (powf(2, c_ag) / 2.0f) * readl_f_ag;
}


static uint16_t ar233_calc_T2(const parameters_storage_t* storage, float32_t CIT, uint32_t ag_fine)
{
    bool input_is_ok = true;
    uint16_t ret = 5;
    uint32_t ag_coarse = (uint32_t)get_param_check(storage, EMB_LINE_ANALOG_GAIN_COARSE_OUT_VAL, &input_is_ok);

    if (input_is_ok)
    {
        float32_t real_ag = calculate_real_analog_gain(ag_coarse & 0xf, ag_fine & 0xf);
        ret = (uint16_t)ceilf((CIT * real_ag) / 100.f);
        ret = clampu(ret, 3, 150);
    }
    else
    {
        isp_tracelog_e("Cannot calc CIT2, not enough embedded line inputs\n");
    }

    return ret;
}

static void set_all_sensor_params(uint32_t cam_num, uint8_t* sensorConfig, uint32_t* numConfigItems, bool* p_exp_gain_change)
{
    parameters_storage_t* parameters_storage = get_parameters_storage(cam_num);
    uint32_t i;
    bool input_is_ok = true;
    const float32_t epsilon = 0.01f;
    bool check_val;
    uint32_t j;
    bool write = (get_param(parameters_storage, SENSOR_WRITE) > 0.0f) ? true : false;
    register_read_f register_read = register_read_233;
    register_write_f register_write = register_write_233;
    uint32_t emb_sensor_params_sz = emb_sensor_params_sz_233;
    uint32_t written = 0;
    uint32_t latest_sz = 2;
    uint32_t limit = numConfigItems[0];

    int32_t err = EOK;

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
                    if (latest_sz != 8)
                    {
                        latest_sz = 8;
                        write_uint16_to_array(sensorConfig, &written, limit, 0, &err);
                        write_uint16_to_array(sensorConfig, &written, limit, latest_sz, &err);
                    }

                    write_uint16_to_array(sensorConfig, &written, limit, 0x3056, &err);
                    write_uint16_to_array_be(sensorConfig, &written, limit, (uint16_t)(sensor_param_g), &err);
                    write_uint16_to_array_be(sensorConfig, &written, limit, (uint16_t)(sensor_param_b), &err);
                    write_uint16_to_array_be(sensorConfig, &written, limit, (uint16_t)(sensor_param_r), &err);
                    write_uint16_to_array_be(sensorConfig, &written, limit, (uint16_t)(sensor_param_g), &err);
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
                    isp_tracelog_e("SENSOR NEED TO WRITE %s: %.1f %.1f\n", get_string_from_id(emb_sensor_params[i].sensor_id), sensor_param, emb);
                }
                uint16_t ag_f = 0;
                switch (emb_sensor_params[i].sensor_id)
                {
                    case SENSOR_EXPOSURE:
                        num = 0;
                        reg_address[num++] = 0x3012;
                        *p_exp_gain_change = true;
                        reg_address[num] = 0x3212;
                        ag_f = (uint16_t)register_write(AE_ANALOG_GAIN, get_param(parameters_storage, AE_ANALOG_GAIN));
                        reg_val[num++] = ar233_calc_T2(parameters_storage, sensor_param, ag_f);
                        break;
                    case SENSOR_DBLC_CONFIG:
                        reg_address[0] = 0x3370;
                        break;
                    case AE_DLO_GAIN:
                        reg_address[0] = 0x3308;
                        *p_exp_gain_change = true;

                        break;
                    case AE_ANALOG_GAIN:
                        num = 0;
                        reg_address[num++] = 0x336a;
                        *p_exp_gain_change = true;
                        reg_address[num] = 0x3212;
                        reg_val[num++] = ar233_calc_T2(parameters_storage, (uint32_t)get_param(parameters_storage, SENSOR_EXPOSURE), reg_val[0]);
                        break;
                    case TPG_PART1:
                        reg_address[0] = 0x3070;
                        break;
                    case TPG_PART2:
                        reg_address[0] = 0x3388;
                        break;
                    case TEST_DATA_R:
                        reg_address[0] = 0x3072;
                        break;
                    case TEST_DATA_GR:
                        reg_address[0] = 0x3074;
                        break;
                    case TEST_DATA_B:
                        reg_address[0] = 0x3076;
                        break;
                    case TEST_DATA_GB:
                        reg_address[0] = 0x3078;
                        break;
                    default:
                        break;
                }

                for (j = 0; j < MAX_REGISTER_BLOCK_NUMBER; j++)
                {
                    if (reg_address[j] != 0)
                    {
                        if (latest_sz != 2)
                        {
                            latest_sz = 2;
                            write_uint16_to_array(sensorConfig, &written, limit, 0, &err);
                            write_uint16_to_array(sensorConfig, &written, limit, latest_sz, &err);
                        }

                        write_uint16_to_array(sensorConfig, &written, limit, reg_address[j], &err);
                        write_uint16_to_array_be(sensorConfig, &written, limit, reg_val[j], &err);
                    }
                }

                if ((g_isp_log_cam == NULL) || ((uint32_t)(*g_isp_log_cam) == MAX_CAMERAS_NUM) || ((uint32_t)(*g_isp_log_cam) == cam_num))
                {
                    isp_tracelog_sv("cam %d emb %.3f %s %.3f\n", cam_num, emb, emb_sensor_params[i].name, sensor_param);
                }
            }
        }
    }

    numConfigItems[0] = written;
}

static const struct ar014x_reg ar0233_regs_wizard[] = {
    AR233_DEFAULTS
    /* end reg wizard WIDTHxHEIGHT@30fps*/
};
const uint32_t ar0233RegsNum = sizeof(ar0233_regs_wizard) / sizeof(ar0233_regs_wizard[0]);


static void fill_regs_default_table(uint8_t* sensorConfig, uint32_t* numConfigItems)
{
    int32_t err = EOK;
    uint32_t written = 0;
    uint32_t array_limit = *numConfigItems;
    write_uint16_to_array(sensorConfig, &written, array_limit, 0, &err);
    write_uint16_to_array(sensorConfig, &written, array_limit, 2, &err);

    uint32_t i;
    for (i = 0; i < ar0233RegsNum; i++)
    {
        write_uint16_to_array(sensorConfig, &written, array_limit, ar0233_regs_wizard[i].reg, &err);
        write_uint16_to_array_be(sensorConfig, &written, array_limit, ar0233_regs_wizard[i].val, &err);
    }
    *numConfigItems = (int32_t)written;
}

void parse_regs_from_emb_line(parameters_storage_t* storage,
                              const struct ar014x_sensor_data* sensorData,
                              uint32_t cam_num);

static const float32_t weight_table[] =
    {
0.0, 8.0, 16.0, 24.0, 32.0, 40.0, 48.0, 56.0, 64.0, 72.0, 80.0, 88.0, 96.0, 104.0, 112.0, 120.0, 128.0, 144.0, 160.0, 176.0, 192.0, 208.0, 224.0, 240.0, 256.0, 288.0, 320.0, 352.0, 384.0, 416.0, 448.0, 480.0, 512.0, 576.0, 640.0, 704.0, 768.0, 832.0, 896.0, 960.0, 1024.0, 1152.0, 1280.0, 1408.0, 1536.0, 1664.0, 1792.0, 1920.0, 2048.0, 2176.0, 2304.0, 2432.0, 2560.0, 2688.0, 2816.0, 2944.0, 3072.0, 3200.0, 3328.0, 3456.0, 3584.0, 3712.0, 3840.0, 3968.0, 4096.0, 4608.0, 5120.0, 5632.0, 6144.0, 6656.0, 7168.0, 7680.0, 8192.0, 8704.0, 9216.0, 9728.0, 10240.0, 10752.0, 11264.0, 11776.0, 12288.0, 12800.0, 13312.0, 13824.0, 14336.0, 14848.0, 15360.0, 15872.0, 16384.0, 16896.0, 17408.0, 17920.0, 18432.0, 18944.0, 19456.0, 19968.0, 20480.0, 20992.0, 21504.0, 22016.0, 22528.0, 23040.0, 23552.0, 24064.0, 24576.0, 25088.0, 25600.0, 26112.0, 26624.0, 27136.0, 27648.0, 28160.0, 28672.0, 29184.0, 29696.0, 30208.0, 30720.0, 31232.0, 31744.0, 32256.0, 32768.0, 33280.0, 33792.0, 34304.0, 34816.0, 35328.0, 35840.0, 36352.0, 36864.0, 37376.0, 37888.0, 38400.0, 38912.0, 39424.0, 39936.0, 40448.0, 40960.0, 41472.0, 41984.0, 42496.0, 43008.0, 43520.0, 44032.0, 44544.0, 45056.0, 45568.0, 46080.0, 46592.0, 47104.0, 47616.0, 48128.0, 48640.0, 49152.0, 49664.0, 50176.0, 50688.0, 51200.0, 51712.0, 52224.0, 52736.0, 53248.0, 53760.0, 54272.0, 54784.0, 55296.0, 55808.0, 56320.0, 56832.0, 57344.0, 57856.0, 58368.0, 58880.0, 59392.0, 59904.0, 60416.0, 60928.0, 61440.0, 61952.0, 62464.0, 62976.0, 63488.0, 64000.0, 64512.0, 65024.0, 65536.0, 81920.0, 98304.0, 114688.0, 131072.0, 147456.0, 163840.0, 180224.0, 196608.0, 212992.0, 229376.0, 245760.0, 262144.0, 278528.0, 294912.0, 311296.0, 327680.0, 344064.0, 360448.0, 376832.0, 393216.0, 409600.0, 425984.0, 442368.0, 458752.0, 475136.0, 491520.0, 507904.0, 524288.0, 540672.0, 557056.0, 573440.0, 589824.0, 606208.0, 622592.0, 638976.0, 655360.0, 671744.0, 688128.0, 704512.0, 720896.0, 737280.0, 753664.0, 770048.0, 786432.0, 802816.0, 819200.0, 835584.0, 851968.0, 868352.0, 884736.0, 901120.0, 917504.0, 933888.0, 950272.0, 966656.0, 983040.0, 999424.0, 1015808.0, 1032192.0
    };

bool parse_histogram(const uint8_t* stat,uint32_t hist[244], uint32_t *pixel_count);
static bool parse_histogram_233(const uint8_t* stat,uint32_t hist[512], uint32_t *pixel_count, uint32_t* bins_num, const float32_t** weights)
{
    if (weights)
    {
        *weights = weight_table;
        bins_num[0] = sizeof(weight_table) / sizeof(weight_table[0]);
    }

    return parse_histogram(stat, hist, pixel_count);
}


static void calc_snr_ar233(const uint32_t hist[512], uint32_t pixel_count, uint32_t bins_num, float dg, float* snr)
{
    static const float32_t snr_weight_table[] = {-3.63f, 1.14f, 4.82f, 7.51f, 9.59f, 11.28f, 12.71f, 13.93f, 15.00f, 15.96f, 16.82f, 17.61f, 18.33f, 19.00f, 19.61f, 20.19f, 20.73f, 21.24f, 21.72f, 22.18f, 22.61f, 23.03f, 23.42f, 23.80f, 24.16f, 24.51f, 24.84f, 25.16f, 25.47f, 25.77f, 26.06f, 26.34f, 26.61f, 26.87f, 27.13f, 27.38f, 27.62f, 27.85f, 28.08f, 28.30f, 28.52f, 28.73f, 28.94f, 29.14f, 29.34f, 29.53f, 29.72f, 29.91f, 30.09f, 30.26f, 30.44f, 30.61f, 30.77f, 30.94f, 31.10f, 31.26f, 31.41f, 31.56f, 28.27f, 28.42f, 28.57f, 28.71f, 28.85f, 28.99f, 29.12f, 29.26f, 29.39f, 29.52f, 29.64f, 29.77f, 29.89f, 30.02f, 30.14f, 30.26f, 30.37f, 30.49f, 30.60f, 30.72f, 30.83f, 30.94f, 31.05f, 31.15f, 31.26f, 31.36f, 31.47f, 31.57f, 31.67f, 31.77f, 31.87f, 31.97f, 32.06f, 32.16f, 32.25f, 32.35f, 32.44f, 32.53f, 32.62f, 32.71f, 32.80f, 32.89f, 32.97f, 33.06f, 33.15f, 33.23f, 33.31f, 33.40f, 33.48f, 33.56f, 33.64f, 33.72f, 33.80f, 33.88f, 33.95f, 34.03f, 34.11f, 34.18f, 34.26f, 34.33f, 34.41f, 34.48f, 34.55f, 34.62f, 34.69f, 34.76f, 34.83f, 34.90f, 34.97f, 35.04f, 35.11f, 35.18f, 35.24f, 35.31f, 35.37f, 35.44f, 35.51f, 35.57f, 35.63f, 35.70f, 35.76f, 35.82f, 35.88f, 35.95f, 36.01f, 36.07f, 36.13f, 36.19f, 36.25f, 36.31f, 36.37f, 36.42f, 36.48f, 36.54f, 36.60f, 36.65f, 36.71f, 36.77f, 36.82f, 36.88f, 36.93f, 36.99f, 37.04f, 37.09f, 37.15f, 37.20f, 37.25f, 37.31f, 37.36f, 37.41f, 37.46f, 37.51f, 37.57f, 37.62f, 37.67f, 37.72f, 37.77f, 37.82f, 37.87f, 37.91f, 37.96f, 38.01f, 38.06f, 38.11f, 38.16f, 38.20f, 38.25f, 38.30f, 38.34f, 38.39f, 38.44f, 38.48f, 38.53f, 38.57f, 38.62f, 38.66f, 38.71f, 38.75f, 38.80f, 38.84f, 38.89f, 38.93f, 38.97f, 39.02f, 39.06f, 39.10f, 39.14f, 39.19f, 39.23f, 39.27f, 39.31f, 39.35f, 39.40f, 39.44f, 39.48f, 39.52f, 39.56f, 39.60f, 39.64f, 39.68f, 39.72f, 39.76f, 39.80f, 39.84f, 39.88f, 39.92f, 39.95f, 39.99f, 40.03f, 40.07f, 40.11f, 40.15f, 40.18f, 40.22f, 40.26f, 40.30f, 40.33f, 40.37f, 40.41f, 40.44f, 40.48f, 40.52f, 40.55f, 40.59f, 40.62f, 40.66f, 40.70f, 40.73f, 40.77f, 40.80f, 40.84f, 40.87f, 40.91f, 40.94f, 40.98f, 41.01f, 41.04f, 41.08f, 41.11f, 41.15f, 41.18f, 41.21f, 41.25f, 41.28f, 41.31f, 41.35f, 41.38f, 41.41f, 41.44f, 41.48f, 41.51f, 41.54f, 41.57f, 41.61f, 41.64f, 41.67f, 41.70f, 41.73f, 41.76f, 41.80f, 41.83f, 41.86f, 41.89f, 41.92f, 41.95f, 41.98f, 42.01f, 42.04f, 42.07f, 42.10f, 42.13f, 42.16f, 42.19f, 42.22f, 42.25f, 42.28f, 42.31f, 42.34f, 42.37f, 42.40f, 42.43f, 42.46f, 42.49f, 42.52f, 42.55f, 42.57f, 42.60f, 42.63f, 42.66f, 42.69f, 42.72f, 42.74f, 42.77f, 42.80f, 42.83f, 42.86f, 42.88f, 42.91f, 42.94f, 27.38f, 27.41f, 27.43f, 27.46f, 27.49f, 27.51f, 27.54f, 27.57f, 27.59f, 27.62f, 27.65f, 27.67f, 27.70f, 27.73f, 27.75f, 27.78f, 27.81f, 27.83f, 27.86f, 27.88f, 27.91f, 27.93f, 27.96f, 27.99f, 28.01f, 28.04f, 28.06f, 28.09f, 28.11f, 28.14f, 28.16f, 28.19f, 28.21f, 28.24f, 28.26f, 28.29f, 28.31f, 28.34f, 28.36f, 28.38f, 28.41f, 28.43f, 28.46f, 28.48f, 28.51f, 28.53f, 28.55f, 28.58f, 28.60f, 28.62f, 28.65f, 28.67f, 28.70f, 28.72f, 28.74f, 28.77f, 28.79f, 28.81f, 28.84f, 28.86f, 28.88f, 28.90f, 28.93f, 28.95f, 28.97f, 29.00f, 29.02f, 29.04f, 29.06f, 29.09f, 29.11f, 29.13f, 29.15f, 29.18f, 29.20f, 29.22f, 29.24f, 29.26f, 29.29f, 29.31f, 29.33f, 29.35f, 29.37f, 29.40f, 29.42f, 29.44f, 29.46f, 29.48f, 29.50f, 29.52f, 29.55f, 29.57f, 29.59f, 29.61f, 29.63f, 29.65f, 29.67f, 29.69f, 29.71f, 29.74f, 29.76f, 29.78f, 29.80f, 29.82f, 29.84f, 29.86f, 29.88f, 29.90f, 29.92f, 29.94f, 29.96f, 29.98f, 30.00f, 30.02f, 30.04f, 30.06f, 30.08f, 30.10f, 30.12f, 30.14f, 30.16f, 30.18f, 30.20f, 30.22f, 30.24f, 30.26f, 30.28f, 30.30f, 30.32f, 30.34f, 30.36f, 30.38f, 30.40f, 30.42f, 30.44f, 30.46f, 30.47f, 30.49f, 30.51f, 30.53f, 30.55f, 30.57f, 30.59f, 30.61f, 30.63f, 30.65f, 30.66f, 30.68f, 30.70f, 30.72f, 30.74f, 30.76f, 30.78f, 30.79f, 30.81f, 30.83f, 30.85f, 30.87f, 30.89f, 30.90f, 30.92f, 30.94f, 30.96f, 30.98f, 31.00f, 31.01f, 31.03f, 31.05f, 31.07f, 31.08f, 31.10f, 31.12f, 31.14f, 31.16f, 31.17f, 31.19f, 31.21f, 31.23f, 31.24f, 31.26f, 31.28f, 31.30f, 31.31f, 31.33f, 31.35f, 31.37f, 31.38f, 31.40f, 31.42f, 31.43f, 31.45f, 31.47f, 31.49f, 31.50f, 31.52f, 31.54f, 31.55f, 31.57f, 31.59f, 31.60f, 31.62f, 31.64f, 31.65f, 31.67f, 31.69f, 31.70f, 31.72f, 31.74f, 31.75f, 31.77f, 31.79f, 31.80f, 31.82f, 31.84f, 31.85f, 31.87f, 31.89f, 31.90f, 31.92f, 31.93f, 31.95f, 31.97f, 31.98f, 32.00f, 32.02f, 32.03f, 32.05f, 32.06f, 32.08f, 32.09f, 32.11f, 32.13f, 32.14f, 32.16f, 32.17f, 32.19f, 32.21f, 32.22f, 32.24f, 32.25f, 32.27f, 32.28f, 32.30f, 32.31f, 32.33f, 32.35f, 32.36f, 32.38f, 32.39f, 32.41f, 32.42f, 32.44f, 32.45f, 32.47f, 32.48f, 32.50f, 32.51f, 32.53f, 32.54f, 32.56f, 32.57f, 32.59f, 32.60f, 32.62f, 32.63f, 32.65f, 32.66f, 32.68f, 32.69f, 32.71f, 32.72f, 32.74f, 32.75f, 32.77f, 32.78f, 32.80f, 32.81f, 32.83f, 32.84f, 32.86f, 32.87f, 32.88f, 32.90f, 32.91f, 32.93f, 32.94f, 32.96f, 32.97f, 32.99f, 33.00f, 33.01f, 33.03f, 33.04f, 33.06f, 33.07f, 33.09f, 33.10f, 33.11f, 33.13f, 33.14f, 33.16f, 33.17f, 33.18f, 33.20f, 33.21f, 33.23f, 33.24f, 33.25f, 33.27f, 33.28f, 33.30f, 33.31f, 33.32f, 33.34f, 33.35f, 33.36f, 33.38f, 33.39f, 33.41f, 33.42f, 33.43f, 33.45f, 33.46f, 33.47f, 33.49f, 33.50f, 33.51f, 33.53f, 33.54f, 33.55f, 33.57f, 33.58f, 33.59f, 33.61f, 33.62f, 33.63f, 33.65f, 33.66f, 33.67f, 33.69f, 33.70f, 33.71f, 33.73f, 33.74f, 33.75f, 33.77f, 33.78f, 33.79f, 33.81f, 33.82f, 33.83f, 33.85f, 33.86f, 33.87f, 33.88f, 33.90f, 33.91f, 33.92f, 33.94f, 33.95f, 33.96f, 33.97f, 33.99f, 34.00f, 34.01f, 34.03f, 34.04f, 34.05f, 34.06f, 34.08f, 34.09f, 34.10f, 34.11f, 34.13f, 34.14f, 34.15f, 34.16f, 34.18f, 34.19f, 34.20f, 34.21f, 34.23f, 34.24f, 34.25f, 34.26f, 34.28f, 34.29f, 34.30f, 34.31f, 34.33f, 34.34f, 34.35f, 34.36f, 34.37f, 34.39f, 34.40f, 34.41f, 34.42f, 34.44f, 34.45f, 34.46f, 34.47f, 34.48f, 34.50f, 34.51f, 34.52f, 34.53f, 34.54f, 34.56f, 34.57f, 34.58f, 34.59f, 34.60f, 34.62f, 34.63f, 34.64f, 34.65f, 34.66f, 34.67f, 34.69f, 34.70f, 34.71f, 34.72f, 34.73f, 34.75f, 34.76f, 34.77f, 34.78f, 34.79f, 34.80f, 34.82f, 34.83f, 34.84f, 34.85f, 34.86f, 34.87f, 34.88f, 34.90f, 34.91f, 34.92f, 34.93f, 34.94f, 34.95f, 34.97f, 34.98f, 34.99f, 35.00f, 35.01f, 35.02f, 35.03f, 35.04f, 35.06f, 35.07f, 35.08f, 35.09f, 35.10f, 35.11f, 35.12f, 35.13f, 35.15f, 35.16f, 35.17f, 35.18f, 35.19f, 35.20f, 35.21f, 35.22f, 35.23f, 35.25f, 35.26f, 35.27f, 35.28f, 35.29f, 35.30f, 35.31f, 35.32f, 35.33f, 35.34f, 35.36f, 35.37f, 35.38f, 35.39f, 35.40f, 35.41f, 35.42f, 35.43f, 35.44f, 35.45f, 35.46f, 35.48f, 35.49f, 35.50f, 35.51f, 35.52f, 35.53f, 35.54f, 35.55f, 35.56f, 35.57f, 35.58f, 35.59f, 35.60f, 35.61f, 35.62f, 35.64f, 35.65f, 35.66f, 35.67f, 35.68f, 35.69f, 35.70f, 35.71f, 35.72f, 35.73f, 35.74f, 35.75f, 35.76f, 35.77f, 35.78f, 35.79f, 35.80f, 35.81f, 35.82f, 35.83f, 35.84f, 35.85f, 35.86f, 35.88f, 35.89f, 35.90f, 35.91f, 35.92f, 35.93f, 35.94f, 35.95f, 35.96f, 35.97f, 35.98f, 35.99f, 36.00f, 36.01f, 36.02f, 36.03f, 36.04f, 36.05f, 36.06f, 36.07f, 36.08f, 36.09f, 36.10f, 36.11f, 36.12f, 36.13f, 36.14f, 36.15f, 36.16f, 36.17f, 36.18f, 36.19f, 36.20f, 36.21f, 36.22f, 36.23f, 36.24f, 36.25f, 36.26f, 36.27f, 36.28f, 36.29f, 36.30f, 36.31f, 36.32f, 36.33f, 36.34f, 36.35f, 36.36f, 36.37f, 36.37f, 36.38f, 36.39f, 36.40f, 36.41f, 36.42f, 36.43f, 36.44f, 36.45f, 36.46f, 36.47f, 36.48f, 36.49f, 36.50f, 36.51f, 36.52f, 36.53f, 36.54f, 36.55f, 36.56f, 36.57f, 36.58f, 36.59f, 36.60f, 36.60f, 36.61f, 36.62f, 36.63f, 36.64f, 36.65f, 36.66f, 36.67f, 36.68f, 36.69f, 36.70f, 36.71f, 36.72f, 36.73f, 36.74f, 36.75f, 36.75f, 36.76f, 36.77f, 36.78f, 36.79f, 36.80f, 36.81f, 36.82f, 36.83f, 36.84f, 36.85f, 36.86f, 36.87f, 36.87f, 36.88f, 36.89f, 36.90f, 36.91f, 36.92f, 36.93f, 36.94f, 36.95f, 36.96f, 36.97f, 36.97f, 36.98f, 36.99f, 37.00f, 37.01f, 37.02f, 37.03f, 37.04f, 37.05f, 37.06f, 37.07f, 37.07f, 37.08f, 37.09f, 37.10f, 37.11f, 37.12f, 37.13f, 37.14f, 37.15f, 37.15f, 37.16f, 37.17f, 37.18f, 37.19f, 37.20f, 37.21f, 37.22f, 37.23f, 37.23f, 37.24f, 37.25f, 37.26f, 37.27f, 37.28f, 37.29f, 37.30f, 37.30f, 37.31f, 37.32f, 37.33f, 37.34f, 37.35f, 37.36f, 37.36f, 37.37f, 37.38f, 37.39f, 37.40f, 37.41f, 37.42f, 37.43f, 37.43f, 37.44f, 37.45f, 37.46f, 37.47f, 37.48f, 37.49f, 37.49f, 37.50f, 37.51f, 37.52f, 37.53f, 37.54f, 37.54f};
    float32_t snr_mean = 0.0f;
    for (uint32_t i = 0; i < bins_num; i++)
    {
        float32_t weight = snr_weight_table[i];
        snr_mean += (float32_t)hist[i] * snr_weight_table[i];
    }

    snr_mean /= pixel_count;
    snr_mean -= 10.0f * log10f(dg + FLT_EPSILON);
    *snr = snr_mean;
}

/// RRS pipeline definitions:
///  - T0 compensation, shell be calculated based on registers for frame that we are set up ISP settings
///  - stat compensation, shell be calcualted based on registers for frame that the stats was gathered
///  - AE input sensor settings should be for the same frame that statistics that AE using

void parse_regs_from_emb_line_ar233(parameters_storage_t* storage_ctx,
                              const struct ar014x_sensor_data* sensorData,
                              uint32_t cam_num)
{
    bool input_is_ok = true;
    parse_regs_from_emb_line(storage_ctx, sensorData, cam_num);

    const ae_auto_params_table_t* table = find_table_by_id(get_global_isp_tables(), TABLES_ANALOG_GAIN_COMP);

    float32_t sixty_hertz = get_param_check(storage_ctx, ALG_SIXTY_HERTZ, &input_is_ok);
    const ae_auto_params_table_t* table_50hz = find_table_by_id(get_global_isp_tables(), TABLES_AF_50hz);
    const ae_auto_params_table_t* table_60hz = find_table_by_id(get_global_isp_tables(), TABLES_AF_60hz);
    const ae_auto_params_table_t* table_af = (sixty_hertz > 0.0f) ? table_60hz : table_50hz;

    float32_t min_exposure_antiflick = (table_af) ? get_table_value(table_af, 0.f) : 512.f;
    set_param_if_empty(storage_ctx, ISP_INTERNAL_MIN_EXPOSURE_AF, min_exposure_antiflick);


    float32_t sensor_param = get_param_check(storage_ctx, ISP_INTERNAL_EMB_LINE_ANALOG_GAIN, &input_is_ok);
    float32_t emb_g = get_param_check(storage_ctx, ISP_INTERNAL_EMB_LINE_GREEN_GAIN, &input_is_ok);
    float32_t emb_r = get_param_check(storage_ctx, ISP_INTERNAL_EMB_LINE_RED_GAIN, &input_is_ok);
    float32_t emb_b = get_param_check(storage_ctx, ISP_INTERNAL_EMB_LINE_BLUE_GAIN, &input_is_ok);
    float32_t sensor_exposure = get_param_check(storage_ctx, ISP_INTERNAL_EMB_LINE_EXPOSURE, &input_is_ok) / min_exposure_antiflick;
    float32_t dlo_gain = get_param_check(storage_ctx, ISP_INTERNAL_EMB_LINE_DLO_GAIN, &input_is_ok);
    float32_t def_gain = get_param_check(storage_ctx, AE_IN_DEF_GAIN, &input_is_ok);

    if (input_is_ok && table != NULL && def_gain > 0.f)
    {
        set_param_if_empty(storage_ctx, ISP_INTERNAL_MIN_AGAIN_COMP, get_table_value(table, 100.f));
        float32_t ms_convertion_coeff = ((float32_t)get_param(storage_ctx, EMB_LINE_LLPCK) / (float32_t)ar0233_sclk);
        set_param(storage_ctx, EXP_MS_CONVERTION, ms_convertion_coeff);

        dlo_gain/= def_gain;
        emb_g/=128.f;
        emb_r/=128.f;
        emb_b/=128.f;
        float32_t pre_hdr_gain = ISP_MIN(emb_g, emb_r);
        pre_hdr_gain = ISP_MIN(pre_hdr_gain, emb_b);
        pre_hdr_gain = ISP_MAX(pre_hdr_gain, 1.f);

        float32_t pre_hdr_comp = (pre_hdr_gain > 1.03f) ?  1.f / pre_hdr_gain : 1.f;
        float32_t cur_again = register_read_233(AE_ANALOG_GAIN, sensor_param);
        float32_t compensate_again = get_table_value(table, cur_again);
        //float32_t compensate_antiflick = (sensor_exposure > 0.f) ? ae_exposure / sensor_exposure : 1.f;
        float32_t compensate_sensor =  ((sensor_exposure*dlo_gain) > 1.f) ? 1.f / (sensor_exposure*dlo_gain) : 1.f;
        set_param_if_empty(storage_ctx, ISP_INTERNAL_T0_PREPIPE, compensate_again*pre_hdr_comp*compensate_sensor);

        isp_tracelog_v("EXP DLO PREHDR COMP %.1f %.1f %.1f %.1f\n", sensor_exposure*512, dlo_gain*512, pre_hdr_gain,  compensate_again*pre_hdr_comp*compensate_sensor);
    }
    else
        isp_tracelog_e("PRE-PIPELINE FAILURE 0x%x %.1f %.1f %.1f \n", (uint32_t)(size_t)table, sensor_exposure, emb_g, sensor_param);
}

void functions_init_ar233(sensor_operations_t* ctx)
{
#ifdef ISP_SENSOR_AR233
    ctx->fill_default_table = fill_regs_default_table;
    ctx->write_all_regs = set_all_sensor_params;
    ctx->parse_embedded_data = parse_regs_from_emb_line_ar233;
    ctx->parse_histogram = parse_histogram_233;
    ctx->calc_snr = calc_snr_ar233;
    ctx->set_default_isp_settings = set_default_isp_233;
#endif
}

static inline void write(uint8_t** ptr, uint32_t* offset, uint32_t sz, void* data)
{
    memcpy(*ptr, data, sz);
    offset[0]+=sz;
    ptr[0]+=sz;
}

static const uint_fast16_t crc_table[256] = {
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
    0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,
    0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
    0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
    0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
    0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
    0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,
    0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,
    0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
    0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
    0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,
    0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
    0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
    0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
    0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
    0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,
    0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,
    0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,
    0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
    0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
    0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,
    0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
    0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
    0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
    0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
    0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
    0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,
    0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
    0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
    0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
};

static inline uint16_t calc_crc16(const uint8_t* buffer, uint32_t len)
{
    unsigned int tbl_idx; // cppcheck-suppress variableScope
    uint_fast16_t crc = 0x1d0f;

    while (len--) {
        tbl_idx = ((crc >> 8) ^ *buffer) & 0xff;
        crc = (crc_table[tbl_idx] ^ (crc << 8)) & 0xffff;
        buffer++;
    }
    return crc & 0xffff;
}

void yuv_data_pack(uint8_t* dst, uint32_t yuv_data_out_sz, struct isp_yuvdata_with_fields* data)
{
    uint8_t buffer[YUVDATA_PACKED_BYTES / 2];
    uint8_t *ptr = buffer;
    uint32_t offset = sizeof(buffer);

    uint8_t version = 0x05;
    write(&ptr, &offset, 1, &version); /*.. header for version 5 */

    write(&ptr, &offset, 4, &data->frame_number);
    write(&ptr, &offset, 4, &data->batch_number);
    write(&ptr, &offset, 4, &data->crc32);
    write(&ptr, &offset, 4, &data->isp_sw_version);
    write(&ptr, &offset, 2, &data->exposure_time_ms);
    write(&ptr, &offset, 2, &data->sensor_gain);
    write(&ptr, &offset, 2, &data->awb_kelvin);
    write(&ptr, &offset, 2, &data->awb_tint);
    write(&ptr, &offset, 1, &data->die_temperature);
    write(&ptr, &offset, 2, &data->flags);
    write(&ptr, &offset, 2, &data->isp_gain);
    write(&ptr, &offset, 2, &data->average_brightness);
    write(&ptr, &offset, 2, &data->line_length_us);
    write(&ptr, &offset, 4, &data->lux);
    write(&ptr, &offset, 2, &data->snr);
    write(&ptr, &offset, 2, &data->awb_patches);
    write(&ptr, &offset, 2, &data->isp_gamma);
    write(&ptr, &offset, 1, &data->banding_frequency);
    write(&ptr, &offset, 2, &data->banding_correlation);
    write(&ptr, &offset, 2, &data->white_q);

    /*.. we should have space for crc-16 only */
    uint16_t crc16 = calc_crc16(buffer, sizeof(buffer) - 2);
    write(&ptr, &offset, 2, &crc16);

    /*.. pack yuvdata into nibble format */
    for (unsigned i = 0; i < sizeof(buffer); i++)
    {
        dst[2 * i + 0] = (buffer[i] << 4) & 0xF0;
        dst[2 * i + 1] = buffer[i] & 0xF0;
    }

    /*.. clear the remaining portion of the buffer */
    memset(dst + YUVDATA_PACKED_BYTES, 0, yuv_data_out_sz - YUVDATA_PACKED_BYTES);
}