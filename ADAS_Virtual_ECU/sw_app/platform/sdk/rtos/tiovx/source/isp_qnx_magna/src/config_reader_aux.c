/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           config_reader_aux.c
 *  @brief          Functions for config reading
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

/* PRQA S 1442 ++ */
/* PRQA S 1441 ++ */
/* PRQA S 1411 ++ */
/* PRQA S 1412 ++ */
/* PRQA S 1422 ++ */
/* PRQA S 3412 ++ */
/* PRQA S 0881 ++ */
/* PRQA S 3450 ++ */
/* PRQA S 0781 ++ */
/* PRQA S 0841 ++ */
/* PRQA S 0342 ++ */
/* PRQA S 3138 ++ */
/* PRQA S 1317 ++ */
/* PRQA S 2814 ++ */
/* PRQA S 2824 ++ */
/* PRQA S 1055 ++ */
/* PRQA S 1056 ++ */
/* PRQA S 0604 ++ */
/* PRQA S 5125 ++ */
/* PRQA S 0602 ++ */

#define MAX_STRING_LENGTH 1024
#define MAX_STRING_BUFFERS 4
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "isp_process.h"

//static void parse_id(const char* line, int64_t* val, uint32_t id, uint32_t *y, uint32_t *x);

#ifdef ITEM_PROC_I
#undef ITEM_PROC_I
#endif
#ifdef ITEM_PROC_F
#undef ITEM_PROC_F
#endif
#define ITEM_PROC_I(X) {STRINGIFY(X), X},
#define ITEM_PROC_F(X) {STRINGIFY(X), X},
static const read_cfg_string_t read_cfg_string[] = {
    LIST_ISP_CFG()
    LIST_NON_ISP_CFG()

    #define ALGO_IMPL(NAME) {STRINGIFY(NAME##_IN_ENABLED), NAME##_IN_ENABLED},
    #include "algo_reg.h"

    LIST_INTERNAL_CFG()
    {"TABLE", TABLE},
};
static const uint32_t read_cfg_string_sz = sizeof(read_cfg_string) / sizeof(read_cfg_string[0]);

// typedef struct
// {
//     char buf[MAX_STRING_LENGTH];
// }string_t;



//static string_t global_buffers[MAX_STRING_BUFFERS] = {0};

const char* get_string_from_id(uint32_t id)
{
    uint32_t l = 0;
    uint32_t r = read_cfg_string_sz - 1; /* PRQA S 2984 */
    const char* ret = "";
    while (l <= r)
    {
        uint32_t middle = ((r - l) / 2) + l;
        if (read_cfg_string[middle].id == id)
        {
            ret = read_cfg_string[middle].name;
            break;
        }
        if (read_cfg_string[middle].id < id)
        {
            l = middle + 1;
        }
        else
        {
            r = middle - 1;
        }
    }

    return ret;
}

// static void split(const char in[], char separator1, char separator2, string_t arr[], uint32_t* number)
// {
//     uint32_t i;
//     uint32_t cur = 0;

//     char buf[MAX_STRING_LENGTH] = {0};
//     uint32_t buf_pos = 0;
//     for (i = 0; i < MAX_STRING_LENGTH; i++)
//     {
//         if ((in[i] != separator1) && (in[i] != separator2) && (in[i] != 0))
//         {
//             buf[buf_pos] = in[i];
//             buf_pos++;
//         }
//         else
//         {
//             if ((buf_pos != 0) && (cur < MAX_STRING_BUFFERS))
//             {
//                 buf[buf_pos] = 0;
//                 (void)strcpy(arr[cur].buf, buf);
//                 cur++;
//                 buf_pos = 0;
//             }
//         }

//         if (in[i] == 0)
//         {
//             break;
//         }
//     }

//     *number = cur;
// }

// static void parse_array(char* in, uint32_t* y, uint32_t* x)
// {
//     uint32_t n = 0;
//     split(in, '[', ']', global_buffers, &n);

//     *y = 0;

//     if (n == 2)
//     {
//         *x = (uint32_t)atoi(global_buffers[1].buf);
//     }
//     else if (n == 3)
//     {
//         *y = (uint32_t)atoi(global_buffers[1].buf);
//         *x = (uint32_t)atoi(global_buffers[2].buf);
//     }
//     else
//     {
//         *x = UINT32_MAX; /* PRQA S 1281 */
//     }


//     (void)strcpy(in, global_buffers[0].buf);
// }

// static inline uint32_t soft_compare(const char s1[], const char s2[]) /* PRQA S 3219 */
// {
//     uint32_t i1 = 0;
//     uint32_t i2 = 0;
//     uint32_t ret = 0;

//     while ((s1[i1] != '\0') && (s2[i2] != '\0'))
//     {
//         if ((s1[i1] == '.') || (s1[i1] == '_'))
//         {
//             i1++;
//         }
//         else if ((s2[i2] == '.') || (s2[i2] == '_'))
//         {
//             i2++;
//         }
//         else
//         {
//             if (s1[i1] != s2[i2])
//             {
//                 ret = i1 + 1;
//                 break;
//             }

//             i1++;
//             i2++;
//         }
//     }

//     return ret;
// }


// static inline uint32_t soft_compare_n(const char s1[], const char s2[], uint32_t n)
// {
//     uint32_t i1 = 0;
//     uint32_t i2 = 0;
//     uint32_t ret = 0;

//     while ((s1[i1] != '\0') && (s2[i2] != '\0') && (i1 < n) && (i2 < n))
//     {
//         if ((s1[i1] == '.') || (s1[i1] == '_'))
//         {
//             i1++;
//         }
//         else if ((s2[i2] == '.') || (s2[i2] == '_'))
//         {
//             i2++;
//         }
//         else
//         {
//             if (s1[i1] != s2[i2])
//             {
//                 ret = i1 + 1;
//                 break;
//             }

//             i1++;
//             i2++;
//         }
//     }

//     if (((s1[i1] != ' ') && (s1[i1] != 0) && (s1[i1] != '[')) ||
//         ((s2[i2] != ' ') && (s2[i2] != 0) && (s2[i2] != '['))
//     )
//     {
//         ret = i1 + 1;
//     }

//     return ret;
// }

// static CFG_ITEM_ID find_id(const char* name, CFG_ITEM_ID prev)
// {
//     uint32_t i;
//     CFG_ITEM_ID id = CFG_ISP_NONE;

//     if (prev != CFG_ISP_NONE)
//     {
//         uint32_t end = (uint32_t)prev + 2;
//         end = ISP_MIN(end, read_cfg_string_sz);

//         for (i = prev; i < end; i++)
//         {
//             if (soft_compare_n(name, read_cfg_string[i].name, (uint32_t)strlen(read_cfg_string[i].name)) == 0)
//             {
//                 id = read_cfg_string[i].id;
//                 break;
//             }
//         }
//     }

//     if (id == CFG_ISP_NONE)
//     {
//         for (i = 0; i < read_cfg_string_sz; i++)
//         {
//             if (soft_compare_n(name, read_cfg_string[i].name, (uint32_t)strlen(read_cfg_string[i].name)) == 0)
//             {
//                 id = read_cfg_string[i].id;
//                 break;
//             }
//         }
//     }

//     return id;
// }

// static float32_t get_float_from_str(const char buf[])
// {
//     bool bf = false;
//     float32_t ret;
//     uint32_t i;

//     for (i = 0; i < 255; i++)
//     {
//         if ((buf[i] == 0) || (bf == true))
//         {
//             break;
//         }

//         if (buf[i] == '.')
//         {
//             bf = true;
//         }
//     }

//     if (bf)
//     {
//         ret = (float32_t)atof(buf);
//     }
//     else
//     {
//         ret = (float32_t)atoi(buf);
//     }

//     return ret;

// }

// static uint32_t parse_interp_type(const char* name)
// {
//     uint32_t i;
//     uint32_t id = 0;

//     static const read_cfg_string_t interp_type_table[] = {
//         {"INTERP_LINEAR_CLAMP", INTERP_LINEAR_CLAMP },
//         {"INTERP_LINEAR_EXTRAPOLATION", INTERP_LINEAR_EXTRAPOLATION},
//         {"INTERP_NEAREST", INTERP_NEAREST}
//     };

//     for (i = 0; i < (sizeof(interp_type_table) / sizeof(interp_type_table[0])); i++)
//     {
//         if (strcmp(name, interp_type_table[i].name) == 0)
//         {
//             id = interp_type_table[i].id;
//             break;
//         }
//     }


//     return id;
// }

// static char get_word(const char in[], uint32_t* pos, char buf[MAX_STRING_LENGTH])
// {
//     uint32_t buf_pos = 0;
//     uint32_t i;
//     char sep = 0;

//     for (i = *pos; i < (MAX_STRING_LENGTH - 1); i++)
//     {
//         if ((in[i] != ',')
//             && (in[i] != ' ')
//             && (in[i] != '[')
//             && (in[i] != ']')
//             && (in[i] != 0)
//             )
//         {
//             buf[buf_pos] = in[i];
//             buf_pos++;
//         }
//         else
//         {
//             sep = in[i];
//             break;
//         }
//     }

//     for (; i < (MAX_STRING_LENGTH - 1); i++)
//     {
//         if ((in[i] != ',')
//             && (in[i] != ' ')
//             && (in[i] != '[')
//             && (in[i] != ']')
//             && (in[i] != 0)
//             )
//         {
//             break;
//         }
//     }

//     *pos = i;
//     buf[buf_pos] = 0;
//     return sep;
// }

// uint32_t get_array(const char in[], uint32_t* pos, char buf[MAX_STRING_LENGTH], float32_t float_buffer[], uint32_t float_buf_sz) /* PRQA S 3408 */
// {
//     uint32_t ret = 0;
//     uint32_t stop = false;

//     while (ever()) /* PRQA S 2740 */
//     {
//         char sep = get_word(in, pos, buf);

//         if ((sep == 0) || (buf[0] == 0))
//         {
//             ret = 0;
//             stop = true;
//         }

//         if (stop == false)
//         {
//             float32_t val = (float32_t)atof(buf);

//             if (ret < float_buf_sz)
//             {
//                 float_buffer[ret] = val;
//                 ret++;
//             }
//         }

//         if ((sep == ']') || (stop == true))
//         {
//             break;
//         }
//     }

//     return ret;
// }

// static void parse_table(const char* in, ae_auto_params_table_t* ret, string_t buffers[])
// {
//     float32_t* float_buffer1 = (float32_t*)buffers; /* PRQA S 0310 */ /* PRQA S 3305 */
//     float32_t* float_buffer2 = (float32_t*)buffers; /* PRQA S 2981 */ /* PRQA S 0310 */ /* PRQA S 3305 */
//     uint32_t float_buf_sz = (sizeof(string_t) * MAX_STRING_BUFFERS) / sizeof(float32_t);
//     float_buf_sz = float_buf_sz / 2;
//     float_buffer2 = &float_buffer1[float_buf_sz]; /* PRQA S 0491 */

//     char buf[MAX_STRING_LENGTH];
//     buf[0] = 0;
//     uint32_t pos = 0;
//     (void)get_word(in, &pos, buf);
//     (void)get_word(in, &pos, buf);
//     (void)strncpy(ret->name, buf, (ae_auto_params_table_name_sz - 1));
//     (void)get_word(in, &pos, buf);
//     ret->input = find_id(buf, 0);
//     (void)get_word(in, &pos, buf);
//     ret->control = find_id(buf, 0);
//     (void)get_word(in, &pos, buf);
//     ret->interp_type = parse_interp_type(buf);
//     (void)get_word(in, &pos, buf);
//     ret->phase = (uint32_t)atoi(buf);
//     ret->freq = 1;
//     uint32_t sz_in = get_array(in, &pos, buf, float_buffer1, float_buf_sz);
//     uint32_t sz_out = get_array(in, &pos, buf, float_buffer2, float_buf_sz);

//     if ((sz_in == 0) || (sz_out != sz_in)
//         || (ret->input == 0)
//         || (ret->control == 0)
//         || (ret->interp_type == 0)
//      )
//      {
//          isp_tracelog_e("cannot parse line %s\n", in); /* PRQA S 2743 */
//      }
//      else
//      {
//         float32_t* in = get_float_data(sz_in); /* PRQA S 3334 */
//         float32_t* out = get_float_data(sz_in);
//         ret->enable = 1;
//         ret->table_size = sz_in;
//         (void)memcpy(in, float_buffer1, sz_in * sizeof(float32_t));
//         (void)memcpy(out, float_buffer2, sz_in * sizeof(float32_t));

//         ret->in = in;
//         ret->out = out;
//         add_tuning_table(ret);
//      }

// }

// static bool parse_id_alg(const char* line, uint32_t id)
// {
//     uint32_t n = 0;
//     uint32_t i;

//     if (id != TABLE)
//     {
//         split(line, ' ', ' ', global_buffers, &n);
//     }

//     ISP_ITEM_EXTENDED type = 0;

//     if ((n == 3) || (id == TABLE))
//     {
//         type = id;

//         if (type != 0)
//         {
//             if (type == ALG_TWEAK_IP)
//             {
//                 uint32_t val = (uint32_t)atoll(global_buffers[2].buf);

//                 for (i = 0; i < MAX_CAMERAS_NUM; i++)
//                 {
//                     set_param_ui(get_parameters_storage(i), type, val);
//                 }
//             }
//             else if (type == TABLE)
//             {
//                 ae_auto_params_table_t t = {0};
//                 parse_table(line, &t, global_buffers);
//             }
//             else
//             {
//                 float32_t val = get_float_from_str(global_buffers[2].buf);

//                 for (i = 0; i < MAX_CAMERAS_NUM; i++)
//                 {
//                     set_param(get_parameters_storage(i), type, val);
//                 }
//             }
//         }
//     }

//     return type != 0;
// }


// static void parse_id(const char* line, int64_t* val, uint32_t id, uint32_t *y, uint32_t *x)
// {
//     uint32_t n = 0;
//     split(line, ' ', ' ', global_buffers, &n);

//     char buf_name[256];

//     if (n == 3)
//     {
//         (void)strcpy(buf_name, global_buffers[0].buf);
//         *val = atol(global_buffers[2].buf);
//         parse_array(buf_name, y, x);
//     }

//     isp_tracelog_v("parse_id %s    %s %d %d %d %d\n", line, buf_name, (int)*val, id, *x, *y); /* PRQA S 2743 */
// }

// uint32_t read_isp_settings_from_file(const char* path, struct ISP_config* ispcfg, isp_cfg_patch_t patch_cfg[MAX_PATCHES_NUM], bool luts)
// {
//     uint32_t ret = 0;

//     FILE* cfg_file = NULL;

//     if (path != NULL)
//     {
//         cfg_file = fopen(path, "r");
//     }

//     if (cfg_file == NULL)
//     {
//         ret = 1;
//     }
//     else
//     {
//         uint32_t counter = 0;
//         char buf[MAX_STRING_LENGTH] = {0};
//         uint32_t id = 0;

//         while (fgets(buf, sizeof(buf), cfg_file) != NULL)
//         {
//             id = find_id(buf, id);

//             if (id == 0)
//             {
//                 isp_tracelog_w("unknown parameter %s\n", buf); /* PRQA S 2743 */
//             }

//             if (id < CFG_ITEM_ID_NUM)
//             {
//                 int64_t val = 0;
//                 uint32_t y = 0;
//                 uint32_t x = 0;

//                 if (patch_cfg != NULL)
//                 {
//                     parse_id(buf, &val, id, &y, &x);
//                     if ((luts == true) || (patch_cfg[counter].x == UINT32_MAX)) /* PRQA S 1281 */
//                     {
//                         patch_cfg[counter].id = id;
//                         patch_cfg[counter].val = val;
//                         patch_cfg[counter].x = x;
//                         patch_cfg[counter].y = y;
//                         counter++;

//                         if (counter == (MAX_PATCHES_NUM - 1))
//                         {
//                             break;
//                         }
//                     }
//                 }

//                 if (ispcfg != 0)
//                 {
//                     parse_id(buf, &val, id, &y, &x);
//                     set_val_to_struct(buf, val, id, y, x, ispcfg);
//                 }
//             }
//             else
//             {
//                 (void)parse_id_alg(buf, id);
//             }
//         }

//         if (patch_cfg != 0)
//         {
//             patch_cfg[counter].id = CFG_ISP_NONE;
//         }

//         (void)fclose(cfg_file);
//     }

//     return ret;
// }

// void apply_patch_to_settings(struct ISP_config* cfg, const isp_cfg_patch_t patches[MAX_PATCHES_NUM])
// {
//     uint32_t i;

//     if (patches != NULL)
//     {
//         for (i = 0; i < MAX_PATCHES_NUM; i++)
//         {
//             if (patches[i].id == CFG_ISP_NONE)
//             {
//                 break;
//             }

//             set_val_to_struct("", patches[i].val, patches[i].id, patches[i].y, patches[i].x, cfg);
//         }
//     }
// }

void apply_patch_to_settings(struct ISP_config* cfg, const isp_cfg_patch_t patches[MAX_PATCHES_NUM])
{

}

void set_isp_val(struct ISP_config* isp_cfg, uint32_t item, float32_t val)
{
    if (item == dgCfg__Gain)
    {
        set_val_to_struct(" ", (int64_t)((val / 256.0f) * 512.0f), nsf4Cfg__gains, 0, 0, isp_cfg);
        isp_tracelog_v("nsf4Cfg__gains: %f\n", val); /* PRQA S 2743 */
    }
    else if (item == wbCfg__offset)
    {
        set_val_to_struct(" ", (int64_t)roundf(val), wbCfg__offset, 0, 0, isp_cfg);
        isp_tracelog_v("art black level: %f\n", val); /* PRQA S 2743 */
    }
    else
    {
        set_val_to_struct(" ", (int64_t)val, item, 0, 0, isp_cfg);
    }
}

void revert_patch_to_settings(const struct ISP_config* cfg_default, struct ISP_config* cfg, const isp_cfg_patch_t patches[MAX_PATCHES_NUM])
{
    uint32_t i;

    if (patches != NULL)
    {
        for (i = 0; i < MAX_PATCHES_NUM; i++)
        {
            if (patches[i].id == CFG_ISP_NONE)
            {
                break;
            }

            int64_t val = get_val_to_struct("",  patches[i].id, patches[i].y, patches[i].x, cfg_default);

            if (val != INT64_MAX)
            {
                set_val_to_struct("", val, patches[i].id, patches[i].y, patches[i].x, cfg);
            }
        }
    }
}

/* PRQA S 1442 -- */
/* PRQA S 1441 -- */
/* PRQA S 1411 -- */
/* PRQA S 1412 -- */
/* PRQA S 1422 -- */
/* PRQA S 3412 -- */
/* PRQA S 0881 -- */
/* PRQA S 3450 -- */
/* PRQA S 0781 -- */
/* PRQA S 0841 -- */
/* PRQA S 0342 -- */
/* PRQA S 3138 -- */
/* PRQA S 1317 -- */
/* PRQA S 2814 -- */
/* PRQA S 2824 -- */
/* PRQA S 1055 -- */
/* PRQA S 1056 -- */
/* PRQA S 0604 -- */
/* PRQA S 5125 -- */
/* PRQA S 0602 -- */
