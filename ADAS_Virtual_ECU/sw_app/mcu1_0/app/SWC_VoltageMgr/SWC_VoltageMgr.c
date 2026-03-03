/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  SWC_VoltageMgr.c
 *           Config:  D:/git/L2H4060_Software_master/sw/platform/asr/DaVinci/L2H4060_CVADAS_MCU1_0.dpa
 *        SW-C Type:  SWC_VoltageMgr
 *  Generation Time:  2024-02-22 16:29:44
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  C-Code implementation template for SW-C <SWC_VoltageMgr>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * ErrorMgr_enErrorNo
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * ErrorMgr_enErrorStatus
 *   uint32 represents integers with a minimum value of 0 and a maximum value 
 *      of 4294967295. The order-relation on uint32 is: x < y if y - x is positive.
 *      uint32 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39). 
 *      
 *      For example: 1, 0, 12234567, 104400.
 *
 * IOHWAB_BOOL
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 * IOHWAB_UINT16
 *   uint16 represents integers with a minimum value of 0 and a maximum value of 65535.
 *      The order-relation on uint16 is: x < y if y - x is positive.
 *      uint16 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 1267, +10000.
 *
 * IOHWAB_UINT8
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * VoltMgr_Enum_VoltageMON
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * udtBatteryVoltageStatus
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_SWC_VoltageMgr.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "Enums.h"
#include "VoltageCurrent_data.h"
#include "ipc_manager.h"
#include "Os_Lcfg.h"

typedef struct vtgMgr_Metadata_s
{
  VoltMgr_Enum_VoltageMON ADC_Index;
  uint16_t ADC_RAW_u16;  
  float32 ADC_CNV_f32;
  uint8_t AdcDebouncCnt_u8;
  uint16_t ADC_RESOLUTION_u16;
  uint16_t ADC_REFVTG_u16;
  uint32 ADCRESISTOR_SUM_u32;
  uint32 ADCRESISTOR_DIV_u32;  
} vtgMgr_Metadata_t;

/* ADC channel configuration */
/* For 12 Bit ADC */
/*HSIS requirement : 14954019 , 14954029 , 14954031 , 14954033 , 14954035 , 14954037 , 14954039 , 14954041 \
 * 14954043 , 14954045, 14954051  */
/* 
 * CAM_CS_A/B conversion factor note [HSIS Spec IDs : 14474418/14474419]
 * => 1/0.0023514 for mA output
 * The table below converts to Amp, so conversion factor for Amp(div by 1000) = 1/2.3514
 * Amp conv factor = 10000/23514 = 5000/11757 
 */
#if defined( BUILD_MCU1_0 )
#define SWC_VoltageMgr_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_VoltageMgr_MemMap.h"
#endif
static vtgMgr_Metadata_t ADCGroup_Data_Read[Vol_Last_Index] =
    {
#ifdef D_DV_BOARD
        {Vol_CAM_PS_MON,      0u,       0.0F,       0u,              4096u,          1800u,        3576u,             576u},
        {Vol_CAM_CS_A,        0u,       0.0F,       0u,              4096u,          1800u,         4253u,          10000u},
        {Vol_CAM_CS_B,        0u,       0.0F,       0u,              4096u,          1800u,         4253u,          10000u},
        {Vol_USS_PWR_A_MON,   0u,       0.0F,       0u,              4096u,          1800u,        36210u,           3010u},
        {Vol_USS_PWR_B_MON,   0u,       0.0F,       0u,              4096u,          1800u,        36210u,           3010u},
        {Vol_USS_PWR_C_MON,   0u,       0.0F,       0u,              4096u,          1800u,        36210u,           3010u},
        {Vol_USS_PWR_IS1_MON, 0u,       0.0F,       0u,              4096u,          1800u,          670u,           1500u},
        {Vol_USS_PWR_IS2_MON, 0u,       0.0F,       0u,              4096u,          1800u,          670u,           1500u},
        {Vol_VBAT_MON,        0u,       0.0F,       0u,              4096u,          1800u,        45000u,           2000u},
        {Vol_TEMP1_MON,       0u,       0.0F,       0u,              4096u,          1800u,        0u,                0u},
        {Vol_TEMP2_MON,       0u,       0.0F,       0u,              4096u,          1800u,        0u,                0u},
#else
        /*ADC_CHannel,        ADC_RAW,  ADC_CNV,  AdcDebouncCnt,  ADC_RESOLUTION, ADC_REFVTG,   ADCRESISTOR_SUM,  ADCRESISTOR_DIV */
        {Vol_CAM_PS_MON,      0u,       0.0F,      0u,              4096u,          1800u,        3576,             576u},
        {Vol_CAM_CS_A,        0u,       0.0F,       0u,              4096u,          1800u,        360u,             1800u},
        {Vol_CAM_CS_B,        0u,       0.0F,       0u,              4096u,          1800u,        360u,             1800u},
        {Vol_USS_PWR_A_MON,   0u,       0.0F,       0u,              4096u,          1800u,        36210u,           3010u},
        {Vol_USS_PWR_B_MON,   0u,       0.0F,       0u,              4096u,          1800u,        36210u,           3010u},
        {Vol_USS_PWR_C_MON,   0u,       0.0F,       0u,              4096u,          1800u,        36210u,           3010u},
        {Vol_USS_PWR_IS1_MON, 0u,       0.0F,       0u,              4096u,          1800u,        670u,             3000u},
        {Vol_USS_PWR_IS2_MON, 0u,       0.0F,       0u,              4096u,          1800u,        670u,             3000u},
        {Vol_VBAT_MON,        0u,       0.0F,       0u,              4096u,          1800u,        51700u,           4700u},
        {Vol_TEMP1_MON,       0u,       0.0F,       0u,              4096u,          1800u,        0u,                0u},
        {Vol_TEMP2_MON,       0u,       0.0F,       0u,              4096u,          1800u,        0u,                0u},
#endif
    };
#if defined( BUILD_MCU1_0 )
#define SWC_VoltageMgr_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_VoltageMgr_MemMap.h"
#endif


#define D_TABLE_LENGTH    26u
#define D_DELAY_CNT 4u
#define D_MAX_DBOUNCE_CNT 3u

float32 ADC_CNV_USS_BUF[2] = {0.0, 0.0};
float32 ADC_CNV_AVGBUFF[2] = {0.0, 0.0};


/* TODO: Vijay: need to update debounce time after verifying with HW team : <#18632715> */
#define D_USS_DEBOUNCE_TIME 5u
#define D_SET_PIN 1u
#define D_CLR_PIN 0u

#define DTC_FLAG_ACTIVE 1u

#if defined( BUILD_MCU1_0 )
#define SWC_VoltageMgr_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_VoltageMgr_MemMap.h"
#endif
/*Variable to read Surround View Cam  0(Absent)-Single Camera system , 1(Present)- Four Camera System*/
#if defined( BUILD_MCU1_0 )
#define SWC_VoltageMgr_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "SWC_VoltageMgr_MemMap.h"
#endif

#if defined( BUILD_MCU1_0 )
#define SWC_VoltageMgr_START_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_VoltageMgr_MemMap.h"
#endif
static uint16_t LMT84TransferTable_VoltageSample_au16[D_TABLE_LENGTH] = 
{
  THOUSAND_TWO_NINETY_NINE,
  THOUSAND_TWO_THIRTY_ONE, 
  THOUSAND_ONE_THIRTY,
  THOUSAND_SEVENTY_SEVEN,
  THOUSAND_TWENTY_EIGHT,
  (uint16_t)e_NINE_EIGHTY,
  (uint16_t)e_NINE_TWENTY_FIVE,
  (uint16_t)e_EIGHT_SIXTY,
  (uint16_t)e_EIGHT_SIXTEEN,
  (uint16_t)e_SEVEN_EIGHTY_EIGHT,
  (uint16_t)e_SEVEN_SIXTY,
  (uint16_t)e_SEVEN_THIRTY_TWO,
  (uint16_t)e_SEVEN_TEN ,
  (uint16_t)e_SIX_SEVENTY,
  (uint16_t)e_SIX_THIRTY,
  (uint16_t)e_FIVE_EIGHTY_FIVE,
  (uint16_t)e_FIVE_FIFTY_SEVEN,
  (uint16_t)e_FIVE_TWENTY_EIGHT, 
  (uint16_t)e_FOUR_NINETY_NINE,
  (uint16_t)e_FOUR_SIXTY_FIVE, 
  (uint16_t)e_FOUR_TWENTY_FIVE,
  (uint16_t) e_THREE_NINETY_SIX,
  (uint16_t)e_THREE_SIXTY_ONE, 
  (uint16_t)e_THREE_THIRTY_TWO,
  (uint16_t)e_TWO_NINETY_ONE,
  (uint16_t)e_ONE_EIGHTY_THREE,
};

static sint16  LMT84TransferTable_TempSample_as16[D_TABLE_LENGTH] = 
{
  (sint16_t)e_NEG_FIFTY,
  (sint16_t)e_NEG_THIRTY_SEVEN,
  (sint16_t)e_NEG_EIGHTEEN,
  (sint16_t)e_NEG_EIGHT,
  (sint16_t)e_ONE,
  (sint16_t)e_TEN,
  (sint16_t)e_TWENTY,
  (sint16_t)e_THIRTY_TWO,
  (sint16_t)e_FORTY,
  (sint16_t)e_FORTY_FIVE,
  (sint16_t)e_FIFTY,
  (sint16_t)e_FIFTY_FIVE,
  (sint16_t)e_FIFTY_NINE,
  (sint16_t)e_SIXTY_SIX,
  (sint16_t)e_SEVENTY_THREE,
  (sint16_t)e_EIGHTY_ONE,
  (sint16_t)e_EIGHTY_SIX,
  (sint16_t)e_NINETY_ONE,
  (sint16_t)e_NINETY_SIX,
  (sint16_t)e_ONE_TWO, 
  (sint16_t)e_ONE_NINE,
  (sint16_t)e_ONE_FOURTEEN,
  (sint16_t)e_ONE_TWENTY,
  (sint16_t)e_ONE_TWENTY_FIVE,
  (sint16_t)e_ONE_THIRTY_TWO,
  (sint16_t)e_ONE_FIFTY,
};
#if defined( BUILD_MCU1_0 )
#define SWC_VoltageMgr_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "SWC_VoltageMgr_MemMap.h"
#endif

#define D_ADC_REFVTG_SCALER 1000

/*UnderVoltage*/
#define D_VBAT_UNDR_VTG_ERR_THRESHOL 8.5f
#define D_VBAT_UNDR_VTG_DMAT_THRESHOL 9.0f
/*OverVoltage*/
#define D_VBAT_OVR_VTG_ERR_THRESHOL 16.5f
#define D_VBAT_OVR_VTG_DMAT_THRESHOL 16.0f
/*Camera Over Voltage*/
#define D_VBAT_CAM_OVR_VTG_ERR_THRESHOL 17.0f
/*Camera Under Voltage*/
#define D_VBAT_CAM_UNDR_VTG_ERR_THRESHOL 6.5f
/*UnderVoltage*/
#define D_VBAT_UNDR_VTG_ERR_THRESHOL 8.5f
#define D_VBAT_UNDR_VTG_DMAT_THRESHOL 9.0f

#define  D_ADC_12BIT_MASK 0x0FFFu

#if !defined (D_VOLTGM_LOCAL) 
#define D_VOLTGM_LOCAL static
#endif

D_VOLTGM_LOCAL FUNC(void, SWC_VoltageMgr_CODE) RE_VoltageMgr_TempValueConversion(uint8_t i_reqItemIndex_u8);
D_VOLTGM_LOCAL FUNC(void, SWC_VoltageMgr_CODE) RE_VoltageMgr_VBATErrorStatusUpdate(void);
D_VOLTGM_LOCAL FUNC(void, SWC_VoltageMgr_CODE) f_CameraPowerSupply_VBATCameraStatusUpdate(void);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * ErrorMgr_enErrorNo: Integer in interval [0...4294967295]
 * ErrorMgr_enErrorStatus: Integer in interval [0...4294967295]
 * IOHWAB_BOOL: Boolean
 * IOHWAB_UINT16: Integer in interval [0...65535]
 * IOHWAB_UINT8: Integer in interval [0...255]
 * VoltMgr_Enum_VoltageMON: Integer in interval [0...255]
 * boolean: Boolean (standard type)
 * dtRef_VOID: DataReference
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * udtBatteryVoltageStatus: Integer in interval [0...255]
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Array Types:
 * ============
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * AdditionalData_arr: Array with 4 element(s) of type uint8
 * Rte_DT_UssPowerSense_3: Array with 2 element(s) of type float32
 *
 * Record Types:
 * =============
 * CAM_select_info_t: Record with elements
 *   s_Cam_ChId of type uint8
 *   s_Cam_PwrEn_Sts of type uint8
 *   rsvd1 of type uint8
 *   rsvd2 of type uint8
 * DtcAddData_B: Record with elements
 *   b210c_16_0 of type AdditionalData_arr
 *   b210c_17_0 of type AdditionalData_arr
 *   u104e_0_0 of type AdditionalData_arr
 *   u100b_0_0 of type AdditionalData_arr
 *   u0140_0_0 of type AdditionalData_arr
 *   u0184_0_0 of type AdditionalData_arr
 *   b223b_0_0 of type AdditionalData_arr
 *   u0129_0_0 of type AdditionalData_arr
 *   u0131_0_0 of type AdditionalData_arr
 *   u0418_0_0 of type AdditionalData_arr
 *   u0420_0_0 of type AdditionalData_arr
 *   u0422_0_0 of type AdditionalData_arr
 *   u0485_0_0 of type AdditionalData_arr
 *   b12b2_2a_0 of type AdditionalData_arr
 *   b1285_2a_0 of type AdditionalData_arr
 *   b128e_13_0 of type AdditionalData_arr
 *   b128f_13_0 of type AdditionalData_arr
 *   b1290_13_0 of type AdditionalData_arr
 *   b1291_13_0 of type AdditionalData_arr
 *   b1292_13_0 of type AdditionalData_arr
 *   b1293_13_0 of type AdditionalData_arr
 *   b1294_13_0 of type AdditionalData_arr
 *   b1295_13_0 of type AdditionalData_arr
 *   b1296_13_0 of type AdditionalData_arr
 *   b1297_13_0 of type AdditionalData_arr
 *   b1298_13_0 of type AdditionalData_arr
 *   b1299_13_0 of type AdditionalData_arr
 *   b128e_92_0 of type AdditionalData_arr
 *   b128f_92_0 of type AdditionalData_arr
 *   b1290_92_0 of type AdditionalData_arr
 *   b1291_92_0 of type AdditionalData_arr
 *   b1292_92_0 of type AdditionalData_arr
 *   b1293_92_0 of type AdditionalData_arr
 *   b1294_92_0 of type AdditionalData_arr
 *   b1295_92_0 of type AdditionalData_arr
 *   b1296_92_0 of type AdditionalData_arr
 *   b1297_92_0 of type AdditionalData_arr
 *   b1298_92_0 of type AdditionalData_arr
 *   b1299_92_0 of type AdditionalData_arr
 *   b212a_16_0 of type AdditionalData_arr
 *   b212b_16_0 of type AdditionalData_arr
 *   b22a9_0_0 of type AdditionalData_arr
 *   b23c6_92_0 of type AdditionalData_arr
 *   u0267_0_0 of type AdditionalData_arr
 *   b23c7_92_0 of type AdditionalData_arr
 *   u0266_0_0 of type AdditionalData_arr
 *   u0264_0_0 of type AdditionalData_arr
 *   b217a_92_0 of type AdditionalData_arr
 *   u0265_0_0 of type AdditionalData_arr
 *   b23c5_92_0 of type AdditionalData_arr
 *   b217a_1c_0 of type AdditionalData_arr
 *   b23c5_1c_0 of type AdditionalData_arr
 *   b23c6_1c_0 of type AdditionalData_arr
 *   b23c7_1c_0 of type AdditionalData_arr
 *   b2286_0_0 of type AdditionalData_arr
 *   c2212_0_0 of type AdditionalData_arr
 *   b212a_17_0 of type AdditionalData_arr
 *   b212b_17_0 of type AdditionalData_arr
 *   u0100_0_0 of type AdditionalData_arr
 *   u0401_0_0 of type AdditionalData_arr
 *   b212a_8_0 of type AdditionalData_arr
 *   b212b_8_0 of type AdditionalData_arr
 * DtcStatus_B: Record with elements
 *   b210c_16_0 of type uint8
 *   b210c_17_0 of type uint8
 *   u104e_0_0 of type uint8
 *   u100b_0_0 of type uint8
 *   u0140_0_0 of type uint8
 *   u0184_0_0 of type uint8
 *   b223b_0_0 of type uint8
 *   u0129_0_0 of type uint8
 *   u0131_0_0 of type uint8
 *   u0418_0_0 of type uint8
 *   u0420_0_0 of type uint8
 *   u0422_0_0 of type uint8
 *   u0485_0_0 of type uint8
 *   b12b2_2a_0 of type uint8
 *   b1285_2a_0 of type uint8
 *   b128e_13_0 of type uint8
 *   b128f_13_0 of type uint8
 *   b1290_13_0 of type uint8
 *   b1291_13_0 of type uint8
 *   b1292_13_0 of type uint8
 *   b1293_13_0 of type uint8
 *   b1294_13_0 of type uint8
 *   b1295_13_0 of type uint8
 *   b1296_13_0 of type uint8
 *   b1297_13_0 of type uint8
 *   b1298_13_0 of type uint8
 *   b1299_13_0 of type uint8
 *   b128e_92_0 of type uint8
 *   b128f_92_0 of type uint8
 *   b1290_92_0 of type uint8
 *   b1291_92_0 of type uint8
 *   b1292_92_0 of type uint8
 *   b1293_92_0 of type uint8
 *   b1294_92_0 of type uint8
 *   b1295_92_0 of type uint8
 *   b1296_92_0 of type uint8
 *   b1297_92_0 of type uint8
 *   b1298_92_0 of type uint8
 *   b1299_92_0 of type uint8
 *   b212a_16_0 of type uint8
 *   b212b_16_0 of type uint8
 *   b22a9_0_0 of type uint8
 *   b23c6_92_0 of type uint8
 *   u0267_0_0 of type uint8
 *   b23c7_92_0 of type uint8
 *   u0266_0_0 of type uint8
 *   u0264_0_0 of type uint8
 *   b217a_92_0 of type uint8
 *   u0265_0_0 of type uint8
 *   b23c5_92_0 of type uint8
 *   b217a_1c_0 of type uint8
 *   b23c5_1c_0 of type uint8
 *   b23c6_1c_0 of type uint8
 *   b23c7_1c_0 of type uint8
 *   b2286_0_0 of type uint8
 *   c2212_0_0 of type uint8
 *   b212a_17_0 of type uint8
 *   b212b_17_0 of type uint8
 *   u0100_0_0 of type uint8
 *   u0401_0_0 of type uint8
 *   b212a_8_0 of type uint8
 *   b212b_8_0 of type uint8
 * ErrorMgr_stAddData: Record with elements
 *   AdditionalData of type AdditionalData_arr
 * UssPowerSense: Record with elements
 *   v_USS_PWR_A_MON_f32 of type float32
 *   v_USS_PWR_B_MON_f32 of type float32
 *   v_USS_PWR_C_MON_f32 of type float32
 *   v_USS_PWR_IS1_MON_MON_f32 of type Rte_DT_UssPowerSense_3
 *   v_USS_PWR_IS2_MON_MON_f32 of type float32
 *
 *********************************************************************************************************************/


#define SWC_VoltageMgr_START_SEC_CODE
#include "SWC_VoltageMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_VoltageMgr_EtGetADCVoltageInfo
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <GetVoltageInfo> of PortPrototype <PpReadVoltInfo>
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpVoltageChannelStatus_BatteryVoltageStatus(udtBatteryVoltageStatus data)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void RE_VoltageMgr_EtGetADCVoltageInfo(VoltMgr_Enum_VoltageMON Channel_ID, float32 *Voltage)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_VoltageMgr_EtGetADCVoltageInfo_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_VoltageMgr_CODE) RE_VoltageMgr_EtGetADCVoltageInfo(VoltMgr_Enum_VoltageMON Channel_ID, P2VAR(float32, AUTOMATIC, RTE_SWC_VOLTAGEMGR_APPL_VAR) Voltage) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_VoltageMgr_EtGetADCVoltageInfo
 *********************************************************************************************************************/
  /* DD-ID: {314B9B44-5A38-4c9a-ACD5-4CEA8D00E941}*/
	*Voltage = ADCGroup_Data_Read[Channel_ID].ADC_CNV_f32;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_VoltageMgr_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_VoltageMgr_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_VoltageMgr_CODE) RE_VoltageMgr_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_VoltageMgr_Init
 *********************************************************************************************************************/
  /* DD-ID: {C4906AFC-E495-4c7f-AD82-69C3C7010169}*/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RE_VoltageMgr_Main
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_R_DtcData_B_Data_DtcAddData_B(DtcAddData_B *data)
 *   Std_ReturnType Rte_Read_R_DtcData_B_Data_DtcStatus_B(DtcStatus_B *data)
 *   Std_ReturnType Rte_Read_RpCAMSelInfo_CAM_select_info_t(CAM_select_info_t *data)
 *   Std_ReturnType Rte_Read_RpProxiToSWC_SurroundViewCam_u8(uint8 *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpTemperatureVal_GetTemperatureVal(uint8 data)
 *   Std_ReturnType Rte_Write_PpUssPowerData_UssPower(const UssPowerSense *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_RpError_CS_B_ReportErrorStatus1_0_B(ErrorMgr_enErrorNo err, ErrorMgr_enErrorStatus errStatus, const ErrorMgr_stAddData *addData)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_P_Error_CS_E_NOK
 *   Std_ReturnType Rte_Call_RpIoHwAbADCData_GetRawValues(IOHWAB_UINT8 Channelndex, IOHWAB_UINT16 *ChannelRawValue)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IF_IoHwAbADCData_IoHwAbApplicationError
 *   Std_ReturnType Rte_Call_RpIoHwAbUSSDselPin_GetUSSDselPinStatus(IOHWAB_BOOL USSDselPinStatus)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_IF_IoHwAbUSSDselPin_IoHwAbApplicationError
 *   Std_ReturnType Rte_Call_RpIpcTxData_IPC_Write_v(dtRef_VOID b_TxData_pv, uint16 i_IpcMsgId_u16, uint16 i_IpcMsgSize_u16)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_VoltageMgr_Main_doc
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, SWC_VoltageMgr_CODE) RE_VoltageMgr_Main(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RE_VoltageMgr_Main
 *********************************************************************************************************************/
  /*GUID:-  {E7CF5A62-1C51-4275-AE0B-B698B6E18EA5}*/
  /* DD-ID: {E7CF5A62-1C51-4275-AE0B-B698B6E18EA5}*/
 
  uint8 	v_reqItemIndex_u8;
  uint16 	v_rawvalue_u16;
  static uint8 v_USSDselPINdebounceCntr_u8 = (uint8)e_ZERO;
  static USS_Curr_Volt_Monitor_t USS_Curr_Volt_Monitor_Data;
  CAM_Curr_Volt_Monitor_t CAM_Curr_Volt_Monitor_Data;
  static uint16 Counter;
  static uint8 v_USSDselPINStatus_u8 = D_SET_PIN;
  static UssPowerSense s_UssPowerSense_s;/*PRQA S 3516*/
  static CAM_select_info_t Camdata;
  static uint8 delay_count = 0u;
  static uint8 Prev_Cam_ChId = 0u;
  static float32 ADC_CNV_USS_BUF[e_TWO] = {0.0f, 0.0f};
  static float32 ADC_CNV_AVGBUFF[e_TWO] = {0.0f, 0.0f};

  for (v_reqItemIndex_u8 = (uint8)e_ZERO; v_reqItemIndex_u8 < (uint8)Vol_Last_Index; v_reqItemIndex_u8++)
  {
    (void)Rte_Call_RpIoHwAbADCData_GetRawValues(v_reqItemIndex_u8, &v_rawvalue_u16);    
    
    ADCGroup_Data_Read[v_reqItemIndex_u8].ADC_RAW_u16 = v_rawvalue_u16;
    if( (v_reqItemIndex_u8 == (uint8)Vol_TEMP1_MON) || (v_reqItemIndex_u8 == (uint8)Vol_TEMP2_MON) )
    {
      RE_VoltageMgr_TempValueConversion(v_reqItemIndex_u8);
    }
    else
    {
      {
        ADCGroup_Data_Read[v_reqItemIndex_u8].ADC_CNV_f32 = (float32)(((float32)(ADCGroup_Data_Read[v_reqItemIndex_u8].ADC_RAW_u16 & (uint16)D_ADC_12BIT_MASK) *(float32)( ADCGroup_Data_Read[v_reqItemIndex_u8].ADC_REFVTG_u16)) / (float32)(ADCGroup_Data_Read[v_reqItemIndex_u8].ADC_RESOLUTION_u16));
        ADCGroup_Data_Read[v_reqItemIndex_u8].ADC_CNV_f32 = (float32)(((ADCGroup_Data_Read[v_reqItemIndex_u8].ADC_CNV_f32) *(float32)( ADCGroup_Data_Read[v_reqItemIndex_u8].ADCRESISTOR_SUM_u32)) / (float32)(ADCGroup_Data_Read[v_reqItemIndex_u8].ADCRESISTOR_DIV_u32));       
        ADCGroup_Data_Read[v_reqItemIndex_u8].ADC_CNV_f32 = (float32)ADCGroup_Data_Read[v_reqItemIndex_u8].ADC_CNV_f32 / (float32)D_ADC_REFVTG_SCALER; 
      }
    }
  }
  if (v_USSDselPINdebounceCntr_u8 >= (uint8)D_USS_DEBOUNCE_TIME)
  {


    /* Toggle USSDsel PIN after 50 ms*/
    v_USSDselPINStatus_u8 = (v_USSDselPINStatus_u8 ==(uint8)D_SET_PIN) ? D_CLR_PIN : D_SET_PIN;
    (void)Rte_Call_RpIoHwAbUSSDselPin_GetUSSDselPinStatus((BOOL)v_USSDselPINStatus_u8);
    v_USSDselPINdebounceCntr_u8 = (uint8)e_ZERO;
  }
  else
  {
    INCREMENT_VALUE_BYONE(v_USSDselPINdebounceCntr_u8);
  }

  /*Add 3 samples value */
  /*Ignore first two samples */
/* VCAST Jenkins requirement - do not modify */
/* VCAST Jenkins requirement - do not modify */
if ((v_USSDselPINdebounceCntr_u8 > (uint8)e_TWO) && (v_USSDselPINdebounceCntr_u8 <(uint8)e_SIX))/* PRQA S 2995*/ /* Warning:The result of logical operation true. Reason:We need to check value as 3,4,5 */
/* VCAST Jenkins requirement - do not modify */
/* VCAST Jenkins requirement - do not modify */
  {
    ADC_CNV_USS_BUF[v_USSDselPINStatus_u8] += ADCGroup_Data_Read[Vol_USS_PWR_IS1_MON].ADC_CNV_f32;
  }
  else
  {
  }

  if (v_USSDselPINdebounceCntr_u8 >= (uint8)e_FIVE)
  {
    ADC_CNV_AVGBUFF[v_USSDselPINStatus_u8] = ADC_CNV_USS_BUF[v_USSDselPINStatus_u8] / (float32)e_THREE;
    ADC_CNV_USS_BUF[v_USSDselPINStatus_u8] =(float32)e_ZERO;
  }
  else
  {
  }

  
  RE_VoltageMgr_VBATErrorStatusUpdate();
  f_CameraPowerSupply_VBATCameraStatusUpdate();

  if(v_USSDselPINStatus_u8 == (uint8)D_CLR_PIN)
  {
    USS_Curr_Volt_Monitor_Data.Curr_A = (uint16)(ADC_CNV_AVGBUFF[v_USSDselPINStatus_u8]*(float32)THOUSAND);
    s_UssPowerSense_s.v_USS_PWR_IS1_MON_MON_f32[v_USSDselPINStatus_u8]  = (float32)USS_Curr_Volt_Monitor_Data.Curr_A; /* Sending Values for $FD4A read */
  }
  else
  {
    USS_Curr_Volt_Monitor_Data.Curr_B = (uint16)(ADC_CNV_AVGBUFF[v_USSDselPINStatus_u8]*(float32)THOUSAND);
    s_UssPowerSense_s.v_USS_PWR_IS1_MON_MON_f32[v_USSDselPINStatus_u8]  = (float32)USS_Curr_Volt_Monitor_Data.Curr_B; /* Sending Values for $FD4A read */
  }

  USS_Curr_Volt_Monitor_Data.Volt_A = (uint16)(ADCGroup_Data_Read[Vol_USS_PWR_A_MON].ADC_CNV_f32*(float32)THOUSAND);
  USS_Curr_Volt_Monitor_Data.Volt_B = (uint16)(ADCGroup_Data_Read[Vol_USS_PWR_B_MON].ADC_CNV_f32*(float32)THOUSAND);
  (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&USS_Curr_Volt_Monitor_Data, (uint16)e_IpcMsgId_Data_USS_Curr_Volt_Monitor_t, (uint16)sizeof(USS_Curr_Volt_Monitor_Data));

  /* Get Cam channel ID */
  (void)Rte_Read_RpCAMSelInfo_CAM_select_info_t(&Camdata);
  if(Prev_Cam_ChId != Camdata.s_Cam_ChId)
  {
    delay_count = delay_count + (uint8)e_ONE;
  }
 else
{
}

  if(delay_count > (uint8)D_DELAY_CNT)/* 40ms delay */
  {
    CAM_Curr_Volt_Monitor_Data.s_Cam_ChId = Camdata.s_Cam_ChId;
    CAM_Curr_Volt_Monitor_Data.CAM_CS_A= (uint16)(ADCGroup_Data_Read[Vol_CAM_CS_A].ADC_CNV_f32*(float32)THOUSAND);
    CAM_Curr_Volt_Monitor_Data.CAM_PS_MON = (uint16)(ADCGroup_Data_Read[Vol_CAM_PS_MON].ADC_CNV_f32*(float32)THOUSAND);
    CAM_Curr_Volt_Monitor_Data.FreshnessCounter = Counter+(uint16)e_ONE;
    Prev_Cam_ChId = Camdata.s_Cam_ChId;
    delay_count = 0u;
    (void)Rte_Call_RpIpcTxData_IPC_Write_v((dtRef_VOID)&CAM_Curr_Volt_Monitor_Data, (uint16)e_IpcMsgId_Data_CAM_Curr_Volt_Monitor_t, (uint16)sizeof(CAM_Curr_Volt_Monitor_Data));
  }
   else
{
}
  s_UssPowerSense_s.v_USS_PWR_A_MON_f32 = ADCGroup_Data_Read[Vol_USS_PWR_A_MON].ADC_CNV_f32;
  s_UssPowerSense_s.v_USS_PWR_B_MON_f32 = ADCGroup_Data_Read[Vol_USS_PWR_B_MON].ADC_CNV_f32;
  s_UssPowerSense_s.v_USS_PWR_C_MON_f32 = ADCGroup_Data_Read[Vol_USS_PWR_C_MON].ADC_CNV_f32;
  s_UssPowerSense_s.v_USS_PWR_IS2_MON_MON_f32 = ADCGroup_Data_Read[Vol_USS_PWR_IS2_MON].ADC_CNV_f32;
  (void)Rte_Write_PpUssPowerData_UssPower(&s_UssPowerSense_s);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}




/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
  /* ===========================================================================
 *
 *   Name: RE_VoltageMgr_TempValueConversion
 *
 *   Function: Convert Temperature values 
 *
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: None
 *		
 * ========================================================================= */
D_VOLTGM_LOCAL FUNC(void, SWC_VoltageMgr_CODE) RE_VoltageMgr_TempValueConversion(uint8_t i_reqItemIndex_u8)
{
  /* DD-ID: {2E58C54B-1057-4441-BC16-97A618D77BEF}*/
  /*ReqID:-  14184936,14954045,14954051 */
  /*GUID:-   {2E58C54B-1057-4441-BC16-97A618D77BEF}  */
  uint16_t 	v_milivolt_u16;
  uint8_t 	v_index_u8;
  uint16_t	v_V1_u16 =(uint16) e_ZERO;
  uint16_t	v_V2_u16 =(uint16) e_ZERO;
  sint16_t 	v_T1_s16 = (sint16)e_ZERO;
  sint16_t 	v_T2_s16 = (sint16)e_ZERO;
  sint16_t 	v_temp_value_calculated_s16 = (sint16)e_ZERO;

  /*Convert temp ADC count back to Vin(Milivolt). Vin(Milivolt) value will be required for temperature calculation*/
  v_milivolt_u16 = ((ADCGroup_Data_Read[i_reqItemIndex_u8].ADC_RAW_u16 & (uint16)D_ADC_12BIT_MASK)
                                 * ADCGroup_Data_Read[i_reqItemIndex_u8].ADC_REFVTG_u16) / ADCGroup_Data_Read[i_reqItemIndex_u8].ADC_RESOLUTION_u16;

  /*Use linear polar equations and temeprature table provided in LMT84 temperature datasheet
  to find temeprature value for Vin(Milivolt)*/
  for(v_index_u8 = (uint8)e_ZERO; v_index_u8 < (uint8)D_TABLE_LENGTH; v_index_u8++)
  {
    if( (v_milivolt_u16 <= LMT84TransferTable_VoltageSample_au16[v_index_u8]) && (v_milivolt_u16  > LMT84TransferTable_VoltageSample_au16[v_index_u8 + (uint8)e_ONE]) )
    {
      v_V1_u16 = LMT84TransferTable_VoltageSample_au16[v_index_u8];
      v_V2_u16 = LMT84TransferTable_VoltageSample_au16[v_index_u8+(uint8)e_ONE]; 

      v_T1_s16 = LMT84TransferTable_TempSample_as16[v_index_u8];
      v_T2_s16 = LMT84TransferTable_TempSample_as16[v_index_u8+(uint8)e_ONE];

      break;
    }
    else if (v_milivolt_u16 == LMT84TransferTable_VoltageSample_au16[(uint8)D_TABLE_LENGTH - (uint8)e_ONE])
    {
      v_V1_u16 = LMT84TransferTable_VoltageSample_au16[(uint8)D_TABLE_LENGTH-(uint8) e_TWO];
      v_V2_u16 = LMT84TransferTable_VoltageSample_au16[(uint8)D_TABLE_LENGTH- (uint8)e_ONE]; 

      v_T1_s16 = LMT84TransferTable_TempSample_as16[(uint8)D_TABLE_LENGTH- (uint8)e_TWO];
      v_T2_s16 = LMT84TransferTable_TempSample_as16[(uint8)D_TABLE_LENGTH- (uint8)e_ONE];  
    }
    else
    {
      /*Do nothing*/
    }
  }

  if((sint16)e_ZERO !=(v_T2_s16-v_T1_s16))
  {
     /*conversion to temperature based sample points found for v_milivolt_u16 above */
     v_temp_value_calculated_s16 = (sint16)((sint16)(v_V2_u16-v_V1_u16)/(v_T2_s16-v_T1_s16)); 
     v_temp_value_calculated_s16 = (sint16)((sint16)(v_milivolt_u16-v_V1_u16)/v_temp_value_calculated_s16);
     v_temp_value_calculated_s16 = v_temp_value_calculated_s16 + v_T1_s16;
   }
   else
   {
      /*Do nothing*/
   }

  /*store converted temperature value in final result buffer ADCGroup_Data_Read[i_reqItemIndex_u8].ADC_CNV_f32
  so other application access the value using Rte_call*/
  ADCGroup_Data_Read[i_reqItemIndex_u8].ADC_CNV_f32 = (float32)v_temp_value_calculated_s16;
}
/* ===========================================================================
 *
 *   Name: RE_VoltageMgr_VBATErrorStatusUpdate
 *
 *   Function: Updates error status of Battery voltage 
 *
 *   Inputs: None
 *
 *   Outputs: None
 *
 *   Side Effects: None
 *
 *   Remarks: None
 *		
 * ========================================================================= */
D_VOLTGM_LOCAL FUNC(void, SWC_VoltageMgr_CODE) RE_VoltageMgr_VBATErrorStatusUpdate(void)
{
  /* DD-ID: {E69735B1-4A67-4392-AC3C-61433253CB06}*/
  /*ReqID:-  14953746,14954043,14955200*/
  /*@GUID>-  {E69735B1-4A67-4392-AC3C-61433253CB06}*/
  udtBatteryVoltageStatus BatteryVoltageStatusLocal = 0U;
  DtcStatus_B Dtc_flag_status_B = {0u};

  (void)Rte_Read_R_DtcData_B_Data_DtcStatus_B(&Dtc_flag_status_B);
  	
  /*Over Volatge fault condition*/
  if(ADCGroup_Data_Read[Vol_VBAT_MON].ADC_CNV_f32 > (float32)D_VBAT_OVR_VTG_ERR_THRESHOL)
  {
    BatteryVoltageStatusLocal = (uint8)OVER_M_VOLTAGE;
    (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_Battery_OverVoltage,ErrorMgr_ErrorActive,NULL_PTR);
  }
/* VCAST Jenkins requirement - do not modify */
/* VCAST Jenkins requirement - do not modify */
else if (((Dtc_flag_status_B.b210c_17_0 != (uint8)DTC_FLAG_ACTIVE)&& (ADCGroup_Data_Read[Vol_VBAT_MON].ADC_CNV_f32 <= (float32)D_VBAT_OVR_VTG_ERR_THRESHOL))||   /*Dtc Inactive and VBAT is less than or equal to 16.5V*/ \
        ((Dtc_flag_status_B.b210c_17_0 == (uint8)DTC_FLAG_ACTIVE) && (ADCGroup_Data_Read[Vol_VBAT_MON].ADC_CNV_f32 < (float32)D_VBAT_OVR_VTG_DMAT_THRESHOL)))     /*Dtc Active and VBAT is less than 15.5V*/
/* VCAST Jenkins requirement - do not modify */
/* VCAST Jenkins requirement - do not modify */	
  { 
    BatteryVoltageStatusLocal = (uint8)NORMAL_M_VOLTAGE;
    (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_Battery_OverVoltage,ErrorMgr_ErrorInactive,NULL_PTR);
  }
  else
  {
    /*QAC*/
  }
   /*Under Volatge fault condition*/
  if(ADCGroup_Data_Read[Vol_VBAT_MON].ADC_CNV_f32 < (float32)D_VBAT_UNDR_VTG_ERR_THRESHOL)
  {
    BatteryVoltageStatusLocal = (uint8)UNDER_M_VOLTAGE;
    (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_Battery_UnderVoltage,ErrorMgr_ErrorActive,NULL_PTR);
  }
/* VCAST Jenkins requirement - do not modify */
/* VCAST Jenkins requirement - do not modify */
else if (((Dtc_flag_status_B.b210c_16_0 != (uint8)DTC_FLAG_ACTIVE)&& (ADCGroup_Data_Read[Vol_VBAT_MON].ADC_CNV_f32 >= (float32)D_VBAT_UNDR_VTG_ERR_THRESHOL))||    /*Dtc Inactive and VBAT is greater than or equal to 8.5V*/ \
        ((Dtc_flag_status_B.b210c_16_0 == (uint8)DTC_FLAG_ACTIVE) && (ADCGroup_Data_Read[Vol_VBAT_MON].ADC_CNV_f32 >(float32) D_VBAT_UNDR_VTG_DMAT_THRESHOL)))     /*Dtc Active and VBAT is greater than 9.5V*/
/* VCAST Jenkins requirement - do not modify */
/* VCAST Jenkins requirement - do not modify */
  {
    BatteryVoltageStatusLocal = (uint8)NORMAL_M_VOLTAGE;  
    (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_Battery_UnderVoltage,ErrorMgr_ErrorInactive,NULL_PTR);
  }
  else
  {
    /*QAC*/
  }

  /*Write BatteryVoltageStatus to Rte variable so that ErrorMgr can read the same for its fault detection and debouncing*/
  (void)Rte_Write_PpVoltageChannelStatus_BatteryVoltageStatus(BatteryVoltageStatusLocal);
}

D_VOLTGM_LOCAL FUNC(void, SWC_VoltageMgr_CODE) f_CameraPowerSupply_VBATCameraStatusUpdate(void)
{
  /* DD-ID: {B5A74786-9BDC-418f-8282-87EB8EB3E254}*/

  uint8 v_SurroundViewCam_u8 ;
  (void)Rte_Read_RpProxiToSWC_SurroundViewCam_u8(&v_SurroundViewCam_u8);  /* Reading Single or four camera */
	  if(ADCGroup_Data_Read[Vol_CAM_PS_MON].ADC_CNV_f32 < D_VBAT_CAM_UNDR_VTG_ERR_THRESHOL)      
	  {
		  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_RearCam_ADC_Ctrl_OORL,ErrorMgr_ErrorActive,NULL_PTR);

		  	/* 0(Absent)-Single Camera system , 1(Present)- Four Camera System */
			if((uint8)e_ONE == v_SurroundViewCam_u8)
			{
				(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_FrontCam_ADC_Ctrl_OORL,ErrorMgr_ErrorActive,NULL_PTR);
				(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_LeftCam_ADC_Ctrl_OORL,ErrorMgr_ErrorActive,NULL_PTR);
				(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_RightCam_ADC_Ctrl_OORL,ErrorMgr_ErrorActive,NULL_PTR);
			}
			else
			{
				(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_FrontCam_ADC_Ctrl_OORL,ErrorMgr_ErrorInactive,NULL_PTR);
				(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_LeftCam_ADC_Ctrl_OORL,ErrorMgr_ErrorInactive,NULL_PTR);
				(void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_RightCam_ADC_Ctrl_OORL,ErrorMgr_ErrorInactive,NULL_PTR);
			}
     
		}
	  else if(D_VBAT_CAM_OVR_VTG_ERR_THRESHOL < ADCGroup_Data_Read[Vol_CAM_PS_MON].ADC_CNV_f32  )      
	  {
		  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_RearCam_ADC_Ctrl_OORH,ErrorMgr_ErrorActive,NULL_PTR);

	  	/* 0(Absent)-Single Camera system , 1(Present)- Four Camera System */
		  if((uint8)e_ONE == v_SurroundViewCam_u8)
		  {
		  	  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_FrontCam_ADC_Ctrl_OORH,ErrorMgr_ErrorActive,NULL_PTR);
		  	  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_LeftCam_ADC_Ctrl_OORH,ErrorMgr_ErrorActive,NULL_PTR);
		  	  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_RightCam_ADC_Ctrl_OORH,ErrorMgr_ErrorActive,NULL_PTR);
		  }
		  else
		  {
		  	  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_FrontCam_ADC_Ctrl_OORH,ErrorMgr_ErrorInactive,NULL_PTR);
		  	  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_LeftCam_ADC_Ctrl_OORH,ErrorMgr_ErrorInactive,NULL_PTR);
		  	  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_RightCam_ADC_Ctrl_OORH,ErrorMgr_ErrorInactive,NULL_PTR);
		  }

	  }
	  else
	  {
			  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_RearCam_ADC_Ctrl_OORL,ErrorMgr_ErrorInactive,NULL_PTR);
			  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_FrontCam_ADC_Ctrl_OORL,ErrorMgr_ErrorInactive,NULL_PTR);
			  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_LeftCam_ADC_Ctrl_OORL,ErrorMgr_ErrorInactive,NULL_PTR);
			  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_RightCam_ADC_Ctrl_OORL,ErrorMgr_ErrorInactive,NULL_PTR);
			  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_RearCam_ADC_Ctrl_OORH,ErrorMgr_ErrorInactive,NULL_PTR);
			  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_FrontCam_ADC_Ctrl_OORH,ErrorMgr_ErrorInactive,NULL_PTR);
			  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_LeftCam_ADC_Ctrl_OORH,ErrorMgr_ErrorInactive,NULL_PTR);
			  (void)Os_Call_RE_ReportErrorStatus1_0_B(ErrorMgr_Error_V_Meas_RightCam_ADC_Ctrl_OORH,ErrorMgr_ErrorInactive,NULL_PTR);
	  }
}

#define SWC_VoltageMgr_STOP_SEC_CODE
#include "SWC_VoltageMgr_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

*/
