/* =========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ========================================================================= */
/* ================= (c) MAGNA Electronics Solutions ======================= */
/** @ingroup
 *  @file           common_sensor_api.c
 *  @brief          sensor API implementation
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <common_sensor_api.h>

int32_t set_register_via_iss(uint32_t channel_id, uint32_t reg_addr, uint32_t value)
{
    int32_t status = -1;
    uint8_t  cmdPrm[CMD_PARAM_SIZE];
    uint8_t * ptr8 = (uint8_t * )cmdPrm;
    char dummy_name[ISS_SENSORS_MAX_NAME] = "dummy";
    IMAGE_SENSOR_CTRLCMD ctrlCmd = IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_REG;

    memcpy(ptr8, dummy_name, ISS_SENSORS_MAX_NAME);
    ptr8 += ISS_SENSORS_MAX_NAME;

    memcpy(ptr8, &channel_id, sizeof(uint32_t));
    ptr8 += sizeof(uint32_t);

    memcpy(ptr8, &ctrlCmd, sizeof(IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_REG));
    ptr8 += sizeof(IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_REG);
    memcpy(ptr8, &reg_addr, sizeof(uint32_t));
    ptr8 += sizeof(uint32_t);
    memcpy(ptr8, &value, sizeof(uint32_t));
    ptr8 += sizeof(uint32_t);

    status = appRemoteServiceRun(
        APP_IPC_CPU_MCU2_0,
        IMAGE_SENSOR_REMOTE_SERVICE_NAME,
        IM_SENSOR_CMD_CTL,
        (void*)cmdPrm,
        CMD_PARAM_SIZE,
        0
    );
    return status;
}

int32_t get_register_via_iss(uint32_t channel_id, uint32_t reg_addr, uint32_t *value)
{
    int32_t status = -1;
    uint8_t  cmdPrm[CMD_PARAM_SIZE];
    uint8_t * ptr8 = (uint8_t * )cmdPrm;
    char dummy_name[ISS_SENSORS_MAX_NAME] = "dummy";
    IMAGE_SENSOR_CTRLCMD ctrlCmd = IMAGE_SENSOR_CTRLCMD_READ_SENSOR_REG;

    memcpy(ptr8, dummy_name, ISS_SENSORS_MAX_NAME);
    ptr8 += ISS_SENSORS_MAX_NAME;

    memcpy(ptr8, &channel_id, sizeof(uint32_t));
    ptr8 += sizeof(uint32_t);

    memcpy(ptr8, &ctrlCmd, sizeof(IMAGE_SENSOR_CTRLCMD_READ_SENSOR_REG));
    ptr8 += sizeof(IMAGE_SENSOR_CTRLCMD_READ_SENSOR_REG);
    memcpy(ptr8, &reg_addr, sizeof(uint32_t));
    ptr8 += sizeof(uint32_t);

    status = appRemoteServiceRun(
        APP_IPC_CPU_MCU2_0,
        IMAGE_SENSOR_REMOTE_SERVICE_NAME,
        IM_SENSOR_CMD_CTL,
        (void*)cmdPrm,
        CMD_PARAM_SIZE,
        0
    );
    memcpy(value, ptr8, sizeof(uint32_t));
    return status;
}

int32_t set_register_byte_array_via_iss(uint32_t channel_id, uint32_t reg_address, const uint8_t* data, uint32_t sz_in_bytes)
{
    int32_t status = -1;
    uint8_t  cmdPrm[CMD_PARAM_SIZE];
    uint8_t * ptr8 = (uint8_t * )cmdPrm;
    char dummy_name[ISS_SENSORS_MAX_NAME] = "dummy";
    IMAGE_SENSOR_CTRLCMD ctrlCmd = IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_NREGS;

    memcpy(ptr8, dummy_name, ISS_SENSORS_MAX_NAME);
    ptr8 += ISS_SENSORS_MAX_NAME;

    memcpy(ptr8, &channel_id, sizeof(uint32_t));
    ptr8 += sizeof(uint32_t);

    memcpy(ptr8, &ctrlCmd, sizeof(IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_NREGS));
    ptr8 += sizeof(IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_NREGS);

    ptr8[0] = (reg_address >> 8) & 0xff;
    ptr8[1] = (reg_address) & 0xff;
    ptr8 += sizeof(uint16_t);
    memcpy(ptr8, &sz_in_bytes, sizeof(uint8_t));
    ptr8 += sizeof(uint8_t);
    uint32_t i;

    memcpy(ptr8, data, sz_in_bytes);

    status = appRemoteServiceRun(
        APP_IPC_CPU_MCU2_0,
        IMAGE_SENSOR_REMOTE_SERVICE_NAME,
        IM_SENSOR_CMD_CTL,
        (void*)cmdPrm,
        CMD_PARAM_SIZE,
        0
    );
    return status;
}


int32_t cuc_set_fps_via_iss(uint32_t channel_id, camera_frame_rate_denominator_t enum_fps)
{
    int32_t status = -1;
    uint8_t cmdPrm[CMD_PARAM_SIZE];
    uint8_t *ptr8 = (uint8_t * )cmdPrm;
    IMAGE_SENSOR_CTRLCMD ctrlCmd = IMAGE_SENSOR_CTRLCMD_SETFPS;

    /* ignored name */
    ptr8 += ISS_SENSORS_MAX_NAME;

    memcpy(ptr8, &channel_id, sizeof(uint32_t));
    ptr8 += sizeof(uint32_t);

    memcpy(ptr8, &ctrlCmd, sizeof(IMAGE_SENSOR_CTRLCMD_SETFPS));
    ptr8 += sizeof(IMAGE_SENSOR_CTRLCMD_SETFPS);
    uint8_t fps = 30;

    if (enum_fps == 2)
    {
        fps = 15;
    }

    *ptr8++ = fps;

    status = appRemoteServiceRun(APP_IPC_CPU_MCU2_0,
                                 IMAGE_SENSOR_REMOTE_SERVICE_NAME,
                                 IM_SENSOR_CMD_CTL, (void*)cmdPrm,
                                 CMD_PARAM_SIZE, 0);

    return status;
}
