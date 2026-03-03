/*
 * US_ECUDiagnostic.c
 *
 *  Created on: Feb 23, 2021
 *      Author: e39960
 */
#include "US_ME_Typedefs_Global.h"
#include "US_PlatformCfg_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_ErrMgr_Global.h"
#include "US_Platform_Global.h"

#if(US_CSM_ENABLE == ME_TRUE)
#include "Us_Csm_If.h"
#include "Us_Hsd_CsmIf.h"
#include "Us_Platform_CsmIf.h"
#include "Us_Dsi3Trcv_CsmIf.h"
#include "Us_Calib_CsmIf.h"
#endif

#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
/* TODO-Need to fill with exact DTC maturation & de-maturation times*/
static const US_S_DiagFlagParms_t sUS_ECUFlagParams[DIAG_FLAG_ECU_MAX_CODE] = {{US_DIAGNOSTIC_MAX_COUNTER+96u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*comment out DIAG_FLAG_REAR_BUMPER_SHRT_TO_GND = 0, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+96u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_REAR_BUMPER_OOR_LOW, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+96u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_REAR_BUMPER_OOR_HIGH, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+96u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_REAR_BUMPER_SHRT_TO_BAT, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+96u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_REAR_BUMPER_OPEN, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+96u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_FRONT_BUMPER_OOR_LOW, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+96u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_FRONT_BUMPER_OOR_HIGH, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+96u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_FRONT_BUMPER_SHRT_TO_GND, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+96u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_FRONT_BUMPER_SHRT_TO_BAT, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+96u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_FRONT_BUMPER_OPEN, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_NO_CALI_DATA, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_SPI_DMA_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_CFG_SENSOR_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_GPIO_INT_INITIAL_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_PIN_INITIAL_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI_CLOCK_INITIAL_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI_REF_INITIAL_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_SPI_INITIAL_ERR, */
																                                  {US_DIAGNOSTIC_MAX_COUNTER, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_MCAN_INITIAL_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_USS_POWER_ON_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+16u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI_OT_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+16u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI_CRC_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+16u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI_RFC_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+16u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI_DSIUV_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+16u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI_VCCUV_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+16u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI_RAM_BIST_FAIL, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+16u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI_FSM_RESET, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+16u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI_CLKREF_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+16u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},       /*DIAG_FLAG_ECU_DSI0_OC_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+16u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI1_OC_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+16u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI0_UV_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+16u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI1_UV_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+16u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_COMM_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+16u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO}      /*DIAG_FLAG_ECU_DSI3_registers_mismatch, */

}; 

#else
/* TODO-Need to fill with exact DTC maturation & de-maturation times*/
static const US_S_DiagFlagParms_t sUS_ECUFlagParams[DIAG_FLAG_ECU_MAX_CODE] = {{US_DIAGNOSTIC_MAX_COUNTER+9u, US_DIAGNOSTIC_MIN_COUNTER+9u,  ZERO},      /*DIAG_FLAG_REAR_BUMPER_SHRT_TO_GND = 0, 50*(9+1) =500ms currently it is still time base, used 10ms check */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+9u, US_DIAGNOSTIC_MIN_COUNTER+9u,  ZERO},      /*DIAG_FLAG_REAR_BUMPER_OOR_LOW,         currently it is still time base, used 10ms check */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+9u, US_DIAGNOSTIC_MIN_COUNTER+9u,  ZERO},      /*DIAG_FLAG_REAR_BUMPER_OOR_HIGH,         currently it is still time base, used 10ms check */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+9u, US_DIAGNOSTIC_MIN_COUNTER+9u,  ZERO},      /*DIAG_FLAG_REAR_BUMPER_SHRT_TO_BAT,      currently it is still time base, used 10ms check */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+9u, US_DIAGNOSTIC_MIN_COUNTER+9u,  ZERO},      /*DIAG_FLAG_REAR_BUMPER_OPEN,             currently it is still time base, used 10ms check */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+9u, US_DIAGNOSTIC_MIN_COUNTER+9u,  ZERO},      /*DIAG_FLAG_FRONT_BUMPER_OOR_LOW, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+9u, US_DIAGNOSTIC_MIN_COUNTER+9u,  ZERO},      /*DIAG_FLAG_FRONT_BUMPER_OOR_HIGH, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+9u, US_DIAGNOSTIC_MIN_COUNTER+9u,  ZERO},      /*DIAG_FLAG_FRONT_BUMPER_SHRT_TO_GND, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+9u, US_DIAGNOSTIC_MIN_COUNTER+9u,  ZERO},      /*DIAG_FLAG_FRONT_BUMPER_SHRT_TO_BAT, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+9u, US_DIAGNOSTIC_MIN_COUNTER+9u,  ZERO},      /*DIAG_FLAG_FRONT_BUMPER_OPEN,            currently it is still time base, used 10ms check */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER,  US_DIAGNOSTIC_MIN_COUNTER,  ZERO},        /*DIAG_FLAG_ECU_NO_CALI_DATA, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+31u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_SPI_DMA_ERR,     16 */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+5u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_CFG_SENSOR_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+15u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_GPIO_INT_INITIAL_ERR, 16 */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+15u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_PIN_INITIAL_ERR,      16 */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+15u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI_CLOCK_INITIAL_ERR,  16 */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+15u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_DSI_REF_INITIAL_ERR,     16 */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+15u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_SPI_INITIAL_ERR,         16 */
																  {US_DIAGNOSTIC_MAX_COUNTER+2u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_MCAN_INITIAL_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+149u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},      /*DIAG_FLAG_ECU_USS_POWER_ON_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+14u, US_DIAGNOSTIC_MIN_COUNTER+0u,  ZERO},      /*DIAG_FLAG_ECU_DSI_OT_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+6u, US_DIAGNOSTIC_MIN_COUNTER,  32u},      /*DIAG_FLAG_ECU_DSI_CRC_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+15u, US_DIAGNOSTIC_MIN_COUNTER+0u,  ZERO},      /*DIAG_FLAG_ECU_DSI_RFC_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+13u, US_DIAGNOSTIC_MIN_COUNTER+0u,  ZERO},      /*DIAG_FLAG_ECU_DSI_DSIUV_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+13u, US_DIAGNOSTIC_MIN_COUNTER+0u,  ZERO},      /*DIAG_FLAG_ECU_DSI_VCCUV_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+13u, US_DIAGNOSTIC_MIN_COUNTER+0u,  ZERO},      /*DIAG_FLAG_ECU_DSI_RAM_BIST_FAIL, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+13u, US_DIAGNOSTIC_MIN_COUNTER+0u,  ZERO},      /*DIAG_FLAG_ECU_DSI_FSM_RESET, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+15u, US_DIAGNOSTIC_MIN_COUNTER+0u,  ZERO},      /*DIAG_FLAG_ECU_DSI_CLKREF_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+13u, US_DIAGNOSTIC_MIN_COUNTER+0u,  ZERO},      /*DIAG_FLAG_ECU_DSI0_OC_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+13u, US_DIAGNOSTIC_MIN_COUNTER+0u,  ZERO},       /*DIAG_FLAG_ECU_DSI1_OC_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+14u, US_DIAGNOSTIC_MIN_COUNTER+0u,  ZERO},      /*DIAG_FLAG_ECU_DSI0_UV_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+14u, US_DIAGNOSTIC_MIN_COUNTER+0u,  ZERO},      /*DIAG_FLAG_ECU_DSI1_UV_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+6u, US_DIAGNOSTIC_MIN_COUNTER,  32u},      /*DIAG_FLAG_ECU_COMM_ERR, */
                                                                  {US_DIAGNOSTIC_MAX_COUNTER+15u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO}      /*DIAG_FLAG_ECU_DSI3_registers_mismatch, */
}; 
#endif

#if(US_CSM_ENABLE == ME_TRUE)
/**
 * \brief This is workaround for error reporting as its much complex to report error from respective module.
 * Eventully we have design lower layer in much layered way.US_CSM_LOCAL_MODULE_ID_MAX means error not reorted
 * from this mapping
 */

UsCsm_MappingId_Type sUS_EcuFlagToCsmErrorMapping[DIAG_FLAG_ECU_MAX_CODE] =
{
    {US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_HSD_INSTANCE_ID_REAR,    (UsCsm_LocalErrorId_Type)US_CSM_HSD_ERR_ID_short_to_GND},             /*comment out DIAG_FLAG_REAR_BUMPER_SHRT_TO_GND = 0, */
    {US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_HSD_INSTANCE_ID_REAR,    (UsCsm_LocalErrorId_Type)US_CSM_HSD_ERR_ID_voltage_OOR_Low},          /*DIAG_FLAG_REAR_BUMPER_OOR_LOW, */
	{US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_HSD_INSTANCE_ID_REAR,    (UsCsm_LocalErrorId_Type)US_CSM_HSD_ERR_ID_voltage_OOR_High},         /*DIAG_FLAG_REAR_BUMPER_OOR_HIGH, */
	{US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_HSD_INSTANCE_ID_REAR,    (UsCsm_LocalErrorId_Type)US_CSM_HSD_ERR_ID_Short_to_Bat},             /*DIAG_FLAG_REAR_BUMPER_SHRT_TO_BAT, */
	{US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_HSD_INSTANCE_ID_REAR,    (UsCsm_LocalErrorId_Type)US_CSM_HSD_ERR_ID_OpenCircuit},                 /*DIAG_FLAG_REAR_BUMPER_OPEN, */
	{US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_HSD_INSTANCE_ID_FRONT,   (UsCsm_LocalErrorId_Type)US_CSM_HSD_ERR_ID_short_to_GND},                /*DIAG_FLAG_FRONT_BUMPER_OOR_LOW, */
	{US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_HSD_INSTANCE_ID_FRONT,   (UsCsm_LocalErrorId_Type)US_CSM_HSD_ERR_ID_voltage_OOR_Low},           /*DIAG_FLAG_FRONT_BUMPER_OOR_HIGH, */
	{US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_HSD_INSTANCE_ID_FRONT,   (UsCsm_LocalErrorId_Type)US_CSM_HSD_ERR_ID_voltage_OOR_High},          /*DIAG_FLAG_FRONT_BUMPER_SHRT_TO_GND, */
	{US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_HSD_INSTANCE_ID_FRONT,   (UsCsm_LocalErrorId_Type)US_CSM_HSD_ERR_ID_Short_to_Bat},              /*DIAG_FLAG_FRONT_BUMPER_SHRT_TO_BAT, */
	{US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_HSD_INSTANCE_ID_FRONT,   (UsCsm_LocalErrorId_Type)US_CSM_HSD_ERR_ID_OpenCircuit},               /*DIAG_FLAG_FRONT_BUMPER_OPEN, */
	{US_CSM_LOCAL_MODULE_ID_CALIB,     US_CSM_CALIB_INSTANCE_ID_0,     (UsCsm_LocalErrorId_Type)US_CSM_CALIB_ERR_ID_CALIB_NOT_AVBL},          /*DIAG_FLAG_ECU_NO_CALI_DATA, */
	{US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_PLATFORM_INSTANCE_ID_0,  (UsCsm_LocalErrorId_Type)US_CSM_PLATFORM_ERR_ID_SPI_TX_FAIL},          /*DIAG_FLAG_ECU_SPI_DMA_ERR, */
	{US_CSM_LOCAL_MODULE_ID_CALIB,     US_CSM_CALIB_INSTANCE_ID_0,     (UsCsm_LocalErrorId_Type)US_CSM_CALIB_ERR_ID_SNR_CFG},                 /*DIAG_FLAG_ECU_CFG_SENSOR_ERR, */
	{US_CSM_LOCAL_MODULE_ID_PLATFORM,  US_CSM_PLATFORM_INSTANCE_ID_0,  (UsCsm_LocalErrorId_Type)US_CSM_PLATFORM_ERR_ID_GPIO_INIT},            /*DIAG_FLAG_ECU_GPIO_INT_INITIAL_ERR, */
	{US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_PLATFORM_INSTANCE_ID_0,  (UsCsm_LocalErrorId_Type)US_CSM_PLATFORM_ERR_ID_GPIO_INIT},            /*DIAG_FLAG_ECU_PIN_INITIAL_ERR, */
	{US_CSM_LOCAL_MODULE_ID_PLATFORM,  US_CSM_PLATFORM_INSTANCE_ID_0,  (UsCsm_LocalErrorId_Type)US_CSM_PLATFORM_ERR_ID_DSI3REF_CLK_INIT},     /*DIAG_FLAG_ECU_DSI_CLOCK_INITIAL_ERR, */
	{US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_PLATFORM_INSTANCE_ID_0,  (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_RFC_ERR},             /*DIAG_FLAG_ECU_DSI_REF_INITIAL_ERR, */
	{US_CSM_LOCAL_MODULE_ID_PLATFORM,  US_CSM_PLATFORM_INSTANCE_ID_0,  (UsCsm_LocalErrorId_Type)US_CSM_PLATFORM_ERR_ID_SPI_INIT},             /*DIAG_FLAG_ECU_SPI_INITIAL_ERR, */
	{US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_PLATFORM_INSTANCE_ID_0,  (UsCsm_LocalErrorId_Type)US_CSM_PLATFORM_ERR_ID_MAX},                  /*DIAG_FLAG_ECU_MCAN_INITIAL_ERR, */
	{US_CSM_LOCAL_MODULE_ID_MAX,       US_CSM_CSM_INSTANCE_ID_0,       (UsCsm_LocalErrorId_Type)US_CSM_CSM_ERR_ID_STATE_TIME_OUT_UNINIT},     /*DIAG_FLAG_ECU_USS_POWER_ON_ERR, */
    {US_CSM_LOCAL_MODULE_ID_DSI3_TRCV, US_CSM_DSI3_TRCV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_OT},                  /*DIAG_FLAG_ECU_DSI_OT_ERR, */
    {US_CSM_LOCAL_MODULE_ID_DSI3_TRCV, US_CSM_DSI3_TRCV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_SPI_RX_CRC},            /*DIAG_FLAG_ECU_DSI_CRC_ERR, */
    {US_CSM_LOCAL_MODULE_ID_DSI3_TRCV, US_CSM_DSI3_TRCV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_RFC_ERR},             /*DIAG_FLAG_ECU_DSI_RFC_ERR, */
    {US_CSM_LOCAL_MODULE_ID_DSI3_TRCV, US_CSM_DSI3_TRCV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_VDSIUV},               /*DIAG_FLAG_ECU_DSI_DSIUV_ERR, */
    {US_CSM_LOCAL_MODULE_ID_DSI3_TRCV, US_CSM_DSI3_TRCV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_VCCUV},                 /*DIAG_FLAG_ECU_DSI_VCCUV_ERR, */
    {US_CSM_LOCAL_MODULE_ID_DSI3_TRCV, US_CSM_DSI3_TRCV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_RAM_BIST_FAIL},         /*DIAG_FLAG_ECU_DSI_RAM_BIST_FAIL, */
    {US_CSM_LOCAL_MODULE_ID_DSI3_TRCV, US_CSM_DSI3_TRCV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_DSI_FSM_RESET},          /*DIAG_FLAG_ECU_DSI_FSM_RESET, */
    {US_CSM_LOCAL_MODULE_ID_DSI3_TRCV, US_CSM_DSI3_TRCV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_CLKREF},                 /*DIAG_FLAG_ECU_DSI_CLKREF_ERR, */
    {US_CSM_LOCAL_MODULE_ID_DSI3_TRCV, US_CSM_DSI3_TRCV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_DSI_OC_CH1},             /*DIAG_FLAG_ECU_DSI0_OC_ERR, */
    {US_CSM_LOCAL_MODULE_ID_DSI3_TRCV, US_CSM_DSI3_TRCV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_DSI_OC_CH2},              /*DIAG_FLAG_ECU_DSI1_OC_ERR, */
    {US_CSM_LOCAL_MODULE_ID_DSI3_TRCV, US_CSM_DSI3_TRCV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_DSI_UV_CH1},             /*DIAG_FLAG_ECU_DSI0_UV_ERR, */
    {US_CSM_LOCAL_MODULE_ID_DSI3_TRCV, US_CSM_DSI3_TRCV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_DSI_UV_CH2},             /*DIAG_FLAG_ECU_DSI1_UV_ERR, */
    {US_CSM_LOCAL_MODULE_ID_DSI3_TRCV, US_CSM_DSI3_TRCV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_COMM_ERR},               /*DIAG_FLAG_ECU_COMM_ERR, */
	{US_CSM_LOCAL_MODULE_ID_DSI3_TRCV, US_CSM_DSI3_TRCV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)US_CSM_DSI3_TRCV_ERR_ID_REG_MISMATCH},           /*DIAG_FLAG_ECU_DSI3_registers_mismatch, */
};
#endif

/*counter values to be stored for each ECU DTC*/
static uint16_t US_ECU_Flag_Set_Counters[DIAG_FLAG_ECU_MAX_CODE];
static uint16_t US_ECU_Flag_Clear_Counters[DIAG_FLAG_ECU_MAX_CODE];

/* final set condition of DTCs */
static bool_t US_ECUFaultFagStatus[DIAG_FLAG_ECU_MAX_CODE];
static bool_t US_ECUFaultFagStatus_Confirmed[DIAG_FLAG_ECU_MAX_CODE];


/* Internal functions */
static void US_ECUDiagnostic_ConfirmFlag(US_E_ECUFaultReason_t EcuFlagType);
static void US_ECUDiagnostic_DeleteFlag(US_E_ECUFaultReason_t EcuFlagType);
static Std_ReturnType US_ECUDiagnostic_IncCounter(US_E_ECUFaultReason_t EcuFlagType);
static Std_ReturnType US_ECUDiagnostic_DecCounter(US_E_ECUFaultReason_t EcuFlagType);
static bool_t US_ECUDiagnostic_IsCounterHigh(US_E_ECUFaultReason_t EcuFlagType);
static bool_t US_ECUDiagnostic_IsCounterLow(US_E_ECUFaultReason_t EcuFlagType);

/* ===========================================================================
 * Name:	 US_ECUDiagnostic_ConfirmFlag
 * Remarks:  DD-ID: {18987DF6-0B22-4664-BCFB-73B39CB601C2}
 * Req.-ID:13396045
 * Req.-ID:13396049
 * Req.-ID:13424090
 * ===========================================================================*/

static void US_ECUDiagnostic_ConfirmFlag(US_E_ECUFaultReason_t EcuFlagType)
{
    if (EcuFlagType < DIAG_FLAG_ECU_MAX_CODE)
    {
        if(ZERO == US_ECUFaultFagStatus_Confirmed[EcuFlagType])
        {
            US_ECUFaultFagStatus_Confirmed[EcuFlagType] = (bool_t)ME_TRUE;
            UssErrMgr_UpdateECUDiagFlagStatus(EcuFlagType, (bool_t)ME_TRUE);

#if(US_CSM_ENABLE == ME_TRUE)
            if(US_CSM_LOCAL_MODULE_ID_MAX != sUS_EcuFlagToCsmErrorMapping[EcuFlagType].LocalModuleId)
            {
                UsCsm_ReportLocalError( sUS_EcuFlagToCsmErrorMapping[EcuFlagType].LocalModuleId,
                                        sUS_EcuFlagToCsmErrorMapping[EcuFlagType].InstanceId,
                                        sUS_EcuFlagToCsmErrorMapping[EcuFlagType].LocalErrId,
                                        US_CSM_LOCAL_ERR_STATE_CONFIRM);
            }
#endif

        }
    }
}

/* ===========================================================================
 * Name:	 US_ECUDiagnostic_DeleteFlag
 * Remarks:  DD-ID: {CB755593-C5DF-4339-9482-F6422E0E1318}
 * Req.-ID:13396045
 * Req.-ID:13396049
 * Req.-ID:13424090
 * ===========================================================================*/
static void US_ECUDiagnostic_DeleteFlag(US_E_ECUFaultReason_t EcuFlagType)
{
    if (EcuFlagType < DIAG_FLAG_ECU_MAX_CODE)
    {
        if(ZERO != US_ECUFaultFagStatus_Confirmed[EcuFlagType])
        {
            US_ECUFaultFagStatus_Confirmed[EcuFlagType] = ME_FALSE;
            UssErrMgr_UpdateECUDiagFlagStatus(EcuFlagType, (bool_t)ME_FALSE);

#if(US_CSM_ENABLE == ME_TRUE)
            if(US_CSM_LOCAL_MODULE_ID_MAX != sUS_EcuFlagToCsmErrorMapping[EcuFlagType].LocalModuleId)
            {
                UsCsm_ReportLocalError( sUS_EcuFlagToCsmErrorMapping[EcuFlagType].LocalModuleId,
                                        sUS_EcuFlagToCsmErrorMapping[EcuFlagType].InstanceId,
                                        sUS_EcuFlagToCsmErrorMapping[EcuFlagType].LocalErrId,
                                        US_CSM_LOCAL_ERR_STATE_PASSIVE);
            }
#endif
        }
    }
}

/* ===========================================================================
 * Name:	 US_ECUDiagnostic_IncCounter
 * Remarks:  DD-ID: {2468C0A3-5E20-4ba3-928C-90C549FC7B99}
 * Req.-ID:13396045
 * Req.-ID:13396049
 * Req.-ID:13424090
 * ===========================================================================*/
static Std_ReturnType US_ECUDiagnostic_IncCounter(US_E_ECUFaultReason_t EcuFlagType)
{
    uint32_t  Disconnect_faults,Unknown_faults,SNR_Fail_faults,mask = 0xffffffffu;
    uint16_t uCounterVal, ExtendedMultiplyier = ZERO;
    Std_ReturnType uRetVal = ME_NOT_OK;

    /*Logic to extend debounce counter for faults which might get impacted when sensor lose contact or diconnect is detected*/
  Disconnect_faults =  US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SENSOR_DISCONNECT)&mask;
  Unknown_faults         =  US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SNR_COMM_UNKNOWN)&mask;
 SNR_Fail_faults      =  US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SNR_FAIL)&mask;

    if((Disconnect_faults  != ZERO) ||      (Unknown_faults  != ZERO) ||        (SNR_Fail_faults != ZERO))
    {
        ExtendedMultiplyier = ONE;
    }

    if (EcuFlagType < DIAG_FLAG_ECU_MAX_CODE)
    {
            uCounterVal = US_ECU_Flag_Set_Counters[EcuFlagType];

            if (uCounterVal < (sUS_ECUFlagParams[EcuFlagType].SetDebounceCounter + (ExtendedMultiplyier * (sUS_ECUFlagParams[EcuFlagType].ExtendedSetDebouncecounter))))
            {
            	uCounterVal++;
            	US_ECU_Flag_Set_Counters[EcuFlagType] = uCounterVal;
            }

            uRetVal = ME_OK;
    }

    return uRetVal;
}

/* ===========================================================================
 * Name:	 US_ECUDiagnostic_DecCounter
 * Remarks:  DD-ID: {E65F61C1-5F2F-44b0-9A25-1F31FDCD619A}
 * Req.-ID:13396045
 * Req.-ID:13396049
 * Req.-ID:13424090
 * ===========================================================================*/
static Std_ReturnType US_ECUDiagnostic_DecCounter(US_E_ECUFaultReason_t EcuFlagType)
{
    uint16_t uCounterVal;
    Std_ReturnType uRetVal = ME_NOT_OK;

    if (EcuFlagType < DIAG_FLAG_ECU_MAX_CODE)
    {
        uCounterVal = US_ECU_Flag_Clear_Counters[EcuFlagType];

        if (uCounterVal < sUS_ECUFlagParams[EcuFlagType].ClearDebounceCounter)
        {
            uCounterVal = uCounterVal+1u;
            US_ECU_Flag_Clear_Counters[EcuFlagType] = uCounterVal;
        }

        uRetVal = ME_OK;
    }

    return uRetVal;
}

/* ===========================================================================
 * Name:	 US_ECUDiagnostic_IsCounterHigh
 * Remarks:  DD-ID: {44071E1C-B2C3-42ba-ACF4-FF62B1759646}
 * Req.-ID:13396045
 * Req.-ID:13396049
 * Req.-ID:13424090
 * ===========================================================================*/
static bool_t US_ECUDiagnostic_IsCounterHigh(US_E_ECUFaultReason_t EcuFlagType)
{
    uint32_t  Disconnect_faults,Unknown_faults,SNR_Fail_faults,mask = 0xffffffffu;
    bool_t bRetVal = ME_FALSE;
    uint16_t uCounterVal, ExtendedMultiplyier = ZERO;

    /*Logic to extend debounce counter for faults which might get impacted when sensor lose contact or diconnect is detected*/
  Disconnect_faults =  US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SENSOR_DISCONNECT)&mask;
  Unknown_faults         =  US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SNR_COMM_UNKNOWN)&mask;
 SNR_Fail_faults      =  US_Diagnostic_IsSnrFaultFlagPending(SNR_DIAG_FLG_SNR_FAIL)&mask;

    if((Disconnect_faults  != ZERO) ||      (Unknown_faults  != ZERO) ||        (SNR_Fail_faults != ZERO))
    {
        ExtendedMultiplyier = ONE;
    }

    if (EcuFlagType < DIAG_FLAG_ECU_MAX_CODE)
    {
        uCounterVal = US_ECU_Flag_Set_Counters[EcuFlagType];

        /*comment out if (uCounterVal >= US_ECU_Flag_Set_Counters[EcuFlagType]) */
        if (uCounterVal >=((sUS_ECUFlagParams[EcuFlagType].SetDebounceCounter) + (ExtendedMultiplyier * (sUS_ECUFlagParams[EcuFlagType].ExtendedSetDebouncecounter))))
        {
			bRetVal = (bool_t)ME_TRUE;
        }
    }

    return bRetVal;
}

/* ===========================================================================
 * Name:	 US_ECUDiagnostic_IsCounterLow
 * Remarks:  DD-ID: {330B4D37-B72F-4dfa-A1A7-BCD88BA7B246}
 * Req.-ID:13396045
 * Req.-ID:13396049
 * Req.-ID:13424090
 * ===========================================================================*/
static bool_t US_ECUDiagnostic_IsCounterLow(US_E_ECUFaultReason_t EcuFlagType)
{
    bool_t bRetVal = ME_FALSE;
    uint16_t uCounterVal;

    if (EcuFlagType < DIAG_FLAG_ECU_MAX_CODE)
    {
        uCounterVal = US_ECU_Flag_Clear_Counters[EcuFlagType];

        /*comment out if (uCounterVal <= US_DIAGNOSTIC_MIN_COUNTER) */
        if (uCounterVal >= sUS_ECUFlagParams[EcuFlagType].ClearDebounceCounter)
        {
            bRetVal = (bool_t)ME_TRUE;
        }
    }

    return bRetVal;
}

/* ===========================================================================
 * Name:	 US_ECUDiagnostic_Init
 * Remarks:  DD-ID: {BDD874FE-5C09-4e10-ADD9-1DCBB5BC702D}
 * Req.-ID:13396045
 * ===========================================================================*/

/****************************************/
/* Start Public Functions               */
/****************************************/
void US_ECUDiagnostic_Init(void)
{
	(void)memset((void*)&US_ECUFaultFagStatus,0,sizeof(uint8_t) * ((uint32_t)DIAG_FLAG_ECU_MAX_CODE));
	(void)memset((void*)&US_ECU_Flag_Set_Counters,0,sizeof(uint8_t) * ((uint32_t)DIAG_FLAG_ECU_MAX_CODE));
	(void)memset((void*)&US_ECU_Flag_Clear_Counters,0,sizeof(uint8_t) *((uint32_t) DIAG_FLAG_ECU_MAX_CODE));
}

/*
 * ************* \TODO - This module needs A LOT of work based on System Requirements decisions **********
 */

#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
/* ===========================================================================
 * Name:	 US_Diagnostic_SetECUFlag
 * Remarks:  DD-ID: {44719DCF-DF42-48da-B487-6F3EA1450068}
 * Req.-ID:13396045
 * ===========================================================================*/
void US_Diagnostic_SetECUFlag(US_E_ECUFaultReason_t EcuFlagType)
{	

    if (EcuFlagType < DIAG_FLAG_ECU_MAX_CODE)
    {
        US_ECUFaultFagStatus[EcuFlagType] = ME_TRUE;
    }
}

/* ===========================================================================
 * Name:	 US_Diagnostic_ClrECUFlag
 * Remarks:  DD-ID: {96758F3C-223C-4e13-B83B-D6675692F836}
 * Req.-ID:15768198
 * Req.-ID:15768224
 * Req.-ID:15768291
 * Req.-ID:15768296
 * Req.-ID:15768434
 * Req.-ID:15768440
 * ===========================================================================*/
void US_Diagnostic_ClrECUFlag(US_E_ECUFaultReason_t EcuFlagType)
{	
    if (EcuFlagType < DIAG_FLAG_ECU_MAX_CODE)
    {
        US_ECUFaultFagStatus[EcuFlagType] = ME_FALSE;
    }
}

/* ===========================================================================
 * Name:	 US_ECUDiagFlagCheckMain
 * Remarks:  DD-ID: {1FFF4E6D-8072-4df2-A63F-82195A3F36D1}
 * Req.-ID:13396045
 * Req.-ID:13396049
 * Req.-ID:13424090
 * ===========================================================================*/
void US_ECUDiagFlagCheckMain(void)
{
    uint16_t EcuFlagType;
    bool_t	 bCounter_Reached;

    /*Check for ECU Flags*/
    for(EcuFlagType = 0;EcuFlagType < DIAG_FLAG_ECU_MAX_CODE;EcuFlagType++)
    {
        if(US_ECUFaultFagStatus[EcuFlagType] != US_ECUFaultFagStatus_Confirmed[EcuFlagType])
        {
            if(ME_FALSE == US_ECUFaultFagStatus_Confirmed[EcuFlagType])
            {
                /*Yes, then the Fault Flag is just set & need to be processed through de-bouncing logic*/
                US_ECUDiagnostic_IncCounter((US_E_ECUFaultReason_t)EcuFlagType);
                bCounter_Reached = US_ECUDiagnostic_IsCounterHigh((US_E_ECUFaultReason_t)EcuFlagType);
                /*Is De-bouncing completed*/
                if( ME_FALSE != bCounter_Reached )
                {
                    /*Yes*/
                    US_ECUDiagnostic_ConfirmFlag(EcuFlagType);
                }
                else
                {
                /*No.de-bounce counter not yet reached*/
                }
            }
            else if(ME_TRUE == US_ECUFaultFagStatus_Confirmed[EcuFlagType])
            {
                /*Yes, then the Fault Flag is just cleared & need to be processed through de-bouncing logic*/
                US_ECUDiagnostic_DecCounter((US_E_ECUFaultReason_t)EcuFlagType);
                bCounter_Reached = US_ECUDiagnostic_IsCounterLow((US_E_ECUFaultReason_t)EcuFlagType);
                /*Is De-bouncing completed*/
                if( ME_FALSE != bCounter_Reached )
                {
                    /*Yes*/
                    US_ECUDiagnostic_DeleteFlag((US_E_ECUFaultReason_t)EcuFlagType);
                }
                else
                {
                    /*No.de-bounce counter not yet reached*/
                }
            }
        }
        else
        {
            /*Since Confirmed status & instantaneous status is same resetting SET & Clear count */
            US_ECU_Flag_Clear_Counters[EcuFlagType] = ZERO;
            US_ECU_Flag_Set_Counters[EcuFlagType] = ZERO;
        }
    }
}
#else
/* ===========================================================================
 * Name:     US_Diagnostic_SetECUFlag
 * Remarks:  DD-ID: {67D1D2E6-3B50-4d96-B37F-8F011789EA49}
 * Req.-ID:13396045
 * ===========================================================================*/
void US_Diagnostic_SetECUFlag(US_E_ECUFaultReason_t EcuFlagType)
{
    bool_t   bCounter_Reached;

    if (EcuFlagType < DIAG_FLAG_ECU_MAX_CODE)
    {
        US_ECUFaultFagStatus[EcuFlagType] = (bool_t)ME_TRUE;
        US_ECU_Flag_Clear_Counters[EcuFlagType] = ZERO;

        if((bool_t)ME_FALSE == US_ECUFaultFagStatus_Confirmed[EcuFlagType])
        {
            /*Yes, then the Fault Flag is just set & need to be processed through de-bouncing logic*/
            (void)US_ECUDiagnostic_IncCounter(EcuFlagType);
            bCounter_Reached = US_ECUDiagnostic_IsCounterHigh(EcuFlagType);

            /*Is De-bouncing completed*/
            if( (bool_t)ME_FALSE != bCounter_Reached )
            {
                /*Yes*/
              /*comment out US_ECU_Flag_Clear_Counters[EcuFlagType] = ZERO; */
                US_ECUDiagnostic_ConfirmFlag(EcuFlagType);
            }
        }
    }
}

/* ===========================================================================
 * Name:     US_Diagnostic_ClrECUFlag
 * Remarks:  DD-ID: {96758F3C-223C-4e13-B83B-D6675692F836}
 * Req.-ID:15768198
 * Req.-ID:15768224
 * Req.-ID:15768291
 * Req.-ID:15768296
 * Req.-ID:15768434
 * Req.-ID:15768440
 * ===========================================================================*/
void US_Diagnostic_ClrECUFlag(US_E_ECUFaultReason_t EcuFlagType)
{
    bool_t   bCounter_Reached;

    if (EcuFlagType < DIAG_FLAG_ECU_MAX_CODE)
    {
            US_ECUFaultFagStatus[EcuFlagType] = ZERO;

            /*Yes, then the Fault Flag is just cleared & need to be processed through de-bouncing logic*/
            (void)US_ECUDiagnostic_DecCounter(EcuFlagType);
            bCounter_Reached = US_ECUDiagnostic_IsCounterLow(EcuFlagType);

            /*Is De-bouncing completed*/
            if((bool_t)ME_FALSE != bCounter_Reached)
            {
                /*Yes*/
                US_ECU_Flag_Set_Counters[EcuFlagType] = ZERO;
                US_ECUDiagnostic_DeleteFlag(EcuFlagType);
            }
    }
}
#endif
/* ===========================================================================
 * Name:	 USDiagnostic_GetECUFlag
 * Remarks:  DD-ID:{DE3BCE3D-BAF8-49ce-A41E-5390ADCE509C}
 * Req.-ID:13473301
 * Req.-ID:13473374
 * Req.-ID:13473418
 * Req.-ID:13473420
 * Req.-ID:13394552
 * Req.-ID:13394152
 * Req.-ID:13394917
 * Req.-ID:13394914
 * Req.-ID:15768392
 * Req.-ID:15768418
 *
 * ===========================================================================*/

bool_t USDiagnostic_GetECUFlag(US_E_ECUFaultReason_t EcuFlagType)
{
    if (US_ECUFaultFagStatus[EcuFlagType] == (bool_t)ME_TRUE)
    {
        return ME_TRUE;
    }
    return ME_FALSE;
}
