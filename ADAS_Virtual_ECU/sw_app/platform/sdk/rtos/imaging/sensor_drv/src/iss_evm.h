#ifndef _ISS_EVM_H_
#define _ISS_EVM_H_

#include "ser_camera.h"

// External sync from gpio 0
#define TI960_BOARD_EXT_SYNC        (0x80)

/* Deser A sensor mappings */
#define SENSOR_0_I2C_ALIAS    (0x40U)
#define SENSOR_1_I2C_ALIAS    (0x42U)
#define SENSOR_2_I2C_ALIAS    (0x44U)
#define SENSOR_3_I2C_ALIAS    (0x46U)
/* Deser B sensor mappings */
#define SENSOR_4_I2C_ALIAS    (0x48U)
#define SENSOR_5_I2C_ALIAS    (0x4AU)
#define SENSOR_6_I2C_ALIAS    (0x4DU)
#define SENSOR_7_I2C_ALIAS    (0x4EU)

/* Deser A serializer mappings */
#define SER_0_I2C_ALIAS       (0x0CU)
#define SER_1_I2C_ALIAS       (0x0DU)
#define SER_2_I2C_ALIAS       (0x0EU)
#define SER_3_I2C_ALIAS       (0x0FU)
/* Deser B serializer mappings */
#define SER_4_I2C_ALIAS       (0x1CU)
#define SER_5_I2C_ALIAS       (0x1DU)
#define SER_6_I2C_ALIAS       (0x1EU)
#define SER_7_I2C_ALIAS       (0x1FU)

int32_t iss_evm_probe(uint32_t channel_mask, const struct sensor_drv *drv);
int32_t iss_evm_eeprom_init(void);
int32_t iss_evm_deinit(uint32_t channel_mask);
int32_t iss_evm_PoC_channel_set(uint32_t slot, uint32_t channel, uint32_t state);
int32_t iss_evm_PoC_enable(uint32_t chMask);
int32_t iss_evm_PoC_disable(uint32_t chMask);

#define iss_board_probe				iss_evm_probe
#define iss_board_eeprom_init       iss_evm_eeprom_init
#define iss_board_deinit			iss_evm_deinit
#define iss_board_PoC_channel_set	iss_evm_PoC_channel_set
#define iss_board_PoC_enable		iss_evm_PoC_enable
#define iss_board_PoC_disable		iss_evm_PoC_disable

#endif /* _ISS_EVM_H_ */
