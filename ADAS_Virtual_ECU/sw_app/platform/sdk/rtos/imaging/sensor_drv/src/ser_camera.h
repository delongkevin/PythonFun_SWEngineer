#ifndef _SEC_CAMERA_H_
#define _SEC_CAMERA_H_

#include "iss_sensors.h"
#include "i2c_helpers.h"

/*******************************************************************************
 *  Camera side API
 ******************************************************************************/

struct sensor_drv {
	char		name[ISS_SENSORS_MAX_NAME];
	IssSensor_CreateParams *params;
	int32_t 	(*detect)(struct i2c_client	*client, void *camera);
	int32_t 	(*power)(struct i2c_client	*client, uint32_t on);
	int32_t		(*config)(struct i2c_client *client, uint32_t feat);
	int32_t		(*stream)(struct i2c_client *client, uint32_t on);
	int32_t		(*rreg)(struct i2c_client *client, uint32_t addr, uint32_t *val);
	int32_t		(*wreg)(struct i2c_client *client, uint32_t addr, uint32_t val);
	int32_t		(*wregs)(struct i2c_client *client, uint16_t *buf, int nregs);
	int32_t		(*wnregs)(struct i2c_client *client, uint8_t *buf, int nregs);
	int32_t		(*rnregs)(struct i2c_client *client, uint16_t addr, uint8_t *buf, int nregs);

	/* common settings */
	int32_t		pwr_delay;	/* delay before sensor is accesable */

	const struct ti9x4_config *ub9x4_cfg;
	const struct max96712_config *max96712_cfg;
};

struct ser_camera {
	struct i2c_client	*ti_ser;
	struct i2c_client	*max_ser;

	struct i2c_client	sensor;

	int			slot;
	int			channel;
	int			started;

	/* special features flags */
	uint32_t			feat;

	const struct sensor_drv	*sensor_drv;
};

/*******************************************************************************
 *  Camera sensor side API
 ******************************************************************************/
int ser_camera_i2c_set_mapping(void *_cam, uint32_t n, uint8_t src, uint8_t dst);
int ser_camera_i2c_forwarding(void *_cam, uint32_t enable);

/*******************************************************************************
 *  Serializers side API
 ******************************************************************************/
int32_t ser_camera_probe_fpdlink(struct i2c_client *ser_client, int slot, int channel, const struct sensor_drv *drv, int is_config);
int32_t ser_camera_probe_fpdlink_broadcast(struct i2c_client *ser_client, int slot, const struct sensor_drv *drv);
int32_t ser_camera_probe_gmsl(struct i2c_client *ser_client, int slot, int channel, const struct sensor_drv *drv);

/*******************************************************************************
 *  ISS side API
 ******************************************************************************/
int32_t ser_camera_get_drv_list(char * buf, int size);
int32_t ser_camera_get_drv_list2(char * buf, int size);
int32_t ser_camera_get_sensor_info(char *name, IssSensor_CreateParams *sensor_prms);

int32_t ser_camera_power(uint32_t idx, uint32_t on);
int32_t ser_camera_configure(uint32_t idx, uint32_t feat);
int32_t ser_camera_board_probe(char *sensor_name, uint32_t channel_mask);
int32_t ser_camera_eeprom_init(void);
int32_t ser_camera_board_deinit(uint32_t channel_mask);
int32_t ser_camera_stream(uint32_t idx, uint32_t on);
int32_t ser_camera_hotplug_diag(uint32_t idx, uint32_t on);
int32_t ser_camera_read_reg(uint32_t idx, uint32_t addr, uint32_t *val);
int32_t ser_camera_write_reg(uint32_t idx, uint32_t addr, uint32_t val);
int32_t ser_camera_write_nreg(uint32_t idx, uint16_t *buf, int nregs);
int32_t ser_camera_write_nregs(uint32_t idx, uint8_t *buf, int nregs);
int32_t ser_camera_read_nregs(uint32_t idx, uint16_t addr, uint8_t *buf, int nregs);
int32_t ser_camera_set_fps(uint32_t channel_mask, int fps);
int32_t ser_camera_deser_read_reg(uint32_t idx, uint8_t addr, uint8_t *val);
int32_t ser_camera_deser_write_reg(uint32_t idx, uint8_t addr, uint8_t val);
const struct sensor_drv *ser_camera_getdrv(uint32_t idx);
int32_t ser_camera_get_mipi_diagnostics(uint32_t idx, IssSensor_MipiStatus *mipi_sts);
int32_t ser_camera_deinit(uint32_t idx);

#endif /* _SEC_CAMERA_H_ */
