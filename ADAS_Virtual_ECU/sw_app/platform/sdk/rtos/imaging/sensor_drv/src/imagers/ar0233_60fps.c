/*
 * ON Semiconductor AR0233 sensor camera driver
 *
 * Copyright (C) 2018-2021 Cogent Embedded, Inc.
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

struct ar0233_reg {
	u16	reg;
	u16	val;
};

#include "ar0233_60fps.h"
#include "ar0233_rev1.h"
#include "ar0233_rev2.h"

static const int ar0233_i2c_addr[] = {0x10, 0x20};

#define AR0233_PID_REG		0x3000
#define AR0233_REV_REG		0x31FE
#define AR0233_PID		0x0956

#define ISS_SENSOR_AR0233_FEATURES	(ISS_SENSOR_FEATURE_MANUAL_EXPOSURE | \
					 ISS_SENSOR_FEATURE_MANUAL_GAIN | \
					 ISS_SENSOR_FEATURE_LINEAR_MODE)

struct ar0233_priv {
	int			fps_denominator;
	int			fps_numerator;
	int			init_complete;
	u16			rev;
	u8			id[6];
	bool			emb_enable;
	/* serializers */
	int			ti9x4_addr;
	int			ti9x3_addr;
	int			port;
	int			trigger;
	int			vts;

	void			*camera;
};

static struct ar0233_priv	ar0233_devs[ISS_SENSORS_MAX_CHANNEL];

static int extclk = 27;
static char *mode = "seplus60";
static int trigger = 0;

static IssSensor_CreateParams  ar0233_CreatePrms = {
	.name = SENSOR_AR0233_ONSEMI,
	.i2cInstId = { 6, 1 },
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
			.width = AR0233_MAX_WIDTH,
			.height = AR0233_MAX_HEIGHT,
			.num_exposures = 1,
			.line_interleaved = vx_false_e,
			.format = {
				[0] = {
					.pixel_container = TIVX_RAW_IMAGE_16_BIT,
					.msb = 11
				},
			},
			.meta_height_before = AR0233_EMB_LINES / 2,
			.meta_height_after = AR0233_EMB_LINES / 2,
		},
		.features = ISS_SENSOR_AR0233_FEATURES,
		.aewbMode = ALGORITHMS_ISS_AEWB_MODE_NONE,
		.fps = 60,
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
	.dccId = 233,
};

static struct ti9x4_config ar0233_ub9x4_cfg[2] = {
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
		.gpio = {TI9X4_REMOTE_GPIO_CONST0, TI9X4_REMOTE_GPIO_CONST0, TI9X4_REMOTE_GPIO_FSYNC, TI9X4_REMOTE_GPIO_CONST0},
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
		.gpio = {0, 0, 2, 0},
		.ti9x3_addr_map = {SER_4_I2C_ALIAS, SER_5_I2C_ALIAS, SER_6_I2C_ALIAS, SER_7_I2C_ALIAS},
		.vc_map = {
			UB960_VC_MAP(0, 0, 0, 0),
			UB960_VC_MAP(1, 1, 1, 1),
			UB960_VC_MAP(2, 2, 2, 2),
			UB960_VC_MAP(3, 3, 3, 3)
		}
	}
};

static int ar0233_set_regs(struct i2c_client *client, const struct ar0233_reg **pregs)
{
	const struct ar0233_reg *regs;
	int i, j;

	for (j = 0; ; j++) {
		regs = pregs[j];

		if (!pregs[j])
			break;

		for (i = 0; ; i++) {
			if (!regs[i].reg && !regs[i].val)
				break;

			if (regs[i].reg == AR0233_DELAY) {
				mdelay(regs[i].val);
				continue;
			}

			reg16_write16(client, regs[i].reg, regs[i].val);
		}
	}

	return 0;
}

static void ar0233_otp_id_read(struct i2c_client *client)
{
	struct ar0233_priv *priv = i2c_get_clientdata(client);
	int i;
	u16 val = 0;

	/* read camera id from ar014x OTP memory */
	reg16_write16(client, 0x3054, 0x400);
	reg16_write16(client, 0x304a, 0x110);
	usleep_range(25000, 25500); /* wait 25 ms */

	for (i = 0; i < 6; i += 2) {
		/* first 4 bytes are equal on all ar014x */
		reg16_read16(client, 0x3800 + i + 4, &val);
		priv->id[i]     = val >> 8;
		priv->id[i + 1] = val & 0xff;
	}
}

static int ar0233_detect(struct i2c_client *client, void *camera)
{
	struct ar0233_priv *priv;
	struct ser_camera *cam = (struct ser_camera *)camera;
	int dev = cam->channel + cam->slot * 4;
	u16 val = 0;
	u16 pid = 0;
	int ret = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE(ar0233_i2c_addr); i++) {
		ret = ser_camera_i2c_set_mapping(camera, 0, client->addr, ar0233_i2c_addr[i]);
		if (ret < 0)
			goto out;

		/* check product ID */
		reg16_read16(client, AR0233_PID_REG, &pid);

		if (pid == AR0233_PID)
			break;
	}

	if (pid != AR0233_PID) {
		ret = -ENODEV;
		goto out;
	}

	priv = &ar0233_devs[dev];
	priv->camera = camera;
	i2c_set_clientdata(client, priv);
	client->dev.name = "AR0233";

	/* check revision  */
	reg16_read16(client, AR0233_REV_REG, &val);
	priv->rev = val & 0xf;
	/* Read OTP IDs */
	ar0233_otp_id_read(client);

	dev_info(&client->dev, "PID %x (r%x), res %dx%d, OTP_ID %02x:%02x:%02x:%02x:%02x:%02x\n",
			       pid, priv->rev, AR0233_DEFAULT_WIDTH, AR0233_DEFAULT_HEIGHT, priv->id[0], priv->id[1], priv->id[2], priv->id[3], priv->id[4], priv->id[5]);

	memcpy(ar0233_CreatePrms.sensorInfo.otp_id[dev], priv->id, 6);
out:
	return ret;
}

static int32_t ar0233_power(struct i2c_client *client, uint32_t on)
{
	struct ar0233_priv *priv;
	int ret = 0;

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	return ret;
}

static int32_t ar0233_config(struct i2c_client *client, uint32_t feat)
{
	struct ar0233_priv *priv;
	u16 val = 0;
	int ret = 0;

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	/* Program wizard registers */
	switch (priv->rev) {
	case 0x1:
		ar0233_set_regs(client, ar0233_regs_hdr_mipi_12bit_30fps_rev1);
		break;
	case 0x2:
		if (strcmp(mode, "hdr") == 0) {
			if (extclk == 27) {
				ar0233_regs_hdr_mipi_12bit_30fps_rev2[4] = ar0233_rev2_pll_27_102_4lane_12b;
				ar0233_regs_seplus_mipi_12bit_30fps_rev2[2] = ar0233_rev2_pll_27_102_4lane_12b;
			}
			ar0233_set_regs(client, ar0233_regs_hdr_mipi_12bit_30fps_rev2);
		} else if (strcmp(mode, "seplus") == 0) {
			// If R0x300E version is earlier than 0x202D, then it should be load
			reg16_read16(client, 0x300e, &val);
			if (val >= 0x202d) {
				ar0233_regs_seplus_mipi_12bit_60fps_rev2[4] = ar0233_rev2_empty;
				ar0233_regs_seplus_mipi_12bit_60fps_rev2[8] = ar0233_rev2_empty;
				ar0233_regs_seplus_mipi_12bit_60fps_rev2[9] = ar0233_rev2_empty;
			}

			ar0233_regs_seplus_mipi_12bit_60fps_rev2[1] = ar0233_rev2_Full_resolution;
			ar0233_regs_seplus_mipi_12bit_60fps_rev2[2] = ar0233_rev2_pll_27_102_4lane_12b;
			ar0233_regs_seplus_mipi_12bit_60fps_rev2[3] = ar0233_rev2_mipi_12bit_4lane;
			ar0233_regs_seplus_mipi_12bit_60fps_rev2[10] = ar0233_rev2_SE_Lin_T2_12bit_30fps;
			ar0233_set_regs(client, ar0233_regs_seplus_mipi_12bit_60fps_rev2);
			if (extclk != 27) {
				reg16_read16(client, 0x3030, &val);
				reg16_write16(client, 0x3030, val * 27 / extclk + 1);
			}
		} else if (strcmp(mode, "seplus60") == 0) {
			// If R0x300E version is earlier than 0x202D, then it should be load
			reg16_read16(client, 0x300e, &val);
			if (val >= 0x202d) {
				ar0233_regs_seplus_mipi_12bit_60fps_rev2[4] = ar0233_rev2_empty;
				ar0233_regs_seplus_mipi_12bit_60fps_rev2[8] = ar0233_rev2_empty;
				ar0233_regs_seplus_mipi_12bit_60fps_rev2[9] = ar0233_rev2_empty;
			}

			ar0233_set_regs(client, ar0233_regs_seplus_mipi_12bit_60fps_rev2);
			if (extclk != 27) {
				reg16_read16(client, 0x3030, &val);
				reg16_write16(client, 0x3030, val * 27 / extclk + 1);
			}
		} else
			dev_err(&client->dev, "Unsupported mode %s\n", mode);
		break;
	default:
		dev_err(&client->dev, "Unsupported chip revision\n");
		ret = -EINVAL;
		goto out;
	}

	priv->trigger = trigger;

	/* Enable trigger */
	if (priv->trigger >= 0 && priv->trigger < 4) {
		reg16_write16(client, 0x340A, (~(BIT(priv->trigger) << 4)) & 0xf0);	/* GPIO_CONTROL1: GPIOn input enable */
		reg16_write16(client, 0x340C, (0x2 << 2*priv->trigger));		/* GPIO_CONTROL2: GPIOn is trigger */
		reg16_write16(client, 0x30CE, 0x0120);					/* TRIGGER_MODE */
		//reg16_write16(client, 0x30DC, 0x0120);				/* TRIGGER_DELAY */
	}

	/* Enable stream */
	reg16_read16(client, 0x301a, &val);	// read inital reset_register value
	val |= (1 << 8);			/* GPI pins enable */
	val |= (1 << 2);			// Set streamOn bit
	reg16_write16(client, 0x301a, val);	// Start Streaming

out:
	return ret;
}

static int32_t ar0233_stream(struct i2c_client *client, uint32_t on)
{
	struct ar0233_priv *priv;
	int ret = 0;

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	return ret;
}

static int32_t ar0233_rreg(struct i2c_client *client, uint32_t addr, uint32_t *val)
{
	struct ar0233_priv *priv;
	uint16_t tmp;
	int ret = 0;

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	ret = reg16_read16(client, addr, &tmp);
	if (!ret && val)
		*val = tmp;

	return ret;
}

static int32_t ar0233_wreg(struct i2c_client *client, uint32_t addr, uint32_t val)
{
	struct ar0233_priv *priv;
	int ret = 0;

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	ret = reg16_write16(client, addr, val & 0xffff);

	return ret;
}

static int32_t ar0233_wnregs(struct i2c_client *client, uint8_t *buf, int nregs)
{
	int ret = 0;
	struct ar0233_priv *priv;

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	ret = i2c_tx_array(client, buf, nregs);

	return ret;
}

static int32_t ar0233_rnregs(struct i2c_client *client, uint16_t addr, uint8_t *buf, int nregs)
{
	int ret = 0;
	struct ar0233_priv *priv;
	uint8_t tx[2];

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	tx[0] = addr >> 8; // msb
	tx[1] = addr & 0xff; //lsb
	ret = i2c_tx_array(client, tx, 2);
	if (ret < 0)
		goto out;
	ret = i2c_rx_array(client, buf, nregs);

out:
	return ret;
}

struct sensor_drv ar0233_60fps_drv = {
	.name = "ar0233_1920x1080@60",
	.params = &ar0233_CreatePrms,
	.power = ar0233_power,
	.detect = ar0233_detect,
	.config = ar0233_config,
	.stream = ar0233_stream,
	.rreg = ar0233_rreg,
	.wreg = ar0233_wreg,
	.wnregs = ar0233_wnregs,
	.rnregs = ar0233_rnregs,
	.ub9x4_cfg = ar0233_ub9x4_cfg,
};
