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
#include <app_iss.h>
#include <app_log.h>
#include "isp_process.h"
#include "cam_tools.h"
#include "safety.h"

#include "crc32c.h"

extern  float32_t* g_isp_log_regs;

#define MAX_REGISTER_BLOCK_NUMBER 5


typedef struct
{
    int32_t storage_id_emb;
    uint32_t id;
    uint32_t reg_address;
    uint32_t offset;
    uint32_t sz;
}emb_data_parsing_table_t;

static const uint32_t ox3c_sclk = 90000U;
static const float32_t T1_T2_ratio = 0.3f;
static const float32_t T1_T3_ratio = 100.0f;

static const uint16_t exposure_addr_curr = 0x350e;
static const uint16_t exposure_addr = 0x3501;
static const uint16_t exposure_addr2 = 0x3541;
static const uint16_t exposure_addr3 = 0x35C1;
static const uint16_t wb_hcg_addr = 0x5280;
static const uint16_t wb_lcg_addr = 0x5480;
static const uint16_t wb_spd_addr = 0x5680;
static const uint16_t wb_vs_addr = 0x5880;
static const uint16_t hts_addr = 0x386e;
static const uint16_t vts_addr = 0x380e;
static const uint16_t frame_ctr_addr = 0x4620;

static const emb_data_parsing_table_t emb_data_parsing_table[] = {
    {EMB_LINE_EXPOSURE_OUT_VAL, SENSOR_EXPOSURE, exposure_addr, 9, 2},
    {EMB_LINE_WB_B_HCG, AE_BLUE_GAIN, 0x5280, 153, 2},
    {EMB_LINE_WB_GB_HCG, AE_GREEN_GAIN, 0x5282, 157, 2},
    {EMB_LINE_WB_GR_HCG, AE_GREEN_GAIN, 0x5284, 161, 2},
    {EMB_LINE_WB_R_HCG, AE_RED_GAIN, 0x5286, 165, 2},
    {EMB_LINE_WB_B_LCG, AE_BLUE_GAIN, 0x5480, 169, 2},
    {EMB_LINE_WB_GB_LCG, AE_GREEN_GAIN, 0x5482, 173, 2},
    {EMB_LINE_WB_GR_LCG, AE_GREEN_GAIN, 0x5484, 177, 2},
    {EMB_LINE_WB_R_LCG, AE_RED_GAIN, 0x5486, 181, 2},
    {EMB_LINE_WB_B_SPD, AE_BLUE_GAIN, 0x5680, 185, 2},
    {EMB_LINE_WB_GB_SPD, AE_GREEN_GAIN, 0x5682, 189, 2},
    {EMB_LINE_WB_GR_SPD, AE_GREEN_GAIN, 0x5684, 193, 2},
    {EMB_LINE_WB_R_SPD, AE_RED_GAIN, 0x5686, 197, 2},
    {EMB_LINE_WB_B_VS, AE_BLUE_GAIN, 0x5880, 201, 2},
    {EMB_LINE_WB_GB_VS, AE_GREEN_GAIN, 0x5882, 205, 2},
    {EMB_LINE_WB_GR_VS, AE_GREEN_GAIN, 0x5884, 209, 2},
    {EMB_LINE_WB_R_VS, AE_RED_GAIN, 0x5886, 213, 2},
    {EMB_LINE_FRAME_COUNTER, SENSOR_FRAME_COUNTER, 0x4620, 217, 4},
    {EMB_LINE_HTS, 0, hts_addr, 105, 2},
    {EMB_LINE_VTS, 0, vts_addr, 93, 2},
    {EMB_LINE_EXP_CUR, 0, exposure_addr_curr, 245, 2},
    {EMB_LINE_EXP_CUR_SPD, 0, 0x354e, 249, 2},
    {EMB_LINE_EXP_CUR_VS, 0, 0x35ce, 253, 2},
};

static const uint32_t emb_data_parsing_table_sz = sizeof(emb_data_parsing_table) / sizeof(emb_data_parsing_table_t);
static const uint32_t emb_data_parsing_table_sz2 = 2;

static const uint8_t  emb_version    = 0x59U;
static const uint32_t emb_crc_offset = 297U;
static const uint8_t  emb_crc_size   = 4U;

#define FAULTS_REG_NUM  3

static const uint16_t fault_latch_2               = 0x4f06;
static const uint16_t fault_latch_2_row_id        = (1 << 0);
static const uint16_t fault_latch_2_sram          = (1 << 1);
static const uint16_t fault_latch_2_sensor_timing = (1 << 4);
static const uint16_t fault_latch_2_blc1          = (1 << 5);

static const uint16_t fault_latch_1              = 0x4f07;
static const uint16_t fault_latch_1_i2c_readback = (1 << 0);
static const uint16_t fault_latch_1_blc0         = (1 << 1);
static const uint16_t fault_latch_1_fifo         = (1 << 2);
static const uint16_t fault_latch_1_sync_fifo    = (1 << 4);
static const uint16_t fault_latch_1_atpr         = (1 << 5);
static const uint16_t fault_latch_1_dtpr         = (1 << 6);
static const uint16_t fault_latch_1_column_id    = (1 << 7);

static const uint16_t fault_latch_0              = 0x4f08;
static const uint8_t  fault_latch_0_mbist        = (1 << 0);
static const uint8_t  fault_latch_0_pixel        = (1 << 1);
static const uint8_t  fault_latch_0_voltage      = (1 << 2);
static const uint8_t  fault_latch_0_pll_lock     = (1 << 3);
static const uint8_t  fault_latch_0_pll_clock    = (1 << 4);
static const uint8_t  fault_latch_0_rom_loader   = (1 << 5);
static const uint8_t  fault_latch_0_temperature  = (1 << 6);

static const uint16_t fault_2       = 0x4f09;
static const uint16_t fault_1       = 0x4f0a;
static const uint16_t fault_0       = 0x4f0b;

static const uint16_t temp_avg_reg     = 0x4d2a;
static const uint16_t temp_125         = 0x7d00; // 125C: 0x7d.00 -> -125.00C
static const uint16_t temp_n40         = 0xe800; // -40C: 0xe8.00 - 0xc0.00 = 0x28.00 -> -40.00C
static const uint16_t temp_npoint      = 0xc000;

static const uint16_t status_f         = 0x4f0f;
static const uint16_t status_f_errb    = (1 << 2);
static const uint16_t status_f_startup = (1 << 6);
static const uint16_t status_f_stream  = (1 << 5);

static const uint16_t tpm_fault        = 0x4d5b;
static const uint16_t tpm_fault_int    = (1 << 1);
static const uint16_t tpm_fault_st     = (1 << 0);
static const uint16_t tpm_fault_oor    = (1 << 3);

static const uint16_t vm_fault           = 0x45b2;
static const uint16_t vm_fault_oor_mask  = 0x7;
static const uint16_t vm_fault_bist_mask = (0x7 << 3);

static const emb_data_parsing_table_t emb_data_fault_parsing_table[] = {
    {0, 0U, fault_latch_2, 279, 1},
    {0, 0U, fault_latch_1, 281, 1},
    {0, 0U, fault_latch_0, 283, 1},
    //{0, 0U, fault_2,       285, 1},
    //{0, 0U, fault_1,       287, 1},
    //{0, 0U, fault_0,       289, 1},
    {0, 0U, status_f,      291, 1},
    {0, 0U, temp_avg_reg,  117, 2},
};
static const uint32_t emb_data_fault_parsing_table_sz = sizeof(emb_data_fault_parsing_table) / sizeof(emb_data_parsing_table_t);

typedef struct {
    uint32_t last_frame;
    int      err_num;
} fault_t;

enum err_type {
    ERR_PIXEL = 0,
    ERR_ATPR,
    ERR_UID,
    ERR_A2DSYNC,
    ERR_DTPR,
    ERR_BLC,
    ERR_EMBEDDEDDATA,
    ERR_FIFO,
    ERR_MIPI_2ECC,
    ERR_MIPI_CRC,
    ERR_MAX,
};

static fault_t errors3[4][ERR_MAX] = {0};
static uint32_t prev_frame[4] = {0};
static uint8_t  frame_counter_errors[4] = {0};
static uint8_t  emb_crc_errors[4] = {0};

static void camera_reset_helper(uint32_t cam)
{
    camera_set_for_reset(cam);
    prev_frame[cam] = 0;
    return;
}

static void handle_error3(uint32_t cam, uint32_t err, uint32_t counter)
{
    if (errors3[cam][err].last_frame == counter - 1) {
        errors3[cam][err].err_num++;
    } else {
        errors3[cam][err].err_num = 1;
    }
    errors3[cam][err].last_frame = counter;

    if (errors3[cam][err].err_num == 3) {
        errors3[cam][err].err_num = 0;
        //camera_set_for_shutdown(cam);
        camera_set_for_reset(cam);
    }
}

static inline uint8_t get_byte(const uint8_t *row, int offset)
{
    return (row[2 * offset + 1] << 8 | row[2 * offset]) >> 4;
}

uint16_t get_uint16(const uint8_t *buf, int offset)
{
    return (buf[offset + 0] | (buf[offset + 1] << 8)) & 0x0fff;
}

extern int32_t get_register_via_iss(uint32_t channel_id, uint32_t reg_addr, uint32_t *value);

static void parse_fault_reg(uint32_t cam_num, uint32_t counter, uint8_t fault_latch[FAULTS_REG_NUM], uint8_t fault_status)
{
    if (fault_latch[0] & fault_latch_0_mbist) {
        isp_tracelog_e("CAM[%d]: MBIST FAULT: reg 0x%x is 0x%x\n", cam_num, fault_latch_0, fault_latch[0]);
        camera_report_error_status(cam_num, ERRMGR_CAM_BIST, 1);
        camera_reset_helper(cam_num);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_BIST, 0);
    }

    if (fault_latch[0] & fault_latch_0_pixel) {
        isp_tracelog_e("CAM[%d]: Online pixel FAULT: reg 0x%x is 0x%x; x%d\n", cam_num, fault_latch_0, fault_latch[0], errors3[cam_num][ERR_PIXEL].err_num);
        camera_report_error_status(cam_num, ERRMGR_CAM_PIXEL, 1);
        handle_error3(cam_num, ERR_PIXEL, counter);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_PIXEL, 0);
    }

    if (fault_latch[0] & fault_latch_0_voltage) {
        isp_tracelog_e("CAM[%d]: Voltage monitor FAULT: reg 0x%x is 0x%x\n", cam_num, fault_latch_0, fault_latch[0]);

        uint32_t vm_fault_val;
        get_register_via_iss(cam_num, vm_fault, &vm_fault_val);
        if (vm_fault_val & vm_fault_bist_mask)
        {
            isp_tracelog_e("CAM[%d]: Voltage monitor Self-test Fault\n", cam_num);
            camera_report_error_status(cam_num, ERRMGR_CAM_VOLTAGE_SELFTEST, 1);
        } else {
            camera_report_error_status(cam_num, ERRMGR_CAM_VOLTAGE_SELFTEST, 0);
        }

        if (vm_fault_val & vm_fault_oor_mask)
        {
            isp_tracelog_e("CAM[%d]: Voltage monitor Out-of-Range Fault\n", cam_num);
            camera_report_error_status(cam_num, ERRMGR_CAM_VOLTAGE_OOR, 1);
        } else {
            camera_report_error_status(cam_num, ERRMGR_CAM_VOLTAGE_OOR, 0);
        }

        camera_reset_helper(cam_num);
    }

    if (fault_latch[0] & fault_latch_0_rom_loader) {
        isp_tracelog_e("CAM[%d]: ROM Loader FAULT: reg 0x%x is 0x%x\n", cam_num, fault_latch_0, fault_latch[0]);
        camera_report_error_status(cam_num, ERRMGR_CAM_ROM_LOADER, 1);
        camera_reset_helper(cam_num);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_ROM_LOADER, 0);
    }

    if (fault_latch[0] & fault_latch_0_pll_clock) {
        isp_tracelog_e("CAM[%d]: PLL clock monitor FAULT: reg 0x%x is 0x%x\n", cam_num, fault_latch_0, fault_latch[0]);
        camera_report_error_status(cam_num, ERRMGR_CAM_PLL_CLOCK, 1);
        camera_reset_helper(cam_num);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_PLL_CLOCK, 0);
    }

    if (fault_latch[0] & fault_latch_0_pll_lock) {
        isp_tracelog_e("CAM[%d]: PLL lock FAULT: reg 0x%x is 0x%x\n", cam_num, fault_latch_0, fault_latch[0]);
        camera_report_error_status(cam_num, ERRMGR_CAM_PLL_LOCK, 1);
        camera_reset_helper(cam_num);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_PLL_LOCK, 0);
    }

    if (fault_latch[0] & fault_latch_0_temperature) {
        isp_tracelog_e("CAM[%d]: Temperature sensor FAULT: reg 0x%x is 0x%x\n", cam_num, fault_latch_0, fault_latch[0]);

        uint32_t tpm_fault_val;
        get_register_via_iss(cam_num, tpm_fault, &tpm_fault_val);
        if (tpm_fault_val & tpm_fault_int)
        {
            isp_tracelog_e("CAM[%d]: Temperature sensor: Integrity check fault\n", cam_num);
            camera_report_error_status(cam_num, ERRMGR_CAM_TEMP_INTEGRITY, 1);
        } else {
            camera_report_error_status(cam_num, ERRMGR_CAM_TEMP_INTEGRITY, 0);
        }

        if (tpm_fault_val & tpm_fault_st)
        {
            isp_tracelog_e("CAM[%d]: Temperature sensor: Self-Test fault\n", cam_num);
            camera_report_error_status(cam_num, ERRMGR_CAM_TEMP_SELFTEST, 1);
        } else {
            camera_report_error_status(cam_num, ERRMGR_CAM_TEMP_SELFTEST, 0);
        }

        camera_reset_helper(cam_num);
    }

    if (fault_latch[1] & fault_latch_1_i2c_readback) {
        isp_tracelog_e("CAM[%d]: I2C Read-Back FAULT: reg 0x%x is 0x%x\n", cam_num, fault_latch_1, fault_latch[1]);
        camera_report_error_status(cam_num, ERRMGR_CAM_I2C_READBACK, 1);
        camera_reset_helper(cam_num);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_I2C_READBACK, 0);
    }

    if ((fault_latch[1] & fault_latch_1_column_id) || (fault_latch[2] & fault_latch_2_row_id)) {
        isp_tracelog_e("CAM[%d]: Column/Row ID FAULT: reg 0x%x is 0x%x; reg 0x%x is 0x%x; x%d\n",
                        cam_num, fault_latch_1, fault_latch[1], fault_latch_2, fault_latch[2], errors3[cam_num][ERR_UID].err_num);
        camera_report_error_status(cam_num, ERRMGR_CAM_UID, 1);
        handle_error3(cam_num, ERR_UID, counter);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_UID, 0);
    }

    if ((fault_latch[1] & fault_latch_1_sync_fifo) || (fault_latch[2] & fault_latch_2_sensor_timing)) {
        isp_tracelog_e("CAM[%d]: Sync FIFO/Sensor timing (analog to digital sync) FAULT: reg 0x%x is 0x%x; reg 0x%x is 0x%x\n",
                       cam_num, fault_latch_1, fault_latch[1], fault_latch_2, fault_latch[2]);
        camera_report_error_status(cam_num, ERRMGR_CAM_A2DSYNC, 1);
        handle_error3(cam_num, ERR_A2DSYNC, counter);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_A2DSYNC, 0);
    }

    if (fault_latch[1] & fault_latch_1_atpr) {
        isp_tracelog_e("CAM[%d]: ATPR FAULT: reg 0x%x is 0x%x\n", cam_num, fault_latch_1, fault_latch[1]);
        camera_report_error_status(cam_num, ERRMGR_CAM_ATPR, 1);
        handle_error3(cam_num, ERR_ATPR, counter);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_ATPR, 0);
    }

    if (fault_latch[1] & fault_latch_1_dtpr) {
        isp_tracelog_e("CAM[%d]: DTPR FAULT: reg 0x%x is 0x%x\n", cam_num, fault_latch_1, fault_latch[1]);
        camera_report_error_status(cam_num, ERRMGR_CAM_DTPR, 1);
        handle_error3(cam_num, ERR_DTPR, counter);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_DTPR, 0);
    }

    if ((fault_latch[1] & fault_latch_1_blc0) || (fault_latch[2] & fault_latch_2_blc1)) {
        isp_tracelog_e("CAM[%d]: BLC FAULT: reg 0x%x is 0x%x; reg 0x%x is 0x%x: frame %d\n",
                        cam_num, fault_latch_1, fault_latch[1], fault_latch_2, fault_latch[2], counter);
        camera_report_error_status(cam_num, ERRMGR_CAM_BLC, 1);
        handle_error3(cam_num, ERR_BLC, counter);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_BLC, 0);
    }

    if (fault_latch[1] & fault_latch_1_fifo) {
        isp_tracelog_e("CAM[%d]: Output FIFO CRC FAULT: reg 0x%x is 0x%x\n", cam_num, fault_latch_1, fault_latch[1]);
        camera_report_error_status(cam_num, ERRMGR_CAM_FIFO_CRC, 1);
        handle_error3(cam_num, ERR_FIFO, counter);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_FIFO_CRC, 0);
    }

    if (fault_latch[2] & fault_latch_2_sram) {
        isp_tracelog_e("CAM[%d]: SRAM CRC FAULT: reg 0x%x is 0x%x\n", cam_num, fault_latch_2, fault_latch[2]);
        camera_report_error_status(cam_num, ERRMGR_CAM_SRAM_CRC, 1);
        camera_reset_helper(cam_num);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_SRAM_CRC, 0);
    }

    if (!(fault_status & status_f_errb)) { // ERRB is active low
        isp_tracelog_e("CAM[%d]: ERRB pin FAULT: reg 0x%x is 0x%x\n", cam_num, fault_latch_2, fault_latch[2]);
    }

    return;
}

static int check_emb_crc(const uint8_t *data)
{
    int ret;
    uint8_t byte;

    /* Check version */
    byte = get_byte(data, 1);
    if (byte != emb_version) {
        isp_tracelog_d("Embedded data version mismatch! Is 0x%x, should be 0x%x\n", byte, emb_version);
        return -1;
    }

    /* Calculate CRC */
    uint32_t crc = crc_init();
    int lim = (emb_crc_offset - 1) / 2;
    for (int i = 0; i < lim; i++)
    {
        byte = get_byte(data, i*2 + 1);
        crc = crc_update(crc, &byte, 1);
    }
    crc = crc_finalize(crc);

    uint32_t crc_stored = 0;
    for (int k = 0; k < emb_crc_size; k++)
    {
        crc_stored |= (get_byte(data, emb_crc_offset + k*2) << k*8);
    }

    if (crc_stored == crc) {
        ret = 0;
    } else {
        ret = -1;
    }

    return ret;
}

void parse_regs_from_emb_line_ox3c(parameters_storage_t* storage_ctx,
                              const struct ar014x_sensor_data* sensorData,
                              uint32_t cam_num)
{
    parameters_storage_t* storage = (parameters_storage_t*)storage_ctx;
    uint32_t i;
    const uint8_t* raw_data = (const uint8_t*)sensorData->embeddedData;

    if (check_emb_crc(raw_data)) {
        isp_tracelog_e("CAM[%d]: Embedded data verification failed! Do not process!\n", cam_num);
        if (++emb_crc_errors[cam_num] == 3) {
            isp_tracelog_e("CAM[%d]: Embedded data verification failed! 3 times in row!\n", cam_num);
            camera_report_error_status(cam_num, ERRMGR_CAM_EMB_CRC, 1);
            camera_set_for_reset(cam_num);
        }
        return;
    } else {
        emb_crc_errors[cam_num] = 0;
        camera_report_error_status(cam_num, ERRMGR_CAM_EMB_CRC, 0);
    }

    for (i = 0; i < emb_data_parsing_table_sz; i++)
    {
        uint32_t val = 0;
        uint32_t k;
        for (k = 0; k < emb_data_parsing_table[i].sz; k++)
        {
            val<<=8;
            val |= get_byte(raw_data, emb_data_parsing_table[i].offset + k*2);
        }

        isp_tracelog_v("EMB: 0x%04x: %d\n", emb_data_parsing_table[i].reg_address, val);
        set_param(storage, emb_data_parsing_table[i].storage_id_emb, (float32_t)val);
    }


    bool input_is_ok = true;

    float32_t sixty_hertz = get_param_check(storage_ctx, ALG_SIXTY_HERTZ, &input_is_ok);
    const ae_auto_params_table_t* table_50hz = find_table_by_id(get_global_isp_tables(), TABLES_AF_50hz);
    const ae_auto_params_table_t* table_60hz = find_table_by_id(get_global_isp_tables(), TABLES_AF_60hz);
    const ae_auto_params_table_t* table_af = (sixty_hertz > 0.0f) ? table_60hz : table_50hz;

    float32_t emb_g = get_param_check(storage_ctx, EMB_LINE_WB_GB_HCG, &input_is_ok);
    float32_t emb_r = get_param_check(storage_ctx, EMB_LINE_WB_R_HCG, &input_is_ok);
    float32_t emb_b = get_param_check(storage_ctx, EMB_LINE_WB_B_HCG, &input_is_ok);
    float32_t hts = get_param_check(storage_ctx, EMB_LINE_HTS, &input_is_ok);
    float32_t vts = get_param_check(storage_ctx, EMB_LINE_VTS, &input_is_ok);
    float32_t sensor_exposure0 = get_param_check(storage_ctx, EMB_LINE_EXP_CUR, &input_is_ok);
    uint32_t id_af = (sixty_hertz > 0.0f) ? ANTI_FLICKER_60_EXP_MS_0 : ANTI_FLICKER_50_EXP_MS_0;
    float32_t min_exposure_antiflick = convert_ms2trow(get_param(storage_ctx, id_af), (uint32_t)hts, ox3c_sclk); //(table_af) ? get_table_value(table_af, 0.f) : 512.f;
    set_param_if_empty(storage_ctx, ISP_INTERNAL_MIN_EXPOSURE_AF, min_exposure_antiflick);
    float32_t sensor_exposure = sensor_exposure0 / min_exposure_antiflick;
    float32_t def_gain = get_param_check(storage_ctx, AE_IN_DEF_GAIN, &input_is_ok);

    float32_t dlo_gain = def_gain;



    float32_t exp_ms = convert_trow2ms(sensor_exposure0, (uint32_t)hts, ox3c_sclk);
    uint32_t max_exp = (uint32_t)vts - 12;
    float32_t max_exp_ms = convert_trow2ms((uint32_t)vts - 12, hts, ox3c_sclk);

    if (input_is_ok && def_gain > 0.f)
    {
        float32_t ms_convertion_coeff = ((float32_t)hts / (float32_t)ox3c_sclk);
        set_param(storage_ctx, EXP_MS_CONVERTION, ms_convertion_coeff);
        set_param(storage_ctx, SENSOR_LPD_SPD_RATIO, (exp_ms > 8.0f) ? 1.0f : 0.3f);
        set_param_if_empty(storage_ctx, ISP_INTERNAL_MIN_AGAIN_COMP, 1.f);
        set_param_if_empty(storage_ctx, ISP_INTERNAL_EMB_LINE_EXPOSURE, sensor_exposure0);
        set_param_if_empty(storage_ctx, ISP_INTERNAL_EMB_LINE_DLO_GAIN, dlo_gain);

        set_param(storage_ctx, ISP_INTERNAL_EMB_LINE_RED_GAIN, emb_r);
        set_param(storage_ctx, ISP_INTERNAL_EMB_LINE_GREEN_GAIN, emb_g);
        set_param(storage_ctx, ISP_INTERNAL_EMB_LINE_BLUE_GAIN, emb_b);


        dlo_gain/= def_gain;
        emb_g/=128.f;
        emb_r/=128.f;
        emb_b/=128.f;
        float32_t pre_hdr_gain = ISP_MIN(emb_g, emb_r);
        pre_hdr_gain = ISP_MIN(pre_hdr_gain, emb_b);
        pre_hdr_gain = ISP_MAX(pre_hdr_gain, 1.f);

        float32_t pre_hdr_comp = (pre_hdr_gain > 1.03f) ?  1.f / pre_hdr_gain : 1.f;
        float32_t compensate_sensor =  ((sensor_exposure*dlo_gain) > 1.f) ? 1.f / (sensor_exposure*dlo_gain) : 1.f;
        set_param_if_empty(storage_ctx, ISP_INTERNAL_T0_PREPIPE, pre_hdr_comp*compensate_sensor);

        isp_tracelog_v("EXPCUR DLO PREHDR COMP %.1f %.1f %.1f %.1f %.2f %.1f [%.2f %d]\n", sensor_exposure0, dlo_gain*512, pre_hdr_gain,  pre_hdr_comp*compensate_sensor
            , exp_ms, hts, max_exp_ms, max_exp);
    }
    else
        isp_tracelog_e("PRE-PIPELINE FAILURE %.1f %.1f \n", sensor_exposure, emb_g);

    uint32_t frame_counter = 0U;
    {
        uint32_t k;
        for (k = 0; k < 4; k++)
        {
            frame_counter <<= 8;
            frame_counter |= get_byte(raw_data, 217 + k*2);
        }
        /*
         * We sometimes see frame counter anomalies right after application start
         * (probably due to ISP initialization).
         * Let's ignore it in the beginning then.
         */
        //isp_tracelog_e("frame_counter[%d]: frame counter is 0x%x\n", cam_num, frame_counter);
        if ((prev_frame[cam_num] && prev_frame[cam_num] != frame_counter - 1) && (frame_counter > 100)) {
            if (++frame_counter_errors[cam_num] == 3) {
                isp_tracelog_e("frame_counter[%d] is %d: prev frame counter is %d\n", cam_num, frame_counter, prev_frame[cam_num]);
                frame_counter_errors[cam_num] = 0;
                camera_report_error_status(cam_num, ERRMGR_CAM_FRAME_COUNTER, 1);
                camera_set_for_reset(cam_num);
            }
        } else {
            frame_counter_errors[cam_num] = 0;
            camera_report_error_status(cam_num, ERRMGR_CAM_FRAME_COUNTER, 0);
        }

        prev_frame[cam_num] = frame_counter;

        /*
         * To be verified:
         * For some reason first frame after reboot may contain lots of errors.
         * As some of them require 'reboot' action we are going into infinite loop
         */
        if (frame_counter == 0) return;
    }

    uint8_t fault_latch[FAULTS_REG_NUM];
    uint8_t fault_status;
    /* Parse fault status */
    for (i = 0; i < emb_data_fault_parsing_table_sz; i++)
    {
        uint32_t val = 0;
        uint32_t k;
        for (k = 0; k < emb_data_fault_parsing_table[i].sz; k++)
        {
            val<<=8;
            val |= get_byte(raw_data, emb_data_fault_parsing_table[i].offset + k*2);
        }

        switch (emb_data_fault_parsing_table[i].reg_address)
        {
        case temp_avg_reg:
            if (((val >= temp_125) && (val < temp_npoint)) || (val > temp_n40))
            {
                isp_tracelog_e("CAM[%d]: Temperature sensor: Out-of-Range fault (0x%x)\n", cam_num, val);
                camera_report_error_status(cam_num, ERRMGR_CAM_TEMP_OOR, 1);
                camera_reset_helper(cam_num);
            } else {
                camera_report_error_status(cam_num, ERRMGR_CAM_TEMP_OOR, 0);
            }
            break;
        case fault_latch_0:
            fault_latch[0] = val;
            break;
        case fault_latch_1:
            fault_latch[1] = val;
            break;
        case fault_latch_2:
            fault_latch[2] = val;
            break;
        case status_f:
            fault_status = val;
            break;
        default:
            break;
        }
    }
    parse_fault_reg(cam_num, frame_counter, fault_latch, fault_status);
}


typedef float32_t (*register_read_f)(uint32_t id, float32_t vf);
static float32_t register_read(uint32_t id, float32_t vf)
{
    float32_t ret = 0.f;
    uint32_t v = (uint32_t)vf;
    ret = vf;

    return ret;
}



static uint16_t register_write(const parameters_storage_t* storage, uint32_t id, float32_t v)
{
    uint32_t reg_val = (uint32_t) v;
    uint32_t ret = (uint32_t)v;
    switch (id)
    {
    case AE_GREEN_GAIN:
    case AE_BLUE_GAIN:
    case AE_RED_GAIN:
    {
        float32_t pre_hdr_gain = get_param(storage, SENSOR_PRE_HDR_GAIN);

        float32_t sensor_param_g = get_param(storage, AE_GREEN_GAIN);
        float32_t sensor_param_r = get_param(storage, AE_RED_GAIN);
        float32_t sensor_param_b = get_param(storage, AE_BLUE_GAIN);

        float32_t max_awb_gain = ISP_MAX(ISP_MAX(sensor_param_r, sensor_param_b), sensor_param_g);
        float32_t max_pre_hdr_gain = ISP_MIN(pre_hdr_gain * max_awb_gain, 15.9921875f);
        pre_hdr_gain = max_pre_hdr_gain / max_awb_gain;
        v = 128.f * pre_hdr_gain * v;
        v = floorf(v + 0.5f);
        break;
    }

    default:
        ret = (uint32_t) v;
        break;
    }

    return (uint16_t)ret;
}


static inline void write_uint16(uint8_t* arr, uint32_t* pos, uint32_t* cur_sz, uint32_t limit, uint16_t address, uint16_t val, int32_t* err)
{
    if (cur_sz[0] != 2)
    {
        cur_sz[0] = 2;
        write_uint16_to_array(arr, pos, limit, 0, err);
        write_uint16_to_array(arr, pos, limit, cur_sz[0], err);
    }
    write_uint16_to_array(arr, pos, limit, address, err);
    write_uint16_to_array_be(arr, pos, limit, val, err);
}

static inline void write_wb(uint8_t* arr, uint32_t* pos, uint32_t* cur_sz, uint32_t limit, uint16_t address, uint16_t val[4], int32_t* err)
{
    if (cur_sz[0] != 8)
    {
        cur_sz[0] = 8;
        write_uint16_to_array(arr, pos, limit, 0, err);
        write_uint16_to_array(arr, pos, limit, cur_sz[0], err);
    }

    write_uint16_to_array(arr, pos, limit, address, err);
    write_uint16_to_array_be(arr, pos, limit, val[0], err);
    write_uint16_to_array_be(arr, pos, limit, val[1], err);
    write_uint16_to_array_be(arr, pos, limit, val[2], err);
    write_uint16_to_array_be(arr, pos, limit, val[3], err);
}

static inline uint8_t get_tpg_reg_val(int32_t tpg_mode)
{
    switch (tpg_mode)
    {
        case ISP_MANUFACTURING_SOLID_WHITE:
            return 0x01;
        case ISP_MANUFACTURING_SOLID_BLACK:
            return 0x01;
        case ISP_MANUFACTURING_SOLID_RED:
            return 0x01;
        case ISP_MANUFACTURING_SOLID_GREEN:
            return 0x01;
        case ISP_MANUFACTURING_SOLID_BLUE:
            return 0x01;
        case ISP_MANUFACTURING_COLOR_BAR:
            return 0x01;
        case ISP_MANUFACTURING_COLOR_BAR_GRADIENT:
            return 0x11;
        default:
            break;
    }
    return 0x0f;
}
static inline void write_tpg(uint8_t* arr, uint32_t* pos, uint32_t* cur_sz, uint32_t limit, int32_t tpg_mode, int32_t* err)
{

    uint8_t hcg_isp_processing = (tpg_mode) ? 0x1f : 0x1e;
    uint8_t tpg_pattern_mode = get_tpg_reg_val(tpg_mode);
    uint8_t tpg_5004[4] = {hcg_isp_processing,hcg_isp_processing,hcg_isp_processing,hcg_isp_processing};
    uint8_t tpg_5000 = 0x8f;

    write_new_size(arr, pos, limit, cur_sz, 1, err);
    write_uint16_to_array(arr, pos, limit, 0x5000, err);
    write_uint8_arr(arr, pos, limit, &tpg_5000, 1, err);

    write_new_size(arr, pos, limit, cur_sz, 4, err);
    write_uint16_to_array(arr, pos, limit, 0x5004, err);
    write_uint8_arr(arr, pos, limit, tpg_5004, 4, err);

    write_new_size(arr, pos, limit, cur_sz, 1, err);

    write_uint16_to_array(arr, pos, limit, 0x5240, err);
    write_uint8_arr(arr, pos, limit, &tpg_pattern_mode, 1, err);
    write_uint16_to_array(arr, pos, limit, 0x5440, err);
    write_uint8_arr(arr, pos, limit, &tpg_pattern_mode, 1, err);
    write_uint16_to_array(arr, pos, limit, 0x5640, err);
    write_uint8_arr(arr, pos, limit, &tpg_pattern_mode, 1, err);
    write_uint16_to_array(arr, pos, limit, 0x5840, err);
    write_uint8_arr(arr, pos, limit, &tpg_pattern_mode, 1, err);
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
    uint32_t emb_sensor_params_sz = emb_data_parsing_table_sz;
    uint32_t written = 0;
    uint32_t latest_sz = 2;
    uint32_t limit = numConfigItems[0];

    int32_t err = EOK;

    if (write)
    {
        bool TPG_mode_is_ok = true;
        int32_t TPG_mode = (int32_t)get_param_check(parameters_storage, ISP_INTERNAL_TPG_VAL, &TPG_mode_is_ok);
        if (TPG_mode_is_ok)
        {
            isp_tracelog_e("TPG mode is %d\n", TPG_mode);
            write_tpg(sensorConfig, &written, &latest_sz, limit, TPG_mode, &err);

            if (TPG_mode)
            {
                set_param(parameters_storage, AE_GREEN_GAIN, 1.0f);
                set_param(parameters_storage, AE_RED_GAIN, 1.0f);
                set_param(parameters_storage, AE_BLUE_GAIN, 1.0f);
            }
        }

        {
            float32_t exposure_emb = get_param_check(parameters_storage, EMB_LINE_EXPOSURE_OUT_VAL, &input_is_ok);
            float32_t exposure_storage = get_param_check(parameters_storage, SENSOR_EXPOSURE, &input_is_ok);
            float32_t hts = get_param_check(parameters_storage, EMB_LINE_HTS, &input_is_ok);
            float32_t vts = get_param_check(parameters_storage, EMB_LINE_VTS, &input_is_ok);

            float32_t exp_ms = convert_trow2ms(exposure_storage, (uint32_t)hts, ox3c_sclk);
            uint32_t max_exp = (uint32_t)vts - 12;
            float32_t max_exp_ms = convert_trow2ms((uint32_t)vts - 12, hts, ox3c_sclk);

            float32_t t2_ratio = (exp_ms > 8.0f) ? 1.0f : 0.3f;
            float32_t exposure_t2 = exposure_storage / t2_ratio;
            float32_t exposure_t3 = exposure_storage / 100.3f;
            exposure_t3 = clampf32(exposure_t3, 1.f, 35.f);
            exposure_t2 = clampf32(exposure_t2, 1.0f, max_exp);
            exposure_storage = clampf32(exposure_storage, 0.0f, max_exp);


            check_val = (fabsf(exposure_emb - exposure_storage) > epsilon) ? true : false;

            if (check_val == true)
            {
                write_uint16(sensorConfig, &written, &latest_sz, limit, exposure_addr, (uint16_t)exposure_storage, &err);
                write_uint16(sensorConfig, &written, &latest_sz, limit, exposure_addr2, (uint16_t)exposure_t2, &err);
                write_uint16(sensorConfig, &written, &latest_sz, limit, exposure_addr3, (uint16_t)exposure_t3, &err);
                isp_tracelog_v("exposure is %.1f %.1f %.1f\n", exposure_storage, exposure_t2, exposure_t3);
            }
        }


        float32_t pre_hdr_gain = get_param(parameters_storage, SENSOR_PRE_HDR_GAIN);
        float32_t sensor_param_g = get_param(parameters_storage, AE_GREEN_GAIN);
        float32_t sensor_param_r = get_param(parameters_storage, AE_RED_GAIN);
        float32_t sensor_param_b = get_param(parameters_storage, AE_BLUE_GAIN);
        float32_t max_awb_gain = ISP_MAX(ISP_MAX(sensor_param_r, sensor_param_b), sensor_param_g);
        float32_t max_pre_hdr_gain = ISP_MIN(pre_hdr_gain * max_awb_gain, 15.9921875f);
        pre_hdr_gain = max_pre_hdr_gain / max_awb_gain;
        sensor_param_g = floorf(1024.f*pre_hdr_gain*sensor_param_g + 0.5f);
        sensor_param_r = floorf(1024.f*pre_hdr_gain*sensor_param_r + 0.5f);
        sensor_param_b = floorf(1024.f*pre_hdr_gain*sensor_param_b + 0.5f);

        int32_t awb_ids[4] = {EMB_LINE_WB_B_HCG, EMB_LINE_WB_B_LCG, EMB_LINE_WB_B_SPD, EMB_LINE_WB_B_VS};
        uint16_t awb_regs[4] = {wb_hcg_addr, wb_lcg_addr, wb_spd_addr, wb_vs_addr};

        for (i = 0; i < 4; i++)
        {
            float32_t wb_emb0 = get_param_check(parameters_storage, awb_ids[i] + 0, &input_is_ok);
            float32_t wb_emb1 = get_param_check(parameters_storage, awb_ids[i] + 1, &input_is_ok);
            float32_t wb_emb2 = get_param_check(parameters_storage, awb_ids[i] + 2, &input_is_ok);
            float32_t wb_emb3 = get_param_check(parameters_storage, awb_ids[i] + 3, &input_is_ok);

            bool check_val0 = (fabsf(wb_emb0 - sensor_param_b) > epsilon) ? true : false;
            bool check_val1 = (fabsf(wb_emb1 - sensor_param_g) > epsilon) ? true : false;
            bool check_val2 = (fabsf(wb_emb2 - sensor_param_g) > epsilon) ? true : false;
            bool check_val3 = (fabsf(wb_emb3 - sensor_param_r) > epsilon) ? true : false;

            if (check_val0 || check_val1 || check_val2 || check_val3)
            {
                uint16_t awb_arr[4] = {(uint16_t)sensor_param_b, (uint16_t)sensor_param_g, (uint16_t)sensor_param_g, (uint16_t)sensor_param_r};
                write_wb(sensorConfig, &written, &latest_sz, limit, awb_regs[i], awb_arr, &err);
            }
        }
    }

    numConfigItems[0] = written;
}


#define REGS_TABLE(IMPL) \
    IMPL(0x3508, 0x0f, 0x80)\



#define REGS_IMPL_VARS(NAME, ...) \
    uint8_t reg_##NAME[] = {__VA_ARGS__};

#define REGS_IMPL_ARR(NAME, ...) \
    reg_##NAME,

#define REGS_IMPL_ARR_SZ(NAME, ...) \
    sizeof(reg_##NAME),

#define REGS_IMPL_ARR_ADDR(NAME, ...) \
    NAME,



static void fill_regs_default_table(uint8_t* sensorConfig, uint32_t* numConfigItems)
{
#if 0
    REGS_TABLE(REGS_IMPL_VARS)
    uint8_t* all_regs[] = {
        REGS_TABLE(REGS_IMPL_ARR)
    };
    uint8_t all_regs_sz[] = {
        REGS_TABLE(REGS_IMPL_ARR_SZ)
    };

    uint16_t all_regs_address[] = {
        REGS_TABLE(REGS_IMPL_ARR_ADDR)
    };

    uint32_t num = sizeof(all_regs_sz);


    int32_t err = EOK;
    uint32_t written = 0;
    uint32_t array_limit = *numConfigItems;
    uint32_t prev_sz = 2;

    uint32_t i;
    for (i = 0; i <  num; i++)
    {
        uint32_t sz = all_regs_sz[i];

        if (sz != prev_sz)
        {
            write_uint16_to_array(sensorConfig, &written, array_limit, 0, &err);
            write_uint16_to_array(sensorConfig, &written, array_limit, sz, &err);
            prev_sz = sz;
        }

        write_uint16_to_array(sensorConfig, &written, array_limit, all_regs_address[i], &err);
        write_uint8_arr(sensorConfig, &written, array_limit, all_regs[i], sz, &err);
    }

    *numConfigItems = (int32_t)written;
#else
    *numConfigItems = 0;
#endif
}

static void calc_snr_ox3c(const uint32_t hist[512], uint32_t pixel_count, uint32_t bins_num, float dg, float* snr)
{
    static const float32_t snr_weight_table[] = {-25.76, -25.76, -25.76, -25.76, -25.76, -25.76, -25.76, -25.76, -25.76, -25.76, -25.76, -25.76, -25.76, -25.76, -25.76, -25.76, 12.06, 12.06, 12.69, 12.69, 12.69, 13.3, 13.3, 13.3, 13.88, 13.88, 13.88, 13.88, 14.43, 14.43, 14.43, 14.97, 14.97, 14.97, 14.97, 14.97, 15.48, 15.48, 15.48, 15.48, 15.98, 15.98, 15.98, 15.98, 15.98, 16.46, 16.46, 16.46, 16.46, 16.46, 16.92, 16.92, 16.92, 16.92, 16.92, 17.37, 17.37, 17.37, 17.37, 17.37, 17.37, 17.81, 17.81, 17.81, 17.81, 17.81, 17.81, 17.81, 18.23, 18.23, 18.23, 18.23, 18.23, 18.23, 18.23, 18.64, 18.64, 18.64, 18.64, 18.64, 18.64, 18.64, 19.03, 19.03, 19.03, 19.03, 19.03, 19.03, 19.03, 19.03, 19.42, 19.42, 19.42, 19.42, 19.42, 19.42, 19.42, 19.42, 19.8, 19.8, 19.8, 19.8, 19.8, 19.8, 19.8, 19.8, 19.8, 20.16, 20.16, 20.16, 20.16, 20.16, 20.16, 20.16, 20.16, 20.16, 20.52, 20.52, 20.52, 20.52, 20.52, 20.52, 20.52, 20.52, 20.52, 20.52, 20.87, 20.87, 20.87, 20.87, 20.87, 20.87, 20.87, 20.87, 20.87, 20.87, 20.87, 21.2, 21.2, 21.2, 21.2, 21.2, 21.2, 21.2, 21.2, 21.2, 21.2, 21.2, 21.54, 21.54, 21.54, 21.54, 21.54, 21.54, 21.54, 21.54, 21.54, 21.54, 21.54, 21.86, 21.86, 21.86, 21.86, 21.86, 21.86, 21.86, 21.86, 21.86, 21.86, 21.86, 21.86, 21.86, 22.17, 22.17, 22.17, 22.17, 22.17, 22.17, 22.17, 22.17, 22.17, 22.17, 22.17, 22.17, 22.48, 22.48, 22.48, 22.48, 22.48, 22.48, 22.48, 22.48, 22.48, 23.65, 24.73, 25.49, 26.21, 26.67, 27.33, 27.76, 28.17, 28.57, 28.77, 29.15, 29.52, 29.7, 30.06, 30.24, 30.41, 30.75, 30.92, 31.09, 31.25, 31.41, 31.57, 31.89, 32.04, 32.19, 32.34, 32.49, 32.64, 32.79, 32.79, 32.93, 33.08, 33.22, 33.36, 33.5, 33.63, 33.63, 33.77, 33.91, 34.04, 34.04, 34.17, 34.3, 34.43, 34.43, 34.56, 34.69, 34.69, 34.82, 34.94, 34.94, 35.06, 35.19, 35.19, 35.31, 35.31, 35.43, 35.55, 35.55, 35.67, 35.67, 37.44, 38.64, 39.56, 40.35, 41.01, 41.64, 42.09, 33.25, 33.6, 34.02, 34.35, 34.68, 34.94, 35.25, 35.5, 35.74, 35.98, 36.21, 36.44, 27.47, 27.69, 27.86, 28.02, 28.18, 28.34, 28.5, 28.65, 28.81, 28.96, 29.11, 29.21, 29.36, 29.46, 29.6, 29.7, 29.84, 29.94, 30.08, 30.17, 30.27, 30.36, 30.45, 30.58, 30.67, 30.76, 30.85, 30.94, 31.03, 31.11, 31.2, 31.29, 31.37, 31.46, 31.5, 31.58, 31.67, 31.75, 31.83, 31.87, 31.96, 32.04, 32.08, 32.16, 32.24, 33.17, 33.93, 34.59, 35.15, 35.66, 36.12, 36.54, 36.89, 37.25, 37.56, 37.85, 38.14, 38.4, 38.63, 38.88, 39.1, 39.3, 39.51, 39.7, 39.89, 40.07, 40.23, 40.39, 40.54, 40.69, 40.84, 40.99, 41.12, 41.27, 41.39, 41.52, 41.64, 41.76, 41.86, 41.98, 42.1, 42.2, 42.3, 42.41, 42.51, 42.6, 42.7, 42.79, 42.88, 42.98, 43.05, 43.14, 43.23, 43.3, 43.39, 43.47, 43.56, 43.63, 43.7, 43.77, 43.85, 43.92, 43.99, 44.06, 44.13, 44.2, 44.26, 44.33, 44.4, 44.45, 44.51, 44.58, 44.65, 44.69, 44.76, 44.81, 44.87, 44.92, 44.98, 45.03, 45.1, 45.14, 45.21, 45.25, 45.3, 45.36, 45.41, 45.46, 45.5, 45.55, 45.61, 45.66, 45.7, 45.75, 45.79, 45.84, 45.88, 45.93, 45.97, 46.02, 46.06, 46.11, 46.15, 46.19, 46.24, 46.27, 46.31, 46.35, 46.4, 46.44, 46.47, 46.51, 46.56, 46.6, 46.63, 46.67, 46.71, 46.74, 46.78, 46.81, 46.85, 46.89, 46.92, 46.96, 46.99, 47.03, 47.06, 47.1, 47.13, 47.17, 47.2, 47.24};
    float32_t snr_mean = 0.0f;
    for (uint32_t i = 0; i < bins_num; i++)
    {
        snr_mean += (float32_t)hist[i] * snr_weight_table[i];
    }

    snr_mean /= pixel_count;
    snr_mean -= 10.0f * log10f(dg + FLT_EPSILON);
    *snr = snr_mean;
}

static void ox03c10_merge_hcg_hdr_hists(const uint32_t hist_hcg[256],
                                        const uint32_t hist_hdr[256],
                                        uint32_t sensor_hist[512],
                                        uint32_t *total_bins,
                                        uint32_t *pix_sum)
{
    uint8_t hcg_last_bin = 192;
    uint8_t hdr_first_bin = 3;
    uint32_t single_hist_size = 256;
    *total_bins = hcg_last_bin + single_hist_size - hdr_first_bin;
    uint32_t i = 0;
    uint32_t stitched_hist_bin = 0;
    uint32_t tsum = 0;

    for (i = 0; i < hcg_last_bin; i++)
    {
        sensor_hist[stitched_hist_bin] = hist_hcg[i];
        tsum += hist_hcg[i];
        isp_tracelog_v("hist[%d]=%d\n", stitched_hist_bin, sensor_hist[stitched_hist_bin]);
        stitched_hist_bin++;
    }

    for (i = hdr_first_bin; i < single_hist_size; i++)
    {
        sensor_hist[stitched_hist_bin] = hist_hdr[i];
        tsum += hist_hdr[i];
        isp_tracelog_v("hist[%d]=%d\n", stitched_hist_bin, sensor_hist[stitched_hist_bin]);
        stitched_hist_bin++;
    }

    *pix_sum = tsum;
    isp_tracelog_v("pix %d total_bins: %d = %d + 256 - %d\n", *pix_sum, *total_bins, hcg_last_bin, hdr_first_bin);
}

static bool parse_histogram_ox3c(const uint8_t* stat,uint32_t hist[512], uint32_t *pixel_count, uint32_t* bins_num, const float32_t** weights)
{
    static const float32_t ox3c_table[] = {0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96,100,104,108,112,116,120,124,128,132,136,140,144,148,152,156,160,164,168,172,176,180,184,188,192,196,200,204,208,212,216,220,224,228,232,236,240,244,248,252,256,260,264,268,272,276,280,284,288,292,296,300,304,308,312,316,320,324,328,332,336,340,344,348,352,356,360,364,368,372,376,380,384,388,392,396,400,404,408,412,416,420,424,428,432,436,440,444,448,452,456,460,464,468,472,476,480,484,488,492,496,500,504,508,512,516,520,524,528,532,536,540,544,548,552,556,560,564,568,572,576,580,584,588,592,596,600,604,608,612,616,620,624,628,632,636,640,644,648,652,656,660,664,668,672,676,680,684,688,692,696,700,704,708,712,716,720,724,728,732,736,740,744,748,752,756,760,764,768,1024,1280,1536,1792,2048,2304,2560,2816,3072,3328,3584,3840,4096,4352,4608,4864,5120,5376,5632,5888,6144,6400,6656,6912,7168,7424,7680,7936,8192,8448,8704,8960,9216,9472,9728,9984,10240,10496,10752,11008,11264,11520,11776,12032,12288,12544,12800,13056,13312,13568,13824,14080,14336,14592,14848,15104,15360,15616,15872,16128,16384,24320,32256,40192,48128,56064,64000,71936,79872,87808,95744,103680,111616,119552,127488,135424,143360,151296,159232,167168,175104,183040,190976,198912,206848,214784,222720,230656,238592,246528,254464,262400,270336,278272,286208,294144,302080,310016,317952,325888,333824,341760,349696,357632,365568,373504,381440,389376,397312,405248,413184,421120,429056,436992,444928,452864,460800,468736,476672,484608,492544,500480,508416,516352,524288,651264,778240,905216,1032192,1159168,1286144,1413120,1540096,1667072,1794048,1921024,2048000,2174976,2301952,2428928,2555904,2682880,2809856,2936832,3063808,3190784,3317760,3444736,3571712,3698688,3825664,3952640,4079616,4206592,4333568,4460544,4587520,4714496,4841472,4968448,5095424,5222400,5349376,5476352,5603328,5730304,5857280,5984256,6111232,6238208,6365184,6492160,6619136,6746112,6873088,7000064,7127040,7254016,7380992,7507968,7634944,7761920,7888896,8015872,8142848,8269824,8396800,8523776,8650752,8777728,8904704,9031680,9158656,9285632,9412608,9539584,9666560,9793536,9920512,10047488,10174464,10301440,10428416,10555392,10682368,10809344,10936320,11063296,11190272,11317248,11444224,11571200,11698176,11825152,11952128,12079104,12206080,12333056,12460032,12587008,12713984,12840960,12967936,13094912,13221888,13348864,13475840,13602816,13729792,13856768,13983744,14110720,14237696,14364672,14491648,14618624,14745600,14872576,14999552,15126528,15253504,15380480,15507456,15634432,15761408,15888384,16015360,16142336,16269312,16396288,16523264,16650240,16777216};

    if (weights)
    {
        *weights = ox3c_table;
    }

    bins_num[0] = sizeof(ox3c_table) / sizeof(ox3c_table[0]);
    const uint8_t* buf0 = stat;
    const uint8_t* buf1 = buf0 + 2 * 1920;
    int i;
    int bin = 0;
    int offset = 0;
    uint32_t sum = 0;
    uint32_t part_1, part_2;
    uint32_t value;
    uint32_t comb_hist[256];
    uint32_t hcg_hist[256];

    // Parse combined histogram
    for (i = 0; i < 128; i++)
    {
        part_1 = get_uint16(buf0, offset);
        part_2 = get_uint16(buf0, offset + 2);
        value = (part_2 << 12) | part_1;
        comb_hist[bin] = value;
        bin++;
        sum += value;

        part_1 = get_uint16(buf1, offset);
        part_2 = get_uint16(buf1, offset + 2);
        value = (part_2 << 12) | part_1;
        comb_hist[bin] = value;
        bin++;
        sum += value;

        offset += 4;
    }

    // Parse HCG histogram
    offset = 0;
    bin = 0;
    int stat_hist_size_pixels = (256 / 2) * 2; /* on each of two lines */
    int stat_avg_size_pixels = (1) * 2;        /* on first line, second line is padded with 0 */
    buf0 += (stat_hist_size_pixels + stat_avg_size_pixels) * 2 * 3;
    buf1 += (stat_hist_size_pixels + stat_avg_size_pixels) * 2 * 3;
    for (i = 0; i < 128; i++)
    {
        part_1 = get_uint16(buf0, offset);
        part_2 = get_uint16(buf0, offset + 2);
        value = (part_2 << 12) | part_1;
        hcg_hist[bin] = value;
        bin++;
        sum += value;

        part_1 = get_uint16(buf1, offset);
        part_2 = get_uint16(buf1, offset + 2);
        value = (part_2 << 12) | part_1;
        hcg_hist[bin] = value;
        bin++;
        sum += value;

        offset += 4;
    }

    ox03c10_merge_hcg_hdr_hists(hcg_hist, comb_hist, hist, bins_num, pixel_count);

    return *pixel_count != 0;
}


void functions_init_ox3c(sensor_operations_t* ctx)
{
#ifdef ISP_SENSOR_OX3C
    ctx->fill_default_table = fill_regs_default_table;
    ctx->write_all_regs = set_all_sensor_params;
    ctx->parse_embedded_data = parse_regs_from_emb_line_ox3c;
    ctx->parse_histogram = parse_histogram_ox3c;
    ctx->calc_snr = calc_snr_ox3c;
    ctx->set_default_isp_settings = set_default_isp_ox3c;
#endif
}

// Embedded data format version = 0x58
// version, 0x302c, 1, 4
// exposure, 0x3501, 9, 2
// exposure_fine, 0x3506, 13, 2
// again_hcg, 0x3508, 17, 1
// again_hcg_f, 0x3508, 19, 1
// dgain_hcg, 0x350a, 21, 2
// exposure_t2, 0x3541, 29, 2
// exposure_t2_fine, 0x3546, 33, 2
// again_spd, 0x3548, 37, 1
// again_spd_f, 0x3549, 39, 1
// dgain_spd, 0x354a, 41, 2
// again_lcg, 0x3588, 57, 1
// again_lcg_f, 0x3589, 59, 1
// dgain_lcg, 0x358a, 61, 2
// exposure_t3, 0x35c1, 69, 2
// exposure_t3_fine, 0x35c6, 73, 2
// again_vs, 0x35c8, 77, 1
// again_vs_f, 0x35c8, 79, 1
// dgain_vs, 0x35ca, 81, 2
// hts_dcg, 0x380c, 89, 2
// vts, 0x380e, 93, 2
// hts_spd, 0x384c, 97, 2
// hts_vs, 0x388c, 101, 2
// hts, 0x386e, 105, 2
// temp_current, 0x4d2a, 117, 2
// sensitivity_ratio_hcg, 0x501a, 137, 2
// sensitivity_ratio_lcg, 0x501e, 141, 2
// sensitivity_ratio_spd, 0x5022, 145, 2
// sensitivity_ratio_vs, 0x5026, 149, 2
// wb_blue_hcg, 0x5280, 153, 2
// wb_green_b_hcg, 0x5282, 157, 2
// wb_green_r_hcg, 0x5284, 161, 2
// wb_red_hcg, 0x5286, 165, 2
// wb_blue_lcg, 0x5480, 169, 2
// wb_green_b_lcg, 0x5482, 173, 2
// wb_green_r_lcg, 0x5484, 177, 2
// wb_red_lcg, 0x5486, 181, 2
// wb_blue_spd, 0x5680, 185, 2
// wb_green_b_spd, 0x5682, 189, 2
// wb_green_r_spd, 0x5684, 193, 2
// wb_red_spd, 0x5686, 197, 2
// wb_blue_vs, 0x5880, 201, 2
// wb_green_b_vs, 0x5882, 205, 2
// wb_green_r_vs, 0x5884, 209, 2
// wb_red_vs, 0x5886, 213, 2
// frame_count, 0x483e, 225, 2
// l_convert_gain, 0x5088, 229, 2
// m_convert_gain, 0x508a, 233, 2
// s_convert_gain, 0x508c, 237, 2
// v_convert_gain, 0x508e, 241, 2
// current_LPD_exposure, 0x350e, 245, 2
// current_SPD_exposure, 0x354e, 249, 2
// current_VS_exposure, 0x35ce, 253, 2
// hcg_isp_enable, 0x5004, 257, 1
// hcg_test_pattern_1, 0x5240, 259, 1
// hcg_test_pattern_2, 0x5241, 261, 1
// hcg_bayer_b_value, 0x5242, 263, 2
// hcg_bayer_gb_value, 0x5244, 267, 2
// hcg_bayer_gr_value, 0x5246, 271, 2
// hcg_bayer_r_value, 0x5248, 275, 2