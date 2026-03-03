/*
 * US_Diagnostic.c
 *
 *  Created on: Feb 23, 2021
 *      Author: e39960
 */
#include "US_ME_Typedefs_Global.h"
#include "US_Diagnostic_Global.h"
#include "US_SnrDrv_Global.h"
#include "US_ErrMgr_Global.h"
#include "US_Platform_Global.h"

#if((US_D_CUR_PLATFORM == US_D_PLATFORM_FISKER)||((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS))
#include "ErrorManagerShared.h"
#endif


#if(US_CSM_ENABLE == ME_TRUE)
#include "Us_Csm_If.h" 
#include "Us_SnrDrv_CsmIf.h"
static const UsCsmErrId_SnrDrv_Type Us_DiagCsmErrIdMap[US_D_MAX_NUM_SENSORS] =
{
    US_CSM_SNR_DRV_ERR_ID_SNR_1_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_2_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_3_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_4_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_5_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_6_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_7_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_8_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_9_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_10_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_11_FAULTS,
    US_CSM_SNR_DRV_ERR_ID_SNR_12_FAULTS
};
static uint8_t US_Diagnostics_IsAnyFaultOnSnr(uint8_t SnrIdx);
#endif

#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
uint8_t UssMgr_GetDiagnostic_CheckFlag(void);
void UssMgr_ClearDiagnostic_CheckFlag(void);
/* ToDo - move to calibration*/
/*Need to defined as per exact requirement SET/CLEAR de-bounce counters*/
static const US_S_DiagFlagParms_t sUS_SnrFlagParams[SNR_DIAG_FLG_SNR_FLAG_MAX_CODE] = {
                              	                                    {US_DIAGNOSTIC_MAX_COUNTER,      US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*comment out SNR_DIAG_FLG_SNR_TEMPERATURE_OUT_OF_RANGE = 0, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER,      US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},       /*SNR_DIAG_FLG_SENSOR_DISCONNECT, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER,      US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_RECEIVED_COMMAND_INVALID, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER,      US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_PDCM_PULSE_INVALID, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER,      US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_DISCOVERY_PULSE_INVALID, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER,      US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_FCC_ERROR_STATE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER,      US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_INVALID_START_EDGE_DETECTED, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER,      US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_SYNCHRONISATION_COUNTER_ERROR_DETECTED, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER,      US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_CRM_TYPE_ERROR, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER,      US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_SNR_COMM_UNKNOWN, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_DRV1_FAILURE_DURING_BURST, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_DRV2_FAILURE_DURING_BURST, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_DRVS_FAILURE_DURING_BURST, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_BURST_ABORT_DURING_BURST, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_RING_COMPARATOR_ZERO, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_GET_DRV_FREQUENCY_FAILURE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_SRAM_PARITY_ERROR, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A1, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A2, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_ADA_MEASURE_TIMEOUT, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_PROGRAM_EEPROM, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_VTANK_OVER_VOLTAGE_DURING_BURST, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_VTANK_OVERVOLTAGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_VTANK_UNDERVOLTAGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_VSUP_OVER_VOLTAGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_VSUP_UNDER_VOLTAGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+96u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_BAD_RING_TIME, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_TRANSDUCER_ERR, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_SNR_BLOCKAGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},     /*SNR_DIAG_FLG_SNR_FW_MISMATCH, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO}, 	   /*SNR_DIAG_FLG_SNR_OPMODE_ERROR, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO}, 	   /*SNR_DIAG_FLG_SNR_FAIL, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_CRC_MISMATCH_IN_OTP, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_DSP_CONFIG_REGISTER_MISMATCH, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_CPU_CONFIG_REGISTER_MISMATCH, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_NOISE_DURING_BURST, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_VREF_OUT_OF_RANGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_VREF_OTP_OUT_OF_RANGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_VDDD_OUT_OF_RANGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_WD_COUNTER_DESYNC, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+96u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_WD_CLOCK_FAIL, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_CRC_BLOCK_CFG1, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_CRC_BLOCK_CFG2, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_CRC_BLOCK_MFG1, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_CRC_BLOCK_MFG2, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},      /*SNR_DIAG_FLG_CRC_OP_MODE1, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO},       /*SNR_DIAG_FLG_CRC_OP_MODE2, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+16u,   US_DIAGNOSTIC_MIN_COUNTER+3u,  ZERO}       /*SNR_DIAG_FLG_SIGNAL_PATH_FAILURE, */
};
#else
/*Need to defined as per exact requirement SET/CLEAR de-bounce counters*/
static const US_S_DiagFlagParms_t sUS_SnrFlagParams[SNR_DIAG_FLG_SNR_FLAG_MAX_CODE] = {
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*0 comment out SNR_TEMPERATURE_OUT_OF_RANGE = 0, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_SENSOR_DISCONNECT, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_RECEIVED_COMMAND_INVALID, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_PDCM_PULSE_INVALID, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_DISCOVERY_PULSE_INVALID, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_FCC_ERROR_STATE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_INVALID_START_EDGE_DETECTED, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_SYNCHRONISATION_COUNTER_ERROR_DETECTED, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_CRM_TYPE_ERROR, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_SNR_COMM_UNKNOWN, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*10 SNR_DIAG_FLG_DRV1_FAILURE_DURING_BURST, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_DRV2_FAILURE_DURING_BURST, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_DRVS_FAILURE_DURING_BURST, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_BURST_ABORT_DURING_BURST, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_RING_COMPARATOR_ZERO, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_GET_DRV_FREQUENCY_FAILURE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_SRAM_PARITY_ERROR, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A1, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A2, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /* 20 SNR_DIAG_FLG_ADA_MEASURE_TIMEOUT, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_PROGRAM_EEPROM, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_VTANK_OVER_VOLTAGE_DURING_BURST, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_VTANK_OVERVOLTAGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_VTANK_UNDERVOLTAGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_VSUP_OVER_VOLTAGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_VSUP_UNDER_VOLTAGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+15u, US_DIAGNOSTIC_MIN_COUNTER+2u,ZERO},  /* SNR_DIAG_FLG_BAD_RING_TIME, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+15u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},  /*SNR_DIAG_FLG_TRANSDUCER_ERR, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER, US_DIAGNOSTIC_MIN_COUNTER,ZERO},     /*SNR_DIAG_FLG_SNR_BLOCKAGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+2u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*30 SNR_DIAG_FLG_SNR_FW_MISMATCH, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+2u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_SNR_OPMODE_ERROR, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+2u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_SNR_FAIL, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_CRC_MISMATCH_IN_OTP, */
 								                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_DSP_CONFIG_REGISTER_MISMATCH, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_CPU_CONFIG_REGISTER_MISMATCH, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_NOISE_DURING_BURST, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_VREF_OUT_OF_RANGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_VREF_OTP_OUT_OF_RANGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*40 SNR_DIAG_FLG_VDDD_OUT_OF_RANGE, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_WD_COUNTER_DESYNC, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_WD_CLOCK_FAIL, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_CRC_BLOCK_CFG1, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_CRC_BLOCK_CFG2, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_CRC_BLOCK_MFG1, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_CRC_BLOCK_MFG2, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_CRC_OP_MODE1, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO},     /*SNR_DIAG_FLG_CRC_OP_MODE2, */
                                                                    {US_DIAGNOSTIC_MAX_COUNTER+7u, US_DIAGNOSTIC_MIN_COUNTER,  ZERO}      /*49 SNR_DIAG_FLG_SIGNAL_PATH_FAILURE, */
};
#endif

/* internal counters of different raw sensor fault flags */
/* when the fault has occured enough times, the fault can be fully set/confirmed */
/* array of sensor index x DTC_Type */
static uint16_t US_SnrFlag_Set_Counters[US_D_MAX_NUM_SENSORS][SNR_DIAG_FLG_SNR_FLAG_MAX_CODE];
static uint16_t US_SnrFlag_Clear_Counters[US_D_MAX_NUM_SENSORS][SNR_DIAG_FLG_SNR_FLAG_MAX_CODE];
/*comment out static uint8_t US_DTC_Set_Counters[DTC_MAX_CODE][US_D_MAX_NUM_SENSORS]; */

/* final set condition of DTCs */
static uint32_t US_DTC_SnrMap_Per_FLG_Type[SNR_DIAG_FLG_SNR_FLAG_MAX_CODE];
static uint32_t US_DTC_SnrMap_Per_FLG_Type_Confirmed[SNR_DIAG_FLG_SNR_FLAG_MAX_CODE];
/*comment out uint16_t James_Debug[32]; */

/* Internal functions */
static void US_Diagnostic_ConfirmSnrFaultFlag(US_E_SnrFaultReason_t SnrFlagType, uint8_t SnrIdx);
static void US_Diagnostic_DeleteSnrFaultFlag(US_E_SnrFaultReason_t SnrFlagType, uint8_t SnrIdx);
static Std_ReturnType US_Diagnostic_IncCounter(US_E_SnrFaultReason_t SnrFlagType, uint8_t SnrIdx);
static Std_ReturnType US_Diagnostic_DecCounter(US_E_SnrFaultReason_t SnrFlagType, uint8_t SnrIdx);
static bool_t US_Diagnostic_IsCounterHigh(US_E_SnrFaultReason_t SnrFlagType, uint8_t SnrIdx);
static bool_t US_Diagnostic_IsCounterLow(US_E_SnrFaultReason_t SnrFlagType, uint8_t SnrIdx);


static void US_DiagnosticsUpdateFaultFlagstatus(uint8_t sensorID,US_E_SnrFaultReason_t SnrFlagType,bool_t faultFlagStatus);

#if(US_CSM_ENABLE == ME_TRUE)
static uint8_t US_Diagnostics_IsAnyFaultOnSnr(uint8_t SnrIdx);
static uint8_t US_Diagnostics_IsErrConfiguredToReportToCsm( uint16_t SnrErrFlagIdx);
#endif

/* ===========================================================================
 * Name:	 US_Diagnostic_ConfirmSnrFaultFlag
 * Remarks:  DD-ID: {BC7485CE-580D-4904-91C8-9E19C946E356}
 * Req.-ID: 13396045
 * ===========================================================================*/
static void US_Diagnostic_ConfirmSnrFaultFlag(US_E_SnrFaultReason_t SnrFlagType, uint8_t SnrIdx)
{
    uint32_t uBitMask;

    if (SnrFlagType < SNR_DIAG_FLG_SNR_FLAG_MAX_CODE)
    {
        if (SnrIdx < US_D_MAX_NUM_SENSORS)
        {
            uBitMask = (uint32_t)US_IDX_TO_BIT_LOC(SnrIdx);              
            US_DTC_SnrMap_Per_FLG_Type_Confirmed[SnrFlagType] |= uBitMask;
            /*comment out James_Debug[DTC_Type] |= uBitMask; */
            US_DiagnosticsUpdateFaultFlagstatus(SnrIdx,SnrFlagType,ME_TRUE);

#if(US_CSM_ENABLE == ME_TRUE)
            if((uint8_t)ME_TRUE == US_Diagnostics_IsErrConfiguredToReportToCsm((uint16_t)SnrFlagType))
            {
                UsCsm_ReportLocalError(US_CSM_LOCAL_MODULE_ID_SNR_DRV, US_CSM_SNR_DRV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)Us_DiagCsmErrIdMap[SnrIdx], US_CSM_LOCAL_ERR_STATE_CONFIRM);   
            }
#endif
        }else{/*empty*/}
    }else{/*empty*/}
}

/* ===========================================================================
 * Name:	 US_Diagnostic_DeleteSnrFaultFlag
 * Remarks:  DD-ID: {DBF23852-A312-4092-9E83-B64517A8AFCE}
 * Req.-ID: 13396049
 * ===========================================================================*/
static void US_Diagnostic_DeleteSnrFaultFlag(US_E_SnrFaultReason_t SnrFlagType, uint8_t SnrIdx)
{
    uint32_t uBitMask;

    if (SnrFlagType < SNR_DIAG_FLG_SNR_FLAG_MAX_CODE)
    {
        if (SnrIdx < US_D_MAX_NUM_SENSORS )
        {
            uBitMask = (uint32_t)US_IDX_TO_BIT_LOC(SnrIdx);     
            US_DTC_SnrMap_Per_FLG_Type_Confirmed[SnrFlagType] &= ~uBitMask;
            /*comment out James_Debug[DTC_Type] &= ~uBitMask; */
            US_DiagnosticsUpdateFaultFlagstatus(SnrIdx,SnrFlagType,ME_FALSE);

#if(US_CSM_ENABLE == ME_TRUE)
            if((uint8_t)ME_FALSE == US_Diagnostics_IsAnyFaultOnSnr(SnrIdx))
            {
               UsCsm_ReportLocalError(US_CSM_LOCAL_MODULE_ID_SNR_DRV, US_CSM_SNR_DRV_INSTANCE_ID_0, (UsCsm_LocalErrorId_Type)Us_DiagCsmErrIdMap[SnrIdx], US_CSM_LOCAL_ERR_STATE_PASSIVE);     
            }
#endif

        }
    }
}

/* ===========================================================================
 * Name:	US_Diagnostic_IncCounter
 * Remarks:  DD-ID: {F2A9E8C1-FDAE-45ab-8C8A-B52FFBE2A931}
 * Req.-ID: 13396049
 * ===========================================================================*/
static Std_ReturnType US_Diagnostic_IncCounter(US_E_SnrFaultReason_t SnrFlagType, uint8_t SnrIdx)
{
    uint16_t uCounterVal;
    Std_ReturnType uRetVal = (uint8_t)ME_NOT_OK;

    if (SnrFlagType < SNR_DIAG_FLG_SNR_FLAG_MAX_CODE)
    {
        if (SnrIdx < US_D_MAX_NUM_SENSORS )
        {
            uCounterVal = US_SnrFlag_Set_Counters[SnrIdx][SnrFlagType];

            if (uCounterVal < sUS_SnrFlagParams[SnrFlagType].SetDebounceCounter)
            {
            	uCounterVal = uCounterVal+1u;
            	US_SnrFlag_Set_Counters[SnrIdx][SnrFlagType] = uCounterVal;
            }

            uRetVal = ME_OK;
        }
    }

    return uRetVal;
}

/* ===========================================================================
 * Name:	 US_Diagnostic_DecCounter
 * Remarks:  DD-ID: {54ADDB4F-CB01-4079-B24D-7E898836798E}
 * Req.-ID: 13396049
 * ===========================================================================*/
static Std_ReturnType US_Diagnostic_DecCounter(US_E_SnrFaultReason_t SnrFlagType, uint8_t SnrIdx)
{
    uint16_t uCounterVal;
    Std_ReturnType uRetVal = (uint8_t)ME_NOT_OK;

    if (SnrFlagType < SNR_DIAG_FLG_SNR_FLAG_MAX_CODE)
    {
        if (SnrIdx < US_D_MAX_NUM_SENSORS )
        {
            uCounterVal = US_SnrFlag_Clear_Counters[SnrIdx][SnrFlagType];

            if (uCounterVal < sUS_SnrFlagParams[SnrFlagType].ClearDebounceCounter)
            {
                uCounterVal++;
                US_SnrFlag_Clear_Counters[SnrIdx][SnrFlagType] = uCounterVal;
            }

            uRetVal = ME_OK;
        }
    }

    return uRetVal;
}

/* ===========================================================================
 * Name:	 US_Diagnostic_IsCounterHigh
 * Remarks:  DD-ID: {98D1CFF1-545A-43aa-8BCD-7D2370394364}
 * Req.-ID: 13396049
 * ===========================================================================*/
static bool_t US_Diagnostic_IsCounterHigh(US_E_SnrFaultReason_t SnrFlagType, uint8_t SnrIdx)
{
    bool_t bRetVal = (bool_t)ME_FALSE;
    uint16_t uCounterVal;

    if (SnrFlagType < SNR_DIAG_FLG_SNR_FLAG_MAX_CODE)
    {
        if (SnrIdx < US_D_MAX_NUM_SENSORS )
        {
            uCounterVal = US_SnrFlag_Set_Counters[SnrIdx][SnrFlagType];

            /*comment out if (uCounterVal >= sUS_DTC_Set_Table[DTC_Type]) */
            if(uCounterVal >= sUS_SnrFlagParams[SnrFlagType].SetDebounceCounter)
            {
                bRetVal = (bool_t)ME_TRUE;
            }
        }
    }

    return bRetVal;
}

/* ===========================================================================
 * Name:	 US_Diagnostic_IsCounterLow
 * Remarks:  DD-ID: {1BD924DC-696A-4422-8261-F56DFF9869D6}
 * Req.-ID: 13396049
 * ===========================================================================*/
static bool_t US_Diagnostic_IsCounterLow(US_E_SnrFaultReason_t SnrFlagType, uint8_t SnrIdx)
{
    bool_t bRetVal = (bool_t)ME_FALSE;
    uint16_t uCounterVal;

    if (SnrFlagType < SNR_DIAG_FLG_SNR_FLAG_MAX_CODE)
    {
        if (SnrIdx < US_D_MAX_NUM_SENSORS )
        {
            uCounterVal = US_SnrFlag_Clear_Counters[SnrIdx][SnrFlagType];

            if (uCounterVal >= sUS_SnrFlagParams[SnrFlagType].ClearDebounceCounter)
            {
                bRetVal = (bool_t)ME_TRUE;
            }
        }
    }

    return bRetVal;
}

/* ===========================================================================
 * Name:	 US_Diagnostic_Init
 * Remarks:  DD-ID: {957FC4F4-2C38-441b-BF48-DA1876639E26}
 * Req.-ID: 13396045
 * ===========================================================================*/

/****************************************/
/* Start Public Functions               */
/****************************************/
void US_Diagnostic_Init(void)
{
	(void)memset((void*)&US_DTC_SnrMap_Per_FLG_Type,0,sizeof(uint32_t) * ((uint32_t)SNR_DIAG_FLG_SNR_FLAG_MAX_CODE));
	(void)memset((void*)&US_SnrFlag_Set_Counters,0,sizeof(uint16_t) * ((uint32_t)US_D_MAX_NUM_SENSORS) *((uint32_t) SNR_DIAG_FLG_SNR_FLAG_MAX_CODE));
	(void)memset((void*)&US_SnrFlag_Clear_Counters,0,sizeof(uint16_t) * ((uint32_t)US_D_MAX_NUM_SENSORS) * ((uint32_t)SNR_DIAG_FLG_SNR_FLAG_MAX_CODE));
}

/*
 * ************* \TODO - This module needs A LOT of work based on System Requirements decisions **********
 */
#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
/*===========================================================================
 * \brief API to set the sensor flag
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 */
/* ===========================================================================
 * Name:	 US_Diagnostic_SetSnrFaultFlag
 * Remarks:  DD-ID: {EE02A35E-C7D7-422b-8560-F1DF543F1880}
 * Req.-ID: 13414924
 * Req.-ID: 13410409
 * Req.-ID: 13473308
 * ===========================================================================*/
void US_Diagnostic_SetSnrFaultFlag(US_E_SnrFaultReason_t SnrFlagType, uint32_t SnrMap)
{
    uint32_t uSnrMap,uSnrGrpMap,cnt;
    bool_t   bGrpPwrErr;
	uint8_t  Trcvr;
    const US_S_PlatPhysInfo_t * sPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();
    Trcvr  = US_SnrDrv_GetChnStatus();
    bGrpPwrErr = ME_FALSE;	
	for(cnt = ZERO;cnt < US_D_PHYS_GRP_MAX; cnt ++)
	{
	   uSnrGrpMap = sPlatPhysInfo->psSnrPhysGrp[cnt].uGrpSnrIdxBitMap;
	   if((uSnrMap & uSnrGrpMap) != ZERO)
	   {
			if(UssHsd_f_GetOnFaultDetectedFlags(cnt) != ME_FALSE)
			{
				bGrpPwrErr  = ME_TRUE; 
				break;
			}
	   }
	}
    if ((SnrFlagType < SNR_DIAG_FLG_SNR_FLAG_MAX_CODE)&&(bGrpPwrErr == ME_FALSE)&&(Trcvr == DSI3_CHANNEL_ENABLED))
    {
    	US_DTC_SnrMap_Per_FLG_Type[SnrFlagType] |= SnrMap;
    }
}



/*===========================================================================
 * \brief Function to call check the sensor specific errors
 *
 * \param none
 * \param none
 * \return none
 * \remarks This functions need to call periodically to check the fault flag status & based on the debounce(inc/dec)
 *  counter values set the confirmed flag
 */

/* ===========================================================================
 * Name:     US_SnrDiagFlagCheckMain
 * Remarks:  DD-ID: {B8149F55-D458-4959-8259-AE83FD16E8AD}
 * Req.-ID: 14992484
 * ===========================================================================*/
void US_SnrDiagFlagCheckMain(void)
{
    uint16_t SnrFlagType;
    uint32_t FlagChanged,FaultFlagSnrMap;
    uint8_t  uSnrIdx;
    bool_t   bCounter_Reached;

    if(UssMgr_GetDiagnostic_CheckFlag()==ME_TRUE)
    {
        UssMgr_ClearDiagnostic_CheckFlag();
    /*Traverse throght the Fault list*/
    for (SnrFlagType = ZERO; SnrFlagType < (uint16_t)SNR_DIAG_FLG_SNR_FLAG_MAX_CODE; SnrFlagType++)
    {
        FlagChanged = US_DTC_SnrMap_Per_FLG_Type[SnrFlagType] ^ US_DTC_SnrMap_Per_FLG_Type_Confirmed[SnrFlagType];
        /*Check the Fault sensor Map is changed , i.e any fault is set/clear for any of the sensor*/
        if(FlagChanged != ZERO)
        {
            FaultFlagSnrMap = US_DTC_SnrMap_Per_FLG_Type[SnrFlagType];

            /*Fault flag Sensor Map is checked, traverse through Sensor list*/
            for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
            {
                /*Is this sensor Fault is in SET condition*/
                if(ZERO != ((FlagChanged>>uSnrIdx) & BIT0))
                {
                    /*Is this sensor Fault is not confirmed */
                    if ( ZERO != ((FaultFlagSnrMap>>uSnrIdx) & BIT0) )
                    {
                        US_SnrFlag_Clear_Counters[uSnrIdx][SnrFlagType] = ZERO;
                        /*Yes, then the Fault Flag is just set & need to be processed through de-bouncing logic*/
                        (void)US_Diagnostic_IncCounter( (US_E_SnrFaultReason_t)SnrFlagType, uSnrIdx);
                        bCounter_Reached = US_Diagnostic_IsCounterHigh( (US_E_SnrFaultReason_t)SnrFlagType, uSnrIdx);
                        /*Is De-bouncing completed*/
                        if( ME_FALSE != bCounter_Reached )
                        {
                            /*Yes*/
                            US_Diagnostic_ConfirmSnrFaultFlag( (US_E_SnrFaultReason_t)SnrFlagType, uSnrIdx);

                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        US_SnrFlag_Set_Counters[uSnrIdx][SnrFlagType] = ZERO;
                        /*Yes, then the Fault Flag is just cleared & need to be processed through de-bouncing logic*/
                        US_Diagnostic_DecCounter( (US_E_SnrFaultReason_t)SnrFlagType, uSnrIdx);
                        bCounter_Reached = US_Diagnostic_IsCounterLow( (US_E_SnrFaultReason_t)SnrFlagType, uSnrIdx);
                        /*Is De-bouncing completed*/
                        if( ME_FALSE != bCounter_Reached )
                        {
                            /*Yes*/
                            US_Diagnostic_DeleteSnrFaultFlag( (US_E_SnrFaultReason_t)SnrFlagType, uSnrIdx);
                        }
                        else
                        {
                            /*No.de-bounce counter not yet reached*/
                        }
                    }
                }
                else
                {
                    US_SnrFlag_Set_Counters[uSnrIdx][SnrFlagType] = ZERO;
                    US_SnrFlag_Clear_Counters[uSnrIdx][SnrFlagType] = ZERO;
                }
            }
        }
        else
        {
            for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
            {
                /*No, Sensor Fault Flag is already in CLEAR state, no need to process through*/
                US_SnrFlag_Clear_Counters[uSnrIdx][SnrFlagType] = ZERO;
                US_SnrFlag_Set_Counters[uSnrIdx][SnrFlagType] = ZERO;
        /*comment out memset((void*)&US_SnrFlag_Set_Counters[SnrFlagType],0,sizeof(uint16_t) *  US_D_MAX_NUM_SENSORS); */
        /*comment out memset((void*)&US_SnrFlag_Clear_Counters[SnrFlagType],0,sizeof(uint16_t)  * US_D_MAX_NUM_SENSORS); */
            }
        }
      }
    }
}
#else
/*===========================================================================
 * \brief API to set the sensor flag
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 */
/* ===========================================================================
 * Name:     US_Diagnostic_SetSnrFaultFlagByIdx
 * Remarks:  DD-ID: {D7BFB8B8-FB33-4c2c-B291-41913DB3438F}
 * Req.-ID: 13414924
 * Req.-ID: 13410409
 * Req.-ID: 13473308
 * ===========================================================================*/
void US_Diagnostic_SetSnrFaultFlagByIdx(US_E_SnrFaultReason_t uSnrFlagType, uint8_t uSnrIdx)
{

    uint32_t uSnrMap,uSnrGrpMap;
    bool_t   bCounter_Reached,bGrpPwrErr,bHsdFault;
	uint8_t  Trcvr,cnt;
    const US_S_PlatPhysInfo_t * sPlatPhysInfo = UssCtrl_psGetPlatPhysInfo();
    Trcvr  = US_SnrDrv_GetChnStatus();
    
    bGrpPwrErr = ME_FALSE;	
    uSnrMap = (uint32_t)US_IDX_TO_BIT_LOC(uSnrIdx); 
	for(cnt = ZERO;cnt < US_D_PHYS_GRP_MAX; cnt ++)
	{
	   uSnrGrpMap = sPlatPhysInfo->psSnrPhysGrp[cnt].uGrpSnrIdxBitMap;
	   if((uSnrMap & uSnrGrpMap) != ZERO)
	   {
                                                               bHsdFault  = UssHsd_f_GetOnFaultDetectedFlags(cnt);
			if(bHsdFault != (bool_t)ME_FALSE)
			{
				bGrpPwrErr  = (bool_t)ME_TRUE; 
				break;
			}
	   }
	}
    if ((uSnrFlagType < (US_E_SnrFaultReason_t)SNR_DIAG_FLG_SNR_FLAG_MAX_CODE)&&(bGrpPwrErr ==(bool_t) ME_FALSE)&&(Trcvr == (uint8_t)DSI3_CHANNEL_ENABLED))
    {
        if (uSnrIdx < US_D_MAX_NUM_SENSORS )
        {
            US_DTC_SnrMap_Per_FLG_Type[uSnrFlagType] |= uSnrMap;
            US_SnrFlag_Clear_Counters[uSnrIdx][uSnrFlagType] = ZERO;

            if ((US_DTC_SnrMap_Per_FLG_Type_Confirmed[uSnrFlagType] & uSnrMap) == ZERO) /*Not yet confirmed */
            {
                /*Yes, then the Fault Flag is just set & need to be processed through de-bouncing logic*/
                (void)US_Diagnostic_IncCounter(uSnrFlagType, uSnrIdx);
                bCounter_Reached = US_Diagnostic_IsCounterHigh(uSnrFlagType, uSnrIdx);

                /*Is De-bouncing completed*/
                if( (bool_t)ME_FALSE != bCounter_Reached )
                {
                    /*Yes*/
                  /*comment out US_SnrFlag_Clear_Counters[uSnrIdx][uSnrFlagType] = ZERO; */
                    US_Diagnostic_ConfirmSnrFaultFlag(uSnrFlagType, uSnrIdx);
                }
            }
        }
    }
}

/*===========================================================================
 * \brief API to clear the sensor flag
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 */

/* ===========================================================================
 * Name:     US_Diagnostic_ClrSnrFaultFlagByIdx
 * Remarks:  DD-ID: {FF525998-E73F-42a2-938B-CF0EABF2F659}
 * Req.-ID: 13414924
 * Req.-ID: 13410409
 * Req.-ID: 13473308
 * ===========================================================================*/
void US_Diagnostic_ClrSnrFaultFlagByIdx(US_E_SnrFaultReason_t uSnrFlagType, uint8_t uSnrIdx)
{
    uint32_t uSnrMap;
    bool_t   bCounter_Reached;

    uSnrMap = (uint32_t)US_IDX_TO_BIT_LOC(uSnrIdx);   

    if (uSnrFlagType < SNR_DIAG_FLG_SNR_FLAG_MAX_CODE)
    {
        if (uSnrIdx < US_D_MAX_NUM_SENSORS)
        {
                US_DTC_SnrMap_Per_FLG_Type[uSnrFlagType] &= ~uSnrMap;

                /*Yes, then the Fault Flag is just cleared & need to be processed through de-bouncing logic*/
                (void)US_Diagnostic_DecCounter(uSnrFlagType, uSnrIdx);
                bCounter_Reached = US_Diagnostic_IsCounterLow(uSnrFlagType, uSnrIdx);

                /*Is De-bouncing completed*/
                if( (bool_t)ME_FALSE != bCounter_Reached )
                {
                    /*Yes*/
                    US_SnrFlag_Set_Counters[uSnrIdx][uSnrFlagType] = ZERO;
                    if ((US_DTC_SnrMap_Per_FLG_Type_Confirmed[uSnrFlagType] & uSnrMap) != ZERO) /*Not yet cleared */
                    {
                       US_Diagnostic_DeleteSnrFaultFlag( uSnrFlagType, uSnrIdx);
                    }
               }
        }
    }
}

#endif

#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
/*===========================================================================
 * \brief API to clear the sensor flag
 *
 * \param none
 * \param none
 * \return none
 * \remarks
 */

/* ===========================================================================
 * Name:	 US_Diagnostic_ClrSnrFaultFlag
 * Remarks:  DD-ID: {FF525998-E73F-42a2-938B-CF0EABF2F659}
 * Req.-ID: 13414924
 * Req.-ID: 13410409
 * Req.-ID: 13473308
 * ===========================================================================*/
void US_Diagnostic_ClrSnrFaultFlag(US_E_SnrFaultReason_t SnrFlagType, uint32_t SnrMap)       
{
    if (SnrFlagType < SNR_DIAG_FLG_SNR_FLAG_MAX_CODE)
    {
    	US_DTC_SnrMap_Per_FLG_Type[SnrFlagType] &= ~SnrMap;
    }
}
#endif
/* ===========================================================================
 * Name:	 US_Diagnostic_GetSnrMapFaultFlag
 * Remarks:  DD-ID: {79A06A4C-1E84-4fb5-9C81-626BD24B022B}
 * Req.-ID: 13396045
 * ===========================================================================*/



uint32_t US_Diagnostic_GetSnrMapFaultFlag(US_E_SnrFaultReason_t SnrFlagType)
{
    uint32_t uRetSnrMap = ZERO;

    if (SnrFlagType < SNR_DIAG_FLG_SNR_FLAG_MAX_CODE)
    {
        uRetSnrMap = US_DTC_SnrMap_Per_FLG_Type_Confirmed[SnrFlagType];
    }

    return uRetSnrMap;
}

/* ===========================================================================
 * Name:	 US_Diagnostic_IsSnrFaultFlagPending
 * Remarks:  DD-ID: {38D28A91-D72E-425d-88C7-FD033484D13B}
 * Req.-ID: 13396045
 * ===========================================================================*/
uint32_t US_Diagnostic_IsSnrFaultFlagPending(US_E_SnrFaultReason_t SnrFlagType)
{
    uint32_t uRetSnrMap = ZERO;
    uint16_t uSnrIdx;
    uint16_t  uCounterVal;
    uint32_t  FaultSnrMap = 0;
    
    if (SnrFlagType < SNR_DIAG_FLG_SNR_FLAG_MAX_CODE)
    {
    	FaultSnrMap = US_DTC_SnrMap_Per_FLG_Type_Confirmed[SnrFlagType];

        for (uSnrIdx = ZERO; uSnrIdx < US_D_MAX_NUM_SENSORS; uSnrIdx++)
        {
            uCounterVal = US_SnrFlag_Set_Counters[uSnrIdx][SnrFlagType];
            
            /*comment out if (uCounterVal > US_DIAGNOSTIC_MIN_COUNTER) */
            if(((uint16_t)ZERO != uCounterVal) || (ZERO != ((FaultSnrMap>>uSnrIdx) & BIT0)))
            {
                uRetSnrMap |= (uint32_t)US_IDX_TO_BIT_LOC(uSnrIdx);             
            }
        }
    }

    return uRetSnrMap;
}

/* ===========================================================================
 * Name:	 US_Diagnostics_GetSnrFaultFlagStatus
 * Remarks:  DD-ID: {32021235-843A-42f1-A4D1-BC9917993B5D}
 * Req.-ID: 13424090
 * ===========================================================================*/

/*This Function is to get the status of individual Faults of sensors*/
bool_t US_Diagnostics_GetSnrFaultFlagStatus(US_E_SnrFaultReason_t SnrFlagType,uint8_t SnrIdx)
{
	bool_t FaultStatus = ME_FALSE;

	if(((US_DTC_SnrMap_Per_FLG_Type_Confirmed[SnrFlagType] >> SnrIdx) & BIT0) == BIT0) 
	{
		FaultStatus = ME_TRUE;
	}
	else
	{
		FaultStatus = ME_FALSE;
	}
	return FaultStatus;
}

/* ===========================================================================
 * Name:	 US_DiagnosticsUpdateFaultFlagstatus
 * Remarks:  DD-ID: {B3E0673B-E33B-49e7-ACFC-173CBF29AAD0}
 * Req.-ID: 13424090
 * ===========================================================================*/

static void US_DiagnosticsUpdateFaultFlagstatus(uint8_t sensorID,US_E_SnrFaultReason_t SnrFlagType,bool_t faultFlagStatus)
{
	/*Call the API of Error Manager to Clear the customer specific Faults*/
	/*comment out void UssErrMgr_UpdateSensorDiagFlagStatus(uint8_t sensorID,uint16_t SnrFlagType,ErrorMgr_enErrorStatus status)*/
	UssErrMgr_UpdateSensorDiagFlagStatus(sensorID,SnrFlagType,faultFlagStatus);
}

#if(US_CSM_ENABLE == ME_TRUE)
/**
 * \brief This 
 * 
 * \param SnrFlagType 
 * \param SnrIdx 
 */

/* ===========================================================================
 * Name:	 US_Diagnostics_IsAnyFaultOnSnr
 * Remarks:  DD-ID: {C930E6B5-FD69-4515-BAC8-913A8C1512BA}
 * Req.-ID: 13424090
 * ===========================================================================*/

static uint8_t US_Diagnostics_IsAnyFaultOnSnr(uint8_t SnrIdx)
{
    uint16_t SnrFlagIdx;
    uint8_t errStatus = ME_FALSE;
   
    if (SnrIdx < (uint8_t)US_D_MAX_NUM_SENSORS)
    {      
        for(SnrFlagIdx = 0u; SnrFlagIdx < (uint16_t)SNR_DIAG_FLG_SNR_FLAG_MAX_CODE; SnrFlagIdx++)
        {
            if((bool_t)ME_TRUE == US_Diagnostics_GetSnrFaultFlagStatus((US_E_SnrFaultReason_t)SnrFlagIdx,SnrIdx))
            {
                if((bool_t)ME_TRUE == US_Diagnostics_IsErrConfiguredToReportToCsm(SnrFlagIdx))
                {
                    errStatus = ME_TRUE;
                    break;
                }
            }
        }
    }

    return (errStatus);
}
#if(QAC_WARNING_FIX == ME_FALSE)
/* ===========================================================================
 * Name:	 US_Diagnostics_GetSnrFaultConfirmedFlagStatus
 * Remarks:  
 * Traceability to source Code: Req.-ID: 
 * ===========================================================================*/

/*This Function is to get the status of individual Faults of sensors*/
uint32_t US_Diagnostics_GetSnrFaultConfirmedFlagStatus(US_E_SnrFaultReason_t SnrFlagType)
{
	return US_DTC_SnrMap_Per_FLG_Type_Confirmed[SnrFlagType];
}
#endif
/**
 * \brief 
 * 
 * \param SnrErrFlagIdx 
 * \return uint8_t 
 */
/* ===========================================================================
 * Name:	 US_Diagnostics_IsErrConfiguredToReportToCsm
 * Remarks:   DD-ID: {607AC8B2-6D32-4797-8364-CFDF89C9D8E2}
 * Traceability to source Code: Req.-ID: 
 * ===========================================================================*/
static uint8_t US_Diagnostics_IsErrConfiguredToReportToCsm( uint16_t SnrErrFlagIdx)
{
    uint8_t retVal = ME_FALSE;

    if((uint16_t)SNR_DIAG_FLG_SNR_FLAG_MAX_CODE > SnrErrFlagIdx)
    {
        switch(SnrErrFlagIdx)
        {
            /*List of error which are not reported to csm as per saftey requirement*/
            case (uint16_t)SNR_DIAG_FLG_SENSOR_DISCONNECT:
            case (uint16_t)SNR_DIAG_FLG_PDCM_PULSE_INVALID:                             
            case (uint16_t)SNR_DIAG_FLG_DISCOVERY_PULSE_INVALID:                        
            case (uint16_t)SNR_DIAG_FLG_FCC_ERROR_STATE:                                
            case (uint16_t)SNR_DIAG_FLG_INVALID_START_EDGE_DETECTED:
            case (uint16_t)SNR_DIAG_FLG_CRM_TYPE_ERROR:                                 
            case (uint16_t)SNR_DIAG_FLG_SNR_COMM_UNKNOWN:
            case (uint16_t)SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE:
            case (uint16_t)SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A1:                     
            case (uint16_t)SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A2:                     
            case (uint16_t)SNR_DIAG_FLG_ADA_MEASURE_TIMEOUT:
            case (uint16_t)SNR_DIAG_FLG_BAD_RING_TIME:                                   
            case (uint16_t)SNR_DIAG_FLG_TRANSDUCER_ERR:                                  
            case (uint16_t)SNR_DIAG_FLG_SNR_BLOCKAGE:                                    
            case (uint16_t)SNR_DIAG_FLG_SNR_FW_MISMATCH:                                 
            case (uint16_t)SNR_DIAG_FLG_SNR_OPMODE_ERROR:                                
            case (uint16_t)SNR_DIAG_FLG_SNR_FAIL:                                        
            case (uint16_t)SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL:                           
            retVal = ME_FALSE;
            break;
        
            default:
            retVal = ME_TRUE;
            break;
        }
    }

    return (retVal);
}

#endif
