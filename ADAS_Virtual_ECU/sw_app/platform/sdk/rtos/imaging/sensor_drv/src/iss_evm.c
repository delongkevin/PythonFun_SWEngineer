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

#include "ub960.h"
#include "i2c_helpers.h"
#include "dev_helpers.h"

#ifdef j721s2_hyd
#include "stellantis.h"

/* Video input boards */
#define VIN_BOARDS_I2C_BUS		1
#define VIN_BOARD_UB960_ADDR_0		0x3d
#define VIN_BOARD_UB960_ADDR_1		0x3d
#define UB960_I2C_TIMEOUT		(5000U)
#define VIN_BOARD_UB960_WAKE_DELAY	10 /* mS */
#define VIN_BOARD_COUNT			2

typedef struct {
	enum i2c_exp_dev dev;
	uint32_t         offset;
} tca9539_pin_t;

tca9539_pin_t cam_pwr_en_pins[VIN_BOARD_COUNT][4] = {
	{
		{
			.dev    = CAM1_PWR_EN_PIN_DEV,
			.offset = CAM1_PWR_EN_PIN_OFF,
		},
		{
			.dev    = CAM2_PWR_EN_PIN_DEV,
			.offset = CAM2_PWR_EN_PIN_OFF,
		},
		{
			.dev    = CAM3_PWR_EN_PIN_DEV,
			.offset = CAM3_PWR_EN_PIN_OFF,
		},
		{
			.dev    = CAM4_PWR_EN_PIN_DEV,
			.offset = CAM4_PWR_EN_PIN_OFF,
		},
	},
	{
		{
			.dev    = PCA953x_DEV_MAX,
			.offset = 0U,
		},
		{
			.dev    = PCA953x_DEV_MAX,
			.offset = 0U,
		},
		{
			.dev    = PCA953x_DEV_MAX,
			.offset = 0U,
		},
		{
			.dev    = PCA953x_DEV_MAX,
			.offset = 0U,
		},
	}
};

/* Everything is located on same i2c bus on evm */
static I2C_Handle slot_i2c_handle[VIN_BOARD_COUNT];

static int32_t __deser_read(I2C_Handle i2c, uint32_t addr, uint32_t reg)
{
	uint8_t rx[1];
	Board_STATUS ret;

	ret = Board_i2c8BitRegRd(i2c, addr, reg, rx, 1, UB960_I2C_TIMEOUT);
	if (ret != BOARD_SOK)
		return ret;

	return rx[0];
}

#define deser_read(x)	__deser_read(deser_i2c, deser_addr, (x))

struct i2c_client *ti94x_des[VIN_BOARD_COUNT];

/*******************************************************************************
 *  Local Functions
 ******************************************************************************/

static int32_t iis_evm_probe_vin_ub960(uint32_t slot, uint32_t channel_mask, const struct sensor_drv *drv)
{
	int32_t i;
	int32_t ret;
	uint8_t name[7];
	I2C_Handle deser_i2c = slot_i2c_handle[slot];
	uint8_t deser_addr = (slot == 0) ? VIN_BOARD_UB960_ADDR_0 : VIN_BOARD_UB960_ADDR_1;

	if (deser_i2c == NULL)
		return -1;

	mdelay(VIN_BOARD_UB960_WAKE_DELAY);

	/* Name is _UB960 located in register 0xf0 - 0xf5 */
	for (i = 0; i < 6; i++) {
		ret = deser_read(0xf0 + i);
		if (ret < 0)
			break;
		name[i] = ret;
	}

	if (ret < 0) {
		appLogPrintf("Failed to read DESER ID on Slot %d: %d\n", slot, ret);
		return -1;
	}

	/* terminate string */
	name[6] = 0;

	appLogPrintf("Slot %d, detected %s channel_mask=0x%x\n", slot, name, channel_mask);

	ti94x_des[slot] = ub960_deser_init(deser_i2c, deser_addr, slot, channel_mask, drv);
	if (ti94x_des[slot]) {
		appLogPrintf("Slot %d, ti9x4 probed ok!\n", slot);
	}

	return 0;
}

static int32_t iss_evm_probe_vin(uint32_t slot, uint32_t channel_mask, const struct sensor_drv *drv)
{
	int32_t ret;

	if (channel_mask == 0x00) {
		appLogPrintf("Slot %d, channel mask is zero, skipping\n", slot);
		return 0;
	}

	slot_i2c_handle[slot] = i2c_get_handle(VIN_BOARDS_I2C_BUS);
	if (slot_i2c_handle[slot] == NULL) {
		appLogPrintf("Slot %d, failed to get DESER i2c bus\n", slot);
		return -1;
	}

	ret = iis_evm_probe_vin_ub960(slot, channel_mask, drv);

	return ret;
}

/*******************************************************************************
 *  Exported Functions
 ******************************************************************************/

int32_t iss_evm_eeprom_init(void)
{
	slot_i2c_handle[1] = i2c_get_handle(VIN_BOARDS_I2C_BUS);
	if (slot_i2c_handle[1] == NULL) {
		appLogPrintf("Slot 1, failed to get DESER i2c bus\n");
		return -1;
	}

	ub960_deser_eeprom_init(slot_i2c_handle[1], VIN_BOARD_UB960_ADDR_1, 1);
	return 0;
}

int32_t iss_evm_probe(uint32_t channel_mask, const struct sensor_drv *drv)
{
	int32_t i;

	ub960_deser_power(1);

	for (i = 0; i < VIN_BOARD_COUNT; i++) {
		iss_evm_probe_vin(i, channel_mask & 0x0f, drv);

		channel_mask >>= 4;
	}

	return 0;
}

int32_t iss_evm_deinit(uint32_t channel_mask)
{
	/* NOP */

	return 0;
}

int32_t iss_evm_PoC_channel_set(uint32_t slot, uint32_t channel, uint32_t state)
{
	return pca953x_direction_output(cam_pwr_en_pins[slot][channel].dev,
									cam_pwr_en_pins[slot][channel].offset,
									state);
}

static int32_t iss_evm_PoC_power(uint32_t channel_mask, uint32_t state)
{
	int32_t ret = 0;
	uint32_t slot;
	uint32_t channel;

	for (int i = 0; i < ISS_SENSORS_MAX_CHANNEL; i++) {
		if (channel_mask & (1 << i)) {
			slot = i / 4;
			channel = i % 4;
			ret = iss_evm_PoC_channel_set(slot, channel, state);
			if (ret < 0) {
				appLogPrintf("ERROR: power %s failed for camera %d: %d\n", state == 1 ? "on" : "off", i, ret);
				break;
			}
			mdelay(40);
		}
	}
	mdelay(40);

	return ret;
}

int32_t iss_evm_PoC_enable(uint32_t channel_mask)
{
	int32_t ret = 0;

	if (channel_mask == 0U) {
		/* Nothing to do */
		return 0;
	}

	ret = cam_common_power(1);
	if (ret != 0) {
		return ret;
	}

	ret = cam_common_power_pgood_wait(15);
	if (ret != 0) {
		return ret;
	}

	return iss_evm_PoC_power(channel_mask, 1);
}

int32_t iss_evm_PoC_disable(uint32_t channel_mask)
{
	return iss_evm_PoC_power(channel_mask, 0);
}

/*******************************************************************************
 *  Debug
 ******************************************************************************/

extern int appCliPrintf(__const char *__restrict __format, ...);

static int iss_evm_DeserDebug(unsigned int chip)
{
	if (!ti94x_des[chip]) {
		appCliPrintf(" UB960 is not probed yet\n");
		return 0;
	}

	return ub960_deser_debug(ti94x_des[chip]);
}

int32_t deser_tools(int argc, char *argv[])
{
	int i;

    /* first arg is "deser" */
    argc--;
    argv++;

    /* no sub-commands yet */
    for (i = 0; i < VIN_BOARD_COUNT; i++) {
		appCliPrintf("Slot %d\n", i);
		iss_evm_DeserDebug(i);
    }

    return 0;
}

#endif /* j721s2_hyd */
