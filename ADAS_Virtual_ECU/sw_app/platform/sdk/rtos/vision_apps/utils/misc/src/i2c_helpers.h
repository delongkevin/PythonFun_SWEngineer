
#define DEF_I2C_TIMEOUT     (5000U)

struct i2c_client {
	I2C_Handle 		adapter;
	uint8_t			addr;
	void			*priv;
};

#define ARRAY_SIZE(a)   (sizeof(a) / sizeof(*(a)))

/* 14 on-chip buses + 16 on muxes - this is maximum! */
static I2C_Handle gISS_Sensor_I2cHandle[14 + 16];
static uint8_t gISS_Sensor_ByteOrder = BOARD_I2C_REG_ADDR_MSB_FIRST;

static int getIssSensorI2cInfo(uint8_t i2cInstId, uint8_t * byteOrder, I2C_Handle * i2cHndl)
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

static int32_t setupI2CInst(uint8_t i2cInstId)
{
    int32_t status = 0;
    I2C_Params i2cParams;

    /* Initializes the I2C Parameters */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz;

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
 *  Globals
 ******************************************************************************/

static I2C_Handle i2c_get_handle(int bus)
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

static void i2c_put_handle(I2C_Handle handle)
{
    I2C_close(handle);
}

static int32_t i2c_tx_array(struct i2c_client *client, uint8_t *tx, uint32_t len)
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

    return ret == I2C_STS_SUCCESS ? 0 : -1;
}

static int32_t i2c_rx_array(struct i2c_client *client, uint8_t *rx, uint32_t len)
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

    return ret == I2C_STS_SUCCESS ? 0 : -1;
}


static int32_t i2c_set_reg(struct i2c_client *client,
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

    return ret == I2C_STS_SUCCESS ? 0 : -1;
}

static int32_t i2c_get_reg(struct i2c_client *client,
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
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;
    transaction.timeout      = DEF_I2C_TIMEOUT;

    ret = I2C_transfer(client->adapter, &transaction);
    if (ret != I2C_STS_SUCCESS) {
        return -1;
    }

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);
    transaction.slaveAddress = client->addr;
    transaction.writeBuf     = NULL;
    transaction.writeCount   = 0;
    transaction.readBuf      = rx;
    transaction.readCount    = val_len;
    transaction.timeout      = DEF_I2C_TIMEOUT;

    ret = I2C_transfer(client->adapter, &transaction);
    if (ret != I2C_STS_SUCCESS) {
        return -2;
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
