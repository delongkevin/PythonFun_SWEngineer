#ifndef _I2C_HELPERS_H_
#define _I2C_HELPERS_H_

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include "dev_helpers.h"

#define DEF_I2C_TIMEOUT     (100U)

struct i2c_client {
	I2C_Handle 		adapter;
	uint8_t			addr;
	uint8_t			idx;

	struct device	dev;
	void			*priv;
};

I2C_Handle i2c_get_handle(int bus);

void *i2c_get_clientdata(struct i2c_client *client);
void i2c_set_clientdata(struct i2c_client *client, void *data);

int32_t i2c_tx_array(struct i2c_client *client, uint8_t *tx, uint32_t len);
int32_t i2c_tx_array_retry3(struct i2c_client *client, uint8_t *tx, uint32_t len);
int32_t i2c_master_send(struct i2c_client *client, uint8_t *buf, uint32_t len);
int32_t i2c_rx_array(struct i2c_client *client, uint8_t *rx, uint32_t len);
int32_t i2c_rx_array_retry3(struct i2c_client *client, uint8_t *rx, uint32_t len);
int32_t i2c_master_recv(struct i2c_client *client, uint8_t *buf, uint32_t len);
int32_t i2c_set_reg(struct i2c_client *client,
    uint32_t reg, uint32_t reg_len,
    uint32_t val, uint32_t val_len);
int32_t i2c_get_reg(struct i2c_client *client,
    uint32_t reg, uint32_t reg_len,
    uint32_t *ptr, uint32_t val_len);


int reg8_read(struct i2c_client *client, uint8_t reg, uint8_t *ptr);
int reg8_write(struct i2c_client *client, uint8_t reg, uint8_t val);
int reg8_read_retry3(struct i2c_client *client, uint8_t reg, uint8_t *val);
int reg8_write_retry3(struct i2c_client *client, uint8_t reg, uint8_t val);
int reg8_write_bits(struct i2c_client *client, uint8_t reg, uint8_t mask, uint8_t val);
int reg8_read16(struct i2c_client *client, uint8_t reg, uint16_t *ptr);
int reg8_write16(struct i2c_client *client, uint8_t reg, uint16_t val);
int reg8_write16_bits(struct i2c_client *client, uint8_t reg, uint16_t mask, uint16_t val);
int reg16_read(struct i2c_client *client, uint16_t reg, uint8_t *ptr);
int reg16_read_retry3(struct i2c_client *client, uint16_t reg, uint8_t *val);
int reg16_write(struct i2c_client *client, uint16_t reg, uint8_t val);
int reg16_write_bits(struct i2c_client *client, uint16_t reg, uint8_t mask, uint8_t val);
int reg16_read16(struct i2c_client *client, uint16_t reg, uint16_t *ptr);
int reg16_read16_retry3(struct i2c_client *client, uint16_t reg, uint16_t *val);
int reg16_write16(struct i2c_client *client, uint16_t reg, uint16_t val);

/* Special helpers, use with care */
int reg8_read_addr(struct i2c_client *client, uint8_t addr, uint8_t reg, uint8_t *val);
int reg8_write_addr(struct i2c_client *client, uint8_t addr, uint8_t reg, uint8_t val);
int reg16_read_addr(struct i2c_client *client, uint8_t addr, uint16_t reg, uint8_t *val);
int reg16_write_addr(struct i2c_client *client, uint8_t addr, uint16_t reg, uint8_t val);

int i2c_recover_bus(struct i2c_client *client);
int i2c_reset_bus(struct i2c_client *client);

int i2c_ret_to_err(int16_t ret);

#endif /* _I2C_HELPERS_H_ */
