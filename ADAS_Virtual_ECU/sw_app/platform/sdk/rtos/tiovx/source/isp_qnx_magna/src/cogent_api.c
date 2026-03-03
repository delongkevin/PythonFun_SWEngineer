/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           cogent_api.c
 *  @brief          Functions for ISP and Sensor adaptive configuration
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
#include <math.h>
/* #include <unistd.h> */
#include "isp_process.h"
#include "config_reader.h"
#include "registers_setup_233.h"
#include "tweak_wrapper.h"
#include "third_party/fastapprox/fastpow.h"

#define ISP_LIB_VERSION_MAJOR 4
#define ISP_LIB_VERSION_MINOR 15

#ifdef VERSION_GEN
#include "version.h"
#else
const unsigned char version_info_txt[] = "ISP_VER "STRINGIFY2(ISP_LIB_VERSION_MAJOR)"."STRINGIFY2(ISP_LIB_VERSION_MINOR)" STL                        ";
#endif

static const uint32_t isp_required_cfg_version_min = 415;
static const uint32_t isp_required_cfg_version_max = 415;

#ifdef PC_VER
#define EOK 0
#endif


#define REQ_ISP_CFG         (FLAG_ISP_DG_CFG | FLAG_ISP_LINOFF_CFG | FLAG_ISP_GAMMADL_CFG | FLAG_ISP_INVGAMMADL_CFG | \
                            FLAG_ISP_GAMMA_CFG | FLAG_ISP_SINTER_CFG | FLAG_ISP_SINTERRS_CFG | FLAG_ISP_PIPENP_CFG | \
                            FLAG_ISP_TONEMAP_CFG | FLAG_ISP_TONEMAPPREGAMMALUT_CFG | FLAG_ISP_TONEMAPPOSTGAMMALUT_CFG | \
                            FLAG_ISP_TONEMAPLOCALASYMLUT_CFG | FLAG_ISP_TONEMAP2DLUT_CFG | FLAG_ISP_DEM_CFG | FLAG_ISP_VTG_CFG | \
                            FLAG_ISP_DEMNP_CFG | FLAG_ISP_HISTSTATS_CFG | FLAG_ISP_WBSTATS_CFG | FLAG_ISP_EXPSTATS_CFG | \
                            FLAG_ISP_ROISTATS_CFG | FLAG_ISP_AFSSTATS_CFG | FLAG_ISP_UROICROP_CFG | FLAG_ISP_WB_CFG)

#define REQ_ISP_STATS       (FLAG_ISP_HISTSTATS_DATA | FLAG_ISP_EXPSTATS_DATA | FLAG_ISP_WBSTATS_DATA)

#define default_hdrmode 17
#define default_exposure 600
#define default_exposure_t2 0
#define default_exposure_t3 0
#define exposure147_t4_min 2
#define exposure147_t4_max 14


/* ### REMOVE green gain == 1.0*/
#define default_red_gain 181
#define default_green_gain 128
#define default_blue_gain 287

typedef struct
{
    ae_auto_tables_t tables;

    bool update_gamma_lut[MAX_CAMERAS_NUM];
    bool update_statistic_node_weight[MAX_CAMERAS_NUM];
    bool update_read_from_file[MAX_CAMERAS_NUM];
    bool upd_cfg_file[MAX_CAMERAS_NUM];
    bool upd_reg_table[MAX_CAMERAS_NUM];
}common_isp_parameters_t;

common_isp_parameters_t common_isp_parameters = {0};
sensor_operations_t sensor_custom_operations = {0};

static flag_isp_cfg_t parameters_flag_table[PARAMS_NUM_ALL] = {FLAG_ZERO};

static uint32_t g_isp_version = 0;
const uint32_t frame_rate_switch_delay = 10;
static uint32_t connected_cameras_counter = 0U;
static camera_frame_rate_denominator_t current_frame_rate = CAMERA_FR_DENOMINATOR_30_FPS; /* PRQA S 3218 */
static int32_t night_mode_common = 0; /* PRQA S 3218 */
static outputFrameRate_callback gOutputFrameRateCallback = NULL;


alg_history_data_t algorithm_history[MAX_CAMERAS_NUM] = {0}; /* PRQA S 0612 */

static float g_isp_log_level_static = 2.f;
float32_t* g_isp_log_level = &g_isp_log_level_static;
float32_t* g_isp_log_emb= 0;
float32_t* g_isp_log_regs= 0;
float32_t* g_isp_log_stats= 0;
float32_t* g_isp_log_to_file = 0;
float32_t* g_isp_log_cam = 0;
float32_t* g_isp_common_saturation = 0;

uint32_t g_counters[4] = {0};

uint32_t* g_isp_tweak_ip = 0;
uint32_t* g_isp_tweak_port = 0;

static struct ar014x_sensor_data ar0143_sensor_data_last2 __attribute__((unused)) = {0};



static struct ar014x_reg register_update[256] = {0};
const uint32_t register_update_sz = sizeof(register_update) / sizeof(register_update[0]);
uint32_t register_update_cur = 0;


volatile bool g_enable_frame_dump = false;
static uint32_t dump_frame_counter  __attribute__((unused)) = 0;
static uint32_t dump_internal_frame_counter __attribute__((unused)) = 0;

static uint32_t proc_frame_counter __attribute__((unused)) = 0;
volatile bool g_enable_proc_frame_dump = false;

//static uint32_t pink_sun_dg[] = {512,576,640,704,768,832,896,960,1024,1088,1152,1216,1280,1344,1408,1472,1536,1600,1664,1728,1792,1856,1920,1984,2047};
//static uint32_t pink_sun_exp[] = {20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,400,420,440,460,480,500,520,540,560,580,600,620,640,660,680,700,720,740,760,780,800,820,840,860,880,900,920,940,960,980,1000,1020,1040,1060,1080,1100,1120,1140,1160,1180,1200,1220,1240,1260,1280,1300,1320,1340,1360,1380,1400,1420,1440,1460,1480,1500,1520,1540,1560,1580,1600,1620,1640,1660,1680,1700,1720,1740,1760,1780,1800,1820,1840,1860,1880,1900,1920,1940,1960,1980,2000,2020,2040,2047};

static const uint16_t pre_post_ltm_lut[] ={0, 1024, 2048, 3072, 4096, 5120, 6144, 7168, 8192, 9216, 10240,
    11264, 12288, 13312, 14336, 15360, 16384, 17408, 18432, 19456, 20480, 21504, 22528, 23552, 24576, 25600,
    26624, 27648, 28672, 29696, 30720, 31744, 32768, 33791, 34815, 35839, 36863, 37887, 38911, 39935, 40959,
    41983, 43007, 44031, 45055, 46079, 47103, 48127, 49151, 50175, 51199, 52223, 53247, 54271, 55295, 56319,
    57343, 58367, 59391, 60415, 61439, 62463, 63487, 64511, 65535};

static uint32_t frame_ctr[4] = {0};
#ifdef _UTESTS

static bool binit = false;

#endif /* _UTESTS */


int32_t g_sensor_idx[4] = {-1,-1,-1,-1}; /* PRQA S 3218 */
struct ISP_config read_isp_conf = {0};
int32_t read_isp_conf_sensor_id = -1;

isp_cfg_patch_t read_isp_no_lut[MAX_PATCHES_NUM] = {0};

static ae_params_for_frame_t next_patches[MAX_CAMERAS_NUM] = {0};
void push_parameter(uint32_t cam_num, uint32_t id, float32_t val)
{
    if (cam_num < MAX_CAMERAS_NUM)
    {
        if (next_patches[cam_num].patches_num < MAX_AE_PATCH_SZ)
        {
            ae_one_param_t* p = &next_patches[cam_num].patches[next_patches[cam_num].patches_num];
            next_patches[cam_num].patches_num++;

            p->control = (AE_CONTROL_ITEM)id;
            p->data_f32 = val;
        }
    }
}

#ifdef ITEM_PROC
#undef ITEM_PROC
#endif
#define ITEM_PROC(X) case X: /* PRQA S 3410 */
static inline bool is_logable(uint32_t id)
{
    bool ret = true;
    switch ((int32_t)id)
    {
        NON_LOGABLE_PARAMETERS()
        ret = false;
        break;

    default:
        break;
    }

    return ret;
}


#define WHITE_LIST_MAX_ITEMS 128
typedef struct
{
    char* items[WHITE_LIST_MAX_ITEMS];
    uint32_t N;
}white_list_t;

static white_list_t white_list = {0};

void white_list_clean(white_list_t* c)
{
    uint32_t i;

    for (i = 0; i < WHITE_LIST_MAX_ITEMS; i++)
    {
        if (c->items[i])
        {
            free(c->items[i]);
            c->items[i] = NULL;
        }
    }

    c->N = 0U;
}

void white_list_parse(white_list_t* c, const char* path)
{
    white_list_clean(c);
    FILE* f = fopen(path, "r");

    if (f != NULL)
    {
        char line[128] = {0};

        bool bloop = true;
        while(bloop)
        {
            char* ret = fgets(line, sizeof(line) - 1, f);
            if (ret == 0)
            {
                bloop = false;
            }
            else
            {
                uint32_t l = strlen(ret);
                if (c->N < WHITE_LIST_MAX_ITEMS && l > 0 && l < 256)
                {
                    c->items[c->N] = calloc(1, l + 1);

                    if (c->items[c->N] != NULL)
                    {
                        memcpy(c->items[c->N], ret, l);
                        c->N++;
                    }
                }
            }

        }
    }
}

bool check_white_list(white_list_t* c,  const char* nm)
{
    bool ret = false;
    bool black = false;
    if (c->N == 0)
    {
        ret = true;
    }
    else
    {
        if (c->items[0][0] == '0')
        {
            return true;
        }

        if (c->items[0][0] == '-')
        {
            black = true;
        }

        ret = black;

        uint32_t i = (black == true) ? 1U : 0U;
        for (; i < c->N; i++)
        {
            if (strstr(nm, c->items[i]) != NULL)
            {
                ret = !black;
                break;
            }
        }
    }

    return ret;
}

static bool print_patch(const ae_params_for_frame_t* patches, uint32_t cam_num)
{
    bool bprinted = false;
    uint32_t i;
    uint32_t log_cam = (uint32_t)(*g_isp_log_cam); /* PRQA S 2814 */

    if ((log_cam == MAX_CAMERAS_NUM) || (log_cam == cam_num))
    {
        for (i = 0; i < patches->patches_num; i++) /* PRQA S 2814 */
        {
            uint32_t control = (uint32_t)patches->patches[i].control;

            if (is_logable(control) == true)
            {
                float32_t val = patches->patches[i].data_f32;
                const char* nm = get_string_from_id(control);

                if ((nm != NULL) && (nm[0] != 0)) /* PRQA S 0491 */
                {
                    if (check_white_list(&white_list, nm))
                    {
                        isp_tracelog_d("[%d] %s: %.3f\n", cam_num, nm, val); /* PRQA S 2743 */
                        bprinted = true;
                    }
                }
            }
        }

        if (bprinted == true)
        {
            isp_tracelog_d("\n"); /* PRQA S 2743 */
        }
    }

    return bprinted;
}

static inline uint32_t get_cam_num(int32_t sensorIdx)
{
    uint32_t ret = MAX_CAMERAS_NUM;

    uint32_t i;

    if (sensorIdx != -1)
    {
        for (i = 0; i < MAX_CAMERAS_NUM; i++)
        {
            if (sensorIdx == g_sensor_idx[i])
            {
                ret = i;
                break;
            }
        }
    }

    return ret;
}






static float32_t to_float(uint32_t type, uint32_t val)
{
    PARAM_TYPE t = (PARAM_TYPE)(type & 15);
    uint32_t frac = (type >> 4) & 255;
    uint32_t signsz = (type >> 12) & 255;
    float32_t fval;

    if (t == TYPE_S)
    {
        fval = convert_fixed_to_float_s(val, signsz, frac);
    }
    else if (t == TYPE_M)
    {
        fval = convert_fixed_to_float_m(val, signsz, frac);
    }
    else if (t == TYPE_U)
    {
        fval = convert_fixed_to_float_u(val, signsz, frac);
    }
    else
    {
        fval = (float32_t)val;
    }


    return fval;
}

static flag_isp_cfg_t get_usage_flag(uint32_t id)
{
    flag_isp_cfg_t ret = FLAG_ZERO;
    if (id < (sizeof(parameters_flag_table) / sizeof(parameters_flag_table[0])))
    {
        ret = parameters_flag_table[id];
    }

    if ((id < CFG_ITEM_ID_NUM) && (ret == FLAG_ZERO))
    {
        ;
        isp_tracelog_w("WARNING, parameter %s has zero update flag\n", get_string_from_id(id)); /* PRQA S 2743 */
    }

    return ret;
}

tweak_table_isp_t tweak_table_isp_create(uint32_t type, double minv, double maxv, uint32_t prec,
    uint32_t enable_bit, const char* name_tab, const char* name, uint32_t id, uint32_t x, uint32_t y, uint32_t p_next)
{
    if (id < (sizeof(parameters_flag_table) / sizeof(parameters_flag_table[0])))
    {
        parameters_flag_table[id] = (flag_isp_cfg_t)enable_bit;
    }

    tweak_table_isp_t ret = {0}; /* PRQA S 0604 */
    ret.type = type;
    ret.minv = minv;
    ret.maxv = maxv;
    ret.prec = prec;
    ret.enable_bit = (flag_isp_cfg_t)enable_bit;
    (void)strcpy(ret.name, name); /* PRQA S 2814 */
    ret.id = id;
    ret.p_next = p_next;
    ret.y = y;
    ret.x = x;

    (void)strcpy(ret.name_tab, name_tab); /* PRQA S 2814 */

    if (id < CFG_ITEM_ID_NUM)
    {
        int64_t rval =  get_val_to_struct("", id, y, x, &read_isp_conf);
        ret.val = to_float(type, (uint32_t)rval);
    }
    else
    {
        ret.val  = get_param(get_parameters_storage(0), (AE_CONTROL_ITEM)id);
    }


    return ret;
}

float32_t float_to_isp(uint32_t type, float32_t fval)
{
    PARAM_TYPE t = (PARAM_TYPE)(type & 15);
    uint32_t frac = (type >> 4) & 255;
    uint32_t signsz = (type >> 12) & 255;
    uint32_t val;

    if (t == TYPE_S)
    {
        val = convert_float_to_fixed_s(fval, signsz, frac);
    }
    else if (t == TYPE_M)
    {
        val = convert_float_to_fixed_m(fval, signsz, frac);
    }
    else if (t == TYPE_U)
    {
        val = convert_float_to_fixed_u(fval, signsz, frac);
    }
    else
    {
        val = (uint32_t)fval;
    }

    fval = (float32_t)val;
    return fval;
}


const uint8_t default_node_weight[ISP_AWB_NUM_ZONES] =
{
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};


void read_sensor_params(uint32_t cam_num, const struct ar014x_reg sensorConfig[], uint32_t num)
{
    uint32_t i;

    if (sensorConfig != NULL)
    {
        for (i = 0; i < num; i++)
        {
            uint16_t reg_val0 = sensorConfig[i].reg;
            uint16_t reg_val1 = sensorConfig[i].val;
            switch (reg_val0)
            {
                case 0x3012:
                    set_param(get_parameters_storage(cam_num), SENSOR_EXPOSURE, (float32_t)reg_val1);
                    break;
                case 0x3370:
                    set_param(get_parameters_storage(cam_num), SENSOR_DBLC_CONFIG, (float32_t)reg_val1);
                    break;
                case 0x3308:
                    set_param(get_parameters_storage(cam_num), AE_DLO_GAIN, (float32_t)reg_val1);
                    break;
                case 0x305A:
                    set_param(get_parameters_storage(cam_num), AE_RED_GAIN, (float32_t)reg_val1 / 128.0f);
                    break;
                case 0x3056:
                    set_param(get_parameters_storage(cam_num), AE_GREEN_GAIN, (float32_t)reg_val1 / 128.0f);
                    break;
                case 0x3058:
                    set_param(get_parameters_storage(cam_num), AE_BLUE_GAIN, (float32_t)reg_val1 / 128.0f);
                    break;
                case 0x3212:
                    set_param(get_parameters_storage(cam_num), EMB_LINE_AE_EXPOSURE, (float32_t)reg_val1);
                    break;
                case 0x31D2:
                    set_param(get_parameters_storage(cam_num), EMB_LINE_ISP_VERSION, convert_fixed_to_float_u(reg_val1, 4, 4));
                    break;
                case 0x3216:
                    set_param(get_parameters_storage(cam_num), EMB_LINE_SENSOR_VIRTUAL_GAIN_T0, convert_fixed_to_float_u(reg_val1, 16, 8));
                    break;
                case 0x321A:
                    set_param(get_parameters_storage(cam_num), EMB_LINE_SENSOR_VIRTUAL_GAIN_T1, convert_fixed_to_float_u(reg_val1, 16, 8));
                    break;
                default:
                    break;
            }
        }
    }
}

#ifdef USE_TWEAK


static void write_from_float(parameters_storage_t* storage, struct ISP_config* isp_config, uint32_t offset, uint32_t type, uint32_t y, uint32_t x, float32_t fval, const char* name)
{
    PARAM_TYPE t = (PARAM_TYPE)(type & 15);
    uint32_t frac = (type >> 4) & 255;
    uint32_t signsz = (type >> 12) & 255;
    uint32_t val = (uint32_t)fval;

    if (t == TYPE_S)
    {
        val = convert_float_to_fixed_s(fval, signsz, frac);
        fval = val;
    }
    else if (t == TYPE_M)
    {
        val = convert_float_to_fixed_m(fval, signsz, frac);
        fval = val;
    }
    else if (t == TYPE_U)  /* PRQA S 2004 */
    {
        val = convert_float_to_fixed_u(fval, signsz, frac);
        fval = val;
    }


    float32_t ret = get_param(storage, offset);
    set_param(storage, offset, fval);

    if (offset < CFG_ITEM_ID_NUM)
    {
        set_val_to_struct("", val, offset, y, x, isp_config);
    }

    if (ret != fval)
    {
        if (name)
        {
            isp_tracelog_i("CHANGE %s value from %.1f to %.1f\n", name, ret, fval); /* PRQA S 2743 */
        }
    }
}


static void convert_ui(tweak_table_isp_t* tweak_table_isp, void* isp_config, uint32_t cam_num)
{
    tweak_table_isp_t* p = (tweak_table_isp_t*)tweak_table_isp;
    uint32_t type = p->type;
    write_from_float(get_parameters_storage(cam_num), isp_config, p->id, type, p->y,p->x, p->val, *g_isp_log_level > 2.f ?  p->name : 0);
}

static void tweak_tool_process(uint32_t cam_num,
                    uint8_t* sensorConfig, int* numConfigItems, struct ISP_config* ispConfig)
{
    if (tweak_is_established())
    {
        uint32_t tw_tab_ui16_sz = 0;
        uint32_t tw_tab_isp_sz = 0;
        tweak_table_ui16_t* tw_tab_ui16 = tweak_get_sensor_tables(&tw_tab_ui16_sz);
        tweak_table_isp_t* tw_tab_isp = tweak_get_isp_tables(&tw_tab_isp_sz);

        bool b_sensor_changed = false;
        size_t i;
        for (i = 0; i < tw_tab_ui16_sz; i++)
        {
            uint16_t* p_upd_flags = tw_tab_ui16[i].val_upd;
            uint16_t* p_val = &tw_tab_ui16[i].val;
            uint16_t  reg_val0 = tw_tab_ui16[i].reg_val0;
            uint16_t  reg_val1 = tw_tab_ui16[i].reg_val1;

            if (p_upd_flags[cam_num] == 1)
            {
                p_upd_flags[cam_num] = 0;
                b_sensor_changed = true;

                {
                    sensorConfig[*numConfigItems].reg = reg_val0;
                    sensorConfig[*numConfigItems].val = p_val[0];
                    numConfigItems[0]++;
                }

                if (reg_val1 != 0)
                {
                    sensorConfig[*numConfigItems].reg = reg_val1;
                    sensorConfig[*numConfigItems].val = p_val[0];
                    numConfigItems[0]++;
                }
            }
        }

        for (i = 0; i < tw_tab_isp_sz; i++)
        {
            uint16_t* p_upd_flags = tw_tab_isp[i].val_upd;

            if (p_upd_flags[cam_num] == 1)
            {
                ispConfig->usageFlag |= tw_tab_isp[i].enable_bit;
                p_upd_flags[cam_num] = 0;
                convert_ui(&tw_tab_isp[i], ispConfig, cam_num);
            }
        }

        if (common_isp_parameters.upd_cfg_file[cam_num] == true)
        {
            if (cam_num == get_cam_num(read_isp_conf_sensor_id))
            {
                *ispConfig = read_isp_conf;
            }
            else
            {
                apply_patch_to_settings(ispConfig, read_isp_no_lut);
                ispConfig->usageFlag = read_isp_conf.usageFlag;
            }
        }

        if (common_isp_parameters.upd_reg_table[cam_num] == true)
        {
            for (i = 0; i < register_update_cur; i++)
            {
                uint16_t reg = register_update[i].reg;
                uint16_t val = register_update[i].val;

                if (reg != 0)
                {
                    sensorConfig[*numConfigItems].reg = reg;
                    sensorConfig[*numConfigItems].val = val;
                    numConfigItems[0]++;
                }
            }
        }

        common_isp_parameters.upd_cfg_file[cam_num] = false;
        common_isp_parameters.upd_reg_table[cam_num] = false;

        if (b_sensor_changed)
        {
            read_sensor_params(cam_num, sensorConfig, numConfigItems[0]);
        }
    }
}

int update_config(int sensorIdx, struct ISP_config* ispConfig);
int read_config_and_patches(struct ISP_config* ispConfig, isp_cfg_patch_t isp_cfg_patch[MAX_PATCHES_NUM]);
static void dump_frame(uint32_t sensor_idx, uint32_t cam_num, const char* prefix) __attribute__((unused));

static void dump_frame(uint32_t sensor_idx, uint32_t cam_num, const char* prefix)
{

}

#else
static void tweak_tool_process(uint32_t cam_num,
                    uint8_t* sensorConfig, int* numConfigItems, struct ISP_config* ispConfig)
{
}
#endif

static void day_night_mode_handling(void)
{
    uint32_t num_night_mode = 0U;

    uint32_t i;
    for (i = 0; i < connected_cameras_counter; i++)
    {
        if ((uint32_t)get_param(get_parameters_storage(i), AE_NIGHT_MODE) != 0)
        {
            num_night_mode++;
        }
    }

    int32_t err = EOK;
    camera_frame_rate_denominator_t changed_frame_rate = current_frame_rate; /* PRQA S 1442 */

    if (current_frame_rate == CAMERA_FR_DENOMINATOR_30_FPS)
    {
        if (((int32_t)num_night_mode >= ((int32_t)connected_cameras_counter - 1)) && (num_night_mode >= 1))
        {
            changed_frame_rate = CAMERA_FR_DENOMINATOR_15_FPS;
        }
    }
    else
    {
       if ((num_night_mode == (0U)))
       {
            changed_frame_rate = CAMERA_FR_DENOMINATOR_30_FPS;
       }
    }

    {
        if (changed_frame_rate == CAMERA_FR_DENOMINATOR_15_FPS)
        {
            if (night_mode_common >= 0)
            {
                night_mode_common = -1;
            }
            else
            {
                night_mode_common -= 1;
            }
        }
        if (changed_frame_rate == CAMERA_FR_DENOMINATOR_30_FPS)
        {
            if (night_mode_common <= 0)
            {
                night_mode_common = 1;
            }
            else
            {
                night_mode_common += 1;
            }
        }

        if ((uint32_t)abs(night_mode_common) < frame_rate_switch_delay)
        {
            changed_frame_rate = current_frame_rate; /* PRQA S 1442 */
        }

        uint32_t nmg = (uint32_t)get_param(get_parameters_storage(0), AE_TEST_FORCE_NM_G);

        if (nmg == 1)
        {
            changed_frame_rate = CAMERA_FR_DENOMINATOR_15_FPS;
        }
        if (nmg == 2)
        {
            changed_frame_rate = CAMERA_FR_DENOMINATOR_30_FPS;
        }

        if ((uint32_t)changed_frame_rate != current_frame_rate)
        {
            if (changed_frame_rate == CAMERA_FR_DENOMINATOR_15_FPS)
            {
                isp_tracelog_w("night mode on\n"); /* PRQA S 2743 */
            }
            if (changed_frame_rate == CAMERA_FR_DENOMINATOR_30_FPS)
            {
                isp_tracelog_w("day mode on\n"); /* PRQA S 2743 */
            }
            if (gOutputFrameRateCallback != NULL)
            {
                err = gOutputFrameRateCallback(connected_cameras_counter - 1, changed_frame_rate);
            }

            if (err == EOK)
            {
                current_frame_rate = changed_frame_rate;

                for (i = 0; i < connected_cameras_counter; i++)
                {
                    set_param(get_parameters_storage(i), AE_IN_GLOBAL_NM, (changed_frame_rate == CAMERA_FR_DENOMINATOR_15_FPS) ? 1.f : 0.f);
                }
            }
            else
            {
                isp_tracelog_e("change frame rate error, then function gOutputFrameRateCallback returns error %d\n", err); /* PRQA S 2743 */
            }
        }
    }
}

static void apply_one_param(uint32_t cam_num,
                            int32_t numConfigItems[],
                            struct ISP_config* ispConfig,
                            ae_one_param_t param,
                            bool* brgb2rgb,
                            bool* update_common_sat)
{
    parameters_storage_t* parameters_storage = get_parameters_storage(cam_num);
    set_param(parameters_storage, param.control, param.data_f32);
    ispConfig->usageFlag |= (uint64_t)get_usage_flag(param.control); /* PRQA S 2814 */

    if ((int32_t)param.control < (int32_t)CFG_ITEM_ID_NUM)
    {
        set_isp_val(ispConfig, (CFG_ITEM_ID)param.control, param.data_f32);
    }
    else
    {
        switch (param.control)
        {
            case AWB_OUT_R:
            case AWB_OUT_G:
            case AWB_OUT_B:
            case AWB_OUT_ENABLED:
            case AWB_OUT_MODE:
            case ALG_CCM_MAT_0_0:
            case ALG_CCM_MAT_0_1:
            case ALG_CCM_MAT_0_2:
            case ALG_CCM_MAT_1_0:
            case ALG_CCM_MAT_1_1:
            case ALG_CCM_MAT_1_2:
            case ALG_CCM_MAT_2_0:
            case ALG_CCM_MAT_2_1:
            case ALG_CCM_MAT_2_2:
            case CONTROLS_OUT_B_VAL:
            case CONTROLS_OUT_C_VAL:
                *brgb2rgb = true; /* PRQA S 2814 */
                break;
            case SATURATION_OUT_VAL:
                *brgb2rgb = true; /* PRQA S 2814 */
                *update_common_sat = true; /* PRQA S 2814 */
                break;
            default:
                break;
        }
    }
}

static void update_sinter_config(struct ISP_config* ispConfig,
                                alg_history_data_t* hist_data,
                                parameters_storage_t* storage)
{
    bool input_is_ok = true;
    float32_t sat_dg = 1.0f;
    uint32_t nr_table_id = (uint32_t)get_param_check(storage, TABLES_ANR_ID, &input_is_ok);
    uint16_t x_offset = (uint16_t)get_param_check(storage, wbCfg__offset, &input_is_ok);
    uint32_t black_level_residue = (uint32_t)get_param_check(storage, BLACK_LEVEL_RESIDUE, &input_is_ok);

    if (input_is_ok)
    {
        const ae_auto_params_table_t* nr_table = find_table_by_id(hist_data->ae_context.adjust_tables, nr_table_id);
        const ae_auto_params_table_t* nr_table_cfa_0 = find_table_by_id(hist_data->ae_context.adjust_tables, (uint32_t)nr_table->out[0]);
        const ae_auto_params_table_t* nr_table_cfa_1 = find_table_by_id(hist_data->ae_context.adjust_tables, (uint32_t)nr_table->out[1]);
        const ae_auto_params_table_t* nr_table_cfa_2 = find_table_by_id(hist_data->ae_context.adjust_tables, (uint32_t)nr_table->out[2]);
        const ae_auto_params_table_t* nr_table_cfa_3 = find_table_by_id(hist_data->ae_context.adjust_tables, (uint32_t)nr_table->out[3]);
        isp_tracelog_sv("nr_table ID: %u\n", nr_table_id);
        isp_tracelog_sv("Tables X ID: %u %u %u %u\n", (uint32_t)nr_table->out[0],
                                                     (uint32_t)nr_table->out[1],
                                                     (uint32_t)nr_table->out[2],
                                                     (uint32_t)nr_table->out[3]);

        for (uint32_t i = 0; i < 12; i++)
        {
            ispConfig->nsf4Cfg.tnCurve[0][i].posX = (uint16_t)ISP_MIN(roundf((nr_table_cfa_0->out[i] + x_offset + sqrtf(black_level_residue*256)) * sat_dg), 65535);
            ispConfig->nsf4Cfg.tnCurve[1][i].posX = (uint16_t)ISP_MIN(roundf((nr_table_cfa_1->out[i] + x_offset + sqrtf(black_level_residue*256)) * sat_dg), 65535);
            ispConfig->nsf4Cfg.tnCurve[2][i].posX = (uint16_t)ISP_MIN(roundf((nr_table_cfa_2->out[i] + x_offset + sqrtf(black_level_residue*256)) * sat_dg), 65535);
            ispConfig->nsf4Cfg.tnCurve[3][i].posX = (uint16_t)ISP_MIN(roundf((nr_table_cfa_3->out[i] + x_offset + sqrtf(black_level_residue*256)) * sat_dg), 65535);
        }

        uint32_t offset = TABLES_ANR_INTERP_EP_0_TEMP_1_CFA0_Y_PROFILE - TABLES_ANR_INTERP_EP_0_TEMP_1_CFA0_X_PROFILE;
        nr_table_cfa_0 = find_table_by_id(hist_data->ae_context.adjust_tables, (uint32_t)nr_table->out[0] + offset);
        nr_table_cfa_1 = find_table_by_id(hist_data->ae_context.adjust_tables, (uint32_t)nr_table->out[1] + offset);
        nr_table_cfa_2 = find_table_by_id(hist_data->ae_context.adjust_tables, (uint32_t)nr_table->out[2] + offset);
        nr_table_cfa_3 = find_table_by_id(hist_data->ae_context.adjust_tables, (uint32_t)nr_table->out[3] + offset);
        isp_tracelog_sv("Tables Y ID: %u %u %u %u\n", (uint32_t)nr_table->out[0] + offset,
                                                     (uint32_t)nr_table->out[1] + offset,
                                                     (uint32_t)nr_table->out[2] + offset,
                                                     (uint32_t)nr_table->out[3] + offset);
        uint16_t max_y = 65535;

        for (uint32_t i = 0; i < 12; i++)
        {
            ispConfig->nsf4Cfg.tnCurve[0][i].posY = (uint16_t)ISP_MIN(roundf(nr_table_cfa_0->out[i] * sat_dg), max_y);
            ispConfig->nsf4Cfg.tnCurve[1][i].posY = (uint16_t)ISP_MIN(roundf(nr_table_cfa_1->out[i] * sat_dg), max_y);
            ispConfig->nsf4Cfg.tnCurve[2][i].posY = (uint16_t)ISP_MIN(roundf(nr_table_cfa_2->out[i] * sat_dg), max_y);
            ispConfig->nsf4Cfg.tnCurve[3][i].posY = (uint16_t)ISP_MIN(roundf(nr_table_cfa_3->out[i] * sat_dg), max_y);
        }

        for (int32_t i = 1; i < 12; i++)
        {
            for (uint32_t j = 0; j < 4; j++)
            {
                float32_t dy = (float32_t)(ispConfig->nsf4Cfg.tnCurve[j][i].posY - ispConfig->nsf4Cfg.tnCurve[j][i - 1].posY);
                float32_t dx = (float32_t)(ispConfig->nsf4Cfg.tnCurve[j][i].posX - ispConfig->nsf4Cfg.tnCurve[j][i - 1].posX);

                if (dx > 0)
                {
                    ispConfig->nsf4Cfg.tnCurve[j][i - 1].slope = (uint16_t)roundf((dy / dx) * 2048);
                }
                else
                {
                    ispConfig->nsf4Cfg.tnCurve[j][i - 1].slope = 0;
                }
            }
        }

        for (uint32_t j = 0; j < 4; j++)
        {
            ispConfig->nsf4Cfg.tnCurve[j][11].slope = 0;
        }
    }

    for (uint32_t i = 0; i < 12; i++)
    {
        isp_tracelog_sv("Result X[%u]: %u %u %u %u\n", i, ispConfig->nsf4Cfg.tnCurve[0][i].posX, ispConfig->nsf4Cfg.tnCurve[1][i].posX, ispConfig->nsf4Cfg.tnCurve[2][i].posX, ispConfig->nsf4Cfg.tnCurve[3][i].posX);
        isp_tracelog_sv("Result Y[%u]: %u %u %u %u\n", i, ispConfig->nsf4Cfg.tnCurve[0][i].posY, ispConfig->nsf4Cfg.tnCurve[1][i].posY, ispConfig->nsf4Cfg.tnCurve[2][i].posY, ispConfig->nsf4Cfg.tnCurve[3][i].posY);
        isp_tracelog_sv("Result S[%u]: %u %u %u %u\n", i, ispConfig->nsf4Cfg.tnCurve[0][i].slope, ispConfig->nsf4Cfg.tnCurve[1][i].slope, ispConfig->nsf4Cfg.tnCurve[2][i].slope, ispConfig->nsf4Cfg.tnCurve[3][i].slope);
    }
}


static void update_lut(uint32_t *ltm_table, const uint16_t default_lut[65], float32_t alpha)
{
    uint32_t i = 0;
    float32_t max_value = 65535.0f;
    float32_t inv_max_value = 1.0f / 65535.0f;

    for (i = 0; i < 65; i++)
    {
        ltm_table[i] = (uint32_t)roundf(ISP_MIN(max_value, fastpow(((float32_t)default_lut[i] * inv_max_value), alpha) * max_value));
        isp_tracelog_sv("lut[%d]: %d = pow(%d, %f)\n", i, ltm_table[i], default_lut[i], alpha);
    }
}

static void update_gamma(struct ISP_config* ispConfig,
                         parameters_storage_t* storage)
{
    bool input_is_ok = true;
    float32_t gamma_value = get_param_check(storage, ISPGAIN_CONTROL_GAMMA_VALUE, &input_is_ok);

    if (input_is_ok)
    {
        uint32_t *table = &ispConfig->fwdPrcpCfg.table[0];
        update_lut(table, pre_post_ltm_lut, gamma_value);
        table = &ispConfig->revPrcpCfg.table[0];
        update_lut(table, pre_post_ltm_lut, 1.0f / gamma_value);
        ispConfig->usageFlag |= (uint64_t)FLAG_ISP_TONEMAPPREGAMMALUT_CFG;
        ispConfig->usageFlag |= (uint64_t)FLAG_ISP_TONEMAPPOSTGAMMALUT_CFG;
    }
}

static float maxv(float x, float y) {
    return x > y ? x : y;
}

static float minv(float x, float y) {
    return x < y ? x : y;
}

static inline float decomp_func(float val, float black_level, float gamma)
{
    return minv(powf(maxv(val - black_level, 0), gamma)*16, 65535.f);
}

extern const int decom_precalculated_xv[];

static void update_decomp_lut(uint32_t* lut, int32_t black_level, float32_t gamma)
{
    float cur_val = decomp_func(decom_precalculated_xv[0], black_level, gamma);
    float next_val;
    int index = 0;
    // First loop (128 iterations)
    for (int i = 0; i < 128; i+=8, index++)
    {
        next_val = decomp_func(decom_precalculated_xv[index + 1], black_level, gamma);
        float d = (next_val - cur_val) / 8.f;
        for (int k = 0; k < 8; k++)
        {
            lut[i + k] = maxv(roundf(cur_val + d*k), 0.f);
        }

        cur_val = next_val;
    }

    // Second loop (511 iterations)
    for (int i = 128; i < 639; ++i, index+=8) 
    {
        lut[i] = maxv(roundf(decomp_func(decom_precalculated_xv[index], black_level, gamma)), 0.f);
    }


    //print all
    for (int i = 0; i < 639; i++)
    {
        isp_tracelog_i("lut[%d]: %d\n", i, lut[i]);
    }
}

static void update_ltm_curve(struct ISP_config* ispConfig,
                         parameters_storage_t* storage)
{
    bool input_is_ok = true;
    float32_t curve_slope = get_param_check(storage, LTM_CONTROL_CURVE_SLOPE, &input_is_ok);

    if (input_is_ok)
    {
        uint32_t *table = &ispConfig->glbceCfg.asymLut[0];

        uint32_t i = 0U;

        float32_t as = curve_slope / 255.0f;

        for (i = 0; i < 33; i++)
        {
            float32_t x = (float32_t)i / (33.0f - 1.0f);
            int32_t y = (int32_t)roundf(((x * (as + 1) / (as + x)) * (1.0f - powf(x, 5)) + powf(x, 5)) * 65535.0f);
            y = ISP_MAX(0, ISP_MIN(y, 65535));
            table[i] = (uint32_t)y;
        }

        ispConfig->usageFlag |= (uint64_t)FLAG_ISP_TONEMAP_CFG;
    }
}

static void apply_rgb2rgb(struct ISP_config* ispConfig, const parameters_storage_t* storage, uint32_t cam_num, bool update_common_sat)
{
        bool input_is_ok = true;
        float32_t saturation = get_param_check(storage, SATURATION_OUT_VAL, &input_is_ok);
        bool saturation_enabled = get_param_check(storage, SATURATION_IN_ENABLED, &input_is_ok) > 0.5;

        if (update_common_sat)
        {
            float32_t smoothed = expf((0.1f*logf(saturation)) + (0.9f*logf(*g_isp_common_saturation))); /* PRQA S 2814 */
            set_param(get_parameters_storage(0), ALG_COMMON_SATURATION, smoothed);
            saturation = smoothed;
        }

        if (!saturation_enabled)
        {
            saturation = 100.f;
        }

        float32_t awb_r = get_param_check(storage, AWB_OUT_R, &input_is_ok);
        float32_t awb_g = get_param_check(storage, AWB_OUT_G, &input_is_ok);
        float32_t awb_b = get_param_check(storage, AWB_OUT_B, &input_is_ok);

        float32_t static_r = get_param_check(storage, AE_RED_GAIN, &input_is_ok);
        float32_t static_g = get_param_check(storage, AE_GREEN_GAIN, &input_is_ok);
        float32_t static_b = get_param_check(storage, AE_BLUE_GAIN, &input_is_ok);
        float32_t awb_mode = get_param_check(storage, AWB_IN_MODE, &input_is_ok);
        float32_t gain_gamma = get_param_check(storage, GAIN_IN_GAMMA, &input_is_ok);

        float32_t brightness = get_param_check(storage, CONTROLS_OUT_B_VAL, &input_is_ok);
        float32_t c = get_param_check(storage, CONTROLS_OUT_C_VAL, &input_is_ok);

        if ((uint32_t)get_param_check(storage, AWB_IN_ENABLED, &input_is_ok) == 0)
        {
            awb_r = awb_g = awb_b = 1.f;
        }
        else
        {
            if ((uint32_t)awb_mode == 0)
            {
                awb_r = awb_r / static_r;
                awb_g = awb_g / static_g;
                awb_b = awb_b / static_b;
            }
        }

        awb_r = powf(awb_r, gain_gamma);
        awb_g = powf(awb_g, gain_gamma);
        awb_b = powf(awb_b, gain_gamma);

        //isp_tracelog_v("cam_num %d awb gains for rgb2rgb (%.3f %.3f %.3f) brightness: %.1f contrast: %.1f saturation: %.1f\n", cam_num, awb_r, awb_g, awb_b, brightness, c, saturation); /* PRQA S 2743 */

        if (input_is_ok)
        {
            float32_t rg = awb_r / awb_g;
            float32_t bg = awb_b / awb_g;
            const float32_t weight_r = 0.299f;
            const float32_t weight_b = 0.114f;
            const float32_t weight_g = 1.f - weight_b - weight_r;

            float32_t bright_fix_green = 1.f / ((weight_r * rg) + weight_g + (weight_b * bg));

            float32_t contrast_mul = 255.f / (255.f - (2 * c));
            float32_t contrast_offset = (255.f * c) / ((2 * c) - 255.f);

            contrast_offset = clampf32(contrast_offset + brightness, -255.f, 255.f);

            float32_t sat_mat[9] = {1,0,0,0,1,0,0,0,1};
            get_saturation_matrix(sat_mat,(float32_t)saturation / 100.f);

            float32_t ccm_mat_from_cfg[9] = {0};
            ccm_mat_from_cfg[0] = get_param(storage, ALG_CCM_MAT_0_0);
            ccm_mat_from_cfg[1] = get_param(storage, ALG_CCM_MAT_0_1);
            ccm_mat_from_cfg[2] = get_param(storage, ALG_CCM_MAT_0_2);
            ccm_mat_from_cfg[3] = get_param(storage, ALG_CCM_MAT_1_0);
            ccm_mat_from_cfg[4] = get_param(storage, ALG_CCM_MAT_1_1);
            ccm_mat_from_cfg[5] = get_param(storage, ALG_CCM_MAT_1_2);
            ccm_mat_from_cfg[6] = get_param(storage, ALG_CCM_MAT_2_0);
            ccm_mat_from_cfg[7] = get_param(storage, ALG_CCM_MAT_2_1);
            ccm_mat_from_cfg[8] = get_param(storage, ALG_CCM_MAT_2_2);
            float32_t* ccm_mat = ccm_mat_from_cfg; /*(get_param(storage, ALG_AWB_CCM) == 1) ? ccm_mat_from_cfg : ccm_eye_mat;*/
            float32_t gains_mat[9];
            float32_t dst_mat[9] = {0};
            (void)memcpy(gains_mat, ccm_eye_mat, sizeof(gains_mat));


            gains_mat[0] = contrast_mul*bright_fix_green*rg;
            gains_mat[4] = contrast_mul*bright_fix_green;
            gains_mat[8] = contrast_mul*bright_fix_green*bg;

            mul33_33(dst_mat, ccm_mat, gains_mat);
            mul33_33(dst_mat, sat_mat, dst_mat);

            if (get_param(storage, DISABLE_CCM) == 1)
            {
                (void)memcpy(dst_mat, ccm_eye_mat, sizeof(gains_mat));
                contrast_offset = 0;

                if (get_param(storage, TPG_IN_VAL) != 0)
                {
                    float32_t v = get_param(storage, TPG_CCM_GAIN);
                    dst_mat[0] = v;
                    dst_mat[4] = v;
                    dst_mat[8] = v;
                }
            }

            ispConfig->ccmCfg.weights[0][0] = convert_float_to_fixed_s(dst_mat[0], 12, 8); /* PRQA S 2814 */
            ispConfig->ccmCfg.weights[0][1] = convert_float_to_fixed_s(dst_mat[1], 12, 8); /* PRQA S 2814 */
            ispConfig->ccmCfg.weights[0][2] = convert_float_to_fixed_s(dst_mat[2], 12, 8); /* PRQA S 2814 */
            ispConfig->ccmCfg.weights[1][0] = convert_float_to_fixed_s(dst_mat[3], 12, 8); /* PRQA S 2814 */
            ispConfig->ccmCfg.weights[1][1] = convert_float_to_fixed_s(dst_mat[4], 12, 8); /* PRQA S 2814 */
            ispConfig->ccmCfg.weights[1][2] = convert_float_to_fixed_s(dst_mat[5], 12, 8); /* PRQA S 2814 */
            ispConfig->ccmCfg.weights[2][0] = convert_float_to_fixed_s(dst_mat[6], 12, 8); /* PRQA S 2814 */
            ispConfig->ccmCfg.weights[2][1] = convert_float_to_fixed_s(dst_mat[7], 12, 8); /* PRQA S 2814 */
            ispConfig->ccmCfg.weights[2][2] = convert_float_to_fixed_s(dst_mat[8], 12, 8); /* PRQA S 2814 */

            ispConfig->ccmCfg.offsets[0] = convert_float_to_fixed_s(contrast_offset, 13, 11); /* PRQA S 2814 */
            ispConfig->ccmCfg.offsets[1] = convert_float_to_fixed_s(contrast_offset, 13, 11); /* PRQA S 2814 */
            ispConfig->ccmCfg.offsets[2] = convert_float_to_fixed_s(contrast_offset, 13, 11); /* PRQA S 2814 */
            ispConfig->usageFlag |= FLAG_ISP_CCM_CFG;
            isp_tracelog_sv("out ccm:\n %1.3f %1.3f %1.3f\n %1.3f %1.3f %1.3f\n %1.3f %1.3f %1.3f\n", dst_mat[0], dst_mat[1], dst_mat[2],
                                                                                         dst_mat[3], dst_mat[4], dst_mat[5],
                                                                                         dst_mat[6], dst_mat[7], dst_mat[8]);
        }

}

static void apply_new_settings(uint32_t cam_num,
                               struct ar014x_sensor_data* sensorData,
                               struct ISP_data* ispData,
                               int* numConfigItems,
                               struct ISP_config* ispConfig,
                               const ae_params_for_frame_t* patches,
                               bool* b_printed,
                               bool common_sat_update)
{
        bool rgb2rgb = false;
        bool update_common_sat = false;
        uint32_t i;

        if ((g_isp_log_cam == NULL) || ((uint32_t)(*g_isp_log_cam) == MAX_CAMERAS_NUM) || ((uint32_t)(*g_isp_log_cam) == cam_num))
        {
            *b_printed = print_patch(patches, cam_num); /* PRQA S 2824 */ /* PRQA S 2814 */
        }

        ae_one_param_t param;

        for (i = 0; i < patches->patches_num; i++) /* PRQA S 2814 */
        {
            param.control = patches->patches[i].control;
            param.data_f32 = patches->patches[i].data_f32;
            apply_one_param(cam_num, numConfigItems, ispConfig, param, &rgb2rgb, &update_common_sat);
        }

        if (common_sat_update)
        {
            rgb2rgb = true;
            update_common_sat = true;
        }

        if (rgb2rgb == true)
        {
            apply_rgb2rgb(ispConfig, get_parameters_storage(cam_num), cam_num, update_common_sat);
        }

        float32_t f0 = get_param(get_parameters_storage(cam_num), SENSOR_EXPOSURE);
        float32_t f1 = get_param(get_parameters_storage(cam_num), AE_DLO_GAIN);
        float32_t f2 = get_param(get_parameters_storage(cam_num), AE_DC_GAIN);
        float32_t f3 = get_param(get_parameters_storage(cam_num), AE_ANALOG_GAIN);
        float32_t f4 = get_param(get_parameters_storage(cam_num), SATURATION_OUT_VAL);
        float32_t f5 = get_param(get_parameters_storage(cam_num), dgCfg__Gain);  /* PRQA S 1401 */ /* PRQA S 1461 */

        if ((g_isp_log_cam == NULL) || ((uint32_t)(*g_isp_log_cam) == MAX_CAMERAS_NUM) || ((uint32_t)(*g_isp_log_cam) == cam_num))
        {
            isp_tracelog_sv("camera: %d exp gain[dlo dc analog] saturation isp_gain %.1f [%.1f %.1f %.1f] %.1f %.1f\n", cam_num, f0, f1, f2, f3, f4, f5 / 256); /* PRQA S 2743 */
        }
}

static void clear_alg_internal_parameters(uint32_t cam_num, uint32_t from)
{
    parameters_storage_t* storage = get_parameters_storage(cam_num);
    uint32_t i;

    for (i = from; i < PARAMS_NUM_ALL; i++)
    {
        set_param(storage, i, INVALID_VALUE);
    }
}

#include "algo_defaults.h"
void algorithm_controls_init(void)
{
    uint32_t i;
    for (i = 0; i < MAX_CAMERAS_NUM; i++)
    {
        parameters_storage_t* s = get_parameters_storage(i);
        algo_defaults(s);

        set_param(s, ALG_LOG_LEVEL,  2);
        set_param(s, ALG_LOG_EMB,  0);
        set_param(s, ALG_LOG_REGS,  0);
        set_param(s, ALG_LOG_STATS,  0);
        set_param(s, ALG_LOG_TO_FILE,  0);
        set_param(s, ALG_LOG_CAM,  MAX_CAMERAS_NUM);
        set_param_ui(s, ALG_TWEAK_IP,  0);
        set_param_ui(s, ALG_TWEAK_PORT,  8);
        set_param(s, ALG_COMMON_SATURATION, 100.0f);
        set_param(s, ALG_DUMP_STATISTIC,  0);
        set_param(s, ALG_LOG_TEST_NUM,  0);

        set_param(s, AE_RED_GAIN, default_red_gain / 128.f);
        set_param(s, AE_GREEN_GAIN, default_green_gain / 128.f);
        set_param(s, AE_BLUE_GAIN, default_blue_gain / 128.f);
        set_param(s, SENSOR_RED_GAIN_DEFAULT, default_red_gain / 128.f);
        set_param(s, SENSOR_GREEN_GAIN_DEFAULT, default_green_gain / 128.f);
        set_param(s, SENSOR_BLUE_GAIN_DEFAULT, default_blue_gain / 128.f);
        set_param(s, SENSOR_BLACK_LEVEL_DEFAULT, 64.f);
        set_param(s, SENSOR_LONG_EXPOSURE_THRESHOLD, 32767.f);

        set_param(s, TOOLS_DUMP_SETTINGS,  0);
    }

    g_isp_tweak_port = (uint32_t*)get_param_address(get_parameters_storage(0), ALG_TWEAK_PORT); /* PRQA S 0316 */
    g_isp_tweak_ip = (uint32_t*)get_param_address(get_parameters_storage(0), ALG_TWEAK_IP); /* PRQA S 0316 */
    g_isp_log_level = (float32_t*)get_param_address(get_parameters_storage(0), ALG_LOG_LEVEL); /* PRQA S 0316 */
    g_isp_log_emb = (float32_t*)get_param_address(get_parameters_storage(0), ALG_LOG_EMB); /* PRQA S 0316 */
    g_isp_log_regs = (float32_t*)get_param_address(get_parameters_storage(0), ALG_LOG_REGS); /* PRQA S 0316 */
    g_isp_log_stats = (float32_t*)get_param_address(get_parameters_storage(0), ALG_LOG_STATS); /* PRQA S 0316 */
    g_isp_log_to_file = (float32_t*)get_param_address(get_parameters_storage(0), ALG_LOG_TO_FILE); /* PRQA S 0316 */
    g_isp_log_cam = (float32_t*)get_param_address(get_parameters_storage(0), ALG_LOG_CAM); /* PRQA S 0316 */
    g_isp_common_saturation = (float32_t*)get_param_address(get_parameters_storage(0), ALG_COMMON_SATURATION); /* PRQA S 0316 */
}



void singletone_init(int sensorIdx, struct ISP_config* ispConfig) /* PRQA S 3673 */
{
    {
        uint32_t i;
        char text_short[32] = {0};
        uint32_t text_sz = (sizeof(version_info_txt) > (sizeof(text_short) - 1)) ? (sizeof(text_short) - 1) : sizeof(version_info_txt);
        (void)memcpy(text_short, version_info_txt, text_sz);
        (void)printf("ISP_version: %s\n", text_short);

        g_isp_version = ISP_LIB_VERSION_MAJOR*100 + ISP_LIB_VERSION_MINOR;
        isp_tracelog_i("ISP_version: %d\n",g_isp_version);

        for (i = 0; i < MAX_CAMERAS_NUM; i++)
        {
            if (g_sensor_idx[i] == -1)
            {
                break;
            }
            set_param(get_parameters_storage((uint32_t)g_sensor_idx[i]), ISP_VERSION, (float32_t)g_isp_version);
        }
    }

    {
        tweak_init(tweak_table_isp_create, &common_isp_parameters.tables);
    }

    read_isp_conf = *ispConfig; /* PRQA S 2814 */
    read_isp_conf_sensor_id = sensorIdx;



    isp_tracelog_i("start: %d\n",g_isp_version);
}

void fill_regs_default_table(uint8_t* sensorConfig, uint32_t* numConfigItems);


int32_t getInitialSensorConfig(int32_t sensorIdx, magna_camera_sensor_type_t sensorType,
                           uint8_t* sensorConfig, uint32_t* numConfigItems)
{
    isp_tracelog_e("sensorIdx: %d, sensorType: %d\n", sensorIdx, sensorType);
    uint32_t i = 0;
    int32_t ret = EOK;

    if (sensor_custom_operations.fill_default_table == NULL)
    {
        if (sensorType == MAGNA_CAMERA_SENSOR_AR0233)
        {
            functions_init_ar233(&sensor_custom_operations);
        }
        else if (sensorType == MAGNA_CAMERA_SENSOR_OX3C)
        {
            functions_init_ox3c(&sensor_custom_operations);
        }
        else
        {
            isp_tracelog_e("unsupported sensor %d\n", sensorType);
            ret = EINVAL;
        }
    }

    uint32_t cam_num = get_cam_num(sensorIdx);

    if (ret == EOK)
    {
        if (cam_num == MAX_CAMERAS_NUM)
        {
            for (i = 0; i < (sizeof(g_sensor_idx) / sizeof(g_sensor_idx[0])); i++)
            {
                if (g_sensor_idx[i] == -1)
                {
                    g_sensor_idx[i] = sensorIdx;
                    connected_cameras_counter++;
                    cam_num = i;
                    break;
                }
            }
        }
    }

    isp_tracelog_e("getInitialSensorConfig %d %d %d\n", sensorIdx, i, sensorType);

    if (ret == EOK)
    {
        if ((sensorConfig == NULL) || (numConfigItems == NULL))
        {
            ret =  EINVAL;
        }
    }

    if (ret == EOK)
    {
        if (sensor_custom_operations.fill_default_table == NULL)
        {
            ret = EINVAL;
            isp_tracelog_e("fill_default_table == NULL\n");
        }
        else
        {
            isp_tracelog_e("fill_default_table\n");
            (*sensor_custom_operations.fill_default_table)(sensorConfig, numConfigItems);
        }
    }

    return ret;
}

void init_params(const struct ISP_config* isp_config, parameters_storage_t* isp_context)
{
    uint32_t i;
    for (i = 1; i < CFG_ITEM_ID_NUM; i++)
    {
        int64_t val = get_val_to_struct("", (CFG_ITEM_ID)i, 0,0, isp_config);
        set_param(isp_context, i, (float32_t)val);
        isp_tracelog_d("param[%03d] = %d\n", i, (int)val); /* PRQA S 2743 */
    }
}

bool check_config(void)
{
    bool ret = false;


    uint32_t cfg_version = (uint32_t)get_param(get_parameters_storage(0), CFG_VERSION);

    ret = ret && !(cfg_version < isp_required_cfg_version_min);
    ret = ret && !(cfg_version > isp_required_cfg_version_max);

    return ret;
}

#ifndef MAGNA_PSA
void init_isp_roi(struct ISP_config* isp_config, parameters_storage_t* storage)
{
    bool input_is_ok = true;
    uint32_t x = (uint32_t)get_param_check(storage, ROI_X_VAL, &input_is_ok);
    uint32_t y = (uint32_t)get_param_check(storage, ROI_Y_VAL, &input_is_ok);
    uint32_t width = (uint32_t)get_param_check(storage, ROI_WIDTH_VAL, &input_is_ok);
    uint32_t height = (uint32_t)get_param_check(storage, ROI_HEIGHT_VAL, &input_is_ok);

    if (input_is_ok && width > 0 && height > 0)
    {
        uint8_t h3a_horz_block_num = 32;
        uint8_t h3a_vert_block_num = 16;
        uint32_t h3a_win_width = (uint32_t)(floorf(((float32_t)width / (float32_t)h3a_horz_block_num) / 2.0f) * 2.0f);
        uint32_t h3a_win_height = (uint32_t)(floorf(((float32_t)height / (float32_t)h3a_vert_block_num) / 2.0f) * 2.0f);
        uint32_t pos_start_x = x;
        uint32_t pos_start_y = y;

        uint32_t horzIncr = (uint32_t)(ceilf((h3a_win_width / 8.0f) / 2.0f) * 2.0f);
        uint32_t vertIncr = (uint32_t)(ceilf((h3a_win_height / 8.0f) / 2.0f) * 2.0f);
        isp_config->h3aCfg.aewbCfg.winCfg.pos.startX = pos_start_x;
        isp_config->h3aCfg.aewbCfg.winCfg.pos.startY = pos_start_y;
        isp_config->h3aCfg.aewbCfg.winCfg.width = h3a_win_width;
        isp_config->h3aCfg.aewbCfg.winCfg.height = h3a_win_height;
        isp_config->h3aCfg.aewbCfg.winCfg.horzIncr = horzIncr;
        isp_config->h3aCfg.aewbCfg.winCfg.vertIncr = vertIncr;
        isp_tracelog_i("H3A config: startX, startY, hor_block_num, ver_block_num, h3a_win_width, h3a_win_height, horzIncr, vertIncr: %d %d %d %d %d %d %d %d \n",
                        pos_start_x, pos_start_y, h3a_horz_block_num, h3a_vert_block_num, h3a_win_width, h3a_win_height, horzIncr, vertIncr);
    }
}
#endif


int getInitialIspConfig(int sensorIdx, struct ISP_config* ispConfig)
{
    isp_tracelog_i("getInitialIspConfig %d 0x%x\n", sensorIdx, (uint32_t)(size_t)ispConfig); /* PRQA S 0306 */ /* PRQA S 2743 */
#ifndef _UTESTS
    static bool binit = false;
#endif /* _UTESTS */

    int ret = EOK;

    if (binit == false)
    {
        algorithm_controls_init();
    }

    {
        uint32_t cam_num = get_cam_num(sensorIdx);


        if (sensor_custom_operations.set_default_isp_settings != NULL)
        {
            (*sensor_custom_operations.set_default_isp_settings)(cam_num, ispConfig);
        }
        else
        {
            ret = EINVAL;
            isp_tracelog_e("ERROR set_default_isp_settings == NULL\n"); /* PRQA S 2743 */
        }

        if (cam_num < MAX_CAMERAS_NUM)
        {
            init_params(ispConfig, get_parameters_storage(cam_num));
#ifndef MAGNA_PSA
            init_isp_roi(ispConfig, get_parameters_storage(cam_num));
#endif
            isp_tracelog_i("init_params\n"); /* PRQA S 2743 */
        }
        if (check_config())
        {
            isp_tracelog_e("not compatible config: min required cfg version is : %.02f\n", (isp_required_cfg_version_min / 100.f));
        }
    }

    if (binit == false)
    {
        singletone_init(sensorIdx, ispConfig);
    }

    binit = true;
    return ret;
}

uint64_t get_time_mcs(void);



static void print_sensor_out(uint32_t cam_num, uint8_t* data, uint32_t numConfigItems)
{
    uint32_t cur_length = 2;
    uint32_t read = 0;
    char text_buffer[128];

    uint32_t ll =  (g_isp_log_regs && g_isp_log_regs[0] > 0.5f) ? ISP_LOG_LEVEL_ERROR : ISP_LOG_LEVEL_DEBUG;

    while (read < numConfigItems)
    {
        uint16_t val16;
        uint16_t reg_address;
        memcpy(&val16, &data[read], sizeof(val16));
        read+= sizeof(val16);
        reg_address = val16;

        if (cur_length >= 32)
        {
            break;
        }

        if (reg_address == 0)
        {
            memcpy(&val16, &data[read], sizeof(val16));
            read+= sizeof(val16);
            cur_length = val16;
            continue;
        }
        else
        {
            char* p = text_buffer;
            int32_t n = (int32_t)sizeof(text_buffer) - 1;
            int32_t k = 0;

            k = snprintf(p, n, "[%d] sensor_write 0x%04x=[ ", cam_num,
                reg_address);
            p+=k; n-=k;

            uint32_t i;
            for (i = 0; i < cur_length; i++)
            {
                k = snprintf(p, n, "%02x ", (uint32_t)data[read + i]);
                p+=k; n-=k;
            }
            k = snprintf(p, n, "]");
            p+=k; n-=k;
            *p = 0;
            read+= cur_length;
            ISP_TRACELOG(ll, "%s\n", text_buffer);
        }
    }
}

#include "config_dump.h"

int processFrame(int sensorIdx, struct ar014x_sensor_data* sensorData, struct ISP_data* ispData,
                 uint8_t* sensorConfig, int* numConfigItems, struct ISP_config* ispConfig, tivxYuvData *yuvData)
{
    int32_t ret = EOK;
PROF_START(processFrame);

    if ((sensorData == NULL)        ||
        (ispData == NULL)           ||
        (sensorConfig == NULL)      ||
        (numConfigItems == NULL)    ||
        (ispConfig == NULL))
    {
        ret = EINVAL;
    }
    else
    {
        uint32_t sensor_arr_len = *numConfigItems;
        *numConfigItems = 0;

        uint32_t cam_num = get_cam_num(sensorIdx);

        isp_tracelog_d("[%d] processFrame\n", cam_num);

        bool bnew_settings = false;

        if (cam_num < MAX_CAMERAS_NUM)
        {
            bool bprinted = false;
            parameters_storage_t* storage = get_parameters_storage(cam_num);
            ae_params_for_frame_t patch = {0};
            clear_alg_internal_parameters(cam_num, ISP_INTERNAL_AVE_BR);

            uint32_t max_phase = get_max_phase(storage);
            uint32_t i;

            for (i = 0; i <= max_phase; i++)
            {
                isp_algorithms(cam_num, i, sensorData, ispData, &algorithm_history[cam_num], storage, &common_isp_parameters.tables, &patch);
                apply_new_settings(cam_num, sensorData, ispData, numConfigItems, ispConfig, &patch, &bprinted, false);
                bnew_settings = bnew_settings || bprinted;
            }

            apply_new_settings(cam_num, sensorData, ispData, numConfigItems, ispConfig, &next_patches[cam_num], &bprinted, true);

#ifndef MAGNA_PSA
            update_sinter_config(ispConfig, &algorithm_history[cam_num], storage);
            update_gamma(ispConfig, storage);
            update_ltm_curve(ispConfig, storage);

            float32_t black_level_residue = get_param(storage, BLACK_LEVEL_RESIDUE);
            float32_t sensor_black_level = get_param(storage, SENSOR_BLACK_LEVEL_DEFAULT);

            float32_t prev_decomp_level = get_param(storage, DECOMP_BLACK_LEVEL);
            float32_t decomp_val = sensor_black_level - black_level_residue;
            
            if (prev_decomp_level != decomp_val)
            {
                isp_tracelog_e("new decomp_black_level: %.1f\n", decomp_val); /* PRQA S 2743 */
                update_decomp_lut(ispConfig->decomp3Cfg.tableAddr, decomp_val, get_param(storage, GAIN_IN_GAMMA));
                set_param(storage, DECOMP_BLACK_LEVEL, decomp_val);
                ispConfig->usageFlag |= (uint64_t)FLAG_ISP_DECOMP3_CFG;

            }
#endif
            ispConfig->usageFlag |= (uint64_t)FLAG_ISP_NSF4_CFG;
            ispConfig->usageFlag |= (uint64_t)FLAG_ISP_WB_CFG;
            bnew_settings = bnew_settings || bprinted;
            next_patches[cam_num].patches_num = 0;
            day_night_mode_handling();
            tweak_tool_process(cam_num, sensorConfig, numConfigItems, ispConfig);
            bool sensor_change = false;

            if (sensor_custom_operations.write_all_regs)
            {
                (*sensor_custom_operations.write_all_regs)(cam_num, sensorConfig, &sensor_arr_len, &sensor_change);
                *numConfigItems = sensor_arr_len;
            }

            if (get_param(storage, TOOLS_DUMP_SETTINGS) > 0.5f)
            {
                set_param(storage, TOOLS_DUMP_SETTINGS, 0.f);
                drvISP_tivxVpaccogent_hydra3_ispConfig_dump(ispConfig);
            }

            if (sensor_change)
            {
                set_param(storage, N_FRAMES_WO_CHANGES_EXP_AGAIN, 0.f);
            }
            else
            {
                set_param(storage, N_FRAMES_WO_CHANGES_EXP_AGAIN, get_param(storage, N_FRAMES_WO_CHANGES_EXP_AGAIN) + 1.f);
            }

            if (yuvData)
            {
                struct isp_yuvdata_with_fields data = {0};

                data.isp_sw_version = get_param(storage, CFG_VERSION);
                data.frame_number = (uint32_t) get_param(storage, EMB_LINE_FRAME_COUNTER);
                data.batch_number = (uint32_t)get_param(storage, FRAME_COUNTER);
                data.exposure_time_ms = (uint16_t) (get_param(storage, EMB_LINE_EXPOSURE_OUT_VAL) * get_param(storage, EXP_MS_CONVERTION) * (1u << 6u)); /*exposure in rows*/
                data.isp_gain = (uint16_t) (get_param(storage, dgCfg__Gain) * (1u << 6u));
                data.average_brightness = (uint16_t) roundf(get_param(storage, AVE_BR) * (1u << 16u));
                data.die_temperature = (int8_t) get_param(storage, EMB_LINE_CURRENT_TEMPERATERE_OUT_VAL);
                data.line_length_us = (uint16_t) (get_param(storage, EMB_LINE_FLL_OUT_VAL) * (1u << 8u));
                data.sensor_gain = (uint16_t) (get_param(storage, EMB_LINE_DLO_GAIN_OUT_VAL) * get_param(storage, EMB_LINE_ANALOG_GAIN_OUT_VAL) * (1u << 6u));
                data.snr = (int16_t) (get_param(storage, SNR) * (1u << 6u));
                data.white_q = (uint16_t) roundf(get_param(storage, WHITE_Q) * (1u << 16u));
                data.awb_patches = (uint16_t) get_param(storage, AWB_VALID_BLOCKS);

                data.crc32 = 0; /*.. not used yet */
                data.flags = 0;
                yuv_data_pack(yuvData->data, sizeof(yuvData->data), &data);
                yuvData->valid = true;
            }

            frame_ctr[cam_num]++;
            set_param(storage, FRAME_COUNTER, frame_ctr[cam_num]);

            if (frame_ctr[0] == 16)
            {
                print_prof();
            }

            push_buffer_parameters(storage);
        }



        if ((g_isp_log_cam == NULL) || ((uint32_t)(*g_isp_log_cam) == MAX_CAMERAS_NUM) || ((uint32_t)(*g_isp_log_cam) == cam_num))
        {
            print_sensor_out(cam_num, sensorConfig, *numConfigItems);
        }
    }
PROF_END(processFrame);

    return ret;
}

int setBrightness(int sensorIdx, int32_t brightness)
{
    isp_tracelog_i("call setBrightness %d\n", brightness); /* PRQA S 2743 */
    uint32_t cam_num = get_cam_num(sensorIdx);
    push_parameter(cam_num, CONTROLS_IN_B_VAL, (float32_t)brightness);
    return EOK;
}

int setContrast(int sensorIdx, int32_t contrast)
{
    isp_tracelog_i("call setContrast %d\n", contrast); /* PRQA S 2743 */
    uint32_t cam_num = get_cam_num(sensorIdx);
    push_parameter(cam_num, CONTROLS_IN_C_VAL, (float32_t)contrast);
    return EOK;
}
int set60HzMode(int sensorIdx, bool mode)
{
    isp_tracelog_i("call set60HzMode %d\n", mode); /* PRQA S 2743 */
    uint32_t cam_num = get_cam_num(sensorIdx);
    push_parameter(cam_num, ALG_SIXTY_HERTZ, (float32_t)mode);
    return EOK;
}


int setToneMapCfgMode(int sensorIdx, int32_t tone_map_cfg_mode)
{
    isp_tracelog_i("call setToneMapCfgMode %d\n", tone_map_cfg_mode); /* PRQA S 2743 */
    return EOK;
}

int register_outputFrameRate_callback(outputFrameRate_callback func)
{
    gOutputFrameRateCallback = func;
    return EOK;
}

int setBrightnessContrastStep(int sensorIdx, uint32_t brightnessStep, uint32_t contrastStep)
{
    isp_tracelog_i("call setBrightnessContrastStep %d %d\n", brightnessStep, contrastStep); /* PRQA S 2743 */
    uint32_t cam_num = get_cam_num(sensorIdx);
    push_parameter(cam_num, CONTROLS_IN_B_STEP, (float32_t)brightnessStep);
    push_parameter(cam_num, CONTROLS_IN_C_STEP, (float32_t)contrastStep);
    return EOK;
}

int setManufacturingTestMode(int sensorIdx, v3xISP_ManufacturingTestType_t type)
{
    //isp_tracelog_i("call setManufacturingTestMode %d\n", (uint32_t)type); /* PRQA S 2743 */
    uint32_t cam_num = get_cam_num(sensorIdx);
    push_parameter(cam_num, TPG_IN_VAL, (float32_t)(uint32_t)type);
    return 0;
}

int setEE(int sensorIdx, uint32_t enable)
{
    //isp_tracelog_i("call setManufacturingTestMode %d\n", (uint32_t)type); /* PRQA S 2743 */
    uint32_t cam_num = get_cam_num(sensorIdx);
    push_parameter(cam_num, eeCfg__enable, (float32_t)enable);
    return 0;
}

void add_tuning_table(const ae_auto_params_table_t* table)
{
    uint32_t cur = common_isp_parameters.tables.ae_auto_table_num;
    if ((cur < MAX_AE_TUNABLE_PARAMETERS_SZ) && (table != NULL))
    {
        common_isp_parameters.tables.ae_auto_table[cur] = *table;
        common_isp_parameters.tables.ae_auto_table_num++;
    }
}

void reset_tuning_tables(void)
{
    common_isp_parameters.tables.ae_auto_table_num = 0;
    reset_allocator();
}

const ae_auto_tables_t* get_global_isp_tables(void)
{
    return &common_isp_parameters.tables;
}

/* PRQA S 0781 -- */
/* PRQA S 1412 -- */
/* PRQA S 1411 -- */
/* PRQA S 1441 -- */
/* PRQA S 1431 -- */
/* PRQA S 1482 -- */
/* PRQA S 3450 -- */
/* PRQA S 1317 -- */
/* PRQA S 3412 -- */
/* PRQA S 0881 -- */
/* PRQA S 3138 -- */
/* PRQA S 3206 -- */
/* PRQA S 0342 -- */
/* PRQA S 1056 -- */
/* PRQA S 1055 -- */
/* PRQA S 0604 -- */
/* PRQA S 0602 -- */
/* PRQA S 3448 -- */
/* PRQA S 3408 -- */
/* PRQA S 2850 -- */
/* PRQA S 2984 -- */
/* PRQA S 3218 -- */
/* PRQA S 3334 -- */
