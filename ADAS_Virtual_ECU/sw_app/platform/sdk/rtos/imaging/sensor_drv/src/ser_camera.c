#include <iss_sensors.h>
#include <iss_sensor_if.h>
#include <iss_sensor_priv.h>
#include <app_remote_service.h>
#include <app_ipc.h>

#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include <ti/csl/csl_gpio.h>
#include <ti/csl/soc/j721s2/src/cslr_soc.h>
#include <ti/csl/src/ip/gpio/V0/gpio.h>

#include "ser_camera.h"
#include "errno.h"
#include "ub960.h"
#include "i2c_helpers.h"
#include "dev_helpers.h"
#include "type_helpers.h"
#include "imagers/common.h"
#include "ser_camera.h"
#include "safety.h"

#define ARRAY_SIZE(a)   (sizeof(a) / sizeof(*(a)))

static const uint8_t camera_addr[2][4] = {
    {
        SENSOR_0_I2C_ALIAS, SENSOR_1_I2C_ALIAS, SENSOR_2_I2C_ALIAS, SENSOR_3_I2C_ALIAS
    },
    {
        SENSOR_4_I2C_ALIAS, SENSOR_5_I2C_ALIAS, SENSOR_6_I2C_ALIAS, SENSOR_7_I2C_ALIAS
    }
};

static struct ser_camera cameras[ISS_SENSORS_MAX_CHANNEL + 1]; // +1 for broadcast

static const struct sensor_drv *sensor_drvs[] = {
    &ar0233_drv,
    &ar0233_60fps_drv,
    &dummy_drv,
    &ox03c10_drv,

    /* fallback driver */
    // &ub960_testpattern_drv
    NULL,
};

/*******************************************************************************
 *  Camera sensor side API
 ******************************************************************************/

int ser_camera_i2c_set_mapping(void *_cam, uint32_t n, uint8_t src, uint8_t dst)
{
    struct ser_camera *cam = _cam;
    if (cam == NULL)
        return -ENODEV;

    if (cam->ti_ser) {
        dev_info(&cam->ti_ser->dev, "i2c mapping: 0x%02x -> 0x%02x\n", src, dst);
        return ub9x3_i2c_set_mapping(cam->ti_ser, n, src, dst);
    }

    return -1;
}

int ser_camera_i2c_forwarding(void *_cam, uint32_t enable)
{
    struct ser_camera *cam = _cam;

    if (cam == NULL)
        return -ENODEV;

    if (cam->ti_ser) {
        //dev_dbg(&cam->ti_ser->dev, "i2c forwarding %d.%d %s\n", cam->slot, cam->channel, enable ? "enable" : "disable");
        return ub9x3_i2c_forwarding(cam->ti_ser, enable);
    }

    return -1;
}

/*******************************************************************************
 *  Serializers side API
 ******************************************************************************/

static int32_t ser_camera_probe(struct ser_camera *cam, const struct sensor_drv *drv, int is_config)
{
    struct i2c_client *ser_client = NULL;
    int32_t            ret = 0;

    if (cam->ti_ser)
        ser_client = cam->ti_ser;
    if (cam->max_ser)
        ser_client = cam->max_ser;

    if (ser_client == NULL) {
        ret = -ENODEV;
        goto error;
    }

    /* probe camera */
    dev_info(&ser_client->dev, "probing %s sensor\n", drv->name);

    ret = drv->detect(&cam->sensor, (void *)cam);
    if (ret)
        goto error;

    if (!is_config)
        return 0;

    /* optional config */
    if (NULL != drv->config) {
        ret = drv->config(&cam->sensor, 0);
    }

    return ret; // imager detected

error:
    return ret; // Nothing detected
}

int32_t ser_camera_probe_fpdlink(struct i2c_client *ser_client, int slot, int channel, const struct sensor_drv *drv, int is_config)
{
    int idx;
    struct ser_camera *cam;

    idx = slot * 4 + channel;

    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return 0;

    cam = &cameras[idx];
    cam->slot = slot;
    cam->channel = channel;
    cam->ti_ser = ser_client;

    /* set sensor i2c location */
    cam->sensor.adapter = ser_client->adapter;
    cam->sensor.addr = camera_addr[slot][channel];
    cam->sensor.idx = idx;
    cam->sensor_drv = drv;

    /* probe cameras */
    return ser_camera_probe(cam, drv, is_config);
}

static int32_t ser_camera_probe_broadcast(struct ser_camera *cam, const struct sensor_drv *drv)
{
    struct i2c_client *ser_client = NULL;
    int ret = 0;

    if (cam->ti_ser)
        ser_client = cam->ti_ser;
    if (cam->max_ser)
        ser_client = cam->max_ser;

    if (ser_client == NULL) {
        ret = -ENODEV;
        goto error;
    }

    /* probe camera */
    dev_info(&ser_client->dev, "probing %s sensor\n", drv->name);

    ret = drv->detect(&cam->sensor, (void *)cam);
    if (ret)
        goto error;

    /* optional config */
    if (NULL != drv->config) {
        ret = drv->config(&cam->sensor, 0);
    }
    return ret; // imager detected

error:
    cam->sensor_drv = NULL;
    return ret; // Nothing detected
}

int32_t ser_camera_probe_fpdlink_broadcast(struct i2c_client *ser_client, int slot, const struct sensor_drv *drv)
{
    int idx;
    struct ser_camera *cam;
    int channel = 0;

    idx = slot * 4 + channel;

    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return 0;

    cam = &cameras[ISS_SENSORS_MAX_CHANNEL];
    cam->slot = slot;
    cam->channel = channel;
    cam->ti_ser = ser_client;
    cam->max_ser = NULL;
    cam->feat = cameras[idx].feat;

    /* set sensor i2c location */
    cam->sensor.adapter = ser_client->adapter;
    cam->sensor.addr = 0x6f;
    cam->sensor.idx = idx;
    cam->sensor_drv = drv;

    /* probe cameras */
    return ser_camera_probe_broadcast(cam, drv);
}

/*******************************************************************************
 *  ISS side API
 ******************************************************************************/
int32_t ser_camera_get_drv_list(char * buf, int size)
{
    uint32_t i;

    memset(buf, 0, ISS_SENSORS_MAX_SUPPORTED_SENSOR * ISS_SENSORS_MAX_NAME);
    for (i = 0; i < ARRAY_SIZE(sensor_drvs); i++) {
        const struct sensor_drv *drv = sensor_drvs[i];

        if ((NULL == drv))
            continue;

        if (((i + 1) * ISS_SENSORS_MAX_NAME) > size)
        {
            appLogPrintf("Not enough memory to return the list of supported sensors\n");
            return -ENOMEM;
        }

        memcpy(buf + (i * ISS_SENSORS_MAX_NAME), drv->name, ISS_SENSORS_MAX_NAME);
    }

    return 0;
}

int32_t ser_camera_get_drv_list2(char *buf, int size)
{
    /*.. First byte indicates which sub-command to execute:
        0xFF - Read the number of sensors available.
        0x00...0xFE - Read the name of one sensor.
                      Invalid sensor indices give zero-length strings.
    */

    uint8_t *bytes = (uint8_t *)buf;
    uint8_t cmd = bytes[0];
    memset(buf, 0, size);

    switch (cmd)
    {
    case IM_SENSOR_CMD_ENUMERATE2_GET_COUNT:
        /*.. read sensor count command */
        bytes[0] = ARRAY_SIZE(sensor_drvs) - 1; /*.. Assuming the last descriptor is NULL */
        break;

    default:
        {
            /*.. read sensor name command */
            uint8_t sensor_index = cmd;
            if (sensor_index < ARRAY_SIZE(sensor_drvs))
            {
                const struct sensor_drv *drv = sensor_drvs[sensor_index];

                if (strlen(drv->name) >= size)
                {
                    appLogPrintf("Not enough memory to return the name of supported sensor\n");
                    return -ENOMEM;
                }

                strncpy(buf, drv->name, size);
            }
        }
        break;
    }

    return 0;
}

int32_t ser_camera_get_sensor_info(char *name, IssSensor_CreateParams *sensor_prms)
{
    int32_t status = -1;
    uint32_t i;

    /* Check For Errors */
    if ((NULL == sensor_prms) || (NULL == name))
    {
        status = -2;
    } else {
        for (i = 0; i < ARRAY_SIZE(sensor_drvs); i++) {
            const struct sensor_drv *drv = sensor_drvs[i];

            if(NULL == drv) {
                appLogPrintf("drv is NULL \n");
                return -1;
            }
            /* if (NULL == drv->name) { */
            /*     appLogPrintf("drv->name is NULL \n"); */
            /*     return -1; */
            /* } */
            if (0 == strncmp(drv->name, name, ISS_SENSORS_MAX_NAME))
            {
                if(NULL == drv->params) {
                    appLogPrintf("params is NULL \n");
                    return -1;
                } else {
                    memcpy(sensor_prms, drv->params, sizeof(IssSensor_CreateParams));
                    status = 0;
                    break;
                }
            }
        }
    }

    return (status);
}

int32_t ser_camera_power(uint32_t idx, uint32_t on)
{
    int ret = 0;

    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return -EINVAL;

    struct ser_camera *cam = &cameras[idx];
    if (cam->sensor_drv == NULL)
        return -ENODEV;
    const struct sensor_drv *sensor_drv = cam->sensor_drv;

    if (on) {
        ret = -1;
        if (cam->ti_ser)
            ret = ub9x3_PoC_set(cam->ti_ser, on);
        if (ret)
            goto out;
    }

    if (NULL != sensor_drv->power) {
        ret = sensor_drv->power(&cam->sensor, on);
    }

    if (!on) {
        ret = -1;
        if (cam->ti_ser)
            ret = ub9x3_PoC_set(cam->ti_ser, on);
        if (ret)
            goto out;
    }

out:
    return ret;
}

int32_t ser_camera_configure(uint32_t idx, uint32_t feat)
{
    int ret = 0;

    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return -EINVAL;

    struct ser_camera *cam = &cameras[idx];

    cam->feat = feat;

#if 0
    if (cam->sensor_drv == NULL)
        return -ENODEV;

    const struct sensor_drv *sensor_drv = cam->sensor_drv;

    if (NULL != sensor_drv->config) {
        ret = sensor_drv->config(&cam->sensor, feat);
    }
#endif

    return ret;
}

int32_t ser_camera_eeprom_init(void)
{
    return iss_board_eeprom_init();
}

int32_t ser_camera_board_probe(char *sensor_name, uint32_t channel_mask)
{
    int i;
    const struct sensor_drv *drv = NULL;

    for (i = 0; sensor_drvs[i]; i++) {
        if (!strncmp(sensor_drvs[i]->name, sensor_name, ISS_SENSORS_MAX_NAME)) {
            drv = sensor_drvs[i];
            break;
        }
    }

    if (drv == NULL) {
        return -EINVAL;
    }

    return iss_board_probe(channel_mask, drv);
}

int32_t ser_camera_board_deinit(uint32_t channel_mask)
{
    return iss_board_deinit(channel_mask);
}

__attribute__((weak)) void Safety_Cam_stream_on(uint32_t cam_num)
{
    return;
}

int32_t ser_camera_stream(uint32_t idx, uint32_t on)
{
    int ret = 0;

    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return -EINVAL;

    struct ser_camera *cam = &cameras[idx];
    if (cam->sensor_drv == NULL)
        return -ENODEV;
    const struct sensor_drv *sensor_drv = cam->sensor_drv;

    if (!on) {
        cam->started = 0;

        if (NULL != sensor_drv->stream) {
            ret = sensor_drv->stream(&cam->sensor, on);
        }
        /* ignore ret when shutting down */

        if (cam->ti_ser) {
            ret = ub9x3_stream(cam->ti_ser, on);
        }
    } else {
        if (cam->ti_ser) {
            ret = ub9x3_stream(cam->ti_ser, on);
        }
        if (ret)
            goto out;

        if (NULL != sensor_drv->stream) {
            ret = sensor_drv->stream(&cam->sensor, on);
        }

        if (ret == 0)
        {
            if (cam->ti_ser)
            {
                ti9x4_port_forward_en_by_ser(cam->ti_ser, idx);
            }
            Safety_Cam_stream_on(idx);
        }
    }

out:
    return ret;
}

int32_t ser_camera_hotplug_diag(uint32_t idx, uint32_t on)
{
    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return -EINVAL;

    struct ser_camera *cam = &cameras[idx];

    /* Unblock hotplug thread */
    cam->started = on;

    return 0;
}

int32_t ser_camera_read_reg(uint32_t idx, uint32_t addr, uint32_t *val)
{
    int ret = 0;

    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return -EINVAL;

    if (camera_is_set_for_action(idx))
		return -EPERM;

    struct ser_camera *cam = &cameras[idx];
    if (cam->sensor_drv == NULL)
        return -ENODEV;
    const struct sensor_drv *sensor_drv = cam->sensor_drv;

    if (NULL != sensor_drv->rreg) {
        ret = sensor_drv->rreg(&cam->sensor, addr, val);
    } else {
        ret = -EPROTONOSUPPORT;
    }

    return ret;
}

int32_t ser_camera_write_reg(uint32_t idx, uint32_t addr, uint32_t val)
{
    int ret = 0;

    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return -EINVAL;

    if (camera_is_set_for_action(idx))
		return -EPERM;

    struct ser_camera *cam = &cameras[idx];
    if (cam->sensor_drv == NULL)
        return -ENODEV;
    const struct sensor_drv *sensor_drv = cam->sensor_drv;

    if (NULL != sensor_drv->wreg) {
        ret = sensor_drv->wreg(&cam->sensor, addr, val);
    } else {
        ret = -EPROTONOSUPPORT;
    }

    return ret;
}

int32_t ser_camera_write_nreg(uint32_t idx, uint16_t *buf, int nregs)
{
    int ret = 0;

    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return -EINVAL;

    if (camera_is_set_for_action(idx))
		return -EPERM;

    struct ser_camera *cam = &cameras[idx];
    if (cam->sensor_drv == NULL)
        return -ENODEV;
    const struct sensor_drv *sensor_drv = cam->sensor_drv;

    if (NULL != sensor_drv->wregs) {
        ret = sensor_drv->wregs(&cam->sensor, buf, nregs);
    } else {
        ret = -EPROTONOSUPPORT;
    }

    return ret;
}

int32_t ser_camera_write_nregs(uint32_t idx, uint8_t *buf, int nregs)
{
    int ret = 0;

    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return -EINVAL;

    if (camera_is_set_for_action(idx))
		return -EPERM;

    struct ser_camera *cam = &cameras[idx];
    if (cam->sensor_drv == NULL)
        return -ENODEV;
    const struct sensor_drv *sensor_drv = cam->sensor_drv;

    if (NULL != sensor_drv->wnregs) {
        ret = sensor_drv->wnregs(&cam->sensor, buf, nregs);
    } else {
        ret = -EPROTONOSUPPORT;
    }

    return ret;
}

int32_t ser_camera_read_nregs(uint32_t idx, uint16_t addr, uint8_t *buf, int nregs)
{
    int ret = 0;

    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return -EINVAL;

    struct ser_camera *cam = &cameras[idx];
    if (cam->sensor_drv == NULL)
        return -ENODEV;
    const struct sensor_drv *sensor_drv = cam->sensor_drv;

    if (NULL != sensor_drv->rnregs) {
        ret = sensor_drv->rnregs(&cam->sensor, addr, buf, nregs);
    } else {
        ret = -EPROTONOSUPPORT;
    }

    return ret;
}

int32_t ser_camera_set_fps(uint32_t channel_mask, int fps)
{
    int idx;
    int ret = 0;

    if (channel_mask == 0x00)
        return -EINVAL;

    for (idx = 0; idx < ISS_SENSORS_MAX_CHANNEL; idx++) {
        if (!(channel_mask & BIT(idx)))
            continue;

        struct ser_camera *cam = &cameras[idx];
        if (cam->sensor_drv == NULL)
            continue;

        if (cam->ti_ser) {
            ret = ub9x3_set_fsync_fps(cam->ti_ser, fps);
            if (ret)
                goto out;
        }

        #if 0
            /* TODO: */
            const struct sensor_drv *sensor_drv = cam->sensor_drv;
            if (NULL != sensor_drv->set_fps) {
                ret = sensor_drv->set_fps(&cam->sensor, addr, buf, nregs);
            } else {
                ret = -EPROTONOSUPPORT;
            }
        #endif
    }

out:
    return ret;
}

int32_t ser_camera_deser_read_reg(uint32_t idx, uint8_t addr, uint8_t *val)
{
    int ret = 0;

    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return -EINVAL;

    struct ser_camera *cam = &cameras[idx];
    if (cam->sensor_drv == NULL)
        return -ENODEV;

    if (cam->ti_ser) {
        ret = ub960_read(cam->ti_ser, addr, val);
    } else {
        ret = -EPROTONOSUPPORT;
    }

    return ret;
}

int32_t ser_camera_deser_write_reg(uint32_t idx, uint8_t addr, uint8_t val)
{
    int ret = 0;

    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return -EINVAL;

    struct ser_camera *cam = &cameras[idx];
    if (cam->sensor_drv == NULL)
        return -ENODEV;

    if (cam->ti_ser) {
        ret = ub960_write(cam->ti_ser, addr, val);
    } else {
        ret = -EPROTONOSUPPORT;
    }

    return ret;
}

int32_t ser_camera_get_mipi_diagnostics(uint32_t idx, IssSensor_MipiStatus *mipi_sts)
{
    int ret = 0;

    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return -EINVAL;

    struct ser_camera *cam = &cameras[idx];
    if (cam->sensor_drv == NULL || cam->ti_ser == NULL)
        return -ENODEV;

    if (cam->ti_ser) {
        ret = ub9x3_mipi_diagnostics(cam->ti_ser, mipi_sts);
    }

    return ret;
}

const struct sensor_drv *ser_camera_getdrv(uint32_t idx)
{
    struct ser_camera *cam = &cameras[idx];

    if (!cam->started)
        return NULL;

    return cam->sensor_drv;
}

int32_t ser_camera_deinit(uint32_t idx)
{
    if (idx >= ISS_SENSORS_MAX_CHANNEL)
        return -EINVAL;

    struct ser_camera *cam = &cameras[idx];

    /* drivers power off is called from ser_camera_power */
    /* delete link to all drivers, serializers */
    cam->sensor_drv = NULL;
    cam->ti_ser = NULL;
    cam->max_ser = NULL;
    cam->started = 0;

    return 0;
}
