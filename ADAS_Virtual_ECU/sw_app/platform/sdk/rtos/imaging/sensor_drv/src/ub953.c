#include <iss_sensors.h>
#include <iss_sensor_if.h>
#include <iss_sensor_priv.h>

extern I2C_Handle gISS_Sensor_I2cHandle[14 + 16];

static int32_t UB953_WriteReg(uint8_t   i2cInstId,
                                 uint8_t   slaveI2cAddr,
                                 uint16_t  regAddr,
                                 uint8_t   regVal)
{
    int32_t status = -1;

    status = Board_i2c8BitRegWr(gISS_Sensor_I2cHandle[i2cInstId], slaveI2cAddr, regAddr, &regVal, 1U, SENSOR_I2C_TIMEOUT);
    if(0 != status)
    {
        appLogPrintf("Error writing 0x%x to UB953 register 0x%x \n", regVal, regAddr);
    }
    return status;
}

int32_t ub953_cfgScript(uint8_t  i2cInstId, uint8_t  slaveAddr, I2cParams *script)
{
    uint16_t regAddr;
    uint8_t  regValue;
    uint16_t delayMilliSec;
    uint32_t cnt;
    int32_t status = 0;

    appLogPrintf("ub953 config start : slaveAddr = 0x%x \n", slaveAddr);
    if(NULL != script)
    {
        cnt = 0;
        regAddr  = script[cnt].nRegAddr;
        regValue = script[cnt].nRegValue;
        delayMilliSec = script[cnt].nDelay;

        while(regAddr != 0xFFFF)
        {
            /* Convert Registers address and value into 8bit array */
            status |= UB953_WriteReg(i2cInstId, slaveAddr, regAddr, regValue);

            if (0 != status)
            {
                appLogPrintf(" UB953: Reg Write Failed for regAddr %x\n", regAddr);
                break;
            }
            cnt++;
            regAddr  = script[cnt].nRegAddr;
            regValue = script[cnt].nRegValue;
            delayMilliSec = script[cnt].nDelay;
            if(delayMilliSec > 0)
            {
                appLogWaitMsecs(delayMilliSec);
            }
        }
    }
    appLogPrintf(" End of UB953 config \n");
    return (status);
}
