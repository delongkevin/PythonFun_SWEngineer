#ifndef FUSAAPP_H_INCGUARD
#define FUSAAPP_H_INCGUARD

#include <stdint.h>
#include "PlatformDataTypes.h"
#include "fusa_application_cfg.h"

#define SDL_APP_OFF                                (0u)
#define SDL_APP_ON                                 (1u)

typedef enum{
e_errLog_PBIST = 0,
e_errLog_LBIST,
e_errLog_CCM,
e_errLog_DCC,
e_errLog_ESM,
e_errLog_ECC,
e_errLog_MTOG,
e_errLog_POK,
e_errLog_TOG,
e_errLog_VIM,
e_errLog_VTM,
e_errLog_MCRC,
e_errLog_Reserved1,
e_errLog_Reserved2,
/* e_errLog_MMR, */ /* Enable after DID spec update */
e_errLog_Max
}T_SDLErrorLog;

/* FD44 and FDF2 NVM Write Status */
#define NVM_WR_DONE			((int8_t)1)
#define NVM_WR_FAILED		((int8_t)-1)
#define NVM_WR_PENDING		((int8_t)0)

/* Fault Status */
#define FAULT_STATUS_NOK	((uint8_t)0x01)
#define FAULT_STATUS_OK		((uint8_t)0x00)
#define ESM_INIT_DONE		((uint8_t)0x01)
#define ESM_INIT_NOT_DONE	((uint8_t)0x00)


/* BIST error-manager logging enabled*/
/*#define BIST_ERRMGR_LOG*/

/* SDL TASK PARAMETERS */
#define SDL_CDD_MAIN_TASK_RATE 					   (10U)
#define SDL_CDD_ERROR_MANAGER_REPORT_TIME_EXPIRED (120U)
/* SDL TASK OFFSET */
#define SDL_APP_VTM_MAIN_FUNCTION_OFFSET           (10)
#define SDL_APP_TOG_MAIN_FUNCTION_OFFSET           (20)
#define SDL_APP_DCC_MAIN_FUNCTION_OFFSET           (30)
#define SDL_APP_CCM_MAIN_FUNCTION_OFFSET           (40)
#define SDL_APP_CBASS_MAIN_FUNCTION_OFFSET         (50)
#define SDL_APP_ADC_MAIN_FUNCTION_OFFSET           (60)
#define SDL_APP_DDR_MAIN_FUNCTION_OFFSET           (70)
#define SDL_APP_RESET_MAIN_FUNCTION_OFFSET         (80)
#define SDL_APP_VIM_MAIN_FUNCTION_OFFSET           (90)
#define SDL_APP_GPIO_MAIN_FUNCTION_OFFSET         (100)
#define SDL_APP_ESM_MAIN_FUNCTION_OFFSET          (110)

/* ECC CONFIG */
#define SDL_APP_ECC_ENABLED SDL_APP_ON
#define SDL_APP_ECC_SELFTEST_ENABLED SDL_APP_OFF

/* DDR PARITY CONFIG */
#define SDL_APP_DDR_PARITY_ENABLED SDL_APP_ON
#define SDL_APP_DDR_PARITY_SELFTEST_ENABLED SDL_APP_OFF

/* CCM CONFIG */
#define SDL_APP_CCM_ENABLED SDL_APP_ON
#define SDL_APP_CCM_SELFTEST_ENABLED SDL_APP_OFF
/*#define SDL_APP_CCM_UART_PRINTS_ENABLE*/

/* VTM CONFIG */
#define SDL_APP_VTM_ENABLED SDL_APP_ON
#define SDL_APP_VTM_SELFTEST_ENABLED SDL_APP_OFF

/* POK CONFIG */
#define SDL_APP_POK_ENABLED SDL_APP_ON
#define SDL_APP_POK_SELFTEST_ENABLED SDL_APP_OFF

/* DCC CONFIG */
#define SDL_APP_DCC_ENABLED SDL_APP_ON
#define SDL_APP_DCC_SELFTEST_ENABLED SDL_APP_OFF

/* TOG CONFIG */
#define SDL_APP_TOG_ENABLED SDL_APP_ON
#define SDL_APP_TOG_SELFTEST_ENABLED SDL_APP_OFF

/* CBASS CONFIG */
#define SDL_APP_CBASS_ENABLED SDL_APP_ON
#define SDL_APP_CBASS_SELFTEST_ENABLED SDL_APP_OFF

/* TOG THRESHOLDS */
#define SDL_APP_TOG_TIMEOUTVAL 0x10000U

/* MTOG CONFIG */
#define SDL_APP_MTOG_ENABLED SDL_APP_OFF
#define SDL_APP_MTOG_SELFTEST_ENABLED SDL_APP_OFF

/* DDR CONFIG */
#define SDL_APP_DDR_ENABLED SDL_APP_ON
#define SDL_APP_DDR_SELFTEST_ENABLED SDL_APP_OFF
/* #define SDL_APP_DDR_UART_PRINTS_ENABLED */

/* NAVSS MAILBOX CONFIG */
#define SDL_APP_NAVSS_MAILBOX_ENABLED SDL_APP_ON
#define SDL_APP_NAVSS_MAILBOX_SELFTEST_ENABLED SDL_APP_OFF

/* MSMC CONFIG */
#define SDL_APP_MSMC_ENABLED SDL_APP_ON
/* DDR ECC */
#define SDL_APP_DDR_ECC_ENABLED SDL_APP_ON
#define SDL_APP_DDR_ECC_SELFTEST_ENABLED SDL_APP_OFF

/* VIM CONFIG */
#define SDL_APP_VIM_ENABLED SDL_APP_ON
#define SDL_APP_VIM_ENABLE_STATIC_REG_CHECK (1)
#define SDL_APP_VIM_ENABLE_VEC_REG_CHECK    (0)
#define SDL_APP_VIM_ENABLE_PRI_REG_CHECK    (0)
/*#define SDL_APP_VIM_UART_PRINTS_ENABLED*/

#define SDL_VTM_TSD_NOT_REQ					   (0u)
#define SDL_VTM_TSD_REQ						   (0xA5A5u)
#define SDL_VTM_TSD_DONE					   (0xB5B5u)
#define SDL_VTM_TSD_DETECTED				   ((uint8)0xFF)
#define SDL_VTM_TSD_NOT_DETECTED			   ((uint8)0x00)

#define SDL_ERR_SAFESTATE_REASON_SDL_ECC_WKUP  (65520u)
#define ERR_SAFESTATE_REASON_SDL_TOG           (65521u)
#define SDL_ERR_FAULT_LOW_TEMP_WARN            (65522u)
#define ERR_SAFESTATE_REASON_SDL_CCM           (65523u)
#define ERR_SAFESTATE_REASON_SDL_ESM_WKUP_REG  (65524u)
#define ERR_SAFESTATE_REASON_SDL_ESM_MCU_REG   (65525u)


extern unsigned char gSDL_Running;

/* APIs */
void Fusa_Application_Init(void);
void Fusa_Application_RunSelfTest(void);
void Fusa_Application_MainFunction(void);

/* Time-Stamp related APIs */
int32_t Fusa_TimestampInit(void);
uint64_t Fusa_GetTimestamp(void);

/* Functions for error flags for CCM errors from ESM module callback */
uint8_t Fusa_Application_GetCcmErrorFlag(void);
void Fusa_Application_SetCcmErrorFlag(void);
void Fusa_Application_ClearCcmErrorFlag(void);

/* Functions for CCM Safety Critical Configuration Failures Flags */
uint8_t Fusa_Application_GetCcmSafetyCriticalConfigFailFlag(void);
void Fusa_Application_SetCcmSafetyCriticalConfigFailFlag(void);
void Fusa_Application_ClearCcmSafetyCriticalConfigFailFlag(void);

/* Functions for ADC Safety Critical Configuration Failures Flags */
uint8_t Fusa_Application_GetAdcSafetyCriticalConfigFailFlag(void);
void Fusa_Application_SetAdcSafetyCriticalConfigFailFlag(void);
void Fusa_Application_ClearAdcSafetyCriticalConfigFailFlag(void);

/* Functions for DDR Safety Critical Configuration Failures Flags */
uint8_t Sdl_Application_GetDDRSafetyCriticalConfigFailFlag(void);
void Sdl_Application_SetDDRSafetyCriticalConfigFailFlag(void);
void Sdl_Application_ClearDDRSafetyCriticalConfigFailFlag(void);

/* Functions for CBASS Safety Critical Configuration Failures Flags */
uint8_t Fusa_Application_GetCbassSafetyCriticalConfigFailFlag(void);
void Fusa_Application_SetCbassSafetyCriticalConfigFailFlag(uint8_t val);
void Fusa_Application_ClearCbassSafetyCriticalConfigFailFlag(void);

/* Functions for RESET Safety Critical Configuration Failures Flags */
uint8_t Fusa_Application_GetResetSafetyCriticalConfigFailFlag(void);
void Fusa_Application_SetResetSafetyCriticalConfigFailFlag(void);
void Fusa_Application_ClearResetSafetyCriticalConfigFailFlag(void);

/* Functions for GPIO Safety Critical Configuration Failures Flags */
uint8_t Fusa_Application_GetGpioSafetyCriticalConfigFailFlag(void);
void Fusa_Application_SetGpioSafetyCriticalConfigFailFlag(void);
void Fusa_Application_ClearGpioSafetyCriticalConfigFailFlag(void);

/* Functions for MMR Safety Critical Configuration Failures Flags */
uint8_t Fusa_Application_GetMcuWkupMMRSafetyCriticalConfigFailFlag(void);
void Fusa_Application_SetMcuWkupMMRSafetyCriticalConfigFailFlag(void);
void Fusa_Application_ClearMcuWkupMMRSafetyCriticalConfigFailFlag(void);
uint8_t Fusa_Application_GetMainMMRSafetyCriticalConfigFailFlag(void);
void Fusa_Application_SetMainMMRSafetyCriticalConfigFailFlag(void);
void Fusa_Application_ClearMainMMRSafetyCriticalConfigFailFlag(void);

/* Functions for ESM Safety Critical Configuration Failures Flags */
uint8_t Fusa_Application_GetEsmSafetyCriticalConfigFailFlag(uint8_t bitPosition);
void Fusa_Application_SetEsmSafetyCriticalConfigFailFlag(uint8_t bitPosition);
void Fusa_Application_ClearEsmSafetyCriticalConfigFailFlag(uint8_t bitPosition);

/* Functions for CCM Safety Critical Configuration Failures Flags */
uint8_t Fusa_Application_GetCcmSafetyCriticalConfigFailFlag(void);
void Fusa_Application_SetCcmSafetyCriticalConfigFailFlag(void);
void Fusa_Application_ClearCcmSafetyCriticalConfigFailFlag(void);

/* Functions for VTM Safety Critical Failures Flags */
uint8_t Fusa_Application_Get_Thermal_Pre_warning_detected(void);
uint8_t Fusa_Application_Get_Overtemperature_detected(void);
uint8_t Fusa_Application_Get_Parity_error_on_VTM_configuration_registers(void);
uint8_t Fusa_Application_Get_Configuration_readback_error_VTM_registers(void);
uint8_t Fusa_Application_Get_Fault_inject_test_failure_on_Over_temperature_detection(void);
uint8_t Fusa_Application_Get_Fault_inject_test_error_on_Parity_detection_logic__VTM_configuration_registers(void);

/* Error Log for DID */
void Fusa_Application_ErrorLogForDID(uint8_t errId, uint8_t error);
void Fusa_Application_GetLogErrorForDID(uint8_t *errTable);

/* Functions for MSMC readback */
uint8_t Sdl_Application_GetMSMCCfgErrorFlag(void);
void Sdl_Application_SetMSMCCfgErrorFlag(void);
void Sdl_Application_ClearMSMCCfgErrorFlag(void);

/* Functions for DCC Failures Flags */
uint8_t Sdl_Application_GetPllSlipMcuErrorFlag(void);
void Sdl_Application_SetPllSlipMcuErrorFlag(void);
void Sdl_Application_ClearPllSlipMcuErrorFlag(void);
uint8_t Sdl_Application_GetPllSlipMainErrorFlag(void);
void Sdl_Application_SetPllSlipMainErrorFlag(void);
void Sdl_Application_ClearPllSlipMainErrorFlag(void);
uint8_t Sdl_Application_GetClkDetErrorFlag(void);
void Sdl_Application_SetClkDetErrorFlag(void);
void Sdl_Application_ClearClkDetErrorFlag(void);

/* BIST NVM Status APIs */
void Cdd_Safety_NVM_Write_PMICLastResetReason_BISTStatus(uint8_t index, uint8_t Data, uint8_t storeAtShut);
void Cdd_Safety_NVM_Read_PMICLastResetReason_BISTStatus(uint8_t index, uint8_t *Data);
uint8_t Sdl_Application_GetMcuDCCErrorFlag(void);
void Sdl_Application_SetMcuDCCErrorFlag(void);
void Sdl_Application_ClearMcuDCCErrorFlag(void);
uint8_t Sdl_Application_GetMainDCCErrorFlag(void);
void Sdl_Application_SetMainDCCErrorFlag(void);
void Sdl_Application_ClearMainDCCErrorFlag(void);
uint8_t Sdl_Application_GetDccErrorFlag(void);
void Sdl_Application_SetDccErrorFlag(void);
void Sdl_Application_ClearDccErrorFlag(void);
uint8_t Sdl_Application_GetPLLreadbackErrorFlag(void);
void Sdl_Application_SetPLLreadbackErrorFlag(void);
void Sdl_Application_ClearPLLreadbackErrorFlag(void);

/* VTM Thermal-Shutdown(TSD) APIs */
void Cdd_Safety_SetTSDStatus(uint16_t TSDStatus);
uint16_t Cdd_Safety_GetTSDStatus(void);

void Cdd_Safety_NVM_Read_PMICLastResetReason_BISTStatus(uint8_t index, uint8_t *Data);

/* CAN Debug Message proto*/
extern void f_Send_Dbg_SDLFault_CanTx(uint16_t SDLFault);

void SafetyGuard_NVM_Write_ResetReason(void);
sint8_t SafetyGuard_Wait_for_NVM_Write_Status(void);
#endif
