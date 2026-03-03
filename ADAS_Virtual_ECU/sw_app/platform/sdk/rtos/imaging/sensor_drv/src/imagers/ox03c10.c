/*
 * OmniVision OX03C10 sensor camera driver
 *
 * Copyright (C) 2022 Cogent Embedded, Inc.
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
#include "safety.h"

#include "ox03c10.h"
#include "ox03c10_crc16.h"
#include "ox03c10_otp_crc.h"

#define REG_ACCESS_WITH_SAFETY_RETRY

#define ISS_SENSOR_OX03C10_FEATURES (ISS_SENSOR_FEATURE_MANUAL_EXPOSURE | \
									 ISS_SENSOR_FEATURE_MANUAL_GAIN |     \
									 ISS_SENSOR_FEATURE_LINEAR_MODE)

static const int ox03c10_i2c_addr[] = {0x36};

#define OX03C10_CHIP_ID_REG_ADDR (0x300a)
#define OX03C10_CHIP_ID_REG_VAL  (0x580343)
#define OX03C10_REV_ID_REG_ADDR  (0x302a)

#define OX03C10_MASTER_FPDLINK_CLOCK 24000000 //_MHz(24)

#define RETURN_ON_ERROR(err) \
	({                       \
		if (err != 0)        \
		{                    \
			return err;      \
		}                    \
	})

#define RETURN_ON_ERROR_NONBROADCAST(client, err) \
	({                                            \
		if (err && !is_broadcast(client))         \
		{                                         \
			return err;                           \
		}                                         \
	})
struct ox03c10_priv
{
	u8    id[6];
	u32   pid;
	u8    rev;
	int   sclk;
	int   vts;
	float fps;

	void  *camera;
};

static struct ox03c10_priv ox03c10_devs[ISS_SENSORS_MAX_CHANNEL + 1];

static IssSensor_CreateParams ox03c10_1280_30fps_CreatePrms = {
	.name = "ox03c10",
	.i2cInstId = {1, 1},
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
			.width = OX03C10_OUT_WIDTH,
			.height = 1280,
			.num_exposures = 1,
			.line_interleaved = vx_false_e,
			.format = {
				[0] = {
					.pixel_container = TIVX_RAW_IMAGE_16_BIT,
					.msb = 11,
				},
			},
			.meta_height_before = OX03C10_META_HEIGHT_BEFORE,
			.meta_height_after = OX03C10_META_HEIGHT_AFTER,
		},
		.features = ISS_SENSOR_OX03C10_FEATURES,
		.aewbMode = ALGORITHMS_ISS_AEWB_MODE_NONE,
		.fps = 30,
		.numDataLanes = 4,
		.dataLanesMap = {1, 2, 3, 4},
		.dataLanesPolarity = {0, 0, 0, 0},
		.csi_ddr_clock = 1600,
		.otp_id = {
			{'d', 'u', 'm', 'm', 'y', '0'},
			{'d', 'u', 'm', 'm', 'y', '1'},
			{'d', 'u', 'm', 'm', 'y', '2'},
			{'d', 'u', 'm', 'm', 'y', '3'},
			{'d', 'u', 'm', 'm', 'y', '4'},
			{'d', 'u', 'm', 'm', 'y', '5'},
			{'d', 'u', 'm', 'm', 'y', '6'},
			{'d', 'u', 'm', 'm', 'y', '7'},
		},
	},
	.num_channels = 8,
	.dccId = 0x3c,
};

static int32_t ox03c10_stream(struct i2c_client *client, uint32_t on);
static int32_t ox03c10_rnregs(struct i2c_client *client, uint16_t addr, uint8_t *buf, int nregs);

static struct ti9x4_config ox03c10_ub9x4_cfg[2] = {
	[0] = {
		.slot = 0,
		.links = 4,
		.lanes = 4,		// Deser -> SoC CSIrx lanes used
		.ser_lanes = 2, // Sensor -> Serializer lanes used
		.csi_rate = 1600,
		.ref_clk = OX03C10_MASTER_FPDLINK_CLOCK,
		.is_coax = 1,
		.dvp_bus = 0,
		.dvp_lsb = 0,
		.hsync = 0,
		.vsync = 0,
		.fc_mode = TI9X3_FC_MODE_CSI_NONSYNC_AON,
		.bc_freq = TI9X4_BC_FREQ_10,
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
	}
};

static uint8_t sensors_addr[4] = {SENSOR_0_I2C_ALIAS, SENSOR_1_I2C_ALIAS, SENSOR_2_I2C_ALIAS, SENSOR_3_I2C_ALIAS};

static inline bool is_broadcast(struct i2c_client *client)
{
	return client->addr == 0x6f;
}

static int32_t ox03c10_read_crc(struct i2c_client *client, uint16_t *crc)
{
	int32_t ret = 0;
	struct i2c_client c = *client;

	/* Read CRC registers to reset them */
	if (is_broadcast(client))
	{
		for (int i = 0; i < 4; i++)
		{
			if (camera_is_set_for_action(i))
			{
				continue;
			}

			c.addr = sensors_addr[i];
			if (reg16_read16_retry3(&c, OX03C10_SCCB_CRC_H_REG, &crc[i]))
			{
				ret |= (1 << i);
			}
		}
		ti9x4_link_boot_shutdown(ret);
	}
	else
	{
		ret = reg16_read16_retry3(client, OX03C10_SCCB_CRC_H_REG, &crc[0]);
	}

	return ret;
}

static int32_t ox03c10_check_crc(struct i2c_client *client, ox03c_crc_t control_crc)
{
	int32_t           ret = 0;
	int               i2c_ret;
	struct i2c_client c = *client;
	uint16_t          sensor_crc;

	if (is_broadcast(client))
	{
		for (int i = 0; i < 4; i++)
		{
			if (!ox03c10_devs[i].camera || camera_is_set_for_action(i))
			{
				dev_info(&client->dev, "CAM[%d]: Skip CRC check for disabled camera\n", i);
				continue;
			}
			c.addr = sensors_addr[i];
			i2c_ret = reg16_read16(&c, OX03C10_SCCB_CRC_H_REG, &sensor_crc);
			if (i2c_ret || (control_crc != sensor_crc))
			{
				dev_info(&client->dev, "CAM[%d]: Missed sensor or SCCB CRC mismatch!: CRC 0x%04x, sensor CRC 0x%04x (ret = %d)\n", i, control_crc, sensor_crc, i2c_ret);
				ret |= 1 << i;
			}
		}
	}
	else
	{
		i2c_ret = reg16_read16(client, OX03C10_SCCB_CRC_H_REG, &sensor_crc);
		if (i2c_ret || (control_crc != sensor_crc))
		{
			dev_info(&client->dev, "CAM[0x%x]: Missed sensor or SCCB CRC mismatch!: CRC 0x%04x, sensor CRC 0x%04x (ret = %d)\n", client->addr, control_crc, sensor_crc, i2c_ret);
			ret = 1;
		}
	}

	return ret;
}

static int32_t i2c_tx_retry_helper(struct i2c_client *client, uint8_t *tx, uint32_t len)
{
	int32_t ret = 0;

	if (is_broadcast(client))
	{
		struct ox03c10_priv *priv = i2c_get_clientdata(client);
		struct ser_camera *cam = (struct ser_camera *)priv->camera;
		uint32_t lock_sts, lock_sts_chg, bcc_err_sts;
		int count = 1;
		while (count-- != 0)
		{
			i2c_tx_array(client, tx, len);
			ti9x4_status_chg_by_ser(cam->ti_ser, &lock_sts, &lock_sts_chg, &bcc_err_sts);
			if (bcc_err_sts == 0)
			{
				break;
			}
		}
		ti9x4_link_boot_shutdown(bcc_err_sts);
		ret = bcc_err_sts;
	}
	else
	{
		ret = i2c_tx_array_retry3(client, tx, len);
	}

	return ret;
}

static int32_t reg16_write_crc(struct i2c_client *client, uint16_t reg, uint8_t val)
{
	int32_t     ret;
	uint8_t     i2c_data[3];
	const int   reg_len = 2;
	ox03c_crc_t crc16;
	uint16_t    crc_sensors[4];

	/* Read CRC registers to reset them */
	ox03c10_read_crc(client, crc_sensors);

	/* MSB first */
    for (int i = 0; i < reg_len; i++)
	{
        i2c_data[reg_len - i - 1] = (reg >> (i * 8)) & 0xff;
    }
	i2c_data[2] = val;
	ret = i2c_tx_retry_helper(client, i2c_data, sizeof(i2c_data));
	if (ret)
	{
		return ret;
	}

	/* Calculate CRC for the original transaction */
	crc16 = ox03c_crc_init();
	crc16 = ox03c_crc_update(crc16, (uint8_t *)&reg + 1, 1);
	crc16 = ox03c_crc_update(crc16, (uint8_t *)&reg, 1);
	crc16 = ox03c_crc_update(crc16, &val, 1);
	crc16 = ox03c_crc_finalize(crc16);

	return ox03c10_check_crc(client, crc16);
}

static int32_t ox03c10_set_regs(struct i2c_client *client,
								const struct ox03c10_reg *regs, int nr_regs)
{
	int l = 0;
	int32_t ret = 0;
	int base = 0x0000;
	uint8_t buf[OX03C10_MAX_CONT_I2C_WRITE + 2];
	struct ox03c10_priv *priv = i2c_get_clientdata(client);
	int i;

	for (i = 0; i < nr_regs; i++)
	{
		/* cache VTS */
		if (regs[i].reg == 0x380e)
			priv->vts = (priv->vts & ~0xff00) | ((u16)regs[i].val << 8);
		if (regs[i].reg == 0x380f)
			priv->vts = (priv->vts & ~0x00ff) | regs[i].val;

		if (((base + l) != regs[i].reg) || (l >= OX03C10_MAX_CONT_I2C_WRITE) || (regs[i].reg == OX03C10_DELAY))
		{
			if (l)
			{
				/* write chained */
				ret |= i2c_tx_retry_helper(client, buf, l + 2);
				l = 0;
				base = 0x0000;
				if (ret && !is_broadcast(client))
				{
					break;
				}
			}
			if (regs[i].reg == OX03C10_DELAY)
			{
				mdelay(regs[i].val);
				continue;
			}

			/* head */
			buf[0] = regs[i].reg >> 8 & 0xff;
			buf[1] = regs[i].reg >> 0 & 0xff;
			buf[2] = regs[i].val;
			base = regs[i].reg;
			l = 1;
		}
		else
		{
			buf[2 + l] = regs[i].val;
			l++;
		}
	}

	if (l)
	{
		/* write chained */
		ret |= i2c_tx_retry_helper(client, buf, l + 2);
	}

	return ret;
}

static ox03c_crc_t ox03c10_regs_table_crc(const struct ox03c10_reg *regs, int nr_regs)
{
	ox03c_crc_t crc16;

	crc16 = ox03c_crc_init();

	for (int i = 0; i < nr_regs; i++)
	{
		uint16_t reg = regs[i].reg;
		uint8_t  val = regs[i].val;

		if (reg == OX03C10_DELAY)
		{
			continue;
		}

		crc16 = ox03c_crc_update(crc16, (uint8_t *)&reg + 1, 1);
		crc16 = ox03c_crc_update(crc16, (uint8_t *)&reg, 1);
		crc16 = ox03c_crc_update(crc16, &val, 1);
	}

	crc16 = ox03c_crc_finalize(crc16);

	return crc16;
}

static int32_t ox03c10_set_regs_crc(struct i2c_client *client,
									const struct ox03c10_reg *regs, int nr_regs)
{
	int         ret;
	uint16_t    crc_sensors[4];
	ox03c_crc_t crc16;

	/* Read CRC registers to reset them */
	ox03c10_read_crc(client, crc_sensors);

	/* Write registers */
	ret = ox03c10_set_regs(client, regs, nr_regs);
	if (ret)
	{
		return ret;
	}

	/* Calculate CRC for the original table */
	crc16 = ox03c10_regs_table_crc(regs, nr_regs);

	return ox03c10_check_crc(client, crc16);
}

static int32_t ox03c10_otp_read_check(struct i2c_client *client)
{
	struct ox03c10_priv *priv = i2c_get_clientdata(client);
	struct ser_camera *cam = (struct ser_camera *)priv->camera;
	int dev = cam->channel + cam->slot * 4;
	u8 val;
	u8 otp_data[OX03C10_OTP_MAX_SECTION_SIZE];
	ox03c10_otp_crc_t crc;
	u16 otp_crc;

	/*.. wait max 50 ms for OTP ID */
	const int one_sleep = 10000;
	for (int i = 0; i < (50000 / one_sleep); i++)
	{
		reg16_read(client, OX03C10_OTP_LOAD_REG, &val);
		if ((val & OX03C10_OTP_LOAD_DONE) == 0)
		{
			break;
		}
		usleep_range(one_sleep, one_sleep + 500);
	}

	if (val & OX03C10_OTP_LOAD_DONE)
	{
		return -ETIMEDOUT;
	}

	/* read and verify wafer info */
	ox03c10_rnregs(client, OX03C10_OTP_WAFER_INFO_ADDR, otp_data, OX03C10_OTP_WAFER_INFO_SIZE);
	crc = ox03c10_otp_crc_init();
	crc = ox03c10_otp_crc_update(crc, otp_data, OX03C10_OTP_WAFER_INFO_SIZE);
	crc = ox03c10_otp_crc_finalize(crc);
	reg16_read16(client, OX03C10_OTP_WAFER_INFO_CRC, &otp_crc);
	if (otp_crc != crc)
	{
		dev_info(&client->dev, "OTP WAFER INFO CRC MISMATCH 0x%x vs 0x%x\n", otp_crc, crc);
		return -EFAULT;
	}
	/* Fill in OTP ID */
	memcpy(priv->id, &otp_data[OX03C10_OTP_WAFER_ID_OFFSET], 6);
	memcpy(ox03c10_1280_30fps_CreatePrms.sensorInfo.otp_id[dev], priv->id, 6);

	/* read and verify calibration info */
	ox03c10_rnregs(client, OX03C10_OTP_CALIB_INFO_ADDR, otp_data, OX03C10_OTP_CALIB_INFO_SIZE);
	crc = ox03c10_otp_crc_init();
	crc = ox03c10_otp_crc_update(crc, otp_data, OX03C10_OTP_CALIB_INFO_SIZE);
	crc = ox03c10_otp_crc_finalize(crc);
	reg16_read16(client, OX03C10_OTP_CALIB_INFO_CRC, &otp_crc);
	if (otp_crc != crc)
	{
		dev_info(&client->dev, "OTP CALIB INFO CRC MISMATCH 0x%x vs 0x%x\n", otp_crc, crc);
		return -EFAULT;
	}

	dev_info(&client->dev, "OTP_ID %02x:%02x:%02x:%02x:%02x:%02x\n",
			 priv->id[0], priv->id[1], priv->id[2], priv->id[3], priv->id[4], priv->id[5]);

	return 0;
}

static int32_t ox03c10_detect(struct i2c_client *client, void *camera)
{
	struct ox03c10_priv *priv;
	struct ser_camera *cam = (struct ser_camera *)camera;
	int dev = cam->channel + cam->slot * 4;
	u8 val;
	u32 pid = 0;
	u8  rev_id = 0;
	int32_t ret = 0;
	int i, retry_cnt;

#define MAX_RETRY_CNT 0
	for (i = 0, retry_cnt = 0; retry_cnt <= MAX_RETRY_CNT; retry_cnt++)
	{
		int j;
		pid = 0;

		if (is_broadcast(client))
		{
			ret = ser_camera_i2c_set_mapping(camera, 1, client->addr, ox03c10_i2c_addr[i]);
			dev = ISS_SENSORS_MAX_CHANNEL;
			pid = OX03C10_CHIP_ID_REG_VAL;
			rev_id = 1;
			break;
		}
		else
		{
			ret = ser_camera_i2c_set_mapping(camera, 0, client->addr, ox03c10_i2c_addr[i]);
		}
		if (ret < 0)
			goto out;

		/* check model ID */
		for (j = 0; j < 3; j++)
		{
			ret = reg16_read_retry3(client, OX03C10_CHIP_ID_REG_ADDR + j, &val);
			if (ret)
				break;
			pid = (pid << 8) | val;
		}

		if (pid == OX03C10_CHIP_ID_REG_VAL)
		{
			reg16_read_retry3(client, OX03C10_REV_ID_REG_ADDR, &rev_id);
			break;
		}

		mdelay(1);
	}

	if (pid != OX03C10_CHIP_ID_REG_VAL)
	{
		ret = -ENODEV;
		goto out;
	}

	priv = &ox03c10_devs[dev];
	priv->camera = camera;
	i2c_set_clientdata(client, priv);
	client->dev.name = "ox03c10";

	priv->pid = pid;
	priv->rev = rev_id;

	/* Skip for Broadcast address */
	if (is_broadcast(client))
		return 0;

	dev_info(&client->dev, "PID 0x%06x (rev %x), res %dx%d\n",
			 pid, priv->rev, OX03C10_OUT_WIDTH, OX03C10_OUT_HEIGHT);

out:
	return ret;
}

static int32_t ox03c10_get_pll(struct i2c_client *client, int idx, int32_t *pll)
{
	int32_t ret;
	u8 val = 0;
	float pre_div_vals[8] = {1, 1.5, 2, 2.5, 3, 4, 6, 8};
	float tc_div_vals[8] = {1, 1.5, 2, 2.5, 3, 3.5, 4, 5};
	int mipi_div_vals[4] = {4, 5, 6, 8};
	float out;
	/* TODO: request mclk from serializer? */
	int mclk = OX03C10_MASTER_FPDLINK_CLOCK;

	if (idx == 2)
	{
		/* PLL2 */
		int pre_divp, mult, tc_pre_div;
		float pre_div, tc_div;

		ret = reg16_read_retry3(client, 0x0326, &val);
		RETURN_ON_ERROR(ret);
		pre_divp = ((val >> 7) & 0x01) + 1;

		ret = reg16_read_retry3(client, 0x0323, &val);
		RETURN_ON_ERROR(ret);
		pre_div = pre_div_vals[val & 0x07];

		ret = reg16_read_retry3(client, 0x0325, &val);
		RETURN_ON_ERROR(ret);
		mult = val;
		ret = reg16_read_retry3(client, 0x0324, &val);
		RETURN_ON_ERROR(ret);
		mult |= (val & 0x03) << 8;

		ret = reg16_read_retry3(client, 0x032A, &val);
		RETURN_ON_ERROR(ret);
		tc_pre_div = (val & 0x0f) + 1;

		ret = reg16_read_retry3(client, 0x032B, &val);
		RETURN_ON_ERROR(ret);
		tc_div = tc_div_vals[val & 0x07];

		out = (float)mclk / pre_divp / pre_div * mult / tc_pre_div / tc_div;
		dev_info(&client->dev, "PLL2: %d / %d / %.1f * %d / %d / %.1f = %.0f Hz\n",
				 mclk, pre_divp, pre_div, mult, tc_pre_div, tc_div, out);

		*pll = (int32_t)out;
	}
	else
	{
		/* PLL1 */
		int pre_divp, mult, mipi_pre_div, mipi_div;
		float pre_div;

		ret = reg16_read_retry3(client, 0x0301, &val);
		RETURN_ON_ERROR(ret);
		pre_divp = ((val >> 6) & 0x01) + 1;

		ret = reg16_read_retry3(client, 0x0303, &val);
		RETURN_ON_ERROR(ret);
		pre_div = pre_div_vals[val & 0x07];

		ret = reg16_read_retry3(client, 0x0305, &val);
		RETURN_ON_ERROR(ret);
		mult = val;
		ret = reg16_read_retry3(client, 0x0304, &val);
		RETURN_ON_ERROR(ret);
		mult |= (val & 0x03) << 8;

		ret = reg16_read_retry3(client, 0x0307, &val);
		RETURN_ON_ERROR(ret);
		mipi_pre_div = (val & 0x0f) + 1;

		out = (float)mclk / pre_divp / pre_div * mult / mipi_pre_div;
		dev_info(&client->dev, "MIPI: %d / %d / %.1f * %d / %d = %.0f MHz\n",
				 mclk, pre_divp, pre_div, mult, mipi_pre_div, out / 1000 / 1000);

		ret = reg16_read_retry3(client, 0x0306, &val);
		RETURN_ON_ERROR(ret);
		mipi_div = mipi_div_vals[val & 0x03];

		out = (float)mclk / pre_divp / pre_div * mult / mipi_pre_div / mipi_div;
		dev_info(&client->dev, "PLL1: %d / %d / %.1f * %d / %d / %d = %.0f Hz\n",
				 mclk, pre_divp, pre_div, mult, mipi_pre_div, mipi_div, out);

		*pll = (int32_t)out;
	}

	return 0;
}

static int32_t ox03c10_get_sclk(struct i2c_client *client, int *pll)
{
	int32_t ret = 0;
	u8 val;

	ret = reg16_read_retry3(client, 0x3104, &val);
	RETURN_ON_ERROR(ret);

	if (val & BIT(1))
	{
		ret = ox03c10_get_pll(client, 1, pll);
	}
	else
	{
		ret = ox03c10_get_pll(client, 2, pll);
	}

	dev_info(&client->dev, "SCLK: %d\n", *pll);

	return ret;
}

static int32_t ox03c10_config_fsin(struct i2c_client *client)
{
	struct ox03c10_reg ox03c10_setup_fsin[] = {
		{0x3009, 0x02},										  // GPIO setting to receive FSIN pulse
		{0x3015, 0x02},										  // GPIO setting to receive FSIN pulse
		{0x3822, 0x23},										  // bxxx1xxxx - Row counter and column counter will not start to count until reception of first FSIN pulse from master sensor
		{0x3823, 0x50},										  // [6] Enable receiving external VSYNC pulse [4] Setting initial value of row counter manually
		{0x3826, (OX03C10_MAX_EXP_TO_VTS_DIFF - 3 - 1) >> 8}, // 0x3826 < vts - max_exp - 3
		{0x3827, (OX03C10_MAX_EXP_TO_VTS_DIFF - 3 - 1) & 0xff},
		{0x383e, 0x81},						 // [7] disable FSIN reset mode
		{0x3881, 0x04},						 // [2] enable FSIN vts_adj mode
		{0x3882, (OX03C10_SYNC_POINT >> 8)}, // Sync point
		{0x3883, (OX03C10_SYNC_POINT & 0xff)},

		// FSIN settings update per OVT
		{0x3002, 0x04},
		{0x3834, 0xf0},
		{0x3832, 0x10},
		{0x3015, 0x0a},
		{0x3822, 0x24},
		{0x3881, 0x34},
		{0x381a, 0x00},
		{0x381b, 0x01},
		{0x3836, 0x00},
		{0x3837, 0x02},
	};

	dev_info(&client->dev, "Setup FSIN!\n");

	return ox03c10_set_regs_crc(client, ox03c10_setup_fsin, ARRAY_SIZE(ox03c10_setup_fsin));
}

static int32_t ox03c10_set_fps_internal(struct i2c_client *client, float fps, bool direct)
{
	int32_t  ret = 0;
	int      vts;
	uint16_t total_hts;
	struct ox03c10_priv *priv = i2c_get_clientdata(client);

	if (priv->sclk == 0)
		return -EINVAL;

	ret = reg16_read16_retry3(client, 0x386e, &total_hts);
	if (ret && is_broadcast(client))
	{
		ret = 0xf;
	}
	RETURN_ON_ERROR(ret);

	vts = (float)priv->sclk / total_hts / fps;

	if (!direct)
	{
		/* start recording group3 */
		ret |= reg16_write_crc(client, 0x3208, 0x03);
		RETURN_ON_ERROR_NONBROADCAST(client, ret);
	}

	/* VTS */
	ret |= reg16_write_crc(client, 0x380e, vts >> 8);
	RETURN_ON_ERROR_NONBROADCAST(client, ret);

	ret |= reg16_write_crc(client, 0x380f, vts & 0xff);
	RETURN_ON_ERROR_NONBROADCAST(client, ret);

	if (!direct)
	{
		/* stop recording */
		ret |= reg16_write_crc(client, 0x3208, 0x13);
		RETURN_ON_ERROR_NONBROADCAST(client, ret);

		/* ...and issue quick manual group 3 launch */
		ret |= reg16_write_crc(client, 0x3208, 0xe3);
		RETURN_ON_ERROR_NONBROADCAST(client, ret);
	}

	return ret;
}

static int32_t ox03c10_setup_safety(struct i2c_client *client)
{
	struct ox03c10_reg ox03c10_setup_safety_regs[] = {
		/* Online pixel test: 0x3b80 - 0x3b9f */
		{0x3b9d, 0x01}, // PIXASIL_STATUS (Default 0x01): Pixel ASIL enabled
		{0x3b9e, 0x08}, // PIXASIL_FAULT_MASK (Default 0x08): Mask manual injections only
		/* Should we configure ROI and thresholds? Or use ones from the main config? */
		/* Setup ROI and thresholds here */

		/* ATPR: 0x3b40 - 0x3b61 */
		{0x4310, 0x95}, // FORMAT_REG_10 (Default 0x95): ATPR output disabled, data type 0x15
		/* Should we configure margins, signal level, etc? Or use ones from the main config? */
		/* Setup calculation regions, margins and other ATPR specific parameters here */

		/* Row-Column ID: 0x4640 - 0x4649 */
		{0x4640, 0x41}, // UID_LATE_CTRL0 (Default 0x40): should correspond to actual H-mirror and V-flip (register 0x3820)
		{0x4649, 0x03}, // UID_LATE_CTRL3 (Default 0x03): should correspond to actual H-mirror and V-flip (register 0x3820)
		{0x4641, 0x11}, // UID_LATE_CTRL1 (Default 0x12): should correspond to actual number of exposures
		{0x4311, 0x16}, // FORMAT_REG_11 (Default 0x16): ROW and Column ID output disabled, data type 0x16

		/* Analog to digital sync: No additional configuration possible */

		/* DTPR: 0x4200 - 0x422a */
		/* Setup any DTPR specific parameters here */
		/*
		 * Note that the DTPR checker functionality might not be valid for all operating modes.
		 * For example, if short exposure is disabled
		 */
		{0x420e, 0xba},
		{0x420f, 0xa5},
		{0x4210, 0x44},
		{0x4211, 0x48},
		{0x507a, 0x6b},
		{0x507b, 0x7f},

		/* BLC: 0x4000 - 0x40e1, No additional configuration for integrity check needed */

		/* PLL clock monitor: 0x0400 - 0x0419, 0x0440 - 0x442 */
		/* PLL monitor setup is done in ox03c10_wdr_60fps_regs_wizard */
		/* Issues fixed with the latest sensor settings (sensor_settings_20230615.txt) */
		//{0x040f, 0x01}, // FAULT_CLOCK_FLAGS_SCLK_MASK (Default 0x00): crc_checksum_flag_sclk_mask enabled
		//{0x0410, 0x01}, // FAULT_CLOCK_FLAGS_PCLK_MASK (Default 0x00): crc_checksum_flag_pclk_mask enabled
		//{0x0407, 0x10}, // TOLERANCE_SCLK (Default 0x08), Increase tolerance a bit to avoid PLL faults (to be checked with latest OV settings)
		//{0x040e, 0x10},	// TOLERANCE_PCLK (Default 0x08), Increase tolerance a bit to avoid PLL faults (to be checked with latest OV settings)

		/* Internal Reference Voltage */
		/* The accuracy and acceptable threshold for each comparator to be provided by OmniVision
		 * after complete characterization. (per product specification datasheet). Assume no configuration needed */

		/* Output FIFO CRC: No additional configuration possible */

		/* SRAM CRC (Group hold): No additional configuration possible */

		/* Temperature sensor: 0x4d00 - 0x4d63 */
		/*
		 * OVT FEEDBACK: The out of range function and integrity test in celsius has a bug and should not be used.
		 * Integrity test in internal units is still enabled
		 */
		{0x4d5a, 0x1c}, // TPM_REG_5A (Deafult 0x10): Unmask temp faults except wd_fault_inject, out-of-range and fault_alarm_cel
		{0x4d07, 0x31}, // TPM_REG_7 (Default 0x31): Continuous updating
		/* Integrity check (considerable difference between the temperature sensors 0 and 1) */
		/*
		 * OVT FEEDBACK: 0x4d12 is set in internal digital number, not in degrees.
		 * Usually we don’t want customer to change it.
		 */
		//{0x4d12, 0x50}, // TPM_REG_0E (Default 0xff): max_difference (dec or int? is it the only parameter?)
		//{0x4d30, 0x01}, // max_diff_int (Default 0xff): does not affect faults generation?
		//{0x4d31, 0x00}, // max_diff_dec (Default 0xff): does not affect faults generation?
		/* Out-of-range */
		//{0x4d17, 0xd4}, // tpm_min (Default 0x00): -20C (0xC0 + 0x14 = 0xD4)
		//{0x4d18, 0x64}, // tpm_max (Default 0xff): 100C (0x64)
		/* Does not affect faults generation? */
		//{0x4d13, 0xe8}, // temp_low   (Default 0xe8): 0xe8 - 0xc0 = 0x28 (-40C)
		//{0x4d14, 0x00}, // temp_low   (Default 0x00):
		//{0x4d15, 0x20}, // temp_high  (Default 0x78): 120C
		//{0x4d16, 0x00}, // temp_high  (Default 0x00):
		//{0x4d32, 0xe8}, // temp_low0  (Default 0xe8): 0xe8 - 0xc0 = 0x28 (-40C)
		//{0x4d33, 0x00}, // temp_low0  (Default 0x00):
		//{0x4d34, 0x78}, // temp_high0 (Default 0x78): 100C (0x64)
		//{0x4d35, 0x00}, // temp_high0 (Default 0x00):
		//{0x4d3a, 0xe8}, // temp_low1  (Default 0x00): 0xe8 - 0xc0 = 0x28 (-40C)
		//{0x4d3b, 0x00}, // temp_low1  (Default 0x00):
		//{0x4d3c, 0x78}, // temp_high1 (Default 0x00): 100C (0x64)
		//{0x4d3d, 0x00}, // temp_high1 (Default 0x00):

		/* Total number of rows per frame */
		/* Active rows (0x380a/b) are set to 0x504 - should not be adjusted to not break FPS */
		//{0x380e, 0x05}, // VTS_H (Default 0x02):
		//{0x380f, 0xae}, // VTS_L (Default 0xae):

		/* Supply Voltage Monitor: 0x4580 - 0x45bb */
		{0x4581, 0xe7}, // VM_CTRL (Default 0xe7): Tester enable, DVDD, DOVDD, AVDD monitors enable
		{0x4597, 0x00}, // VOLTAGE_MONITOR_FAULT_MASK (Default 0x00): Unmask all self-test and out-of-range faults
		{0x45b6, 0x00}, // R_OFFSET_S0_H (Default 0x00): Calibration. To be read from OTP?
		{0x45b7, 0x00}, // R_OFFSET_S0_L (Default 0x00): Calibration. To be read from OTP?
		{0x45b8, 0x00}, // R_OFFSET_S1_H (Default 0x00): Calibration. To be read from OTP?
		{0x45b9, 0x00}, // R_OFFSET_S1_L (Default 0x00): Calibration. To be read from OTP?
		{0x45ba, 0x00}, // R_OFFSET_S2_H (Default 0x00): Calibration. To be read from OTP?
		{0x45bb, 0x00}, // R_OFFSET_S2_L (Default 0x00): Calibration. To be read from OTP?
		{0x4583, 0x00}, // R_VOL_0_MIN_H (Default 0x00): To be set per Magna requirements?
		{0x4584, 0x00}, // R_VOL_0_MIN_L (Default 0x00): To be set per Magna requirements?
		{0x4585, 0x0f}, // R_VOL_0_MAX_H (Default 0x0f): To be set per Magna requirements?
		{0x4586, 0xff}, // R_VOL_0_MAX_H (Default 0xff): To be set per Magna requirements?
		{0x4587, 0x00}, // R_VOL_1_MIN_H (Default 0x00): To be set per Magna requirements?
		{0x4588, 0x00}, // R_VOL_1_MIN_L (Default 0x00): To be set per Magna requirements?
		{0x4589, 0x0f}, // R_VOL_1_MAX_H (Default 0x0f): To be set per Magna requirements?
		{0x458a, 0xff}, // R_VOL_1_MAX_H (Default 0xff): To be set per Magna requirements?
		{0x458b, 0x00}, // R_VOL_2_MIN_H (Default 0x00): To be set per Magna requirements?
		{0x458c, 0x00}, // R_VOL_2_MIN_L (Default 0x00): To be set per Magna requirements?
		{0x458d, 0x0f}, // R_VOL_2_MAX_H (Default 0x0f): To be set per Magna requirements?
		{0x458e, 0xff}, // R_VOL_2_MAX_H (Default 0xff): To be set per Magna requirements?

		/* CRC */
		{0x3218, 0x02}, // GRP_HOLD_CTRL_18 (Default 0x06): Enable embedded data CRC only
	};

	return ox03c10_set_regs_crc(client, ox03c10_setup_safety_regs, ARRAY_SIZE(ox03c10_setup_safety_regs));
}

static int32_t ox03c10_config_internal(struct i2c_client *client, uint32_t feat, int height, int fps, bool bypass)
{
	int32_t              ret = 0;
	int32_t              sclk_ret;
	struct ox03c10_priv *priv;

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	/* Program wizard registers */
	/*
	 * Collect errors and not exit at the first one as might be called for the broadcast address
	 * where some cameras are absent. Missed/broken cameras are reported as flags in positive return code.
	 */
	ret |= ox03c10_set_regs_crc(client, ox03c10_wdr_60fps_regs_wizard, ARRAY_SIZE(ox03c10_wdr_60fps_regs_wizard));
	RETURN_ON_ERROR_NONBROADCAST(client, ret);

	if (height == 1080)
	{
		ret |= ox03c10_set_regs_crc(client, ox03c10_wdr_60fps_1080_regs_wizard, ARRAY_SIZE(ox03c10_wdr_60fps_1080_regs_wizard));
		RETURN_ON_ERROR_NONBROADCAST(client, ret);
	}

	/* Program embedded data settings */
	ret |= ox03c10_set_regs_crc(client, ox03c10_setup_embedded_data, ARRAY_SIZE(ox03c10_setup_embedded_data));
	RETURN_ON_ERROR_NONBROADCAST(client, ret);

	/* Program ISP-RC table */
	ret |= ox03c10_set_regs_crc(client, ox03c10_isp_rc_init, ARRAY_SIZE(ox03c10_isp_rc_init));
	RETURN_ON_ERROR_NONBROADCAST(client, ret);

	if (bypass)
	{
		ret |= ox03c10_set_regs_crc(client, ox03c10_enable_bypass, ARRAY_SIZE(ox03c10_enable_bypass));
		RETURN_ON_ERROR_NONBROADCAST(client, ret);
	}

	if ((feat & ISS_SENSOR_FEATURE_DISABLE_FSYNC) == 0)
	{
		ret |= ox03c10_config_fsin(client);
		RETURN_ON_ERROR_NONBROADCAST(client, ret);
	}

	sclk_ret = ox03c10_get_sclk(client, &priv->sclk);
	if (sclk_ret && is_broadcast(client))
	{
		// We are not able to configure any camera
		ret |= 0xf;
		return ret;
	}

	/* force VTS update */
	ret |= ox03c10_set_fps_internal(client, fps, true);
	RETURN_ON_ERROR_NONBROADCAST(client, ret);

	priv->fps = fps;

	/* Setup safety mechanism specific registers */
	ret |= ox03c10_setup_safety(client);
	RETURN_ON_ERROR_NONBROADCAST(client, ret);

	/* stream on */
	ret |= reg16_write_crc(client, 0x0100, 0x01);

	if (!ret && !is_broadcast(client))
	{
		/* OTP data load will be triggered whenever streaming is entered */
		ret = ox03c10_otp_read_check(client);
	}

	return ret;
}

static int32_t ox03c10_config_30fps_no_flip(struct i2c_client *client, uint32_t feat)
{
	int32_t              ret = 0;
	struct ox03c10_priv *priv;

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	ret |= ox03c10_config_internal(client, feat, 1280, 30, false);
	if (ret && !is_broadcast(client))
	{
		return ret;
	}

	/* Lock SCCB registers */
	ret |= reg16_write_crc(client, 0x3187, 0x00);

	return ret;
}

static int32_t ox03c10_stream(struct i2c_client *client, uint32_t on)
{
	int32_t              ret;
	struct ox03c10_priv *priv;
	struct ser_camera   *cam;
	int                  cam_num;

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	cam = (struct ser_camera *)priv->camera;
	cam_num = cam->channel + cam->slot * 4;
	if (camera_is_set_for_action(cam_num))
		return -EPERM;

	/* stream on/off */
	ret = reg16_write_crc(client, 0x0100, on ? 0x01 : 0x00);

	/* OTP should be read when stream is on so do it here */
	if (!ret && on)
	{
		ret = ox03c10_otp_read_check(client);
	}

	return ret;
}

#ifndef REG_ACCESS_WITH_SAFETY_RETRY
static int32_t ox03c10_rreg(struct i2c_client *client, uint32_t addr, uint32_t *val)
{
	struct ox03c10_priv *priv;
	uint8_t tmp;
	int32_t ret = 0;

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	ret = reg16_read(client, addr, &tmp);
	if (!ret && val)
		*val = tmp;

	return ret;
}
#else
static int32_t ox03c10_rreg(struct i2c_client *client, uint32_t addr, uint32_t *val)
{
	struct ox03c10_priv *priv;
	struct ser_camera *cam;
	int cam_num;
	uint8_t tmp;
	int32_t ret = 0;

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	cam = (struct ser_camera *)priv->camera;
	cam_num = cam->slot * 4 + cam->channel;

	ret = reg16_read_retry3(client, addr, &tmp);
	if (!ret && val)
		*val = tmp;

	if (ret)
	{
		camera_report_error_status(cam_num, ERRMGR_CAM_I2C_NACK, 1);
		camera_set_for_reset(cam_num);
	}

	return ret;
}
#endif

static int32_t ox03c10_wreg(struct i2c_client *client, uint32_t addr, uint32_t val)
{
	struct ox03c10_priv *priv;

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	return reg16_write(client, addr, val & 0xff);
}

#ifndef REG_ACCESS_WITH_SAFETY_RETRY
static int32_t ox03c10_wnregs(struct i2c_client *client, uint8_t *buf, int nregs)
{
	struct ox03c10_priv *priv;

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	return i2c_tx_array(client, buf, nregs);
}
#else
static int32_t ox03c10_wnregs(struct i2c_client *client, uint8_t *buf, int nregs)
{
	int32_t ret;
	struct ox03c10_priv *priv;
	struct ser_camera *cam;
	int cam_num;

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	cam = (struct ser_camera *)priv->camera;
	cam_num = cam->slot * 4 + cam->channel;

	ret = i2c_tx_array_retry3(client, buf, nregs);
	if (ret)
	{
		camera_report_error_status(cam_num, ERRMGR_CAM_I2C_NACK, 1);
		camera_set_for_reset(cam_num);
	}

	return ret;
}
#endif

#ifndef REG_ACCESS_WITH_SAFETY_RETRY
static int32_t ox03c10_rnregs(struct i2c_client *client, uint16_t addr, uint8_t *buf, int nregs)
{
	int32_t ret = 0;
	struct ox03c10_priv *priv;
	uint8_t tx[2];

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	tx[0] = addr >> 8;	 // msb
	tx[1] = addr & 0xff; // lsb
	ret = i2c_tx_array(client, tx, 2);
	if (ret < 0)
		goto out;
	ret = i2c_rx_array(client, buf, nregs);
	if (ret < 0)
		goto out;

out:
	return ret;
}
#else
static int32_t ox03c10_rnregs(struct i2c_client *client, uint16_t addr, uint8_t *buf, int nregs)
{
	int32_t ret = 0;
	struct ox03c10_priv *priv;
	struct ser_camera *cam;
	int cam_num;
	uint8_t tx[2];

	priv = i2c_get_clientdata(client);
	if (priv == NULL)
		return -ENODEV;

	cam = (struct ser_camera *)priv->camera;
	cam_num = cam->slot * 4 + cam->channel;

	tx[0] = addr >> 8;	 // msb
	tx[1] = addr & 0xff; // lsb
	ret = i2c_tx_array_retry3(client, tx, 2);
	if (ret < 0)
		goto out;
	ret = i2c_rx_array_retry3(client, buf, nregs);
	if (ret < 0)
		goto out;

out:
	if (ret)
	{
		camera_report_error_status(cam_num, ERRMGR_CAM_I2C_NACK, 1);
		camera_set_for_reset(cam_num);
	}

	return ret;
}
#endif

/* FPDLink, 1920x1280, 30fps, no H-flip */
struct sensor_drv ox03c10_drv = {
	.name = "ox03c10",
	.params = &ox03c10_1280_30fps_CreatePrms,
	.power = NULL,
	.detect = ox03c10_detect,
	.config = ox03c10_config_30fps_no_flip,
	.stream = ox03c10_stream,
	.rreg = ox03c10_rreg,
	.wreg = ox03c10_wreg,
	.wnregs = ox03c10_wnregs,
	.rnregs = ox03c10_rnregs,
	/* FPDlink only */
	.ub9x4_cfg = ox03c10_ub9x4_cfg,
};
