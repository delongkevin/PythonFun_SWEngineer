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

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "isp_process.h"
#ifdef MAGNA_PSA
#include <pthread.h>
#define CASE_REG_ID(x, y) case x: ret=ISP_INTERNAL_##y; break;

int32_t parse_register(uint32_t reg_id)
{
    int32_t ret = -1;
    switch (reg_id)
    {
        EMB_DATA_REGISTER_LIST(CASE_REG_ID)

        default:
            break;
    }

    return ret;
}


typedef struct
{
    uint32_t reg_value;
    uint32_t reg_address;
    char reg_address_symbolic[256 - 8];
}reg_t ;

static inline bool check_tag(const uint8_t buf[], uint32_t tag_address_msb, uint32_t tag_address_lsb)
{
    bool res = false;

    if (buf != NULL)
    {
        if ((buf[1] == tag_address_msb) && (buf[4] == tag_address_lsb))
        {
            res = true;
        }
    }

    return res;
}

static inline bool check_tag_end(const uint8_t buf[], uint32_t tag_value, uint32_t tag_end)
{
    bool res = false;

    if (buf != NULL)
    {
        if (((uint8_t)buf[1] != tag_value) && ((uint8_t)buf[5] == tag_end))
        {
            res = true;
        }
    }

    return res;
}

static inline uint32_t parse_value(const uint8_t buf[])
{
    uint32_t val = 0;

    if (buf != NULL)
    {
        val = ((uint32_t)buf[3] << 12U) + ((uint32_t)buf[2] << 4U) + ((uint32_t)buf[6] << 4U) + ((uint32_t)buf[5] >> 4U);
    }

    return val;
}


static inline int32_t find_start_end_line_tags(const uint8_t buf[],
                                                   uint32_t size,
                                                   uint32_t *start_index,
                                                   uint32_t *end_index,
                                                   uint32_t tag_address_msb,
                                                   uint32_t tag_address_lsb,
                                                   uint32_t tag_value,
                                                   uint32_t tag_start_line,
                                                   uint32_t tag_end_line)
{
    int32_t err = 0;
    uint32_t i;
    int32_t start_line_tag_index = -1;
    int32_t end_line_tag_index = -1;
    bool first_base_address_found = false;
    uint32_t step = 1;

    if ((buf != NULL) && (start_index != NULL) && (end_index != NULL))
    {
        for (i = *start_index; i < size; i+=step)
        {
            if ((buf[i] == tag_start_line) && (first_base_address_found == false))
            {
                start_line_tag_index = (int32_t)i;
                first_base_address_found = check_tag((&buf[start_line_tag_index + 1]), tag_address_msb, tag_address_lsb);
                i++; /* PRQA S 2469 */
                step = 8;
            }

            if (start_line_tag_index >= 0)
            {
                if (check_tag_end(&buf[i], tag_value, tag_end_line))
                {
                    end_line_tag_index = (int32_t)i;
                    break;
                }
            }
        }

        if (i < size)
        {
            if ((start_line_tag_index < 0) ||  /* PRQA S 2996 */
                (end_line_tag_index < 0) ||
                (first_base_address_found == false)
                )
            {
                err = 1;
            }
            else
            {
                *start_index = (uint32_t)start_line_tag_index;
                *end_index = (uint32_t)end_line_tag_index;
            }
        }
        else
        {
            *end_index = size;
        }
    }
    else
    {
        err = 1;
    }



    return err;
}

void parse_regs_from_emb_line(parameters_storage_t* storage, const struct ar014x_sensor_data* sensorData, uint32_t cam_num)
{
    uint32_t i;
    uint32_t j;
    uint32_t tag_address_msb = 0xAA;
    uint32_t tag_address_lsb = 0xA5;
    uint32_t tag_value = 0x5A;
    uint32_t tag_start_line = 0xA0;
    uint32_t tag_end_line = 0x07;
    uint32_t start_line_tag_index;
    uint32_t end_line_tag_index;
    uint32_t start_index = 0;
    uint32_t end_index = 0;
    uint32_t line_size = ((AR014X_MAX_WIDTH*12)/8);
    const uint32_t MAX_EMB_LINE_NUMBER = 16;
    uint32_t size = line_size * MAX_EMB_LINE_NUMBER; /* PRQA S 2984 */

    reg_t reg_emb_line = {0};

    int32_t err = -1; /* PRQA S 2981 */
    const uint8_t* buf = (const uint8_t*) sensorData; /* PRQA S 0310 */

    if (buf != NULL)
    {
        for (j = 0; j < MAX_EMB_LINE_NUMBER; j++)
        {
            err = find_start_end_line_tags(buf,
                                        size,
                                        &start_index,
                                        &end_index,
                                        tag_address_msb,
                                        tag_address_lsb,
                                        tag_value,
                                        tag_start_line,
                                        tag_end_line);

            if ((err != 0) || (end_index >= size)) /* PRQA S 3415 */
            {
                break;
            }

            start_line_tag_index = start_index;
            end_line_tag_index = (start_index + line_size);
            start_index = line_size * (((end_index + line_size) - 1) / line_size);

            for (i = start_line_tag_index + 1; i < end_line_tag_index; i += 6)
            {
                bool register_was_found = false;
                if (check_tag(&buf[i], tag_address_msb, tag_address_lsb) == true)
                {
                    reg_emb_line.reg_address = parse_value(&buf[i]);

                    i+=6; /* PRQA S 2469 */

                    if (check_tag(&buf[i], tag_value, tag_value) == true)
                    {
                        reg_emb_line.reg_value = parse_value(&buf[i]);
                        register_was_found = true;
                    }
                }
                else
                {
                    if (check_tag(&buf[i], tag_value, tag_value) == true)
                    {
                        reg_emb_line.reg_address += 2;
                        reg_emb_line.reg_value = parse_value(&buf[i]);
                        register_was_found = true;
                    }
                }

                if (register_was_found)
                {
                    int32_t id = parse_register(reg_emb_line.reg_address);
                    if (id != -1)
                    {
                        set_param(storage, id, (float32_t)reg_emb_line.reg_value);
                    }
                }

            }
        }
    }
}
#else

// #define EMB_LINE_FULL_PARSER

/* 8 bits data aligned to 12 bits - 4 LSB are fillers by sensor */
/* same for value and addr data  */
#define TAG_ADDR_MSB    0xAA5
#define TAG_ADDR_LSB    0xA55
#define TAG_VAL         0x5A5
#define TAG_START       0x0A5
#define TAG_END         0x075

typedef uint16_t e_data_t;

#ifndef EMB_LINE_FULL_PARSER

#define MAX_SIG_LEN         10
#define MAX_REGS_TO_PARSE   41

typedef struct
{
    uint32_t offset;
    uint16_t tag;
    uint16_t value;
} record_t;

record_t ar233_4lines_signatures[4][MAX_SIG_LEN] = {
    { { 0, TAG_START }, { 1, TAG_ADDR_MSB, 0x2000 }, { 1789, TAG_END }, { 0, 0 } },
    { { 0, TAG_START }, { 1, TAG_ADDR_MSB, 0x3176 }, { 1689, TAG_END }, { 0, 0 } },
    { { 0, TAG_START }, { 1, TAG_ADDR_MSB, 0x3500 }, { 1777, TAG_END }, { 0, 0 } },
    { { 0, TAG_START }, { 1, TAG_ADDR_MSB, 0x3f4e }, { 1833, TAG_END }, { 0, 0 } },
};

record_t regs_to_parse[4][MAX_REGS_TO_PARSE] = {
    {
       {   5, TAG_VAL, 0x2000 },
       { 125, TAG_VAL, 0x2040 },
       { 129, TAG_VAL, 0x2042 },
       { 153, TAG_VAL, 0x204e },
       { 1197, TAG_VAL, 0x3002 },
       { 1205, TAG_VAL, 0x3006 },
       { 1213, TAG_VAL, 0x300a },
       { 1217, TAG_VAL, 0x300c },
       { 1221, TAG_VAL, 0x300e },
       { 1229, TAG_VAL, 0x3012 },
       { 1233, TAG_VAL, 0x3014 },
       { 1277, TAG_VAL, 0x302a },
       { 1285, TAG_VAL, 0x302e },
       { 1289, TAG_VAL, 0x3030 },
       { 1317, TAG_VAL, 0x3040 },
       { 1361, TAG_VAL, 0x3056 },
       { 1365, TAG_VAL, 0x3058 },
       { 1369, TAG_VAL, 0x305a },
       { 1405, TAG_VAL, 0x3070 },
       { 1409, TAG_VAL, 0x3072 },
       { 1413, TAG_VAL, 0x3074 },
       { 1417, TAG_VAL, 0x3076 },
       { 1421, TAG_VAL, 0x3078 },
       { 1577, TAG_VAL, 0x30c6 },
       { 1581, TAG_VAL, 0x30c8 },
       { 0, 0 }
    },
    {
       { 185, TAG_VAL, 0x31d2 },
       { 281, TAG_VAL, 0x3212 },
       { 289, TAG_VAL, 0x3216 },
       { 297, TAG_VAL, 0x321a },
       { 321, TAG_VAL, 0x3226 },
       { 661, TAG_VAL, 0x32ec },
       { 701, TAG_VAL, 0x3308 },
       { 877, TAG_VAL, 0x3362 },
       { 885, TAG_VAL, 0x3366 },
       { 893, TAG_VAL, 0x336a },
       { 905, TAG_VAL, 0x3370 },
       { 953, TAG_VAL, 0x3388 },
       { 1129, TAG_VAL, 0x33e2 },
       { 1133, TAG_VAL, 0x33e4 },
       { 0, 0 }
    },
    { { 0, 0 } },
    { { 0, 0 } },
};
#endif

#define REC_VAL(line, i) ((line[i + 1] << 4 & 0xff00) | \
                          (line[i + 3] >> 4 & 0x00ff))


#define CASE_REG_ID(x, y) case x: ret=ISP_INTERNAL_##y; break;

int32_t find_register(uint32_t reg_id)
{
    int32_t ret = -1;
    switch (reg_id)
    {
        EMB_DATA_REGISTER_LIST(CASE_REG_ID)

        default:
            break;
    }

    return ret;
}

#ifdef EMB_LINE_FULL_PARSER
static inline int32_t find_start_end_line_tags(const uint16_t *line,
                                               const uint32_t size,
                                               uint32_t *start_index,
                                               uint32_t *end_index)
{
    int32_t err = 0;
    uint32_t i;
    int32_t start_tag_index = -1;
    int32_t end_tag_index = -1;
    bool first_base_address_found = false;
    uint32_t step = 1;

    if ((line != NULL) && (start_index != NULL) && (end_index != NULL))
    {
        for (i = *start_index; i < size; i += step)
        {
            if ((line[i] == TAG_START) && (first_base_address_found == false))
            {
                start_tag_index = (int32_t)i;
                /* in next check_tag we read +3, so make sure it is safe */
                if ((start_tag_index + 3) < size)
                {
                    first_base_address_found =
                        (line[start_tag_index + 1] == TAG_ADDR_MSB) &&
                        (line[start_tag_index + 3] == TAG_ADDR_LSB);
                    /* advance to tag */
                    i++; /* PRQA S 2469 */
                    step = 2; /* now go trough tags only */
                }
                else
                {
                    i = size;
                    break;
                }
            }

            if (start_tag_index >= 0 && line[i] == TAG_END)
            {
                end_tag_index = (int32_t)i;
                break;
            }
        }

        if (i < size)
        {
            if ((start_tag_index < 0) ||  /* PRQA S 2996 */
                (end_tag_index < 0) ||
                (first_base_address_found == false)
                )
            {
                err = 1;
            }
            else
            {
                *start_index = (uint32_t)start_tag_index;
                *end_index = (uint32_t)end_tag_index;
            }
        }
        else
        {
            err = 1;
        }
    }
    else
    {
        err = 1;
    }



    return err;
}
#else
bool verify_signature(uint16_t *line, record_t *signature)
{
    int i;
    bool valid = false;
    bool eol = false;

    for (i = 0; i < MAX_SIG_LEN; i++)
    {
        record_t *rec = &signature[i];

        switch (rec->tag)
        {
            case TAG_START:
            case TAG_END:
                valid = (line[rec->offset] == rec->tag);
                break;
            case TAG_ADDR_MSB:
                valid = (rec->tag == line[rec->offset] &&
                         rec->value == REC_VAL(line, rec->offset));
                break;
            case 0:
                valid = true;
                eol = true;
                break;
            default:
                valid = false;
                eol = true;
                break;
        }

        if (valid == false || eol == true)
            break;
    }

    return !(valid == false && eol == true);
}
#endif

void parse_regs_from_emb_line(parameters_storage_t* storage,
                              const struct ar014x_sensor_data* sensorData,
                              uint32_t cam_num)
{
    uint32_t i, y;

    if (sensorData != NULL)
    {
        for (y = 0; y < 4; y++)
        {
            uint16_t *line = &sensorData->embeddedData[y * sensorData->embedded_data_width];
#ifdef EMB_LINE_FULL_PARSER
            e_data_t reg_addr, reg_val;
            uint32_t start_tag_index = 0;
            uint32_t end_tag_index = 0;
            int err = find_start_end_line_tags(line, AR0233_MAX_WIDTH,
                                               &start_tag_index, &end_tag_index);

            if (err != 0) /* PRQA S 3415 */
            {
                break;
            }
            else
            {
                isp_tracelog_sv("start_index = %d end_index = %d\n",
                         start_tag_index, end_tag_index);
            }

            for (i = start_tag_index + 1; i < end_tag_index - 4; i += 4)
            {
                bool register_parsed = false;
                if ((line[i] == TAG_ADDR_MSB) && (line[i + 2] == TAG_ADDR_LSB))
                {
                    reg_addr = REC_VAL(line, i);
                    i += 4; /* advance to next tags pair */
                    if (i >= end_tag_index - 4)
                        break;

                    if ((line[i] == TAG_VAL) && (line[i + 2] == TAG_VAL))
                    {
                        reg_val = (e_data_t)REC_VAL(line, i);
                        register_parsed = true;
                    }
                }
                else
                {
                    if ((line[i] == TAG_VAL) && (line[i + 2] == TAG_VAL))
                    {
                        reg_addr += 2;
                        reg_val = (e_data_t)REC_VAL(line, i);
                        register_parsed = true;
                    }
                }

                if (register_parsed)
                {
                    int32_t id = find_register(reg_addr);
                    if (id != -1)
                    {
                        isp_tracelog_sv("cam_num %d Emb. line reg addr = 0x%04x val = 0x%04x\n",
                             cam_num, reg_addr, reg_val);
                        set_param(storage, id, (float32_t)reg_val);
                    }
                }
            }
#else
            record_t *signature = ar233_4lines_signatures[y];
            if (verify_signature(line, signature) == false)
            {
                /* VX_PRINT(VX_ZONE_ERROR, "emb line %d parsing failed\n", y); */
                break;
            }

            for (i = 0; i < MAX_REGS_TO_PARSE; i++)
            {
                record_t *rec = &regs_to_parse[y][i];

                if (rec->tag == 0)
                    break;

                if (rec->tag == TAG_VAL && line[rec->offset] == TAG_VAL &&
                    line[rec->offset + 2] == TAG_VAL)
                {
                    int32_t id = find_register(rec->value);
                    if (id != -1)
                    {
                        isp_tracelog_sv("cam_num %d Emb. line reg addr = 0x%04x val = 0x%04x\n",
                             cam_num, rec->value, REC_VAL(line, rec->offset));
                        set_param(storage, id, (float32_t)REC_VAL(line, rec->offset));
                    }
                }
                else
                {
                    isp_tracelog_e("emb line %d parsing failed\n", y);
                    break;
                }

            }
#endif
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
