#ifndef US_ERR_MGR_H
#define US_ERR_MGR_H

/*Allowed flag mask need to define -- use allowed flag mask */
#include "US_Diagnostic_Global.h"
/*#include "PlatformDataTypes.h" */
/*#include "ErrorManagerDef.h" */

#define TOTAL_NO_OF_FLAGS   (US_D_MAX_NUM_SENSORS * MAX_PER_SNR_FLAGS)
#if(((US_D_CUR_PLATFORM & US_D_PLATFORM_CVADAS)== US_D_PLATFORM_CVADAS)||((US_D_CUR_PLATFORM & US_D_PLATFORM_DTPAM)== US_D_PLATFORM_DTPAM))
typedef enum US_E_DiagOuptutFlagPos_e
{
	SNR_COMM_FAULT = 0,						
	SNR_LOSS_POWER_FAULT,					
	SNR_FW_MISMATCH,						
	SNR_OVER_TEMP_FLAG,					
    SNR_OPMODE_ERROR,                      
	SNR_DRV1_FAILURE_DURING_BURST,        	
	SNR_DRV2_FAILURE_DURING_BURST,			
	SNR_DRVS_FAILURE_DURING_BURST,			
	SNR_BURST_ABORT_DURING_BURST,			
	SNR_RING_COMPARATOR_ZERO,				
	SNR_GET_RING_FREQUENCY_FAILURE,		
	SNR_GET_DRV_FREQUENCY_FAILURE,			
	SNR_SRAM_PARITY_ERROR,					
	SNR_CRC_MISTMATCH_IN_EEPROM_A1,		
	SNR_CRC_MISTMATCH_IN_EEPROM_A2,		
	SNR_ADA_MEASURE_TIMEOUT,				
	SNR_PROGRAM_EEPROM,					
	SNR_VTANK_OVER_VOLTAGE_DURING_BURST,	
	SNR_VTANK_OVERVOLTAGE,					
	SNR_VTANK_UNDERVOLTAGE,				
	SNR_VSUP_OVER_VOLTAGE,					
	SNR_VSUP_UNDER_VOLTAGE,				
	SNR_BAD_RING_TIME,						
/*SNR_TRANSDUCER_ERR, */
	SNR_SNR_SETUP_SENSOR_FAIL,				
#if((US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS)||((US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS_BEV)))
	SNR_CRC_MISMATCH_IN_OTP,				
	SNR_DSP_CONFIG_REGISTER_MISMATCH,		
	SNR_CPU_CONFIG_REGISTER_MISMATCH,		
	SNR_NOISE_DURING_BURST,				
	SNR_VREF_OUT_OF_RANGE,					
	SNR_VREF_OTP_OUT_OF_RANGE,				
	SNR_VDDD_OUT_OF_RANGE,					
	SNR_WD_COUNTER_DESYNC,					
	SNR_WD_CLOCK_FAIL,						
	SNR_CRC_BLOCK_CFG1,					
	SNR_CRC_BLOCK_CFG2,					
	SNR_CRC_BLOCK_MFG1,					
	SNR_CRC_BLOCK_MFG2,					
	SNR_CRC_OP_MODE1,						
	SNR_CRC_OP_MODE2,						
	SNR_SIGNAL_PATH_FAILURE,
#endif
	SNR_SYNCHRONISATION_COUNTER_ERROR,
	SNR_RECEIVED_COMMAND_INVALID,
	SNR_BLOCKAGE_FLAG,				
	MAX_DTC_SNR_FLAGS,
	SNR_COMM_UNKNOWN,
	SNR_NO_OUTPUT_FLAG,
	MAX_PER_SNR_FLAGS 
}US_E_DiagOuptutFlagGrp_t;

typedef enum US_E_ECUDiagOuptutFlagPos_e
{
	    ECU_FRONT_BUMPER_SHORT_TO_GND_FLAG,        
	    ECU_FRONT_BUMPER_VOLTAGE_OOR_LOW_FLAG,     
	    ECU_FRONT_BUMPER_VOLTAGE_OOR_HIGH_FLAG ,   
	    ECU_FRONT_BUMPER_SHORT_TO_BAT_FLAG,
		ECU_REAR_BUMPER_SHORT_TO_GND_FLAG,         
	    ECU_REAR_BUMPER_VOLTAGE_OOR_LOW_FLAG,      
	    ECU_REAR_BUMPER_VOLTAGE_OOR_HIGH_FLAG,     
	    ECU_REAR_BUMPER_SHORT_TO_BAT_FLAG,                 
	    ECU_NO_CALI_DATA,  
	    ECU_DSI_VCCUV_ERR,
	    ECU_DSI_CLKREF_ERR,
	    ECU_DSI_OT_ERR,
	    ECU_DSI_CRC_ERR,
#if((US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS)||((US_D_CUR_PLATFORM == US_D_PLATFORM_CVADAS_BEV)))
	    ECU_SPI_DMA_ERR,
#endif
	    ECU_CFG_SENSOR_ERR,
	    ECU_GPIO_INT_INITIAL_ERR,
	    ECU_PIN_INITIAL_ERR,
	    ECU_DSI_CLOCK_INITIAL_ERR,
/*	    ECU_DSI_REF_INITIAL_ERR,  */
	    ECU_SPI_INITIAL_ERR,
	    ECU_USS_POWER_ON_ERR,
	    ECU_DSI_RFC_ERR,
	    ECU_DSI0_OC_ERR,
	    ECU_DSI0_UV_ERR,
	    ECU_DSI1_OC_ERR,
	    ECU_DSI1_UV_ERR,
	    ECU_COMM_ERR,
	    ECU_DSI_FSM_RESET,
	    ECU_DSI_DSIUV_ERR,
	    ECU_DSI3_registers_mismatch,
	    ECU_DSI_RAM_BIST_FAIL,
	    ECU_MCAN_INITIAL_ERR,
	    MAX_ECU_FLAGS,
	    ECU_NO_OUTPUT_FLAG 			/*Added this ENUM to disabling ECU error & not to output it*/
}US_E_ECUDiagOuptutFlagGrp_t;

#else
typedef enum US_E_DiagOuptutFlagPos_e
{
	SNR_OVER_TEMP_FLAG = 0,
	SNR_COMM_FAULT,
	SNR_COMM_UNKNOWN,
	SNR_HARDWARE_FAULT,
	SNR_BLOCKAGE_FLAG,
	SNR_FW_MISMATCH,
	MAX_DTC_SNR_FLAGS,
	MAX_PER_SNR_FLAGS,
	SNR_NO_OUTPUT_FAULT		/*Added this ENUM to disabling ECU error & not to output it*/
}US_E_DiagOuptutFlagGrp_t;

#endif
#if 0
/*Values of bellow enums should be arranged w.r.t. customer specific numbers*/
typedef enum US_E_SensorErrGrpdFlag_e
{
	ErrorMgr_Error_USS_FSL_OverTemp         ,
	ErrorMgr_Error_USS_FSL_commFault        ,
	ErrorMgr_Error_USS_FSL_commUnknown      ,
	ErrorMgr_Error_USS_FSL_hardwareFault    ,
	ErrorMgr_Error_USS_FSL_blockage,
	ErrorMgr_Error_USS_FOL_OverTemp,
	ErrorMgr_Error_USS_FOL_commFault       ,
	ErrorMgr_Error_USS_FOL_commUnknown     ,
	ErrorMgr_Error_USS_FOL_hardwareFault   ,
	ErrorMgr_Error_USS_FOL_blockage,
	ErrorMgr_Error_USS_FIL_OverTemp       ,
	ErrorMgr_Error_USS_FIL_commFault      ,
	ErrorMgr_Error_USS_FIL_commUnknown    ,
	ErrorMgr_Error_USS_FIL_hardwareFault  ,
	ErrorMgr_Error_USS_FIL_blockage,
	ErrorMgr_Error_USS_FIR_OverTemp        ,
	ErrorMgr_Error_USS_FIR_commFault       ,
	ErrorMgr_Error_USS_FIR_commUnknown     ,
	ErrorMgr_Error_USS_FIR_hardwareFault   ,
	ErrorMgr_Error_USS_FIR_blockage,
	ErrorMgr_Error_USS_FOR_OverTemp       ,
	ErrorMgr_Error_USS_FOR_commFault      ,
	ErrorMgr_Error_USS_FOR_commUnknown    ,
	ErrorMgr_Error_USS_FOR_hardwareFault  ,
	ErrorMgr_Error_USS_FOR_blockage,
	ErrorMgr_Error_USS_FSR_OverTemp     ,
	ErrorMgr_Error_USS_FSR_commFault    ,
	ErrorMgr_Error_USS_FSR_commUnknown  ,
	ErrorMgr_Error_USS_FSR_hardwareFault,
	ErrorMgr_Error_USS_FSR_blockage,
	ErrorMgr_Error_USS_RSL_OverTemp       ,
	ErrorMgr_Error_USS_RSL_commFault      ,
	ErrorMgr_Error_USS_RSL_commUnknown    ,
	ErrorMgr_Error_USS_RSL_hardwareFault  ,
	ErrorMgr_Error_USS_RSL_blockage,
	ErrorMgr_Error_USS_ROL_OverTemp     ,
	ErrorMgr_Error_USS_ROL_commFault    ,
	ErrorMgr_Error_USS_ROL_commUnknown  ,
	ErrorMgr_Error_USS_ROL_hardwareFault,
	ErrorMgr_Error_USS_ROL_blockage,
	ErrorMgr_Error_USS_RIL_OverTemp      ,
	ErrorMgr_Error_USS_RIL_commFault     ,
	ErrorMgr_Error_USS_RIL_commUnknown   ,
	ErrorMgr_Error_USS_RIL_hardwareFault ,
	ErrorMgr_Error_USS_RIL_blockage,
	ErrorMgr_Error_USS_RIR_OverTemp     ,
	ErrorMgr_Error_USS_RIR_commFault    ,
	ErrorMgr_Error_USS_RIR_commUnknown  ,
	ErrorMgr_Error_USS_RIR_hardwareFault,
	ErrorMgr_Error_USS_RIR_blockage,
	ErrorMgr_Error_USS_ROR_OverTemp     ,
	ErrorMgr_Error_USS_ROR_commFault    ,
	ErrorMgr_Error_USS_ROR_commUnknown  ,
	ErrorMgr_Error_USS_ROR_hardwareFault,
	ErrorMgr_Error_USS_ROR_blockage,
	ErrorMgr_Error_USS_RSR_OverTemp     ,
	ErrorMgr_Error_USS_RSR_commFault    ,
	ErrorMgr_Error_USS_RSR_commUnknown  ,
	ErrorMgr_Error_USS_RSR_hardwareFault,
	ErrorMgr_Error_USS_RSR_blockage,
	ErrorMgr_Error_USS_ECU_RearBumperFault,
	ErrorMgr_Error_USS_ECU_FrontBumperFault,
	ErrorMgr_Error_USS_ECU_NOCaliDataFault,
	ErrorMgr_Error_USS_ECU_InitErrorFault,
}US_E_SensorErrGrpdFlag_t;
#endif

typedef struct
{
	/*TODO-KPK-Need to change the name to Fault reason*/
	US_E_SnrFaultReason_t Fault_Name;
	US_E_DiagOuptutFlagGrp_t DiagOuptutFlagGrp; /*TODO-KPK Need to change the Name*/
}US_DiagConfStrType;


typedef struct
{
	/*TODO-KPK-Need to change the name to Fault reason*/
	US_E_ECUFaultReason_t ECUFault_Name;
	US_E_ECUDiagOuptutFlagGrp_t ECUDiagOuptutFlagGrp; /*TODO-KPK Need to change the Name*/
}US_ECUDiagConfStrType;

#if 0
/*/
 * Fisker Specific Constant structure to map the error numbers from FISKER error manager to specific sensor fault Flags
 * Need to check the feasibility, since this structure access need an execution , to avoid the execution 2 D array is defined
 */

typedef struct US_s_FaultFlag_s
{
	ErrorMgr_enErrorStatus uUSSSnrDTCFltStatus;
	US_E_DiagSnrFlag_t uFaultReson;
}US_s_FaultFlag_t;


typedef struct US_s_ECUFaultFlag_s
{
	ErrorMgr_enErrorStatus uUSSECUDTCFltStatus;
	US_E_ECUDiag_DTC_t uECUFaultReson;
}US_s_ECUFaultFlag_t;

/*Output Flag structure*/
/*these flags need to aledign with xls entry so that passing flags values to Error Manager Sattelite API would be in sync with error numbers*/
typedef union US_u_sensorDiagFlags_u
{
	struct {
		US_s_FaultFlag_t USS_OverTemp ;
		US_s_FaultFlag_t USS_commFault;
		US_s_FaultFlag_t USS_commUnknown;
		US_s_FaultFlag_t USS_hardwareFault;
		US_s_FaultFlag_t USS_blockage;
		US_s_FaultFlag_t USS_SnrFWMismatch;
	}sensorDiagDTCFlags;
	US_s_FaultFlag_t perSensorFlagArray[MAX_PER_SNR_FLAGS];
}US_u_sensorDiagFlags_t;

typedef union US_u_ECUDiagFlags_u
{
	struct {
		US_s_ECUFaultFlag_t USS_ECURearBumperFault ;
		US_s_ECUFaultFlag_t USS_ECUFrontBumperFault;
		US_s_ECUFaultFlag_t USS_ECUNoCaliDataFault;
		US_s_ECUFaultFlag_t USS_ECUInitErrFault;
	}ECUDiagDTCFlags;
	US_s_ECUFaultFlag_t ECUFlagArray[MAX_ECU_FLAGS];
}US_u_ECUDiagFlags_t;




typedef struct UssDiag_S_USSDiagFlags_s
{
	US_u_sensorDiagFlags_t uSensorDiagFlags[US_D_MAX_NUM_SENSORS];  /*12 = MAX SENSOR NUMBERS //12*12 = 144bytes */
	US_u_sensorDiagFlags_t uPrevSensorDiagFlags[US_D_MAX_NUM_SENSORS];						/*144bytes */
	US_u_ECUDiagFlags_t sCurECUDiagFlags;	/*8bytes */
	US_u_ECUDiagFlags_t sPrevECUDiagFlags;	/*8bytes */
}UssDiag_S_USSDiagFlags_t;
#endif

/*Global Functions*/
void UssErrMgr_UpdateSensorDiagFlagStatus(uint8_t sensorID,US_E_SnrFaultReason_t Dtc_Type,bool_t status);
/*void UssErrMgr_SetSensorDiagFlagStatus(uint8_t sensorID,US_E_Diag_DTC_t Dtc_Type); */
/*void UssErrMgr_ClearSensorDiagFlagStatus(uint8_t sensorID,US_E_Diag_DTC_t Dtc_Type); */
void UssErrMgr_UpdateECUDiagFlagStatus(US_E_ECUFaultReason_t Dtc_Type, bool_t status);
bool_t UssHsd_f_GetOnFaultDetectedFlags(const uint8_t ChannelID);
#endif

