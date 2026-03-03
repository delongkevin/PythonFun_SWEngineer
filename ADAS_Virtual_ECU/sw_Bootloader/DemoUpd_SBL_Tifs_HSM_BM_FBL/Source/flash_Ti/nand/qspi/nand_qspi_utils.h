#ifndef NAND_QSPI_CONFIG_UTILS_H_
#define NAND_QSPI_CONFIG_UTILS_H_

#include <ti/board/src/flash/nand/device/w25n01gw.h>
#include <ti/board/src/flash/nand/nand.h>
#include <ti/csl/soc.h>
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/SPI_soc.h>


#include <ti/csl/csl_gpio.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

void Nand_enterQspiMode(OSPI_Handle handle, bool dacEnable, bool phyEnable, bool dtrEnable);
void Nand_enterSpiMode(OSPI_Handle handle, bool dacEnable, bool phyEnable);
NAND_STATUS NAND_qspiCmdRead(OSPI_Handle handle, uint8_t *cmdBuf,
                            uint32_t cmdLen, uint8_t *rxBuf, uint32_t rxLen);
NAND_STATUS Nand_qspiReadId(OSPI_Handle handle);

NAND_STATUS Nand_qspiResetMemory(OSPI_Handle handle);

NAND_STATUS Nand_qspiDisableWriteProtection(OSPI_Handle handle);

NAND_STATUS Nand_qspiSetBufferReadMode(OSPI_Handle handle, bool enable_buffer_mode);

void Nand_qspiSetOpcode(OSPI_Handle handle);

NAND_STATUS Nand_qspiCmdWrite(OSPI_Handle handle, uint8_t *cmdBuf,
                                        uint32_t cmdLen, uint32_t dataLen);

NAND_STATUS Nand_qspiWaitReady(OSPI_Handle handle, uint32_t timeOut, uint8_t* sr3);

NAND_STATUS NAND_SendPageReadCmd(OSPI_Handle spiHandle, uint32_t pageidx);

bool IsOspiConfigValid(OSPI_v0_HwAttrs* const ospiCfg);

void SetDeviceSizeReg(OSPI_v0_HwAttrs* handle);

NAND_STATUS Nand_qspiReadStatusRegister(OSPI_Handle handle, uint8_t status_reg_addr, uint8_t* status);

bool Nand_qspiOptimizedQuadRead(OSPI_Handle handle, OSPI_Transaction *transaction);

void PrintBuffer(uint8_t* buf, uint32_t length);

#endif  /*NAND_QSPI_CONFIG_UTILS_H_*/
