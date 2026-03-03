/*
 * These symbols need to be defined for QNX shared object build of
 * PDK to compile properly, though they are not needed
 * in any apps/libs that are actually being used.
 */
#include <stdint.h>

uint64_t TTBR3_BASE_ADDR, TTBR2_BASE_ADDR, TTBR1_BASE_ADDR;

int32_t SPI_control(void* handle, uint32_t cmd, void *arg) { return 0; }
uint32_t SPI_transfer(void* handle, void *spiTrans) { return 0; }
void SPI_Params_init(void *params) { return; }
void SPI_open(uint32_t idx, void *params) { return; }
void SPI_close(void* handle) { return; }

void OSPI_dmaTransfer(void* handle,const void *transaction) { return; }

void I2C_Params_init(void *params) { return; }
void I2C_init(void) { return; }
void I2C_open(uint32_t idx, void *params) { return; }
void I2C_close(void* handle) { return; }
void I2C_transactionInit(void *transaction) { return; }
int16_t I2C_transfer(void* i2cHnd, void *transaction) { return 0; }

int32_t I2C_socSetInitCfg(uint32_t index, const void *cfg) { return 0; }
int32_t I2C_socGetInitCfg(uint32_t index, void *cfg) { return 0; }
int32_t OSPI_socSetInitCfg(uint32_t idx, const void *cfg) { return 0; }
int32_t OSPI_socGetInitCfg(uint32_t idx, void *cfg) { return 0; }
int32_t UART_socSetInitCfg(uint32_t idx, const void *cfg) { return 0; }
int32_t UART_socGetInitCfg(uint32_t idx, void *cfg) { return 0; }


void UART_stdioInit(uint32_t value) { return; }
void UART_stdioDeInit(void) { return; }
void UART_printf(const char *pcString, ...) { return; }

void* OSPI_open(uint32_t domain, uint32_t idx, void *params) { return 0; }
void OSPI_close(void* handle) { return; }
int32_t OSPI_transfer(void* handle, void *spiTrans) { return 0; }
int32_t OSPI_control(void* handle, uint32_t cmd, void *arg) { return 0; }
void OSPI_Params_init(void* params) { return; }
