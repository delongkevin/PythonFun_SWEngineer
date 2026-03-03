/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           processing.c
 *  @brief          API implementation for communication with ISP framework
 *
 *
 *  @version        3.31
 *  @author         Ronzhin Alexander
 *  @date           01.10.2021
 *
 * =========================================================================
 *
 *  @par          Change History:
 *
 * ========================================================================= */

#include "vx_vpac_cuc_common.h"

#include <def_cfg.h>
#include "common_sensor_api.h"


/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define BITMASK_SWITCH(x) \
    for (i = 1; (x) >= i; i *= 2) if ((x) & i) switch (i)


/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */


/* ========================================================================== */
/*                         Default Values Declarations                        */
/* ========================================================================== */

////

static void send_all_sensor_params(uint32_t sensor_id, uint8_t* data, uint32_t numConfigItems)
{
    uint32_t cur_length = 2;
    uint32_t read = 0;
    uint8_t buffer[32];

    while (read < numConfigItems)
    {
        uint16_t val16;
        uint16_t reg_address;
        memcpy(&val16, &data[read], sizeof(val16));
        read+= sizeof(val16);
        reg_address = val16;

        if (cur_length >= sizeof(buffer))
        {
            VX_PRINT(VX_ZONE_ERROR, "SET register error too big data size [0x%04x] %d", reg_address, cur_length);
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
            memcpy(buffer, &data[read], cur_length);
            read+= cur_length;
            if (set_register_byte_array_via_iss(sensor_id, reg_address, buffer, cur_length))
            {
                break;
            }
        }
    }
}

magna_camera_sensor_type_t get_sensor_type(void)
{
    /// ### TO DO: get sensor type in runtime
    #ifdef ISP_SENSOR_OX3C
        return MAGNA_CAMERA_SENSOR_OX3C;
    #endif
    #ifdef ISP_SENSOR_AR233
        return MAGNA_CAMERA_SENSOR_AR0233;
    #endif
return MAGNA_CAMERA_SENSOR_UNKNOWN;
}


vx_status rc_init(tivxVpacCucIspObj* ispObj, uint32_t width, uint32_t height)
{
    vx_status status;
    /* set custom default value to ISP config */
    VX_PRINT(VX_ZONE_ERROR, "sensor %d width, height: %d %d\n", ispObj->ispPrms.channel_id, width, height);
    /* Init storage and algorithms */
    ispObj->list_elements_counter = SENSOR_DATA_ARRAY_MAX_SZ;
    status = getInitialSensorConfig(ispObj->ispPrms.channel_id,
                                    get_sensor_type(),
                                    ispObj->sensor_register_list,
                                    &ispObj->list_elements_counter);

    set_default_isp_config(ispObj, width, height);

    send_all_sensor_params(ispObj->ispPrms.channel_id, ispObj->sensor_register_list, ispObj->list_elements_counter);

    if ((vx_status)VX_SUCCESS == status)
    {
        status = getInitialIspConfig(ispObj->ispPrms.channel_id, &ispObj->vissCfg);

        uint32_t v_size = ispObj->vissCfg.h3aCfg.aewbCfg.winCfg.height;
        uint32_t h_size = ispObj->vissCfg.h3aCfg.aewbCfg.winCfg.width;
        uint32_t v_count = ispObj->vissCfg.h3aCfg.aewbCfg.winCfg.vertCount;
        uint32_t h_count = ispObj->vissCfg.h3aCfg.aewbCfg.winCfg.horzCount;
        uint32_t v_skip = ispObj->vissCfg.h3aCfg.aewbCfg.winCfg.vertIncr;
        uint32_t h_skip = ispObj->vissCfg.h3aCfg.aewbCfg.winCfg.horzIncr;

        uint16_t winh = (h_size + h_skip - 1)/h_skip;
        uint16_t winv = (v_size + v_skip - 1)/v_skip;
        uint32_t n_row = v_count;
        uint32_t n_col = h_count;
        uint32_t n_pix = winh * winv;
        ispObj->isp_data_storage.n_row = n_row;
        ispObj->isp_data_storage.n_col = n_col;
        ispObj->isp_data_storage.n_pix = n_pix;
    }

    return status;
}

vx_status rc_process(tivxVpacCucIspObj* ispObj)
{
    vx_status status = VX_SUCCESS;
    uint32_t channel_id = ispObj->ispPrms.channel_id;
    ispObj->isp_data_storage.h3a_data = (H3a_StatsData_32x16_SumOnly *)ispObj->h3a_stats_data;

    // VX_PRINT(VX_ZONE_ERROR, "Start processFrame\n");
    // uint64_t t0 = __get_time_us();
    ispObj->list_elements_counter = SENSOR_DATA_ARRAY_MAX_SZ;
    status = processFrame(channel_id,
                 &ispObj->sensorData,
                 &ispObj->isp_data_storage,
                 ispObj->sensor_register_list,
                 &ispObj->list_elements_counter,
                 &ispObj->vissCfg, NULL);
    // uint64_t t1 = __get_time_us();
    // VX_PRINT(VX_ZONE_ERROR, "End processFrame %llu\n", t1 - t0);

    uint64_t i;
    BITMASK_SWITCH(ispObj->vissCfg.usageFlag)
    {
        case FLAG_ISP_CCM_CFG:
            ispObj->vissCfgRef.ccm = &ispObj->vissCfg.ccmCfg;
            break;
        case FLAG_ISP_CFA_CFG:
            ispObj->vissCfgRef.cfaCfg = &ispObj->vissCfg.cfaCfg;
            break;
        case FLAG_ISP_CFALUT16TO12_CFG:
            ispObj->vissCfgRef.cfaLut16to12Cfg = &ispObj->vissCfg.cfaLut16to12Cfg;
            break;
        case FLAG_ISP_DECOMP1_CFG:
            ispObj->vissCfgRef.lLutCfg = &ispObj->vissCfg.decomp1Cfg;
            break;
        case FLAG_ISP_DECOMP2_CFG:
            ispObj->vissCfgRef.sLutCfg = &ispObj->vissCfg.decomp2Cfg;
            break;
        case FLAG_ISP_DECOMP3_CFG:
            ispObj->vissCfgRef.vsLutCfg = &ispObj->vissCfg.decomp3Cfg;
            break;
        case FLAG_ISP_DPCLUT_CFG:
            ispObj->vissCfgRef.dpcLut = &ispObj->vissCfg.dpcLutCfg;
            break;
        case FLAG_ISP_DPCOTF_CFG:
            ispObj->vissCfgRef.dpcOtf = &ispObj->vissCfg.dpcOtfCfg;
            break;
        case FLAG_ISP_TONEMAP_CFG:
            ispObj->vissCfgRef.glbceCfg = &ispObj->vissCfg.glbceCfg;
            break;
        case FLAG_ISP_TONEMAPPREGAMMALUT_CFG:
            ispObj->vissCfgRef.fwdPrcpCfg = &ispObj->vissCfg.fwdPrcpCfg;
            break;
        case FLAG_ISP_TONEMAPPOSTGAMMALUT_CFG:
            ispObj->vissCfgRef.revPrcpCfg = &ispObj->vissCfg.revPrcpCfg;
            break;
        case FLAG_ISP_EE_CFG:
            ispObj->vissCfgRef.eeCfg = &ispObj->vissCfg.eeCfg;
            break;
        case FLAG_ISP_GAMMA_CFG:
            ispObj->vissCfgRef.gamma = &ispObj->vissCfg.gammaCfg;
            break;
        case FLAG_ISP_H3A_CFG:
            ispObj->vissCfgRef.h3aCfg = &ispObj->vissCfg.h3aCfg;
            break;
        case FLAG_ISP_H3ALUT_CFG:
            ispObj->vissCfgRef.h3aLutCfg = &ispObj->vissCfg.h3aLutCfg;
            break;
        case FLAG_ISP_HIST_CFG:
            ispObj->vissCfgRef.histCfg = &ispObj->vissCfg.histCfg;
            break;
        case FLAG_ISP_LSC_CFG:
            ispObj->vissCfgRef.lscCfg = &ispObj->vissCfg.lscCfg;
            break;
        case FLAG_ISP_MERGE1_CFG:
            ispObj->vissCfgRef.wdr1Cfg = &ispObj->vissCfg.merge1Cfg;
            break;
        case FLAG_ISP_MERGE2_CFG:
            ispObj->vissCfgRef.wdr2Cfg = &ispObj->vissCfg.merge2Cfg;
            break;
        case FLAG_ISP_NSF4_CFG:
            ispObj->vissCfgRef.nsf4Cfg = &ispObj->vissCfg.nsf4Cfg;
            break;
        case FLAG_ISP_PWL1_CFG:
            ispObj->vissCfgRef.lPwlCfg = &ispObj->vissCfg.pwlCfg1;
            break;
        case FLAG_ISP_PWL2_CFG:
            ispObj->vissCfgRef.sPwlCfg = &ispObj->vissCfg.pwlCfg2;
            break;
        case FLAG_ISP_PWL3_CFG:
            ispObj->vissCfgRef.vsPwlCfg = &ispObj->vissCfg.pwlCfg3;
            break;
        case FLAG_ISP_RFELUT20TO16_CFG:
            ispObj->vissCfgRef.comp20To16LutCfg = &ispObj->vissCfg.rfeLut20to16Cfg;
            break;
        case FLAG_ISP_RGB2HSV_CFG:
            ispObj->vissCfgRef.rgb2Hsv = &ispObj->vissCfg.rgb2hsvCfg;
            break;
        case FLAG_ISP_RGB2YUV_CFG:
            ispObj->vissCfgRef.rgb2yuv = &ispObj->vissCfg.rgb2yuvCfg;
            break;
        case FLAG_ISP_WB_CFG:
            ispObj->vissCfgRef.wbCfg = &ispObj->vissCfg.wbCfg;
            break;
        case FLAG_ISP_YUVSATLUT_CFG:
            ispObj->vissCfgRef.yuvSatLutCfg = &ispObj->vissCfg.yuvSatLutCfg;
            break;
        default:
        break;
    }

    return status;
}


void rc_sensor_write(tivxVpacCucIspObj* ispObj)
{
    uint32_t sensor_id = ispObj->ispPrms.channel_id;

    send_all_sensor_params(sensor_id, ispObj->sensor_register_list,
                           ispObj->list_elements_counter);
}
/*  */
