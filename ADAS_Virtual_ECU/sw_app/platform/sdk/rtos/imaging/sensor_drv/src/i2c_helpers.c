#include <iss_sensors.h>
#include <iss_sensor_if.h>
#include <iss_sensor_priv.h>
#include <app_remote_service.h>
#include <app_ipc.h>

#include "i2c_helpers.h"

/*******************************************************************************
 *  Globals OLD - TO BE REMOVED
 ******************************************************************************/

#define ARRAY_SIZE(a)   (sizeof(a) / sizeof(*(a)))

//static I2C_Handle gISS_Sensor_I2cHandle[2] = {NULL, NULL};
/* 14 on-chip buses + 16 on muxes - this is maximum! */
I2C_Handle gISS_Sensor_I2cHandle[14 + 16];

static uint8_t gISS_Sensor_ByteOrder = BOARD_I2C_REG_ADDR_MSB_FIRST;

int getIssSensorI2cInfo(uint8_t i2cInstId, uint8_t * byteOrder, I2C_Handle * i2cHndl)
{
    if (i2cInstId > ARRAY_SIZE(gISS_Sensor_I2cHandle))
        return -1;
    if (gISS_Sensor_I2cHandle[i2cInstId] == NULL)
        return -2;

    if (byteOrder)
        *byteOrder = gISS_Sensor_ByteOrder;
    if (i2cHndl)
        *i2cHndl = gISS_Sensor_I2cHandle[i2cInstId];

    return 0;
}

int32_t setupI2CInst(uint8_t i2cInstId)
{
    int32_t status = 0;
    I2C_Params i2cParams;
    I2C_HwAttrs i2cCfg;

    /* Initializes the I2C Parameters */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz;

    I2C_socGetInitCfg(i2cInstId, &i2cCfg);
    i2cCfg.enableIntr = 1;
    I2C_socSetInitCfg(i2cInstId, &i2cCfg);

    /* Configures the I2C instance with the passed parameters*/
    if(NULL == gISS_Sensor_I2cHandle[i2cInstId]) {
        gISS_Sensor_I2cHandle[i2cInstId] = I2C_open(i2cInstId, &i2cParams);
        if(gISS_Sensor_I2cHandle[i2cInstId] == NULL) {
            appLogPrintf(" I2C: ERROR: I2C Open Failed for instance %d !!!\n", i2cInstId);
            return -1;
        }
    }

    return status;
}

/*******************************************************************************
 *  Globals OLD - TO BE REMOVED END
 ******************************************************************************/

/*******************************************************************************
 *  Globals
 ******************************************************************************/

I2C_Handle i2c_get_handle(int bus)
{
    int ret;
    I2C_Handle handle = NULL;

    ret = setupI2CInst(bus);
    if (ret) {
        return NULL;
    }

    ret = getIssSensorI2cInfo(bus, NULL, &handle);
    if (ret) {
        return NULL;
    }

    return handle;
}

void *i2c_get_clientdata(struct i2c_client *client)
{
    return client->priv;
}

void i2c_set_clientdata(struct i2c_client *client, void *data)
{
    client->priv = data;
}

int i2c_ret_to_err(int16_t ret)
{
    if (ret == I2C_STS_SUCCESS)
        return 0;

    /*
     * TODO:
     * #define I2C_STS_ERR_TIMEOUT          (-(int16_t)(1))
     * #define I2C_STS_ERR_BUS_BUSY         (-(int16_t)(2))
     * #define I2C_STS_ERR_NO_ACK           (-(int16_t)(3))
     * #define I2C_STS_ERR_ARBITRATION_LOST (-(int16_t)(4))
     * #define I2C_STS_ERR_ACCESS_ERROR     (-(int16_t)(5))
     * #define I2C_STS_ERR_COMMAND_FAILURE  (-(int16_t)(6))
     * #define I2C_STS_ERR_INVALID_COMMAND  (-(int16_t)(7))
     */
    if (ret < 0) {
        /* straight mapping */
        return ret;
    }

    /*
     * #define I2C_STS_ERR               ((int16_t)(0))
     */
    if (ret == I2C_STS_ERR) {
        return -10;
    }

    /* should not happen */
    return -11;
}

int32_t i2c_tx_array(struct i2c_client *client, uint8_t *tx, uint32_t len)
{
    int16_t ret;
    I2C_Transaction transaction;

    if ((client == NULL) || (client->adapter == NULL) || (tx == NULL))
        return -2;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);
    transaction.slaveAddress = client->addr;
    transaction.writeBuf     = tx;
    transaction.writeCount   = len;
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;
    transaction.timeout      = DEF_I2C_TIMEOUT;

    ret = I2C_transfer(client->adapter, &transaction);

    return i2c_ret_to_err(ret);
}

int32_t i2c_tx_array_retry3(struct i2c_client *client, uint8_t *tx, uint32_t len)
{
    int32_t ret;
    int count = 3;

    while ((count-- != 0) && (ret = i2c_tx_array(client, tx, len)));

    return ret;
}

int32_t i2c_master_send(struct i2c_client *client, uint8_t *buf, uint32_t len)
{
    int ret;

    ret = i2c_tx_array(client, buf, len);

    if (ret == 0)
        return len;

    return ret;
}

int32_t i2c_rx_array(struct i2c_client *client, uint8_t *rx, uint32_t len)
{
    int16_t ret;
    I2C_Transaction transaction;

    if ((client == NULL) || (client->adapter == NULL) || (rx == NULL))
        return -2;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);
    transaction.slaveAddress = client->addr;
    transaction.writeBuf     = NULL;
    transaction.writeCount   = 0;
    transaction.readBuf      = rx;
    transaction.readCount    = len;
    transaction.timeout      = DEF_I2C_TIMEOUT;

    ret = I2C_transfer(client->adapter, &transaction);

    return i2c_ret_to_err(ret);
}

int32_t i2c_rx_array_retry3(struct i2c_client *client, uint8_t *rx, uint32_t len)
{
    int32_t ret;
    int count = 3;

    while ((count-- != 0) && (ret = i2c_rx_array(client, rx, len)));

    return ret;
}

int32_t i2c_master_recv(struct i2c_client *client, uint8_t *buf, uint32_t len)
{
    int ret;

    ret = i2c_rx_array(client, buf, len);

    if (ret == 0)
        return len;

    return ret;
}

int32_t i2c_set_reg(struct i2c_client *client,
    uint32_t reg, uint32_t reg_len,
    uint32_t val, uint32_t val_len)
{
    int i;
    int16_t ret;
    I2C_Transaction transaction;
    uint8_t tx[8];

    if ((client == NULL) || (client->adapter == NULL))
        return -2;

    if ((reg_len > 4) || (val_len > 4))
        return -1;

    /* MSB first */
    for (i = 0; i < reg_len; i++) {
        tx[reg_len - i - 1] = (reg >> (i * 8)) & 0xff;
    }

    /* MSB first */
    for (i = 0; i < val_len; i++) {
        tx[reg_len + val_len - i - 1] = (val >> (i * 8)) & 0xff;
    }

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);
    transaction.slaveAddress = client->addr;
    transaction.writeBuf     = tx;
    transaction.writeCount   = reg_len + val_len;
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;
    transaction.timeout      = DEF_I2C_TIMEOUT;

    ret = I2C_transfer(client->adapter, &transaction);

    return i2c_ret_to_err(ret);
}

int32_t i2c_get_reg(struct i2c_client *client,
    uint32_t reg, uint32_t reg_len,
    uint32_t *ptr, uint32_t val_len)
{
    int i;
    int16_t ret;
    I2C_Transaction transaction;
    uint8_t tx[4];
    uint8_t rx[4];

    if ((client == NULL) || (client->adapter == NULL))
        return -2;

    if ((reg_len > 4) || (val_len > 4))
        return -1;

    for (i = 0; i < reg_len; i++) {
        /* MSB first */
        tx[reg_len - i - 1] = (reg >> (i * 8)) & 0xff;
    }

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);
    transaction.slaveAddress = client->addr;
    transaction.writeBuf     = tx;
    transaction.writeCount   = reg_len;
    transaction.readBuf      = rx;
    transaction.readCount    = val_len;
    transaction.timeout      = DEF_I2C_TIMEOUT;

    ret = I2C_transfer(client->adapter, &transaction);
    ret = i2c_ret_to_err(ret);
    if (ret) {
        return ret;
    }

    if (ptr != NULL) {
        uint32_t val = 0;
        /* MSB first */
        for (i = 0; i < val_len; i++) {
            val = (val << 8) | rx[i];
        }
        *ptr = val;
    }

    return 0;
}

int reg8_read(struct i2c_client *client, uint8_t reg, uint8_t *ptr)
{
    int32_t ret;
    uint32_t tmp;

    ret = i2c_get_reg(client, reg, 1, &tmp, 1);
    if (ret < 0)
        return ret;

    *ptr = tmp & 0xff;
    return 0;
}

int reg8_read_retry3(struct i2c_client *client, uint8_t reg, uint8_t *val)
{
    int ret;
    int count = 3;

    while ((count-- != 0) && (ret = reg8_read(client, reg, val)));

    return ret;
}

int reg8_write(struct i2c_client *client, uint8_t reg, uint8_t val)
{
    return i2c_set_reg(client, reg, 1, val, 1);
}

int reg8_write_retry3(struct i2c_client *client, uint8_t reg, uint8_t val)
{
    int ret;
    int count = 3;

    while ((count-- != 0) && (ret = reg8_write(client, reg, val)));

    return ret;
}

int reg8_write_bits(struct i2c_client *client, uint8_t reg, uint8_t mask, uint8_t val)
{
    int ret;
    uint8_t tmp;

    ret = reg8_read(client, reg, &tmp);
    if (ret < 0)
        return ret;

    tmp &= ~mask;
    tmp |= (val & mask);

    return reg8_write(client, reg, tmp);
}

int reg8_read16(struct i2c_client *client, uint8_t reg, uint16_t *ptr)
{
    int32_t ret;
    uint32_t tmp;

    ret = i2c_get_reg(client, reg, 1, &tmp, 2);
    if (ret < 0)
        return ret;

    *ptr = tmp & 0xffff;
    return 0;
}

int reg8_write16(struct i2c_client *client, uint8_t reg, uint16_t val)
{
    return i2c_set_reg(client, reg, 1, val, 2);
}

int reg8_write16_bits(struct i2c_client *client, uint8_t reg, uint16_t mask, uint16_t val)
{
    int ret;
    uint16_t tmp;

    ret = reg8_read16(client, reg, &tmp);
    if (ret < 0)
        return ret;

    tmp &= ~mask;
    tmp |= (val & mask);

    return reg8_write16(client, reg, tmp);
}

int reg16_read(struct i2c_client *client, uint16_t reg, uint8_t *ptr)
{
    int32_t ret;
    uint32_t tmp;

    ret = i2c_get_reg(client, reg, 2, &tmp, 1);
    if (ret < 0)
        return ret;

    *ptr = tmp & 0xff;
    return 0;
}

int reg16_read_retry3(struct i2c_client *client, uint16_t reg, uint8_t *val)
{
    int ret;
    int count = 3;

    while ((count-- != 0) && (ret = reg16_read(client, reg, val)));

    return ret;
}

int reg16_write(struct i2c_client *client, uint16_t reg, uint8_t val)
{
    return i2c_set_reg(client, reg, 2, val, 1);
}

int reg16_write_bits(struct i2c_client *client, uint16_t reg, uint8_t mask, uint8_t val)
{
    int ret;
    uint8_t tmp;

    ret = reg16_read(client, reg, &tmp);
    if (ret < 0)
        return ret;

    tmp &= ~mask;
    tmp |= (val & mask);

    return reg16_write(client, reg, tmp);
}

int reg16_read16(struct i2c_client *client, uint16_t reg, uint16_t *ptr)
{
    int32_t ret;
    uint32_t tmp;

    ret = i2c_get_reg(client, reg, 2, &tmp, 2);
    if (ret < 0)
        return ret;

    *ptr = tmp & 0xffff;
    return 0;
}

int reg16_read16_retry3(struct i2c_client *client, uint16_t reg, uint16_t *val)
{
    int ret;
    int count = 3;

    while ((count-- != 0) && (ret = reg16_read16(client, reg, val)));

    return ret;
}

int reg16_write16(struct i2c_client *client, uint16_t reg, uint16_t val)
{
    return i2c_set_reg(client, reg, 2, val, 2);
}

/* Special helpers, use with care */
int reg8_read_addr(struct i2c_client *client, uint8_t addr, uint8_t reg, uint8_t *val)
{
	struct i2c_client tmp_client = { .adapter = client->adapter, .addr = addr };

	return reg8_read(&tmp_client, reg, val);
}

int reg8_write_addr(struct i2c_client *client, uint8_t addr, uint8_t reg, uint8_t val)
{
	struct i2c_client tmp_client = { .adapter = client->adapter, .addr = addr };

	return reg8_write(&tmp_client, reg, val);
}

int reg16_read_addr(struct i2c_client *client, uint8_t addr, uint16_t reg, uint8_t *val)
{
	struct i2c_client tmp_client = { .adapter = client->adapter, .addr = addr };

	return reg16_read(&tmp_client, reg, val);
}

int reg16_write_addr(struct i2c_client *client, uint8_t addr, uint16_t reg, uint8_t val)
{
	struct i2c_client tmp_client = { .adapter = client->adapter, .addr = addr };

	return reg16_write(&tmp_client, reg, val);
}

int i2c_recover_bus(struct i2c_client *client)
{
    uint32_t delayValue = 2000U;
    return I2C_control(client->adapter, I2C_CMD_RECOVER_BUS, &delayValue);
}

int i2c_reset_bus(struct i2c_client *client)
{
    return I2C_control(client->adapter, I2C_CMD_RESET_BUS, NULL);
}
