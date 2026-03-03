/*
 * Dummy sensor camera driver
 *
 * Copyright (C) 2019-2021 Cogent Embedded, Inc.
 */

#include <iss_sensors.h>
#include <iss_sensor_if.h>
#include <iss_sensor_priv.h>

#include "ub960.h"
#include "ser_camera.h"
#include "dev_helpers.h"
#include "i2c_helpers.h"
#include "type_helpers.h"
#include "errno.h"

#define ISS_SENSOR_DUMMY_FEATURES      (ISS_SENSOR_FEATURE_MANUAL_EXPOSURE | \
                                        ISS_SENSOR_FEATURE_MANUAL_GAIN | \
                                        ISS_SENSOR_FEATURE_LINEAR_MODE)

struct dummy_priv {
	u8				id[6];
	int				max_width;
	int				max_height;
	const char *			media_bus_format;

	void				*camera;
};

static struct dummy_priv  dummy_devs[ISS_SENSORS_MAX_CHANNEL];

static int width = 1024;
static int height = 768;
static char *mbus = "yuyv";

static IssSensor_CreateParams dummy_CreatePrms = {
	.name = "dummy",
	.i2cInstId = { 1, 1 },
	.i2cAddrSensor = {
		SENSOR_0_I2C_ALIAS, SENSOR_1_I2C_ALIAS, SENSOR_2_I2C_ALIAS, SENSOR_3_I2C_ALIAS,
		SENSOR_4_I2C_ALIAS, SENSOR_5_I2C_ALIAS, SENSOR_6_I2C_ALIAS, SENSOR_7_I2C_ALIAS
	},
	.i2cAddrSer = {
		SER_0_I2C_ALIAS, SER_1_I2C_ALIAS, SER_2_I2C_ALIAS, SER_3_I2C_ALIAS,
		SER_4_I2C_ALIAS, SER_5_I2C_ALIAS, SER_6_I2C_ALIAS, SER_7_I2C_ALIAS
	},
	/*IssSensor_Info*/
	.sensorInfo = {
		.raw_params = {
			.width = 1024,
			.height = 768,
			.num_exposures = 1,
			.line_interleaved = vx_false_e,
			.format = {
				[0] = {
					.pixel_container = TIVX_RAW_IMAGE_16_BIT,
					.msb = 11,
				},
			},
			.meta_height_before = 0,
			.meta_height_after = 0,
		},
		.features = ISS_SENSOR_DUMMY_FEATURES,
		.aewbMode = ALGORITHMS_ISS_AEWB_MODE_NONE,
		.fps = 30,
		.numDataLanes = 4,
		.dataLanesMap = {1, 2, 3, 4},
		.dataLanesPolarity = {0, 0, 0, 0},
		.csi_ddr_clock = 1600,
		.otp_id = {
			{'d', 'u', 'm', 'm', 'y', '0'}, {'d', 'u', 'm', 'm', 'y', '1'}, {'d', 'u', 'm', 'm', 'y', '2'}, {'d', 'u', 'm', 'm', 'y', '3'},
			{'d', 'u', 'm', 'm', 'y', '4'}, {'d', 'u', 'm', 'm', 'y', '5'}, {'d', 'u', 'm', 'm', 'y', '6'}, {'d', 'u', 'm', 'm', 'y', '7'},
		},
	},
	.num_channels = 8,
	.dccId = 12345,
};

static struct ti9x4_config dummy_ub9x4_cfg[2] = {
	[0] = {
		.slot = 0,
		.links = 4,
		.lanes = 4, // Deser -> SoC CSIrx lanes used
		.ser_lanes = 4, // Sensor -> Serializer lanes used
		.csi_rate = 1600,
		.ref_clk = 23304200, /* 23.3042 MHz */
		.is_coax = 1,
		.dvp_bus = 0,
		.dvp_lsb = 0,
		.hsync = 0,
		.vsync = 1,
		.fc_mode = TI9X3_FC_MODE_CSI_SYNC,
		.bc_freq = TI9X4_BC_FREQ_50,
		.ser_id = {TI953_ID, TI953_ID, TI953_ID, TI953_ID},
		.forwarding_mode = FORWARDING_MODE_ROUND_ROBIN,
		.gpio = {TI9X4_REMOTE_GPIO_CONST0, TI9X4_REMOTE_GPIO_CONST0, TI9X4_REMOTE_GPIO_CONST0, TI9X4_REMOTE_GPIO_CONST0},
		.ti9x3_addr_map = {SER_0_I2C_ALIAS, SER_1_I2C_ALIAS, SER_2_I2C_ALIAS, SER_3_I2C_ALIAS},
		.vc_map = {
			UB960_VC_MAP(0, 0, 0, 0),
			UB960_VC_MAP(1, 1, 1, 1),
			UB960_VC_MAP(2, 2, 2, 2),
			UB960_VC_MAP(3, 3, 3, 3)
		}
	},
	[1] = {
		.slot = 1,
		.links = 4,
		.lanes = 4, // Deser -> SoC CSIrx lanes used
		.ser_lanes = 4, // Sensor -> Serializer lanes used
		.csi_rate = 1600,
		.ref_clk = 23304200, /* 23.3042 MHz */
		.is_coax = 1,
		.dvp_bus = 0,
		.dvp_lsb = 0,
		.hsync = 0,
		.vsync = 1,
		.ser_id = {TI953_ID, TI953_ID, TI953_ID, TI953_ID},
		.forwarding_mode = FORWARDING_MODE_ROUND_ROBIN,
		.gpio = {0, 0, 0, 0},
		.ti9x3_addr_map = {SER_4_I2C_ALIAS, SER_5_I2C_ALIAS, SER_6_I2C_ALIAS, SER_7_I2C_ALIAS},
		.vc_map = {
			UB960_VC_MAP(0, 0, 0, 0),
			UB960_VC_MAP(1, 1, 1, 1),
			UB960_VC_MAP(2, 2, 2, 2),
			UB960_VC_MAP(3, 3, 3, 3)
		}
	}
};

static inline struct dummy_priv *to_dummy(struct i2c_client *client)
{
	return i2c_get_clientdata(client);
}

static int32_t dummy_s_stream(struct i2c_client *client, uint32_t enable)
{
	return 0;
}

static void dummy_otp_id_read(struct i2c_client *client)
{
	struct dummy_priv *priv = to_dummy(client);

	/* dummy camera id */
	priv->id[0] = 'd';
	priv->id[1] = 'u';
	priv->id[2] = 'm';
	priv->id[3] = 'm';
	priv->id[4] = 'y';
	priv->id[5] = '.';
}

static int dummy_initialize(struct i2c_client *client, void *camera)
{
	struct dummy_priv *priv = to_dummy(client);
	struct ser_camera *cam = (struct ser_camera *)camera;
	int dev = cam->channel + cam->slot * 4;

#if 0
	setup_i2c_translator(client, priv->ser_addr, 0x10);
#endif
	/* Read OTP IDs */
	dummy_otp_id_read(client);

	dev_info(&client->dev, "Dummy camera sensor, res %dx%d, mbus %s, OTP_ID %02x:%02x:%02x:%02x:%02x:%02x\n",
		 priv->max_width, priv->max_height, priv->media_bus_format, priv->id[0], priv->id[1], priv->id[2], priv->id[3], priv->id[4], priv->id[5]);

	memcpy(dummy_CreatePrms.sensorInfo.otp_id[dev], priv->id, 6);

	return 0;
}

static int dummy_parse_dt(struct i2c_client *client, struct dummy_priv *priv)
{
	priv->max_width = width;
	priv->max_height = height;
	priv->media_bus_format = mbus;

	if (width != 1920)
		priv->max_width = width;
	if (height != 1080)
		priv->max_height = height;

	return 0;
}

static int dummy_probe(struct i2c_client *client, void *camera)
{
	struct dummy_priv *priv;
	int ret;
	struct ser_camera *cam = (struct ser_camera *)camera;
	int dev = cam->channel + cam->slot * 4;

	priv = &dummy_devs[dev];
	priv->camera = camera;
	i2c_set_clientdata(client, priv);
	client->dev.name = "dummy";

	ret = dummy_parse_dt(client, priv);
	if (ret)
		goto cleanup;

	ret = dummy_initialize(client, camera);
	if (ret < 0)
		goto cleanup;

	return 0;

cleanup:
	return -ENODEV;
}
static int32_t dummy_power(struct i2c_client *client, uint32_t on)
{
	return 0;
}

static int32_t dummy_config(struct i2c_client *client, uint32_t feat)
{
	return 0;
}
struct sensor_drv dummy_drv = {
	.name = "dummy",
	.params = &dummy_CreatePrms,
	.power = dummy_power,
	.detect = dummy_probe,
	.config = dummy_config,
	.stream = dummy_s_stream,
	.ub9x4_cfg = dummy_ub9x4_cfg,
};
