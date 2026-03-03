#include <iss_sensors.h>
#include <iss_sensor_if.h>
#include <iss_sensor_priv.h>

extern I2C_Handle gISS_Sensor_I2cHandle[14 + 16];

int32_t initFusion2_UB97x()
{
    int32_t status = -1;
    uint32_t tca6408I2CSlaveAddr = 0x20;
    uint8_t regAddr = 0x3;
    uint8_t regVal = 0xFE;

    status = Board_i2c8BitRegWr(gISS_Sensor_I2cHandle[0], tca6408I2CSlaveAddr, regAddr, &regVal, 1U, SENSOR_I2C_TIMEOUT);
    if(0 == status)
    {
        appLogPrintf("write 0x%x to TCA6408 register 0x%x \n", regVal, regAddr);
    }else
    {
        appLogPrintf("Error writing to TCA6408 register 0x%x \n", regAddr);
    }

    appLogWaitMsecs(100);

    return status;
}

int32_t deInitFusion2_UB97x()
{
    int32_t status = 0;
    return status;
}
